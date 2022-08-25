#include <windows.h>
#include "kal_release.h"
#include "fat_fs.h"
#include "w32_file_disk.h"
#include "flash_opt.h"
#include "drvflash.h"

#define CRITICAL_SECTION_BEGIN   OSC_Sys_Schedule_Enable(0)
#define CRITICAL_SECTION_END     OSC_Sys_Schedule_Enable(1)

#define FILE_DISK_PATH	"\\WIN32FS\\"

#ifdef NAND_SUPPORT

#if   defined(_NAND_FLASH_BOOTING_)
#define NAND_FLASH_SIZE NAND_BOOTING_NAND_FS_SIZE
#define NOR_FLASH_SIZE 	0
#elif defined(__FS_SYSDRV_ON_NAND__)
#define NAND_FLASH_SIZE NAND_BOOTING_NAND_FS_SIZE
#define NOR_FLASH_SIZE 	0
#else
#define NAND_FLASH_SIZE NOR_BOOTING_NAND_FS_SIZE
#define NOR_FLASH_SIZE 	NOR_ALLOCATED_FAT_SPACE
#endif

#else

#define NOR_FLASH_SIZE 	NOR_ALLOCATED_FAT_SPACE
#define NAND_FLASH_SIZE 0

#endif /* NAND_SUPPORT */

/* system drive name */
#define FILE_DISK_DRIVE		L'C'

/* bytes per sector */
#define FILE_DISK_BYTES_PER_SECTOR 512

kal_uint8 fssim_root_dir[FS_MAX_PATH];

/*
 * Array of drives' information.
 */
FILE_DISK_INFO_T file_disk_info[MAX_FILE_DISK + 1] =
{
	{"nor_disk",   FILE_DISK_DRIVE + NOR_DISK,   FS_DEVICE_TYPE_NOR,  FILE_DISK_BYTES_PER_SECTOR, NOR_FLASH_SIZE / 512, 0, 0 },
	{"nand_disk",  FILE_DISK_DRIVE + NAND_DISK,  FS_DEVICE_TYPE_NAND, FILE_DISK_BYTES_PER_SECTOR, NAND_FLASH_SIZE / 512, 0, 0 },
	{"nand_disk1", FILE_DISK_DRIVE + NAND_DISK1, FS_DEVICE_TYPE_NAND, FILE_DISK_BYTES_PER_SECTOR, 271560, 0, 0 },
	{"nand_disk2", FILE_DISK_DRIVE + NAND_DISK2, FS_DEVICE_TYPE_NAND, FILE_DISK_BYTES_PER_SECTOR, 271560, 0, 0 },
	{"nand_disk3", FILE_DISK_DRIVE + NAND_DISK3, FS_DEVICE_TYPE_NAND, FILE_DISK_BYTES_PER_SECTOR, 271560, 0, 0 },
	{"nand_disk4", FILE_DISK_DRIVE + NAND_DISK4, FS_DEVICE_TYPE_NAND, FILE_DISK_BYTES_PER_SECTOR, 271560, 0, 0 },
	{"nand_disk5", FILE_DISK_DRIVE + NAND_DISK5, FS_DEVICE_TYPE_NAND, FILE_DISK_BYTES_PER_SECTOR, 271560, 0, 0 },
	{"nand_disk6", FILE_DISK_DRIVE + NAND_DISK6, FS_DEVICE_TYPE_NAND, FILE_DISK_BYTES_PER_SECTOR, 271560, 0, 0 },
	{"nand_disk7", FILE_DISK_DRIVE + NAND_DISK7, FS_DEVICE_TYPE_NAND, FILE_DISK_BYTES_PER_SECTOR, 271560, 0, 0 },

	{"card_disk0", FILE_DISK_DRIVE + CARD_DISK,  FS_DEVICE_TYPE_CARD, FILE_DISK_BYTES_PER_SECTOR, 4194304*5, 0, 0 },
    {"card_disk1", FILE_DISK_DRIVE + CARD_DISK1, FS_DEVICE_TYPE_CARD, FILE_DISK_BYTES_PER_SECTOR, 4194304*5, 0, 0 },
	/* The number of supported OTG devices is not configurable */
	{"otg_disk",   FILE_DISK_DRIVE + OTG_DISK,  FS_DEVICE_TYPE_CARD, FILE_DISK_BYTES_PER_SECTOR, 4194304, 0, 0 },
	{"otg_disk1",  FILE_DISK_DRIVE + OTG_DISK1, FS_DEVICE_TYPE_CARD, FILE_DISK_BYTES_PER_SECTOR, 4194304, 0, 0 },
	{"otg_disk2",  FILE_DISK_DRIVE + OTG_DISK2, FS_DEVICE_TYPE_CARD, FILE_DISK_BYTES_PER_SECTOR, 4194304, 0, 0 },
	{"otg_disk3",  FILE_DISK_DRIVE + OTG_DISK3, FS_DEVICE_TYPE_CARD, FILE_DISK_BYTES_PER_SECTOR, 4194304, 0, 0 },
	{"otg_disk4",  FILE_DISK_DRIVE + OTG_DISK4, FS_DEVICE_TYPE_CARD, FILE_DISK_BYTES_PER_SECTOR, 4194304, 0, 0 },
	{"otg_disk5",  FILE_DISK_DRIVE + OTG_DISK5, FS_DEVICE_TYPE_CARD, FILE_DISK_BYTES_PER_SECTOR, 4194304, 0, 0 },
	{"otg_disk6",  FILE_DISK_DRIVE + OTG_DISK6, FS_DEVICE_TYPE_CARD, FILE_DISK_BYTES_PER_SECTOR, 4194304, 0, 0 },
	{"otg_disk7",  FILE_DISK_DRIVE + OTG_DISK7, FS_DEVICE_TYPE_CARD, FILE_DISK_BYTES_PER_SECTOR, 4194304, 0, 0 },

	{0, 0, 0, 0, 0, 0, 0 }
};

kal_uint32 gFileDiskBuffer[128] = {0};

static int SelfFormat(void * DriveData, FS_PartitionRecord	 *Partition);
static int FileDisk_Format(void * DriveData, kal_uint32 first_sectors);


// Release .\mcu\MoDIS_VC9\MoDIS\Release\MoDIS.exe
// Debug   .\mcu\MoDIS_VC9\MoDIS\Debug\MoDIS.exe
// Image Path .\mcu\MoDIS_VC9\WIN32FS

static char *FileDisk_LocateImageDir(char *dir_name)
{
    kal_char *pch = NULL;

    do {
        // Remove last three parent folders
        pch=strrchr(dir_name, '\\');
        if (pch==NULL) break;
        *pch=0;
        pch=strrchr(dir_name, '\\');
        if (pch==NULL) break;
        *pch=0;
        pch=strrchr(dir_name, '\\');
        if (pch==NULL) break;
        *pch=0;        
        // Concat "\WIN32FS\"
        strcat(dir_name, FILE_DISK_PATH);
        return pch;
    } while (0);

    printf("Error: Invalid execution path, please execute Modis in Modis_VC9\\MoDIS\\Debug\\ or Modis_VC9\\MoDIS\\Release\\ \n");
    return NULL;
}

#ifndef _NAND_FLASH_BOOTING_
//============================================================================================
// nor disk driver
//============================================================================================
int  FileDiskNor_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, UINT Flags)
{
	FILE *fd;
	printf("[FS] FileDiskNor_MountDevice\n");

	if(file_disk_info[NOR_DISK].file_handle == NULL)
	{
        kal_char *pch = NULL;
        
        CRITICAL_SECTION_BEGIN;
        GetModuleFileName( NULL, file_disk_info[NOR_DISK].dir_name, MAX_PATH);
        CRITICAL_SECTION_END;

        printf("[FS] FileDiskNor_MountDevice - \n    Current Dir: %s\n", file_disk_info[NOR_DISK].dir_name);

        pch = FileDisk_LocateImageDir(file_disk_info[NOR_DISK].dir_name);

        if (pch==NULL)
        {
            ASSERT(0);
        }

        if (fssim_root_dir[0] == 0)
            kal_wsprintf((kal_wchar *)&fssim_root_dir[0], "%s", file_disk_info[NOR_DISK].dir_name);

		strcat(file_disk_info[NOR_DISK].dir_name, file_disk_info[NOR_DISK].name);
		strcat(file_disk_info[NOR_DISK].dir_name, ".img");
        printf("[FS] FileDiskNor_MountDevice - \n    Try to open %s\n", file_disk_info[NOR_DISK].dir_name);
		fd = fopen(file_disk_info[NOR_DISK].dir_name, "rb+");

		if(fd == NULL)
		{
            printf("[FS] FileDiskNor_MountDevice - \n    Can't open existent file: %s\n", strerror(errno));
			fd = fopen(file_disk_info[NOR_DISK].dir_name, "wb+");
		}
        if(fd == NULL)
        {
            printf("[FS] FileDiskNor_MountDevice - \n    Can't open virtual disk: %s\n", strerror(errno));
            ASSERT(0);
        }
		file_disk_info[NOR_DISK].file_handle = fd;
		gFileDiskBuffer[127] = 0;
		FileDiskNor_ReadSectors(NULL, 0, 1, (void*)gFileDiskBuffer);
		if(gFileDiskBuffer[127] != 0xaa550000)
		{
			FileDisk_Format(&file_disk_info[NOR_DISK], file_disk_info[NOR_DISK].totalsectors);
		}
	}
	
	return file_disk_info[NOR_DISK].bytespersector;
}

int  FileDiskNor_ShutDown(void * DriveData)
{
	if(file_disk_info[NOR_DISK].file_handle)
		fclose(file_disk_info[NOR_DISK].file_handle);
	return FS_NO_ERROR;
}

void FileDiskNor_Exit(void)
{
	if(file_disk_info[NOR_DISK].file_handle)
		fclose(file_disk_info[NOR_DISK].file_handle);
}

int  FileDiskNor_ReadSectors(void * DriveData, UINT Sector, UINT Sectors, void * Buffer)
{
	fseek(file_disk_info[NOR_DISK].file_handle, Sector << 9, SEEK_SET);
	fread(Buffer, 1, Sectors << 9, file_disk_info[NOR_DISK].file_handle);
	return FS_NO_ERROR;
}

int  FileDiskNor_WriteSectors(void * DriveData, UINT Sector, UINT Sectors, void * Buffer)
{
	fseek(file_disk_info[NOR_DISK].file_handle, Sector << 9, SEEK_SET);
	fwrite(Buffer, 1, Sectors << 9, file_disk_info[NOR_DISK].file_handle);
	return FS_NO_ERROR;
}

int  FileDiskNor_MediaChanged(void * DriveData)
{
	return FS_NO_ERROR;
}

int  FileDiskNor_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
    memset((void*)DiskGeometry, 0, sizeof * DiskGeometry);
	DiskGeometry->Sectors = file_disk_info[NOR_DISK].totalsectors;
	*MediaDescriptor = 0xf8;
   	return FS_NO_ERROR;
}

FS_Driver FileDiskNorDriver =
{
	FileDiskNor_MountDevice,
	FileDiskNor_ShutDown,
	FileDiskNor_ReadSectors,
	FileDiskNor_WriteSectors,
	FileDiskNor_MediaChanged,
	NULL,
	FileDiskNor_GetDiskGeometry,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,//FileDisk_HighLevelFormat,
	NULL, /*flush data*/
	NULL,  /*message ack*/
	NULL,
	NULL,
	NULL,
	NULL
};
#endif


//============================================================================================
// nand disk driver
//============================================================================================
#ifdef NAND_SUPPORT
int  FileDiskNand_ReadSectors(void * DriveData, UINT Sector, UINT Sectors, void * Buffer);

int  FileDiskNand_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, UINT Flags)
{
	FILE *fd;
	
	if(file_disk_info[NAND_DISK].file_handle == NULL)
	{
        kal_char *pch = NULL;
        kal_uint32 len = strlen(FSSIM_STANDALONG_PATH);

        CRITICAL_SECTION_BEGIN;
        GetModuleFileName( NULL, file_disk_info[NAND_DISK].dir_name, MAX_PATH);
        CRITICAL_SECTION_END;

        pch = strrchr(file_disk_info[NAND_DISK].dir_name, '\\');
        
        ASSERT(pch);
        *(++pch) = 0;
        pch -= len;
        printf("[FS] FileDiskNand_MountDevice - \n    Current Dir: %s\n", file_disk_info[NAND_DISK].dir_name);

        if (strlen(file_disk_info[NAND_DISK].dir_name) > len &&
            strcmp(pch, FSSIM_STANDALONG_PATH) == 0)
        {
            *pch = 0;
            strcat(pch, FILE_DISK_PATH);
        }
        else
        {
            ASSERT(0);
        }

		strcat(file_disk_info[NAND_DISK].dir_name, file_disk_info[NAND_DISK].name);
		strcat(file_disk_info[NAND_DISK].dir_name, ".img");
        printf("[FS] FileDiskNand_MountDevice - \n    Try to open %s\n", file_disk_info[NAND_DISK].dir_name);
		fd = fopen(file_disk_info[NAND_DISK].dir_name, "rb+");

		if(fd == NULL)
		{
            printf("[FS] FileDiskNand_MountDevice - \n    Can't open existent file: %s\n", strerror(errno));
			fd = fopen(file_disk_info[NAND_DISK].dir_name, "wb+");
		}
        if(fd == NULL)
        {
            printf("[FS] FileDiskNand_MountDevice - \n    Can't open virtual disk: %s\n", strerror(errno));
            ASSERT(0);
        }

        file_disk_info[NAND_DISK].file_handle = fd;
		gFileDiskBuffer[127] = 0;
		FileDiskNand_ReadSectors(NULL, 0, 1, (void*)gFileDiskBuffer);
		if(gFileDiskBuffer[127] != 0xaa550000)
		{
			FileDisk_Format(&file_disk_info[NAND_DISK], file_disk_info[NAND_DISK].totalsectors);
		}
	}
	
	return file_disk_info[NAND_DISK].bytespersector;
}

int  FileDiskNand_ShutDown(void * DriveData)
{
	if(file_disk_info[NAND_DISK].file_handle)
		fclose(file_disk_info[NAND_DISK].file_handle);
	return FS_NO_ERROR;
}

void FileDiskNand_Exit(void)
{
	if(file_disk_info[NAND_DISK].file_handle)
		fclose(file_disk_info[NAND_DISK].file_handle);
}

int  FileDiskNand_ReadSectors(void * DriveData, UINT Sector, UINT Sectors, void * Buffer)
{
	fseek(file_disk_info[NAND_DISK].file_handle, Sector << 9, SEEK_SET);
	fread(Buffer, 1, Sectors << 9, file_disk_info[NAND_DISK].file_handle);
	return FS_NO_ERROR;
}

int  FileDiskNand_WriteSectors(void * DriveData, UINT Sector, UINT Sectors, void * Buffer)
{
	fseek(file_disk_info[NAND_DISK].file_handle, Sector << 9, SEEK_SET);
	fwrite(Buffer, 1, Sectors << 9, file_disk_info[NAND_DISK].file_handle);
	return FS_NO_ERROR;
}

int  FileDiskNand_MediaChanged(void * DriveData)
{
	return FS_NO_ERROR;
}

int  FileDiskNand_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
	memset((void*)DiskGeometry, 0, sizeof * DiskGeometry);
	DiskGeometry->Sectors = file_disk_info[NAND_DISK].totalsectors;
	*MediaDescriptor = 0xf8;
   	return FS_NO_ERROR;
}

FS_Driver FileDiskNandDriver =
{
	FileDiskNand_MountDevice,
	FileDiskNand_ShutDown,
	FileDiskNand_ReadSectors,
	FileDiskNand_WriteSectors,
	FileDiskNand_MediaChanged,
	NULL,
	FileDiskNand_GetDiskGeometry,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,//FileDisk_HighLevelFormat,
	NULL, /*flush data*/
	NULL,  /*message ack*/
	NULL,
	NULL,
	NULL,
	NULL
};

#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
#if (NAND_DISK_NUM > 1)
//============================================================================================
// nand disk driver
//============================================================================================
int  FileDiskNand1_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, UINT Flags)
{
	FILE *fd;
	
	if(file_disk_info[NAND_DISK1].file_handle == NULL)
	{
		strcpy(file_disk_info[NAND_DISK1].dir_name, FILE_DISK_PATH);
		strcat(file_disk_info[NAND_DISK1].dir_name, file_disk_info[NAND_DISK1].name);
		strcat(file_disk_info[NAND_DISK1].dir_name, ".img");
		fd = fopen(file_disk_info[NAND_DISK1].dir_name, "rb+");
		if(fd == NULL)
		{
			fd = fopen(file_disk_info[NAND_DISK1].dir_name, "wb+");
		}
		file_disk_info[NAND_DISK1].file_handle = fd;
		gFileDiskBuffer[127] = 0;
		FileDiskNand1_ReadSectors(NULL, 0, 1, (void*)gFileDiskBuffer);
		if(gFileDiskBuffer[127] != 0xaa550000)
		{
			FileDisk_Format(&file_disk_info[NAND_DISK1], file_disk_info[NAND_DISK1].totalsectors);
		}
	}
	
	return file_disk_info[NAND_DISK1].bytespersector;
}

int  FileDiskNand1_ShutDown(void * DriveData)
{
	if(file_disk_info[NAND_DISK1].file_handle)
		fclose(file_disk_info[NAND_DISK1].file_handle);
	return FS_NO_ERROR;
}

void FileDiskNand1_Exit(void)
{
	if(file_disk_info[NAND_DISK1].file_handle)
		fclose(file_disk_info[NAND_DISK1].file_handle);
}

int  FileDiskNand1_ReadSectors(void * DriveData, UINT Sector, UINT Sectors, void * Buffer)
{
	fseek(file_disk_info[NAND_DISK1].file_handle, Sector << 9, SEEK_SET);
	fread(Buffer, 1, Sectors << 9, file_disk_info[NAND_DISK1].file_handle);
	return FS_NO_ERROR;
}

int  FileDiskNand1_WriteSectors(void * DriveData, UINT Sector, UINT Sectors, void * Buffer)
{
	fseek(file_disk_info[NAND_DISK1].file_handle, Sector << 9, SEEK_SET);
	fwrite(Buffer, 1, Sectors << 9, file_disk_info[NAND_DISK1].file_handle);
	return FS_NO_ERROR;
}

int  FileDiskNand1_MediaChanged(void * DriveData)
{
	return FS_NO_ERROR;
}

int  FileDiskNand1_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
	memset((void*)DiskGeometry, 0, sizeof * DiskGeometry);
	DiskGeometry->Sectors = file_disk_info[NAND_DISK1].totalsectors;
	*MediaDescriptor = 0xf8;
   	return FS_NO_ERROR;
}

FS_Driver FileDiskNandDriver1 =
{
	FileDiskNand1_MountDevice,
	FileDiskNand1_ShutDown,
	FileDiskNand1_ReadSectors,
	FileDiskNand1_WriteSectors,
	FileDiskNand1_MediaChanged,
	NULL,
	FileDiskNand1_GetDiskGeometry,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,//FileDisk_HighLevelFormat,
	NULL, /*flush data*/
	NULL,  /*message ack*/
	NULL,
	NULL,
	NULL,
	NULL
};
#endif
#endif
#endif


//============================================================================================
// card disk driver
//============================================================================================
#if (defined __MSDC_MS__) || (defined __MSDC_SD_MMC__) || (defined __MSDC_MSPRO__)
int  FileDiskCard_ReadSectors(void * DriveData, UINT Sector, UINT Sectors, void * Buffer);

int  FileDiskCard_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, UINT Flags)
{
	FILE *fd;
	FILE_DISK_INFO_T *drive = (FILE_DISK_INFO_T *)DriveData;

	if(drive->file_handle == NULL)
	{
        kal_char *pch = NULL;

        CRITICAL_SECTION_BEGIN;
        GetModuleFileName( NULL, drive->dir_name, MAX_PATH);
        CRITICAL_SECTION_END;

        printf("[FS] FileDiskCard_MountDevice - \n    Current Dir: %s\n", drive->dir_name);

        pch = FileDisk_LocateImageDir(drive->dir_name);

        if (pch==NULL)
        {
            ASSERT(0);
        }

		strcat(drive->dir_name, drive->name);
		strcat(drive->dir_name, ".img");
        printf("[FS] FileDiskCard_MountDevice - \n    Try to open %s\n", drive->dir_name);
		fd = fopen(drive->dir_name, "rb+");

		if(fd == NULL)
		{
            printf("[FS] FileDiskCard_MountDevice - \n    Can't open existent file: %s\n", strerror(errno));
			fd = fopen(drive->dir_name, "wb+");
		}
        if(fd == NULL)
        {
            printf("[FS] FileDiskCard_MountDevice - \n    Can't open virtual disk: %s\n", strerror(errno));
            ASSERT(0);
        }		
        
        drive->file_handle = fd;
		gFileDiskBuffer[127] = 0;
		
        FileDiskCard_ReadSectors(DriveData, 0, 1, (void*)gFileDiskBuffer);
		if(gFileDiskBuffer[127] != 0xaa550000)
		{
			FileDisk_Format(DriveData, drive->totalsectors);
		}
	}
	
	return drive->bytespersector;
}

int  FileDiskCard_ShutDown(void * DriveData)
{
    FILE_DISK_INFO_T *drive = (FILE_DISK_INFO_T *)DriveData;

	if(drive->file_handle)
		fclose(drive->file_handle);
	return FS_NO_ERROR;
}
/*
void FileDiskCard_Exit(void)
{
    FILE_DISK_INFO_T *drive = (FILE_DISK_INFO_T *)DriveData;

	if(drive->file_handle)
		fclose(drive->file_handle);
}
*/
int  FileDiskCard_ReadSectors(void * DriveData, UINT Sector, UINT Sectors, void * Buffer)
{
    FILE_DISK_INFO_T *drive = (FILE_DISK_INFO_T *)DriveData;

    fseek(drive->file_handle, Sector << 9, SEEK_SET);
	fread(Buffer, 1, Sectors << 9, drive->file_handle);
	return FS_NO_ERROR;
}

int  FileDiskCard_WriteSectors(void * DriveData, UINT Sector, UINT Sectors, void * Buffer)
{
    FILE_DISK_INFO_T *drive = (FILE_DISK_INFO_T *)DriveData;

    fseek(drive->file_handle, Sector << 9, SEEK_SET);
	fwrite(Buffer, 1, Sectors << 9, drive->file_handle);
	return FS_NO_ERROR;
}

int  FileDiskCard_MediaChanged(void * DriveData)
{
    FILE_DISK_INFO_T *drive = (FILE_DISK_INFO_T *)DriveData;

    if (drive->is_plug_out)
    {
        drive->is_plug_out = KAL_FALSE;
        return FS_NO_ERROR;
    }
    else
    {
        drive->is_plug_out = KAL_TRUE;
        return FS_MSDC_NOT_PRESENT;
    }
}


int  FileDiskCard_MessageAck(void * DriveData, int AckType)
{
	return FS_NO_ERROR;
}

int  FileDiskCard_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
    FILE_DISK_INFO_T *drive = (FILE_DISK_INFO_T *)DriveData;

	memset((void*)DiskGeometry, 0, sizeof * DiskGeometry);
	DiskGeometry->Sectors = drive->totalsectors;
	*MediaDescriptor = 0xf8;
   	return FS_NO_ERROR;
}


FS_Driver FileDiskCardDriver =
{
	FileDiskCard_MountDevice,       /* MountDevice              */
	FileDiskCard_ShutDown,          /* ShutDown                 */
	FileDiskCard_ReadSectors,       /* ReadSectors              */
	FileDiskCard_WriteSectors,      /* WriteSectors             */
	FileDiskCard_MediaChanged,      /* MediaChanged             */
	NULL,                           /* DiscardSectors           */
	FileDiskCard_GetDiskGeometry,   /* GetDiskGeometry          */
	NULL,                           /* LowLevelFormat           */
	NULL,                           /* NonBlockWriteSectors     */
	NULL,                           /* RecoverableWriteSectors  */
	NULL,                           /* ResumeSectorStates       */
	FileDisk_Format,                /* HighLevelFormat          */
	NULL,                           /* RecoverDisk              */
	FileDiskCard_MessageAck,        /* MessageAck               */
	NULL,                           /* CopySectors              */
	NULL,                           /* OTPAccess                */
	NULL,                           /* OTPQueryLength           */
	NULL                            /* IOCtrl                   */
};
#endif

ReadSectors get_read_sector_func(TCHAR drive)
{
	switch(drive - FILE_DISK_DRIVE)
	{
	#ifndef _NAND_FLASH_BOOTING_
	case NOR_DISK:
		return (ReadSectors)FileDiskNor_ReadSectors;
	#endif
	
	#ifdef NAND_SUPPORT
	case NAND_DISK:
		return (ReadSectors)FileDiskNand_ReadSectors;
	#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
	#if (NAND_DISK_NUM > 1)
	case NAND_DISK1:
		return (ReadSectors)FileDiskNand1_ReadSectors;
	#endif
	#endif
	#endif

	#if (defined __MSDC_MS__) || (defined __MSDC_SD_MMC__) || (defined __MSDC_MSPRO__)
	case CARD_DISK:
    #if defined(__FS_CARD2_SUPPORT__)
    case CARD_DISK1: 
    #endif
		return (ReadSectors)FileDiskCard_ReadSectors;
	#endif
	}
	return NULL;
}

WriteSectors get_write_sector_func(TCHAR drive)
{
	switch(drive - FILE_DISK_DRIVE)
	{
	#ifndef _NAND_FLASH_BOOTING_
	case NOR_DISK:
		return (WriteSectors)FileDiskNor_WriteSectors;
	#endif
	
	#ifdef NAND_SUPPORT
	case NAND_DISK:
		return (WriteSectors)FileDiskNand_WriteSectors;
	#endif
	#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
	#if (NAND_DISK_NUM > 1)
	case NAND_DISK1:
		return (WriteSectors)FileDiskNand1_WriteSectors;
	#endif
	#endif

	#if (defined __MSDC_MS__) || (defined __MSDC_SD_MMC__) || (defined __MSDC_MSPRO__)
	case CARD_DISK:
    #if defined(__FS_CARD2_SUPPORT__)
    case CARD_DISK1: 
    #endif

		return (WriteSectors)FileDiskCard_WriteSectors;
	#endif
	}
	return NULL;
}

static int FileDisk_Format(void * DriveData, kal_uint32 first_sectors)
{
	FILE_DISK_INFO_T *driver = (FILE_DISK_INFO_T *)DriveData;

	FS_PartitionRecord	Partition1, Partition2;
	int Result   = FS_NO_ERROR;
 
	ReadSectors read_sectors = get_read_sector_func(driver->drive);
	WriteSectors write_sectors = get_write_sector_func(driver->drive);
	
	// build MBR
	kal_mem_set((void*)&Partition1, 0, sizeof(Partition1));
	Partition1.Sectors = driver->totalsectors;
	FS_CreateMasterBootRecord((void*)gFileDiskBuffer, &Partition1);

	#ifndef _NAND_FLASH_BOOTING_
	if(driver->drive - FILE_DISK_DRIVE == NOR_DISK)
	{
		if(NOR_PARTITION_SECTORS && (NOR_PARTITION_SECTORS < NOR_ALLOCATED_FAT_SPACE))
		{
			FS_SplitPartition((void*)gFileDiskBuffer, NOR_PARTITION_SECTORS);
		}
	}
	#endif

	#ifdef NAND_SUPPORT
	if(driver->drive - FILE_DISK_DRIVE == NAND_DISK)
	{
		if(NAND_PARTITION_SECTORS && (NAND_PARTITION_SECTORS < NAND_FLASH_SIZE))
		{
			FS_SplitPartition((void*)gFileDiskBuffer, NAND_PARTITION_SECTORS);
		}
	}
	#endif

    Result = write_sectors(DriveData, 0, 1, gFileDiskBuffer);
	if(0 > Result)
		return Result;

	Partition1 = ((FS_MasterBootRecord*)gFileDiskBuffer)->PTable[0];
	Partition2 = ((FS_MasterBootRecord*)gFileDiskBuffer)->PTable[1];
	if(Partition1.Sectors > 5)
	{
        kal_int32 i = 0;
        for (; i < 10; i++)
        {
            kal_sleep_task(5);
        }
		Result = SelfFormat(DriveData, &Partition1);
	}
	if(Partition2.Sectors > 5)
	{
		Result = SelfFormat(DriveData, &Partition2);
	}

	return Result;
}

static int SelfFormat(void * DriveData, FS_PartitionRecord	 *Partition)
{
	int        FATType;
	kal_uint32 RootDirSectors;
	kal_uint32 FATSectors, Written;
	kal_uint32 FatCount, StartOfFAT;
	kal_uint32 InfoSector;
	kal_uint32 i;
	kal_uint32 x, y;
	FILE_DISK_INFO_T *driver = (FILE_DISK_INFO_T *)DriveData;
	UINT BaseSectorNumber;
	FS_BootRecord       *PBR;
	kal_uint8 MediaDescriptor;
	int Result   = FS_NO_ERROR;

	ReadSectors read_sectors = get_read_sector_func(driver->drive);
	WriteSectors write_sectors = get_write_sector_func(driver->drive);

	// build PBR
	BaseSectorNumber = Partition->RelativeSector;
	Result = FS_CreateBootSector(gFileDiskBuffer, Partition, 0xF8, 0, 0);
	if (Result < FS_NO_ERROR) return Result;
		FATType = Result;
	Result = write_sectors(DriveData, BaseSectorNumber, 1, gFileDiskBuffer);
	if(0 > Result)
		return Result;
	
	Result = read_sectors(DriveData, BaseSectorNumber, 1, gFileDiskBuffer);
	if(0 > Result)
		return Result;
	
	PBR = (FS_BootRecord*)gFileDiskBuffer;

	/* HLF - 2 - Setup PBR sector content and attributes */
	if (PBR->BP.SectorsOnDisk != 0)
		PBR->BP.TotalSectors = PBR->BP.SectorsOnDisk;

	if (PBR->Signature != 0xAA55 ||
		//PBR->BP.TotalSectors > Par.Partition.Sectors ||
		PBR->BP.TotalSectors > Partition->Sectors ||
		PBR->BP.BytesPerSector != 512 ||
		PBR->BP.SectorsPerCluster == 0 ||
		PBR->BP.ReservedSectors == 0 ||
		PBR->BP.NumberOfFATs == 0)
	{
		return FS_INVALID_FILE_SYSTEM;
	}

	FATSectors     = (PBR->BP.SectorsPerFAT) ? PBR->BP.SectorsPerFAT : PBR->BP.E._32.SectorsPerFAT;
	RootDirSectors = (PBR->BP.DirEntries * 32 + (PBR->BP.BytesPerSector - 1)) / PBR->BP.BytesPerSector;

	Written        = PBR->BP.TotalSectors
		- PBR->BP.ReservedSectors
		- PBR->BP.NumberOfFATs * FATSectors
		- RootDirSectors;
	Written = Written / PBR->BP.SectorsPerCluster;

	if (Written <= 0xFF4L)            FATType = 12;
	else if (Written <= 0xFFF4L)      FATType = 16;
	else if (Written <= 0xFFFFFF4L)   FATType = 32;
	else		return FS_INVALID_FILE_SYSTEM;
		Written = 0;

	if (FATType == 32)
	{
		RootDirSectors = PBR->BP.SectorsPerCluster;

		if (PBR->BP.E._32.RootDirCluster != 2)
		{
			PBR->BP.E._32.RootDirCluster = 2;
			
			//above seek and write seems mean write to specific sector
			Result = write_sectors(DriveData, BaseSectorNumber , 1, (void *)PBR);
			if(0 > Result)
				return Result;
			
			Result = write_sectors(DriveData, BaseSectorNumber + PBR->BP.E._32.BackupBootSector , 1, (void *)PBR);
			if(0 > Result)
				return Result;
		}
	}
	FatCount       = PBR->BP.NumberOfFATs;
	StartOfFAT     = PBR->BP.ReservedSectors;
	InfoSector     = PBR->BP.E._32.FSInfoSector;
	
	/*we get MediaDescriptor for step 6 usage, since we will clear gFileDiskBuffer*/
	MediaDescriptor = PBR->BP.MediaDescriptor;
	/*we need gFileDiskBuffer to be 512-byte-0 now*/
	kal_mem_set(gFileDiskBuffer, 0, 512);
   
	/* HLF - 3 - Formating cont, FAT32 reserved sector write down */
	if ((FATType == 32) && (InfoSector > 0) && (InfoSector < StartOfFAT))
	{                                              /* Zero Sector Count   */ 
		Result = write_sectors(DriveData, BaseSectorNumber + InfoSector, 1, gFileDiskBuffer);
		if(0 > Result)
			return Result;
	}
	  
	/* HLF - 4 - Formating cont, start, FAT Table write down , remember FAT begin sector */
	for(i = 0; i < FATSectors * FatCount; i++){
		Result = write_sectors(DriveData, BaseSectorNumber + StartOfFAT + i, 1 , gFileDiskBuffer);
		if(0 > Result){
			return Result;
		}
	}

	/* HLF - 5 - Formating cont, Root directory write down */   
	x = StartOfFAT + FATSectors * FatCount;
	for(i = 0; i < RootDirSectors; i++){
		Result = write_sectors(DriveData, BaseSectorNumber + x + i, 1 , gFileDiskBuffer);
		if(0 > Result){
		return Result;
		}
	}

   /* HLF - 6 - Formating final, 1st FAT sector must be rewritten */
   {
      switch (FATType)
      {
         case 32:
            {
               //kal_uint32 * FPtr = (void*) ScratchSector;
               gFileDiskBuffer[2] = 0x0FFFFFFF; // this is for the root dir
               gFileDiskBuffer[1] = 0x0FFFFFFF;
               //break;
            }
         case 16:
            {
               kal_uint16 * FPtr = (void*) gFileDiskBuffer;
               FPtr[1] = 0xFFFF;
               //break;
            }
         case 12:
            {
            	 kal_uint8 *FPtr = (void *)gFileDiskBuffer;
               /* FIXME */ FPtr[2] = 0xFF;
               /* FIXME */ FPtr[1] = 0xFF;
               /* FIXME */ FPtr[0] = MediaDescriptor;
               break;
            }
         default:
         	ASSERT(0);
         	break;
      }
      for (i = 0, y = StartOfFAT; i < FatCount; i++, y+= FATSectors)
      {
         write_sectors(DriveData, BaseSectorNumber + y, 1 , gFileDiskBuffer);
      }
   }

   /* HLF - 7 - The END */
   return Result;
}


#ifdef WIN32	// zza add

kal_uint32 INT_GetCurrentTime(void)
{
   //return *(volatile kal_uint32*)(0x80200230);
   return 0;
}

int Check_NORFlash_Formatted(void)
{
#if 0//( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) )
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else   // The following is __FS_SYSDRV_ON_NAND__ or _NAND_FLASH_BOOTING_

   #if defined(__NAND_FDM_50__)
   return 1;
   #else	
   return 0; //formatted (may false alarm!)
   #endif
   
#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */    
}
#endif
