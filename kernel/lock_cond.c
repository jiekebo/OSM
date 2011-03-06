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
	sleepq_wake_all(cond);
    return 0;
}

void condition_wait(cond_t * cond, lock_t *condition_lock){
	interrupt_status_t intr_status = _interrupt_disable();
	sleepq_add(cond);
	_interrupt_set_state(intr_status);
	lock_release(condition_lock);
	thread_switch();
}

void condition_signal(cond_t *cond, lock_t *condition_lock){
	condition_lock = condition_lock;
	sleepq_wake(cond);
}

void condition_broadcast(cond_t *cond, lock_t *condition_lock){
	condition_lock = condition_lock;
	sleepq_wake_all(cond);
}
