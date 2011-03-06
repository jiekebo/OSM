/*
 * lock.c
 *
 *  Created on: Mar 5, 2011
 *      Author: arkimedes
 */

#include "kernel/interrupt.h"
#include "kernel/sleepq.h"
#include "kernel/lock.h"

int lock_reset(lock_t *lock){
	spinlock_reset(&lock->spinlock);
	lock->locked = 0;
	return 0;
}

void lock_acquire(lock_t *lock){
	interrupt_status_t intr_status;
	intr_status = _interrupt_disable();
	spinlock_acquire(&lock->spinlock);

	while(lock->locked == 1){
		sleepq_add(lock);
		spinlock_release(&lock->spinlock);
		thread_switch();
		spinlock_acquire(&lock->spinlock);
	}

	lock->locked = 1;
	spinlock_release(&lock->spinlock);

	_interrupt_set_state(intr_status);
}

void lock_release(lock_t *lock){
	lock->locked = 0;
	sleepq_wake(lock);
}
