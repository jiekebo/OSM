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

int fat32_unmount(fs_t *fs);
int fat32_open(fs_t *fs, char *filename);
int fat32_close(fs_t *fs, int fileid);
int fat32_create(fs_t *fs, char *filename, int size);
int fat32_remove(fs_t *fs, char *filename);
int fat32_read(fs_t *fs, int fileid, void *buffer, int bufsize, int offset);
int fat32_write(fs_t *fs, int fileid, void *buffer, int datasize, int offset);
int fat32_getfree(fs_t *fs);

#define FAT32_SIGNATURE 0xAA55
#define FAT32_DIR_ENTRY_UNUSED 0xE5
#define FAT32_MBR_SIZE 0
#define FAT32_RESERVED_SECTOR_COUNT_OFFSET 0x0E
#define FAT32_NUM_FATS_OFFSET 0x10
#define FAT32_SECS_PER_FAT_OFFSET 0x24
#define FAT32_SECS_PER_CLUS_OFFSET 0x0D
#define FAT32_ROOT_CLUS_OFFSET 0x2C
#define FAT32_SIG_OFFSET 0x1FE



typedef struct {
	char name[10];
	uint32_t attr;
	uint32_t size;
	uint32_t cluster;
	uint32_t sector;
	uint32_t entry;

	uint16_t *low_cluster;
	uint16_t *high_cluster;

} directory_t;
#endif /* FAT32_H_ */
