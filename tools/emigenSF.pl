#!/usr/bin/perl
#
my $DebugPrint    = 0; # 1 for debug; 0 for non-debug
require "tools/emigenMD.pl";
&PrintDependency($0);
&PrintDependency('tools\emigenMD.pl');
#****************************************************************************
# subroutine:  Lookup_SFI_setting_by_IDX_CLK_BB_REG
# input:       MEM_IDX, CLK , PLATFORM , REGISTER
# return:      SFI setting of the input MEM_IDX/MCU_CLOCK/PLATFORM/REGISTER
#****************************************************************************
sub Lookup_SFI_setting_by_IDX_CLK_BB_REG
{
    my ($idx, $clk, $bb, $reg, $MDL_INFO_LIST_LOCAL) = @_;
    my $clk_str = sprintf("%sMHz SFC Setting", $clk);

    if (($bb eq 'MT2501') || ($bb eq 'MT2502'))
    {
        $bb = 'MT6261';
    }

    if (($bb eq 'MT6252') || ($bb eq 'MT6255') || ($bb eq 'MT6250') || ($bb eq 'MT6260') || ($bb eq 'MT6261'))
    {
        return $MDL_INFO_LIST_LOCAL->[$idx]->{0}->{$bb}->{$clk_str}->{$reg};
    }
    else
    {
        return $MDL_INFO_LIST_LOCAL->[$idx]->{0}->{$clk_str}->{$reg};
    }
}

#****************************************************************************
# subroutine:  Lookup_SFI_setting_by_IDX_CLK_BB_REG
# input:       MEM_IDX, CLK , PLATFORM , REGISTER
# return:      SFI setting of the input MEM_IDX/MCU_CLOCK/PLATFORM/REGISTER
#****************************************************************************
sub Lookup_SNAND_setting_by_IDX_CLK_BB_REG
{
    my ($idx, $clk, $bb, $reg, $MDL_INFO_LIST_LOCAL) = @_;
    my $clk_str = sprintf("%sMHz SPI_NAND Setting", $clk);

    if ($bb eq 'MT6260')
    {
        return $MDL_INFO_LIST_LOCAL->[$idx]->{0}->{$bb}->{$clk_str}->{$reg};
    }
    else
    {
        return $MDL_INFO_LIST_LOCAL->[$idx]->{0}->{$clk_str}->{$reg};
    }
}

#****************************************************************************
# subroutine:  Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF
# input:       MEM_IDX, CLK , PLATFORM , REGISTER
# return:      SFI setting of the input MEM_IDX/MCU_CLOCK/PLATFORM/REGISTER
#****************************************************************************
sub Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF
{
    my ($idx, $clk, $bb, $reg, $MDL_INFO_LIST_LOCAL, $CS) = @_;
    my $clk_str = sprintf("%sMHz SFC Setting", $clk);

    if ($CS == 1)
    {
        return $MDL_INFO_LIST_LOCAL->[$idx]->{1}->{$bb}->{$clk_str}->{$reg};
    }
    else
    {
        return $MDL_INFO_LIST_LOCAL->[$idx]->{0}->{$bb}->{$clk_str}->{$reg};
    }
}

#****************************************************************************
# subroutine:  combo_sfi_config_h_file_body
# return:
#****************************************************************************
sub combo_sfi_config_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $sfi_clk_config_LOCAL, $MCP_LIST_DUAL_SF_LOCAL) = @_;
    ###
    my $MAX_SFI_COMMAND = 32;
    my $combo_mem_info_struct;
    if ($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE')
    {
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";

            my @device_setup_command_cs0 = &split_sfi_command($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Setup'}->{'Command'});
            my @device_setup_command_cs1 = &split_sfi_command($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Setup'}->{'Command'});
            #SFI 166Mhz setting command
            my $sf_mac_ctl_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            my ($sf_misc_ctl_1_166_cs0, $sf_dly_ctl_1_166_cs0, $sf_misc_ctl_2_166_cs0, $sf_dly_ctl_2_166_cs0);
            my ($sf_direct_ctl_1_166_cs0, $sf_misc_ctl_1_166_cs0, $sf_dly_ctl_2_166_cs0, $sf_dly_ctl_3_166_cs0, $sf_dly_ctl_4_166_cs0, $sf_dly_ctl_5_166_cs0);

            my $sf_mac_ctl_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            my ($sf_misc_ctl_1_166_cs1, $sf_dly_ctl_1_166_cs1, $sf_misc_ctl_2_166_cs1, $sf_dly_ctl_2_166_cs1);
            my ($sf_direct_ctl_1_166_cs1, $sf_misc_ctl_1_166_cs1, $sf_dly_ctl_2_166_cs1, $sf_dly_ctl_3_166_cs1, $sf_dly_ctl_4_166_cs1, $sf_dly_ctl_5_166_cs1);

            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_misc_ctl_1_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_misc_ctl_2_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_direct_ctl_1_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_dly_ctl_2_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_dly_ctl_3_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_dly_ctl_4_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_dly_ctl_5_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) : "0";

                $sf_misc_ctl_1_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_misc_ctl_2_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_direct_ctl_1_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_dly_ctl_2_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_dly_ctl_3_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_dly_ctl_4_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_dly_ctl_5_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) : "0";
            }

            #SFI 130Mhz setting command
            my $sf_mac_ctl_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            my ($sf_misc_ctl_1_130_cs0, $sf_dly_ctl_1_130_cs0, $sf_misc_ctl_2_130_cs0, $sf_dly_ctl_2_130_cs0);
            my ($sf_direct_ctl_1_130_cs0, $sf_misc_ctl_1_130_cs0, $sf_dly_ctl_2_130_cs0, $sf_dly_ctl_3_130_cs0, $sf_dly_ctl_4_130_cs0, $sf_dly_ctl_5_130_cs0);

            my $sf_mac_ctl_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            my ($sf_misc_ctl_1_130_cs1, $sf_dly_ctl_1_130_cs1, $sf_misc_ctl_2_130_cs1, $sf_dly_ctl_2_130_cs1);
            my ($sf_direct_ctl_1_130_cs1, $sf_misc_ctl_1_130_cs1, $sf_dly_ctl_2_130_cs1, $sf_dly_ctl_3_130_cs1, $sf_dly_ctl_4_130_cs1, $sf_dly_ctl_5_130_cs1);

            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_misc_ctl_1_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_misc_ctl_2_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_direct_ctl_1_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_dly_ctl_2_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_dly_ctl_3_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_dly_ctl_4_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) : "0";
                $sf_dly_ctl_5_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) : "0";

                $sf_misc_ctl_1_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_misc_ctl_2_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_direct_ctl_1_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_dly_ctl_2_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_dly_ctl_3_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_dly_ctl_4_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) : "0";
                $sf_dly_ctl_5_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) : "0";
            }

            #SFI 104Mhz setting command
            my $sf_mac_ctl_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            my ($sf_misc_ctl_1_104_cs0, $sf_dly_ctl_1_104_cs0, $sf_misc_ctl_2_104_cs0, $sf_dly_ctl_2_104_cs0);
            my ($sf_direct_ctl_1_104_cs0, $sf_misc_ctl_1_104_cs0, $sf_dly_ctl_2_104_cs0, $sf_dly_ctl_3_104_cs0, $sf_dly_ctl_4_104_cs0, $sf_dly_ctl_5_104_cs0);

            $sf_misc_ctl_1_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_misc_ctl_2_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_direct_ctl_1_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_2_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_3_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_4_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_5_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) : "0";

            my $sf_mac_ctl_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            my ($sf_misc_ctl_1_104_cs1, $sf_dly_ctl_1_104_cs1, $sf_misc_ctl_2_104_cs1, $sf_dly_ctl_2_104_cs1);
            my ($sf_direct_ctl_1_104_cs1, $sf_misc_ctl_1_104_cs1, $sf_dly_ctl_2_104_cs1, $sf_dly_ctl_3_104_cs1, $sf_dly_ctl_4_104_cs1, $sf_dly_ctl_5_104_cs1);

            $sf_misc_ctl_1_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_misc_ctl_2_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_direct_ctl_1_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_2_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_3_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_4_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_5_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) : "0";

            #SerialFlash driving set
            ###166MHZ driving
            my (@sf_driving_166_cs0, $sf_driving1_166_cs0, $sf_driving2_166_cs0, @dev_set_burst_166_cs0, $devinit_166_cs0 );
            my ($sf_driving_166_cs0, @dev_set_burst_166_cs0, $devinit_166_cs0);

            $sf_driving_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) : "0";
            #print "driving 166: $sf_driving_166\n";
            @dev_set_burst_166_cs0 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL,0));
            #print "@dev_set_burst_166\n";
            $devinit_166_cs0 = &sfi_dev_init(\@device_setup_command_cs0, \@dev_set_burst_166_cs0, $MAX_SFI_COMMAND);
            #print "dev init 166: $devinit_166\n";

            my (@sf_driving_166_cs1, $sf_driving1_166_cs1, $sf_driving2_166_cs1, @dev_set_burst_166_cs1, $devinit_166_cs1 );
            my ($sf_driving_166_cs1, @dev_set_burst_166_cs1, $devinit_166_cs1);

            $sf_driving_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) : "0";
            #print "driving 130: $sf_driving_130\n";
            @dev_set_burst_166_cs1 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL,1));
            #print "@dev_set_burst_166\n";
            $devinit_166_cs1 = &sfi_dev_init(\@device_setup_command_cs1, \@dev_set_burst_166_cs1, $MAX_SFI_COMMAND);
            #print "dev init 166: $devinit_166\n";

            ###130 MHZ driving
            my (@sf_driving_130_cs0, $sf_driving1_130_cs0, $sf_driving2_130_cs0, @dev_set_burst_130_cs0, $devinit_130_cs0 );
            my ($sf_driving_130_cs0, @dev_set_burst_130_cs0, $devinit_130_cs0);

            $sf_driving_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) : "0";
            #print "driving 130: $sf_driving_130\n";
            @dev_set_burst_130_cs0 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL,0));
            #print "@dev_set_burst_130\n";
            $devinit_130_cs0 = &sfi_dev_init(\@device_setup_command_cs0, \@dev_set_burst_130_cs0, $MAX_SFI_COMMAND);
            #print "dev init 130: $devinit_130\n";

            my (@sf_driving_130_cs1, $sf_driving1_130_cs1, $sf_driving2_130_cs1, @dev_set_burst_130_cs1, $devinit_130_cs1 );
            my ($sf_driving_130_cs1, @dev_set_burst_130_cs1, $devinit_130_cs1);

            $sf_driving_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) : "0";
            #print "driving 130: $sf_driving_130\n";
            @dev_set_burst_130_cs1 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL,1));
            #print "@dev_set_burst_130\n";
            $devinit_130_cs1 = &sfi_dev_init(\@device_setup_command_cs1, \@dev_set_burst_130_cs1, $MAX_SFI_COMMAND);
            #print "dev init 130: $devinit_130\n";

            ###104MHZ driving
            my (@sf_driving_104_cs0, $sf_driving1_104_cs0, $sf_driving2_104_cs0, @dev_set_burst_104_cs0, $devinit_104_cs0 );
            my ($sf_driving_104_cs0, @dev_set_burst_104_cs0, $devinit_104_cs0);

            $sf_driving_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) : "0";
            #print "driving 104: $sf_driving_104\n";
            @dev_set_burst_104_cs0 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL,0));
            $devinit_104_cs0 = &sfi_dev_init(\@device_setup_command_cs0, \@dev_set_burst_104_cs0, $MAX_SFI_COMMAND);
            #print "dev init 104: $devinit_104\n";

            my (@sf_driving_104_cs1, $sf_driving1_104_cs1, $sf_driving2_104_cs1, @dev_set_burst_104_cs1, $devinit_104_cs1 );
            my ($sf_driving_104_cs1, @dev_set_burst_104_cs1, $devinit_104_cs1);

            $sf_driving_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) : "0";
            #print "driving 104: $sf_driving_104\n";
            @dev_set_burst_104_cs1 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL,1));
            $devinit_104_cs1 = &sfi_dev_init(\@device_setup_command_cs1, \@dev_set_burst_104_cs1, $MAX_SFI_COMMAND);
            #print "dev init 104: $devinit_104\n";

            ###78MHZ driving
            my $sf_mac_ctl_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            my ($sf_misc_ctl_1_78_cs0, $sf_dly_ctl_1_78_cs0, $sf_misc_ctl_2_78_cs0, $sf_dly_ctl_2_78_cs0);
            my ($sf_direct_ctl_1_78_cs0, $sf_misc_ctl_1_78_cs0, $sf_dly_ctl_1_78_cs0, $sf_dly_ctl_2_78_cs0, $sf_dly_ctl_3_78_cs0, $sf_dly_ctl_4_78_cs0, $sf_dly_ctl_5_78_cs0);

            $sf_misc_ctl_1_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_misc_ctl_2_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_direct_ctl_1_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_2_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_3_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_4_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_5_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) : "0";

            my $sf_mac_ctl_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            my ($sf_misc_ctl_1_78_cs1, $sf_dly_ctl_1_78_cs1, $sf_misc_ctl_2_78_cs1, $sf_dly_ctl_2_78_cs1);
            my ($sf_direct_ctl_1_78_cs1, $sf_misc_ctl_1_78_cs1, $sf_dly_ctl_1_78_cs1, $sf_dly_ctl_2_78_cs1, $sf_dly_ctl_3_78_cs1, $sf_dly_ctl_4_78_cs1, $sf_dly_ctl_5_78_cs1);

            $sf_misc_ctl_1_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_misc_ctl_2_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_direct_ctl_1_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_2_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_3_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_4_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_5_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) : "0";

            my (@sf_driving_78_cs0, $sf_driving1_78_cs0, $sf_driving2_78_cs0, @dev_set_burst_78_cs0, $devinit_78_cs0 );
            my ($sf_driving_78_cs0, @dev_set_burst_78_cs0, $devinit_78_cs0);

            $sf_driving_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) : "0";
            #print "driving 78: $sf_driving_78_cs0\n";
            @dev_set_burst_78_cs0 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL,0));
            $devinit_78_cs0 = &sfi_dev_init(\@device_setup_command_cs0, \@dev_set_burst_78_cs0, $MAX_SFI_COMMAND);
            #print "dev init 78: $devinit_78_cs0\n";

            my (@sf_driving_78_cs1, $sf_driving1_78_cs1, $sf_driving2_78_cs1, @dev_set_burst_78_cs1, $devinit_78_cs1 );
            my ($sf_driving_78_cs1, @dev_set_burst_78_cs1, $devinit_78_cs1);

            $sf_driving_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) : "0";
            #print "driving 78: $sf_driving_78\n";
            @dev_set_burst_78_cs1 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL,1));
            #for(0..$#dev_set_burst_78_cs1)
            #{
            #   print "burst setting:$dev_set_burst_78_cs1[$_]\n";
            #}
            $devinit_78_cs1 = &sfi_dev_init(\@device_setup_command_cs1, \@dev_set_burst_78_cs1, $MAX_SFI_COMMAND);
            #print "dev init 78: $devinit_78_cs1";

            my ($sf_mac_ctl_13_cs0, $sf_misc_ctl_13_cs0, $sf_dly_ctl_13_cs0, @sf_driving_13_cs0, $sf_driving1_13_cs0, $sf_driving2_13_cs0);
            my ($sf_misc_ctl_1_26_cs0, $sf_direct_ctl_1_26_cs0, $sf_dly_ctl_2_26_cs0, $sf_dly_ctl_3_26_cs0, $sf_dly_ctl_4_26_cs0, $sf_dly_ctl_5_26_cs0, $sf_driving_26_cs0);

            $sf_mac_ctl_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_misc_ctl_1_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_misc_ctl_2_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_direct_ctl_1_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_2_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_3_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_4_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_5_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_driving_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,0) : "0";

            my ($sf_mac_ctl_13_cs1, $sf_misc_ctl_13_cs1, $sf_dly_ctl_13_cs1, @sf_driving_13_cs1, $sf_driving1_13_cs1, $sf_driving2_13_cs1);
            my ($sf_misc_ctl_1_26_cs1, $sf_direct_ctl_1_26_cs1, $sf_dly_ctl_2_26_cs1, $sf_dly_ctl_3_26_cs1, $sf_dly_ctl_4_26_cs1, $sf_dly_ctl_5_26_cs1, $sf_driving_26_cs1);

            $sf_mac_ctl_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_misc_ctl_1_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_misc_ctl_2_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_direct_ctl_1_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_2_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_3_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_4_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_5_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_driving_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL,1) : "0";

            if ($sfi_clk_config_LOCAL eq '130')
            {
                $combo_mem_info_struct .= <<"__TEMPLATE";
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}part
            {   // HW config 130Mhz Start
                $sf_mac_ctl_130_cs0,           // SFI_MAC_CTL
                $sf_direct_ctl_1_130_cs0,           // SFI_DIRECT_CTL
                $sf_misc_ctl_1_130_cs0,           // SFI_MISC_CTL
                $sf_misc_ctl_2_130_cs0,           // SFI_MISC_CTL2
                $sf_dly_ctl_2_130_cs0,           //  1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_130_cs0,           // 1st  SFI_DLY_CTL_3
                $sf_driving_130_cs0,           // DRIVING
                0,           // Reserved
                $sf_dly_ctl_4_130_cs0,           // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_130_cs0            // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_130_cs0
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26_cs0,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26_cs0,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26_cs0,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26_cs0,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26_cs0,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs0,         // 1st SFI_DLY_CTL_3
                $sf_driving_26_cs0,           // DRIVING
                0                 // Reserved
            }  // HW config End
        },
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Part Number'}part
            {   // HW config 130Mhz Start
                $sf_mac_ctl_130_cs1,           // SFI_MAC_CTL
                $sf_direct_ctl_1_130_cs1,           // SFI_DIRECT_CTL
                $sf_misc_ctl_1_130_cs1,           // SFI_MISC_CTL
                $sf_misc_ctl_2_130_cs1,           // SFI_MISC_CTL2
                $sf_dly_ctl_2_130_cs1,           //  1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_130_cs1,           // 1st  SFI_DLY_CTL_3
                $sf_driving_130_cs1,           // DRIVING
                0,           // Reserved
                $sf_dly_ctl_4_130_cs1,           // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_130_cs1            // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_130_cs1
            },

            {   // HW config 26Mhz Start
                $sf_mac_ctl_26_cs1,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26_cs1,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26_cs1,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26_cs1,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26_cs1,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs1,         // 1st SFI_DLY_CTL_3
                $sf_driving_26_cs1,           // DRIVING
                0                 // Reserved
            }  // HW config End
        }$comma
__TEMPLATE
            }
            elsif($sfi_clk_config_LOCAL eq '166')
            {
                $combo_mem_info_struct .= <<"__TEMPLATE";
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}part
            {   // HW config 166Mhz Start
                $sf_mac_ctl_166_cs0,           // SFI_MAC_CTL
                $sf_direct_ctl_1_166_cs0,           // SFI_DIRECT_CTL
                $sf_misc_ctl_1_166_cs0,           // SFI_MISC_CTL
                $sf_misc_ctl_2_166_cs0,           // SFI_MISC_CTL2
                $sf_dly_ctl_2_166_cs0,           //  1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_166_cs0,           // 1st  SFI_DLY_CTL_3
                $sf_driving_166_cs0,           // DRIVING
                0,           // Reserved
                $sf_dly_ctl_4_166_cs0,           // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_166_cs0            // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_166_cs0
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26_cs0,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26_cs0,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26_cs0,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26_cs0,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26_cs0,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs0,         // 1st SFI_DLY_CTL_3
                $sf_driving_26_cs0,           // DRIVING
                0                 // Reserved
            }  // HW config End
        },
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Part Number'}part
            {   // HW config 130Mhz Start
                $sf_mac_ctl_166_cs1,           // SFI_MAC_CTL
                $sf_direct_ctl_1_166_cs1,           // SFI_DIRECT_CTL
                $sf_misc_ctl_1_166_cs1,           // SFI_MISC_CTL
                $sf_misc_ctl_2_166_cs1,           // SFI_MISC_CTL2
                $sf_dly_ctl_2_166_cs1,           //  1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_166_cs1,           // 1st  SFI_DLY_CTL_3
                $sf_driving_166_cs1,           // DRIVING
                0,           // Reserved
                $sf_dly_ctl_4_166_cs1,           // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_166_cs1            // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_166_cs1
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26_cs1,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26_cs1,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26_cs1,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26_cs1,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26_cs1,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs1,         // 1st SFI_DLY_CTL_3
                $sf_driving_26_cs1,           // DRIVING
                0                 // Reserved
            }  // HW config End
        }$comma
__TEMPLATE
            }
            elsif($sfi_clk_config_LOCAL eq '104')
            {
                $combo_mem_info_struct .= <<"__TEMPLATE";
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}part
            {   // HW config 104Mhz Start
                $sf_mac_ctl_104_cs0,  // SFI_MAC_CTL
                $sf_direct_ctl_1_104_cs0,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_104_cs0,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_104_cs0,           // SFI_MISC_CTL2
                $sf_dly_ctl_2_104_cs0,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_104_cs0,         // 1st SFI_DLY_CTL_3
                $sf_driving_104_cs0,           // DRIVING
                0,                  // Reserved
                $sf_dly_ctl_4_104_cs0,  // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_104_cs0  // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_104_cs0
            },
               {   // HW config 26Mhz Start
                $sf_mac_ctl_26_cs0,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26_cs0,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26_cs0,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26_cs0,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26_cs0,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs0,         // 1st SFI_DLY_CTL_3
                $sf_driving_26_cs0,           // DRIVING
                0                 // Reserved
            }  // HW config End
        },
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Part Number'}part
            {   // HW config 104Mhz Start
                $sf_mac_ctl_104_cs1,  // SFI_MAC_CTL
                $sf_direct_ctl_1_104_cs1,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_104_cs1,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_104_cs1,           // SFI_MISC_CTL2
                $sf_dly_ctl_2_104_cs1,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_104_cs1,         // 1st SFI_DLY_CTL_3
                $sf_driving_104_cs1,           // DRIVING
                0,                  // Reserved
                $sf_dly_ctl_4_104_cs1,  // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_104_cs1  // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_104_cs1
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26_cs1,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26_cs1,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26_cs1,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26_cs1,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26_cs1,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs1,         // 1st SFI_DLY_CTL_3
                $sf_driving_26_cs1,           // DRIVING
                0                 // Reserved
            }  // HW config End
        }$comma
__TEMPLATE
            }
            elsif($sfi_clk_config_LOCAL eq '78')
            {
                #print "test 78\n";
                $combo_mem_info_struct .= <<"__TEMPLATE";
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}part
            {   // HW config 78Mhz Start
                $sf_mac_ctl_78_cs0,  // SFI_MAC_CTL
                $sf_direct_ctl_1_78_cs0,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_78_cs0,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_78_cs0,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_78_cs0,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_78_cs0,         // 1st SFI_DLY_CTL_3
                $sf_driving_78_cs0,           // DRIVING
                0,                  // Reserved
                $sf_dly_ctl_4_78_cs0,  // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_78_cs0  // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_78_cs0
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26_cs0,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26_cs0,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26_cs0,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26_cs0,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26_cs0,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs0,         // 1st SFI_DLY_CTL_3
                $sf_driving_26_cs0,           // DRIVING
                0                 // Reserved
            }  // HW config End
        },
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Part Number'}part
            {   // HW config 78Mhz Start
                $sf_mac_ctl_78_cs1,  // SFI_MAC_CTL
                $sf_direct_ctl_1_78_cs1,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_78_cs1,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_78_cs1,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_78_cs1,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_78_cs1,         // 1st SFI_DLY_CTL_3
                $sf_driving_78_cs1,           // DRIVING
                0,                  // Reserved
                $sf_dly_ctl_4_78_cs1,  // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_78_cs1  // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_78_cs1
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26_cs1,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26_cs1,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26_cs1,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26_cs1,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26_cs1,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs1,         // 1st SFI_DLY_CTL_3
                $sf_driving_26_cs1,           // DRIVING
                0                 // Reserved
            }  // HW config End
        }$comma
__TEMPLATE
            }
        } ### for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})

        ###filter duplicate part number
        if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
        {
            for (0..$#$MCP_LIST_DUAL_SF_LOCAL)
            {
                my $duplicate_count = 0;
                while ($combo_mem_info_struct =~ /\{\s+\/\/$MCP_LIST_DUAL_SF_LOCAL->[$_]part\s+(\w*\W*){88}\w*\s+\}\W/gis)
                {
                    $duplicate_count = $duplicate_count + 1;
                    if ($duplicate_count > 1)
                    {
                        $combo_mem_info_struct = $` . $' . "deleted";
                        #'print "combo sfi config h : $&~~END~~,  , $duplicate_count\n";
                        $duplicate_count = 0;
                    }
                }
                print "part number : $MCP_LIST_DUAL_SF_LOCAL->[$_], $combo_mem_info_struct\n";
            }

            ###
            $combo_mem_info_struct = $combo_mem_info_struct . "deleted";
            if ($combo_mem_info_struct =~ /\W+deleted/gis)
            {
                $combo_mem_info_struct = $` . "\n\t\t}";
                #print "combo flash configure : $&, $combo_mem_info_struct\n";
                #last;
            }
        }
    } ### if ($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE')
    else
    {
        ### Fill-in the information of each memory

        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";

            my @device_setup_command = &split_sfi_command($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Setup'}->{'Command'});
            #SFI 166Mhz setting command
            my $sf_mac_ctl_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_166, $sf_dly_ctl_1_166, $sf_misc_ctl_2_166, $sf_dly_ctl_2_166);
            my ($sf_direct_ctl_1_166, $sf_misc_ctl_1_166, $sf_dly_ctl_2_166, $sf_dly_ctl_3_166, $sf_dly_ctl_4_166, $sf_dly_ctl_5_166);
            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_misc_ctl_1_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }

            #SFI 130Mhz setting command
            my $sf_mac_ctl_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_130, $sf_dly_ctl_1_130, $sf_misc_ctl_2_130, $sf_dly_ctl_2_130);
            my ($sf_direct_ctl_1_130, $sf_misc_ctl_1_130, $sf_dly_ctl_2_130, $sf_dly_ctl_3_130, $sf_dly_ctl_4_130, $sf_dly_ctl_5_130);
            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_misc_ctl_1_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }

            #SFI 104Mhz setting command
            my $sf_mac_ctl_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_104, $sf_dly_ctl_1_104, $sf_misc_ctl_2_104, $sf_dly_ctl_2_104);
            my ($sf_direct_ctl_1_104, $sf_misc_ctl_1_104, $sf_dly_ctl_2_104, $sf_dly_ctl_3_104, $sf_dly_ctl_4_104, $sf_dly_ctl_5_104);
            if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252')
            {
                $sf_misc_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                $sf_misc_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }
            elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_misc_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }
            else
            {
                $sf_misc_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_104 = "0";
                $sf_dly_ctl_2_104 = "0";
            }
            #SerialFlash driving set
            ###166MHZ driving
            my (@sf_driving_166, $sf_driving1_166, $sf_driving2_166, @dev_set_burst_166, $devinit_166 );
            my ($sf_driving_166, @dev_set_burst_166, $devinit_166);
            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_driving_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) : "0";
                print "driving 130: $sf_driving_130\n";
                @dev_set_burst_166 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL));
                print "@dev_set_burst_130\n";
                $devinit_166 = &sfi_dev_init(\@device_setup_command, \@dev_set_burst_166, $MAX_SFI_COMMAND);
                print "dev init 130: $devinit_130\n";
            }
            ###130MHZ driving
            my (@sf_driving_130, $sf_driving1_130, $sf_driving2_130, @dev_set_burst_130, $devinit_130 );
            my ($sf_driving_130, @dev_set_burst_130, $devinit_130);
            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_driving_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) : "0";
                print "driving 130: $sf_driving_130\n";
                @dev_set_burst_130 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL));
                print "@dev_set_burst_130\n";
                $devinit_130 = &sfi_dev_init(\@device_setup_command, \@dev_set_burst_130, $MAX_SFI_COMMAND);
                print "dev init 130: $devinit_130\n";
            }

            my (@sf_driving_104, $sf_driving1_104, $sf_driving2_104, @dev_set_burst_104, $devinit_104 );
            my ($sf_driving_104, @dev_set_burst_104, $devinit_104);
            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6251'))
            {
                @sf_driving_104 = &split_sfi_driving(&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL));
                $sf_driving1_104 = (defined $sf_driving_104[0] and $sf_driving_104[0] ne 'x') ? $sf_driving_104[0] : "0x0";
                $sf_driving2_104 = (defined $sf_driving_104[1] and $sf_driving_104[1] ne 'x') ? $sf_driving_104[1] : "0x0";
                @dev_set_burst_104 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL));
                $devinit_104 = &sfi_dev_init(\@device_setup_command, \@dev_set_burst_104, $MAX_SFI_COMMAND);
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                $sf_driving_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) : "0";
                print "driving: $sf_driving_104\n";
                @dev_set_burst_104 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL));
                $devinit_104 = &sfi_dev_init(\@device_setup_command, \@dev_set_burst_104, $MAX_SFI_COMMAND);
                print "dev init : $devinit_104";
            }
            elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_driving_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) : "0";
                print "driving 104: $sf_driving_104\n";
                @dev_set_burst_104 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL));
                $devinit_104 = &sfi_dev_init(\@device_setup_command, \@dev_set_burst_104, $MAX_SFI_COMMAND);
                print "dev init 104: $devinit_104\n";
            }

            my $sf_mac_ctl_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_78, $sf_dly_ctl_1_78, $sf_misc_ctl_2_78, $sf_dly_ctl_2_78);
            my ($sf_direct_ctl_1_78, $sf_misc_ctl_1_78, $sf_dly_ctl_1_78, $sf_dly_ctl_2_78, $sf_dly_ctl_3_78, $sf_dly_ctl_4_78, $sf_dly_ctl_5_78);
            if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252')
            {
                $sf_misc_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                $sf_misc_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }
            elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_misc_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }
            else
            {
                $sf_misc_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_78 = "0";
                $sf_dly_ctl_2_78 = "0";
            }

            my (@sf_driving_78, $sf_driving1_78, $sf_driving2_78, @dev_set_burst_78, $devinit_78 );
            my ($sf_driving_78, @dev_set_burst_78, $devinit_78);
            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6251'))
            {
                 @sf_driving_78 = &split_sfi_driving(&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL));
                 $sf_driving1_78 = (defined $sf_driving_78[0] and $sf_driving_78[0] ne 'x') ? $sf_driving_78[0] : "0x0";
                 $sf_driving2_78 = (defined $sf_driving_78[1] and $sf_driving_78[1] ne 'x') ? $sf_driving_78[1] : "0x0";
                 @device_setup_command = &split_sfi_command($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Setup'}->{'Command'});
                 @dev_set_burst_78 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL));
                 $devinit_78 = &sfi_dev_init(\@device_setup_command, \@dev_set_burst_78, $MAX_SFI_COMMAND);

            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                $sf_driving_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) : "0";
                @dev_set_burst_78 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL));
                $devinit_78 = &sfi_dev_init(\@device_setup_command, \@dev_set_burst_104, $MAX_SFI_COMMAND);
            }
            elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_driving_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) : "0";
                #print "driving 78: $sf_driving_78\n";
                @dev_set_burst_78 = &split_sfi_command(&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DEV_SET_BURST', $MDL_INFO_LIST_LOCAL));
                $devinit_78 = &sfi_dev_init(\@device_setup_command, \@dev_set_burst_78, $MAX_SFI_COMMAND);
                # print "dev init 78: $devinit_78";
            }

            my ($sf_mac_ctl_13, $sf_misc_ctl_13, $sf_dly_ctl_13, @sf_driving_13, $sf_driving1_13, $sf_driving2_13);
            my ($sf_misc_ctl_1_26, $sf_direct_ctl_1_26, $sf_dly_ctl_2_26, $sf_dly_ctl_3_26, $sf_dly_ctl_4_26, $sf_dly_ctl_5_26, $sf_driving_26);
            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6251'))
            {
                $sf_mac_ctl_13 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_13 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_13 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                @sf_driving_13 = &split_sfi_driving(&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL));
                $sf_driving1_13 = (defined $sf_driving_13[0] and $sf_driving_13[0] ne 'x') ? $sf_driving_13[0] : "0x0";
                $sf_driving2_13 = (defined $sf_driving_13[1] and $sf_driving_13[1] ne 'x') ? $sf_driving_13[1] : "0x0";
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                $sf_mac_ctl_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_1_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_driving_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) : "0";
            }
            elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_mac_ctl_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_1_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_driving_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) : "0";
            }

            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6251'))
            {
                $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 104Mhz Start
                $sf_mac_ctl_104,  // SF_MAC_CTL
                $sf_misc_ctl_1_104,  // 1st SF_MISC_CTL
                $sf_dly_ctl_1_104,  // 1st SF_DLY_CTL
                0x000001F0,  // SF_DR_CTL
                $sf_driving1_104,         // SF_DRVING1
                $sf_driving2_104,         // SF_DRVING2
                0,            // Reserved
                $sf_misc_ctl_2_104,  // 2nd SF_MISC_CTL
                $sf_dly_ctl_2_104  // 2nd SF_DLY_CTL
            },  // HW config End
            {
$devinit_104
            },
            {   // HW config 78Mhz Start
                $sf_mac_ctl_78,  // SF_MAC_CTL
                $sf_misc_ctl_1_78,  // 1st SF_MISC_CTL
                $sf_dly_ctl_1_78,  // 1st SF_DLY_CTL
                0x000000F0,  // SF_DR_CTL
                $sf_driving1_78,         // SF_DRVING1
                $sf_driving2_78,         // SF_DRVING2
                0,            // Reserved
                $sf_misc_ctl_2_78,  // 2nd SF_MISC_CTL
                $sf_dly_ctl_2_78  // 2nd SF_DLY_CTL
            },  // HW config End
            {
$devinit_78
            },
            {   // HW config 13Mhz Start
                $sf_mac_ctl_13,  // SF_MAC_CTL
                $sf_misc_ctl_13,  // SF_MISC_CTL
                $sf_dly_ctl_13,  // SF_DLY_CTL
                0x000000F0,  // SF_DR_CTL
                $sf_driving1_13,         // SF_DRVING1
                $sf_driving2_13,         // SF_DRVING2
                0            // Reserved
            }  // HW config End
        }$comma
__TEMPLATE
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 104Mhz Start
                $sf_mac_ctl_104,  // SFI_MAC_CTL
                $sf_direct_ctl_1_104,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_104,     //  SFI_MISC_CTL
                $sf_dly_ctl_2_104,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_104,         // 1st SFI_DLY_CTL_3
                $sf_driving_104,           // DRIVING
                0,                  // Reserved
                $sf_dly_ctl_4_104,  // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_104  // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_104
            },
            {   // HW config 78Mhz Start
                $sf_mac_ctl_78,  // SFI_MAC_CTL
                $sf_direct_ctl_1_78,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_78,     //  SFI_MISC_CTL
                $sf_dly_ctl_2_78,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_78,         // 1st SFI_DLY_CTL_3
                $sf_driving_78,           // DRIVING
                0,                  // Reserved
                $sf_dly_ctl_4_78,  // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_78  // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_78
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26,     //  SFI_MISC_CTL
                $sf_dly_ctl_2_26,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,         // 1st SFI_DLY_CTL_3
                $sf_driving_26,           // DRIVING
                0                 // Reserved
            }  // HW config End
        }$comma
__TEMPLATE
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250')
            {
                if ($sfi_clk_config_LOCAL eq '130')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
#if defined(MT6250) || defined(MT6280)
            {   // HW config 130Mhz Start
                $sf_mac_ctl_130,           // SFI_MAC_CTL
                $sf_direct_ctl_1_130,           // SFI_DIRECT_CTL
                $sf_misc_ctl_1_130,           // SFI_MISC_CTL
                $sf_misc_ctl_2_130,           // SFI_MISC_CTL2
                $sf_dly_ctl_2_130,           //  1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_130,           // 1st  SFI_DLY_CTL_3
                $sf_driving_130,           // DRIVING
                0,           // Reserved
                $sf_dly_ctl_4_130,           // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_130            // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_130
            },
#endif
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,         // 1st SFI_DLY_CTL_3
                $sf_driving_26,           // DRIVING
                0                 // Reserved
            }  // HW config End
        }$comma
__TEMPLATE
                }
                elsif ($sfi_clk_config_LOCAL eq '104')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 104Mhz Start
                $sf_mac_ctl_104,  // SFI_MAC_CTL
                $sf_direct_ctl_1_104,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_104,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_104,           // SFI_MISC_CTL2
                $sf_dly_ctl_2_104,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_104,         // 1st SFI_DLY_CTL_3
                $sf_driving_104,           // DRIVING
                0,                  // Reserved
                $sf_dly_ctl_4_104,  // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_104  // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_104
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,         // 1st SFI_DLY_CTL_3
                $sf_driving_26,           // DRIVING
                0                 // Reserved
            }  // HW config End
        }$comma
__TEMPLATE
                }
                elsif ($sfi_clk_config_LOCAL eq '78')
                {
                    #print "test 78\n";
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 78Mhz Start
                $sf_mac_ctl_78,  // SFI_MAC_CTL
                $sf_direct_ctl_1_78,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_78,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_78,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_78,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_78,         // 1st SFI_DLY_CTL_3
                $sf_driving_78,           // DRIVING
                0,                  // Reserved
                $sf_dly_ctl_4_78,  // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_78  // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_78
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,         // 1st SFI_DLY_CTL_3
                $sf_driving_26,           // DRIVING
                0                 // Reserved
            }   // HW config End
        }$comma
__TEMPLATE
                }
            }
            elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                if ($sfi_clk_config_LOCAL eq '130')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}

            {   // HW config 130Mhz Start
                $sf_mac_ctl_130,           // SFI_MAC_CTL
                $sf_direct_ctl_1_130,           // SFI_DIRECT_CTL
                $sf_misc_ctl_1_130,           // SFI_MISC_CTL
                $sf_misc_ctl_2_130,           // SFI_MISC_CTL2
                $sf_dly_ctl_2_130,           //  1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_130,           // 1st  SFI_DLY_CTL_3
                $sf_driving_130,           // DRIVING
                0,           // Reserved
                $sf_dly_ctl_4_130,           // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_130            // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_130
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,         // 1st SFI_DLY_CTL_3
                $sf_driving_26,           // DRIVING
                0                 // Reserved
            }   // HW config End
        }$comma
__TEMPLATE
                }
                elsif ($sfi_clk_config_LOCAL eq '166')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}

            {   // HW config 166Mhz Start
                $sf_mac_ctl_166,           // SFI_MAC_CTL
                $sf_direct_ctl_1_166,           // SFI_DIRECT_CTL
                $sf_misc_ctl_1_166,           // SFI_MISC_CTL
                $sf_misc_ctl_2_166,           // SFI_MISC_CTL2
                $sf_dly_ctl_2_166,           //  1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_166,           // 1st  SFI_DLY_CTL_3
                $sf_driving_166,           // DRIVING
                0,           // Reserved
                $sf_dly_ctl_4_166,           // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_166            // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_166
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,         // 1st SFI_DLY_CTL_3
                $sf_driving_26,           // DRIVING
                0                 // Reserved
            }   // HW config End
        }$comma
__TEMPLATE
                }
                elsif ($sfi_clk_config_LOCAL eq '104')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 104Mhz Start
                $sf_mac_ctl_104,  // SFI_MAC_CTL
                $sf_direct_ctl_1_104,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_104,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_104,           // SFI_MISC_CTL2
                $sf_dly_ctl_2_104,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_104,         // 1st SFI_DLY_CTL_3
                $sf_driving_104,           // DRIVING
                0,                  // Reserved
                $sf_dly_ctl_4_104,  // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_104  // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_104
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,         // 1st SFI_DLY_CTL_3
                $sf_driving_26,           // DRIVING
                0                 // Reserved
            }   // HW config End
        }$comma
__TEMPLATE
                }
                elsif ($sfi_clk_config_LOCAL eq '78')
                {
                    #print "test 78\n";
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 78Mhz Start
                $sf_mac_ctl_78,  // SFI_MAC_CTL
                $sf_direct_ctl_1_78,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_78,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_78,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_78,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_78,         // 1st SFI_DLY_CTL_3
                $sf_driving_78,           // DRIVING
                0,                  // Reserved
                $sf_dly_ctl_4_78,  // 2nd SFI_DLY_CTL_4
                $sf_dly_ctl_5_78  // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
$devinit_78
            },
            {   // HW config 26Mhz Start
                $sf_mac_ctl_26,  // SFI_MAC_CTL
                $sf_direct_ctl_1_26,  // SFI_DIRECT_CTL
                $sf_misc_ctl_1_26,     //  SFI_MISC_CTL
                $sf_misc_ctl_2_26,     //  SFI_MISC_CTL2
                $sf_dly_ctl_2_26,     // 1st SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,         // 1st SFI_DLY_CTL_3
                $sf_driving_26,           // DRIVING
                0                 // Reserved
            }   // HW config End
        }$comma
__TEMPLATE
                }
            }
        }
    }



    ###
    my $template = <<"__TEMPLATE";
//-----------------------------------------------------------------------------
// MCP Serial Flash HW settings (for ComboMEM only, do not include this header)
//-----------------------------------------------------------------------------
static const CMEMEntrySFIList combo_mem_hw_list = {   // (to be renamed by SFI owner)
#if defined(MT6251) || defined(MT6255) || defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    "COMBO_MEM_SFI",
#elif defined(MT6253L)||defined(MT6252)
    #ifdef __SV5_ENABLED__
    GFH_HEADER(GFH_EPP_PARAM, 1),
    #else
    "COMBO_MEM_SFI",
    #endif
#endif //defined(MT6251)
    COMBO_SFI_VER,           // SFI structure version
    SFI_COMBO_COUNT,   // defined in custom_Memorydevice.h
    {

$combo_mem_info_struct
    }
};

__TEMPLATE

}

#****************************************************************************
# subroutine:  combo_sfi_defs_h_file_body
# return:
#****************************************************************************
sub combo_sfi_defs_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $DUAL_SF_COUNT_LOCAL) = @_;
    ###
    my $MAX_SFI_COMMAND = 32;

    ### Define SIP compile option
    my $sfi_sip;
    #if (($PLATFORM eq 'MT6252') and ($MAKEFILE_OPTIONS{'sip_serial_flash_size'} eq '16M_BITS'))
    if ((($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502')) and ($MAKEFILE_OPTIONS_LOCAL->{'sip_serial_flash_size'} ne 'NONE'))
    {
        $sfi_sip = "#define _SFI_SIP_SerialFlash\n";
    }
    chomp $sfi_sip;
    my $dual_sf_count;
    if ($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE')
    {
        $dual_sf_count = "#define DUAL_COMBO_MEM_ENTRY_COUNT  ";
        $dual_sf_count .= $DUAL_SF_COUNT_LOCAL;
    }
    ### Define SIP sfi count
    my $sfi_sip_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT};

    ###
    my $template = <<"__TEMPLATE";
#ifndef _COMBO_SFI_DEFS_H
#define _COMBO_SFI_DEFS_H

#include "flash_sfi_release.h"
//-----------------------------------------------------------------------------
// Combo MEM HW Settings
//-----------------------------------------------------------------------------
#define COMBO_SFI_VER   1

$dual_sf_count

$sfi_sip

#if defined(_SFI_SIP_SerialFlash)
  #define SFI_COMBO_COUNT    $sfi_sip_count
#elif defined(__COMBO_MEMORY_SUPPORT__)
  #if !defined(__DUAL_SERIAL_FLASH_SUPPORT__)
    #define SFI_COMBO_COUNT    COMBO_MEM_ENTRY_COUNT
  #else
    #define SFI_COMBO_COUNT    DUAL_COMBO_MEM_ENTRY_COUNT
  #endif
#else
  #define SFI_COMBO_COUNT    1
#endif

#if defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
typedef struct 
{
  #if defined(__SFI_CLK_166MHZ__) && defined(MT6260)
    kal_uint32      HWConf_166M[10];    // to be defined by SFI/EMI owner
    kal_uint8       DevInit_166M[32];   // to be defined by SFI/EMI owner  (reserved for serial flash)
  #endif //defined(__SFI_CLK_166MHZ__)
  #if defined(__SFI_CLK_130MHZ__)
    kal_uint32      HWConf_130M[10];    // to be defined by SFI/EMI owner
    kal_uint8       DevInit_130M[32];   // to be defined by SFI/EMI owner  (reserved for serial flash)
  #endif //defined(__SFI_CLK_130MHZ__)
  #if defined(__SFI_CLK_104MHZ__)
    kal_uint32      HWConf_104M[10];    // to be defined by SFI/EMI owner
    kal_uint8       DevInit_104M[32];   // to be defined by SFI/EMI owner  (reserved for serial flash)
  #endif //defined(__SFI_CLK_104MHZ__)
  #if defined(__SFI_CLK_78MHZ__) || defined(__SFI_CLK_80MHZ__)
    kal_uint32      HWConf_78M[10];     // to be defined by SFI/EMI owner
    kal_uint8       DevInit_78M[32];    // to be defined by SFI/EMI owner  (reserved for serial flash)
  #endif //defined(__SFI_CLK_78MHZ__)
    kal_uint32      HWConf_26M[8];      // to be defined by SFI/EMI owner

} CMEMEntrySFI;
#else
typedef struct 
{
    kal_uint32      HWConf_104M[9];     // to be defined by SFI/EMI owner
    kal_uint8       DevInit_104M[$MAX_SFI_COMMAND];   // to be defined by SFI/EMI owner  (reserved for serial flash)
    kal_uint32      HWConf_78M[9];      // to be defined by SFI/EMI owner
    kal_uint8       DevInit_78M[$MAX_SFI_COMMAND];    // to be defined by SFI/EMI owner  (reserved for serial flash)
    kal_uint32      HWConf_13M[7];      // to be defined by SFI/EMI owner

} CMEMEntrySFI;
#endif

#if defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
typedef struct 
{
  #if defined(__SFI_CLK_166MHZ__) && defined(MT6260)
    kal_uint32      HWConf_166M[5];     // to be defined by SFI/EMI owner
  #endif //defined(__SFI_CLK_166MHZ__)
  #if defined(__SFI_CLK_130MHZ__)
    kal_uint32      HWConf_130M[5];     // to be defined by SFI/EMI owner
  #endif //defined(__SFI_CLK_130MHZ__)
  #if defined(__SFI_CLK_104MHZ__)
    kal_uint32      HWConf_104M[5];     // to be defined by SFI/EMI owner
  #endif //defined(__SFI_CLK_104MHZ__)
  #if defined(__SFI_CLK_78MHZ__) || defined(__SFI_CLK_80MHZ__)
    kal_uint32      HWConf_78M[5];      // to be defined by SFI/EMI owner
  #endif //defined(__SFI_CLK_78MHZ__)
    kal_uint32      HWConf_26M[3];      // to be defined by SFI/EMI owner
} CMEMEntrySFI_DCM;
#else
typedef struct 
{
    kal_uint32      HWConf_104M[5];     // to be defined by SFI/EMI owner
    kal_uint32      HWConf_78M[5];      // to be defined by SFI/EMI owner
    kal_uint32      HWConf_13M[3];      // to be defined by SFI/EMI owner
} CMEMEntrySFI_DCM;
#endif


typedef struct 
{
    kal_uint32      HWConf[16];         // to be defined by EMI owner
} CMEMEntryEMI;

typedef struct 
{
#if defined(MT6251) || defined(MT6255) || defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    char               m_identifier[16];   // MTK_COMBO_ID_INFO
#elif defined(MT6253L)||defined(MT6252)
  #ifdef __SV5_ENABLED__
    GFH_Header_Type    mem_info;
  #else
    char               m_identifier[16];   // MTK_COMBO_ID_INFO
  #endif
#endif //defined(MT6251) || defined(MT6255) || defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    unsigned int       m_ver;
    unsigned int       Count;
    CMEMEntrySFI       List[SFI_COMBO_COUNT];  // to be defined by SFI/EMI owner
} CMEMEntrySFIList;

typedef struct 
{
    CMEMEntrySFI_DCM      List[SFI_COMBO_COUNT];  // to be defined by SFI/EMI owner
} CMEMEntrySFIList_dcm;

#endif

__TEMPLATE
}


#****************************************************************************
# subroutine:  custom_SFI_h_file_body
# return:
#****************************************************************************
sub custom_SFI_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $sfi_clk_config_LOCAL, $MCP_LIST_DUAL_SF_LOCAL) = @_;
    my $sfi_clk_str = sprintf("#define __SFI_CLK_%sMHZ__", $sfi_clk_config_LOCAL);
    my $combo_mem_info_struct;
    # print "test custom sfi\n";
    if ($MAKEFILE_OPTIONS_LOCAL->{'dual_serial_flash_support'} eq 'TRUE')
    {
        ### Fill-in the information of each memory

        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";

            my @device_setup_command_cs0 = &split_sfi_command($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Setup'}->{'Command'});
            my @device_setup_command_cs1 = &split_sfi_command($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Device Setup'}->{'Command'});
            ###166MHZ setting
            my $sf_mac_ctl_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            my $sf_mac_ctl_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";

            my ($sf_misc_ctl_1_166_cs0, $sf_dly_ctl_1_166_cs0, $sf_misc_ctl_2_166_cs0, $sf_dly_ctl_2_166_cs0);
            my ($sf_misc_ctl_1_166_cs0, $sf_direct_ctl_1_166_cs0, $sf_dly_ctl_2_166_cs0, $sf_dly_ctl_3_166_cs0, $sf_dly_ctl_4_166_cs0, $sf_dly_ctl_5_166_cs0);

            my ($sf_misc_ctl_1_166_cs1, $sf_dly_ctl_1_166_cs1, $sf_misc_ctl_2_166_cs1, $sf_dly_ctl_2_166_cs1);
            my ($sf_misc_ctl_1_166_cs1, $sf_direct_ctl_1_166_cs1, $sf_dly_ctl_2_166_cs1, $sf_dly_ctl_3_166_cs1, $sf_dly_ctl_4_166_cs1, $sf_dly_ctl_5_166_cs1);

            my $sf_mac_ctl_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            my ($sf_misc_ctl_1_166_cs0, $sf_dly_ctl_1_166_cs0, $sf_misc_ctl_2_166_cs0, $sf_dly_ctl_2_166_cs0);
            my ($sf_misc_ctl_1_166_cs0, $sf_direct_ctl_1_166_cs0, $sf_dly_ctl_2_166_cs0, $sf_dly_ctl_3_166_cs0, $sf_dly_ctl_4_166_cs0, $sf_dly_ctl_5_166_cs0);

            my $sf_mac_ctl_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            my ($sf_misc_ctl_1_166_cs1, $sf_dly_ctl_1_166_cs1, $sf_misc_ctl_2_166_cs1, $sf_dly_ctl_2_166_cs1);
            my ($sf_misc_ctl_1_166_cs1, $sf_direct_ctl_1_166_cs1, $sf_dly_ctl_2_166_cs1, $sf_dly_ctl_3_166_cs1, $sf_dly_ctl_4_166_cs1, $sf_dly_ctl_5_166_cs1);

            ###130MHZ setting
            my $sf_mac_ctl_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            my $sf_mac_ctl_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";

            my ($sf_misc_ctl_1_130_cs0, $sf_dly_ctl_1_130_cs0, $sf_misc_ctl_2_130_cs0, $sf_dly_ctl_2_130_cs0);
            my ($sf_misc_ctl_1_130_cs0, $sf_direct_ctl_1_130_cs0, $sf_dly_ctl_2_130_cs0, $sf_dly_ctl_3_130_cs0, $sf_dly_ctl_4_130_cs0, $sf_dly_ctl_5_130_cs0);

            my ($sf_misc_ctl_1_130_cs1, $sf_dly_ctl_1_130_cs1, $sf_misc_ctl_2_130_cs1, $sf_dly_ctl_2_130_cs1);
            my ($sf_misc_ctl_1_130_cs1, $sf_direct_ctl_1_130_cs1, $sf_dly_ctl_2_130_cs1, $sf_dly_ctl_3_130_cs1, $sf_dly_ctl_4_130_cs1, $sf_dly_ctl_5_130_cs1);

            my $sf_mac_ctl_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            my ($sf_misc_ctl_1_130_cs0, $sf_dly_ctl_1_130_cs0, $sf_misc_ctl_2_130_cs0, $sf_dly_ctl_2_130_cs0);
            my ($sf_misc_ctl_1_130_cs0, $sf_direct_ctl_1_130_cs0, $sf_dly_ctl_2_130_cs0, $sf_dly_ctl_3_130_cs0, $sf_dly_ctl_4_130_cs0, $sf_dly_ctl_5_130_cs0);

            my $sf_mac_ctl_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            my ($sf_misc_ctl_1_130_cs1, $sf_dly_ctl_1_130_cs1, $sf_misc_ctl_2_130_cs1, $sf_dly_ctl_2_130_cs1);
            my ($sf_misc_ctl_1_130_cs1, $sf_direct_ctl_1_130_cs1, $sf_dly_ctl_2_130_cs1, $sf_dly_ctl_3_130_cs1, $sf_dly_ctl_4_130_cs1, $sf_dly_ctl_5_130_cs1);

            $sf_misc_ctl_1_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_direct_ctl_1_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_2_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_3_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_4_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_5_166_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) : "0";

            $sf_misc_ctl_1_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_direct_ctl_1_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_2_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_3_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_4_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_5_166_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) : "0";

            $sf_misc_ctl_1_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_direct_ctl_1_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_2_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_3_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_4_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_5_130_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) : "0";

            $sf_misc_ctl_1_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_direct_ctl_1_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_2_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_3_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_4_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_5_130_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) : "0";

            my  $sf_mac_ctl_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            my ($sf_misc_ctl_1_104_cs0, $sf_dly_ctl_1_104_cs0, $sf_misc_ctl_2_104_cs0, $sf_dly_ctl_2_104_cs0);
            my ($sf_misc_ctl_1_104_cs0, $sf_direct_ctl_1_104_cs0, $sf_dly_ctl_2_104_cs0, $sf_dly_ctl_3_104_cs0, $sf_dly_ctl_4_104_cs0, $sf_dly_ctl_5_104_cs0);

            my  $sf_mac_ctl_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            my ($sf_misc_ctl_1_104_cs1, $sf_dly_ctl_1_104_cs1, $sf_misc_ctl_2_104_cs1, $sf_dly_ctl_2_104_cs1);
            my ($sf_misc_ctl_1_104_cs1, $sf_direct_ctl_1_104_cs1, $sf_dly_ctl_2_104_cs1, $sf_dly_ctl_3_104_cs1, $sf_dly_ctl_4_104_cs1, $sf_dly_ctl_5_104_cs1);

            $sf_misc_ctl_1_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_direct_ctl_1_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_2_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_3_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_4_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_5_104_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) : "0";

            $sf_misc_ctl_1_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_direct_ctl_1_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_2_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_3_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_4_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_5_104_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) : "0";

            my $sf_mac_ctl_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_78_cs0, $sf_dly_ctl_1_78_cs0, $sf_misc_ctl_2_78_cs0, $sf_dly_ctl_2_78_cs0);
            my ($sf_misc_ctl_1_78_cs0, $sf_direct_ctl_1_78_cs0, $sf_dly_ctl_2_78_cs0, $sf_dly_ctl_3_78_cs0, $sf_dly_ctl_4_78_cs0, $sf_dly_ctl_5_78_cs0);

            $sf_misc_ctl_1_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_direct_ctl_1_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_2_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_3_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_4_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_5_78_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,0) : "0";

            my $sf_mac_ctl_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_78_cs1, $sf_dly_ctl_1_78_cs1, $sf_misc_ctl_2_78_cs1, $sf_dly_ctl_2_78_cs1);
            my ($sf_misc_ctl_1_78_cs1, $sf_direct_ctl_1_78_cs1, $sf_dly_ctl_2_78_cs1, $sf_dly_ctl_3_78_cs1, $sf_dly_ctl_4_78_cs1, $sf_dly_ctl_5_78_cs1);

            $sf_misc_ctl_1_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_direct_ctl_1_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_2_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_3_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_4_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_5_78_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL,1) : "0";


            my ($sf_mac_ctl_26_cs0, $sf_misc_ctl_26_cs0, $sf_direct_ctl_26_cs0);
            my ($sf_misc_ctl_1_26_cs0, $sf_direct_ctl_1_26_cs0, $sf_dly_ctl_2_26_cs0, $sf_dly_ctl_3_26_cs0, $sf_dly_ctl_4_26_cs0, $sf_dly_ctl_5_26_cs0, $sf_driving_26_cs0);
            my ($sf_mac_ctl_26_cs1, $sf_misc_ctl_26_cs1, $sf_direct_ctl_26_cs1);
            my ($sf_misc_ctl_1_26_cs1, $sf_direct_ctl_1_26_cs1, $sf_dly_ctl_2_26_cs1, $sf_dly_ctl_3_26_cs1, $sf_dly_ctl_4_26_cs1, $sf_dly_ctl_5_26_cs1, $sf_driving_26_cs1);

            $sf_mac_ctl_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_misc_ctl_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_direct_ctl_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_2_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,0) : "0";
            $sf_dly_ctl_3_26_cs0 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,0) : "0";

            $sf_mac_ctl_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_misc_ctl_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_direct_ctl_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_2_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL,1) : "0";
            $sf_dly_ctl_3_26_cs1 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG_DUAL_SF($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL,1) : "0";

            if ($sfi_clk_config_LOCAL eq '130')
            {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}part

            {   // HW config 130Mhz Start
                $sf_misc_ctl_1_130_cs0,  // SFI_MISC_CTL
                $sf_dly_ctl_2_130_cs0,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_130_cs0,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_130_cs0,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_130_cs0,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26_cs0,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26_cs0,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs0,  // SFI_DLY_CTL_3
            }   // HW config END
        },
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Part Number'}part

            {   // HW config 130Mhz Start
                $sf_misc_ctl_1_130_cs1,  // SFI_MISC_CTL
                $sf_dly_ctl_2_130_cs1,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_130_cs1,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_130_cs1,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_130_cs1,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26_cs1,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26_cs1,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs1,  // SFI_DLY_CTL_3
            }   // HW config END
        }$comma
__TEMPLATE
            }
            elsif ($sfi_clk_config_LOCAL eq '166')
            {
                $combo_mem_info_struct .= <<"__TEMPLATE";
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}part

            {   // HW config 166Mhz Start
                $sf_misc_ctl_1_166_cs0,  // SFI_MISC_CTL
                $sf_dly_ctl_2_166_cs0,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_166_cs0,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_166_cs0,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_166_cs0,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26_cs0,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26_cs0,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs0,  // SFI_DLY_CTL_3
            }   // HW config END
        },
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Part Number'}part

            {   // HW config 166Mhz Start
                $sf_misc_ctl_1_166_cs1,  // SFI_MISC_CTL
                $sf_dly_ctl_2_166_cs1,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_166_cs1,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_166_cs1,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_166_cs1,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26_cs1,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26_cs1,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs1,  // SFI_DLY_CTL_3
            }   // HW config END
        }$comma
__TEMPLATE
            }
            elsif ($sfi_clk_config_LOCAL eq '104')
            {
                $combo_mem_info_struct .= <<"__TEMPLATE";
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}part

            {   // HW config 104Mhz Start
                $sf_misc_ctl_1_104_cs0,  // SFI_MISC_CTL
                $sf_dly_ctl_2_104_cs0,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_104_cs0,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_104_cs0,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_104_cs0,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26_cs0,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26_cs0,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs0,  // SFI_DLY_CTL_3
            }   // HW config END
        },
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Part Number'}part

            {   // HW config 104Mhz Start
                $sf_misc_ctl_1_104_cs1,  // SFI_MISC_CTL
                $sf_dly_ctl_2_104_cs1,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_104_cs1,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_104_cs1,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_104_cs1,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26_cs1,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26_cs1,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs1,  // SFI_DLY_CTL_3
            }   // HW config END
        }$comma
__TEMPLATE
            }
            elsif ($sfi_clk_config_LOCAL eq '78')
            {
                $combo_mem_info_struct .= <<"__TEMPLATE";
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}part

            {   // HW config 78Mhz Start
                $sf_misc_ctl_1_78_cs0,  // SFI_MISC_CTL
                $sf_dly_ctl_2_78_cs0,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_78_cs0,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_78_cs0,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_78_cs0,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26_cs0,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26_cs0,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs0,  // SFI_DLY_CTL_3
            }    // HW config END
        },
        {   //$MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Part Number'}part

            {   // HW config 78Mhz Start
                $sf_misc_ctl_1_78_cs1,  // SFI_MISC_CTL
                $sf_dly_ctl_2_78_cs1,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_78_cs1,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_78_cs1,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_78_cs1,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26_cs1,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26_cs1,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26_cs1,  // SFI_DLY_CTL_3
            }   // HW config END
       }$comma
__TEMPLATE
            }
        }

        ###filter duplicate part number
        for (0..$#$MCP_LIST_DUAL_SF_LOCAL)
        {
            my $duplicate_count = 0;
            while ($combo_mem_info_struct =~ /\{\s+\/\/$MCP_LIST_DUAL_SF_LOCAL->[$_]part\s+(\w*\W*){30}\w*\s+\}\W/gis)
            {
                $duplicate_count = $duplicate_count + 1;
                if ($duplicate_count > 1)
                {
                    $combo_mem_info_struct = $` . $' . "deleted";
                    # '#print "custom flash h : $&~~END~~,  , $duplicate_count\n";
                    $duplicate_count = 0;
                }
            }
            #  'print "part number : $MCP_LIST_DUAL_SF_LOCAL->[$_]\n";
        }
        ###
        $combo_mem_info_struct = $combo_mem_info_struct . "deleted";
        if ($combo_mem_info_struct =~ /\W+deleted/gis)
        {
            $combo_mem_info_struct = $` . "\n\t\t}";
            #  print "combo flash configure : $&, $combo_mem_info_struct\n";
            #  last;
        }#'
    }
    else
    {
        ### Fill-in the information of each memory

        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";

            my @device_setup_command = &split_sfi_command($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Device Setup'}->{'Command'});
            ###166MHZ setting
            my $sf_mac_ctl_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_166, $sf_dly_ctl_1_166, $sf_misc_ctl_2_166, $sf_dly_ctl_2_166);
            my ($sf_misc_ctl_1_166, $sf_direct_ctl_1_166, $sf_dly_ctl_2_166, $sf_dly_ctl_3_166, $sf_dly_ctl_4_166, $sf_dly_ctl_5_166);
            my $sf_mac_ctl_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_166, $sf_dly_ctl_1_166, $sf_misc_ctl_2_166, $sf_dly_ctl_2_166);
            my ($sf_misc_ctl_1_166, $sf_direct_ctl_1_166, $sf_dly_ctl_2_166, $sf_dly_ctl_3_166, $sf_dly_ctl_4_166, $sf_dly_ctl_5_166);
            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_misc_ctl_1_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_166 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }

            ###130MHZ setting
            my $sf_mac_ctl_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_130, $sf_dly_ctl_1_130, $sf_misc_ctl_2_130, $sf_dly_ctl_2_130);
            my ($sf_misc_ctl_1_130, $sf_direct_ctl_1_130, $sf_dly_ctl_2_130, $sf_dly_ctl_3_130, $sf_dly_ctl_4_130, $sf_dly_ctl_5_130);
            my $sf_mac_ctl_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_130, $sf_dly_ctl_1_130, $sf_misc_ctl_2_130, $sf_dly_ctl_2_130);
            my ($sf_misc_ctl_1_130, $sf_direct_ctl_1_130, $sf_dly_ctl_2_130, $sf_dly_ctl_3_130, $sf_dly_ctl_4_130, $sf_dly_ctl_5_130);
            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_misc_ctl_1_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_130 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 130, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }

            ###104MHZ setting
            my $sf_mac_ctl_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_104, $sf_dly_ctl_1_104, $sf_misc_ctl_2_104, $sf_dly_ctl_2_104);
            my ($sf_misc_ctl_1_104, $sf_direct_ctl_1_104, $sf_dly_ctl_2_104, $sf_dly_ctl_3_104, $sf_dly_ctl_4_104, $sf_dly_ctl_5_104);
            if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252')
            {
                $sf_misc_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                $sf_misc_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }
            elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_misc_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }
            else
            {
                $sf_misc_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_1_104 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_104 = "0";
                $sf_dly_ctl_2_104 = "0";
            }

            ###78MHZ setting
            my $sf_mac_ctl_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            my ($sf_misc_ctl_1_78, $sf_dly_ctl_1_78, $sf_misc_ctl_2_78, $sf_dly_ctl_2_78);
            my ($sf_misc_ctl_1_78, $sf_direct_ctl_1_78, $sf_dly_ctl_2_78, $sf_dly_ctl_3_78, $sf_dly_ctl_4_78, $sf_dly_ctl_5_78);
            if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252')
            {
                $sf_misc_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_1', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_1', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                $sf_misc_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }
            elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_misc_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_4_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_4', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_5_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_5', $MDL_INFO_LIST_LOCAL) : "0";
            }
            else
            {
                $sf_misc_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_1_78 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_2_78 = "0";
                $sf_dly_ctl_2_78 = "0";
            }

            ###13/26MHZ setting
            my ($sf_mac_ctl_13, $sf_misc_ctl_13, $sf_dly_ctl_13);
            my ($sf_mac_ctl_26, $sf_misc_ctl_26, $sf_direct_ctl_26);
            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6251'))
            {
                $sf_mac_ctl_13 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_13 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_13 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL', $MDL_INFO_LIST_LOCAL) : "0";
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                $sf_mac_ctl_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
            }
            elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                $sf_mac_ctl_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_misc_ctl_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_direct_ctl_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DIRECT_CTL', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_2_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_2', $MDL_INFO_LIST_LOCAL) : "0";
                $sf_dly_ctl_3_26 = (defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 26, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_DLY_CTL_3', $MDL_INFO_LIST_LOCAL) : "0";
            }

            if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6251'))
            {
                $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 104Mhz Start
                $sf_mac_ctl_104,  // SF_MAC_CTL
                $sf_misc_ctl_1_104,  // SF_MISC_CTL
                $sf_dly_ctl_1_104,  // SF_DLY_CTL
                $sf_dly_ctl_2_104,  // SF_MISC_CTL
                $sf_dly_ctl_2_104,  // SF_DLY_CTL
            },  // HW config End
            {   // HW config 78Mhz Start
                $sf_mac_ctl_78,  // SF_MAC_CTL
                $sf_misc_ctl_1_78,  // SF_MISC_CTL
                $sf_dly_ctl_1_78,  // SF_DLY_CTL
                $sf_dly_ctl_2_78,  // SF_MISC_CTL
                $sf_dly_ctl_2_78,  // SF_DLY_CTL
            },  // HW config End
            {   // HW config 13Mhz Start
                $sf_mac_ctl_13,  // SF_MAC_CTL
                $sf_misc_ctl_13,  // SF_MISC_CTL
                $sf_dly_ctl_13,  // SF_DLY_CTL
            }  // HW config End

        }$comma
__TEMPLATE
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 104Mhz Start
                $sf_misc_ctl_1_104,  // SF_MISC_CTL
                $sf_dly_ctl_2_104,  // SF_DLY_2_CTL
                $sf_dly_ctl_3_104,  // SF_DLY_3_CTL
                $sf_dly_ctl_4_104,  // SF_DLY_4_CTL
                $sf_dly_ctl_5_104,  // SF_DLY_5_CTL
            },  // HW config End
            {   // HW config 78Mhz Start
                $sf_misc_ctl_1_78,  // SF_MISC_CTL
                $sf_dly_ctl_2_78,  // SF_DLY_2_CTL
                $sf_dly_ctl_3_78,  // SF_DLY_3_CTL
                $sf_dly_ctl_4_78,  // SF_DLY_4_CTL
                $sf_dly_ctl_5_78,  // SF_DLY_5_CTL
            },  // HW config End
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26,  // SF_MISC_CTL
                $sf_dly_ctl_2_26,  // SF_DLY_2_CTL
                $sf_dly_ctl_3_26,  // SF_DLY_3_CTL
            }  // HW config End

        }$comma
__TEMPLATE
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6250')
            {
                if ($sfi_clk_config_LOCAL eq '130')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 130Mhz Start
                $sf_misc_ctl_1_130,  // SFI_MISC_CTL
                $sf_dly_ctl_2_130,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_130,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_130,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_130,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,  // SFI_DLY_CTL_3
            }   // HW config END
        }$comma
__TEMPLATE
                }
                elsif ($sfi_clk_config_LOCAL eq '104')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 104Mhz Start
                $sf_misc_ctl_1_104,  // SFI_MISC_CTL
                $sf_dly_ctl_2_104,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_104,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_104,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_104,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,  // SFI_DLY_CTL_3
            }  // HW config END
        }$comma
__TEMPLATE
                }
                elsif ($sfi_clk_config_LOCAL eq '78')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 78Mhz Start
                $sf_misc_ctl_1_78,  // SFI_MISC_CTL
                $sf_dly_ctl_2_78,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_78,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_78,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_78,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,  // SFI_DLY_CTL_3
            }  // HW config END
       }$comma
__TEMPLATE
                }
            }
            elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6260') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6261') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2501') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT2502'))
            {
                if ($sfi_clk_config_LOCAL eq '130')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 130Mhz Start
                $sf_misc_ctl_1_130,  // SFI_MISC_CTL
                $sf_dly_ctl_2_130,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_130,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_130,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_130,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,  // SFI_DLY_CTL_3
            }   // HW config END
        }$comma
__TEMPLATE
                }
                elsif ($sfi_clk_config_LOCAL eq '166')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 166Mhz Start
                $sf_misc_ctl_1_166,  // SFI_MISC_CTL
                $sf_dly_ctl_2_166,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_166,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_166,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_166,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,  // SFI_DLY_CTL_3
            }  // HW config END
        }$comma
__TEMPLATE
                }
                elsif ($sfi_clk_config_LOCAL eq '104')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 104Mhz Start
                $sf_misc_ctl_1_104,  // SFI_MISC_CTL
                $sf_dly_ctl_2_104,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_104,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_104,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_104,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,  // SFI_DLY_CTL_3
            }  // HW config END
        }$comma
__TEMPLATE
                }
                elsif ($sfi_clk_config_LOCAL eq '78')
                {
                    $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 78Mhz Start
                $sf_misc_ctl_1_78,  // SFI_MISC_CTL
                $sf_dly_ctl_2_78,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_78,  // SFI_DLY_CTL_3
                $sf_dly_ctl_4_78,  // SFI_DLY_CTL_4
                $sf_dly_ctl_5_78,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                $sf_misc_ctl_26,  // SFI_MISC_CTL
                $sf_dly_ctl_2_26,  // SFI_DLY_CTL_2
                $sf_dly_ctl_3_26,  // SFI_DLY_CTL_3
            }  // HW config END
       }$comma
__TEMPLATE
                }
            }
        }
    }



    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_SFI__
#define __CUSTOM_SFI__

/*
 ****************************************************************************
 Specify the chip select configuration
 Possible choices, NOR_FLASH, RAM, LPSDRAM, UNUSED
 ****************************************************************************
*/

/*
 ****************************************************************************
 Specify RAM size in Bytes
 ****************************************************************************
*/


/*
 ****************************************************************************
 Define the driving and cache/prefetch setting (optional)
 ****************************************************************************
*/

$sfi_clk_str

#define __SFI_DCM_COMBO_INDEX_UND   0xffffffff

#if defined(MT6252) || defined(MT6251)
typedef enum {
    SFC_MAC_CTL            = 0x0      // Write Enable Latch
   ,SFC_MISC_CTL_1         = 0x1      // Write Suspend Program Status
   ,SFC_DLY_CTL_1          = 0x2      // Security ID status (Once set by Lock Security ID (0x85h) it can not be reset)
   ,SFC_DR_CTL             = 0x3      // Write operation status (Write In Progress Bit)
   ,SFC_Driving_1          = 0x4      // Write operation status (Write In Progress Bit)
   ,SFC_Driving_2          = 0x5      // Write operation status (Write In Progress Bit)
   ,SFC_Reserved           = 0x6      // Write operation status (Write In Progress Bit)
   ,SFC_MISC_CTL_2         = 0x7      // Write Protection Lockdown Status (Resets to 0 after a power cycle)
   ,SFC_DLY_CTL_2          = 0x8      // Write operation status (Write In Progress Bit)
} SF_SFC_Control_Reg_Enum;

#elif defined(MT6255)
typedef enum {
    SFC_MAC_CTL            = 0x0      // Write Enable Latch
   ,SFC_DR_CTL             = 0x1      // Write Suspend Program Status
   ,SFC_MISC_CTL           = 0x2      // Security ID status (Once set by Lock Security ID (0x85h) it can not be reset)
   ,SFC_DLY_CTL2           = 0x3      // Write operation status (Write In Progress Bit)
   ,SFC_DLY_CTL3           = 0x4      // Write operation status (Write In Progress Bit)
   ,SFC_Driving            = 0x5      // Write operation status (Write In Progress Bit)
   ,SFC_Reserved           = 0x6      // Write operation status (Write In Progress Bit)
   ,SFC_DLY_CTL4           = 0x7      // Write operation status (Write In Progress Bit)
   ,SFC_DLY_CTL5           = 0x8      // Write operation status (Write In Progress Bit)
} SF_SFC_Control_Reg_Enum;

#elif defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
typedef enum {
    SFC_MAC_CTL            = 0x0
   ,SFC_DR_CTL             = 0x1
   ,SFC_MISC_CTL           = 0x2
   ,SFC_MISC_CTL2          = 0x3
   ,SFC_DLY_CTL2           = 0x4
   ,SFC_DLY_CTL3           = 0x5
   ,SFC_Driving            = 0x6
   ,SFC_Reserved           = 0x7
   ,SFC_DLY_CTL4           = 0x8
   ,SFC_DLY_CTL5           = 0x9
} SF_SFC_Control_Reg_Enum;
#endif

#define ProcessID       ((volatile UINT32P)(EFUSE_base+0x0024))  /* Chip ID register 3 */

#if defined(MT6251)
#define ACIF_CON4       ((volatile UINT16P)(CONFIG_base+0x718))
#define ACIF_CON5       ((volatile UINT16P)(CONFIG_base+0x71C))
//#define SFI_CLOCK     78

#elif defined(MT6253L)||defined(MT6252)
#define ACIF_CON0       ((volatile UINT32P)(CONFIG_base+0x700))

#elif defined(MT6255)
#define IO_DRV2         ((volatile UINT32P)(CONFIG_base+0x508))
#define SFC_CTRL_SET    ((volatile UINT32P)(CONFIG_base+0x61C))
#define VSF_CON0        ((volatile UINT16P)(MIXED_base+0x700))
#define VSF_CON3        ((volatile UINT16P)(MIXED_base+0x70C))

#elif defined(MT6250)
#define GPIO_DRV0           ((volatile UINT16P)(GPIO_base+0x800))
#define SFC_EFUSE           ((volatile UINT32P)(EFUSE_base+0x108))
#define GPIO_SF2            (GPIO_base+0xC92)
#define GPIO_SF2_Enable     (0x00111117)

#define GPIO_DRV0_OFFSET            (8)
#define GPIO_DRV0_SIZE              (3)
#define GPIO_DRV0_MASK              (0x0700)
#define SFIFO_WR_EN_DLY_SEL_OFFSET  (24)

#define SFC_DRIVING_OFFSET          (0)
#define SFC_DRIVING_SIZE            (3)
#define SFC_INPUT0_DLY_OFFSET       (3)
#define SFC_INPUT0_DLY_SIZE         (2)
#define SFC_INPUT1_DLY_OFFSET       (5)
#define SFC_INPUT1_DLY_SIZE         (2)
#define SFC_INPUT2_DLY_OFFSET       (7)
#define SFC_INPUT2_DLY_SIZE         (2)
#define SFC_INPUT3_DLY_OFFSET       (9)
#define SFC_INPUT3_DLY_SIZE         (2)
#define SFC_SAMPLECLK_DLY_OFFSET    (11)
#define SFC_SAMPLECLK_DLY_SIZE      (6)

#define SFC_GET_EfuseBits(offset, size)         ((*SFC_EFUSE <<(32 - (offset+size))) >> (32-size))
#define SFC_IS_NEGATIVE(number, size)           (number &(1<<(size-1)))
#define SFC_NEGATIVE_TO_POSITIVE(number, size)  ((1<<size)-number)

#elif defined(MT6260)
/* SFC clock registers */
#define PDN_COND2           (CONFIG_base + 0x308)
#define PDN_SETD2           (CONFIG_base + 0x318)
#define PDN_CLRD2           (CONFIG_base + 0x328)
#define RG_SFC_SW_CG        (0x0800)

/* SFC pad switch register */
#define HW_MISC2            (CONFIG_base + 0x230)
#define PAD_SWITCH          (0x0001)

/* SF GPIO registers*/
#define SF_GPIO_MODE8       (GPIO_base + 0xc80)
#define SF_GPIO_MODE9       (GPIO_base + 0xc90)
#define SF_GPIO_MODE8_CLR   (0x00000077) //Clear mode setting of GPIO 66 to 71
#define SF_GPIO_MODE9_CLR   (0x77777770) //Clear mode setting of GPIO 72
#define SF_GPIO66           (0x00000100) //SFSCS1 not use in BootROM
#define SF_GPIO67           (0x00001000) //SFSWP
#define SF_GPIO68           (0x00010000) //SFSCS0
#define SF_GPIO69           (0x00100000) //SFSCK
#define SF_GPIO70           (0x01000000) //SFSIN
#define SF_GPIO71           (0x10000000) //SFSOUT
#define SF_GPIO72           (0x00000001) //SFSHOLD
#define GPIO_RESEN1         (GPIO_base + 0xb10)
#define GPIO_RESEN2         (GPIO_base + 0xb20)
#define GPIO_RESEN4         (GPIO_base + 0xb40)
#define GPIO_RESEN5         (GPIO_base + 0xb50)

#define SF_SLT_MODE_R0_R1_SET           (0x1F80) //GPIO_R1[12:7] and GPIO_R4[12:7]
#define SF_NORMAL_MODE_R0_R1_SET1       (0xE000) //GPIO_R1[15:13] and GPIOR4[15:13]
#define SF_NORMAL_MODE_R0_R1_Dual_SET   (0x2000) //GPIO_R1[13] and GPIOR4[13]
#define SF_NORMAL_MODE_R0_R1_SET2       (0x000F) //GPIO_R2[3:0] and GPIO_R5[3:0]


/* SFC Driving registers */
#define GPIO_DRV0           ((volatile UINT16P)(GPIO_base+0x800))


/* SFC Dual SF registers */
#define GPIO_SF2_Enable     (0x00000100)

/* SFC SLT registers */
#define SF_NORMAL_MODE      (0x00000001)
#define SF_SLT_MODE         (0x00000002)
#define SF_SLT_MODE_MASK    (0x00000007)


/* SFC foundry porting registers */
#define SFC_EFUSE           ((volatile UINT32P)(EFUSE_base+0x108))

#define GPIO_DRV0_OFFSET            (8)
#define GPIO_DRV0_SIZE              (3)
#define GPIO_DRV0_MASK              (0x0700)
#define SFIFO_WR_EN_DLY_SEL_OFFSET  (24)

#define SFC_DRIVING_OFFSET          (0)
#define SFC_DRIVING_SIZE            (3)
#define SFC_INPUT0_DLY_OFFSET       (3)
#define SFC_INPUT0_DLY_SIZE         (2)
#define SFC_INPUT1_DLY_OFFSET       (5)
#define SFC_INPUT1_DLY_SIZE         (2)
#define SFC_INPUT2_DLY_OFFSET       (7)
#define SFC_INPUT2_DLY_SIZE         (2)
#define SFC_INPUT3_DLY_OFFSET       (9)
#define SFC_INPUT3_DLY_SIZE         (2)
#define SFC_SAMPLECLK_DLY_OFFSET    (11)
#define SFC_SAMPLECLK_DLY_SIZE      (6)

#define SFC_GET_EfuseBits(offset, size)         ((*SFC_EFUSE <<(32 - (offset+size))) >> (32-size))
#define SFC_IS_NEGATIVE(number, size)           (number &(1<<(size-1)))
#define SFC_NEGATIVE_TO_POSITIVE(number, size)  ((1<<size)-number)

#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
/* SF GPIO registers*/
#define SFIO_CFG0           (CONFIG_base + 0x600)
#define SFIO_CFG1           (CONFIG_base + 0x604)
#define SFIO_CFG2           (CONFIG_base + 0x608)
#define SF_NORMAL_HIGHZ     (0xFFCFFFCF)
#define GPIO_RESEN0_1       (GPIO_base + 0xb10)
#define GPIO_RESEN1_1       (GPIO_base + 0xb30)
#define SF_SLT_HIGHZ        (0xFFF81FFF)
#define GPIO_DRV1           (GPIO_base + 0x810)
#define SF_SLT_DRIVING_CLR  (0xFF3FFFFF)
#define SF_SLT_DRIVING_12mA (0xFF8FFFFF)

/* SFC Driving registers */
#define SFIO_CFG0_DRV       ((volatile UINT32P)(CONFIG_base+0x600))
#define SFIO_CFG1_DRV       ((volatile UINT32P)(CONFIG_base+0x604))
#define SFIO_CFG2_DRV       ((volatile UINT32P)(CONFIG_base+0x608))


/* SFC SLT registers */
#define SF_NORMAL_MODE      (0x00000001)
#define SF_SLT_MODE         (0x00000002)
#define SF_SLT_MODE_MASK    (0x00000007)


#elif defined(MT6280)
#define GPIO_DRV6           ((volatile UINT16P)(GPIO_base+0x3500))
#define GPIO84_MODE_SFIO2   (2)
#define GPIO85_MODE_SFIO1   (2)
#define GPIO86_MODE_SFIO0   (2)
#define GPIO87_MODE_SFCS    (2)
#define GPIO88_MODE_SFCLK   (2)
#define GPIO89_MODE_SFIO3   (2)

#define GPIO_MODE_BASE          (GPIO_base + 0x1000)
#define GPIO_GET_MODE(_n)       *(U16 *)(GPIO_MODE_BASE + (_n >> 2) * 0x100)
#define GPIO_SET_MODE(_n, mode) *(U16 *)(GPIO_MODE_BASE + (_n >> 2) * 0x100) =  \
                                (*(U16*)(GPIO_MODE_BASE + (_n >> 2) * 0x100) & (~(0xF << (4 * (_n & 0x3))))) | (mode << (4 * (_n & 0x3)))
#endif


static const CMEMEntrySFIList_dcm combo_mem_hw_list_dcm = {   // (to be renamed by SFI owner)

    //COMBO_SFI_VER,           // SFI structure version
    //COMBO_MEM_ENTRY_COUNT,   // defined in custom_Memorydevice.h
    {

$combo_mem_info_struct
    }
};

/*
 ****************************************************************************
 Specify the related EMI Setting
 ****************************************************************************
*/

/*
 ****************************************************************************
 Specify additional information
 ****************************************************************************
*/

#endif /* __CUSTOM_SFI__ */

__TEMPLATE
}

#****************************************************************************
# subroutine:  combo_sfi_config_h_file_body
# return:
#****************************************************************************
sub combo_snand_config_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $snand_clk_config_LOCAL, $MCP_LIST_DUAL_SF_LOCAL) = @_;
    my $combo_mem_info_struct;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";
        my $devinit_104;
        my $spare_format;
        ###SPI_NAND register setting
        $snand_dly_ctl_1_104 = (defined &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL1', $MDL_INFO_LIST_LOCAL) and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL1', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL1', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL1', $MDL_INFO_LIST_LOCAL) : "0";
        $snand_dly_ctl_2_104 = (defined &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL2', $MDL_INFO_LIST_LOCAL) and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL2', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL2', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL2', $MDL_INFO_LIST_LOCAL) : "0";
        $snand_dly_ctl_3_104 = (defined &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL3', $MDL_INFO_LIST_LOCAL) and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL3', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL3', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL3', $MDL_INFO_LIST_LOCAL) : "0";
        $snand_dly_ctl_4_104 = (defined &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL4', $MDL_INFO_LIST_LOCAL) and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL4', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL4', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_DLY_CTL4', $MDL_INFO_LIST_LOCAL) : "0";
        $snand_misc_ctl_104 = (defined &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_MISC_CTL', $MDL_INFO_LIST_LOCAL) and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_MISC_CTL', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SNF_MISC_CTL', $MDL_INFO_LIST_LOCAL) : "0";
        $snand_driving_104 = (defined &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne 'x' and &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) ne ' ') ? &Lookup_SNAND_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', $MDL_INFO_LIST_LOCAL) : "0";
        print "MDL info : $MDL_INFO_LIST_LOCAL->[1]->{0}->{'NAND Size (Mb)'}\n";
        ###SPI NAND flash info
        $spare_format = "SNAND_SPARE_FORMAT_" . $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Spare Format'};
        $devinit_104 .= <<"__TEMPLATE1";
            SNAND_COMMAND_SERIES_COMMON,                             // command_series
            $spare_format,                                           // spare_format
            $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NAND Size (Mb)'},      // total_size_mbits
            $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NAND Block Size(KB)'}, // block_size_kbytes
            $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NAND Page Size(B)'},   // page_size_bytes
            $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NAND Spare Size(B)'},  // spare_size_bytes
            $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NAND Plane Number'}    // plane_number
__TEMPLATE1

        ###SPI_NAND TEMPLATE
        $combo_mem_info_struct .= <<"__TEMPLATE";
        {   // $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}
            {   // HW config 104Mhz Start
                $snand_dly_ctl_1_104,           // SNAND_AUTOGEN_REG_SNF_DLY_CTL1
                $snand_dly_ctl_2_104,           // SNAND_AUTOGEN_REG_SNF_DLY_CTL2
                $snand_dly_ctl_3_104,           // SNAND_AUTOGEN_REG_SNF_DLY_CTL3
                $snand_dly_ctl_4_104,           // SNAND_AUTOGEN_REG_SNF_DLY_CTL4
                $snand_misc_ctl_104,           // SNAND_AUTOGEN_REG_SNF_MISC_CTL
                $snand_driving_104,           // SNAND_AUTOGEN_REG_DRIVING
            },  // HW config End
$devinit_104
        }$comma
__TEMPLATE
    }
    ###
    my $template = <<"__TEMPLATE";
//-----------------------------------------------------------------------------
// MCP Serial Flash HW settings (for ComboMEM only, do not include this header)
//-----------------------------------------------------------------------------
static const CMEMEntrySNANDList combo_mem_hw_list =
{
    "COMBO_MEM_SNAND",
    COMBO_SNAND_VER,            // SNAND structure version
    SNAND_COMBO_COUNT,          // defined in custom_Memorydevice.h
    {
$combo_mem_info_struct
    }
};

__TEMPLATE

}


#****************************************************************************
# subroutine:  split_sfi_command
# return:      List of SFI commands
# input:       $command_str: Excel value to be split
#****************************************************************************
sub split_sfi_command
{
    my ($command_str) = @_;
    my @ret_command;

    while ($command_str =~ /(\{.+\})/)
    {
        my $tmp_str = $1;
        $command_str = $';
        $tmp_str =~ s/\{//;  # remove parentheses
        $tmp_str =~ s/\}//;  # remove parentheses
        $tmp_str =~ s/\s+//g;  # remove spaces
        ### parse the driving string
        my $saved_sep = $/;
        undef $/;
        my @tmp_list = split(/\,/, $tmp_str);
        $/ = $saved_sep;

        ### for commands {SPI, 0x35}, output "SPI, 1, 0x35", where 1 is the number of commands
        if ($tmp_list[0] eq 'SPI' or $tmp_list[0] eq 'QPI')
        {
            push @ret_command, $tmp_list[0];
            push @ret_command, $#tmp_list;
            for (1..$#tmp_list)
            {
                push @ret_command, $tmp_list[$_];
            }
        }
        else
        {
            &error_handler("$MEMORY_DEVICE_LIST_XLS_E: Unknown SFI commands $command_str!", __FILE__, __LINE__);
        }
    }

    return @ret_command;

}

#****************************************************************************
# subroutine:  split_sfi_driving
# return:      List of SFI driving
# input:       $driving_str: Excel value to be split
#****************************************************************************
sub split_sfi_driving
{
    my ($driving_str) = @_;
    my @ret_driving;

    $driving_str =~ s/\{//;  # remove parentheses
    $driving_str =~ s/\}//;  # remove parentheses
    $driving_str =~ s/\s+//g;  # remove spaces
    ### parse the driving string
    my $saved_sep = $/;
    undef $/;
    @ret_driving = split(/\,/, $driving_str);
    $/ = $saved_sep;

    return @ret_driving;
}

#****************************************************************************
# subroutine:  sfi_dev_init
# input:       $dev_setup_list_href:     hash reference of Device Setup Command list
#              $dev_set_burst_list_href: hash reference of Device Set Burst list
#              $max_cmd:                 maximum number of commands
# return:      template of DevInit part in CMEMEntrySFI structure in combo_sfi_config.h
#****************************************************************************
sub sfi_dev_init
{
    my ($dev_setup_list_href, $dev_set_burst_list_href, $max_cmd) = @_;
    my $ret_template;

    for (0..($max_cmd-1))
    {
        if (($_%8) == 0)
        {
            $ret_template .= "                ";
        }

        if (defined $dev_setup_list_href->[$_])
        {
            $ret_template .= ($dev_setup_list_href->[$_] eq 'x') ? "0" : "$dev_setup_list_href->[$_]";
        }
        elsif (defined $dev_set_burst_list_href->[$_ - ($#$dev_setup_list_href+1)])
        {
            $ret_template .= ($dev_set_burst_list_href->[$_ - ($#$dev_setup_list_href+1)] eq 'x') ? "0" : "$dev_set_burst_list_href->[$_ - ($#$dev_setup_list_href+1)]";
        }
        else
        {
            if ($_ == (($#$dev_setup_list_href + 1) + ($#$dev_set_burst_list_href + 1)))
            {
                $ret_template .= "SF_UNDEF";
            }
            else
            {
                $ret_template .= "0";
            }
        }

        if ($_ < ($max_cmd-1))
        {
            if (($_%8) == 7)
            {
                $ret_template .= ",\n";
            }
            else
            {
                $ret_template .= ", ";
            }
        }
    }

    return $ret_template;
}

#****************************************************************************
# subroutine:  custom_sfi_clock_h
# input:       $dev_setup_list_href:     hash reference of Device Setup Command list
#              $dev_set_burst_list_href: hash reference of Device Set Burst list
#              $max_cmd:                 maximum number of commands
# return:      template of DevInit part in CMEMEntrySFI structure in custom_sfi_clock.h
#****************************************************************************
sub custom_sfi_clock_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $sfi_clk_config_LOCAL) = @_;
    print "clock str:$sfi_clk_config_LOCAL\n";
    my $sfi_clk_str_temp = sprintf("#define __SFI_CLK_%sMHZ__", $sfi_clk_config_LOCAL);

    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_SFI_CLOCK__
#define __CUSTOM_SFI_CLOCK__

$sfi_clk_str_temp

#endif  /* __CUSTOM_SFI_CLOCK__ */

__TEMPLATE

}

sub PrintDependency
{
    my $file = shift;
    if (-e $file)
    {
        $file = Win32::GetCwd() . "\\" . $file if (index($file, Win32::GetCwd()) != 0);
        $file =~ s/\//\\/g;
        print STDERR "[Dependency] $file\n";
    }
}

