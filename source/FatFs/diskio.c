/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2014        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "diskio.h"		/* FatFs lower layer API */
#include "fatfs_sd_sdio.h"	/* Header file of existing MMC/SDC contorl module */

/* Definitions of physical drive number for each drive */
#define SD		0	/* Example: Map MMC/SD card to physical drive 0 */
#define ATA		1	/* Example: Map ATA harddisk to physical drive 1 */
#define USB		2	/* Example: Map USB MSD to physical drive 2 */


/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;

	switch (pdrv) {
	case ATA :
		//stat = ATA_disk_status();

		// translate the reslut code here

		return stat;

	case SD :
		
		return FATFS_SD_SDIO_disk_status();

	case USB :
		//stat = USB_disk_status();

		// translate the reslut code here

		return stat;
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;

	switch (pdrv) {
	case ATA :
		//stat = ATA_disk_initialize();

		// translate the reslut code here

		return stat;

	case SD :
		
		return FATFS_SD_SDIO_disk_initialize();

	case USB :
		//stat = USB_disk_initialize();

		// translate the reslut code here

		return stat;
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address in LBA */
	UINT count		/* Number of sectors to read */
)
{
	DRESULT res;

	switch (pdrv) {
	case ATA :
		// translate the arguments here

		//result = ATA_disk_read(buff, sector, count);

		// translate the reslut code here

		return res;

	case SD :
		
		return FATFS_SD_SDIO_disk_read(buff, sector, count);

	case USB :
		// translate the arguments here

		//result = USB_disk_read(buff, sector, count);

		// translate the reslut code here

		return res;
	}

	return RES_PARERR;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if _USE_WRITE
DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address in LBA */
	UINT count			/* Number of sectors to write */
)
{
	DRESULT res;

	switch (pdrv) {
	case ATA :
		// translate the arguments here

		//result = ATA_disk_write(buff, sector, count);

		// translate the reslut code here

		return res;

	case SD :
		
		return FATFS_SD_SDIO_disk_write(buff, sector, count);

	case USB :
		// translate the arguments here

		//result = USB_disk_write(buff, sector, count);

		// translate the reslut code here

		return res;
	}

	return RES_PARERR;
}
#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

#if _USE_IOCTL
DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res;

	switch (pdrv) {
	case ATA :

		// Process of the command for the ATA drive

		return res;

	case SD :

		return FATFS_SD_SDIO_disk_ioctl(cmd, buff);

	case USB :

		// Process of the command the USB drive

		return res;
	}

	return RES_PARERR;
}
#endif
