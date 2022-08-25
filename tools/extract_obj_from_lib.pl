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
############################################################

use File::stat;
use Cwd;

$lib_file = "init.lib";
$short_lib_file = "init.lib";
$obj_path = "init";
$ar_file = "c:\progra~1\arm\adsv1_2\bin\armar.exe";
$lis_file = ".\make\init\init.lis";
$current_lib = "";
$lis_path = ""; 


while ($#ARGV != -1) {
  if ($ARGV[0] =~ /-h/) {
    Usage();
  } elsif ($#ARGV > 2) {
    $lib_file = $ARGV[0];
    $obj_path = $ARGV[1]; 
    $ar_file = $ARGV[2];     
    $lis_file = $ARGV[3];     
    shift(@ARGV);
    shift(@ARGV);    
    shift(@ARGV);        
    shift(@ARGV);            
#    @arg_objs = @ARGV;
    
    last;
       
  } else {
    Usage();
  }
  #shift(@ARGV);
}


  $short_lib_file   =   "$lib_file" . "_bak";   
  if ( $lib_file =~  /\w+[\\|\/]{1}(\w+)(\.lib)\s*/)
  { 	
    $short_lib_file   = "$1$2"."_bak";
    $current_lib = lc($1);
  }

          
  if ( ! -e  $lib_file )
  {
  	   print " no $lib_file file \n";
  	   exit 0;
  }	  
          
          
  ##@files_in_lib_file =` $ar_file -t $lib_file `;

  
  if ( ! ( -e $lis_file))
  {  
  	
  	open (FILE_HANDLE, ".\\make\\ALIAS.mak") or die "cannot open .\\make\\ALIAS.mak\n";
    while (<FILE_HANDLE>) {
      if (/^(\S+)\s*=\s*(\S+)/) {
        $keyname = lc($1);
        $${keyname} = uc($2);
      }
    }
    close FILE_HANDLE;
   
    if($lis_file =~ /(.+module)/i)
    {
   	 $lis_path = $1;
    }
    
    if(defined $current_lib)
    {
   	 if($$current_lib =~ /PLUTOMMI/i )
   	 {
   		 $lis_file = $lis_path."\\PLUTOMMI\\$current_lib\\$current_lib.lis";
   	 }
   	 if($$current_lib =~ /VENUS/i )
   	 {
   		 $lis_file = $lis_path."\\VENUS\\$current_lib\\$current_lib.lis";
   	 }
    }
  }
  
  if ( ! ( -e $lis_file))
  {   
  	   print " $lis_file not exist ! \n";
  	   exit 0;
  } else
  {
  	   print " lis_file = $lis_file \n";
  	
  }


$inode = stat($lib_file);
$mtime = $inode->mtime;
$ctime = $inode->ctime;
$atime = $inode->atime;

print " mtime = $mtime \n";
print " ctime = $ctime \n";
print " atime = $atime \n";

#system "pause";


print "====================================\n";
print " lib_file = $lib_file \n";
print " obj_path = $obj_path \n";
print " ar_file  = $ar_file \n";
print " lis_file = $lis_file  \n";
print " short_lib_file = $short_lib_file \n";
print "====================================\n";

#system "pause";

#@a=<$obj_path\\*.obj>;
# foreach $xx (@a) 
#{
#	print " find obj, exit 0 \n";
#   exit 0;	
#}

  
  
  open(F, "<$lis_file");
  @objs=();
  
  $i =0;
  $obj;
 
  while (<F>)    
  {
  	  # print "$_ ";

     if ( /\w+[\\|\/]{1}(\w+\.)(c|cpp|s|arm)\s*$/)
     {	
     	 # print "2) i==$i, 1=$1,  2=$2,  \n\n";
     	 $obj = "$1" . "obj";
    	      	 
       push(@objs, "$obj"); 
     } 

  	$i = $i +1;
  }
  
  print " ====================== \n";
  
  print " objs  = @objs  \n";
  $obj=""; 
  
  @real_objs = ();  


      foreach $obj (@objs) {
        if (! (-e "$obj_path/$obj" ))
        {
#        	 unlink( $obj );
          print " not exist $obj_path\\$obj  \n";          
  #        print " $ar_file -x $lib_file $obj \n";          
  #        system " $ar_file -x $lib_file $obj"; 

#          print " ar_file ok \n";                            
          
          push(@real_objs, $obj);
            
            
            

        }  
        
        if ( -e "$obj_path/$obj" )
        {
           print " exist $obj_path\\$obj  \n";          
        }  
      	
      } # foreach 	


      $cwd = getcwd();
      chdir($obj_path);


     if ( ! @real_objs == ())
     {
          print " $ar_file -x $short_lib_file @real_objs \n";          
          system " $ar_file -x $short_lib_file @real_objs ";      	
     }	
     
      $obj=""; 
      
      
      
       
     foreach $obj (@real_objs) 
     {
          if ( -e $obj )
          {                             
            utime( $atime, $mtime, $obj);
            #print "$obj utime ok  \n";                    
            
          }  
          else 
          {
            print " no file $obj error ! \n";  
            exit 1;
          }  
                    
          ##print " copy $obj   $obj_path \n";                    
          ##system(" copy $obj   $obj_path ");                    
 #         unlink( $obj);
     }

      chdir($cwd);


   # unlink($lib_file) or die "Can't delete $lib_file";


exit 0;

sub Usage {
  print <<"__EOFUSAGE";
Usage: $0 [-h | lib_file obj_path obj_name ]
        -h       Help.
__EOFUSAGE
  exit 0;
}
