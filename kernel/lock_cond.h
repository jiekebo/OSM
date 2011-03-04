/*
 * lock_cond.h
 *
 *  Created on: Mar 4, 2011
 *      Author: arkimedes
 */

#ifndef LOCK_COND_H_
#define LOCK_COND_H_

typedef struct {

} cond_t;

int condition_reset(cond_t *cond);
void condition_wait(cond_t * cond, lock_t *condition_lock);
void condition_signal(cond_t *cond, lock_t *condition_lock);
void condition_broadcast(cond_t *cond, lock_t *condition_lock);

#endif /* LOCK_COND_H_ */
