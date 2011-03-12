/*
 * fat32.c
 *
 *  Created on: Mar 12, 2011
 *      Author: arkimedes
 */

#include "kernel/kmalloc.h"
#include "kernel/assert.h"
#include "vm/pagepool.h"
#include "drivers/gbd.h"
#include "fs/vfs.h"
#include "fs/fat32.h"

// Table for Secto size and offset using the sec_t struct, all numbers are bytes.

sec_t sector_offset[] = {
		{0,3},
		{3,8},
		{11,2},
		{13,1},
		{14,2},
		{16,1},
		{17,2},
		{19,2},
		{21,2},
		{22,1},
		{24,2},
		{26,2},
		{28,2},
		{32,4},
		{36,4},
		{40,2},
		{42,2},
		{44,4},
		{48,2},
		{50,2},
		{52,12},
		{64,2},
		{65,1},
		{66,1},
		{67,4},
		{71,11},
		{82,8},
};

int mask(int size) {



	return 1 << (4*size);
}
fs_t * fat32_init(gbd_t *disk) {




}
