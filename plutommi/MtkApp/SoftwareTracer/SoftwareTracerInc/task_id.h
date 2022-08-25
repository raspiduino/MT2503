


/*****************************************************************************
 * FUNCTION
 *  mmi_swtr_task_name_2_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
int mmi_swtr_task_name_2_id(char *task_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!strcmp(AUX, task_name))
    {
        return 0;
    }

    if (!strcmp(BCHS, task_name))
    {
        return 1;
    }

    if (!strcmp(BT, task_name))
    {
        return 2;
    }

    if (!strcmp(CAMERA, task_name))
    {
        return 3;
    }

    if (!strcmp(CC, task_name))
    {
        return 4;
    }

    if (!strcmp(CISS, task_name))
    {
        return 5;
    }

    if (!strcmp(CMUX, task_name))
    {
        return 6;
    }

    if (!strcmp(DATA, task_name))
    {
        return 7;
    }

    if (!strcmp(DHCP, task_name))
    {
        return 8;
    }

    if (!strcmp(DM, task_name))
    {
        return 9;
    }

    if (!strcmp(DRMT, task_name))
    {
        return 10;
    }

    if (!strcmp(DRVBMT, task_name))
    {
        return 11;
    }

    if (!strcmp(DRVKBD, task_name))
    {
        return 12;
    }

    if (!strcmp(DRVTEST, task_name))
    {
        return 13;
    }

    if (!strcmp(DT, task_name))
    {
        return 14;
    }

    if (!strcmp(DUMMYL1, task_name))
    {
        return 15;
    }

    if (!strcmp(DUMMYMPAL, task_name))
    {
        return 16;
    }

    if (!strcmp(DUMMYRR, task_name))
    {
        return 17;
    }

    if (!strcmp(EMAIL, task_name))
    {
        return 18;
    }

    if (!strcmp(FMT, task_name))
    {
        return 19;
    }

    if (!strcmp(GDC, task_name))
    {
        return 20;
    }

    if (!strcmp(GDD, task_name))
    {
        return 21;
    }

    if (!strcmp(IDLE, task_name))
    {
        return 22;
    }

    if (!strcmp(IDLER, task_name))
    {
        return 23;
    }

    if (!strcmp(IMPS, task_name))
    {
        return 24;
    }

    if (!strcmp(IPERF, task_name))
    {
        return 25;
    }

    if (!strcmp(IPERF2, task_name))
    {
        return 26;
    }

    if (!strcmp(IPERF3, task_name))
    {
        return 27;
    }

    if (!strcmp(IPERF4, task_name))
    {
        return 28;
    }

    if (!strcmp(IRCOMM, task_name))
    {
        return 29;
    }

    if (!strcmp(IRDA, task_name))
    {
        return 30;
    }

    if (!strcmp(JDAEMON, task_name))
    {
        return 31;
    }

    if (!strcmp(JVM, task_name))
    {
        return 32;
    }

    if (!strcmp(L1, task_name))
    {
        return 33;
    }

    if (!strcmp(L1AUDIO, task_name))
    {
        return 34;
    }

    if (!strcmp(L4, task_name))
    {
        return 35;
    }

    if (!strcmp(LLC, task_name))
    {
        return 36;
    }

    if (!strcmp(MED, task_name))
    {
        return 37;
    }

    if (!strcmp(MM, task_name))
    {
        return 38;
    }

    if (!strcmp(MMI, task_name))
    {
        return 39;
    }

    if (!strcmp(NVRAM, task_name))
    {
        return 40;
    }

    if (!strcmp(OBEX, task_name))
    {
        return 41;
    }

    if (!strcmp(POC, task_name))
    {
        return 42;
    }

    if (!strcmp(PPP, task_name))
    {
        return 43;
    }

    if (!strcmp(REASM, task_name))
    {
        return 44;
    }

    if (!strcmp(RR, task_name))
    {
        return 45;
    }

    if (!strcmp(RTSP, task_name))
    {
        return 46;
    }

    if (!strcmp(SAF, task_name))
    {
        return 47;
    }

    if (!strcmp(SIM, task_name))
    {
        return 48;
    }

    if (!strcmp(SIP, task_name))
    {
        return 49;
    }

    if (!strcmp(SM, task_name))
    {
        return 50;
    }

    if (!strcmp(SMS, task_name))
    {
        return 51;
    }

    if (!strcmp(SNDCP, task_name))
    {
        return 52;
    }

    if (!strcmp(SOC, task_name))
    {
        return 53;
    }

    if (!strcmp(SSDBG1, task_name))
    {
        return 54;
    }

    if (!strcmp(SSDBG2, task_name))
    {
        return 55;
    }

    if (!strcmp(SUPC, task_name))
    {
        return 56;
    }

    if (!strcmp(SYNCML, task_name))
    {
        return 57;
    }

    if (!strcmp(SYSDEBUG, task_name))
    {
        return 58;
    }

    if (!strcmp(TCPIP, task_name))
    {
        return 59;
    }

    if (!strcmp(TFTP, task_name))
    {
        return 60;
    }

    if (!strcmp(TP_TASK, task_name))
    {
        return 61;
    }

    if (!strcmp(TR, task_name))
    {
        return 62;
    }

    if (!strcmp(TST, task_name))
    {
        return 63;
    }

    if (!strcmp(USB, task_name))
    {
        return 64;
    }

    if (!strcmp(VIDEO, task_name))
    {
        return 65;
    }

    if (!strcmp(VOIP, task_name))
    {
        return 66;
    }

    if (!strcmp(VUART, task_name))
    {
        return 67;
    }

    if (!strcmp(WAP, task_name))
    {
        return 68;
    }

    if (!strcmp(WNDRV, task_name))
    {
        return 69;
    }

    if (!strcmp(WPS, task_name))
    {
        return 70;
    }

    if (!strcmp(XDM, task_name))
    {
        return 71;
    }

    return (-1 * 72);
}

