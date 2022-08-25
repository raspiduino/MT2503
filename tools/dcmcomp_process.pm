#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   dcmcomp_process.pm
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file implemented the DCM image post build process.
#*
#*
#* Author:
#* -------
#*   Raymond Chen (mtk05332)
#*
#*****************************************************************************
package dcmcomp_process;
#****************************************************************************
# Included Modules
#****************************************************************************
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use vivaHelper;
use File::stat;
use Math::BigInt;

#****************************************************************************
# Constants
#****************************************************************************
my $compressTool = "tools\\7lzma.exe";
my $dcmcmpBinaryName = "DYNAMIC_COMP_CODE";
my %info = ("name" => "DCM with Compression",
            "binary_name" => $dcmcmpBinaryName,
            "struct_name" => "dcmcmp",
            "entry_function" => \&Process);

#****************************************************************************
# see dcmgr.h to konw the composition of region bin header
# bin header include identifier(32bytes), checksum (4bytes), 
# region id(4bytes), image base (4bytes)
# image zi base(4bytes), image zi size(4bytes), total 52 bytes
#****************************************************************************

my $UNCOMPRESSED_BIN_IDENTIFIER_LEN = 32;
my $UNCOMPRESSED_BIN_CHECKSUM_LEN = 4;

# see dcmgr.h to konw the composition of output bin header
my $OUTPUT_BIN_IDENTIFIER_LEN = 8;

my $OUTPUT_BIN_REGION_NUM_OFFSET = 136;
my $OUTPUT_BIN_REGION_NUM_LEN = 4;

my $OUTPUT_BIN_REGION_INFO_OFFSET = $OUTPUT_BIN_REGION_NUM_OFFSET + $OUTPUT_BIN_REGION_NUM_LEN;

my $REGION_ID_LEN = 2;
my $POOL_ID_LEN = 1;
my $GROUP_ID_LEN = 1;
my $IMAGE_EXEC_BASE_LEN = 4;
my $IMAGE_ZI_BASE_LEN = 0;
my $IMAGE_ZI_SIZE_LEN = 0;
my $IMAGE_EXEC_SIZE_LEN = 4;
my $IMAGE_COMPRESSED_SIZE_LEN = 4;
my $LAST_POSITION_LEN = 4;

my $OUTPUT_BIN_REGION_INFO_SIZE = $REGION_ID_LEN + 
                                  $POOL_ID_LEN + 
                                  $GROUP_ID_LEN + 
                                  $IMAGE_EXEC_BASE_LEN + 
                                  $IMAGE_ZI_BASE_LEN + 
					                        $IMAGE_ZI_SIZE_LEN + 
					                        $IMAGE_EXEC_SIZE_LEN + 
					                        $IMAGE_COMPRESSED_SIZE_LEN + 
					                        $LAST_POSITION_LEN;


my $BASE_IDENTIFIER = unpack('V1', "DCM_COMPRESS_CANDIDATE_HDR_V01");
my $OUTPUT_IDENTIFIER = "DCMGBODY";


#****************************************************************************
# parameters for lazy loading
#****************************************************************************
my $SHOULD_CUT_SIZE = 0x20000; # a region is divided if its size exceeding 128K
# my $MIN_CUT_SIZE = 0x1000;     # 4K

my $BUF_SIZE = 1024;

#****************************************************************************
# subroutine:  Process
# description: Perform the ZIMAGE post build process.
# input:       Binary folder, available start address,
#              original start address ref, original size ref
# output:      Actual start address, new binary size
#****************************************************************************
sub Process
{
   my $binaryFolder = shift;
   my $availableStartAddress = shift;
   my $startAddressRef = shift;
   my $sizeRef = shift;
   my $dcmcmpEnabled = &vivaHelper::GetMakefileOption("DCM_COMPRESSION_SUPPORT");
   my $multiTrunkEnabled = &vivaHelper::GetMakefileOption("DCM_MULTITRUNK");
   
   if (defined $dcmcmpEnabled and $dcmcmpEnabled eq "TRUE")
   {
      
   	  if(defined $multiTrunkEnabled and $multiTrunkEnabled ne "NONE")
   	  {
   	      DCMCompProcess_Pl($binaryFolder);
      }
   	  else 
   	  {
       	  DCMCompProcess($binaryFolder);
      }
      
      # Update start address and binary size
      # Need 4 byte align
      $$startAddressRef = &vivaHelper::RoundUpToAlignment($availableStartAddress, 4);
   	  my $binary = "$binaryFolder\\$dcmcmpBinaryName";
      $$sizeRef = -s $binary;
      return 1;
   }
   else
   {
      return 0;
   }
}
#****************************************************************************
# subroutine:  DCMCompProcess
# description: Perform the ZIMAGE post build process.
# input:       Binary folder
# output:      None
#****************************************************************************
sub DCMCompProcess
{
   my ($processed_folder) = @_;
   my @Binary_Files = ();
   my @Compress_List = ();
   my $lzma_exe = "tools\\7lzma.exe";
   die "compression tool $lzma_exe do NOT exist!\n" if (!-e $lzma_exe);
   if(-d "$processed_folder"){
     opendir DIRHANDLE, "$processed_folder";
     @Binary_Files =  grep { !/^\.{1,2}$/ and -f "$processed_folder\\$_"} readdir (DIRHANDLE);
     close DIRHANDLE;
   } else {
     die "$processed_folder bin file folder do NOT exist!!!\n";
   }
   my $base_identifier = "DCM_COMPRESS_CANDIDATE_HDR_V01";
   $base_identifier = unpack('V1', "$base_identifier");
   my $output_identifier = "DCMGBODY";
   foreach (@Binary_Files){
     my $B_file = $_;
     open (FILE, "<$processed_folder\\$B_file") or die "cannot open $processed_folder\\$B_file\n";
     binmode(FILE);
     (read FILE, $identifier, 32);
     my $tmp_id = $identifier;
     $identifier = unpack('V1', $identifier);
     (read FILE, $checksum, 4);
     $checksum = unpack('V1', $checksum);
     push(@Compress_List,$B_file) && next if (($identifier eq $base_identifier) && (&checkSum($tmp_id,$checksum)));
     $identifier = "";
     seek(FILE, 0, 0);
     (read FILE, $identifier, 8);
     unpack('C', $identifier);
     $output_file = "$B_file" if ($identifier eq $output_identifier);
     close FILE;
   }
   my $comp_files_cnt = $#Compress_List + 1;
   print "Total $comp_files_cnt files need to be compressed to $output_file\n";
   if($output_file eq "") {
   	print "Error: DCM output file is not existed!\n";
   	exit 1 ;
   }
   system("rd \"$processed_folder\\DYNAMIC_COMP_BIN\"") if (-d "$processed_folder\\DYNAMIC_COMP_BIN");
   system("md \"$processed_folder\\DYNAMIC_COMP_BIN\"");
   system("copy \"$processed_folder\\$output_file\" \"$processed_folder\\DYNAMIC_COMP_BIN\\$output_file.bin\"");
   open (OUTFILE, "+<$processed_folder\\$output_file") or die "cannot open $processed_folder\\$output_file\n";
   binmode(OUTFILE);
   seek(OUTFILE, 136, 0);
   print OUTFILE pack("V1",$comp_files_cnt);
   my $processed_cnt = 0;
   foreach (@Compress_List) {
   	my $current_file = $_;
     system("$lzma_exe et \"$processed_folder\\$current_file\" \"$processed_folder\\$current_file.gz\"");
     system("rename \"$processed_folder\\$current_file\" \"$current_file.bin\"");
     system("rename \"$processed_folder\\$current_file.gz\" \"$current_file\"");
   	open (FILE, "<$processed_folder\\$current_file.bin") or die "cannot open $processed_folder\\$current_file.bin\n";
     binmode(FILE);
     seek(FILE, 36, 0);
     (read FILE, $img_id, 4);
     $img_id = unpack('V1', $img_id);
     (read FILE, $img_exec_base, 4);
     $img_exec_base = unpack('V1', $img_exec_base);
     (read FILE, $img_zi_base, 4);
     $img_zi_base = unpack('V1', $img_zi_base);
     (read FILE, $img_zi_size, 4);
     $img_zi_size = unpack('V1', $img_zi_size);
     $comp_size = stat("$processed_folder\\$current_file")->size;
     $original_size = stat("$processed_folder\\$current_file.bin")->size;
     my $header_pos = 140 + 28*$processed_cnt;
     seek(OUTFILE, 0, 2);
     my $last_position = tell(OUTFILE);
     seek(OUTFILE, $header_pos, 0);
     print OUTFILE pack("V1",$img_id);
     print OUTFILE pack("V1",$img_exec_base);
     print OUTFILE pack("V1",$img_zi_base);
     print OUTFILE pack("V1",$img_zi_size);
     print OUTFILE pack("V1",$original_size);
     print OUTFILE pack("V1",$comp_size);
     print OUTFILE pack("V1",$last_position);
     seek(OUTFILE, $last_position, 0);
     open (GZFILE, "<$processed_folder\\$current_file") or die "cannot open $processed_folder\\$current_file\n";
     binmode GZFILE;
     while (read(GZFILE, $buf, 4)) {
       print OUTFILE $buf;
     }
     close GZFILE;
     close FILE;
     system("move /y  \"$processed_folder\\$current_file\" \"$processed_folder\\DYNAMIC_COMP_BIN\\$current_file\"");
     system("move /y  \"$processed_folder\\$current_file.bin\" \"$processed_folder\\DYNAMIC_COMP_BIN\\$current_file.bin\"");
     $processed_cnt ++;
   }
   close OUTFILE;
}
#****************************************************************************
# subroutine:  DCMCompProcess_Pl
# description: Perform the DCM with compression post build process.
# input:       Binary folder, available start address,
#              original start address ref, original size ref
# output:      Actual start address, new binary size
#****************************************************************************
sub DCMCompProcess_Pl
{
    my $bin_folder = shift;
    #my $reserved_folder = "$bin_folder\\DYNAMIC_COMP_BIN";

    my $output_bin;
    my %bins_data;
    my %bins_by_group;
    my %bins_by_pool;
    my @bins_not_cut;
    my %should_cut_trunk;
    my %should_cut_trunk_size;
    

      
    # if compress tool is found
    die "compression tool $compressTool do NOT exist!\n" if (!-e $compressTool);

    # filter out dcm bins
    listDCMBins($bin_folder, #input
    	          $output_bin, #output
    	          \@dcm_bins);
        
    ($bins_data, $bins_by_group, $bins_by_pool) = parseRegionInformation($bin_folder, @dcm_bins);
    %bins_data = %$bins_data;
    %bins_by_group = %$bins_by_group;
    %bins_by_pool = %$bins_by_pool;       
               
 
    ($bins_not_cut, $should_cut_trunk_size, $should_cut_trunk) = getCutInformation($SHOULD_CUT_SIZE, 
                                                                                $MIN_CUT_SIZE, 
                                                                                $bin_folder, 
                                                                                \%bins_data,
                                                                                \%bins_by_pool);
     @bins_not_cut = @$bins_not_cut;
     %should_cut_trunk_size = %$should_cut_trunk_size;
     %should_cut_trunk = %$should_cut_trunk;
        
     cutBinIntoTrunks($bin_folder, 
                      \%should_cut_trunk_size, 
                      \%should_cut_trunk);
        
     doCompression($bin_folder, @dcm_bins);
     doRenaming($bin_folder, @dcm_bins);
        
        
     for $bin (keys %should_cut_trunk) {
         my @trunks = @{$should_cut_trunk{$bin}};
         doCompression($bin_folder, @trunks);
         doRenaming($bin_folder, @trunks);
         glueTrunks($bin_folder, $bin, \@trunks);
     }
        
        
     recreateCompressFolder("$bin_folder\\DYNAMIC_COMP_BIN");   
        
     combineBin($bin_folder,
                $output_bin,
                $bins_data,
                \@dcm_bins, 
                \%should_cut_trunk);     

}


#****************************************************************************
# subroutine:  listDCMBins
# description: filter out dcm bins and output bin according to input file the header
# input:       Binary folder, input filenames
# output:      $_[1] : output bin filename, $_[2]DCM bin filenames and 
#****************************************************************************
sub listDCMBins
{
	
	  # variables
		my $bin_folder = $_[0];
		my @bins = ();
    #my @dcm_bins = ();
    #my $output_bin = "";
	
    
	  # list files under the binary folder
    opendir (dir_hdl, "$bin_folder") or die "$bin_folder bin file folder do NOT exist!!!\n";
    @bins =  grep { !/^\.{1,2}$/ and -f "$bin_folder\\$_"} readdir (dir_hdl);
    close dir_hdl;	
	
    
	  # filter out DCM bins
    foreach (@bins){
    	
        my $bin = $_;
        my ($unpacked_identifier, $identifier);
        my ($unpacked_checksum, $checksum);
        
        open (fp, "<$bin_folder\\$bin") or die "cannot open $bin_folder\\$bin\n";
        binmode fp;
       
        # parse header
        read fp, $identifier, $UNCOMPRESSED_BIN_IDENTIFIER_LEN;
        $unpacked_identifier = unpack 'V1', $identifier;
        read fp, $checksum, $UNCOMPRESSED_BIN_CHECKSUM_LEN;         		
        $unpacked_checksum = unpack 'V1', $checksum;
        
        # is it a region bin a output bin ?
        if (($unpacked_identifier eq $BASE_IDENTIFIER) && (&checkSum($identifier,$unpacked_checksum))) # region bin
        {
            push @{$_[2]}, $bin;
            printLog("DCM_BIN", $bin);
        } 
        else # output bin
        {
            seek (fp, 0, 0);
            read fp, $identifier, $OUTPUT_BIN_IDENTIFIER_LEN;
            unpack 'C', $identifier;
            
            if ($identifier eq $OUTPUT_IDENTIFIER) 
            {
        	      $_[1] = "$bin";
                printLog("OUTPUT_BIN", $bin);
            }

        }
        close fp;
               
    }
    #return ($output_bin, \@dcm_bins);
}

#****************************************************************************
# subroutine:  parseRegionInformation
# description: parse region information accroding to its bin
# input:       Binary folder, input filenames
# output:      $_[1] : output bin filename, $_[2]DCM bin filenames and 
#****************************************************************************
sub parseRegionInformation
{
    my ($bin_folder, @exec_bins) = @_;
    
    my %bins_data;
    my %bins_by_group;
    my %bins_by_pool;
    
    # decide which bins should be cut and the cut line
    foreach (@exec_bins) {

        my $bin = $_;

        # open region bin and compressed bin
   	    open (bin_fp, "<$bin_folder\\$bin") or die "cannot open $bin_folder\\$bin\n";
        binmode bin_fp;
   	    
        # parse region bin header
        seek (bin_fp, ($UNCOMPRESSED_BIN_IDENTIFIER_LEN + $UNCOMPRESSED_BIN_CHECKSUM_LEN + $REGION_ID_LEN), 0);
        read bin_fp, $img_pool, $POOL_ID_LEN;
        read bin_fp, $img_group, $GROUP_ID_LEN;
        read bin_fp, $img_exec_base, $IMAGE_EXEC_BASE_LEN;
        $img_pool = unpack('C1', $img_pool);
        $img_group = unpack('C1', $img_group);       
        $img_exec_base = unpack('V1', $img_exec_base);       
        
        # get region bin size and compressed region bin size
        $bin_size = stat("$bin_folder\\$bin")->size;
        
              
        # get pool and group information of bin
        $bins_data{$bin} = [$img_pool, $img_group, $img_exec_base, $bin_size];
               
        
        if(exists($bins_by_pool{$img_pool})) {
            push @{ $bins_by_pool{$img_pool} }, $bin;
        }
        else {
            $bins_by_pool{$img_pool} = [$bin];
        }
        
        if(exists($bins_by_group{$img_group})) {
            push @{ $bins_by_group{$img_group} }, $bin;
        }
        else {
            $bins_by_group{$img_group} = [$bin];
        }
                
        close bin_fp;
    }    
    

    return (\%bins_data, \%bins_by_group, \%bins_by_pool);
    
}


sub getCutInformation
{
    my ($should_cut_size, $min_cut_size, $bin_folder, $bins_data, $bins_by_pool) = @_;  
    %bins_data = %$bins_data; 
    %bins_by_pool = %$bins_by_pool;
    
    my @bins_not_cut;
    my %should_cut_trunk_size;
    my %should_cut_trunk;
    
    for $bin (keys %bins_data) {
    	
    	  printLog("Cut Info", $bin);
    	  
        if ($bins_data{$bin}[3] > $should_cut_size) {
        	
        	  my $bin_group = $bins_data{$bin}[1];
    	      my $bin_base = $bins_data{$bin}[2];
    	      my $bin_size = $bins_data{$bin}[3];
    	      my $bin_end = $bin_base + $bin_size;
    	      
	          printLog ("CUT bin", "$bin with $bins_data{$bin}[3] bytes should be cut");
	          $should_cut_trunk_size{$bin} = [];
	          $should_cut_trunk{$bin} = [];
	          
	          	          
	          my @overlay_bins = @{ $bins_by_pool{$bins_data{$bin}[0]} };
	          my @cut_lines;
	          my $max_cut_lines = 0;
	          my $max_end = 0;
		    	  foreach (@overlay_bins) {
		    	  	  my $overlay = $_;
		    	      my $overlay_group = $bins_data{$overlay}[1];
		            my $overlay_base = $bins_data{$overlay}[2];
		            my $overlay_size = $bins_data{$overlay}[3];
		            my $overlay_end = $overlay_base + $overlay_size;
		    	  	  
		    	  	  
		    	  	  # different group
								if($overlay_group != $bin_group) {
									  
								    if(($overlay_base >= $bin_base) && ($overlay_base < $bin_end) ) {
								    	  printLog("Cut Info", $overlay);
								    	  printLog("Cut Info", ($overlay_base - $bin_base));
								    	  
								    	  if($overlay_base - $bin_base > 0) {
								    	      push @cut_lines, ($overlay_base - $bin_base);		   
								    	  } 	              		
								    }
								    # the last cut is the end of the overlay region with higher address
								    if ($max_cut_lines < ($overlay_end - $bin_base) ) {
								    	  $max_end = $overlay_end + (32 - ($overlay_end % 32));
								    	  if($max_end <= $bin_end) {

								            $max_cut_lines = ($max_end - $bin_base);
								    	  }								    	  
								    }
								    #if (($overlay_base + $overlay_size > $bin_base) && ($overlay_base + $overlay_size <= $bin_base + $bin_size) ) {
								    #	  printLog("Cut Info", $overlay);
								    #	  printLog("Cut Info", ($overlay_base + $overlay_size - $bin_base));
								    #	  push @cut_lines, ($overlay_base + $overlay_size - $bin_base);		
								    #}
								}								
		    	  }
		    	  if($max_cut_lines > 0) { 
			    	    printLog("Last Cut", $max_cut_lines);
			    	    push @cut_lines, $max_cut_lines;		    	
		    	  }
		    	  
		    	  # calculate trunk size
		    	  @cut_lines =  sort {$a <=> $b} @cut_lines;
	          
	          my $i = 0;
	          while ($i < @cut_lines){
	          	  push @{$should_cut_trunk{$bin}}, "$bin\_$i";
	              if ($i == 0){
	                  push @{$should_cut_trunk_size{$bin}}, $cut_lines[$i];
	              }
	              else {
	              	  push @{$should_cut_trunk_size{$bin}}, ($cut_lines[$i] - $cut_lines[$i - 1]);
	              }
	              $i = $i + 1;
	          }
        	  push @{$should_cut_trunk{$bin}}, "$bin\_$i";
	          push @{$should_cut_trunk_size{$bin}}, ($bin_size - $cut_lines[@cut_lines-1]);
        }
        else {
        	push @bins_not_cut, $bin;
        }
    }
    
    
    return (\@bins_not_cut, \%should_cut_trunk_size, \%should_cut_trunk);
    
    
}

# decide how to cut image
sub cutBinIntoTrunks
{
    my ($bin_folder, $should_cut_trunk_size, $should_cut_trunk) = @_;
    
    %should_cut_trunk_size = %$should_cut_trunk_size;
    %should_cut_trunk = %$should_cut_trunk;

    for $bin (keys %should_cut_trunk_size) {

        my @trunk_size = @{ $should_cut_trunk_size{$bin} };
        my @trunk = @{ $should_cut_trunk{$bin} };
        
        my $i = 0;

    	  open (bin_fp, "<$bin_folder\\$bin") or die "cannot open $bin_folder\\$bin\n";
        binmode bin_fp;

        foreach(@trunk_size) {
            my $total_bytes = 0;
            open (out_fp, ">$bin_folder\\$trunk[$i]") or die "cannot open $bin_folder\\$trunk[$i]\n";
            binmode out_fp;
            
            TRUNK_LOOP: {
            	  my $ts = $trunk_size[$i];
		            while(1) {
		                if($total_bytes >= $ts) {
		                    last TRUNK_LOOP;
		                }
		                
		                my $bytes_to_read = $ts - $total_bytes;
		                if($bytes_to_read > $BUF_SIZE) {
		                    $bytes_to_read = $BUF_SIZE;
		                }
		                read(bin_fp, $buf, $bytes_to_read);
		                print out_fp $buf;
		                
		                $total_bytes = $total_bytes + $bytes_to_read;
		            }
            }
           
            close out_fp;
            
            $i = $i + 1;
            
        }
        
        close bin_fp;
  
    }    
    
}

#****************************************************************************
# subroutine:  combineBin
# description: combine DCM bins into output bin. The output bin is the bin to be put in ROM
# input:       Output bin filename, binary folder, dcm bin filenames
# output:      DCM bins and output bin
#****************************************************************************
sub combineBin
{
                   
    my ($bin_folder, $output_bin, $bins_data, $dcm_bins, $should_cut_trunk) = @_;
                       
    @dcm_bins = @$dcm_bins;
    %should_cut_trunk = %$should_cut_trunk;

          
    my $comp_files_cnt = $#dcm_bins + 1;
    

    # copy file to 'DYNAMIC_COMP_BIN' and rename it with a '.bin' file extension
    system("copy \"$bin_folder\\$output_bin\" \"$bin_folder\\DYNAMIC_COMP_BIN\\$output_bin.bin\"");
    
    
    open (out_fp, "+<$bin_folder\\$output_bin") or die "cannot open $bin_folder\\$output_bin\n";

    # fill # of region to output bin   
    binmode(out_fp);
    seek(out_fp, $OUTPUT_BIN_REGION_NUM_OFFSET, 0);
    print out_fp pack("V1",$comp_files_cnt);
	  
	  my $cnt = 0;
	  #my $sum = 0;
    foreach (@dcm_bins) {

        my $bin = $_;

        # !!!!!!!!!!!!!!!!!!!!!!!!!!!!! 4 bytes align        

        # open region bin and compressed bin
   	    open (bin_fp, "<$bin_folder\\$bin.bin") or die "cannot open $bin_folder\\$bin.bin\n";
        binmode bin_fp;

        # parse region bin header
        seek (bin_fp, ($UNCOMPRESSED_BIN_IDENTIFIER_LEN + $UNCOMPRESSED_BIN_CHECKSUM_LEN), 0);
        read bin_fp, $img_info, ($REGION_ID_LEN + 
                                 $POOL_ID_LEN + 
                                 $GROUP_ID_LEN +
        												 $IMAGE_EXEC_BASE_LEN + 
        												 $IMAGE_ZI_BASE_LEN + 
        												 $IMAGE_ZI_SIZE_LEN);
				
        # get region bin size and compressed region bin size
        $bin_size = stat("$bin_folder\\$bin.bin")->size;      # 7
        $comp_size = stat("$bin_folder\\$bin")->size;         # 8
        #$sum = $sum + $comp_size;
        
        # last position of file
        seek(out_fp, 0, 2);
        my $last_position = tell(out_fp);                     # 9
        

        # fill header information for each bin to output bin
        my $header_pos = $OUTPUT_BIN_REGION_INFO_OFFSET + $OUTPUT_BIN_REGION_INFO_SIZE*$cnt;
        
        
        seek(out_fp, $header_pos, 0);
        print out_fp $img_info;
        print out_fp pack("V1",$bin_size);
        print out_fp pack("V1",$comp_size);
        print out_fp pack("V1",$last_position);
        
        
        
        seek(out_fp, $last_position, 0);
        
        if(exists($should_cut_trunk{$bin})) {
            my @trunks = @{$should_cut_trunk{$bin}} ;
            my $num_trunks = $#trunks + 1;
            print out_fp pack("V1", $num_trunks);
            foreach (@trunks){
                my $trunk_bin_size = stat("$bin_folder\\$_.bin")->size;
                my $trunk_comp_size = stat("$bin_folder\\$_")->size;
                print out_fp pack("V1", $trunk_bin_size);
                print out_fp pack("V1", $trunk_comp_size);
            }
        }
        else {
            print out_fp pack("V1", 1);
            print out_fp pack("V1", $bin_size);
            print out_fp pack("V1", $comp_size);
        }
        
   	    open (compressed_fp, "<$bin_folder\\$bin") or die "cannot open $bin_folder\\$bin\n";
        binmode compressed_fp;
        # fill compressed bin to output bin
        while (read(compressed_fp, $buf, $BUF_SIZE)) {
            print out_fp $buf;
        }
        close compressed_fp;

        # make the last position 4-bytes aligned
        $last_position = tell(out_fp);
        my $remain = $last_position % 4;
        
        if($remain != 0) {
	        for my $i (1..(4 - $remain)){
	            print out_fp pack("C",0);
	        }
        }

        # close region bin and compressed bin        
        close bin_fp;

        if(exists($should_cut_trunk{$bin})) {
        	  my @trunks = @{$should_cut_trunk{$bin}} ;
        	  foreach (@trunks){
        	      system("move /y  \"$bin_folder\\$_\" \"$bin_folder\\DYNAMIC_COMP_BIN\\$_\"");
                system("move /y  \"$bin_folder\\$_.bin\" \"$bin_folder\\DYNAMIC_COMP_BIN\\$_.bin\"");
            }
        }
        
        
        # done, move region bin and compressed bin to 'DYNAMIC_COMP_BIN'
        system("move /y  \"$bin_folder\\$bin\" \"$bin_folder\\DYNAMIC_COMP_BIN\\$bin\"");
        system("move /y  \"$bin_folder\\$bin.bin\" \"$bin_folder\\DYNAMIC_COMP_BIN\\$bin.bin\"");
        
        # next region bin
        $cnt++;
      
   }
   #print "sum = $sum\n";
   close out_fp;


}



#****************************************************************************
# subroutine:  doCompression
# description: Compress files
# input:       Binary folder, filenames of bin to be compressed
# output:      
#****************************************************************************

sub doCompression
{
    my ($bin_folder, @bins) = @_;
    
    # copy file into bin folder and rename it
    my $bin_cnt = $#bins + 1;
    
    printLog("Compress", "Total $bin_cnt files need to be compressed ...\n");
    
    foreach (@bins) {
    	
        my $bin = $_;
        
        system("$compressTool et \"$bin_folder\\$bin\" \"$bin_folder\\$bin.gz\"");
        
        
    }

}


#****************************************************************************
# subroutine:  doRenaming
# description: Compress files
# input:       Files to be renamed and its renaming
# output:      
#****************************************************************************

sub doRenaming
{
    my ($bin_folder, @bins) = @_;
    
    # copy file into bin folder and rename it
    my $bin_cnt = $#bins + 1;
    
    
    foreach (@bins) {
    	
        my $bin = $_;
        
        system("rename \"$bin_folder\\$bin\" \"$bin.bin\"");
        system("rename \"$bin_folder\\$bin.gz\" \"$bin\"");
        
    }

}

#****************************************************************************
# subroutine:  glueTrunks
# description: glue trunk which is originally the same region
# input:       
# output:      
#****************************************************************************
sub glueTrunks
{
	  my ($bin_folder, $out_bin, $compress_bins) = @_;
	  @compress_bins = @$compress_bins;
	  
	  open (out_fp, "+<$bin_folder\\$out_bin") or die "1 cannot open $bin_folder\\$out_bin\n"; 
	  binmode(out_fp);
	  
    foreach (@compress_bins) {
    
    	  my $bin = $_;
    	
    	  open (compressed_fp, "<$bin_folder\\$bin") or die "2 cannot open $bin_folder\\$bin\n";
        binmode compressed_fp;
        
	      while (read(compressed_fp, $buf, $BUF_SIZE)) {
            print out_fp $buf;
        }
        
        close compressed_fp;
    }
    
    close out_fp;
}

#****************************************************************************
# subroutine:  recreateCompressFolder
# description: Before update the 'DYNAMIC_COMP_BIN' folder. Delete it and recreate it
# input:       
# output:      
#****************************************************************************
sub recreateCompressFolder
{
    my ($bin_folder) = @_;
    
    # remove folder 'DYNAMIC_COMP_BIN' if exist
    system("rd $bin_folder") if (-d "$bin_folder");
    
    # re-create folder 'DYNAMIC_COMP_BIN'
    system("md $bin_folder");
    
}

sub checkSum {
	my ($identifier,$id_checksum) = @_;
  my $count = 0;
  my $checksum1="";
  my $checksum2="";
  my $checksum="";
  my @buffer = split(//,$identifier);
  my @buffer2 = reverse @buffer;
  foreach (@buffer2) {
    if ($count % 4 < 3) {
      $checksum1 = $checksum1.unpack("H*",$_);
    }
    if ($count % 4 == 3) {
      $checksum2 = $checksum1.unpack("H*",$_);
      $checksum = eval($checksum+hex($checksum2));
      $checksum1=undef;
      $checksum2=undef;
    }
    $count++;
  }
  $checksum=$checksum%(Math::BigInt->new('0x100000000'));
  my $result = ($checksum eq $id_checksum) ? 1 : 0;
  return $result;
}
=pod
sub checkSum 
{
  	my ($identifier,$id_checksum) = @_;
    my $count = 0;
    my $checksum1="";
    my $checksum2="";
    my $checksum="";
    my $unpacked_checksum = unpack 'V1', $id_checksum;
    my @buffer = split(//,$identifier);
    my @buffer2 = reverse @buffer;

    foreach (@buffer2) {

        if ($count % 4 < 3) {
            $checksum1 = $checksum1.unpack("H*",$_);
        }

        if ($count % 4 == 3) {
            $checksum2 = $checksum1.unpack("H*",$_);
            $checksum = eval($checksum+hex($checksum2));
            $checksum1=undef;
            $checksum2=undef;
        }

        $count++;

    }

    $checksum=$checksum%(Math::BigInt->new('0x100000000'));
    my $result = ($checksum eq $unpacked_checksum) ? 1 : 0;
    return $result;

}
=cut

#****************************************************************************
# subroutine:  GetInfo
# description: Get the basic information of processing
# input:       None
# output:      Info ref
#****************************************************************************
sub GetInfo
{
   return \%info;
}

sub Usage {
  print "perl dcmcomp_process.pl <bin file folder>\n";
  exit 1;
}

sub printLog
{
	 my $info = $_[0];
	 my $msg = $_[1];
   print "[DCM with compression] $info - $msg\n";
}

1;

