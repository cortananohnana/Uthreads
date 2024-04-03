/*
 *   FILE: uthread_cond.c
 * AUTHOR: Peter Demoreuille
 *  DESCR: uthreads 条件变量
 *   DATE: Mon Oct  1 01:59:37 2001
 *
 *
 * Modified to handle time slicing by Tom Doeppner
 *   DATE: Sun Jan 10, 2016
 * Modified for SCUT students in July 2021 By Wu Yimin
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "uthread.h"
#include "uthread_mtx.h"
#include "uthread_cond.h"
#include "uthread_queue.h"
#include "uthread_sched.h"
#include "uthread_private.h"


/*
 * uthread_cond_init
 *
 * 初始化指定的条件变量
 */
void uthread_cond_init(uthread_cond_t *cond) {
    //Function_you_need_to_implement("UTHREADS: uthread_cond_init");
	utqueue_init(&cond->uc_waiters);
}

/*
 * uthread_cond_wait
 *
 * 等待指定的条件变量
 * 所作工作：改变当前线程的状态，并将其放入条件变量的等待队列中，切换线程。
 */
void uthread_cond_wait(uthread_cond_t *cond, uthread_mtx_t *mtx) {
    //Function_you_need_to_implement("UTHREADS: uthread_cond_wait");
    uthread_mtx_unlock(mtx);
	
	utqueue_enqueue(&cond->uc_waiters, ut_curthr);
	ut_curthr->ut_state = UT_WAIT;
	uthread_switch();
	ut_curthr->ut_state = UT_ON_CPU;

	uthread_mtx_lock(mtx);
}


/*
 * uthread_cond_broadcast
 *
 * 唤醒等待于此条件变量的所有线程.
 */
void uthread_cond_broadcast(uthread_cond_t *cond) {
    //Function_you_need_to_implement("UTHREADS: uthread_cond_broadcast");
	while(! utqueue_empty(&cond->uc_waiters)) {
		uthread_t *uth = utqueue_dequeue(&cond->uc_waiters);
		uthread_wake(uth);
	}
}

/*
 * uthread_cond_signal
 *
 * 唤醒等待于此条件变量的一个线程.
 */
void uthread_cond_signal(uthread_cond_t *cond) {
    //Function_you_need_to_implement("UTHREADS: uthread_cond_signal");
 
	if(utqueue_empty(&cond->uc_waiters)) {
		return;
	}
	uthread_t *uth = utqueue_dequeue(&cond->uc_waiters);
	uthread_wake(uth);
}
