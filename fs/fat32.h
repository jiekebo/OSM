/*
 * fat32.h
 *
 *  Created on: Mar 12, 2011
 *      Author: arkimedes
 */

#ifndef FAT32_H_
#define FAT32_H_

#define FAT32_MBR_SIZE 0
#define FAT32_BLOCK_SIZE 512


#include "drivers/gbd.h"
#include "fs/vfs.h"

fs_t * fat32_init(gbd_t *disk);

int tfs_unmount(fs_t *fs);
int tfs_open(fs_t *fs, char *filename);
int tfs_close(fs_t *fs, int fileid);
int tfs_create(fs_t *fs, char *filename, int size);
int tfs_remove(fs_t *fs, char *filename);
int tfs_read(fs_t *fs, int fileid, void *buffer, int bufsize, int offset);
int tfs_write(fs_t *fs, int fileid, void *buffer, int datasize, int offset);
int tfs_getfree(fs_t *fs);

enum Sector_name {
	BS_jmpBoot,
	BS_OEMName,
	BPB_BytsPerSec,
	BPB_SecPerClus,
	BPB_RsvdSecCnt,
	BPB_NumFATs,
	BPB_RootEntCnt,
	BPB_TotSec16,
	BPB_Media,
	BPB_FATSsz16,
	BPB_SecPerTrk,
	BPB_NumHeads,
	BPB_HiddSec,
	BPB_TotSec32,
	BPB_FATSz32,
	BPB_ExitFlags,
	BPB_FSVer,
	BPB_RootClus,
	BPB_FSInfo,
	BPB_BkBootSec,
	BPB_Reserved,
	BS_DrvNum,
	BS_Reserved,
	BS_DrvNum,
	BS_Reserved1,
	BS_BootSig,
	BS_VolID,
	BS_FIlSysType

};

struct {

	int offset;
	int size;


} sec_t;

#endif /* FAT32_H_ */
