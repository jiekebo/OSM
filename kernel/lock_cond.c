/*
 * lock_cond.c
 *
 *  Created on: Mar 4, 2011
 *      Author: arkimedes
 */

#include "kernel/interrupt.h"
#include "kernel/sleepq.h"
#include "kernel/thread.h"
#include "kernel/lock.h"
#include "kernel/lock_cond.h"

int condition_reset(cond_t *cond){
	cond = cond;
	return 0;
}

void condition_wait(cond_t * cond, lock_t *condition_lock){
	cond = cond;
	condition_lock = condition_lock;
}

void condition_signal(cond_t *cond, lock_t *condition_lock){
	cond = cond;
	condition_lock = condition_lock;
}

void condition_broadcast(cond_t *cond, lock_t *condition_lock){
	cond = cond;
	condition_lock = condition_lock;
}
