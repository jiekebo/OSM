/*
 * lock.h
 *
 *  Created on: Mar 5, 2011
 *      Author: arkimedes
 */

#ifndef LOCK_H_
#define LOCK_H_

#include "kernel/spinlock.h"
#include "kernel/thread.h"

typedef struct {
	spinlock_t spinlock;
	int locked;
} lock_t;

typedef lock_t usr_lock_t;

int lock_reset(lock_t *lock);
void lock_acquire(lock_t *lock);
void lock_release(lock_t *lock);

#endif /* LOCK_H_ */
