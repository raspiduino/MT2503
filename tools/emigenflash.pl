#!/usr/bin/perl
#

my $nor_fat_base_offset;
my $nor_fat_size_offset;
my $nor_partition_sector_offset;
my $nor_nand_fat_base_offset;
my $nor_nand_fat_size_offset;
my $nor_nand_partition_sector_offset;
my $nfb_fat_base_offset;
my $nfb_fat_size_offset;
my $nfb_partition_sector_offset;
my $cmem_max_blocks;
my $cmem_max_sectors;
my $nor_max_block_size;
my $nor_disk0_block_size;
my $DebugPrint    = 1; # 1 for debug; 0 for non-debug
require "tools/emigenMD.pl";
require "tools/config_MemSegment.pm";
&PrintDependency($0);
&PrintDependency('tools\emigenMD.pl');
#****************************************************************************
# subroutine:  Calculate_FAT_Info
# input:       $info_list_href:   input list reference of list of MDL info
#              $combo_mem_count:  number of memory devices selected
#              $combo_sip_count:  number of SIPs
#              $mem_dev_type:     MEMORY_DEVICE_TYPE
#              $info_output_href: output hash reference for common MDL info,
#                                 including minimum physical flash size,
#                                           minimum small block start address
#                                           maximum default FAT base address
#                                           minimum default FAT size
#                                           minimum RAM size
#                                           common flash series information
#                                           common single/multiple-bank definition
#                                           common PBP information
#                                           minimum PBP size
#****************************************************************************
sub Calculate_FAT_Info
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $COMM_MDL_INFO_LOCAL, $MDL_INFO_LIST_LOCAL, $NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, $NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL,$nor_size_Mb_LOCAL, $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $ENTIRE_BLOCK_INFO_START_LIST_LOCAL, $ENTIRE_BLOCK_INFO_SIZE_LIST_LOCAL) = @_;
    ### Print out the physical available flash size
    my $flash_limit = sprintf("0x%08X", $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});

    ### Calculate real FAT start address and size based on customization
    if ((defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS}) && (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_SIZE}))
    {
        $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL = hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS});
        $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL = hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_SIZE});
    }
    elsif ((defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS}) && (!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_SIZE}))
    {
        $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL = hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS});
        if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})  # for NOR FDM5, small blocks at the end of the flash should not be used
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Define NOR_FDM5 need to define FAT BASE and SIZE!", __FILE__, __LINE__);
            #$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL = $COMM_MDL_INFO_LOCAL->{0}->{'Small Block Start'} - hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS});
        }
        else
        {
            $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL = $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} - hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS});
        }
    }
    elsif ((!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS}) && (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_SIZE}))
    {
        if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})  # for NOR FDM5, small blocks at the end of the flash should not be used
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Define NOR_FDM5 need to define FAT BASE and SIZE!", __FILE__, __LINE__);
        }
        else
        {
            $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL = $COMM_MDL_INFO_LOCAL->{0}->{'Default FAT Base'};
            $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL = hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_SIZE});
        }
    }
    else
    {
        if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})  # for NOR FDM5, small blocks at the end of the flash should not be used
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Define NOR_FDM5 need to define FAT BASE and SIZE!", __FILE__, __LINE__);
        }
        else
        {
            $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL = $COMM_MDL_INFO_LOCAL->{0}->{'Default FAT Base'};
            $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL = $COMM_MDL_INFO_LOCAL->{0}->{'Default FAT Size'};
        }
    }

    ### work-around for bad small block issue
    my $fat_size_shrink;
    if ((($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL+$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL)>$COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'}) && (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL+$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL)<=($nor_size_Mb_LOCAL/8*1024*1024)))
    {
        $fat_size_shrink = sprintf(" - 0x%08x", $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL+$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL-$COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});
        $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL =  $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} - $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL;
    }

    print "NOR_FLASH_BASE_ADDRESS_VAL = $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, NOR_ALLOCATED_FAT_SPACE_VAL = $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL\n" if ($DebugPrint == 1);

    ### Check FAT settings validity
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: FAT address and space setting is wrong!", __FILE__, __LINE__)
        if (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL<0) || ($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL<0));
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: FAT space cannot exceed physical NOR flash size!", __FILE__, __LINE__)
        if (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL+$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > ($COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'}));
    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
    {
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: FAT space cannot include small blocks in NOR FDM 5.0!", __FILE__, __LINE__)
            if (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL+$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > $COMM_MDL_INFO_LOCAL->{0}->{'Small Block Start'});
    }

    ### FAT tuning for FOTA
    $nor_fat_base_offset = "0x0";
    $nor_fat_size_offset = "0x0";
    $nor_partition_sector_offset = 0;
    $nor_nand_fat_base_offset = "0x0";
    $nor_nand_fat_size_offset = "0x0";
    $nor_nand_partition_sector_offset = 0;
    $nfb_fat_base_offset = "0x0";
    $nfb_fat_size_offset = "0x0";
    $nfb_partition_sector_offset = 0;

    if ($MAKEFILE_OPTIONS_LOCAL->{'fota_enable'} eq 'FOTA_DM')
    {
        if ($MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} ne 'NONE')
        {
            ###
            # image head area size = block number * block size (0x20000)
            #                      = (1(FOTA_BL_IMG_MAX_SIZE) + 6(FOTA_UE_RESIDENT_FLASH_SPACE_SIZE) + 6(FOTA_UE_BACKUP_FLASH_SPACE_SIZE) + 8(image list block) + 1(ext_bootloader) + 2(bad block margin)) * 0x20000 = 0x300000
            my $image_head_area_size = 0x300000;

            my ($package_storage_base, $package_storage_size);
            ###
            # FOTA_PACKAGE_STORAGE_BASE = image head area size + all ROM sizes (ROM, SECONDARY_ROM, THIRD_ROM, DEMAND_PAGING_ROM0)
            if (defined $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} and $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} eq 'ENFB')
            {
                $package_storage_base = $image_head_area_size + 0x900000 + 0x1500000 + 0x800000;
            }
            elsif (defined $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} and $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} eq 'ONDEMAND')
            {
                $package_storage_base = $image_head_area_size + 0x400000 + 0xC00000 + 0xE00000;
            }
            elsif (defined $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} and $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} eq 'MIXED')
            {
                $package_storage_base = $image_head_area_size + 0x400000 + 0xF00000 + 0x800000 + 0x400000;
            }
            elsif (defined $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} and $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} eq 'BASIC')
            {
                $package_storage_base = $image_head_area_size + 0x800000 + 0x1600000;
            }
            $package_storage_size = (hex($CUSTOM_FEATURE_CFG_OPTIONS_LOCAL->{CONFIG_FOTA_PACKAGE_AREA_SIZE}) / 0x20000) * 0x20000;

            my $recommend_fat_base;
            if ($MAKEFILE_OPTIONS_LOCAL->{'secure_support'} eq 'TRUE')
            {
                # When SECURE_SUPPORT = TRUE, FAT_BASE_ADDRESS = FOTA_PACKAGE_STORAGE_BASE + FOTA_PACKAGE_STORAGE_SIZE + ((4 + FOTA_EXTRA_RESERVED_BLOCKS) * (block size)0x20000)
                $recommend_fat_base = $package_storage_base + $package_storage_size + ((4 + 5) * 0x20000);
            }
            else
            {
                # When SECURE_SUPPORT = FALSE, FAT_BASE_ADDRESS = FOTA_PACKAGE_STORAGE_BASE + FOTA_PACKAGE_STORAGE_SIZE
                $recommend_fat_base = $package_storage_base + $package_storage_size;
            }
            if (($recommend_fat_base - hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_BASE_ADDRESS})) > 0)
            {
                $nfb_fat_base_offset = sprintf("0x%08X", $recommend_fat_base - hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_BASE_ADDRESS}));
                $nfb_fat_size_offset = sprintf("0x%08X", $recommend_fat_base - hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_BASE_ADDRESS}));
                if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS})
                {
                    my $nand_fat_partition_sectors;
                    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS} =~ /\(*(\d+)\)*/)
                    {
                        $nand_fat_partition_sectors = $1;
                    }
                    $nfb_partition_sector_offset = sprintf("%d", ($recommend_fat_base - hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_BASE_ADDRESS})) / 512) if (($nand_fat_partition_sectors - ($recommend_fat_base-hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_BASE_ADDRESS}))/512) >= 4096);  # NAND user drive should be no less than 4096 sectors
                }
            }
        }
        elsif ($MAKEFILE_OPTIONS_LOCAL->{'system_drive_on_nand'} eq 'TRUE' or $MAKEFILE_OPTIONS_LOCAL->{'fota_update_package_on_nand'} eq 'TRUE')
        {
            my $package_storage_size = (hex($CUSTOM_FEATURE_CFG_OPTIONS_LOCAL->{CONFIG_FOTA_PACKAGE_AREA_SIZE}) / 0x20000) * 0x20000;
            $nor_nand_fat_base_offset = sprintf("0x%08X", $package_storage_size);
            $nor_nand_fat_size_offset = sprintf("0x%08X", $package_storage_size);
            if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS})
            {
                my $nand_fat_partition_sectors;
                if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS} =~ /\(*(\d+)\)*/)
                {
                    $nand_fat_partition_sectors = $1;
                }
                $nor_nand_partition_sector_offset = sprintf("%d", $package_storage_size / 512) if (($nand_fat_partition_sectors - ($package_storage_size)/512) >= 4096);  # NAND user drive should be no less than 4096 sectors
            }
        }
        elsif (!exists $MAKEFILE_OPTIONS_LOCAL->{'emmc_booting'} or $MAKEFILE_OPTIONS_LOCAL->{'emmc_booting'} eq 'NONE')  # FOTA update package will be put in a different partition from FS
        {
            my $fota_block_number = $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL->{CONFIG_FOTA_PACKAGE_BLOCK_NUMBER};
            my $ori_nor_flash_base_address_val = $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL;
            my $ori_nor_allocated_fat_space_val = $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL;

            ### Package Storage
            while ($fota_block_number > 0)
            {
                my $tmp_block_sz;
                $tmp_block_sz = &config_query_flash_block_sz($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, $COMM_MDL_INFO_LOCAL,$ENTIRE_BLOCK_INFO_START_LIST_LOCAL, $ENTIRE_BLOCK_INFO_SIZE_LIST_LOCAL);

                $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL += $tmp_block_sz;
                $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL -= $tmp_block_sz;
                $fota_block_number--;
            }

            ### Backup Storage
            my $query_address = 0;
            my $max_block_size = 0;
            while ($query_address < $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'})
            {
                my $cur_block_size = &config_query_flash_block_sz($query_address, $COMM_MDL_INFO_LOCAL, $ENTIRE_BLOCK_INFO_START_LIST_LOCAL, $ENTIRE_BLOCK_INFO_SIZE_LIST_LOCAL);
                if ($cur_block_size > $max_block_size)
                {
                    $max_block_size = $cur_block_size;
                }
                $query_address += $cur_block_size;
            }
            $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL += 2 * $max_block_size;
            $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL -= 2 * $max_block_size;

            if (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL - $ori_nor_flash_base_address_val) > 0)
            {
                $nor_fat_base_offset = sprintf("0x%08X", $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL - $ori_nor_flash_base_address_val);
                $nor_fat_size_offset = sprintf("0x%08X", $$ori_nor_allocated_fat_space_val - $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
                if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS})
                {
                    my $nor_fat_partition_sectors;
                    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS} =~ /\(*(\d+)\)*/)
                    {
                        $nor_fat_partition_sectors = $1;
                    }
                    $nor_partition_sector_offset = sprintf("%d", ($ori_nor_allocated_fat_space_val - $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) / 512) if (($nor_fat_partition_sectors - ($ori_nor_allocated_fat_space_val-$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL)/512) >= 128);  # NOR user drive should be no less than 128 sectors
                }
            }
        }
    } ### if ($MAKEFILE_OPTIONS_LOCAL->{'fota_enable'} eq 'FOTA_DM')

    ### Calculate TOTAL_BLOCKS and NOR_BLOCK_SIZE by different memory devices
    $cmem_max_blocks = 0;
    $cmem_max_sectors = 0;
    $nor_max_block_size = 0;
    $nor_disk0_block_size = 0;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $mem_idx    = $_;
        my (@cur_regions, @cur_banks, @cur_blocks, @cur_new_regions, @cur_blocks_start, @cur_blocks_size);
        my $cur_blocks_sum  = 0;
        my $cur_regions_sum = 0;
        my $cur_total_blocks = 0;
        my $cur_nor_block_size = 0;
        my $cur_total_sectors = 0;
        my $cur_sector_size = ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'Comm. Series'} eq 'INTEL_SIBLEY') ? 0x400 : 0x200;
        my @sds_block_size_all, @cur_blocks_sds ;
        my $sds_block_size, $sds_block_start, @tmp_sds_block_size;
        my $sds_block_count;
        my $sds_total_size;

        @cur_regions = &split_info($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'Last Bank'}->{'Region'});
        my $cur_bank_str = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'Device Geometry'}->{'Bank Info.'});
        @cur_banks   = &split_info($cur_bank_str);
        my $cur_block_str = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'Device Geometry'}->{'Block Info.'});
        my $cur_block_str_fdm5;
        my @cur_block_fdm5;
        my $cur_block_fdm5_tmp;
        if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
        {

            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                $cur_block_str_fdm5 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                @cur_block_fdm5 = &split_info($cur_block_str_fdm5);
                if ($cur_block_fdm5[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                {
                    last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                    $cur_block_fdm5_tmp = $2;
                }
                if(hex($cur_block_fdm5_tmp) < 65536)
                {
                    $cur_block_str = "\{0x0, 0x1000\}";
                    #print "test norfdm5\n";
                }
                else
                {
                    $cur_block_str = "\{0x0, 0x10000\}";
                    goto Label2;
                }
            }
        }
        Label2:
        ;#print "test Label2 $cur_block_str\n";
        if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
        {
            my @tmp_block_str_all;
            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                $tmp_block_str_all[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                @cur_blocks_sds = &split_info($tmp_block_str_all[$_]);
                if ($cur_blocks_sds[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                {
                    last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                    $tmp_sds_block_size[$_] = $2;
                }
                print "first temp block size : $tmp_sds_block_size[$_], block str : $tmp_block_str_all[$_]\n";
            }

            my $tmp_sds_start, $tmp_sds_last_block_start;


            ###judge sds block size
            my @cur_uni_block_str;
            my @cur_uni_block;
            my $tmp_max_block_size = 0;
            my @tmp_block_str, @tmp_block_size;
            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                $cur_uni_block_str[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                $cur_uni_block[$_] = &split_info_for_UB_SDS($cur_uni_block_str[$_]);
                if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                {
                    if($cur_uni_block[$_] ne '4')
                    {
                        $cur_block_str = "\{0x0, 0x10000\}";
                        goto Finally1;
                    }
                    else
                    {
                        #$sds_block_size = sprintf("0x%X", $cur_uni_block[$_]*1024);
                        $cur_block_str = "\{0x0, 0x1000\}";
                        #goto Finally1;
                    }
                }
                else
                {
                    if($cur_uni_block[$_] ne '4')
                    {
                        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                        {
                            if($tmp_max_block_size < hex($tmp_sds_block_size[$_]))
                            {
                                $tmp_max_block_size = $tmp_sds_block_size[$_];
                            }
                        }
                        $sds_block_size = $tmp_max_block_size;
                        goto Finally1;
                    }
                    else
                    {
                        $sds_block_size = sprintf("0x%X", $cur_uni_block[$_]*1024);
                    }
                }
            }
            ###
            if (!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
            {
                print "block info fisrt :$sds_block_size\n";
                $nor_disk0_block_size = hex($sds_block_size);

                #$tmp_sds_last_block_start = sprintf("0x%X", $block_start_href->[$i]);
                $sds_total_size = &memConfig::Get_SDS_total_size(hex($sds_block_size), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                $tmp_sds_start = sprintf("0x%X", $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} - $sds_total_size);
                $sds_block_start = sprintf("0x%X", $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} - hex($tmp_sds_block_size[$_]));
                $sds_block_count = (($sds_total_size)) / (hex($sds_block_size));
                print "beforesds block start:$sds_block_start, $sds_total_size, $tmp_sds_start, $sds_block_count\n";
                print "before block info fisrt :$sds_block_size, $tmp_sds_start, $sds_total_size\n";
                while(hex($sds_block_start) > hex($tmp_sds_start))
                {
                    $sds_block_start = sprintf("0x%X", hex($sds_block_start) - hex($tmp_sds_block_size[$_]));
                }
                print "after sds block start:$sds_block_start\n";
                $cur_block_str .= "\{$sds_block_start, $sds_block_size\}";
            }
            Finally1:
            print "test finally1\n";
        } ### if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))


        if (($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
        {
            my @tmp_block_str_all;

            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                $tmp_block_str_all[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});

                @cur_blocks_sds = &split_info($tmp_block_str_all[$_]);

                if ($cur_blocks_sds[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                {
                    last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                    $tmp_sds_block_size[$_] = $2;
                }

                print "first temp block size : $tmp_sds_block_size[$_], block str : $tmp_block_str_all[$_]\n";
            }

            my $tmp_sds_start, $tmp_sds_last_block_start;

            ###judge sds block size
            my @cur_uni_block_str;
            my @cur_uni_block;
            my $tmp_max_block_size = 0;
            my @tmp_block_str, @tmp_block_size;

            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                $cur_uni_block_str[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                $cur_uni_block[$_] = &split_info_for_UB_SDS($cur_uni_block_str[$_]);
                if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                {
                    if ($cur_uni_block[$_] ne '4')
                    {
                        $cur_block_str = "\{0x0, 0x10000\}";
                        $sds_block_size = sprintf("0x%X", 64*1024);
                        goto Finally6;
                    }
                    else
                    {
                        $cur_block_str = "\{0x0, 0x1000\}";
                        $sds_block_size = sprintf("0x%X", 4*1024);
                        #goto Finally10;
                    }
                }
                else
                {
                    if ($cur_uni_block[$_] ne '4')
                    {
                        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                        {
                            if($tmp_max_block_size < hex($tmp_sds_block_size[$_]))
                            {
                                $tmp_max_block_size = $tmp_sds_block_size[$_];
                            }
                        }

                        $sds_block_size = $tmp_max_block_size;
                        goto Finally6;
                    }
                    else
                    {
                        $sds_block_size = sprintf("0x%X", $cur_uni_block[$_]*1024);
                    }
                }
            }
            ###
            Finally6:
            print "block info fisrt :$sds_block_size\n";
            $nor_disk0_block_size = hex($sds_block_size);
        } ### if (($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))


        print "calculate cur block str : $cur_block_str\n";
        for (0..$#$ENTIRE_BLOCK_INFO_START_LIST_LOCAL)
        {
            print "block info:$ENTIRE_BLOCK_INFO_START_LIST_LOCAL->[$_], $ENTIRE_BLOCK_INFO_SIZE_LIST_LOCAL->[$_]\n";
        }
        @cur_blocks  = &split_info($cur_block_str);
        for (0..$#cur_blocks)
        {
            if ($cur_blocks[$_] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
            {
                last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                push @cur_blocks_start, $1;
                push @cur_blocks_size, $2;
            }
        }

        push @cur_blocks_start, $flash_limit;
        for (0..($#cur_blocks_start-1))
        {

            my $target_region = $cur_blocks_size[$_];
            my $tmp_block_count = 0;
            while ($cur_blocks_sum < hex($cur_blocks_start[$_+1]))
            {
                $cur_blocks_sum += hex($cur_blocks_size[$_]);
                if ($cur_blocks_sum > $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL)
                {
                    $cur_regions_sum += hex($cur_blocks_size[$_]);
                    $tmp_block_count++;
                }
                last if ($cur_regions_sum >= $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
            }

            if ($tmp_block_count > 0)
            {
                $cur_total_blocks += $tmp_block_count;
                if (hex($target_region) > hex($cur_nor_block_size))  # Find the largest block size within FS
                {
                    $cur_nor_block_size = $target_region;
                }
            }
            last if ($cur_regions_sum >= $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
        }

        #if($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} ne 'ENABLE')
        #{
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: FAT space must be multiples of blocks!", __FILE__, __LINE__) if ($cur_regions_sum > $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
        #}
        if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
        {
            $cur_total_blocks = $cur_total_blocks - $sds_block_count;
        }

        if ((($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > (hex($flash_limit) - $sds_total_size)) && (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) < (hex($flash_limit))))
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: FAT space not allowed to be the middle of the sds region!", __FILE__, __LINE__);
        }

        if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') && (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) != (hex($flash_limit))))
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: FAT base + size must = flash size when sds enable!", __FILE__, __LINE__);
        }

        ### Calculate the current number of sectors
        ### S1 = ((NOR_ALLOCATED_FAT_SPACE - NOR_BLOCK_SIZEMCP1 * SNOR_ERASE_QUEUE_SIZE) / SECTOR_SIZE)
        ### NOR_ALLOCATED_FAT_SPACE := NOR_BOOTING_NOR_FS_SIZE
        ### SNOR_ERASE_QUEUE_SIZE := NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE or 5 (default value)
        ### NOR_SYSTEM_DRIVE_RESERVED_BLOCK := NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK or 3 (default value)
        ### NOR_BLOCK_SIZEMCP1 := The largest block size within FAT in MCP 1.
        ### SECTOR_SIZE:
        ### Sibley:=0x400
        ### Non-Sibley := 0x200
        if ($MAKEFILE_OPTIONS_LOCAL->{'enhanced_single_bank_nor_flash_support'} eq 'TRUE')
        {
            if(($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
            {
                $cur_total_sectors = (($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - $sds_total_size) - (hex($cur_nor_block_size) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE})) / $cur_sector_size;
            }
            else
            {
                $cur_total_sectors = ($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - (hex($cur_nor_block_size) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE})) / $cur_sector_size;
            }

        }
        else
        {
            if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
            {
                $cur_total_sectors = (($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - $sds_total_size) - (hex($cur_nor_block_size) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK})) / $cur_sector_size;
            }
            else
            {
                $cur_total_sectors = ($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - (hex($cur_nor_block_size) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK})) / $cur_sector_size;
            }
        }

        ### Find the overall max TOTAL_BLOCKS and NOR_BLOCK_SIZE
        if ($nor_max_block_size < hex($cur_nor_block_size))
        {
            $nor_max_block_size = hex($cur_nor_block_size);
        }
        if ($cmem_max_blocks < $cur_total_blocks)
        {
            $cmem_max_blocks = $cur_total_blocks;
        }
        if ($cmem_max_sectors < $cur_total_sectors)
        {
            $cmem_max_sectors = $cur_total_sectors;
        }
    } ### for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})

    print "\$nor_max_block_size: $nor_max_block_size, \$cmem_max_blocks: $cmem_max_blocks, \$cmem_max_sectors : $cmem_max_sectors\n";

    print "TOTAL_BLOCKS > 127 , recommend enable FDM5.0 feature!\n" if ($cmem_max_blocks > 127);
}

#****************************************************************************
# subroutine:  Calculate_FAT_Info
# input:       $info_list_href:   input list reference of list of MDL info
#              $combo_mem_count:  number of memory devices selected
#              $combo_sip_count:  number of SIPs
#              $mem_dev_type:     MEMORY_DEVICE_TYPE
#              $info_output_href: output hash reference for common MDL info,
#                                 including minimum physical flash size,
#                                           minimum small block start address
#                                           maximum default FAT base address
#                                           minimum default FAT size
#                                           minimum RAM size
#                                           common flash series information
#                                           common single/multiple-bank definition
#                                           common PBP information
#                                           minimum PBP size
#****************************************************************************
sub Calculate_FAT_Info_DUAL_SF
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $COMM_MDL_INFO_LOCAL, $MDL_INFO_LIST_LOCAL, $NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, $NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL,$nor_size_Mb_LOCAL, $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $ENTIRE_BLOCK_INFO_START_LIST_LOCAL, $ENTIRE_BLOCK_INFO_SIZE_LIST_LOCAL) = @_;
    ### Print out the physical available flash size
    my $flash_limit = sprintf("0x%08X", ($COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'}));
    my $flash_limit_cs0 ;
    my $flash_limit_cs1 ;

    ### Calculate real FAT start address and size based on customization
    if ((defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS}) && (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_SIZE}))
    {
        $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL = hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS});
        $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL = hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_SIZE});
    }
    elsif ((defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS}) && (!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_SIZE}))
    {
        $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL = hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS});
        if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})  # for NOR FDM5, small blocks at the end of the flash should not be used
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Define NOR_FDM5 need to define FAT BASE and SIZE!", __FILE__, __LINE__);
        }
        else
        {
            $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL = $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} - hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS});
        }
    }
    elsif ((!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_BASE_ADDRESS}) && (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_SIZE}))
    {
        if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})  # for NOR FDM5, small blocks at the end of the flash should not be used
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Define NOR_FDM5 need to define FAT BASE and SIZE!", __FILE__, __LINE__);
        }
        else
        {
            $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL = $COMM_MDL_INFO_LOCAL->{0}->{'Default FAT Base'};
            $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL = hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_SIZE});
        }
    }
    else
    {
        if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})  # for NOR FDM5, small blocks at the end of the flash should not be used
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Define NOR_FDM5 need to define FAT BASE and SIZE!", __FILE__, __LINE__);
        }
        else
        {
            $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL = $COMM_MDL_INFO_LOCAL->{0}->{'Default FAT Base'};
            $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL = $COMM_MDL_INFO_LOCAL->{0}->{'Default FAT Size'};
        }
    }

    ### work-around for bad small block issue
    my $fat_size_shrink;
    if ((($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL+$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL)>$COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'}) && (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL+$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL)<=($nor_size_Mb_LOCAL/8*1024*1024)))
    {
        $fat_size_shrink = sprintf(" - 0x%08x", $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL+$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL-$COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});
        $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL = $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - ($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL+$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL-$COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});
    }

    print "NOR_FLASH_BASE_ADDRESS_VAL = $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, NOR_ALLOCATED_FAT_SPACE_VAL = $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL\n" if ($DebugPrint == 1);

    ### Check FAT settings validity
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: FAT address and space setting is wrong!", __FILE__, __LINE__)
        if (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL<0) || ($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL<0));
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: FAT space cannot exceed physical NOR flash size!", __FILE__, __LINE__)
        if (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL+$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});
    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
    {
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: FAT space cannot include small blocks in NOR FDM 5.0!", __FILE__, __LINE__)
            if (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL+$$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > $COMM_MDL_INFO_LOCAL->{0}->{'Small Block Start'});
    }

    ### FAT tuning for FOTA
    $nor_fat_base_offset = "0x0";
    $nor_fat_size_offset = "0x0";
    $nor_partition_sector_offset = 0;
    $nor_nand_fat_base_offset = "0x0";
    $nor_nand_fat_size_offset = "0x0";
    $nor_nand_partition_sector_offset = 0;
    $nfb_fat_base_offset = "0x0";
    $nfb_fat_size_offset = "0x0";
    $nfb_partition_sector_offset = 0;

    if ($MAKEFILE_OPTIONS_LOCAL->{'fota_enable'} eq 'FOTA_DM')
    {
        if ($MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} ne 'NONE')
        {
            ###
            # image head area size = block number * block size (0x20000)
            #                      = (1(FOTA_BL_IMG_MAX_SIZE) + 6(FOTA_UE_RESIDENT_FLASH_SPACE_SIZE) + 6(FOTA_UE_BACKUP_FLASH_SPACE_SIZE) + 8(image list block) + 1(ext_bootloader) + 2(bad block margin)) * 0x20000 = 0x300000
            my $image_head_area_size = 0x300000;

            my ($package_storage_base, $package_storage_size);
            ###
            # FOTA_PACKAGE_STORAGE_BASE = image head area size + all ROM sizes (ROM, SECONDARY_ROM, THIRD_ROM, DEMAND_PAGING_ROM0)
            if (defined $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} and $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} eq 'ENFB')
            {
                $package_storage_base = $image_head_area_size + 0x900000 + 0x1500000 + 0x800000;
            }
            elsif (defined $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} and $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} eq 'ONDEMAND')
            {
                $package_storage_base = $image_head_area_size + 0x400000 + 0xC00000 + 0xE00000;
            }
            elsif (defined $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} and $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} eq 'MIXED')
            {
                $package_storage_base = $image_head_area_size + 0x400000 + 0xF00000 + 0x800000 + 0x400000;
            }
            elsif (defined $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} and $MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} eq 'BASIC')
            {
                $package_storage_base = $image_head_area_size + 0x800000 + 0x1600000;
            }
            $package_storage_size = (hex($CUSTOM_FEATURE_CFG_OPTIONS_LOCAL->{CONFIG_FOTA_PACKAGE_AREA_SIZE}) / 0x20000) * 0x20000;

            my $recommend_fat_base;
            if ($MAKEFILE_OPTIONS_LOCAL->{'secure_support'} eq 'TRUE')
            {
                # When SECURE_SUPPORT = TRUE, FAT_BASE_ADDRESS = FOTA_PACKAGE_STORAGE_BASE + FOTA_PACKAGE_STORAGE_SIZE + ((4 + FOTA_EXTRA_RESERVED_BLOCKS) * (block size)0x20000)
                $recommend_fat_base = $package_storage_base + $package_storage_size + ((4 + 5) * 0x20000);
            }
            else
            {
                # When SECURE_SUPPORT = FALSE, FAT_BASE_ADDRESS = FOTA_PACKAGE_STORAGE_BASE + FOTA_PACKAGE_STORAGE_SIZE
                $recommend_fat_base = $package_storage_base + $package_storage_size;
            }
            if (($recommend_fat_base - hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_BASE_ADDRESS})) > 0)
            {
                $nfb_fat_base_offset = sprintf("0x%08X", $recommend_fat_base - hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_BASE_ADDRESS}));
                $nfb_fat_size_offset = sprintf("0x%08X", $recommend_fat_base - hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_BASE_ADDRESS}));
                if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS})
                {
                    my $nand_fat_partition_sectors;
                    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS} =~ /\(*(\d+)\)*/)
                    {
                        $nand_fat_partition_sectors = $1;
                    }
                    $nfb_partition_sector_offset = sprintf("%d", ($recommend_fat_base - hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_BASE_ADDRESS})) / 512) if (($nand_fat_partition_sectors - ($recommend_fat_base-hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NAND_BOOTING_NAND_FS_BASE_ADDRESS}))/512) >= 4096);  # NAND user drive should be no less than 4096 sectors
                }
            }
        }
        elsif ($MAKEFILE_OPTIONS_LOCAL->{'system_drive_on_nand'} eq 'TRUE' or $MAKEFILE_OPTIONS_LOCAL->{'fota_update_package_on_nand'} eq 'TRUE')
        {
            my $package_storage_size = (hex($CUSTOM_FEATURE_CFG_OPTIONS_LOCAL->{CONFIG_FOTA_PACKAGE_AREA_SIZE}) / 0x20000) * 0x20000;
            $nor_nand_fat_base_offset = sprintf("0x%08X", $package_storage_size);
            $nor_nand_fat_size_offset = sprintf("0x%08X", $package_storage_size);
            if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS})
            {
                my $nand_fat_partition_sectors;
                if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS} =~ /\(*(\d+)\)*/)
                {
                    $nand_fat_partition_sectors = $1;
                }
                $nor_nand_partition_sector_offset = sprintf("%d", $package_storage_size / 512) if (($nand_fat_partition_sectors - ($package_storage_size)/512) >= 4096);  # NAND user drive should be no less than 4096 sectors
            }
        }
        elsif (!exists $MAKEFILE_OPTIONS_LOCAL->{'emmc_booting'} or $MAKEFILE_OPTIONS_LOCAL->{'emmc_booting'} eq 'NONE')  # FOTA update package will be put in a different partition from FS
        {
            my $fota_block_number = $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL->{CONFIG_FOTA_PACKAGE_BLOCK_NUMBER};
            my $ori_nor_flash_base_address_val = $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL;
            my $ori_nor_allocated_fat_space_val = $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL;

            ### Package Storage
            while ($fota_block_number > 0)
            {
                my $tmp_block_sz;
                $tmp_block_sz = &config_query_flash_block_sz($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, $COMM_MDL_INFO_LOCAL,$ENTIRE_BLOCK_INFO_START_LIST_LOCAL, $ENTIRE_BLOCK_INFO_SIZE_LIST_LOCAL);

                $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL += $tmp_block_sz;
                $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL -= $tmp_block_sz;
                $fota_block_number--;
            }

            ### Backup Storage
            my $query_address = 0;
            my $max_block_size = 0;
            while ($query_address < ($COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} + $COMM_MDL_INFO_LOCAL->{1}->{'Flash Size'}))
            {
                my $cur_block_size = &config_query_flash_block_sz($query_address, $COMM_MDL_INFO_LOCAL, $ENTIRE_BLOCK_INFO_START_LIST_LOCAL, $ENTIRE_BLOCK_INFO_SIZE_LIST_LOCAL);
                if ($cur_block_size > $max_block_size)
                {
                    $max_block_size = $cur_block_size;
                }
                $query_address += $cur_block_size;
            }
            $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL += 2 * $max_block_size;
            $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL -= 2 * $max_block_size;

            if (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL - $ori_nor_flash_base_address_val) > 0)
            {
                $nor_fat_base_offset = sprintf("0x%08X", $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL - $ori_nor_flash_base_address_val);
                $nor_fat_size_offset = sprintf("0x%08X", $$ori_nor_allocated_fat_space_val - $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
                if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS})
                {
                    my $nor_fat_partition_sectors;
                    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS} =~ /\(*(\d+)\)*/)
                    {
                        $nor_fat_partition_sectors = $1;
                    }
                    $nor_partition_sector_offset = sprintf("%d", ($ori_nor_allocated_fat_space_val - $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) / 512) if (($nor_fat_partition_sectors - ($ori_nor_allocated_fat_space_val-$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL)/512) >= 128);  # NOR user drive should be no less than 128 sectors
                }
            }
        }
    }

    ### Calculate TOTAL_BLOCKS and NOR_BLOCK_SIZE by different memory devices
    $cmem_max_blocks = 0;
    $cmem_max_sectors = 0;
    $nor_block_size = 0;
    $nor_max_block_size = 0;
    $nor_disk0_block_size = 0;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $mem_idx    = $_;
        my (@cur_regions_cs0, @cur_banks_cs0, @cur_blocks_cs0, @cur_new_regions_cs0, @cur_blocks_start_cs0, @cur_blocks_size_cs0);
        my (@cur_regions_cs1, @cur_banks_cs1, @cur_blocks_cs1, @cur_new_regions_cs1, @cur_blocks_start_cs1, @cur_blocks_size_cs1);
        my $cur_blocks_sum_cs0  = 0;
        my $cur_regions_sum_cs0 = 0;
        my $cur_total_blocks_cs0 = 0;
        my $cur_nor_block_size_cs0 = 0;
        my $cur_total_sectors_cs0 = 0;

        my $cur_blocks_sum_cs1  = 0;
        my $cur_regions_sum_cs1 = 0;
        my $cur_total_blocks_cs1 = 0;
        my $cur_nor_block_size_cs1 = 0;
        my $cur_total_sectors_cs1 = 0;

        my $cur_total_blocks = 0;

        my $cur_sector_size = ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'Comm. Series'} eq 'INTEL_SIBLEY') ? 0x400 : 0x200;

        $flash_limit_cs0 = sprintf("0x%08X", ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'Size (Mb)'}*1024*1024/8));
        $flash_limit_cs1 = sprintf("0x%08X", ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{1}->{'Size (Mb)'}*1024*1024/8));
        #print "flash limit:$flash_limit_cs0,$flash_limit_cs1\n";

        my @sds_block_size_all_cs0, @cur_blocks_sds_cs0 ;
        my $sds_block_size_cs0, $sds_block_start_cs0, @tmp_sds_block_size_cs0;
        my $sds_block_count_cs0;
        my $sds_total_size_cs0;

        my @sds_block_size_all_cs1, @cur_blocks_sds_cs1 ;
        my $sds_block_size_cs1, $sds_block_start_cs1, @tmp_sds_block_size_cs1;
        my $sds_block_count_cs1;
        my $sds_total_size_cs1;

        @cur_regions = &split_info($MDL_INFO_LIST_LOCAL->[$mem_idx]->{1}->{'Last Bank'}->{'Region'});
        #my $cur_bank_str = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'Device Geometry'}->{'Bank Info.'});
        #@cur_banks   = &split_info($cur_bank_str);
        my $cur_block_str_cs0 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{0}->{'Device Geometry'}->{'Block Info.'});
        my $cur_block_str_cs1 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$mem_idx]->{1}->{'Device Geometry'}->{'Block Info.'});
        my $cur_block_str_fdm5_cs0;
        my $cur_block_str_fdm5_cs1;
        my @cur_block_fdm5_cs0;
        my @cur_block_fdm5_cs1;
        my $cur_block_fdm5_tmp_cs0;
        my $cur_block_fdm5_tmp_cs1;
        if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
        {

            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                $cur_block_str_fdm5_cs0 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                $cur_block_str_fdm5_cs1 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
                @cur_block_fdm5_cs0 = &split_info($cur_block_str_fdm5_cs0);
                @cur_block_fdm5_cs1 = &split_info($cur_block_str_fdm5_cs1);
                if ($cur_block_fdm5_cs0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                {
                    last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                    $cur_block_fdm5_tmp_cs0 = $2;
                }

                if(hex($cur_block_fdm5_tmp_cs0) < 65536)
                {
                    $cur_block_str_cs0 = "\{0x0, 0x1000\}";
                }
                else
                {
                    $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                    $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                    goto Label3;
                }

                ###CS1
                if ($cur_block_fdm5_cs1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                {
                    last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                    $cur_block_fdm5_tmp_cs1 = $2;
                }

                if(hex($cur_block_fdm5_tmp_cs1) < 65536)
                {
                    $cur_block_str_cs1 = "\{0x0, 0x1000\}";
                }
                else
                {
                    $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                    $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                    goto Label3;
                }
            }
        }
        Label3:
        ;#print "test Label3 $cur_block_str_cs0, $cur_block_str_cs1\n";
        if(($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
        {
            my @tmp_block_str_all_cs0, @tmp_block_str_all_cs1;
            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                $tmp_block_str_all_cs0[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                $tmp_block_str_all_cs1[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
                @cur_blocks_sds_cs0 = &split_info($tmp_block_str_all_cs0[$_]);
                @cur_blocks_sds_cs1 = &split_info($tmp_block_str_all_cs1[$_]);
                if ($cur_blocks_sds_cs0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                {
                    last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                    $tmp_sds_block_size_cs0[$_] = $2;
                }

                if ($cur_blocks_sds_cs1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                {
                    last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                    $tmp_sds_block_size_cs1[$_] = $2;
                }
                # print "first temp block size : $tmp_sds_block_size_cs0[$_], $tmp_sds_block_size_cs1[$_],block str : $tmp_block_str_all_cs0[$_], $tmp_block_str_all_cs1[$_]\n";
            }

            my $tmp_sds_start_cs0, $tmp_sds_last_block_start_cs0;
            my $tmp_sds_start_cs1, $tmp_sds_last_block_start_cs1;


            ###judge sds block size
            my @cur_uni_block_str_cs0,@cur_uni_block_str_cs1;
            my @cur_uni_block_cs0,@cur_uni_block_cs1;
            my $tmp_max_block_size_cs0 = 0;
            my $tmp_max_block_size_cs1 = 0;
            my @tmp_block_str_cs0, @tmp_block_size_cs0;
            my @tmp_block_str_cs1, @tmp_block_size_cs1;
            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                $cur_uni_block_str_cs0[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                $cur_uni_block_cs0[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs0[$_]);
                $cur_uni_block_str_cs1[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Uniform Block (KB)'};
                $cur_uni_block_cs1[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs1[$_]);
                if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                {

                    if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                    {
                        $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                        $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                        goto Finally11;
                    }
                    else
                    {
                        $cur_block_str_cs0 = "\{0x0, 0x1000\}";
                    }

                    if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                    {
                        $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                        $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                        goto Finally11;
                    }
                    else
                    {
                        $cur_block_str_cs1 = "\{0x0, 0x1000\}";
                    }
                }
                else
                {
                    if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                    {
                        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                        {
                            if($tmp_max_block_size_cs0 < hex($tmp_sds_block_size_cs0[$_]))
                            {
                                $tmp_max_block_size_cs0 = $tmp_sds_block_size_cs0[$_];
                            }
                        }
                        $sds_block_size_cs0 = $tmp_max_block_size_cs0;
                        #goto Finally1;
                    }
                    else
                    {
                        $sds_block_size_cs0 = sprintf("0x%X", $cur_uni_block_cs0[$_]*1024);
                    }

                    if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                    {
                        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                        {
                            if($tmp_max_block_size_cs1 < hex($tmp_sds_block_size_cs1[$_]))
                            {
                                $tmp_max_block_size_cs1 = $tmp_sds_block_size_cs1[$_];
                            }
                        }
                        $sds_block_size_cs1 = $tmp_max_block_size_cs1;
                        goto Finally11;
                    }
                    else
                    {
                        $sds_block_size_cs1 = sprintf("0x%X", $cur_uni_block_cs1[$_]*1024);
                    }
                }
            }
            ###
            #Finally11:
            #    print "test finally11\n";
            #print "block info fisrt :$sds_block_size\n";
            #$tmp_sds_last_block_start = sprintf("0x%X", $block_start_href->[$i]);
            if (!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
            {
                $sds_total_size_cs0 = &memConfig::Get_SDS_total_size(hex($sds_block_size_cs0), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                $tmp_sds_start_cs0 = sprintf("0x%X", hex($flash_limit_cs0) - $sds_total_size_cs0);
                $sds_block_start_cs0 = sprintf("0x%X", hex($flash_limit_cs0) - hex($tmp_sds_block_size_cs0[$_]));
                #$sds_block_count_cs0 = (($sds_total_size)) / (hex($sds_block_size));

                while(hex($sds_block_start_cs0) > hex($tmp_sds_start_cs0))
                {
                    $sds_block_start_cs0 = sprintf("0x%X", hex($sds_block_start_cs0) - hex($tmp_sds_block_size_cs0[$_]));
                }
                #print "sds block start:$sds_block_start\n";
                $cur_block_str_cs0 .= "\{$sds_block_start_cs0, $sds_block_size_cs0\}";

                $sds_total_size_cs1 = &memConfig::Get_SDS_total_size(hex($sds_block_size_cs1), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                $tmp_sds_start_cs1 = sprintf("0x%X", hex($flash_limit_cs1) - $sds_total_size_cs1);
                $sds_block_start_cs1 = sprintf("0x%X", hex($flash_limit_cs1) - hex($tmp_sds_block_size_cs1[$_]));
                $sds_block_count_cs1 = (($sds_total_size_cs1)) / (hex($sds_block_size_cs1));
                #print "beforesds block start:$sds_block_start, $sds_total_size, $tmp_sds_start, $sds_block_count\n";
                #print "before block info fisrt :$sds_block_size, $tmp_sds_start, $sds_total_size\n";
                while(hex($sds_block_start_cs1) > hex($tmp_sds_start_cs1))
                {
                    $sds_block_start_cs1 = sprintf("0x%X", hex($sds_block_start_cs1) - hex($tmp_sds_block_size_cs1[$_]));
                }
                #print "sds block start:$sds_block_start\n";
                $cur_block_str_cs1 .= "\{$sds_block_start_cs1, $sds_block_size_cs1\}";
                #$cur_block_str_cs0 .= $cur_block_str_cs1;
            }
            Finally11:
            print "test finally11\n";

        }
        # print "calculate FAT cur block str : $cur_block_str_cs0, $cur_block_str_cs1, $sds_total_size_cs1\n";

        if(($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
        {
            my @tmp_block_str_all_cs0;
            my @tmp_block_str_all_cs1;

            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                $tmp_block_str_all_cs0[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                $tmp_block_str_all_cs1[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});

                @cur_blocks_sds_cs0 = &split_info($tmp_block_str_all_cs0[$_]);
                @cur_blocks_sds_cs1 = &split_info($tmp_block_str_all_cs1[$_]);

                if ($cur_blocks_sds_cs0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                {
                    last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                    $tmp_sds_block_size_cs0[$_] = $2;
                }

                if ($cur_blocks_sds_cs1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                {
                    last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                    $tmp_sds_block_size_cs1[$_] = $2;
                }

                #   print "first temp block size : $tmp_sds_block_size_cs0[$_],$tmp_sds_block_size_cs0[$_], block str : $tmp_block_str_all_cs0[$_],$tmp_block_str_all_cs1[$_]\n";
            }

            my $tmp_sds_start_cs0, $tmp_sds_last_block_start_cs0;
            my $sds_total_size_cs0;

            my $tmp_sds_start_cs1, $tmp_sds_last_block_start_cs1;
            my $sds_total_size_cs1;

            ###judge sds block size
            my @cur_uni_block_str_cs0;
            my @cur_uni_block_cs0;
            my $tmp_max_block_size_cs0 = 0;
            my @tmp_block_str_cs0, @tmp_block_size_cs0;

            my @cur_uni_block_str_cs1;
            my @cur_uni_block_cs1;
            my $tmp_max_block_size_cs1 = 0;
            my @tmp_block_str_cs1, @tmp_block_size_cs1;

            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                $cur_uni_block_str_cs0[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                $cur_uni_block_cs0[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs0[$_]);

                $cur_uni_block_str_cs1[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Uniform Block (KB)'};
                $cur_uni_block_cs1[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs1[$_]);
                if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                {

                    if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                    {
                        $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                        $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                        $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                        $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                        goto Finally5;
                    }
                    else
                    {
                        $cur_block_str_cs0 = "\{0x0, 0x1000\}";
                        $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                        $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                    }

                    if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                    {
                        $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                        $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                        $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                        $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                        goto Finally5;
                    }
                    else
                    {
                        $cur_block_str_cs1 = "\{0x0, 0x1000\}";
                        $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                        $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                    }
                }
                else
                {
                    if($cur_uni_block_cs0[$_] ne '4')
                    {
                        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                        {
                            if($tmp_max_block_size_cs0 < hex($tmp_sds_block_size_cs0[$_]))
                            {
                                $tmp_max_block_size_cs0 = $tmp_sds_block_size_cs0[$_];
                            }
                        }

                        $sds_block_size_cs0 = $tmp_max_block_size_cs0;
                        goto Finally5;
                    }
                    else
                    {
                        $sds_block_size_cs0 = sprintf("0x%X", $cur_uni_block_cs0[$_]*1024);
                    }

                    if($cur_uni_block_cs1[$_] ne '4')
                    {
                        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                        {
                            if($tmp_max_block_size_cs1 < hex($tmp_sds_block_size_cs1[$_]))
                            {
                                $tmp_max_block_size_cs1 = $tmp_sds_block_size_cs1[$_];
                            }
                        }

                        $sds_block_size_cs1 = $tmp_max_block_size_cs1;
                        goto Finally5;
                    }
                    else
                    {
                        $sds_block_size_cs1 = sprintf("0x%X", $cur_uni_block_cs1[$_]*1024);
                    }
                }
            }
            ###
            Finally5:
            print "test finally5\n";
            print "block info fisrt :$sds_block_size_cs0, $sds_block_size_cs1\n";
            if(hex($sds_block_size_cs0) > hex($sds_block_size_cs1))
            {
                $nor_disk0_block_size = hex($sds_block_size_cs0);
            }
            else
            {
                $nor_disk0_block_size = hex($sds_block_size_cs1);
            }

        }
        # for(0..$#$ENTIRE_BLOCK_INFO_START_LIST_LOCAL)
        # {
        #    print "block info:$ENTIRE_BLOCK_INFO_START_LIST_LOCAL->[$_], $ENTIRE_BLOCK_INFO_SIZE_LIST_LOCAL->[$_]\n";
        # }
        @cur_blocks_cs0  = &split_info($cur_block_str_cs0);
        @cur_blocks_cs1  = &split_info($cur_block_str_cs1);
        for (0..$#cur_blocks_cs0)
        {
            if ($cur_blocks_cs0[$_] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
            {
                last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                push @cur_blocks_start_cs0, $1;
                push @cur_blocks_size_cs0, $2;
            }
        }

        for (0..$#cur_blocks_cs1)
        {
            if ($cur_blocks_cs1[$_] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
            {

                last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                push @cur_blocks_start_cs1, $1;
                push @cur_blocks_size_cs1, $2;

            }
        }

        if(hex($cur_blocks_size_cs1[0]) == 0)
        {
            push @cur_blocks_start_cs0, $flash_limit_cs0;
        }
        else
        {

            for(0..$#cur_blocks_start_cs1)
            {
                $cur_blocks_start_cs1[$_] = sprintf("0x%X", hex($flash_limit_cs0) + hex($cur_blocks_start_cs1[$_]));
            }
            push @cur_blocks_start_cs1, $flash_limit;

        }

        for(0..$#cur_blocks_size_cs0)
        {
            # print "size cs0 : $cur_blocks_size_cs0[$_]\n";
        }
        my $block_size_count = $#cur_blocks_size_cs0;
        my $block_start_count = $#cur_blocks_start_cs0;
        for(0..$#cur_blocks_size_cs1)
        {
            if(hex($cur_blocks_size_cs1[0]) == 0)
            {

            }
            else
            {
                $cur_blocks_size_cs0[$_+$block_size_count+1] = $cur_blocks_size_cs1[$_];
                #  print "size cs1 : $cur_blocks_size_cs1[$_]\n";
            }

        }

        for(0..$#cur_blocks_size_cs0)
        {
            #    print "size cs0 : $cur_blocks_size_cs0[$_]\n";
        }

        for(0..$#cur_blocks_start_cs0)
        {
            #    print "start test cs0 : $cur_blocks_start_cs0[$_]\n";
        }



        for(0..$#cur_blocks_start_cs1)
        {
            if(hex($cur_blocks_size_cs1[0]) == 0)
            {

            }
            else
            {
                $cur_blocks_start_cs0[$_+$block_start_count+1] = $cur_blocks_start_cs1[$_];
                #  print "start test cs0 : $cur_blocks_start_cs0[$_+$block_start_count+1],$cur_blocks_start_cs1[$_],$#cur_blocks_start_cs0\n";
            }

        }

        for(0..$#cur_blocks_start_cs0)
        {
            #     print "start test cs0 all: $cur_blocks_start_cs0[$_]\n";
        }

        for(0..$#cur_blocks_start_cs1)
        {
            #     print "start test cs1 all: $cur_blocks_start_cs1[$_]\n";
        }
        #print "test calculate\n";
        if(($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
        {

            for (0..($#cur_blocks_start_cs0-1))
            {
                my $target_region = $cur_blocks_size_cs0[$_];
                #  print "target : $target_region\n";
                my $tmp_block_count = 0;
                while ($cur_blocks_sum_cs0 < hex($cur_blocks_start_cs0[$_+1]))
                {

                    $cur_blocks_sum_cs0 += hex($cur_blocks_size_cs0[$_]);
                    #print "blocks sum: cs0:$cur_blocks_sum_cs0\n";
                    if ($cur_blocks_sum_cs0 > $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL)
                    {
                        #print "test cs0\n";
                        $cur_regions_sum_cs0 += hex($cur_blocks_size_cs0[$_]);
                        $tmp_block_count++;
                    }
                    last if ($cur_regions_sum_cs0 >= $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
                }
                if ($tmp_block_count > 0)
                {
                    $cur_total_blocks_cs0 += $tmp_block_count;
                    if (hex($target_region) > hex($cur_nor_block_size_cs0))  # Find the largest block size within FS
                    {
                        $cur_nor_block_size_cs0 = $target_region;
                    }
                }
                last if ($cur_regions_sum_cs0 >= $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
            }
            # print "Test calculate nor block size cs0: $cur_nor_block_size_cs0,$cur_total_blocks_cs0\n";
            if(hex($cur_blocks_size_cs1[0]) == 0)
            {
                # print "test1\n";
            }
            else
            {
                for (0..($#cur_blocks_start_cs1-1))
                {
                    my $target_region = $cur_blocks_size_cs1[$_];
                    #  print "nor calculate block size target: $target_region\n";
                    my $tmp_block_count = 0;
                    while ($cur_blocks_sum_cs1 < hex($cur_blocks_start_cs1[$#cur_blocks_start_cs1]))
                    {
                        #print "target : $target_region, $cur_nor_block_size_cs1\n";
                        $cur_blocks_sum_cs1 += hex($cur_blocks_size_cs1[$_]);
                        if ($cur_blocks_sum_cs1 > $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL)
                        {
                            #  print "test $target_region,$tmp_block_count\n";
                            $cur_regions_sum_cs1 += hex($cur_blocks_size_cs1[$_]);
                            $tmp_block_count++;
                        }
                        last if ($cur_regions_sum_cs1 >= $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
                    }
                    if ($tmp_block_count > 0)
                    {
                        # print "test $target_region,$tmp_block_count\n";
                        $cur_total_blocks_cs1 += $tmp_block_count;
                        if (hex($target_region) > hex($cur_nor_block_size_cs1))  # Find the largest block size within FS
                        {
                            $cur_nor_block_size_cs1 = $target_region;
                        }
                    }
                    last if ($cur_regions_sum_cs1 >= $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
                }
            }
        }
        else
        {

            for (0..($#cur_blocks_start_cs0-1))
            {
                my $target_region = $cur_blocks_size_cs0[$_];
                # print "target : $target_region\n";
                my $tmp_block_count = 0;
                while ($cur_blocks_sum_cs0 < hex($cur_blocks_start_cs0[$_+1]))
                {

                    $cur_blocks_sum_cs0 += hex($cur_blocks_size_cs0[$_]);
                    if ($cur_blocks_sum_cs0 > $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL)
                    {
                        $cur_regions_sum_cs0 += hex($cur_blocks_size_cs0[$_]);
                        $tmp_block_count++;
                    }
                    last if ($cur_regions_sum_cs0 >= $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
                }
                if ($tmp_block_count > 0)
                {
                    $cur_total_blocks_cs0 += $tmp_block_count;
                    if (hex($target_region) > hex($cur_nor_block_size_cs0))  # Find the largest block size within FS
                    {
                        $cur_nor_block_size_cs0 = $target_region;
                    }
                }
                last if ($cur_regions_sum_cs0 >= $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
            }
            # print "Test calculate nor block size cs0: $cur_nor_block_size_cs0,$cur_total_blocks_cs0\n";
            if(hex($cur_blocks_size_cs1[0]) == 0)
            {
                # print "test1\n";
            }
            else
            {
                for (0..($#cur_blocks_start_cs1-1))
                {
                    my $target_region = $cur_blocks_size_cs1[$_];
                    # print "nor calculate block size target: $target_region\n";
                    my $tmp_block_count = 0;
                    while ($cur_blocks_sum_cs1 < hex($cur_blocks_start_cs1[$_+1]))
                    {
                        #print "target : $target_region, $cur_nor_block_size_cs1\n";
                        $cur_blocks_sum_cs1 += hex($cur_blocks_size_cs1[$_]);
                        if ($cur_blocks_sum_cs1 > $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL)
                        {
                            #  print "test $target_region,$tmp_block_count\n";
                            $cur_regions_sum_cs1 += hex($cur_blocks_size_cs1[$_]);
                            $tmp_block_count++;
                        }
                        last if ($cur_regions_sum_cs1 >= $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
                    }
                    if ($tmp_block_count > 0)
                    {
                        #  print "test $target_region,$tmp_block_count\n";
                        $cur_total_blocks_cs1 += $tmp_block_count;
                        if (hex($target_region) > hex($cur_nor_block_size_cs1))  # Find the largest block size within FS
                        {
                            $cur_nor_block_size_cs1 = $target_region;
                        }
                    }
                    last if ($cur_regions_sum_cs1 >= $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
                }
            }
        }


        # print "Test calculate nor block size cs1: $cur_nor_block_size_cs1,$tmp_block_count,$cur_total_blocks_cs0,$cur_total_blocks_cs1, $sds_block_count_cs1\n";
        #    if($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} ne 'ENABLE')
        #{
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: FAT space must be multiples of blocks!", __FILE__, __LINE__) if ($cur_regions_sum_cs0 > $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);
        #}
        #print "total block cs0:$cur_total_blocks_cs0, $cur_total_blocks_cs1\n";
        if(($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
        {
            # print "test calculate sds, $sds_block_start_cs0, $sds_block_start_cs1,count:$sds_block_count_cs0,$sds_block_count_cs1,$flash_limit_cs0\n";
            if(($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL < (hex($sds_block_start_cs1) + hex($flash_limit_cs0)))&&(($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > (hex($sds_block_start_cs1) + hex($flash_limit_cs0))))
            {
                # my $sds_block_count = ((($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) - (hex($sds_block_start_cs1) + hex($flash_limit_cs0)))) / (hex($sds_block_size_cs1));
                # my $sds_total_size = ((($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) - (hex($sds_block_start_cs1) + hex($flash_limit_cs0))));
                $cur_total_blocks = $cur_total_blocks_cs0 - $sds_block_count_cs1;
                # print "2,$cur_total_blocks,$sds_block_count,$sds_total_size_cs1,$sds_total_size_cs0\n";

            }
            else
            {
                if(($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL < hex($flash_limit_cs0)) && (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > (hex($sds_block_start_cs0))))
                {
                    # my $sds_block_count = ((($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) - (hex($sds_block_start_cs0) + hex($flash_limit_cs0)))) / (hex($sds_block_size_cs1));
                    # my $sds_total_size = ((($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) - (hex($sds_block_start_cs0) + hex($flash_limit_cs0))));
                     $cur_total_blocks = $cur_total_blocks_cs0 - $sds_block_count_cs1;
                    # print "1,$cur_total_blocks,$sds_block_count,$sds_total_size_cs1,$sds_total_size_cs0\n";
                }
                else
                {
                    $cur_total_blocks = $cur_total_blocks_cs0;
                    #  print "3\n";
                }

            }
            if((($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > (hex($flash_limit) - $sds_total_size_cs1)) && (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) < (hex($flash_limit)))
                || (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > (hex($flash_limit) - $sds_total_size_cs0 )) && (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) < (hex($flash_limit))))
            {
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: FAT space not allowed to be the middle of the sds region!", __FILE__, __LINE__);
            }
            my $total_size = $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL;
            my $cs1_size = hex($flash_limit) - $sds_total_size_cs1;
            my $cs0_size = hex($flash_limit) - $sds_total_size_cs0;
            # print "total size: $total_size,$cs1_size,$cs0_size\n";
        }
        else
        {
            $cur_total_blocks = $cur_total_blocks_cs0 ;

        }
        ### Calculate the current number of sectors
        ### S1 = ((NOR_ALLOCATED_FAT_SPACE - NOR_BLOCK_SIZEMCP1 * SNOR_ERASE_QUEUE_SIZE) / SECTOR_SIZE)
        ### NOR_ALLOCATED_FAT_SPACE := NOR_BOOTING_NOR_FS_SIZE
        ### SNOR_ERASE_QUEUE_SIZE := NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE or 5 (default value)
        ### NOR_SYSTEM_DRIVE_RESERVED_BLOCK := NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK or 3 (default value)
        ### NOR_BLOCK_SIZEMCP1 := The largest block size within FAT in MCP 1.
        ### SECTOR_SIZE:
        ### Sibley:=0x400
        ### Non-Sibley := 0x200
        if ($MAKEFILE_OPTIONS_LOCAL->{'enhanced_single_bank_nor_flash_support'} eq 'TRUE')
        {
            if(($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
            {
                if(($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL < (hex($sds_block_start_cs1) + hex($flash_limit_cs0)))&&(($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > (hex($sds_block_start_cs1) + hex($flash_limit_cs0))))
                {
                    # my $sds_total_size = ($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) - (hex($sds_block_start_cs1) + hex($flash_limit_cs0));
                     $cur_total_sectors_cs0 = (($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - $sds_total_size_cs1) - (hex($cur_nor_block_size_cs1) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE})) / $cur_sector_size;
                    # print "test4-1\n";
                }
                else
                {
                    if(($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL < hex($flash_limit_cs0)) && (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > (hex($sds_block_start_cs0))))
                    {
                        #my $sds_total_size = ($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) - (hex($sds_block_start_cs0) + hex($flash_limit_cs0));
                        $cur_total_sectors_cs0 = (($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - $sds_total_size_cs0) - (hex($cur_nor_block_size_cs0) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE})) / $cur_sector_size;
                        #  print "test4-2\n";
                    }
                    else
                    {
                        $cur_total_sectors_cs0 = (($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) - (hex($cur_nor_block_size_cs0) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE})) / $cur_sector_size;
                        #  print "test4-2\n";
                    }

               }

           }
           else
           {
               my $temp = hex($flash_limit_cs0);
               # print "calculate : $$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, $temp\n";
               if($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL < hex($flash_limit_cs0))
               {
                   $cur_total_sectors_cs0 = ($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - (hex($cur_nor_block_size_cs0) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE})) / $cur_sector_size;
                   # print "test3-1, $cur_total_sectors_cs0, $cur_nor_block_size_cs0\n";
               }
               else
               {
                   $cur_total_sectors_cs0 = ($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - (hex($cur_nor_block_size_cs1) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE})) / $cur_sector_size;
                   # print "test3-2, $cur_total_sectors_cs0, $cur_nor_block_size_cs1\n";
               }

            }

        }
        else
        {
            if(($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
            {
                if(($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL < hex($flash_limit_cs0)) && (($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL + $$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL) > (hex($sds_block_start_cs0))))
                {
                    $cur_total_sectors_cs0 = (($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - $sds_total_size_cs0) - (hex($cur_nor_block_size_cs1) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK})) / $cur_sector_size;
                    #  print "test2-1\n";
                }
                else
                {
                    $cur_total_sectors_cs0 = (($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - $sds_total_size_cs1) - (hex($cur_nor_block_size_cs1) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK})) / $cur_sector_size;
                    #   print "test2-2\n";
                }

            }
            else
            {
                if($$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL < hex($flash_limit_cs0))
                {
                    $cur_total_sectors_cs0 = ($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - (hex($cur_nor_block_size_cs0) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK})) / $cur_sector_size;
                    #  print "test1-1\n";
                }
                else
                {
                    $cur_total_sectors_cs0 = ($$NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL - (hex($cur_nor_block_size_cs1) * $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK})) / $cur_sector_size;
                    #  print "test1-2\n";
                }

            }
        }

        ### Find the overall max TOTAL_BLOCKS and NOR_BLOCK_SIZE
        if (($nor_block_size < hex($cur_nor_block_size_cs0)) || ($nor_block_size < hex($cur_nor_block_size_cs1)))
        {
            if (hex($cur_nor_block_size_cs0) < hex($cur_nor_block_size_cs1))
            {
                $nor_block_size = hex($cur_nor_block_size_cs1);
            }
            else
            {
                $nor_block_size = hex($cur_nor_block_size_cs0);
            }

            if ($nor_max_block_size < $nor_block_size)
            {
                $nor_max_block_size = $nor_block_size;
            }
            #    print "nor block size: $nor_block_size,$cur_nor_block_size_cs1, $nor_max_block_size\n";
        }
        if ($cmem_max_blocks < $cur_total_blocks)
        {
            $cmem_max_blocks = $cur_total_blocks;
        }
        if ($cmem_max_sectors < $cur_total_sectors_cs0)
        {
            $cmem_max_sectors = $cur_total_sectors_cs0;
        }

    }
    print "TOTAL_BLOCKS > 127 , recommend enable FDM5.0 feature!\n" if ($cmem_max_blocks > 127);
}

#****************************************************************************
# subroutine:  Validate_FAT_NORRAWDISK_OVERLAP
# input:       $info_list_href:   input list reference of list of MDL info
#              $combo_mem_count:  number of memory devices selected
#              $combo_sip_count:  number of SIPs
#              $mem_dev_type:     MEMORY_DEVICE_TYPE
#              $info_output_href: output hash reference for common MDL info,
#                                 including minimum physical flash size,
#                                           minimum small block start address
#                                           maximum default FAT base address
#                                           minimum default FAT size
#                                           minimum RAM size
#                                           common flash series information
#                                           common single/multiple-bank definition
#                                           common PBP information
#                                           minimum PBP size
#****************************************************************************
sub Validate_FAT_NORRAWDISK_OVERLAP
{
    my ($CUSTOM_MEM_DEV_OPTIONS_LOCAL, $COMM_MDL_INFO_LOCAL, $NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, $NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL) = @_;
    my %dsk_layout_hash;
    my @dsk_layout_sort_list;
    $dsk_layout_hash{$NOR_FLASH_BASE_ADDRESS_VAL_LOCAL} = $NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL;

    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK0_BASE_ADDRESS})
    {
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot configure NOR Raw Disk0 larger than physical NOR flash size!", __FILE__, __LINE__)
            if ((hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK0_BASE_ADDRESS})+hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK0_SIZE})) > $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot configure NOR Raw Disk0 the same base address as FAT!", __FILE__, __LINE__)
            if (hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK0_BASE_ADDRESS}) == $NOR_FLASH_BASE_ADDRESS_VAL_LOCAL);
        $dsk_layout_hash{hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK0_BASE_ADDRESS})} = hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK0_SIZE});
    }

    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL{NOR_BOOTING_NOR_DISK1_BASE_ADDRESS})
    {
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot configure NOR Raw Disk1 larger than physical NOR flash size!", __FILE__, __LINE__)
            if ((hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK1_BASE_ADDRESS})+hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK1_SIZE})) > $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot configure NOR Raw Disk1 the same base address as FAT!", __FILE__, __LINE__)
            if (hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK1_BASE_ADDRESS}) == $NOR_FLASH_BASE_ADDRESS_VAL_LOCAL);
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot configure NOR Raw Disk1 the same base address as NOR Raw Disk0!", __FILE__, __LINE__)
            if (hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK1_BASE_ADDRESS}) == hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK0_BASE_ADDRESS}));
        $dsk_layout_hash{hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK1_BASE_ADDRESS})} = hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK1_SIZE});
    }

    foreach (sort {$a <=> $b} keys %dsk_layout_hash)
    {
        push @dsk_layout_sort_list, $_;
    }

    foreach (1..$#dsk_layout_sort_list)
    {
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: NOR Flash disk overlapping detected. Please check NOR Raw disk and FAT setting!", __FILE__, __LINE__)
            if (($dsk_layout_sort_list[$_-1]+$dsk_layout_hash{$dsk_layout_sort_list[$_-1]}) > $dsk_layout_sort_list[$_]);
    }
}

#****************************************************************************
# subroutine:  Calculate_NORRAWDISK_Region_Info
# input:       $info_list_href:   input list reference of list of MDL info
#              $combo_mem_count:  number of memory devices selected
#              $combo_sip_count:  number of SIPs
#              $mem_dev_type:     MEMORY_DEVICE_TYPE
#              $info_output_href: output hash reference for common MDL info,
#                                 including minimum physical flash size,
#                                           minimum small block start address
#                                           maximum default FAT base address
#                                           minimum default FAT size
#                                           minimum RAM size
#                                           common flash series information
#                                           common single/multiple-bank definition
#                                           common PBP information
#                                           minimum PBP size
#****************************************************************************
sub Calculate_NORRAWDISK_Region_Info
{
    my ($CUSTOM_MEM_DEV_OPTIONS_LOCAL) = @_;
    my (@regions_disk0, @regions_disk1);
    for (0..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_BOOTING_NOR_DISK_NUM})
    {
        my $nor_booting_nor_disk_base_address = sprintf("NOR_BOOTING_NOR_DISK%d_BASE_ADDRESS", $_);
        my $nor_booting_nor_disk_size         = sprintf("NOR_BOOTING_NOR_DISK%d_SIZE", $_);
        my $nor_booting_nor_disk_index        = $_;

        if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{$nor_booting_nor_disk_base_address})
        {
            for (0..($#entire_block_info_start_list-1))
            {
                my $target_region;
                my $tmp_block_count = 0;
                my $tmp_blocks_sum = 0;
                my $tmp_regions_sum = 0;

                while ($tmp_blocks_sum < $entire_block_info_start_list[$_+1])
                {
                    $tmp_blocks_sum += $entire_block_info_size_list[$_];
                    if ($tmp_blocks_sum > hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{$nor_booting_nor_disk_base_address}))
                    {
                        $tmp_regions_sum += $entire_block_info_size_list[$_];
                        $target_region = sprintf("0x%X", $entire_block_info_size_list[$_]);
                        $tmp_block_count++;
                    }
                    if ($tmp_regions_sum >= hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{$nor_booting_nor_disk_size}))
                    {
                        last;
                    }
                }
                if ($tmp_block_count > 0)
                {
                    if ($nor_booting_nor_disk_index == 0)
                    {
                        push @regions_disk0, "{$target_region,$tmp_block_count}";
                    }
                    elsif ($nor_booting_nor_disk_index == 1)
                    {
                        push @regions_disk1, "{$target_region,$tmp_block_count}";
                    }
                }
                if ($tmp_regions_sum >= hex($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{$nor_booting_nor_disk_size}))
                {
                    last;
                }
            }
        }
    }
}
#****************************************************************************
# subroutine:  get_common_MDL_info
# input:       $info_list_href:   input list reference of list of MDL info
#              $combo_mem_count:  number of memory devices selected
#              $combo_sip_count:  number of SIPs
#              $mem_dev_type:     MEMORY_DEVICE_TYPE
#              $info_output_href: output hash reference for common MDL info,
#                                 including minimum physical flash size,
#                                           minimum small block start address
#                                           maximum default FAT base address
#                                           minimum default FAT size
#                                           minimum RAM size
#                                           common flash series information
#                                           common single/multiple-bank definition
#                                           common PBP information
#                                           minimum PBP size
#****************************************************************************
sub get_common_MDL_info
{
    #my ($info_list_href, $combo_mem_count, $combo_sip_count, $mem_dev_type, $info_output_href, $LPSDRAM_CHIP_SELECT_LOCAL, $MAKEFILE_OPTIONS, $CUSTOM_MEM_DEV_OPTIONS, $CUSTOM_MEMORY_DEVICE_HDR) = @_;
    my ($info_list_href, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $info_output_href, $MAKEFILE_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL) = @_;
    my $combo_mem_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT};
    my $combo_sip_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT};
    my $mem_dev_type = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE};
    my $platform = $MAKEFILE_OPTIONS_LOCAL->{'platform'};
    my $min_flash_size = 0xffffffff;
    my $max_nand_block_size = 0;
    my $min_small_block_start = 0xffffffff;
    my $max_fat_base = 0;
    my $min_fat_space = 0xffffffff;
    my $Size_Mb_ram_min = 0xffffffff*8/1024/1024;  # minimum size in "Size (Mb)" field for RAM
    my $ADMUX_CS0;
    my $ADMUX_CS1;
    my $if_DRAM;
    my $Comm_Series_CS0_all = '*';  # all "Comm. Series" information
    my $Comm_Series_CS1_all = '*';  # all "Comm. Series" information
    my $Bank_if_S = 'M';  # mark as 'S' if there is any device whose "Bank" field is 'S'
    my $PBP_Y_N_if_Y = 'N';  # mark as 'N' if there is any device whose "PBP -> Y/N" field is 'N'
    my $PBP_Size_W_min = 0xffffffff;  # minimum size in "PBP -> Size(W)" field
    my $Last_Bank_Region;  # common "Last Bank -> Region" field
    my $Geometry_Bank_Info;  # common "Geometry -> Bank Info." field
    my $Geometry_Block_Info;  # common "Geometry -> Block Info." field

    for (1..$combo_mem_count)
    {
        ### Find the smallest default FAT configuration among all MCPs
        my $cur_flash_size = 0;  # physical flash size (excluding bad small blocks for Toshiba)
        my $cur_small_block_start = 0;  # the starting location of small blocks at the end of a flash
        my $cur_sum_of_regions = 0;  # the sum of the regions in the last bank
        my $cur_fat_base = 0;  # default FAT base (physical flash size - last bank size)
        my $cur_fat_space = 0;  # default FAT size (last bank size)
        my @cur_blocks_start;  # list of Block Info starting addresses
        my @cur_blocks_size;  # list of Block Info sizes
        my @cur_regions = &split_info($info_list_href->[$_]->{0}->{'Last Bank'}->{'Region'});  # list of Last Bank -> Region Info.
        my $cur_bank_str = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Bank Info.'});
        my @cur_banks = &split_info($cur_bank_str);  # list of Bank Info.
        my $cur_block_str = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
        my @cur_blocks = &split_info($cur_block_str);  # list of Block Info.

        # Calculate default FAT size/start address (Last Bank)
        for (0..$#cur_regions)  # calculate the sum of last bank
        {
            if ($cur_regions[$_] =~ /\{(0x\w+)\s*,\s*(\d+)\}/) # match {0x20000, 7}
            {
                $cur_sum_of_regions += hex($1) * $2;
            }
        }
        for (0..$#cur_banks)  # calculate the physical flash size
        {
            if ($cur_banks[$_] =~ /\{(0x\w+)\s*,\s*(\d+)\}/) # match {0x20000, 7}
            {
                $cur_flash_size += hex($1) * $2;
                $cur_small_block_start += hex($1) * $2;
            }
        }
        if (($#cur_regions>0) && (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__}))  # for NOR FDM5, small blocks at the end of the flash should be excluded
        {
            if ($cur_blocks[$#cur_blocks] =~ /\{(0x\w+)\s*,\s*(0x\w+)\}/) # match {0xFF0000,0x2000}
            {
                $cur_small_block_start = hex($1);
            }
            $cur_fat_space = $cur_sum_of_regions - ($cur_flash_size - $cur_small_block_start);
        }
        else
        {
            $cur_fat_space = $cur_sum_of_regions;
        }
        $cur_fat_base = $cur_flash_size - $cur_sum_of_regions;

        if (($platform eq 'MT6255') || ($platform eq 'MT6922'))
        {
             if (($mem_dev_type eq 'LPDDR') or ($mem_dev_type eq 'DISCRETE_NAND') or ($mem_dev_type eq 'SERIALFLASH'))
             {

                 if (defined $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'NAND Size(MB)'})
                 {
                     $cur_flash_size = $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'NAND Size(MB)'} * 1024 * 1024;
                 }
                 else
                 {
                     $cur_flash_size = 0xffffffff;
                 }
             }
        }
        else
        {
            if (($mem_dev_type eq 'LPSDRAM') or ($mem_dev_type eq 'LPDDR') or ($mem_dev_type eq 'LPDDR2'))
            {
                if (defined $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'NAND Size(MB)'})
                {
                    $cur_flash_size = $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'NAND Size(MB)'} * 1024 * 1024;
                }
                else
                {
                    $cur_flash_size = 0xffffffff;
                }

                if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6276')
                {
                    $info_output_href->{0}->{'DQ Bus width'} = $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'DQ Bus width'};
                }
            }
            elsif (($mem_dev_type eq 'SPI_NAND'))
            {
                if (defined $info_list_href->[$_]->{0}->{'NAND Size (Mb)'})
                {
                    $cur_flash_size = ($info_list_href->[$_]->{0}->{'NAND Size (Mb)'} / 8) * 1024 * 1024;
                }
            }
        }
        # Temporarily store physical flash size, small block start, and default FAT size/base for future reference
        $info_list_href->[$_]->{0}->{'Flash Size'} = $cur_flash_size;
        $info_list_href->[$_]->{0}->{'Small Block Start'} = $cur_small_block_start;
        $info_list_href->[$_]->{0}->{'Default FAT Base'} = $cur_fat_base;
        $info_list_href->[$_]->{0}->{'Default FAT Size'} = $cur_fat_space;
        # In order to speed-up, assume the largest FAT base will be smaller than the physical flash size first
        # Find the largest FAT base
        if ($max_fat_base < $cur_fat_base)
        {
            $max_fat_base = $cur_fat_base;
        }
        # Find the smallest flash size
        if ($min_flash_size > $cur_flash_size)
        {
            $min_flash_size = $cur_flash_size;
        }
        # Find the smallest small block start
        if ($min_small_block_start > $cur_small_block_start)
        {
            $min_small_block_start = $cur_small_block_start;
        }

        ### Find the minimum RAM size in Mb
        if (($platform ne 'MT6252') and ($platform ne 'MT6255') and ($platform ne 'MT6250') and ($platform ne 'MT6260') and ($platform ne 'MT6261') and ($platform ne 'MT2501') and ($platform ne 'MT2502'))  # MT6252 uses SIP
        {
            my $cur_Size_Mb_ram = (($mem_dev_type eq 'LPSDRAM') or ($mem_dev_type eq 'LPDDR') or ($mem_dev_type eq 'LPDDR2')) ? $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'Density (Mb)'} : $info_list_href->[$_]->{1}->{'Size (Mb)'};
            if ($Size_Mb_ram_min > $cur_Size_Mb_ram)
            {
                $Size_Mb_ram_min = $cur_Size_Mb_ram;
            }
        }

        ### Find common ADMUX definition
        if ($info_list_href->[$_]->{0}->{'ADMUX'} =~ /YES/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select ADMUX/AD-DEMUX at one time! Please change selected MCP!", __FILE__, __LINE__) if ($ADMUX_CS0 eq "NO");
            $ADMUX_CS0 = "YES";
        }
        elsif ($info_list_href->[$_]->{0}->{'ADMUX'} =~ /NO/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select ADMUX/AD-DEMUX at one time! Please change selected MCP!", __FILE__, __LINE__) if ($ADMUX_CS0 eq "YES");
            $ADMUX_CS0 = "NO";
        }
        if ($info_list_href->[$_]->{1}->{'ADMUX'} =~ /YES/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select ADMUX/AD-DEMUX at one time! Please change selected MCP!", __FILE__, __LINE__) if ($ADMUX_CS1 eq "NO");
            $ADMUX_CS1 = "YES";
        }
        elsif ($info_list_href->[$_]->{1}->{'ADMUX'} =~ /NO/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select ADMUX/AD-DEMUX at one time! Please change selected MCP!", __FILE__, __LINE__) if ($ADMUX_CS1 eq "YES");
            $ADMUX_CS1 = "NO";
        }

        ### Find common "DRAM" information
        if ($info_list_href->[$_]->{1}->{'DRAM'} =~ /YES/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select DRAM/PSRAM at one time! Please change selected MCP!", __FILE__, __LINE__) if ($if_DRAM eq "NO");
            $if_DRAM = "YES";
        }
        elsif ($info_list_href->[$_]->{1}->{'DRAM'} =~ /NO/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select DRAM/PSRAM at one time! Please change selected MCP!", __FILE__, __LINE__) if ($if_DRAM eq "YES");
            $if_DRAM = "NO";
        }

        ### Find common "Comm. Series" information
        if ((defined $info_list_href->[$_]->{0}->{'Comm. Series'}) and ($info_list_href->[$_]->{0}->{'Comm. Series'} ne '*'))
        {
            if ($Comm_Series_CS0_all eq '*')
            {
                $Comm_Series_CS0_all = $info_list_href->[$_]->{0}->{'Comm. Series'};
            }
            else
            {
                $Comm_Series_CS0_all .= " $info_list_href->[$_]->{0}->{'Comm. Series'}";
            }
        }

        if (($platform ne 'MT6252') and ($platform ne 'MT6250') and ($platform ne 'MT6260') and ($platform ne 'MT6261') and ($platform ne 'MT2501') and ($platform ne 'MT2502'))  # MT6252 uses SIP
        {
            if ((defined $info_list_href->[$_]->{1}->{'Comm. Series'}) and ($info_list_href->[$_]->{1}->{'Comm. Series'} ne '*'))
            {
                if ($Comm_Series_CS1_all eq '*')
                {
                    $Comm_Series_CS1_all = $info_list_href->[$_]->{1}->{'Comm. Series'};
                }
                else
                {
                    $Comm_Series_CS1_all .= " $info_list_href->[$_]->{1}->{'Comm. Series'}";
                }
            }
        }

        ### Find common single/multiple-bank definition
        if ($info_list_href->[$_]->{0}->{'Bank'} =~ /S/i)
        {
            $Bank_if_S = 'S';
        }

        ### Find common PBP information
        if ($info_list_href->[$_]->{0}->{'PBP'}->{'Y / N'} =~ /Y/i)
        {
            $PBP_Y_N_if_Y = 'Y';
        }

        ### Find the minimum PBP size
        my $cur_PBP_size_W = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'PBP'}->{'Size(W)'}) : ($info_list_href->[$_]->{0}->{'PBP'}->{'Size (Byte)'}/2);

        if ($cur_PBP_size_W eq '*' or $cur_PBP_size_W eq 'x' or $cur_PBP_size_W eq ' ')
        {
            $cur_PBP_size_W = 0;
        }
        if ($PBP_Size_W_min > $cur_PBP_size_W)
        {
            $PBP_Size_W_min = $cur_PBP_size_W;
        }
        if (($platform eq 'MT6255') || ($platform eq 'MT6922'))
        {
            if (($mem_dev_type eq 'LPDDR') or ($mem_dev_type eq 'DISCRETE_NAND') or ($mem_dev_type eq 'SERIAL_FLASH'))
            {
                ### Find the max block size
                if (defined $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'NAND Block Size(KB)'})
                {
                    if ($max_nand_block_size < $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'NAND Block Size(KB)'} * 1024)
                    {
                        $max_nand_block_size = $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'NAND Block Size(KB)'} * 1024;
                    }
                }
            }
        }
        else
        {
            if (($mem_dev_type eq 'LPSDRAM') or ($mem_dev_type eq 'LPDDR') or ($mem_dev_type eq 'LPDDR2'))
            {
                ### Find the max block size
                if (defined $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'NAND Block Size(KB)'})
                {
                    if ($max_nand_block_size < $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'NAND Block Size(KB)'} * 1024)
                    {
                        $max_nand_block_size = $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'NAND Block Size(KB)'} * 1024;
                    }
                }
            }
            elsif (($mem_dev_type eq 'SPI_NAND'))
            {
                ### Find the max block size
                if (defined $info_list_href->[$_]->{0}->{'NAND Block Size(KB)'})
                {
                    if ($max_nand_block_size < $info_list_href->[$_]->{0}->{'NAND Block Size(KB)'} * 1024)
                    {
                        $max_nand_block_size = $info_list_href->[$_]->{0}->{'NAND Block Size(KB)'} * 1024;
                    }
                }
            }
        }
    }

    ### Work around when the FAT base is larger than some flash size
    if (($max_fat_base > $min_flash_size) or ($max_fat_base > $min_small_block_start))
    {
        $max_fat_base = 0;
        for (1..$combo_mem_count)
        {
            if (($info_list_href->[$_]->{0}->{'Default FAT Base'} < $min_flash_size) and ($info_list_href->[$_]->{0}->{'Default FAT Base'} < $min_small_block_start) and ($max_fat_base < $info_list_href->[$_]->{0}->{'Default FAT Base'}))
            {
                $max_fat_base = $info_list_href->[$_]->{0}->{'Default FAT Base'};
            }
        }
    }
    $min_fat_space = $min_flash_size - $max_fat_base;

    ### for MT6252 SIP case
    if (($platform eq 'MT6252') || ($platform eq 'MT6250') || ($platform eq 'MT6260') || ($platform eq 'MT6261') || ($platform eq 'MT2501') || ($platform eq 'MT2502'))
    {
        for (1..$combo_sip_count)
        {
            ### Find the minimum RAM size in Mb
            if ($Size_Mb_ram_min > $info_list_href->[$_]->{1}->{'Size (Mb)'})
            {
                $Size_Mb_ram_min = $info_list_href->[$_]->{1}->{'Size (Mb)'};
            }

            ### Find common "Comm. Series" information
            if ((defined $info_list_href->[$_]->{1}->{'Comm. Series'}) and ($info_list_href->[$_]->{1}->{'Comm. Series'} ne '*'))
            {
                if ($Comm_Series_CS1_all eq '*')
                {
                    $Comm_Series_CS1_all = $info_list_href->[$_]->{1}->{'Comm. Series'};
                }
                else
                {
                    $Comm_Series_CS1_all .= " $info_list_href->[$_]->{1}->{'Comm. Series'}";
                }
            }
        }
    }

    ### for MT6255
    if (($platform eq 'MT6255') || ($platform eq 'MT6922'))
    {

        ### Find the minimum RAM size in Mb
        if ($mem_dev_type eq 'LPDDR')
        {
            for (1..$combo_mem_count)
            {
                my $cur_Size_Mb_ram;
                $cur_Size_Mb_ram = $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'Density (Mb)'};
                if ($Size_Mb_ram_min > $cur_Size_Mb_ram)
                {
                    $Size_Mb_ram_min = $cur_Size_Mb_ram;
                }
            }
        }
        elsif (($mem_dev_type eq 'DISCRETE_NAND') or ($mem_dev_type eq 'SERIAL_FLASH'))
        {
            for (1..$combo_sip_count)
            {
                if ($Size_Mb_ram_min > $info_list_href->[$_]->{1}->{'Density (Mb)'})
                {
                    $Size_Mb_ram_min = $info_list_href->[$_]->{1}->{'Density (Mb)'};
                }
            }
        }
        else
        {
            for (1..$combo_mem_count)
            {
                $cur_Size_Mb_ram = $info_list_href->[$_]->{1}->{'Size (Mb)'};
                if ($Size_Mb_ram_min > $cur_Size_Mb_ram)
                {
                    $Size_Mb_ram_min = $cur_Size_Mb_ram;
                }
            }
        }
    }

    $info_output_href->{0}->{'Flash Size'} = $min_flash_size;
    $info_output_href->{0}->{'NAND Block Size(KB)'} = $max_nand_block_size / 1024;
    $info_output_href->{0}->{'Small Block Start'} = $min_small_block_start;
    $info_output_href->{0}->{'Default FAT Base'} = $max_fat_base;
    $info_output_href->{0}->{'Default FAT Size'} = $min_fat_space;
    $info_output_href->{1}->{'Size (Mb)'} = (&config_query_no_EMI($platform) == 1) ? 0 : $Size_Mb_ram_min;
    $info_output_href->{0}->{'ADMUX'} = $ADMUX_CS0;
    $info_output_href->{1}->{'ADMUX'} = $ADMUX_CS1;
    $info_output_href->{1}->{'DRAM'} = $if_DRAM;
    $info_output_href->{0}->{'Comm. Series'} = $Comm_Series_CS0_all;
    $info_output_href->{1}->{'Comm. Series'} = $Comm_Series_CS1_all;
    $info_output_href->{0}->{'Bank'} = $Bank_if_S;
    $info_output_href->{0}->{'PBP'}->{'Y / N'} = $PBP_Y_N_if_Y;
    $info_output_href->{0}->{'PBP'}->{'Size(W)'} = $PBP_Size_W_min;
}

#****************************************************************************
# subroutine:  get_common_MDL_info
# input:       $info_list_href:   input list reference of list of MDL info
#              $combo_mem_count:  number of memory devices selected
#              $combo_sip_count:  number of SIPs
#              $mem_dev_type:     MEMORY_DEVICE_TYPE
#              $info_output_href: output hash reference for common MDL info,
#                                 including minimum physical flash size,
#                                           minimum small block start address
#                                           maximum default FAT base address
#                                           minimum default FAT size
#                                           minimum RAM size
#                                           common flash series information
#                                           common single/multiple-bank definition
#                                           common PBP information
#                                           minimum PBP size
#****************************************************************************
sub get_common_MDL_info_dual_sf
{
    #my ($info_list_href, $combo_mem_count, $combo_sip_count, $mem_dev_type, $info_output_href, $LPSDRAM_CHIP_SELECT_LOCAL, $MAKEFILE_OPTIONS, $CUSTOM_MEM_DEV_OPTIONS, $CUSTOM_MEMORY_DEVICE_HDR) = @_;
    my ($info_list_href, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $info_output_href, $MAKEFILE_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL) = @_;
    my $combo_mem_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT};
    my $combo_sip_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT};
    my $mem_dev_type = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE};
    my $platform = $MAKEFILE_OPTIONS_LOCAL->{'platform'};
    my $min_flash_size = 0xffffffff;
    my $max_nand_block_size = 0;
    my $min_small_block_start = 0xffffffff;
    my $max_fat_base = 0;
    my $min_fat_space = 0xffffffff;
    my $Size_Mb_ram_min = 0xffffffff*8/1024/1024;  # minimum size in "Size (Mb)" field for RAM
    my $ADMUX_CS0;
    my $ADMUX_CS1;
    my $if_DRAM;
    my $Comm_Series_CS0_all = '*';  # all "Comm. Series" information
    my $Comm_Series_CS1_all = '*';  # all "Comm. Series" information
    my $Bank_if_S = 'M';  # mark as 'S' if there is any device whose "Bank" field is 'S'
    my $PBP_Y_N_if_Y = 'N';  # mark as 'N' if there is any device whose "PBP -> Y/N" field is 'N'
    my $PBP_Size_W_min_cs0 = 0xffffffff;  # minimum size in "PBP -> Size(W)" field
    my $PBP_Size_W_min_cs1 = 0xffffffff;  # minimum size in "PBP -> Size(W)" field
    my $Last_Bank_Region;  # common "Last Bank -> Region" field
    my $Geometry_Bank_Info;  # common "Geometry -> Bank Info." field
    my $Geometry_Block_Info;  # common "Geometry -> Block Info." field

    for (1..$combo_mem_count)
    {
        ### Find the smallest default FAT configuration among all MCPs
        my $cur_flash_size = 0;  # physical flash size (excluding bad small blocks for Toshiba)
        my $cur_small_block_start = 0;  # the starting location of small blocks at the end of a flash
        my $cur_sum_of_regions = 0;  # the sum of the regions in the last bank
        my $cur_fat_base = 0;  # default FAT base (physical flash size - last bank size)
        my $cur_fat_space = 0;  # default FAT size (last bank size)
        my @cur_blocks_start;  # list of Block Info starting addresses
        my @cur_blocks_size;  # list of Block Info sizes
        my @cur_regions_cs0 = &split_info($info_list_href->[$_]->{0}->{'Last Bank'}->{'Region'});  # list of Last Bank -> Region Info.
        my @cur_regions_cs1 = &split_info($info_list_href->[$_]->{1}->{'Last Bank'}->{'Region'});  # list of Last Bank -> Region Info.
        my $cur_bank_str_cs0 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Bank Info.'});
        my $cur_bank_str_cs1 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($info_list_href->[$_]->{1}->{'Device Geometry'}->{'Bank Info.'});
        my @cur_banks_cs0 = &split_info($cur_bank_str_cs0);  # list of Bank Info.
        my @cur_banks_cs1 = &split_info($cur_bank_str_cs1);  # list of Bank Info.
        my $cur_block_str = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
        my @cur_blocks = &split_info($cur_block_str);  # list of Block Info.

        # Calculate default FAT size/start address (Last Bank)
        # for (0..$#cur_regions)  # calculate the sum of last bank
        # {
        #     if ($cur_regions[$_] =~ /\{(0x\w+)\s*,\s*(\d+)\}/) # match {0x20000, 7}
        #     {
        #         $cur_sum_of_regions += hex($1) * $2;
        #     }
        # }
        for (0..$#cur_banks_cs0)  # calculate the physical flash size
        {
            if ($cur_banks_cs0[$_] =~ /\{(0x\w+)\s*,\s*(\d+)\}/) # match {0x20000, 7}
            {
                $cur_flash_size += hex($1) * $2;
                $cur_small_block_start += hex($1) * $2;
            }
        }

        for (0..$#cur_banks_cs1)  # calculate the physical flash size
        {
            if ($cur_banks_cs1[$_] =~ /\{(0x\w+)\s*,\s*(\d+)\}/) # match {0x20000, 7}
            {
                $cur_flash_size += hex($1) * $2;
                $cur_small_block_start += hex($1) * $2;
            }
        }

        #  if (($#cur_regions>0) && (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__}))  # for NOR FDM5, small blocks at the end of the flash should be excluded
        #  {
        #      if ($cur_blocks[$#cur_blocks] =~ /\{(0x\w+)\s*,\s*(0x\w+)\}/) # match {0xFF0000,0x2000}
        #      {
        #          $cur_small_block_start = hex($1);
        #      }
        #      $cur_fat_space = $cur_sum_of_regions - ($cur_flash_size-$cur_small_block_start);
        #  }
        #  else
        #  {
        #      $cur_fat_space = $cur_sum_of_regions;
        #  }
        $cur_fat_base = $cur_flash_size - $cur_sum_of_regions;


        # Temporarily store physical flash size, small block start, and default FAT size/base for future reference
        $info_list_href->[$_]->{0}->{'Flash Size'} = $cur_flash_size;
        $info_list_href->[$_]->{0}->{'Small Block Start'} = $cur_small_block_start;
        $info_list_href->[$_]->{0}->{'Default FAT Base'} = $cur_fat_base;
        $info_list_href->[$_]->{0}->{'Default FAT Size'} = $cur_fat_space;
        # In order to speed-up, assume the largest FAT base will be smaller than the physical flash size first
        # Find the largest FAT base
        if ($max_fat_base < $cur_fat_base)
        {
            $max_fat_base = $cur_fat_base;
        }
        # Find the smallest flash size
        if ($min_flash_size > $cur_flash_size)
        {
            $min_flash_size = $cur_flash_size;
        }
        # Find the smallest small block start
        if ($min_small_block_start > $cur_small_block_start)
        {
            $min_small_block_start = $cur_small_block_start;
        }

        ### Find the minimum RAM size in Mb
        if (($platform ne 'MT6252') and ($platform ne 'MT6255') and ($platform ne 'MT6250') and ($platform ne 'MT6260') and ($platform ne 'MT6261') and ($platform ne 'MT2501') and ($platform ne 'MT2502'))  # MT6252 uses SIP
        {
            my $cur_Size_Mb_ram = (($mem_dev_type eq 'LPSDRAM') or ($mem_dev_type eq 'LPDDR') or ($mem_dev_type eq 'LPDDR2')) ? $info_list_href->[$_]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'Density (Mb)'} : $info_list_href->[$_]->{1}->{'Size (Mb)'};
            if ($Size_Mb_ram_min > $cur_Size_Mb_ram)
            {
                $Size_Mb_ram_min = $cur_Size_Mb_ram;
            }
        }

        ### Find common ADMUX definition
        if ($info_list_href->[$_]->{0}->{'ADMUX'} =~ /YES/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select ADMUX/AD-DEMUX at one time! Please change selected MCP!", __FILE__, __LINE__) if ($ADMUX_CS0 eq "NO");
            $ADMUX_CS0 = "YES";
        }
        elsif ($info_list_href->[$_]->{0}->{'ADMUX'} =~ /NO/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select ADMUX/AD-DEMUX at one time! Please change selected MCP!", __FILE__, __LINE__) if ($ADMUX_CS0 eq "YES");
            $ADMUX_CS0 = "NO";
        }
        if ($info_list_href->[$_]->{2}->{'ADMUX'} =~ /YES/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select ADMUX/AD-DEMUX at one time! Please change selected MCP!", __FILE__, __LINE__) if ($ADMUX_CS1 eq "NO");
            $ADMUX_CS1 = "YES";
        }
        elsif ($info_list_href->[$_]->{2}->{'ADMUX'} =~ /NO/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select ADMUX/AD-DEMUX at one time! Please change selected MCP!", __FILE__, __LINE__) if ($ADMUX_CS1 eq "YES");
            $ADMUX_CS1 = "NO";
        }

        ### Find common "DRAM" information
        if ($info_list_href->[$_]->{2}->{'DRAM'} =~ /YES/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select DRAM/PSRAM at one time! Please change selected MCP!", __FILE__, __LINE__) if ($if_DRAM eq "NO");
            $if_DRAM = "YES";
        }
        elsif ($info_list_href->[$_]->{2}->{'DRAM'} =~ /NO/i)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR_LOCAL: Cannot select DRAM/PSRAM at one time! Please change selected MCP!", __FILE__, __LINE__) if ($if_DRAM eq "YES");
            $if_DRAM = "NO";
        }

        ### Find common "Comm. Series" information
        if ((defined $info_list_href->[$_]->{0}->{'Comm. Series'}) and ($info_list_href->[$_]->{0}->{'Comm. Series'} ne '*'))
        {
            if ($Comm_Series_CS0_all eq '*')
            {
                $Comm_Series_CS0_all = $info_list_href->[$_]->{0}->{'Comm. Series'};
            }
            else
            {
                $Comm_Series_CS0_all .= " $info_list_href->[$_]->{0}->{'Comm. Series'}";
            }
        }
        if (($platform ne 'MT6252') and ($platform ne 'MT6250') and ($platform ne 'MT6260') and ($platform ne 'MT6261') and ($platform ne 'MT2501') and ($platform ne 'MT2502'))  # MT6252 uses SIP
        {
            if ((defined $info_list_href->[$_]->{1}->{'Comm. Series'}) and ($info_list_href->[$_]->{1}->{'Comm. Series'} ne '*'))
            {
                if ($Comm_Series_CS1_all eq '*')
                {
                    $Comm_Series_CS1_all = $info_list_href->[$_]->{1}->{'Comm. Series'};
                }
                else
                {
                    $Comm_Series_CS1_all .= " $info_list_href->[$_]->{1}->{'Comm. Series'}";
                }
            }
        }

        ### Find common single/multiple-bank definition
        if ($info_list_href->[$_]->{0}->{'Bank'} =~ /S/i)
        {
            $Bank_if_S = 'S';
        }

        ### Find common PBP information
        if ($info_list_href->[$_]->{0}->{'PBP'}->{'Y / N'} =~ /Y/i)
        {
            $PBP_Y_N_if_Y = 'Y';
        }

        ### Find the minimum PBP size
        my $cur_PBP_size_W_cs0 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'PBP'}->{'Size(W)'}) : ($info_list_href->[$_]->{0}->{'PBP'}->{'Size (Byte)'}/2);
        my $cur_PBP_size_W_cs1 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'PBP'}->{'Size(W)'}) : ($info_list_href->[$_]->{1}->{'PBP'}->{'Size (Byte)'}/2);
        if ($cur_PBP_size_W_cs0 eq '*' or $cur_PBP_size_W_cs0 eq 'x' or $cur_PBP_size_W_cs0 eq ' ')
        {
            $cur_PBP_size_W_cs0 = 0;
        }
        if ($PBP_Size_W_min_cs0 > $cur_PBP_size_W_cs0)
        {
            $PBP_Size_W_min_cs0 = $cur_PBP_size_W_cs0;
        }

        if ($cur_PBP_size_W_cs1 eq '*' or $cur_PBP_size_W_cs1 eq 'x' or $cur_PBP_size_W_cs1 eq ' ')
        {
            $cur_PBP_size_W_cs1 = 0;
        }
        if ($PBP_Size_W_min_cs1 > $cur_PBP_size_W_cs1)
        {
            $PBP_Size_W_min_cs1 = $cur_PBP_size_W_cs1;
        }

    }

    ### Work around when the FAT base is larger than some flash size
    #  if (($max_fat_base > $min_flash_size) or ($max_fat_base > $min_small_block_start))
    #  {
    #      $max_fat_base = 0;
    #      for (1..$combo_mem_count)
    #      {
    #          if (($info_list_href->[$_]->{0}->{'Default FAT Base'} < $min_flash_size) and ($info_list_href->[$_]->{0}->{'Default FAT Base'} < $min_small_block_start) and ($max_fat_base < $info_list_href->[$_]->{0}->{'Default FAT Base'}))
    #          {
    #              $max_fat_base = $info_list_href->[$_]->{0}->{'Default FAT Base'};
    #          }
    #      }
    #  }
    $min_fat_space = $min_flash_size - $max_fat_base;

    ### for MT6252 SIP case
    if (($platform eq 'MT6252') || ($platform eq 'MT6250') || ($platform eq 'MT6260') || ($platform eq 'MT6261') || ($platform eq 'MT2501') || ($platform eq 'MT2502'))
    {

        for (1..$combo_sip_count)
        {

            ### Find the minimum RAM size in Mb
            if ($Size_Mb_ram_min > $info_list_href->[$_]->{2}->{'Size (Mb)'})
            {
                $Size_Mb_ram_min = $info_list_href->[$_]->{2}->{'Size (Mb)'};

            }

            ### Find common "Comm. Series" information
            if ((defined $info_list_href->[$_]->{1}->{'Comm. Series'}) and ($info_list_href->[$_]->{1}->{'Comm. Series'} ne '*'))
            {
                if ($Comm_Series_CS1_all eq '*')
                {
                    $Comm_Series_CS1_all = $info_list_href->[$_]->{1}->{'Comm. Series'};
                }
                else
                {
                    $Comm_Series_CS1_all .= " $info_list_href->[$_]->{1}->{'Comm. Series'}";
                }
            }
        }
    }



    $info_output_href->{0}->{'Flash Size'} = $min_flash_size;
    $info_output_href->{0}->{'NAND Block Size(KB)'} = $max_nand_block_size / 1024;
    $info_output_href->{0}->{'Small Block Start'} = $min_small_block_start;
    $info_output_href->{0}->{'Default FAT Base'} = $max_fat_base;
    $info_output_href->{0}->{'Default FAT Size'} = $min_fat_space;
    $info_output_href->{1}->{'Size (Mb)'} = (&config_query_no_EMI($platform) == 1) ? 0 : $Size_Mb_ram_min;
    $info_output_href->{0}->{'ADMUX'} = $ADMUX_CS0;
    $info_output_href->{1}->{'ADMUX'} = $ADMUX_CS1;
    $info_output_href->{1}->{'DRAM'} = $if_DRAM;
    $info_output_href->{0}->{'Comm. Series'} = $Comm_Series_CS0_all;
    $info_output_href->{1}->{'Comm. Series'} = $Comm_Series_CS1_all;
    $info_output_href->{0}->{'Bank'} = $Bank_if_S;
    $info_output_href->{0}->{'PBP'}->{'Y / N'} = $PBP_Y_N_if_Y;
    $info_output_href->{0}->{'PBP'}->{'Size(W)'} = $PBP_Size_W_min_cs0;
    $info_output_href->{1}->{'PBP'}->{'Size(W)'} = $PBP_Size_W_min_cs1;
}

#****************************************************************************
# subroutine:  get_common_MDL_Geo_info
# input:       $info_list_href:         input list reference of list of MDL info
#              $combo_count:            number of memory devices selected
#              $mem_dev_type:           MEMORY_DEVICE_TYPE
#              $baseaddr:               base address where the geometry list starts
#              $endaddr:                end address where the geometry list ends
#              $region_info_size_href:  list reference of common RegionInfo of the specified area (Size)
#              $region_info_count_href: list of common RegionInfo of the specified area (Count)
#              $bank_info_size_href:    list of common BankInfo of the specified area (Size)
#              $bank_info_count_href:   list of common BankInfo of the specified area (Count)
#****************************************************************************
sub get_common_MDL_Geo_info
{
    my ($info_list_href, $combo_count, $mem_dev_type, $baseaddr, $endaddr, $region_info_size_href, $region_info_count_href, $bank_info_size_href, $bank_info_count_href, $MAKEFILE_OPTIONS_LOCAL, $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL) = @_;
    my ($prev_addr, $curr_addr, $idx);
    print "get common MDL info:$CUSTOM_FEATURE_CFG_OPTIONS_LOCAL->{'SDS_MAX_SIZE'}\n";

    ### Get common RegionInfo
    $prev_addr = $baseaddr;
    $curr_addr = $baseaddr;
    $idx = 0;

    while ($curr_addr < $endaddr)  # traverse till the endaddr
    {
        ### Find the largest block/bank offset from the current address to the next boundary
        ### Stop if the end of BankInfo or RegionInfo has been reached
        my $largest_offset = 0;  # largest offset from curr_addr to the next block/bank boundary
        my $common_size = 0;  # final(common) block/bank size of this round
        my $size;  # current offset from curr_addr to the next block/bank boundary
        my $cur_combo_idx;

        for (1..$combo_count)
        {
            $cur_combo_idx = $_;
            my $cur_block_str = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
            my $cur_block_str_fdm5;
            my @cur_block_fdm5;
            my $cur_block_fdm5_tmp;
            if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
            {

                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $cur_block_str_fdm5 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_block_fdm5 = &split_info($cur_block_str_fdm5);
                    if ($cur_block_fdm5[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $cur_block_fdm5_tmp = $2;
                    }
                    if (hex($cur_block_fdm5_tmp) < 65536)
                    {
                        $cur_block_str = "\{0x0, 0x1000\}";
                        #print "test norfdm5\n";

                    }
                    else
                    {
                        $cur_block_str = "\{0x0, 0x10000\}";
                        goto Label4;
                    }
                }
            } ### if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})

            Label4:
            ;#print "test Label4 $cur_block_str\n";
            if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') && ($mem_dev_type eq 'SERIAL_FLASH'))
            {
                my @sds_block_size_all, @cur_blocks_sds ;
                my $sds_block_size, $sds_block_start, @tmp_sds_block_size;
                my @tmp_block_str_all;
                for (1..$combo_count)
                {
                    $tmp_block_str_all[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds = &split_info($tmp_block_str_all[$_]);
                    if ($cur_blocks_sds[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size[$_] = $2;
                    }
                    #print "second temp block size : $tmp_sds_block_size[$_], block str : $tmp_block_str_all[$_]\n";
                }

                my $tmp_sds_start, $tmp_sds_last_block_start;
                my $sds_total_size;
                ###judge sds block size
                my @cur_uni_block_str;
                my @cur_uni_block;
                my $tmp_max_block_size = 0;
                my @tmp_block_str, @tmp_block_size;
                for (1..$combo_count)
                {
                    $cur_uni_block_str[$_] = $info_list_href->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block[$_] = &split_info_for_UB_SDS($cur_uni_block_str[$_]);
                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {
                        if($cur_uni_block[$_] ne '4')
                        {
                            $cur_block_str = "\{0x0, 0x10000\}";
                            $sds_block_size = sprintf("0x%X", 64*1024);
                            goto Finally2;
                        }
                        else
                        {
                            #$sds_block_size = sprintf("0x%X", $cur_uni_block[$_]*1024);
                            $cur_block_str = "\{0x0, 0x1000\}";
                            $sds_block_size = sprintf("0x%X", 4*1024);
                            #goto Finally1;
                        }
                    }
                    else
                    {
                        if ($cur_uni_block[$_] ne '4')
                        {
                            for (1..$combo_count)
                            {
                                if($tmp_max_block_size < hex($tmp_sds_block_size[$_]))
                                {
                                    $tmp_max_block_size = $tmp_sds_block_size[$_];
                                }
                            }
                            $sds_block_size = $tmp_max_block_size;
                            goto Finally2;
                        }
                        else
                        {
                            $sds_block_size = sprintf("0x%X", $cur_uni_block[$_]*1024);
                        }
                    }
                }
                if (!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                {
                    print "second sds block size : $sds_block_size\n";
                    $sds_block_start = sprintf("0x%X", (($info_list_href->[$_]->{0}->{'Size (Mb)'}*1024*1024/8) - hex($tmp_sds_block_size[$_])));
                    $sds_total_size = &memConfig::Get_SDS_total_size(hex($sds_block_size), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                    $tmp_sds_start = sprintf("0x%X", (($info_list_href->[$_]->{0}->{'Size (Mb)'}*1024*1024/8) - $sds_total_size));
                    print "second sds temp block start : $tmp_sds_start\n";
                    while(hex($sds_block_start) > hex($tmp_sds_start))
                    {
                        $sds_block_start = sprintf("0x%X", hex($sds_block_start) - hex($tmp_sds_block_size[$_]));
                    }
                    #    print "combo sds block start:$sds_block_start\n";
                    $cur_block_str .= "\{$sds_block_start, $sds_block_size\}";
                }
                Finally2:
                ;#print "test Finally2\n";
            } ### if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') && ($mem_dev_type eq 'SERIAL_FLASH'))


            if (($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($mem_dev_type eq 'SERIAL_FLASH'))
            {
                #print "nvram backup enable\n";
                my @sds_block_size_all, @cur_blocks_sds ;
                my $sds_block_size, $sds_block_start, @tmp_sds_block_size;
                my @tmp_block_str_all;

                for (1..$combo_count)
                {
                    $tmp_block_str_all[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds = &split_info($tmp_block_str_all[$_]);

                    if ($cur_blocks_sds[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size[$_] = $2;
                    }
                    #print "second temp block size : $tmp_sds_block_size[$_], block str : $tmp_block_str_all[$_]\n";
                }

                my $tmp_sds_start, $tmp_sds_last_block_start;
                my $sds_total_size;
                ###judge sds block size
                my @cur_uni_block_str;
                my @cur_uni_block;
                my $tmp_max_block_size = 0;
                my @tmp_block_str, @tmp_block_size;
                for (1..$combo_count)
                {
                    $cur_uni_block_str[$_] = $info_list_href->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block[$_] = &split_info_for_UB_SDS($cur_uni_block_str[$_]);
                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {
                        if ($cur_uni_block[$_] ne '4')
                        {
                            $cur_block_str = "\{0x0, 0x10000\}";
                            $sds_block_size = sprintf("0x%X", 64*1024);
                            goto Label5;
                        }
                        else
                        {
                            $cur_block_str = "\{0x0, 0x1000\}";
                            $sds_block_size = sprintf("0x%X", 4*1024);
                            #goto Finally1;
                        }
                    }
                    else
                    {
                        if ($cur_uni_block[$_] ne '4')
                        {
                            for (1..$combo_count)
                            {
                                if($tmp_max_block_size < hex($tmp_sds_block_size[$_]))
                                {
                                    $tmp_max_block_size = $tmp_sds_block_size[$_];
                                }
                            }
                            $sds_block_size = $tmp_max_block_size;
                            #goto Finally2;
                        }
                        else
                        {
                            $sds_block_size = sprintf("0x%X", $cur_uni_block[$_]*1024);
                        }
                    }
                }

                Label5:
                ;#print "second sds block size : $sds_block_size, $cur_block_str\n";
                $nor_disk0_block_size = hex($sds_block_size);
            } ### if (($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($mem_dev_type eq 'SERIAL_FLASH'))


            #   print "combo cur block str : $cur_block_str\n";
            my @cur_blocks = &split_info($cur_block_str);  # list of Block Info.
            my @cur_entire_regions = &convert_blocks_to_regions(\@cur_blocks, $endaddr);  # list of Region Info. (of the entire flash)
            my (@cur_entire_regions_size, @cur_entire_regions_count);
            &convert_geo_hash_from_list(\@cur_entire_regions, \@cur_entire_regions_size, \@cur_entire_regions_count);
            ### Get the offset to the next boundary
            $size = &get_next_Geo_boundary(\@cur_entire_regions_size, \@cur_entire_regions_count, $curr_addr);

            last if ($size == 0);  # reach the end of RegionInfo/BankInfo
            if ($size > $largest_offset)
            {
                $largest_offset = $size;
            }
        } ### for (1..$combo_count)
        last if ($cur_combo_idx != $combo_count);  # early break in for loop represents end of RegionInfo/BankInfo is reached

        ### Check whether curr_address+largest_offset is still on the boundaries of all MCPs
        for (1..$combo_count)
        {
            $cur_combo_idx = $_;
            my $cur_block_str = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
            my $cur_block_str_fdm5;
            my @cur_block_fdm5;
            my $cur_block_fdm5_tmp;

            if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
            {
                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $cur_block_str_fdm5 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_block_fdm5 = &split_info($cur_block_str_fdm5);
                    if ($cur_block_fdm5[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $cur_block_fdm5_tmp = $2;
                    }
                    if(hex($cur_block_fdm5_tmp) < 65536)
                    {
                        $cur_block_str = "\{0x0, 0x1000\}";
                        #print "test norfdm5\n";

                    }
                    else
                    {
                        $cur_block_str = "\{0x0, 0x10000\}";
                        goto Label6;
                    }
                }
            }
            Label6:
            ;# print "test Label6 $cur_block_str\n";
            if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') && ($mem_dev_type eq 'SERIAL_FLASH'))
            {

                my @sds_block_size_all, @cur_blocks_sds ;
                my $sds_block_size, $sds_block_start, @tmp_sds_block_size;
                my @tmp_block_str_all;
                for (1..$combo_count)
                {
                    $tmp_block_str_all[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds = &split_info($tmp_block_str_all[$_]);
                    if ($cur_blocks_sds[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size[$_] = $2;
                    }
                    #print "third temp block size : $tmp_sds_block_size[$_], block str : $tmp_block_str_all[$_]\n";
                }

                my $tmp_sds_start, $tmp_sds_last_block_start;
                my $sds_total_size;
                ###judge sds block size
                my @cur_uni_block_str;
                my @cur_uni_block;
                my $tmp_max_block_size = 0;
                my @tmp_block_str, @tmp_block_size;
                for (1..$combo_count)
                {
                    $cur_uni_block_str[$_] = $info_list_href->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block[$_] = &split_info_for_UB_SDS($cur_uni_block_str[$_]);
                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {
                        if($cur_uni_block[$_] ne '4')
                        {
                            $cur_block_str = "\{0x0, 0x10000\}";
                            $sds_block_size = sprintf("0x%X", 64*1024);
                            goto Finally3;
                        }
                        else
                        {
                            $cur_block_str = "\{0x0, 0x1000\}";
                            $sds_block_size = sprintf("0x%X", 4*1024);
                            #goto Finally1;
                        }
                    }
                    else
                    {
                        if($cur_uni_block[$_] ne '4')
                        {
                            for (1..$combo_count)
                            {
                                if($tmp_max_block_size < hex($tmp_sds_block_size[$_]))
                                {
                                    $tmp_max_block_size = $tmp_sds_block_size[$_];
                                }
                            }
                            $sds_block_size = $tmp_max_block_size;
                            goto Finally3;
                        }
                        else
                        {
                            $sds_block_size = sprintf("0x%X", $cur_uni_block[$_]*1024);
                        }
                    }
                }
                ###
                if (!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                {
                    $sds_block_start = sprintf("0x%X", (($info_list_href->[$_]->{0}->{'Size (Mb)'}*1024*1024/8) - hex($tmp_sds_block_size[$_])));
                    $sds_total_size = &memConfig::Get_SDS_total_size(hex($sds_block_size), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                    $tmp_sds_start = sprintf("0x%X", (($info_list_href->[$_]->{0}->{'Size (Mb)'}*1024*1024/8) - $sds_total_size));
                    #  print "sds temp block start : $tmp_sds_start\n";
                    while(hex($sds_block_start) > hex($tmp_sds_start))
                    {
                        $sds_block_start = sprintf("0x%X", hex($sds_block_start) - hex($tmp_sds_block_size[$_]));
                    }
                    #   print "combo sds block start:$sds_block_start\n";
                    $cur_block_str .= "\{$sds_block_start, $sds_block_size\}";
                }
                Finally3:
                ;#print "test Finally3\n";
            } ### if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') && ($mem_dev_type eq 'SERIAL_FLASH'))

            if (($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($mem_dev_type eq 'SERIAL_FLASH'))
            {
                my @sds_block_size_all, @cur_blocks_sds ;
                my $sds_block_size, $sds_block_start, @tmp_sds_block_size;
                my @tmp_block_str_all;
                for (1..$combo_count)
                {
                    $tmp_block_str_all[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds = &split_info($tmp_block_str_all[$_]);
                    if ($cur_blocks_sds[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size[$_] = $2;
                    }
                    #print "third temp block size : $tmp_sds_block_size[$_], block str : $tmp_block_str_all[$_]\n";
                }

                my $tmp_sds_start, $tmp_sds_last_block_start;
                my $sds_total_size;
                ###judge sds block size
                my @cur_uni_block_str;
                my @cur_uni_block;
                my $tmp_max_block_size = 0;
                my @tmp_block_str, @tmp_block_size;
                for (1..$combo_count)
                {
                    $cur_uni_block_str[$_] = $info_list_href->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block[$_] = &split_info_for_UB_SDS($cur_uni_block_str[$_]);
                    #print "uni block $cur_uni_block[$_]\n";
                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {
                        if($cur_uni_block[$_] ne '4')
                        {
                            $cur_block_str = "\{0x0, 0x10000\}";
                            $sds_block_size = sprintf("0x%X", 64*1024);
                            #print "big block:$cur_block_str\n";
                            goto Label7;
                        }
                        else
                        {
                            $cur_block_str = "\{0x0, 0x1000\}";
                            $sds_block_size = sprintf("0x%X", 4*1024);
                            #print "small block:$cur_block_str\n";
                            #goto Finally1;
                        }
                    }
                    else
                    {
                        if($cur_uni_block[$_] ne '4')
                        {
                            for (1..$combo_count)
                            {
                                if($tmp_max_block_size < hex($tmp_sds_block_size[$_]))
                                {
                                    $tmp_max_block_size = $tmp_sds_block_size[$_];
                                }
                            }
                            $sds_block_size = $tmp_max_block_size;
                            #goto Finally3;
                        }
                        else
                        {
                            $sds_block_size = sprintf("0x%X", $cur_uni_block[$_]*1024);
                        }
                    }
                }
                ###
                Label7:
                $nor_disk0_block_size = hex($sds_block_size);
                #print "Label 7 second sds block size : $sds_block_size, $cur_block_str\n";
            } ### if (($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($mem_dev_type eq 'SERIAL_FLASH'))

            my @cur_blocks = &split_info($cur_block_str);  # list of Block Info.
            my @cur_entire_regions = &convert_blocks_to_regions(\@cur_blocks, $endaddr);  # list of Region Info. (of the entire flash)
            my (@cur_entire_regions_size, @cur_entire_regions_count);
            &convert_geo_hash_from_list(\@cur_entire_regions, \@cur_entire_regions_size, \@cur_entire_regions_count);

            last if (&query_if_Geo_boundary(\@cur_entire_regions_size, \@cur_entire_regions_count, $curr_addr+$largest_offset) != 1);
        }
        # The address is not on the boundaries of all MCPs, need to go to the next address
        # The next address is curr_addr + largest_offset
        if ($cur_combo_idx != $combo_count)
        {
            $curr_addr += $largest_offset;
            next;
        }

        ### Add the address into the output RegionInfo/BankInfo
        # Get the size of common block/bank size
        $common_size = $curr_addr + $largest_offset - $prev_addr;
        if ($prev_addr == $baseaddr)  # the first entry
        {
            $region_info_size_href->[0] = $common_size;
            $region_info_count_href->[0] = 1;
        }
        elsif ($common_size == $region_info_size_href->[$idx])  # the size is identical to the last bank we added --> count + 1
        {
            $region_info_count_href->[$idx]++;
        }
        else  # the size is different from the last bank we added --> append new entry
        {
            $idx++;
            $region_info_size_href->[$idx] = $common_size;
            $region_info_count_href->[$idx] = 1;
        }

        ### Increment the current address and then perform the loop again
        $curr_addr += $largest_offset;
        $prev_addr = $curr_addr;
    }
    #print "pass block info\n";



    ### Get common BankInfo
    $prev_addr = $baseaddr;
    $curr_addr = $baseaddr;
    $idx = 0;
    while ($curr_addr < $endaddr)  # traverse till the endaddr
    {
        ### Find the largest block/bank offset from the current address to the next boundary
        ### Stop if the end of BankInfo or RegionInfo has been reached
        my $largest_offset = 0;  # largest offset from curr_addr to the next block/bank boundary
        my $common_size = 0;  # final(common) block/bank size of this round
        my $size;  # current offset from curr_addr to the next block/bank boundary
        my $cur_combo_idx;

        for (1..$combo_count)
        {
            $cur_combo_idx = $_;
            my $cur_bank_str = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Bank Info.'});
            my @cur_banks = &split_info($cur_bank_str);  # list of Bank Info.
            my (@cur_banks_size, @cur_banks_count);
            &convert_geo_hash_from_list(\@cur_banks, \@cur_banks_size, \@cur_banks_count);

            ### Get the offset to the next boundary
            $size = &get_next_Geo_boundary(\@cur_banks_size, \@cur_banks_count, $curr_addr);
            last if ($size == 0);  # reach the end of RegionInfo/BankInfo
            if ($size > $largest_offset)
            {
                $largest_offset = $size;
            }
        }
        last if ($cur_combo_idx != $combo_count);  # early break in for loop represents end of RegionInfo/BankInfo is reached

        ### Check whether curr_address+largest_offset is still on the boundaries of all MCPs
        for (1..$combo_count)
        {
            $cur_combo_idx = $_;
            my $cur_bank_str = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Bank Info.'});
            my @cur_banks = &split_info($cur_bank_str);  # list of Bank Info.
            my (@cur_banks_size, @cur_banks_count);
            &convert_geo_hash_from_list(\@cur_banks, \@cur_banks_size, \@cur_banks_count);
            last if (&query_if_Geo_boundary(\@cur_banks_size, \@cur_banks_count, $curr_addr+$largest_offset) != 1);
        }
        # The address is not on the boundaries of all MCPs, need to go to the next address
        # The next address is curr_addr + largest_offset
        if ($cur_combo_idx != $combo_count)
        {
            $curr_addr += $largest_offset;
            next;
        }

        ### Add the address into the output RegionInfo/BankInfo
        # Get the size of common block/bank size
        $common_size = $curr_addr + $largest_offset - $prev_addr;

        if ($prev_addr == $baseaddr)  # the first entry
        {
            $bank_info_size_href->[0] = $common_size;
            $bank_info_count_href->[0] = 1;
        }
        elsif ($common_size == $bank_info_size_href->[$idx])  # the size is identical to the last bank we added --> count + 1
        {
            $bank_info_count_href->[$idx]++;
        }
        else  # tje soze os different from the last bank we added --> append new entry
        {
            $idx++;
            $bank_info_size_href->[$idx] = $common_size;
            $bank_info_count_href->[$idx] = 1;
        }

        ### Increment the current address and then perform the loop again
        $curr_addr += $largest_offset;
        $prev_addr = $curr_addr;
    }
}

#****************************************************************************
# subroutine:  get_common_MDL_Geo_info_dual_sf
# input:       $info_list_href:         input list reference of list of MDL info
#              $combo_count:            number of memory devices selected
#              $mem_dev_type:           MEMORY_DEVICE_TYPE
#              $baseaddr:               base address where the geometry list starts
#              $endaddr:                end address where the geometry list ends
#              $region_info_size_href:  list reference of common RegionInfo of the specified area (Size)
#              $region_info_count_href: list of common RegionInfo of the specified area (Count)
#              $bank_info_size_href:    list of common BankInfo of the specified area (Size)
#              $bank_info_count_href:   list of common BankInfo of the specified area (Count)
#****************************************************************************
sub get_common_MDL_Geo_info_dual_sf
{
    my ($info_list_href, $combo_count, $mem_dev_type, $baseaddr, $endaddr, $region_info_size_href, $region_info_count_href, $bank_info_size_href, $bank_info_count_href, $MAKEFILE_OPTIONS_LOCAL, $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL) = @_;
    my ($prev_addr, $curr_addr, $idx);
    #print "custom_memory : $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}\n";
    ### Get common RegionInfo
    $prev_addr = $baseaddr;
    $curr_addr = $baseaddr;
    $idx = 0;
    #print "$curr_addr, $endaddr\n";
    #exit;
    while ($curr_addr < $endaddr)  # traverse till the endaddr
    {
        ### Find the largest block/bank offset from the current address to the next boundary
        ### Stop if the end of BankInfo or RegionInfo has been reached
        my $largest_offset = 0;  # largest offset from curr_addr to the next block/bank boundary
        my $common_size = 0;  # final(common) block/bank size of this round
        my $size;  # current offset from curr_addr to the next block/bank boundary
        my $cur_combo_idx;
        #print "cur addr before : $curr_addr, $prev_addr, $endaddr\n";
        for (1..$combo_count)
        {
            $cur_combo_idx = $_;
            my $cur_block_str_cs0 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
            my $cur_block_str_cs1 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
            my $cur_block_str_fdm5_cs0;
            my $cur_block_str_fdm5_cs1;
            my @cur_block_fdm5_cs0;
            my @cur_block_fdm5_cs1;
            my $cur_block_fdm5_tmp_cs0;
            my $cur_block_fdm5_tmp_cs1;
            if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
            {

                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $cur_block_str_fdm5_cs0 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    $cur_block_str_fdm5_cs1 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
                    @cur_block_fdm5_cs0 = &split_info($cur_block_str_fdm5_cs0);
                    @cur_block_fdm5_cs1 = &split_info($cur_block_str_fdm5_cs1);

                    if ($cur_block_fdm5_cs0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $cur_block_fdm5_tmp_cs0 = $2;
                    }

                    if ($cur_block_fdm5_cs1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $cur_block_fdm5_tmp_cs1 = $2;
                    }


                    if(hex($cur_block_fdm5_tmp_cs0) < 65536)
                    {
                        $cur_block_str_cs0 = "\{0x0, 0x1000\}";

                    }
                    else
                    {
                        $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                        $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                        goto Label8;
                    }


                    if(hex($cur_block_fdm5_tmp_cs1) < 65536)
                    {
                        if(hex($cur_block_fdm5_tmp_cs0) > 65536)
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                            $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                            goto Label8;
                        }
                        else
                        {
                            $cur_block_str_cs1 = "\{0x0, 0x1000\}";
                        }

                    }
                    else
                    {
                        $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                        $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                        goto Label8;
                    }
                }
           }
           Label8:
           ;#print "test Label8 $cur_block_str_cs0, $cur_block_str_cs1\n";
            if(($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($mem_dev_type eq 'SERIAL_FLASH'))
            {
                my @sds_block_size_all_cs0, @cur_blocks_sds_cs0 ;
                my $sds_block_size_cs0, $sds_block_start_cs0, @tmp_sds_block_size_cs0;
                my @tmp_block_str_all_cs0;

                my @sds_block_size_all_cs1, @cur_blocks_sds_cs1 ;
                my $sds_block_size_cs1, $sds_block_start_cs1, @tmp_sds_block_size_cs1;
                my @tmp_block_str_all_cs1;
                for (1..$combo_count)
                {

                    $tmp_block_str_all_cs0[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    $tmp_block_str_all_cs1[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds_cs0 = &split_info($tmp_block_str_all_cs0[$_]);
                    @cur_blocks_sds_cs1 = &split_info($tmp_block_str_all_cs1[$_]);
                    if ($cur_blocks_sds_cs0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        # print "1:$1,2:$2, $info_list_href->[$_]->{0}->{'Flash Size'}\n";
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_cs0[$_] = $2;
                    }

                    if ($cur_blocks_sds_cs1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        #  print "1:$1,2:$2, $info_list_href->[$_]->{1}->{'Flash Size'}\n";
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_cs1[$_] = $2;
                        #  print "block : $tmp_sds_block_size_cs1[$_]\n";
                    }
                    #print "test1, $combo_count\n";

                }

                #  for(1..$#tmp_sds_block_size_cs0)
                #  {
                #       print "second temp block size : $tmp_sds_block_size_cs0[$_], $tmp_sds_block_size_cs1[$_],block str : $tmp_block_str_all_cs0[$_],$tmp_block_str_all_cs1[$_]\n";
                #  }
                #   print "test2\n";

                my $tmp_sds_start_cs0, $tmp_sds_last_block_start_cs0;
                my $sds_total_size_cs0;
                ###judge sds block size
                my @cur_uni_block_str_cs0;
                my @cur_uni_block_cs0;
                my $tmp_max_block_size_cs0 = 0;
                my @tmp_block_str_cs0, @tmp_block_size_cs0;
                my @cur_uni_block_cs1,@cur_uni_block_cs0;
                for (1..$combo_count)
                {
                    $cur_uni_block_str_cs0[$_] = $info_list_href->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_cs0[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs0[$_]);

                    $cur_uni_block_str_cs1[$_] = $info_list_href->[$_]->{1}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_cs1[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs1[$_]);

                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {

                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                            $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                            goto Finally2;
                        }
                        else
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x1000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                        }

                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                            $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                            goto Finally2;
                        }
                        else
                        {
                            $cur_block_str_cs1 = "\{0x0, 0x1000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                        }
                    }
                    else
                    {

                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            for (1..$combo_count)
                            {
                                if($tmp_max_block_size_cs0 < hex($tmp_sds_block_size_cs0[$_]))
                                {
                                    $tmp_max_block_size_cs0 = $tmp_sds_block_size_cs0[$_];
                                }
                            }
                            $sds_block_size_cs0 = $tmp_max_block_size_cs0;
                            #goto Finally2;
                        }
                        else
                        {
                            $sds_block_size_cs0 = sprintf("0x%X", $cur_uni_block_cs0[$_]*1024);
                        }


                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            for (1..$combo_count)
                            {
                                if($tmp_max_block_size_cs1 < hex($tmp_sds_block_size_cs1[$_]))
                                {
                                    $tmp_max_block_size_cs1 = $tmp_sds_block_size_cs1[$_];
                                }
                            }
                            $sds_block_size_cs1 = $tmp_max_block_size_cs1;
                            goto Finally2;
                        }
                        else
                        {
                            $sds_block_size_cs1 = sprintf("0x%X", $cur_uni_block_cs1[$_]*1024);
                        }
                    }
                }
                Finally2:
                ;#print "test Finally2\n";
                # print "second sds block size : $sds_block_size_cs0\n";
                if (!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                {
                    $sds_block_start_cs0 = sprintf("0x%X", (($info_list_href->[$_]->{0}->{'Size (Mb)'}*1024*1024/8) - hex($tmp_sds_block_size_cs0[$_])));
                    $sds_total_size_cs0  = &memConfig::Get_SDS_total_size(hex($sds_block_size_cs0), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                    $tmp_sds_start_cs0   = sprintf("0x%X", (($info_list_href->[$_]->{0}->{'Size (Mb)'}*1024*1024/8) - $sds_total_size_cs0));

                    $sds_block_start_cs1 = sprintf("0x%X", (($info_list_href->[$_]->{1}->{'Size (Mb)'}*1024*1024/8) - hex($tmp_sds_block_size_cs1[$_])));
                    $sds_total_size_cs1  = &memConfig::Get_SDS_total_size(hex($sds_block_size_cs1), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                    $tmp_sds_start_cs1   = sprintf("0x%X", (($info_list_href->[$_]->{1}->{'Size (Mb)'}*1024*1024/8) - $sds_total_size_cs1));

                    #print "second sds temp block start : $tmp_sds_start\n";
                    while(hex($sds_block_start_cs0) > hex($tmp_sds_start_cs0))
                    {
                        $sds_block_start_cs0 = sprintf("0x%X", hex($sds_block_start_cs0) - hex($tmp_sds_block_size_cs0[$_]));
                    }

                    while(hex($sds_block_start_cs1) > hex($tmp_sds_start_cs1))
                    {
                        $sds_block_start_cs1 = sprintf("0x%X", hex($sds_block_start_cs1) - hex($tmp_sds_block_size_cs1[$_]));
                    }
                    #    print "combo sds block start:$sds_block_start\n";

                    $cur_block_str_cs0 .= "\{$sds_block_start_cs0, $sds_block_size_cs0\}";
                    $cur_block_str_cs1 .= "\{$sds_block_start_cs1, $sds_block_size_cs1\}";
                }
                #$cur_block_str_cs0 .= $cur_blcok_str_cs1;

            }
            if(($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($mem_dev_type eq 'SERIAL_FLASH'))
            {
                my @sds_block_size_all_cs0, @cur_blocks_sds_cs0 ;
                my $sds_block_size_cs0, $sds_block_start_cs0, @tmp_sds_block_size_cs0;
                my @tmp_block_str_all_cs0;

                my @sds_block_size_all_cs1, @cur_blocks_sds_cs1 ;
                my $sds_block_size_cs1, $sds_block_start_cs1, @tmp_sds_block_size_cs1;
                my @tmp_block_str_all_cs1;
                for (1..$combo_count)
                {
                    $tmp_block_str_all_cs0[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds_cs0 = &split_info($tmp_block_str_all_cs0[$_]);
                    if ($cur_blocks_sds_cs0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_cs0[$_] = $2;
                    }

                    $tmp_block_str_all_cs1[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds_cs1 = &split_info($tmp_block_str_all_cs1[$_]);
                    if ($cur_blocks_sds_cs1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_cs1[$_] = $2;
                    }
                    # print "third temp block size : $tmp_sds_block_size_cs0[$_], $tmp_sds_block_size_cs1[$_],block str : $tmp_block_str_all_cs0[$_],$tmp_block_str_all_cs1[$_]\n";
                }

                my $tmp_sds_start_cs0, $tmp_sds_last_block_start_cs0;
                my $sds_total_size_cs0;
                ###judge sds block size
                my @cur_uni_block_str_cs0;
                my @cur_uni_block_cs0;
                my $tmp_max_block_size_cs0 = 0;
                my @tmp_block_str_cs0, @tmp_block_size_cs0;

                my $tmp_sds_start_cs1, $tmp_sds_last_block_start_cs1;
                my $sds_total_size_cs1;
                ###judge sds block size
                my @cur_uni_block_str_cs1;
                my @cur_uni_block_cs1;
                my $tmp_max_block_size_cs1 = 0;
                my @tmp_block_str_cs1, @tmp_block_size_cs1;
                for (1..$combo_count)
                {
                    $cur_uni_block_str_cs0[$_] = $info_list_href->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_cs0[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs0[$_]);

                    $cur_uni_block_str_cs1[$_] = $info_list_href->[$_]->{1}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_cs1[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs1[$_]);

                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {

                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                            $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                            goto Finally7;
                        }
                        else
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x1000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                        }

                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                            $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                            goto Finally7;
                        }
                        else
                        {
                            $cur_block_str_cs1 = "\{0x0, 0x1000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                        }
                    }
                    else
                    {
                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            for (1..$combo_count)
                            {
                                if ($tmp_max_block_size_cs0 < hex($tmp_sds_block_size_cs0[$_]))
                                {
                                    $tmp_max_block_size_cs0 = $tmp_sds_block_size_cs0[$_];
                                }
                            }
                            $sds_block_size_cs0 = $tmp_max_block_size_cs0;
                            goto Finally7;
                        }
                        else
                        {
                            $sds_block_size_cs0 = sprintf("0x%X", $cur_uni_block_cs0[$_]*1024);
                        }

                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            for (1..$combo_count)
                            {
                                if($tmp_max_block_size_cs1 < hex($tmp_sds_block_size_cs1[$_]))
                                {
                                    $tmp_max_block_size_cs1 = $tmp_sds_block_size_cs1[$_];
                                }
                            }
                            $sds_block_size_cs1 = $tmp_max_block_size_cs1;
                            goto Finally7;
                        }
                        else
                        {
                            $sds_block_size_cs1 = sprintf("0x%X", $cur_uni_block_cs1[$_]*1024);
                        }
                    }
                }
                ###
                #if(hex($sds_block_size_cs0) > hex($sds_block_size_cs1))
                #{
                #     $nor_disk0_block_size = hex($sds_block_size_cs0);
                #}
                #else
                #{
                #     $nor_disk0_block_size = hex($sds_block_size_cs1);
                #}

            }
            Finally7:
            ;#print "test Finally7\n";

            #  print "combo cur block str : $cur_block_str\n";
            my $block_cs1_str =$info_list_href->[$_]->{0}->{'Size (Mb)'}*1024*1024/8;
            my @cur_blocks_cs0 = &split_info($cur_block_str_cs0);  # list of Block Info.
            my @cur_blocks_cs1 = &split_info_cs1($cur_block_str_cs1, $block_cs1_str);


            #     for(0..$#cur_blocks_cs1)
            #    {
            #       print "block info cs1:$cur_blocks_cs1[$_]\n";
            #    }
            my @cur_blocks;
            #$cur_blocks_cs1[0] = (hex($info_list_href->[$_]->{0}->{'Size (Mb)'})*1024*1024/8);
            for (0..$#cur_blocks_cs0)
            {
                $cur_blocks[$_] = $cur_blocks_cs0[$_];
            }
            for (0..$#cur_blocks_cs1)
            {
                $cur_blocks[$_ + $#cur_blocks_cs0 + 1] = $cur_blocks_cs1[$_];
            }

            #      for(0..$#cur_blocks)
            #      {

            #         print "block info:$cur_blocks[$_]\n";
            #      }
            my @cur_entire_regions = &convert_blocks_to_regions(\@cur_blocks, $endaddr);  # list of Region Info. (of the entire flash)

            my (@cur_entire_regions_size, @cur_entire_regions_count);
            &convert_geo_hash_from_list(\@cur_entire_regions, \@cur_entire_regions_size, \@cur_entire_regions_count);
            ### Get the offset to the next boundary
            for (0..$#cur_entire_regions_size)
            {
                #print "region info:$cur_entire_regions_size[$_]\n";
            }

            for (0..$#cur_entire_regions_count)
            {
                # print "region count:$cur_entire_regions_count[$_]\n";
            }

            $size = &get_next_Geo_boundary(\@cur_entire_regions_size, \@cur_entire_regions_count, $curr_addr);
            # print "size:$size\n";
            last if ($size == 0);  # reach the end of RegionInfo/BankInfo
            if ($size > $largest_offset)
            {
                $largest_offset = $size;
            }
        }
        last if ($cur_combo_idx != $combo_count);  # early break in for loop represents end of RegionInfo/BankInfo is reached

        ### Check whether curr_address+largest_offset is still on the boundaries of all MCPs
        for (1..$combo_count)
        {
            $cur_combo_idx = $_;
            my $cur_block_str_cs0 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
            my $cur_block_str_cs1 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});

            my $cur_block_str_fdm5_cs0;
            my $cur_block_str_fdm5_cs1;
            my @cur_block_fdm5_cs0;
            my @cur_block_fdm5_cs1;
            my $cur_block_fdm5_tmp_cs0;
            my $cur_block_fdm5_tmp_cs1;
            if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
            {

                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $cur_block_str_fdm5_cs0 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    $cur_block_str_fdm5_cs1 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
                    @cur_block_fdm5_cs0 = &split_info($cur_block_str_fdm5_cs0);
                    @cur_block_fdm5_cs1 = &split_info($cur_block_str_fdm5_cs1);

                    if ($cur_block_fdm5_cs0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $cur_block_fdm5_tmp_cs0 = $2;
                    }

                    if ($cur_block_fdm5_cs1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $cur_block_fdm5_tmp_cs1 = $2;
                    }

                    if(hex($cur_block_fdm5_tmp_cs0) < 65536)
                    {
                        $cur_block_str_cs0 = "\{0x0, 0x1000\}";

                    }
                    else
                    {
                        $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                        $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                        goto Label9;
                    }

                    if(hex($cur_block_fdm5_tmp_cs1) < 65536)
                    {
                        if(hex($cur_block_fdm5_tmp_cs0) > 65536)
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                            $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                            goto Label9;
                        }
                        else
                        {
                            $cur_block_str_cs1 = "\{0x0, 0x1000\}";
                        }

                    }
                    else
                    {

                        $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                        $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                        goto Label9;
                    }
                }
            }
            Label9:
            ;#print "test Label9 $cur_block_str_cs0, $cur_block_str_cs1\n";

            if(($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($mem_dev_type eq 'SERIAL_FLASH'))
            {

                my @sds_block_size_all_cs0, @cur_blocks_sds_cs0 ;
                my $sds_block_size_cs0, $sds_block_start_cs0, @tmp_sds_block_size_cs0;
                my @tmp_block_str_all_cs0;

                my @sds_block_size_all_cs1, @cur_blocks_sds_cs1 ;
                my $sds_block_size_cs1, $sds_block_start_cs1, @tmp_sds_block_size_cs1;
                my @tmp_block_str_all_cs1;
                for (1..$combo_count)
                {
                    $tmp_block_str_all_cs0[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    $tmp_block_str_all_cs1[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds_cs0 = &split_info($tmp_block_str_all_cs0[$_]);
                    if ($cur_blocks_sds_cs0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_cs0[$_] = $2;
                    }

                    @cur_blocks_sds_cs1 = &split_info($tmp_block_str_all_cs1[$_]);
                    if ($cur_blocks_sds_cs1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{1}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_cs1[$_] = $2;
                    }
                    #print "third temp block size : $tmp_sds_block_size[$_], block str : $tmp_block_str_all[$_]\n";
                }

                my $tmp_sds_start_cs0, $tmp_sds_last_block_start_cs0;
                my $sds_total_size_cs0;
                ###judge sds block size
                my @cur_uni_block_str_cs0;
                my @cur_uni_block_cs0;
                my $tmp_max_block_size_cs0 = 0;
                my @tmp_block_str_cs0, @tmp_block_size_cs0;

                my $tmp_sds_start_cs1, $tmp_sds_last_block_start_cs1;
                my $sds_total_size_cs1;
                ###judge sds block size
                my @cur_uni_block_str_cs1;
                my @cur_uni_block_cs1;
                my $tmp_max_block_size_cs1 = 0;
                my @tmp_block_str_cs1, @tmp_block_size_cs1;
                for (1..$combo_count)
                {
                    $cur_uni_block_str_cs0[$_] = $info_list_href->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_cs0[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs0[$_]);

                    $cur_uni_block_str_cs1[$_] = $info_list_href->[$_]->{1}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_cs1[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs1[$_]);

                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {

                        if (($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                            $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                            goto Finally3;
                        }
                        else
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x1000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                        }

                        if (($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                            $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                            goto Finally3;
                        }
                        else
                        {
                            $cur_block_str_cs1 = "\{0x0, 0x1000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                        }
                    }
                    else
                    {
                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            for (1..$combo_count)
                            {
                                if($tmp_max_block_size_cs0 < hex($tmp_sds_block_size_cs0[$_]))
                                {
                                    $tmp_max_block_size_cs0 = $tmp_sds_block_size_cs0[$_];
                                }
                            }
                            $sds_block_size_cs0 = $tmp_max_block_size_cs0;
                            #goto Finally3;
                        }
                        else
                        {
                            $sds_block_size_cs0 = sprintf("0x%X", $cur_uni_block_cs0[$_]*1024);
                        }


                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            for (1..$combo_count)
                            {
                                if($tmp_max_block_size_cs1 < hex($tmp_sds_block_size_cs1[$_]))
                                {
                                    $tmp_max_block_size_cs1 = $tmp_sds_block_size_cs1[$_];
                                }
                            }
                            $sds_block_size_cs1 = $tmp_max_block_size_cs1;
                            goto Finally3;
                        }
                        else
                        {
                            $sds_block_size_cs1 = sprintf("0x%X", $cur_uni_block_cs1[$_]*1024);
                        }
                    }
                }
                ###
                Finally3:
                ;#print "test Finally3\n";
                if (!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                {
                    $sds_block_start_cs0 = sprintf("0x%X", (($info_list_href->[$_]->{0}->{'Size (Mb)'}*1024*1024/8) - hex($tmp_sds_block_size_cs0[$_])));
                    $sds_total_size_cs0 = &memConfig::Get_SDS_total_size(hex($sds_block_size_cs0), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                    $tmp_sds_start_cs0 = sprintf("0x%X", (($info_list_href->[$_]->{0}->{'Size (Mb)'}*1024*1024/8) - $sds_total_size_cs0));

                    while(hex($sds_block_start_cs0) > hex($tmp_sds_start_cs0))
                    {
                        $sds_block_start_cs0 = sprintf("0x%X", hex($sds_block_start_cs0) - hex($tmp_sds_block_size_cs0[$_]));
                    }

                    $sds_block_start_cs1 = sprintf("0x%X", (($info_list_href->[$_]->{1}->{'Size (Mb)'}*1024*1024/8) - hex($tmp_sds_block_size_cs1[$_])));
                    $sds_total_size_cs1 = &memConfig::Get_SDS_total_size(hex($sds_block_size_cs1), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                    $tmp_sds_start_cs1 = sprintf("0x%X", (($info_list_href->[$_]->{1}->{'Size (Mb)'}*1024*1024/8) - $sds_total_size_cs1));
                    #  print "sds temp block start : $tmp_sds_start\n";
                    while(hex($sds_block_start_cs1) > hex($tmp_sds_start_cs1))
                    {
                        $sds_block_start_cs1 = sprintf("0x%X", hex($sds_block_start_cs1) - hex($tmp_sds_block_size_cs1[$_]));
                    }
                    #   print "combo sds block start:$sds_block_start\n";
                    $cur_block_str_cs0 .= "\{$sds_block_start_cs0, $sds_block_size_cs0\}";
                    $cur_block_str_cs1 .= "\{$sds_block_start_cs1, $sds_block_size_cs1\}";
                }
                #$cur_block_str_cs0 .= $cur_block_str_cs1;

            }

            if(($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($mem_dev_type eq 'SERIAL_FLASH'))
            {
                my @sds_block_size_all_cs0, @cur_blocks_sds_cs0 ;
                my $sds_block_size_cs0, $sds_block_start_cs0, @tmp_sds_block_size_cs0;
                my @tmp_block_str_all_cs0;

                my @sds_block_size_all_cs1, @cur_blocks_sds_cs1 ;
                my $sds_block_size_cs1, $sds_block_start_cs1, @tmp_sds_block_size_cs1;
                my @tmp_block_str_all_cs1;
                for (1..$combo_count)
                {
                    $tmp_block_str_all_cs0[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds_cs0 = &split_info($tmp_block_str_all_cs0[$_]);
                    if ($cur_blocks_sds_cs0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_cs0[$_] = $2;
                    }

                    $tmp_block_str_all_cs1[$_] = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($info_list_href->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds_cs1 = &split_info($tmp_block_str_all_cs1[$_]);
                    if ($cur_blocks_sds_cs1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $info_list_href->[$_]->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_cs1[$_] = $2;
                    }
                    # print "third temp block size : $tmp_sds_block_size_cs0[$_], $tmp_sds_block_size_cs1[$_],block str : $tmp_block_str_all_cs0[$_],$tmp_block_str_all_cs1[$_]\n";
                }

                my $tmp_sds_start_cs0, $tmp_sds_last_block_start_cs0;
                my $sds_total_size_cs0;
                ###judge sds block size
                my @cur_uni_block_str_cs0;
                my @cur_uni_block_cs0;
                my $tmp_max_block_size_cs0 = 0;
                my @tmp_block_str_cs0, @tmp_block_size_cs0;

                my $tmp_sds_start_cs1, $tmp_sds_last_block_start_cs1;
                my $sds_total_size_cs1;
                ###judge sds block size
                my @cur_uni_block_str_cs1;
                my @cur_uni_block_cs1;
                my $tmp_max_block_size_cs1 = 0;
                my @tmp_block_str_cs1, @tmp_block_size_cs1;
                for (1..$combo_count)
                {
                    $cur_uni_block_str_cs0[$_] = $info_list_href->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_cs0[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs0[$_]);

                    $cur_uni_block_str_cs1[$_] = $info_list_href->[$_]->{1}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_cs1[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs1[$_]);

                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {

                        if (($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                            $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                            goto Finally8;
                        }
                        else
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x1000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                        }

                        if (($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            $cur_block_str_cs0 = "\{0x0, 0x10000\}";
                            $cur_block_str_cs1 = "\{0x0, 0x10000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                            goto Finally8;
                        }
                        else
                        {
                            $cur_block_str_cs1 = "\{0x0, 0x1000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                        }
                    }
                    else
                    {
                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            for (1..$combo_count)
                            {
                                if($tmp_max_block_size_cs0 < hex($tmp_sds_block_size_cs0[$_]))
                                {
                                    $tmp_max_block_size_cs0 = $tmp_sds_block_size_cs0[$_];
                                }
                          }
                          $sds_block_size_cs0 = $tmp_max_block_size_cs0;
                          goto Finally8;
                        }
                        else
                        {
                            $sds_block_size_cs0 = sprintf("0x%X", $cur_uni_block_cs0[$_]*1024);
                        }

                        if(($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            for (1..$combo_count)
                            {
                                if($tmp_max_block_size_cs1 < hex($tmp_sds_block_size_cs1[$_]))
                                {
                                    $tmp_max_block_size_cs1 = $tmp_sds_block_size_cs1[$_];
                                }
                            }
                            $sds_block_size_cs1 = $tmp_max_block_size_cs1;
                            goto Finally8;
                        }
                        else
                        {
                            $sds_block_size_cs1 = sprintf("0x%X", $cur_uni_block_cs1[$_]*1024);
                        }
                    }
                }
                Finally8:
                ;#print "test Finally8\n";
                #  print "sds block : $sds_block_size_cs1,$sds_block_size_cs0\n";
                ###
                # if(hex($sds_block_size_cs0) > hex($sds_block_size_cs1))
                # {
                #      $nor_disk0_block_size = hex($sds_block_size_cs0);
                # }
                # else
                # {
                #      $nor_disk0_block_size = hex($sds_block_size_cs1);
                # }

            }

            my $block_cs1_str =$info_list_href->[$_]->{0}->{'Size (Mb)'}*1024*1024/8;
            my @cur_blocks_cs0 = &split_info($cur_block_str_cs0);  # list of Block Info.
            my @cur_blocks_cs1 = &split_info_cs1($cur_block_str_cs1, $block_cs1_str);


            #      for(0..$#cur_blocks_cs1)
            #     {
            #        print "block info cs1:$cur_blocks_cs1[$_]\n";
            #     }
            my @cur_blocks;
            #$cur_blocks_cs1[0] = (hex($info_list_href->[$_]->{0}->{'Size (Mb)'})*1024*1024/8);
            for (0..$#cur_blocks_cs0)
            {
                $cur_blocks[$_] = $cur_blocks_cs0[$_];
            }
            for (0..$#cur_blocks_cs1)
            {
                $cur_blocks[$_ + $#cur_blocks_cs0 + 1] = $cur_blocks_cs1[$_];
            }

            for (0..$#cur_blocks)
            {

                #         print "block info cs all get common mdl info:$cur_blocks[$_]\n";
            }

            my @cur_entire_regions = &convert_blocks_to_regions(\@cur_blocks, $endaddr);  # list of Region Info. (of the entire flash)
            my (@cur_entire_regions_size, @cur_entire_regions_count);
            #      for(0..$#cur_entire_regions)
            #      {
            #         print "region info:$cur_entire_regions[$_]\n";
            #      }
            &convert_geo_hash_from_list(\@cur_entire_regions, \@cur_entire_regions_size, \@cur_entire_regions_count);
            last if (&query_if_Geo_boundary(\@cur_entire_regions_size, \@cur_entire_regions_count, $curr_addr+$largest_offset) != 1);
        }
        # The address is not on the boundaries of all MCPs, need to go to the next address
        # The next address is curr_addr + largest_offset
        #  print "offset before:$cur_combo_idx,$combo_count,$largest_offset\n";
        if ($cur_combo_idx != $combo_count)
        {
            $curr_addr += $largest_offset;
            next;
        }
        #  print "offset after:$cur_combo_idx,$combo_count,$largest_offset\n";
        ### Add the address into the output RegionInfo/BankInfo
        # Get the size of common block/bank size
        $common_size = $curr_addr + $largest_offset - $prev_addr;
        if ($prev_addr == $baseaddr)  # the first entry
        {
            $region_info_size_href->[0] = $common_size;
            $region_info_count_href->[0] = 1;
            #print "1:$common_size\n";
        }
        elsif ($common_size == $region_info_size_href->[$idx])  # the size is identical to the last bank we added --> count + 1
        {
            $region_info_count_href->[$idx]++;
            # print "3:$common_size, $region_info_size_href->[$idx]\n";
        }
        else  # tje soze os different from the last bank we added --> append new entry
        {
            $idx++;
            $region_info_size_href->[$idx] = $common_size;
            $region_info_count_href->[$idx] = 1;
             #print "2:$common_size\n";
        }

        for (0..$#$region_info_size_href)
        {

             #print "region info cs all get common mdl info:$region_info_size_href->[$idx], $region_info_count_href->[$idx]\n";
        }

        ### Increment the current address and then perform the loop again
        $curr_addr += $largest_offset;
        $prev_addr = $curr_addr;
        #  print "cur addr after : $curr_addr, $prev_addr, $endaddr\n";
    }

    ### Get common BankInfo
    $prev_addr = $baseaddr;
    $curr_addr = $baseaddr;
    $idx = 0;
    while ($curr_addr < $endaddr)  # traverse till the endaddr
    {
        ### Find the largest block/bank offset from the current address to the next boundary
        ### Stop if the end of BankInfo or RegionInfo has been reached
        my $largest_offset = 0;  # largest offset from curr_addr to the next block/bank boundary
        my $common_size = 0;  # final(common) block/bank size of this round
        my $size;  # current offset from curr_addr to the next block/bank boundary
        my $cur_combo_idx;

        for (1..$combo_count)
        {
            $cur_combo_idx = $_;
            my $cur_bank_str_cs0 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Bank Info.'});
            my $cur_bank_str_cs1 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($info_list_href->[$_]->{1}->{'Device Geometry'}->{'Bank Info.'});
            my @cur_banks_cs0 = &split_info($cur_bank_str_cs0);  # list of Bank Info.
            my @cur_banks_cs1 = &split_info($cur_bank_str_cs1);  # list of Bank Info.

            my (@cur_banks_size, @cur_banks_count);
            my (@cur_banks_size_cs0, @cur_banks_count_cs0, @cur_banks_size_cs1, @cur_banks_count_cs1);
            &convert_geo_hash_from_list(\@cur_banks_cs0, \@cur_banks_size_cs0, \@cur_banks_count_cs0);
            &convert_geo_hash_from_list(\@cur_banks_cs1, \@cur_banks_size_cs1, \@cur_banks_count_cs1);

            for(0..$#cur_banks_cs0)
            {
               $cur_banks_size[$_] = $cur_banks_size_cs0[$_]*$cur_banks_count_cs0[$_] + $cur_banks_size_cs1[$_]*$cur_banks_count_cs1[$_];
               $cur_banks_count[$_] = $cur_banks_count_cs0[$_];
            }
            ### Get the offset to the next boundary
            $size = &get_next_Geo_boundary(\@cur_banks_size, \@cur_banks_count, $curr_addr);
            last if ($size == 0);  # reach the end of RegionInfo/BankInfo
            if ($size > $largest_offset)
            {
                $largest_offset = $size;
            }
        }
        last if ($cur_combo_idx != $combo_count);  # early break in for loop represents end of RegionInfo/BankInfo is reached

        ### Check whether curr_address+largest_offset is still on the boundaries of all MCPs
        for (1..$combo_count)
        {
            $cur_combo_idx = $_;
            my $cur_bank_str_cs0 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{0}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($info_list_href->[$_]->{0}->{'Device Geometry'}->{'Bank Info.'});
            my $cur_bank_str_cs1 = ($mem_dev_type eq 'NOR_RAM_MCP') ? ($info_list_href->[$_]->{1}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($info_list_href->[$_]->{1}->{'Device Geometry'}->{'Bank Info.'});
            my @cur_banks_cs0 = &split_info($cur_bank_str_cs0);  # list of Bank Info.
            my @cur_banks_cs1 = &split_info($cur_bank_str_cs1);  # list of Bank Info.

            my (@cur_banks_size, @cur_banks_count);
            my (@cur_banks_size_cs0, @cur_banks_count_cs0, @cur_banks_size_cs1, @cur_banks_count_cs1);
            &convert_geo_hash_from_list(\@cur_banks_cs0, \@cur_banks_size_cs0, \@cur_banks_count_cs0);
            &convert_geo_hash_from_list(\@cur_banks_cs1, \@cur_banks_size_cs1, \@cur_banks_count_cs1);

            for(0..$#cur_banks_cs0)
            {
               $cur_banks_size[$_] = $cur_banks_size_cs0[$_]*$cur_banks_count_cs0[$_] + $cur_banks_size_cs1[$_]*$cur_banks_count_cs1[$_];
               $cur_banks_count[$_] = $cur_banks_count_cs0[$_];
            }
            last if (&query_if_Geo_boundary(\@cur_banks_size, \@cur_banks_count, $curr_addr+$largest_offset) != 1);
        }
        # The address is not on the boundaries of all MCPs, need to go to the next address
        # The next address is curr_addr + largest_offset
        if ($cur_combo_idx != $combo_count)
        {
            $curr_addr += $largest_offset;
            next;
        }

        ### Add the address into the output RegionInfo/BankInfo
        # Get the size of common block/bank size
        $common_size = $curr_addr + $largest_offset - $prev_addr;

        if ($prev_addr == $baseaddr)  # the first entry
        {
            $bank_info_size_href->[0] = $common_size;
            $bank_info_count_href->[0] = 1;
        }
        elsif ($common_size == $bank_info_size_href->[$idx])  # the size is identical to the last bank we added --> count + 1
        {
            $bank_info_count_href->[$idx]++;
        }
        else  # tje soze os different from the last bank we added --> append new entry
        {
            $idx++;
            $bank_info_size_href->[$idx] = $common_size;
            $bank_info_count_href->[$idx] = 1;
        }

        ### Increment the current address and then perform the loop again
        $curr_addr += $largest_offset;
        $prev_addr = $curr_addr;
    }
    #  print "pass block info\n";
}

#****************************************************************************
# subroutine:  get_next_Geo_boundary
# input:       $geo_size_list_href:  input list reference of geometry (Size list)
#              $geo_count_list_href: input list reference of geometry (Size list)
#              $addr:                current address from which to query next boundary
# output:      $size:                size from current address to the next boundary
#****************************************************************************
sub get_next_Geo_boundary
{
    my ($geo_size_list_href, $geo_count_list_href, $addr) = @_;
    my $size;

    ### for all {Size, Count} pairs
    for (0..$#$geo_size_list_href)
    {
        ### Treat the address as a pile of blocks. Remove them region by region.
        if (($geo_size_list_href->[$_]*$geo_count_list_href->[$_]) <= $addr)
        {
            $addr -= $geo_size_list_href->[$_]*$geo_count_list_href->[$_];
            next;
        }

        ### Blocks that cannot fit-into one region.
        # 1. We have found the region that addr belongs to.
        # 2. The addr is aligned, if (addr % Size[$_]) equals 0.
        # 3. The offset to the next boundary is (Size[$_] - (addr % Size[$_]))
        return ($geo_size_list_href->[$_] - ($addr % $geo_size_list_href->[$_]));
    }

    return 0;
}

#****************************************************************************
# subroutine:  query_if_Geo_boundary
# input:       $geo_size_list_href:  input list reference of geometry (Size list)
#              $geo_count_list_href: input list reference of geometry (Size list)
#              $addr:                address to be checked whether it is on the boundary or not
# output:      $is_boundary:         1 if the queried address is on the boundary of all MCPs
#****************************************************************************
sub query_if_Geo_boundary
{
    my ($geo_size_list_href, $geo_count_list_href, $addr) = @_;
    my $ret;

    ### for all {Size, Count} pairs
    for (0..$#$geo_size_list_href)
    {
        ### Treat the address as a pile of blocks. Remove them region by region.
        if (($geo_size_list_href->[$_]*$geo_count_list_href->[$_]) <= $addr)
        {
            $addr -= $geo_size_list_href->[$_]*$geo_count_list_href->[$_];
            next;
        }

        ### Blocks that cannot fit-into one region.
        # 1. We have found the region that addr belongs to.
        # 2. The addr is aligned, if (addr % Size[$_]) equals 0.
        # 3. The offset to the next boundary is (Size[$_] - (addr % Size[$_]))
        if (($addr % $geo_size_list_href->[$_]) != 0)
        {
            return 0;
        }
    }
    return 1;
}

#****************************************************************************
# subroutine:  split_info
# return:      List of RegionInfo/BlockInfo/BankInfo
# input:       $info: Excel value to be split
#****************************************************************************
sub split_info
{
    my ($info) = @_;
    my $ret_str;
    my @ret_info;

    if ($info eq '*')
    {
        push @ret_info, $info;
        return @ret_info;
    }

    while ($info =~ /\{(0x\w+)\s*,\s*(\w+)\}/)
    {
        $ret_str = "{" . $1 . "," . $2 . "}";
        push @ret_info, $ret_str;
        $info = $';
    }
    return @ret_info;
}

#****************************************************************************
# subroutine:  split_info
# return:      List of RegionInfo/BlockInfo/BankInfo
# input:       $info: Excel value to be split
#****************************************************************************
sub split_info_cs1
{
    my ($info, $flash_size_cs0) = @_;
    my $ret_str;
    my @ret_info;

    if ($info eq '*')
    {
        push @ret_info, $info;
        return @ret_info;
    }
    # print "cs1:$flash_size_cs0\n";
    while ($info =~ /\{(0x\w+)\s*,\s*(\w+)\}/)
    {
        # if(hex($1) == 0)
        # {
        #      $info = $';
        # }
        # else
        # {
        my $block_str = sprintf("0x%08X", ($flash_size_cs0 + hex($1)));
        $ret_str = "{" . $block_str . "," . $2 . "}";
        push @ret_info, $ret_str;
        $info = $';
        # }

    }
    return @ret_info;
}


#****************************************************************************
# subroutine:  region_info
# return:      template of part "configure flash memory for FAT"
#****************************************************************************
sub region_info
{
    my ($region_size_href, $region_count_href, $naming, $newline) = @_;
    my $region_info_lines;

    for (0..$#$region_size_href)
    {
        my $tmp_size = sprintf("0x%X", $region_size_href->[$_]);
        my $tmp_count = sprintf("%d", $region_count_href->[$_]);
        if ($_ == $#$region_size_href)
        {
            $region_info_lines .=  "   \{$tmp_size, $tmp_count\},\n";
        }
        else
        {
            $region_info_lines .=  "   \{$tmp_size, $tmp_count\}, \\$newline\n";
        }
    }
    chomp $region_info_lines;

    if (!defined $naming)
    {
        return $region_info_lines;
    }

    ###
    my $template;
    if (defined $newline)
    {
        $template .= <<"__TEMPLATE";
$region_info_lines
__TEMPLATE
        return $template;
    }
    my $naming_str = sprintf("$naming\[\]");
    if ($naming eq 'oriRegionInfo')
    {
        $template .= <<"__TEMPLATE";
FLASH_REGIONINFO_VAR_MODIFIER FlashRegionInfo $naming_str =
{
$region_info_lines
   EndoriRegionInfo
};
__TEMPLATE
    }
    else
    {
        $template .= <<"__TEMPLATE";
#define $naming $region_info_lines
__TEMPLATE
    }

    chomp $template;
    return $template;
}

#****************************************************************************
# subroutine:  block_info
# return:      template of part "configure flash memory for FAT"
# input:       $tmp_blocks: Block Info
#              $newline:    whether there exists newline character and comments in the output Block Info string
#****************************************************************************
sub block_info
{
    my ($block_start_href, $block_size_href, $MAKEFILE_OPTIONS_LOCAL, $COMM_MDL_INFO_LOCAL, $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $newline) = @_;
    my $block_info_lines;
    my $block_info_lines_sds;
    my @sds_block_size_all ;
    my $sds_block_size;
    for (0..$#$block_start_href)
    {
        my $tmp_start = sprintf("0x%X", $block_start_href->[$_]);
        my $tmp_size = sprintf("0x%X", $block_size_href->[$_]);

        print "start:$tmp_start, size:$tmp_size\n";
        if ($_ == $#$block_start_href)
        {
            $block_info_lines .=  "    \{$tmp_start, $tmp_size\},\n";
        }
        else
        {
            $block_info_lines .=  "    \{$tmp_start, $tmp_size\}, $newline\n";
        }
    }
    chomp $block_info_lines;

    ###
    my $template;
    if (defined $newline)
    {
        $template .= <<"__TEMPLATE";
$block_info_lines
__TEMPLATE
    }
    else
    {
        $template .= <<"__TEMPLATE";
/*
FLASH_REGIONINFO_VAR_MODIFIER FlashBlockTBL NOTREADYYET[] =
{
$block_info_lines
    EndBlockInfo
};
*/
__TEMPLATE
    }

    return $template;
}

#****************************************************************************
# subroutine:  bank_info
# return:      template of part "configure flash memory for FAT"
# input:       $bank_size_href:  Bank Info size
#              $bank_count_href: Bank Info count
#              $offset:          the offset to start counting bank
#              $target_size:     the size of the FAT
#              $newline:         whether there exists newline character and comments in the output Bank Info string
#****************************************************************************
sub bank_info
{
    my ($bank_size_href, $bank_count_href, $offset, $target_size, $newline) = @_;
    my $template;

    if (defined $newline)
    {
        for (0..$#$bank_size_href)
        {
            my $tmp_size = sprintf("0x%X", $bank_size_href->[$_]);
            my $tmp_count = sprintf("%d", $bank_count_href->[$_]);
            if ($_ == $#$bank_size_href)
            {
                $template .= "   \{$tmp_size, $tmp_count\},\n";
            }
            else
            {
                $template .= "   \{$tmp_size, $tmp_count\}, $newline\n";
            }
        }
        return $template;
    }
    for (0..$#$bank_size_href)
    {
        my $tmp_size = sprintf("0x%X", $bank_size_href->[$_]);
        my $tmp_count = sprintf("%d", $bank_count_href->[$_]);

        my $segment = ( hex($tmp_size) * $tmp_count );
        if ($offset <= 0)
        # Bank already in
        {
            if ($target_size >= $segment)
            # Bank full in-used
            {
                $template .= sprintf("   \{0x%X, %d\}, %s\\\n", hex($tmp_size), $tmp_count);
            }
            elsif ($target_size > 0)
            # Bank partial used
            {
                my $tmp = int($target_size / hex($tmp_size));;
                if ( int($target_size / hex($tmp_size)) > 0 )
                {
                    $template .= sprintf("   \{0x%X, %d\}, %s\\\n", hex($tmp_size), int($target_size / hex($tmp_size)));
                    $target_size    -= hex($tmp_size) * int($target_size / hex($tmp_size));
                }
                if ($target_size > 0)
                {
                    $template .= sprintf("   \{0x%X, %d\}, %s\\\n", $target_size , 1);
                }
            }
            else
            # Bank discarded
            {
            }
            $target_size -= $segment;
        }
        elsif ($offset < $segment)
        # Segment cross the FAT Baseaddr
        {
            my $c = $tmp_count;
            while ($offset >= hex($tmp_size))
            {
                $c--;
                $offset -= hex($tmp_size);
            }
            # Bank partial in-used
            if ($offset > 0 and (hex($tmp_size) - $offset) >= $target_size)
            {
                $template .= sprintf("   \{0x%X, %d\}, %s\\\n", $target_size, 1);
                $target_size    -= hex($tmp_size);
                $c--;
            }
            elsif ($offset > 0)
            {
                $template .= sprintf("   \{0x%X, %d\}, %s\\\n", (hex($tmp_size) - $offset), 1);
                $target_size    -= (hex($tmp_size) - $offset);
                $c--;
            }
            # discount $offset and make $offset to negative value
            $offset   -= hex($tmp_size);

            next if ($c == 0); # already last one bank on the FAT boundary
            if ($target_size >= (hex($tmp_size) * $c))
            {
                $template .= sprintf("   \{0x%X, %d\}, %s\\\n", hex($tmp_size), $c);
                $target_size    -= (hex($tmp_size) * $c);
            }
            elsif ($target_size > 0)
            {
                if ( int($target_size / hex($tmp_size)) > 0 )
                {
                    $template .= sprintf("   \{0x%X, %d\}, %s\\\n", hex($tmp_size), int($target_size / hex($tmp_size)));
                    $target_size    -= hex($1) * int($target_size / hex($tmp_size));
                }
                if ($target_size > 0)
                {
                    $template .= sprintf("   \{0x%X, %d\}, %s\\\n", $target_size , 1);
                }
            }
        }
        # No output and down counting to reach FAT Baseaddr
        else
        {
            $offset -= $segment;
        }
    }

    $template = "   {x , x},\n" if not defined $template;

    chomp($template);
    return $template;
}

#****************************************************************************
# subroutine:  convert_blocks_to_regions
# return:      RegionInfo of the entire flash, in {size, count} format instead of {start, size} format
# input:       $tmp_blocks: input list of blocks
# output:      @regions:    output list of regions
#****************************************************************************
sub convert_blocks_to_regions
{
    my ($tmp_blocks, $endaddr) = @_;
    my @regions;
    my ($cur_reg_start, $cur_block_size, $prev_reg_start, $prev_block_size);

    for (0..$#$tmp_blocks)
    {
        if ($tmp_blocks->[$_] =~ /\{(\w+)\s*,\s*(\w+)\}/) # match {0x20000, 7}
        {
            $cur_reg_start = hex($1);
            $cur_block_size = hex($2);
        }

        if ($_ > 0)
        {
            if ($tmp_blocks->[$_-1] =~ /\{(\w+)\s*,\s*(\w+)\}/) # match {0x20000, 7}
            {
                $prev_reg_start = hex($1);
                $prev_block_size = hex($2);
                #print "before 1:$1,2:$2\n";
            }

            if ($prev_block_size == 0)
            {

            }
            else
            {
                my $tmp_region_info_line = sprintf("\{0x%X,%d\}", $prev_block_size, ($cur_reg_start-$prev_reg_start)/$prev_block_size);
                push @regions, $tmp_region_info_line;
            }
        }
    }
    my $tmp_region_info_line;
    #print "end addr : $endaddr\n";
    if ($#$tmp_blocks >= 0)
    {
        if ($cur_block_size == 0)
        {

        }
        else
        {
            $tmp_region_info_line = sprintf("\{0x%X,%d\}", $cur_block_size, ($endaddr-$cur_reg_start)/$cur_block_size);
        }

    }
    push @regions, $tmp_region_info_line;

    return @regions;
}

#****************************************************************************
# subroutine:  convert_regions_to_blocks
# return:      BlockInfo of the input RegionInfo, in {start, size} format instead of {size, count} format
# input:       $regions_start:          start address of region info
#              $tmp_regions_size_list:  input list of regions size
#              $tmp_regions_count_list: input list of regions count
# output:      $output_blocks_start_list: output list of blocks start
#              $output_blocks_size_list:  output list of blocks size
#****************************************************************************
sub convert_regions_to_blocks
{
    my ($regions_start, $tmp_regions_size_list, $tmp_regions_count_list, $output_blocks_start_list, $output_blocks_size_list) = @_;
    my @ret_blocks;

    my $idx = 0;
    $output_blocks_start_list->[0] = $regions_start;
    for (0..$#$tmp_regions_size_list)
    {
        $idx = $_;
        # the block size is identical to the region block size
        $output_blocks_size_list->[$_] = $tmp_regions_size_list->[$_];
        # the offset equals to the accumulated size of former regions
        if ($_ != $#$tmp_regions_size_list)
        {
            $output_blocks_start_list->[$_+1] = $output_blocks_start_list->[$_] + ($tmp_regions_size_list->[$_]*$tmp_regions_count_list->[$_]);
        }
    }
}

#****************************************************************************
# subroutine:  convert_geo_hash_from_list
# return:      lists of flash geometry in {size, count} format
# input:       $list_href:                  input list of blocks/banks
#              $geo_size_list_output_href:  Size part of flash geometry pairs
#              $geo_count_list_output_href: Count part of flash geometry pairs
#****************************************************************************
sub convert_geo_hash_from_list
{
    my ($list_href, $geo_size_list_output_href, $geo_count_list_output_href) = @_;

    for (0..$#$list_href)
    {
        if ($list_href->[$_] =~ /\{(\w+)\s*,\s*(\w+)\}/) # match {0x20000, 7}
        {
            $geo_size_list_output_href->[$_] = hex($1);
            $geo_count_list_output_href->[$_] = $2;
        }
    }
}


#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query Flash Block Size
# input:       Flash Offset Address
# Output:      Flash block size
#****************************************************************************
sub config_query_flash_block_sz
{
    my ($offset, $COMM_MDL_INFO_LOCAL, $ENTIRE_BLOCK_INFO_START_LIST_LOCAL, $ENTIRE_BLOCK_INFO_SIZE_LIST_LOCAL) = @_;

    &error_handler("tools\\emigenflash.pl: Query Block Size at $offset larger than available size!", __FILE__, __LINE__) if ($offset > $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});

    for (0..$#$ENTIRE_BLOCK_INFO_START_LIST_LOCAL)
    {
        return ($ENTIRE_BLOCK_INFO_SIZE_LIST_LOCAL->[$#$ENTIRE_BLOCK_INFO_START_LIST_LOCAL-$_]) if ($offset >= $ENTIRE_BLOCK_INFO_START_LIST_LOCAL->[$#$ENTIRE_BLOCK_INFO_START_LIST_LOCAL-$_]);
    }
    &error_handler("tools\\emigenflash.pl: Unreachable!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  flash_opt_h_file_body
# return:      flash opt header file
#****************************************************************************
sub flash_opt_gen_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $THEMF_LOCAL, $entire_bank_info_size_list_LOCAL, $entire_bank_info_count_list_LOCAL, $entire_block_info_start_list_LOCAL, $entire_block_info_size_list_LOCAL, $entire_region_info_size_list_LOCAL, $entire_region_info_count_list_LOCAL, $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MCP_LIST_LOCAL) = @_;
    my $current_nor_opt;

    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPSDRAM') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPDDR') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPDDR2') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'SPI_NAND'))
    {
        if ($COMM_MDL_INFO_LOCAL->{0}->{'PBP'}->{'Y / N'} =~ /Y/i)
        {
            $current_nor_opt .= "#define __PAGE_BUFFER_PROGRAM__\n";
        }

        if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
        {
            $current_nor_opt .= "#define __SERIAL_FLASH__\n";
        }

        ### Define flash types
        my $cnt_sibley = 0;
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            if ($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE')
            {
                if ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Comm. Series'} =~ /(\w*)/i)
                {
                    my $tmp_series = $1;
                    if ($current_nor_opt =~ /$tmp_series/)
                    {
                    }
                    else
                    {
                        if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
                        {
                            $current_nor_opt .= "#define SF_DAL_" . $tmp_series . "\n";
                        }
                        else
                        {
                            $current_nor_opt .= "#define NOR_FLASH_TYPE_" . $tmp_series . "\n";
                            if ($tmp_series eq 'INTEL_SIBLEY')
                            {
                                $cnt_sibley++;
                            }
                        }
                    }
                }

                if ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Comm. Series'} =~ /(\w*)/i)
                {
                    my $tmp_series = $1;
                    if ($current_nor_opt =~ /$tmp_series/)
                    {
                    }
                    else
                    {
                        if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
                        {
                            $current_nor_opt .= "#define SF_DAL_" . $tmp_series . "\n";
                        }
                        else
                        {
                            $current_nor_opt .= "#define NOR_FLASH_TYPE_" . $tmp_series . "\n";
                            if ($tmp_series eq 'INTEL_SIBLEY')
                            {
                                $cnt_sibley++;
                            }
                        }
                    }
                }
            }
            else
            {
                if ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Comm. Series'} =~ /(\w*)/i)
                {
                    my $tmp_series = $1;
                    if ($current_nor_opt =~ /$tmp_series/)
                    {
                    }
                    else
                    {
                        if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
                        {
                            $current_nor_opt .= "#define SF_DAL_" . $tmp_series . "\n";
                        }
                        else
                        {
                            $current_nor_opt .= "#define NOR_FLASH_TYPE_" . $tmp_series . "\n";
                            if ($tmp_series eq 'INTEL_SIBLEY')
                            {
                                $cnt_sibley++;
                            }
                        }
                    }
                }
            }

        }
        if ($cnt_sibley != $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            $current_nor_opt .= "#define __NON_INTEL_SIBLEY__\n";
        }


        $current_nor_opt .= "\n";
        $current_nor_opt .= "\n";

        if ($COMM_MDL_INFO_LOCAL->{0}->{'Bank'} =~ /M/i)
        {
            $current_nor_opt .= "#define __MULTI_BANK_NOR_DEVICE__\n";
        }
        elsif ($COMM_MDL_INFO_LOCAL->{0}->{'Bank'} =~ /S/i)
        {
            $current_nor_opt .= "#define __SINGLE_BANK_NOR_DEVICE__\n";
        }
    }

    ###
    my $pbp_size            = ($COMM_MDL_INFO_LOCAL->{0}->{'PBP'}->{'Y / N'} =~ /Y/i)
                            ?  $COMM_MDL_INFO_LOCAL->{0}->{'PBP'}->{'Size(W)'}
                            : 0;

    ###
    my $nor_max_block_size_str = sprintf("0x%X", $nor_max_block_size);
    my $nor_disk0_block_size_str ;
    if (($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE') && ($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE'))
    {
        $nor_disk0_block_size_str = sprintf("0x%X", $nor_max_block_size);
    }
    else
    {
        $nor_disk0_block_size_str = sprintf("0x%X", $nor_disk0_block_size);
    }

    ###
    my $nand_total_size = 0;
    my $nand_block_size = 0;
    if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6922'))
    {
        if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND'))
        {
            $nand_total_size = ($COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} == 0xffffffff)
                             ? 0
                             : ($COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} / (1024*1024));
            $nand_block_size = $COMM_MDL_INFO_LOCAL->{0}->{'NAND Block Size(KB)'};
        }
    }
    else
    {
        if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SPI_NAND'))
        {
            $nand_total_size = ($COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} == 0xffffffff)
                             ? 0
                             : ($COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} / (1024*1024));
            $nand_block_size = $COMM_MDL_INFO_LOCAL->{0}->{'NAND Block Size(KB)'};
        }
    }
    ###
    my $base_addr_string    = sprintf("0x%08X", $COMM_MDL_INFO_LOCAL->{0}->{'Default FAT Base'});
    my $fat_space_string    = sprintf("0x%08X", $COMM_MDL_INFO_LOCAL->{0}->{'Default FAT Size'});

    ###
    my $fota_check;
    if ($MAKEFILE_OPTIONS_LOCAL->{'fota_enable'} eq 'FOTA_DM')
    {
           $fota_check = <<"__TEMPLATE";
#ifndef __FOTA_DM__
    #error "$THEMF: Error! FOTA_ENABLE should be set to FOTA_DM!"
#endif /* __FOTA_DM__ */
__TEMPLATE
    }
    else
    {
           $fota_check = <<"__TEMPLATE";
#ifdef __FOTA_DM__
    #error "$THEMF_LOCAL: Error! FOTA_ENABLE should not be defined!"
#endif /* __FOTA_DM__ */
__TEMPLATE
    }

    ###
    my ($fota_nor_region_def, $fota_nor_block_def, $fota_nor_bank_def);
    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP')
    {
        $fota_nor_region_def = &region_info($entire_region_info_size_list_LOCAL, $entire_region_info_count_list_LOCAL, undef, '\\');
        $fota_nor_block_def = &block_info($entire_block_info_start_list_LOCAL, $entire_block_info_size_list_LOCAL, $MAKEFILE_OPTIONS_LOCAL, $COMM_MDL_INFO_LOCAL, $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL,'\\');
        $fota_nor_bank_def = &bank_info($entire_bank_info_size_list_LOCAL, $entire_bank_info_count_list_LOCAL, 0, $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'}, '\\');
    }

    ###
    my $command_compile_option;
    #if ((!defined $MAKEFILE_OPTIONS_LOCAL->{'combo_memory_support'}) or ($MAKEFILE_OPTIONS_LOCAL->{'combo_memory_support'} eq 'FALSE'))
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        if (($MCP_LIST_LOCAL->[$_]->{0} eq "KH25L12839FZNW_08G") || ($MCP_LIST_LOCAL->[$_]->{0} eq "KH25L6439EMBI_10G"))
        {
            $command_compile_option .= "#define __SF_MXIC_KH_FLASH__\n";
        }

        if (($MCP_LIST_LOCAL->[$_]->{1} eq "KH25L12839FZNW_08G") || ($MCP_LIST_LOCAL->[$_]->{1} eq "KH25L6439EMBI_10G"))
        {
            $command_compile_option .= "#define __SF_MXIC_KH_FLASH__\n";
        }

        if (($MCP_LIST_LOCAL->[$_]->{0} eq "MX25L8006E") || ($MCP_LIST_LOCAL->[$_]->{1} eq "MX25L8006E"))
        {
            $command_compile_option .= "#define __SF_NO_SUS_RES_FLASH__\n";
        }
        
        if (($MCP_LIST_LOCAL->[$_]->{0} eq "MD25D80") || ($MCP_LIST_LOCAL->[$_]->{1} eq "MD25D80"))
        {
            $command_compile_option .= "#define __SF_NO_SUS_RES_FLASH__\n";
        }
    }

    ###
    my $dual_sf_flash_size;
    if($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE')
    {
        my $dual_flash_limit = sprintf("0x%08X", ($COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} + $COMM_MDL_INFO_LOCAL->{1}->{'Flash Size'}));;
        $dual_sf_flash_size = "#define DUAL_NOR_FLASH_SIZE           ";
        $dual_sf_flash_size .= $dual_flash_limit;
    }
    ###
    my $template = <<"__TEMPLATE";

/*
 *******************************************************************************
 PART 1:
   FLASH CONFIG Options Definition here
 *******************************************************************************
*/
$command_compile_option

$current_nor_opt

/*
 *******************************************************************************
 PART 2:
   FLASH FDM FEATURE CONFIG PARAMETERS translated from Manual custom_Memorydevice.h
 *******************************************************************************
*/

#define BUFFER_PROGRAM_ITERATION_LENGTH  ($pbp_size)

/*
 *******************************************************************************
 PART 3:
   FLASH GEOMETRY translated from MEMORY DEVICE DATABASE
 *******************************************************************************
*/

/* NOR flash maximum block size (Byte) in file system region */
#define NOR_BLOCK_SIZE  $nor_max_block_size_str
#define NOR_DISK0_BLOCK_SIZE $nor_disk0_block_size_str

/* NAND flash total size (MB). PLEASE configure it as 0 if it is unknown. */
#define NAND_TOTAL_SIZE $nand_total_size

/* NAND flash block size (KB). PLEASE configure it as 0 if it is unknown. */
#define NAND_BLOCK_SIZE $nand_block_size

/*
 *******************************************************************************
 PART 4:
   FLASH FAT CONFIG translated from Manual custom_Memorydevice.h
 *******************************************************************************
*/

    $dual_sf_flash_size

    #define NOR_FLASH_BASE_ADDRESS_DEFAULT     ($base_addr_string)
    #define NOR_ALLOCATED_FAT_SPACE_DEFAULT    ($fat_space_string)
    #define FOTA_DM_FS_OFFSET $nfb_fat_size_offset
    #define FOTA_DM_FS_SECTOR_OFFSET $nfb_partition_sector_offset

/*
 *******************************************************************************
 PART 6:
   FOTA UPDATABLE FLASH AREA
 *******************************************************************************
*/

$fota_check

#define CONFIG_FOTA_NOR_REGION_DEF \\
$fota_nor_region_def

#define CONFIG_FOTA_NOR_BLOCK_DEF \\
$fota_nor_block_def

#define CONFIG_FOTA_NOR_BANK_DEF \\
$fota_nor_bank_def

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  combo_flash_config_h_file_body
# return:
#****************************************************************************
sub combo_flash_config_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL,$CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MCP_LIST_DUAL_SF_LOCAL) = @_;

    if ($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE')
    {
        ### There should be totally 8 BlockInfo and BankInfo
        my $MAX_BLOCK_INFO = 8;
        my $MAX_BANK_INFO = 8;
        # print "combo flash config : $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL->{'SDS_MAX_SIZE'}\n";
        ### Fill-in the information of each memory
        my $combo_mem_info_struct;

        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            my $mcp_idx = $_;
            my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";
            my $cmem_fdm_type_CS0 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? 'CMEM_NOR_CS_'.$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Comm. Series'} : 'CMEM_FDM_NOR_DEFAULT';
            my $cmem_fdm_type_CS1 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? 'CMEM_NOR_CS_'.$MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Comm. Series'} : 'CMEM_FDM_NOR_DEFAULT';
            my $pbp_size_CS0 = 0;
            my $pbp_size_CS1 = 0;
            my $flash_limit_cs0 = sprintf("0x%08X", ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Size (Mb)'}*1024*1024/8));
            my $flash_limit_cs1 = sprintf("0x%08X", ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Size (Mb)'}*1024*1024/8));

            if ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'PBP'}->{'Y / N'} =~ /Y/i)
            {
                $pbp_size_CS0 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'PBP'}->{'Size(W)'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'PBP'}->{'Size (Byte)'}/2);
            }
            my $cur_block_str = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});

            if ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'PBP'}->{'Y / N'} =~ /Y/i)
            {
                $pbp_size_CS1 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'PBP'}->{'Size(W)'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'PBP'}->{'Size (Byte)'}/2);
            }
            my $cur_block_str_CS0 ;
            my $cur_block_str_CS1 ;

            $cur_block_str_CS0 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
            $cur_block_str_CS1 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});

            my $cur_block_str_fdm5_cs0;
            my $cur_block_str_fdm5_cs1;
            my @cur_block_fdm5_cs0;
            my @cur_block_fdm5_cs1;
            my $cur_block_fdm5_tmp_cs0;
            my $cur_block_fdm5_tmp_cs1;

            if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
            {
                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $cur_block_str_fdm5_cs0 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    $cur_block_str_fdm5_cs1 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
                    @cur_block_fdm5_cs0 = &split_info($cur_block_str_fdm5_cs0);
                    @cur_block_fdm5_cs1 = &split_info($cur_block_str_fdm5_cs1);
                    my $idx = 1;
                    if ($cur_block_fdm5_cs0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $cur_block_fdm5_tmp_cs0 = $2;
                    }

                    if (hex($cur_block_fdm5_tmp_cs0) < 65536)
                    {
                        $cur_block_str_CS0 = "\{0x0, 0x1000\}";

                    }
                    else
                    {
                        $cur_block_str_CS0 = "\{0x0, 0x10000\}";
                        $cur_block_str_CS1 = "\{0x0, 0x10000\}";
                        goto Label10;
                    }

                    ###CS1
                    if ($cur_block_fdm5_cs1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $cur_block_fdm5_tmp_cs1[idx] = $2;
                    }


                    if (hex($cur_block_fdm5_tmp_cs1) < 65536)
                    {

                        if (hex($cur_block_fdm5_tmp_cs0) > 65536)
                        {
                            $cur_block_str_CS1 = "\{0x0, 0x10000\}";
                            $cur_block_str_CS0 = "\{0x0, 0x10000\}";
                            goto Label10;
                        }
                        else
                        {
                            $cur_block_str_CS1 = "\{0x0, 0x1000\}";
                        }

                    }
                    else
                    {
                        $cur_block_str_CS1 = "\{0x0, 0x10000\}";
                        $cur_block_str_CS0 = "\{0x0, 0x10000\}";
                        goto Label10;
                    }

                }
            }
            Label10:
            ;#print "test Label10 $cur_block_str_CS0, $cur_block_str_CS1\n";
            #  print "combo flash before:$cur_block_str_CS0, $cur_block_str_CS1\n";
            if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
            {
                my @sds_block_size_all_CS0, @cur_blocks_sds_CS0, @tmp_block_str_all_CS0,@sds_block_size_all_CS1, @cur_blocks_sds_CS1, @tmp_block_str_all_CS1 ;
                my $sds_block_size_CS0, $sds_block_start_CS0, @tmp_sds_block_size_CS0,$sds_block_size_CS1, $sds_block_start_CS1, @tmp_sds_block_size_CS1;
                # print "combo cur block str before : $cur_block_str\n";
                my @tmp_block_str_all_CS0,@tmp_block_str_all_CS1;
                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $tmp_block_str_CS0_all[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    $tmp_block_str_CS1_all[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds_CS0 = &split_info($tmp_block_str_CS0_all[$_]);
                    @cur_blocks_sds_CS1 = &split_info($tmp_block_str_CS1_all[$_]);
                    if ($cur_blocks_sds_CS0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_CS0[$_] = $2;
                    }
                    # print "fourth temp block size : $tmp_sds_block_size_CS0[$_], block str : $tmp_block_str_CS0_all[$_]\n";

                    if ($cur_blocks_sds_CS1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_CS1[$_] = $2;
                    }
                    #  print "fourth temp block size : $tmp_sds_block_size_CS1[$_], block str : $tmp_block_str_CS1_all[$_]\n";
                }
                my $tmp_sds_start_CS0, $tmp_sds_last_block_start_CS0, $tmp_sds_start_CS1, $tmp_sds_last_block_start_CS1;
                my $sds_total_size_CS0, $sds_total_size_CS1;
                ###judge sds block size
                my @cur_uni_block_str_CS0, @cur_uni_block_str_CS1;
                my @cur_uni_block_CS0, @cur_uni_block_CS1;
                my $tmp_max_block_size_CS0 = 0;
                my $tmp_max_block_size_CS1 = 0;
                my @tmp_block_str_CS0, @tmp_block_size_CS0, @tmp_block_str_CS1, @tmp_block_size_CS1;
                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    ###calculate CS0
                    $cur_uni_block_str_CS0[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_CS0[$_] = &split_info_for_UB_SDS($cur_uni_block_str_CS0[$_]);
                    $cur_uni_block_str_CS1[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_CS1[$_] = &split_info_for_UB_SDS($cur_uni_block_str_CS1[$_]);

                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {
                        if (($cur_uni_block_CS0[$_] ne '4') || ($cur_uni_block_CS1[$_] ne '4'))
                        {
                            $cur_block_str_CS0 = "\{0x0, 0x10000\}";
                            $cur_block_str_CS1 = "\{0x0, 0x10000\}";

                            goto Finally;
                        }
                        else
                        {
                            $cur_block_str_CS0 = "\{0x0, 0x1000\}";

                        }

                        if (($cur_uni_block_CS0[$_] ne '4') || ($cur_uni_block_CS1[$_] ne '4'))
                        {
                            $cur_block_str_CS0 = "\{0x0, 0x10000\}";
                            $cur_block_str_CS1 = "\{0x0, 0x10000\}";

                            goto Finally;
                        }
                        else
                        {
                            $cur_block_str_CS1 = "\{0x0, 0x1000\}";

                        }
                    }
                    else
                    {
                        if ($cur_uni_block_CS0[$_] ne '4')
                        {
                            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                            {
                                if(hex($tmp_max_block_size_CS0) < hex($tmp_max_block_size_CS0[$_]))
                                {
                                   $tmp_max_block_size_CS0 = $tmp_max_block_size_CS0[$_];
                                }
                            }
                            $sds_block_size_CS0 = $tmp_max_block_size_CS0;
                            #  print "combo block info fisrt :$sds_block_size_CS0\n";
                            goto Finally;
                        }
                        else
                        {
                            $sds_block_size_CS0 = sprintf("0x%X", $cur_uni_block_CS0[$_]*1024);
                            #print "sds block: $sds_block_size_CS0\n"
                        }
                        ###calculate CS1

                        if ($cur_uni_block_CS1[$_] ne '4')
                        {
                            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                            {
                                if(hex($tmp_max_block_size_CS1) < hex($tmp_max_block_size_CS1[$_]))
                                {
                                    $tmp_max_block_size_CS1 = $tmp_max_block_size_CS1[$_];
                                }
                            }
                            $sds_block_size_CS1 = $tmp_max_block_size_CS1;
                            #  print "combo block info fisrt :$sds_block_size_CS0\n";
                            goto Finally;
                        }
                        else
                        {
                            $sds_block_size_CS1 = sprintf("0x%X", $cur_uni_block_CS1[$_]*1024);
                            #print "sds block: $sds_block_size_CS1\n";
                        }
                    }
                }
                ###

                if (!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                {
                    ###calculate CS0
                    $sds_block_start_CS0 = sprintf("0x%X", hex($flash_limit_cs0) - hex($tmp_sds_block_size_CS0[$_]));
                    $sds_total_size_CS0 = &memConfig::Get_SDS_total_size(hex($sds_block_size_CS0), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                    $tmp_sds_start_CS0 = sprintf("0x%X", hex($flash_limit_cs0) - $sds_total_size_CS0);
                    #  print "combo block info fisrt cs0:$sds_block_start_CS0, $tmp_sds_start_CS0, $sds_total_size_CS0, $flash_limit_cs0\n";
                    while (hex($sds_block_start_CS0) > hex($tmp_sds_start_CS0))
                    {
                        $sds_block_start_CS0 = sprintf("0x%X", hex($sds_block_start_CS0) - hex($tmp_sds_block_size_CS0[$_]));
                    }
                    # print "combo sds block info cs0:$sds_block_start_CS0,$tmp_sds_block_size_CS0[1],$tmp_sds_block_size_CS0[2]\n";
                    if (hex($sds_block_size_CS0) == hex($tmp_sds_block_size_CS0[1]))
                    {

                    }
                    elsif (hex($tmp_sds_block_size_CS0[$_]) == 0)
                    {
                        # print "test block size, $tmp_sds_block_size_CS0[1]\n";
                    }
                    else
                    {
                        $cur_block_str_CS0 .= "\{$sds_block_start_CS0, $sds_block_size_CS0\}";
                    }

                    ###calculate CS1
                    $sds_block_start_CS1 = sprintf("0x%X", hex($flash_limit_cs1) - hex($tmp_sds_block_size_CS1[$_]));
                    $sds_total_size_CS1 = &memConfig::Get_SDS_total_size(hex($sds_block_size_CS1), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                    $tmp_sds_start_CS1 = sprintf("0x%X", hex($flash_limit_cs1) - $sds_total_size_CS1);
                    # print "combo block info fisrt cs1:$sds_block_start_CS1, $tmp_sds_start_CS1,$tmp_sds_block_size_CS1[1],$tmp_sds_block_size_CS1[2],$flash_limit_cs1\n";
                    while (hex($sds_block_start_CS1) > hex($tmp_sds_start_CS1))
                    {
                        $sds_block_start_CS1 = sprintf("0x%X", hex($sds_block_start_CS1) - hex($tmp_sds_block_size_CS1[$_]));
                    }
                    #  print "combo sds block start cs1:$sds_block_start_CS1\n";
                    if (hex($sds_block_size_CS1) == hex($tmp_sds_block_size_CS0[$#tmp_sds_block_size_CS1]))
                    {

                    }
                    elsif (hex($tmp_sds_block_size_CS1[$_]) == 0)
                    {
                        # print "test block size cs1\n";
                    }
                    else
                    {
                        $cur_block_str_CS1 .= "\{$sds_block_start_CS1, $sds_block_size_CS1\}";
                    }
                }


                Finally:
                ;#print "test finally, $cur_block_str_CS0, $cur_block_str_CS1\n";
            }
            # print "combo cur block str : $cur_block_str_CS0, $cur_block_str_CS1\n";

            my @nvram_block_size_cs0,@nvram_block_size_cs1;
            if (($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
            {
                my @sds_block_size_all_cs0, @cur_blocks_sds_cs0, @tmp_block_str_all_cs0 ;
                my $sds_block_size_cs0, $sds_block_start_cs0, @tmp_sds_block_size_cs0;

                my @sds_block_size_all_cs1, @cur_blocks_sds_cs1, @tmp_block_str_all_cs1 ;
                my $sds_block_size_cs1, $sds_block_start_cs1, @tmp_sds_block_size_cs1;
                # print "combo cur block str before : $cur_block_str\n";
                my @tmp_block_str_all_cs0;
                my @tmp_block_str_all_cs1;
                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $tmp_block_str_all_cs0[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds_cs0 = &split_info($tmp_block_str_all_cs0[$_]);
                    if ($cur_blocks_sds_cs0[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_cs0[$_] = $2;
                        $nvram_block_size_cs0[$_] = $2;
                    }

                    $tmp_block_str_all_cs1[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds_cs1 = &split_info($tmp_block_str_all_cs1[$_]);
                    if ($cur_blocks_sds_cs1[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size_cs1[$_] = $2;
                        $nvram_block_size_cs1[$_] = $2;
                    }
                    # print "fourth temp block size : $tmp_sds_block_size_cs0[$_], $tmp_sds_block_size_cs1[$_],block str : $tmp_block_str_all_cs0[$_],$tmp_block_str_all_cs1[$_]\n";
                }
                my $tmp_sds_start_cs0, $tmp_sds_last_block_start_cs0;
                my $sds_total_size_cs0;
                ###judge sds block size
                my @cur_uni_block_str_cs0;
                my @cur_uni_block_cs0;
                my $tmp_max_block_size_cs0 = 0;
                my @tmp_block_str_cs0, @tmp_block_size_cs0;

                my $tmp_sds_start_cs1, $tmp_sds_last_block_start_cs1;
                my $sds_total_size_cs1;
                ###judge sds block size
                my @cur_uni_block_str_cs1;
                my @cur_uni_block_cs1;
                my $tmp_max_block_size_cs1 = 0;
                my @tmp_block_str_cs1, @tmp_block_size_cs1;

                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $cur_uni_block_str_cs0[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_cs0[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs0[$_]);

                    $cur_uni_block_str_cs1[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block_cs1[$_] = &split_info_for_UB_SDS($cur_uni_block_str_cs1[$_]);
                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {

                        if (($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            $cur_block_str_CS0 = "\{0x0, 0x10000\}";
                            $cur_block_str_CS1 = "\{0x0, 0x10000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                            goto Finally4;
                        }
                        else
                        {
                            $cur_block_str_CS0 = "\{0x0, 0x1000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                        }

                        if (($cur_uni_block_cs0[$_] ne '4') || ($cur_uni_block_cs1[$_] ne '4'))
                        {
                            $cur_block_str_CS0 = "\{0x0, 0x10000\}";
                            $cur_block_str_CS1 = "\{0x0, 0x10000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 64*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 64*1024);
                            goto Finally4;
                        }
                        else
                        {
                            $cur_block_str_CS1 = "\{0x0, 0x1000\}";
                            $sds_block_size_cs0 = sprintf("0x%X", 4*1024);
                            $sds_block_size_cs1 = sprintf("0x%X", 4*1024);
                        }
                    }
                    else
                    {
                        if ($cur_uni_block_cs0[$_] ne '4')
                        {
                            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                            {
                                if (hex($tmp_max_block_size_cs0) < hex($tmp_sds_block_size_cs0[$_]))
                                {
                                    $tmp_max_block_size_cs0 = $tmp_sds_block_size_cs0[$_];
                                }
                            }
                            $sds_block_size_cs0 = $tmp_max_block_size_cs0;
                            #  print "combo block info fisrt :$sds_block_size_cs0\n";
                            goto Finally4;
                        }
                        else
                        {
                            $sds_block_size_cs0 = sprintf("0x%X", $cur_uni_block_cs0[$_]*1024);
                            # print "test1\n";
                        }

                        if ($cur_uni_block_cs1[$_] ne '4')
                        {
                            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                            {
                                if (hex($tmp_max_block_size_cs1) < hex($tmp_sds_block_size_cs1[$_]))
                                {
                                    $tmp_max_block_size_cs1 = $tmp_sds_block_size_cs1[$_];
                                }
                            }
                            $sds_block_size_cs1 = $tmp_max_block_size_cs1;
                            #  print "combo block info second :$sds_block_size_cs1\n";

                            goto Finally4;
                        }
                        else
                        {
                            $sds_block_size_cs1 = sprintf("0x%X", $cur_uni_block_cs1[$_]*1024);
                            # print "test2\n";
                        }
                    }
                }

                Finally4:
                ;#print "test finally\n";
                # print "sds block : $sds_block_size_cs1,$sds_block_size_cs0, $nvram_block_size_cs0[1]\n";
            }
            #print "backup partition block :  $nvram_block_size_cs0[$_],$nvram_block_size_cs1[$_]\n";
            #print "combo flash after:$cur_block_str_CS1\n";
            my @cur_blocks_CS0 = &split_info($cur_block_str_CS0);  # list of Block Info.

            my @cur_blocks_CS1 = &split_info($cur_block_str_CS1);  # list of Block Info.
            my $cur_bank_str_CS0 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Bank Info.'});
            my $cur_bank_str_CS1 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Bank Info.'});

            my @cur_banks_CS0 = &split_info($cur_bank_str_CS0);  # list of Bank Info.
            my @cur_banks_CS1 = &split_info($cur_bank_str_CS1);  # list of Bank Info.
            my @cur_bank_size_CS0, @cur_bank_size_CS1;
            if (($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
            {
                if ($cur_banks_CS0[0] =~ /\{(\w+)\s*,\s*(\w+)\}/)
                {
                    $cur_bank_size_CS0[0] = $1;
                }

                if ($cur_banks_CS1[0] =~ /\{(\w+)\s*,\s*(\w+)\}/)
                {
                    $cur_bank_size_CS1[0] = $1;
                }
            }
            my $cur_uni_block_str_CS0 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'}) : "0";
            my $cur_uni_block_str_CS1 = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH') ? ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Geometry'}->{'Uniform Block (KB)'}) : "0";

            my $cur_uni_block_CS0 = &split_info_for_UB($cur_uni_block_str_CS0);
            my $cur_uni_block_CS1 = &split_info_for_UB($cur_uni_block_str_CS1);
            my ($block_info_template_CS0, $bank_info_template_CS0);
            my ($block_info_template_CS1, $bank_info_template_CS1);
            my $nvram_calculate_method_cs0,$nvram_calculate_method_cs1;
            $nvram_calculate_method_cs0 = "{(" . $cur_bank_size_CS0[0] . "- ((NVRAM_BACKUP_PARTITION_SIZE + NOR_BLOCK_SIZE - 1) & ~(NOR_BLOCK_SIZE - 1))), NOR_DISK0_BLOCK_SIZE}";
            $nvram_calculate_method_cs1 = "{(" . $cur_bank_size_CS1[0] . "- ((NVRAM_BACKUP_PARTITION_SIZE + NOR_BLOCK_SIZE - 1) & ~(NOR_BLOCK_SIZE - 1))), NOR_DISK0_BLOCK_SIZE}";
            for (0..($MAX_BLOCK_INFO-1))
            {
                $block_info_template_CS0 .= "            ";
                if (defined $cur_blocks_CS0[$_])
                {
                    $block_info_template_CS0 .= $cur_blocks_CS0[$_];
                }
                else
                {
                    #if (($_ == ( $#cur_blocks_CS0 + 1)) &&
                    #    ($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') &&
                    #    ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH') && (($nvram_block_size_cs0[$mcp_idx] ne '0x0') ))
                    #{
                    #   $block_info_template_CS0 .= $nvram_calculate_method_cs0;#"DISK0_REGION_INFO_LAYOUT";
                    #}
                    #else
                    #{
                    $block_info_template_CS0 .= "EndRegionInfo";
                    #}
                }
                if ($_ != ($MAX_BLOCK_INFO-1))
                {
                    $block_info_template_CS0 .= ",\n";
                }
            }
            ###calculate CS1
            for (0..($MAX_BLOCK_INFO-1))
            {
                $block_info_template_CS1 .= "            ";
                if (defined $cur_blocks_CS1[$_])
                {
                    $block_info_template_CS1 .= $cur_blocks_CS1[$_];
                }
                else
                {
                    #if (($_ == ( $#cur_blocks_CS1 + 1)) &&
                    #    ($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') &&
                    #    ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH') && (($nvram_block_size_cs1[$mcp_idx] ne '0x0') ))
                    #{
                    #   $block_info_template_CS1 .= $nvram_calculate_method_cs1;#"DISK0_REGION_INFO_LAYOUT";
                        #print "backup : $nvram_block_size_cs1[$_]\n";
                    #}
                    #else
                    #{
                    $block_info_template_CS1 .= "EndRegionInfo";
                    #}
                }
                if ($_ != ($MAX_BLOCK_INFO-1))
                {
                    $block_info_template_CS1 .= ",\n";
                }
            }
            ###calculate CS0
            for (0..($MAX_BANK_INFO-1))
            {
                $bank_info_template_CS0 .= "            ";
                if (defined $cur_banks_CS0[$_])
                {
                    $bank_info_template_CS0 .= $cur_banks_CS0[$_];
                }
                else
                {
                    $bank_info_template_CS0 .= "EndBankInfo";
                }
                if ($_ != ($MAX_BANK_INFO-1))
                {
                    $bank_info_template_CS0 .= ",\n";
                }
            }

            ###calculate CS1
            for (0..($MAX_BANK_INFO-1))
            {
                $bank_info_template_CS1 .= "            ";
                if (defined $cur_banks_CS1[$_])
                {
                    $bank_info_template_CS1 .= $cur_banks_CS1[$_];
                }
                else
                {
                    $bank_info_template_CS1 .= "EndBankInfo";
                }
                if ($_ != ($MAX_BANK_INFO-1))
                {
                    $bank_info_template_CS1 .= ",\n";
                }
            }

            $combo_mem_info_struct .= <<"__TEMPLATE";
    {   //$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}part
        $cmem_fdm_type_CS0,
        $pbp_size_CS0,      // Page Buffer Program Size
        $cur_uni_block_CS0, // Unifom Blocks
        {   // BlockInfo Start
$block_info_template_CS0
        },  // BlockInfo End
        {   // BankInfo Start
$bank_info_template_CS0
        }  // BankInfo End
    },
    {   //$MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Part Number'}part
        $cmem_fdm_type_CS1,
        $pbp_size_CS1,      // Page Buffer Program Size
        $cur_uni_block_CS1, // Unifom Blocks
        {   // BlockInfo Start
$block_info_template_CS1
        },  // BlockInfo End
        {   // BankInfo Start
$bank_info_template_CS1
        }  // BankInfo End
    },
__TEMPLATE
        }

        ###filter duplicate part number info

        if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
        {
            for (0..$#$MCP_LIST_DUAL_SF_LOCAL)
            {
                my $duplicate_count = 0;
                while ($combo_mem_info_struct =~ /\{\s+\/\/$MCP_LIST_DUAL_SF_LOCAL->[$_]part\s+(\w*\W*){37}\w*\s+\}\W/gis)
                {
                    $duplicate_count = $duplicate_count + 1;
                    if ($duplicate_count > 1)
                    {
                        $combo_mem_info_struct = $` . $' . "deleted"; #'
                        # print "success , $` ~~END~~,  , $duplicate_count\n";
                        $duplicate_count = 0;
                    }
                }
                # print "part number : $MCP_LIST_DUAL_SF_LOCAL->[$_]\n";
            }

            ###
            $combo_mem_info_struct = $combo_mem_info_struct . "deleted";
            if ($combo_mem_info_struct =~ /\W+deleted/gis)
            {
                $combo_mem_info_struct = $` . "\n\t\t}";
                # print "combo flash configure : $&, $combo_mem_info_struct\n";
                #    last;
            }
        }
        elsif (($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
        {
            $combo_mem_info_struct =~ s/^\s+//;
            $combo_mem_info_struct =~ s/\s+$//;
            # print "test combo flash config\n";
            for (0..$#$MCP_LIST_DUAL_SF_LOCAL)
            {
                my $duplicate_count = 0;
                while ($combo_mem_info_struct =~ /\{\s+\/\/$MCP_LIST_DUAL_SF_LOCAL->[$_]part\s+(\w*\W*){36}\w*\s+\}\W/gis)
                {
                    $duplicate_count = $duplicate_count + 1;
                    if ($duplicate_count > 1)
                    {
                        $combo_mem_info_struct = $` . $';#'
                        # print "success , $& ~~END~~,  , $duplicate_count\n";
                        $duplicate_count = 0;
                    }
                }
                # print "part number : $MCP_LIST_DUAL_SF_LOCAL->[$_]\n";
            }

            ###
            $combo_mem_info_struct = $combo_mem_info_struct . "deleted";
            if ($combo_mem_info_struct =~ /\W+deleted/gis)
            {
                $combo_mem_info_struct = $` . "\n\t\t}";
                # print "combo flash configure : $&, $combo_mem_info_struct\n";
                #    last;
            }
        }
        else
        {
            $combo_mem_info_struct =~ s/^\s+//;
            $combo_mem_info_struct =~ s/\s+$//;
            for (0..$#$MCP_LIST_DUAL_SF_LOCAL)
            {
                my $duplicate_count = 0;
                while ($combo_mem_info_struct =~ /\{\s+\/\/$MCP_LIST_DUAL_SF_LOCAL->[$_]part\s+(\w*\W*){36}\w*\s+\}\W/gis)
                {
                    $duplicate_count = $duplicate_count + 1;
                    if (($duplicate_count > 1))
                    {
                        $combo_mem_info_struct = $` . $';#'
                        # print "success test, $& ~~END~~,  , $duplicate_count\n";
                        $duplicate_count = 0;
                    }
                }
                # print "part number : $MCP_LIST_DUAL_SF_LOCAL->[$_]\n";
            }

            ###
            $combo_mem_info_struct = $combo_mem_info_struct . "deleted";
            if ($combo_mem_info_struct =~ /\W+deleted/gis)
            {
                $combo_mem_info_struct = $` . "\n\t\t}";
                # print "combo flash configure : $&, $combo_mem_info_struct\n";
                #    last;
            }
        }

        ###
        my $template = <<"__TEMPLATE";
#ifdef __NVRAM_BACKUP_PARTITION__
#define CMEM_MAX_BLOCKS     $cmem_max_blocks
#else
#define CMEM_MAX_BLOCKS     $cmem_max_blocks
#endif
#define CMEM_MAX_SECTORS    $cmem_max_sectors

COMBO_MEM_TYPE_MODIFIER COMBO_MEM_TYPE_NAME COMBO_MEM_INST_NAME = {
    COMBO_MEM_STRUCT_HEAD
$combo_mem_info_struct
    COMBO_MEM_STRUCT_FOOT
};
__TEMPLATE

    }### if ($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE')
    else
    {
        ### There should be totally 8 BlockInfo and BankInfo
        my $MAX_BLOCK_INFO = 8;
        my $MAX_BANK_INFO = 8;

        ### Fill-in the information of each memory
        my $combo_mem_info_struct;
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";
            my $cmem_fdm_type = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? 'CMEM_NOR_CS_'.$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Comm. Series'} : 'CMEM_FDM_NOR_DEFAULT';
            my $pbp_size = 0;
            if ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'PBP'}->{'Y / N'} =~ /Y/i)
            {
                $pbp_size = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'PBP'}->{'Size(W)'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'PBP'}->{'Size (Byte)'}/2);
            }
            my $cur_block_str = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
            my $cur_block_str_fdm5;
            my @cur_block_fdm5;
            my $cur_block_fdm5_tmp;
            if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
            {

                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $cur_block_str_fdm5[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_block_fdm5 = &split_info($cur_block_str_fdm5[$_]);
                    if ($cur_block_fdm5[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $cur_block_fdm5_tmp = $2;
                    }
                    if (hex($cur_block_fdm5_tmp) < 65536)
                    {
                        $cur_block_str = "\{0x0, 0x1000\}";
                        #print "test norfdm5\n";

                    }
                    else
                    {
                        $cur_block_str = "\{0x0, 0x10000\}";
                        goto Label1;
                    }
                }
            }
            Label1:
            ;#print "test Label1 $cur_block_str\n";

            if (($MAKEFILE_OPTIONS_LOCAL->{'sds_support'} eq 'TRUE') &&($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
            {
                my @sds_block_size_all, @cur_blocks_sds, @tmp_block_str_all ;
                my $sds_block_size, $sds_block_start, @tmp_sds_block_size;
                # print "combo cur block str before : $cur_block_str\n";
                my @tmp_block_str_all;
                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $tmp_block_str_all[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds = &split_info($tmp_block_str_all[$_]);
                    if ($cur_blocks_sds[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size[$_] = $2;
                    }
                    # print "fourth temp block size : $tmp_sds_block_size[$_], block str : $tmp_block_str_all[$_]\n";
                }
                my $tmp_sds_start, $tmp_sds_last_block_start;
                my $sds_total_size;
                ###judge sds block size
                my @cur_uni_block_str;
                my @cur_uni_block;
                my $tmp_max_block_size = 0;
                my @tmp_block_str, @tmp_block_size;
                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $cur_uni_block_str[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block[$_] = &split_info_for_UB_SDS($cur_uni_block_str[$_]);
                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {
                        if ($cur_uni_block[$_] ne '4')
                        {
                            $cur_block_str = "\{0x0, 0x10000\}";
                            goto Finally;
                        }
                        else
                        {
                            #$sds_block_size = sprintf("0x%X", $cur_uni_block[$_]*1024);
                            $cur_block_str = "\{0x0, 0x1000\}";
                            #goto Finally;
                        }
                    }
                    else
                    {
                        if($cur_uni_block[$_] ne '4')
                        {
                            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                            {
                                if(hex($tmp_max_block_size) < hex($tmp_sds_block_size[$_]))
                                {
                                    $tmp_max_block_size = $tmp_sds_block_size[$_];
                                }
                            }
                            $sds_block_size = $tmp_max_block_size;
                            # print "combo block info fisrt :$sds_block_size\n";
                            goto Finally;
                        }
                        else
                        {
                            $sds_block_size = sprintf("0x%X", $cur_uni_block[$_]*1024);
                        }
                    }

                }
                ###

                #  print "combo block info fisrt :$sds_block_size\n";
                if (!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                {
                    $sds_block_start = sprintf("0x%X", $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} - hex($tmp_sds_block_size[$_]));
                    $sds_total_size = &memConfig::Get_SDS_total_size(hex($sds_block_size), $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MAKEFILE_OPTIONS_LOCAL);
                    $tmp_sds_start = sprintf("0x%X", $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} - $sds_total_size);
                    #$sds_block_start = sprintf("0x%X", $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} - hex($tmp_sds_block_size));
                    while(hex($sds_block_start) > hex($tmp_sds_start))
                    {
                        $sds_block_start = sprintf("0x%X", hex($sds_block_start) - hex($tmp_sds_block_size[$_]));
                    }
                    # print "combo sds block start:$sds_block_start\n";
                    $cur_block_str .= "\{$sds_block_start, $sds_block_size\}";
                }
                Finally:
                print "test finally $cur_block_str\n";
            }
            # print "combo cur block str : $cur_block_str\n";

            if (($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
            {
                my @sds_block_size_all, @cur_blocks_sds, @tmp_block_str_all ;
                my $sds_block_size, $sds_block_start, @tmp_sds_block_size;
                # print "combo cur block str before : $cur_block_str\n";
                my @tmp_block_str_all;
                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $tmp_block_str_all[$_] = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Block Info.'});
                    @cur_blocks_sds = &split_info($tmp_block_str_all[$_]);
                    if ($cur_blocks_sds[0] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0x0,0x10000}
                    {
                        last if (hex($1) >= $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});  # end block infor traversal when the flash end among all memories has been reached
                        $tmp_sds_block_size[$_] = $2;
                    }
                    # print "fourth temp block size : $tmp_sds_block_size[$_], block str : $tmp_block_str_all[$_]\n";
                }
                my $tmp_sds_start, $tmp_sds_last_block_start;
                my $sds_total_size;
                ###judge sds block size
                my @cur_uni_block_str;
                my @cur_uni_block;
                my $tmp_max_block_size = 0;
                my @tmp_block_str, @tmp_block_size;
                for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                {
                    $cur_uni_block_str[$_] = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'};
                    $cur_uni_block[$_] = &split_info_for_UB_SDS($cur_uni_block_str[$_]);
                    if (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{__NOR_FDM5__})
                    {
                        if ($cur_uni_block[$_] ne '4')
                        {
                            $cur_block_str = "\{0x0, 0x10000\}";
                            $sds_block_size = sprintf("0x%X", 64*1024);
                            goto Finally10;
                        }
                        else
                        {
                             $cur_block_str = "\{0x0, 0x1000\}";
                            $sds_block_size = sprintf("0x%X", 4*1024);
                            #goto Finally10;
                        }
                    }
                    else
                    {
                        if ($cur_uni_block[$_] ne '4')
                        {
                            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
                            {
                                if(hex($tmp_max_block_size) < hex($tmp_sds_block_size[$_]))
                                {
                                    $tmp_max_block_size = $tmp_sds_block_size[$_];
                                }
                            }
                            $sds_block_size = $tmp_max_block_size;
                            # print "combo block info fisrt :$sds_block_size\n";
                            goto Finally10;
                        }
                        else
                        {
                            $sds_block_size = sprintf("0x%X", $cur_uni_block[$_]*1024);
                        }
                    }
                }
            }
            Finally10:
            print "test finally10 $cur_block_str\n";
            my @cur_blocks = &split_info($cur_block_str);  # list of Block Info.
            my $cur_bank_str = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NOR Flash Geometry'}->{'Bank Info.'}) : ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Bank Info.'});
            my @cur_banks = &split_info($cur_bank_str);  # list of Bank Info.
            my $cur_uni_block_str = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH') ? ($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Geometry'}->{'Uniform Block (KB)'}) : "0";
            my $cur_uni_block = &split_info_for_UB($cur_uni_block_str);
            my ($block_info_template, $bank_info_template);

            for (0..($MAX_BLOCK_INFO-1))
            {
                $block_info_template .= "            ";
                if (defined $cur_blocks[$_])
                {
                    $block_info_template .= $cur_blocks[$_];
                }
                else
                {
                    if (($_ == ( $#cur_blocks + 1)) &&
                        ($MAKEFILE_OPTIONS_LOCAL->{'nvram_backup_partition_on_nor'} eq 'ENABLE') &&
                        ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
                    {
                        $block_info_template .= "DISK0_REGION_INFO_LAYOUT";
                    }
                    else
                    {
                        $block_info_template .= "EndRegionInfo";
                    }
                }
                if ($_ != ($MAX_BLOCK_INFO-1))
                {
                    $block_info_template .= ",\n";
                }
            }

            for (0..($MAX_BANK_INFO-1))
            {
                $bank_info_template .= "            ";
                if (defined $cur_banks[$_])
                {
                    $bank_info_template .= $cur_banks[$_];
                }
                else
                {
                    $bank_info_template .= "EndBankInfo";
                }
                if ($_ != ($MAX_BANK_INFO-1))
                {
                    $bank_info_template .= ",\n";
                }
            }

            $combo_mem_info_struct .= <<"__TEMPLATE";
    {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
        $cmem_fdm_type,
        $pbp_size,      // Page Buffer Program Size
        $cur_uni_block, // Unifom Blocks
        {   // BlockInfo Start
$block_info_template
        },  // BlockInfo End
        {   // BankInfo Start
$bank_info_template
        }  // BankInfo End
    }$comma
__TEMPLATE
        }

        ###
        my $template = <<"__TEMPLATE";
#ifdef __NVRAM_BACKUP_PARTITION__
#define CMEM_MAX_BLOCKS       (NOR_ALLOCATED_FAT_SPACE/NOR_BLOCK_SIZE)+(((NVRAM_BACKUP_PARTITION_SIZE + NOR_BLOCK_SIZE - 1) & ~(NOR_BLOCK_SIZE - 1))/NOR_DISK0_BLOCK_SIZE)
#else
#define CMEM_MAX_BLOCKS       $cmem_max_blocks
#endif
#define CMEM_MAX_SECTORS      $cmem_max_sectors

COMBO_MEM_TYPE_MODIFIER COMBO_MEM_TYPE_NAME COMBO_MEM_INST_NAME = {
    COMBO_MEM_STRUCT_HEAD
$combo_mem_info_struct
    COMBO_MEM_STRUCT_FOOT
};
__TEMPLATE
    }

}

#****************************************************************************
# subroutine:  combo_flash_id_h_file_body
# return:
#****************************************************************************
sub combo_flash_id_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $MCP_LIST_DUAL_SF_LOCAL) = @_;
    if ($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE')
    {
        ### There should be totally 8 Flash ID entries
        my $MAX_FLASH_ID = 8;

        ### Fill-in the information of each memory
        my $combo_mem_info_struct;
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";
            my $cmem_type;
            if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
            {
                $cmem_type = "CMEM_TYPE_SERIAL_NOR_FLASH";
            }

            my $flash_id_str_CS0 = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Flash ID'};
            my $flash_id_str_CS1 = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Flash ID'};
            $flash_id_str_CS0 =~ s/\{//;  # remove parentheses
            $flash_id_str_CS0 =~ s/\}//;  # remove parentheses
            $flash_id_str_CS0 =~ s/\s+//g;  # remove spaces

            $flash_id_str_CS1 =~ s/\{//;  # remove parentheses
            $flash_id_str_CS1 =~ s/\}//;  # remove parentheses
            $flash_id_str_CS1 =~ s/\s+//g;  # remove spaces

            ### parse the flash id string
            my $saved_sep = $/;
            undef $/;
            my @flash_id_CS0 = split(/\,/, $flash_id_str_CS0);
            my @flash_id_CS1 = split(/\,/, $flash_id_str_CS1);
            $/ = $saved_sep;
            my $flash_id_cnt_CS0 = $#flash_id_CS0 + 1;
            my $flash_id_cnt_CS1 = $#flash_id_CS1 + 1;

            my $flash_id_template_CS0 = "";
            my $flash_id_template_CS1 = "";
            #print "flash id str before:$flash_id_template_CS1\n";
            ###calculate CS0
            for (0..($MAX_FLASH_ID-1))
            {
                if (defined $flash_id_CS0[$_])
                {
                    $flash_id_template_CS0 .= $flash_id_CS0[$_];
                }
                else
                {
                    $flash_id_template_CS0 .= "0x00";
                }
                if ($_ != ($MAX_FLASH_ID-1))
                {
                    $flash_id_template_CS0 .= ", ";
                }
            }

            ###calculate CS1
            for (0..($MAX_FLASH_ID-1))
            {
                if (defined $flash_id_CS1[$_])
                {
                    $flash_id_template_CS1 .= $flash_id_CS1[$_];
                   # print "flash id : $flash_id_CS1[$_]\n";
                }
                else
                {
                    $flash_id_template_CS1 .= "0x00";
                }
                if ($_ != ($MAX_FLASH_ID-1))
                {
                    $flash_id_template_CS1 .= ", ";
                }
            }
            #print "flash id str after:$flash_id_template_CS1\n";
            $combo_mem_info_struct .= <<"__TEMPLATE";
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}part
            $cmem_type,
            $flash_id_cnt_CS0,  // Valid ID length
            {$flash_id_template_CS0}  // Flash ID
        },
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Part Number'}part
            $cmem_type,
            $flash_id_cnt_CS1,  // Valid ID length
            {$flash_id_template_CS1}  // Flash ID
        }$comma
__TEMPLATE
        }

        ###filter duplicate part number

        for(0..$#$MCP_LIST_DUAL_SF_LOCAL)
        {
            my $duplicate_count = 0;
            #print "test combo flash id 1\n";
            while ($combo_mem_info_struct =~ /\{\s+\/\/$MCP_LIST_DUAL_SF_LOCAL->[$_]part\s+(\w*\W*){14}\w*\s+\}\W/gis)
            {
                #print "test combo flash id 2\n";
                $duplicate_count = $duplicate_count + 1;
                if ($duplicate_count > 1)
                {
                    $combo_mem_info_struct = $` . $' . "deleted";
                    # print "combo flash id : $&~~END~~,  , $duplicate_count\n";'
                    $duplicate_count = 0;
                }

            }

            #print' "test combo flash id 3\n";
            # print "part number : $MCP_LIST_DUAL_SF_LOCAL->[$_]\n";
        }
        $combo_mem_info_struct = $combo_mem_info_struct . "deleted";
        if ($combo_mem_info_struct =~ /\W+deleted/gis)
        {
            $combo_mem_info_struct = $` . "\n\t\t}";
            #  print "combo flash configure : $&, $combo_mem_info_struct\n";
            #    last;
        }
        ###
        #print "test combo flash id 4\n";
        my $template = <<"__TEMPLATE";
COMBO_MEM_TYPE_MODIFIER COMBO_MEM_TYPE_NAME COMBO_MEM_INST_NAME = {
    COMBO_MEM_STRUCT_HEAD
$combo_mem_info_struct
    COMBO_MEM_STRUCT_FOOT
};
__TEMPLATE
    } ### if ($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE')
    else
    {
        ### There should be totally 8 Flash ID entries
        my $MAX_FLASH_ID = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') ? 4 : 8;

        ### Fill-in the information of each memory
        my $combo_mem_info_struct;
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";
            my $cmem_type;
            if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
            {
                $cmem_type = "CMEM_TYPE_SERIAL_NOR_FLASH";
            }
            elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND')
            {
                $cmem_type = "CMEM_TYPE_NAND";
            }
            elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP')
            {
                $cmem_type = "CMEM_TYPE_NOR";
            }
            elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SPI_NAND')
            {
                $cmem_type = "CMEM_TYPE_SERIAL_NAND_FLASH";
            }
            my $flash_id_str = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Flash ID'};
            $flash_id_str =~ s/\{//;  # remove parentheses
            $flash_id_str =~ s/\}//;  # remove parentheses
            $flash_id_str =~ s/\s+//g;  # remove spaces
            ### parse the flash id string
            my $saved_sep = $/;
            undef $/;
            my @flash_id = split(/\,/, $flash_id_str);
            $/ = $saved_sep;
            my $flash_id_cnt = $#flash_id + 1;

            my $flash_id_template;
            for (0..($MAX_FLASH_ID-1))
            {
                if (defined $flash_id[$_])
                {
                    $flash_id_template .= $flash_id[$_];
                }
                else
                {
                    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP')
                    {
                        $flash_id_template .= "0x0000";
                    }
                    else
                    {
                        $flash_id_template .= "0x00";
                    }
                }

                if ($_ != ($MAX_FLASH_ID-1))
                {
                    $flash_id_template .= ", ";
                }
            }

            $combo_mem_info_struct .= <<"__TEMPLATE";
    {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
        $cmem_type,
        $flash_id_cnt,  // Valid ID length
        {$flash_id_template}  // Flash ID
    }$comma
__TEMPLATE
        } ### for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})

        ###
        my $template = <<"__TEMPLATE";
COMBO_MEM_TYPE_MODIFIER COMBO_MEM_TYPE_NAME COMBO_MEM_INST_NAME = {
    COMBO_MEM_STRUCT_HEAD
$combo_mem_info_struct
    COMBO_MEM_STRUCT_FOOT
};
__TEMPLATE
    }

}

#****************************************************************************
# subroutine:  custom_flash_c_file_body
# return:
#****************************************************************************
sub custom_flash_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $MCP_LIST_LOCAL, $NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, $NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL,$LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $nor_size_Mb_LOCAL, $entire_bank_info_size_list_LOCAL, $entire_bank_info_count_list_LOCAL, $entire_block_info_start_list_LOCAL, $entire_block_info_size_list_LOCAL, $fs_region_info_size_list_LOCAL, $fs_region_info_count_list_LOCAL, $entire_region_info_size_list_LOCAL, $entire_region_info_count_list_LOCAL, $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL) = @_;
    my $cs1_base_address = sprintf("0x%08X", &config_query_cs1_addr($MAKEFILE_OPTIONS_LOCAL->{'platform'}));
    my $flash_limit = sprintf("0x%08X", $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});
    my $flash_size = sprintf("0x%08X", $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});

    if ($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE')
    {
        $flash_size = sprintf("0x%08X", ($COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'} ));
        $flash_limit = sprintf("0x%08X", ($COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'}));
    }

    ###
    my $pbp_size = ($COMM_MDL_INFO_LOCAL->{0}->{'PBP'}->{'Y / N'} =~ /Y/i)
                 ? $COMM_MDL_INFO_LOCAL->{0}->{'PBP'}->{'Size(W)'}
                 : 0;

    ###
    my $bank_info_string = &bank_info($entire_bank_info_size_list_LOCAL, $entire_bank_info_count_list_LOCAL, $NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, $NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL);

    ###
    my $sub_content_block1 = &region_info($fs_region_info_size_list_LOCAL, $fs_region_info_count_list_LOCAL, 'REGION_INFO_LAYOUT');
    my $sub_content_block2 = &block_info($entire_block_info_start_list_LOCAL, $entire_block_info_size_list_LOCAL, $MAKEFILE_OPTIONS_LOCAL, $COMM_MDL_INFO_LOCAL, $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
    my $sub_content_block3;
    my $sub_content_block4;

    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPSDRAM') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPDDR') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPDDR2') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'DISCRETE_NAND'))
    {
        my $ori_bank_info = &bank_info($entire_bank_info_size_list_LOCAL, $entire_bank_info_count_list_LOCAL, 0, $COMM_MDL_INFO_LOCAL->{0}->{'Flash Size'});
        ### ? what is the purpose?
        $sub_content_block3 = &region_info($fs_region_info_size_list_LOCAL, $fs_region_info_count_list_LOCAL, 'oriRegionInfo');
        $sub_content_block4 .= <<"__TEMPLATE";

static NORBankInfo oriBankInfo[] =
{
$ori_bank_info
   EndBankInfo
};

__TEMPLATE
        chomp $sub_content_block4;
    }

    ###
    my $region_info_disk0 = &region_info($fs_region_info_size_list_LOCAL, $fs_region_info_count_list_LOCAL, 'DISK0_REGION_INFO_LAYOUT');
    my $region_info_disk1 = &region_info($fs_region_info_size_list_LOCAL, $fs_region_info_count_list_LOCAL, 'DISK1_REGION_INFO_LAYOUT');
    my $region_info_entire = &region_info($entire_region_info_size_list_LOCAL, $entire_region_info_count_list_LOCAL, 'ENTIRE_DISK_REGION_INFO_LAYOUT');

    ###
    my $template1;
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPSDRAM') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPDDR') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPDDR2') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'DISCRETE_NAND'))
    {
        $template1 .= <<"__TEMPLATE__";
/*******************************************************************************
   NOTICE: Fill the flash region information table, a region is the memory space
           that contains continuous sectors of equal size. Each region element
           in the table is the format as below:
           {S_sector, N_sector},
           S_sector: the size of sector in the region
           N_sector: the number of sectors in the region
 *******************************************************************************/
$sub_content_block1

#ifndef __NVRAM_BACKUP_PARTITION__
$region_info_disk0
$region_info_disk1
#endif

$region_info_entire

/*******************************************************************************
   NOTICE. Modify the value of TOTAL_BLOCKS, which is the sum of the number of
           sectors in all regions.
           Note : The Maximum value of TOTAL_BLOCKS is (127).
 *******************************************************************************/

#ifdef __NVRAM_BACKUP_PARTITION__
#define TOTAL_BLOCKS    (NOR_ALLOCATED_FAT_SPACE/NOR_BLOCK_SIZE)+(((NVRAM_BACKUP_PARTITION_SIZE + NOR_BLOCK_SIZE - 1) & ~(NOR_BLOCK_SIZE - 1))/NOR_DISK0_BLOCK_SIZE)
#else
#define TOTAL_BLOCKS    $cmem_max_blocks
#endif

/*******************************************************************************
   NOTICE. Modify the value of page buffer size in WORD for page buffer program
 *******************************************************************************/
//kal_uint32 PAGE_BUFFER_SIZE = $pbp_size;

#define BANK_INFO_LAYOUT $bank_info_string

/*******************************************************************************
   NOTICE. NOR FLASH BLOCKS SIZE LOOKUP TABLE
          Each entry element
          {Offset, Block_Size},
          Offset:     the offset address
          Block_Size: the size of block
 *******************************************************************************/
$sub_content_block2
__TEMPLATE__
    }

    ###
    my $flash_id_str;
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2')or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND'))
    {
        $flash_id_str .= <<"__TEMPLATE__";
const kal_char FLASH_ID[] = "$MDL_INFO_LIST_LOCAL->[1]->{0}->{'Flash ID'}";
__TEMPLATE__
    }
    else
    {
        if ((($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6922')) and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'NOR_RAM_MCP'))
        {
            $flash_id_str .= <<"__TEMPLATE__";
const kal_char FLASH_ID[] = "$MDL_INFO_LIST_LOCAL->[1]->{0}->{'Flash ID'}";
__TEMPLATE__
        }
        else
        {
            $flash_id_str .= <<"__TEMPLATE__";
const kal_char FLASH_ID[] = "$MDL_INFO_LIST_LOCAL->[1]->{0}->{'Flash ID'}";
__TEMPLATE__
        }
    }
    chomp $flash_id_str;

    ###
    my ($cs0_info, $cs1_info);
    my ($pn0_str, $pn1_str);
    # print "MCP part nubmer custom_flash:$MCP_LIST_LOCAL->[1]->{0}, $MCP_LIST_LOCAL->[0]->{0}\n";
    if ((!defined $MAKEFILE_OPTIONS_LOCAL->{'combo_memory_support'}) or ($MAKEFILE_OPTIONS_LOCAL->{'combo_memory_support'} eq 'FALSE'))
    {
        if (defined $MCP_LIST_LOCAL->[1]->{0})
        {
            $cs0_info .= <<"__TEMPLATE__";
 * CS0_PART_NUMBER: $MCP_LIST_LOCAL->[1]->{0}
__TEMPLATE__
            chomp $cs0_info;

            $pn0_str .= <<"__TEMPLATE__";
const kal_char PART_NUMBER_0[] = "$MCP_LIST_LOCAL->[1]->{0}";
__TEMPLATE__
            chomp $pn0_str;
        }
        if (defined $MCP_LIST_LOCAL->[1]->{1})
        {
            $cs1_info .= <<"__TEMPLATE__";
 * CS1_PART_NUMBER: $MCP_LIST_LOCAL->[1]->{1}
__TEMPLATE__
            chomp $cs1_info;

            $pn1_str .= <<"__TEMPLATE__";
const kal_char PART_NUMBER_1[] = "$MCP_LIST_LOCAL->[1]->{1}";
__TEMPLATE__
            chomp $pn1_str;
        }
    }

    ###
    my $flash_density;
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPSDRAM') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPDDR') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'LPDDR2') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} ne 'DISCRETE_NAND'))
    {
        $flash_density .= <<"__TEMPLATE__";
 * NOR_FLASH_DENSITY: $flash_limit
 * NOR_FLASH_SIZE(Mb): $nor_size_Mb_LOCAL
__TEMPLATE__
        chomp $flash_density;
    }

    ###
    my $template = <<"__TEMPLATE";


#ifdef REMAPPING
#define NOR_FLASH_BASE_ADDR $cs1_base_address
#define RAM_BASE_ADDR       0x00000000
#else
#define NOR_FLASH_BASE_ADDR 0x00000000
#define RAM_BASE_ADDR       $cs1_base_address
#endif

/*
 ****************************************************************************
 PART 2:
 Essential Information of NOR Flash Geometry Layout Information
 ****************************************************************************
*/
$template1

#define NOR_FLASH_SIZE  $flash_size

$flash_id_str

/****************************************************
 * This part is for auto-gen validity CHECK *
 * Don't modify any content in this comment section *
$cs0_info
$cs1_info
$flash_density

$sub_content_block3

$sub_content_block4
 ****************************************************/

__TEMPLATE
}

#****************************************************************************
# subroutine:  custom_flash_norfdm5_c_file_body
# return:
#****************************************************************************
sub custom_flash_norfdm5_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, $NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL, $entire_bank_info_size_list_LOCAL, $entire_bank_info_count_list_LOCAL) = @_;
    my $bank_info_string = &bank_info( $entire_bank_info_size_list_LOCAL, $entire_bank_info_count_list_LOCAL, $NOR_FLASH_BASE_ADDRESS_VAL_LOCAL, $NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL );

    ###
    my $nor_total_lsmt  = 1;
    my $count           = 0;
    my $sum             = 1;
    my $tmp_regions_sum = $NOR_ALLOCATED_FAT_SPACE_VAL_LOCAL;

    if ($MEM_DEV_LIST_INFO{0}->{'Comm. Series'} eq 'INTEL_SIBLEY')
    {
        if ($tmp_regions_sum > (64*1024*1024))
        {
            my $count = 0;
            my $sum  = 1;
            $tmp_regions_sum /= 1024;
            while ($sum < $tmp_regions_sum)
            {
                $sum *= 2;
                $count++;
            }
            $count -= 8;
            for (my $i=0; $i<$count; $i++)
            {
                $nor_total_lsmt *= 2;
            }
        }
        else
        {
            my $count = 0;
            my $sum  = 1;
            $tmp_regions_sum /= 1024;
            while ($sum < $tmp_regions_sum)
            {
                $sum *= 2;
                $count++;
            }
            if (($count/2) == 1)
            {
                $count += 1;
            }
            $count /= 2;
            for (my $i=0; $i<$count; $i++)
            {
                $nor_total_lsmt *= 2;
            }
        }
    }
    else
    {
        if ($tmp_regions_sum > (32*1024*1024))
        {
            my $count = 0;
            my $sum  = 1;
            $tmp_regions_sum /= 512;
            while ($sum < $tmp_regions_sum)
            {
                $sum *= 2;
                $count++;
            }
            $count -= 8;
            for (my $i=0; $i<$count; $i++)
            {
                $nor_total_lsmt *= 2;
            }
        }
        else
        {
            my $count = 0;
            my $sum  = 1;
            $tmp_regions_sum /= 512;
            while ($sum < $tmp_regions_sum)
            {
                $sum *= 2;
                $count++;
            }
            if (($count/2) == 1)
            {
                $count += 1;
            }
            $count /= 2;
            for (my $i=0; $i<$count; $i++)
            {
                $nor_total_lsmt *= 2;
            }
        }
    }

    ###
    my $template = <<"__TEMPLATE";

#ifdef __NOR_FDM5__

/*******************************************************************************
   Follow the 4 steps below to configure flash memory

   Step 1. Fill the flash bank (partition) information table,
           flash device features flexible, multi-bank read-while-program and
           read-while-erase capability, enabling background programming or erasing in
           one bank simultaneously with code execution or data reads in another bank.
           Each element in the table is the format as below:
           {bank size, bank number},

   Step 2. Modify the value of LSMT, you can see MemoryDevice_FlashDisk_FAQ for
           detail information

   Step 2. Define the toal sectors (512bytes) of system drive
           the remainder is the size of public drive
           If there is no partiton (just one drive, system drive)
           set this value to STORAGE_NO_PARTITION (0xFFFFFFFF)


   Note : Code region and FAT region can not share the same bank (partition)
*******************************************************************************/


/***********
 * Step 1. *
 ***********/
#define NOR_FDM5_BANK_INFO_LAYOUT $bank_info_string

/***********
 * Step 2. *
 ***********/
#define NOR_TOTAL_LSMT $nor_total_lsmt

/***********
 * Step 3. *
 ***********/
// Set NOR_SYSDRV_SECTORS to 0 will disable this setting and use PARTITION_SECTORS in custom_memorydevice.h to set user drive size.
#define NOR_SYSDRV_SECTORS 0

#endif //__NOR_FDM5__

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  split_info_for_UB
# return:      List of RegionInfo/BlockInfo/BankInfo
# input:       $info: Excel value to be split
#****************************************************************************
sub split_info_for_UB
{
    my ($text, $ub_info_href) = @_;
    #print "sub index : $ub_info_href->[0]\n";
    my @new = ();
    my $ref_str;
    my $i;
    push(@new, $+) while $text =~ m{
        "([^\"\\]*(?:\\.[^\"\\]*)*)", ?
        | ([^,]+), ?
        | ,
    }gx;
    push(@new, undef) if substr($text, -1,1) eq ',';

    $ref_str = "(";
    for ($i = 0; $i < @new; $i++){
        if($i == (@new -1))
        {
            $ref_str .= $new[$i];
        }
        else
        {
            $ref_str .= $new[$i] . "|";
        }
        $ub_info_href->[$i] = $new[$i];
        # print "sub : $ub_info_href->[$i]\n";
    }
    $ref_str .= ")";

    # print "$ref_str\n";
    return $ref_str;
}

sub split_info_for_UB_SDS
{
    my ($text) = @_;
    my @new = ();
    my $i;
    push(@new, $+) while $text =~ m{
        "([^\"\\]*(?:\\.[^\"\\]*)*)", ?
        | ([^,]+), ?
        | ,
    }gx;
    push(@new, undef) if substr($text, -1,1) eq ',';
    #print "0,1,2:$new[0],$new[1],$new[2]\n";
    return $new[0];
}

sub split_info_for_UB_FDM5
{
    my ($text) = @_;
    my @new = ();
    my $i;
    push(@new, $+) while $text =~ m{
        "([^\"\\]*(?:\\.[^\"\\]*)*)", ?
        | ([^,]+), ?
        | ,
    }gx;
    push(@new, undef) if substr($text, -1,1) eq ',';
    if($new[2] > $new[1])
    {
        print "test 2\n";
    }
    else
    {
        print "test 1;\n";
    }
    print "0,1,2:$new[0],$new[1],$new[2]";
    return $new[0];
}

