/*
 * osal_list.h
 *
 *  Created on: 30-Sep-2018
 *      Author: sunny
 */

#ifndef SRC_OSAL_INCLUDE_OSAL_LIST_H_
#define SRC_OSAL_INCLUDE_OSAL_LIST_H_

VOID mbeOSALaddTask(MBEOSAL_TASK_LIST_STRUCT **stTaskList ,MBEOSAL_TASK_CREATE_STRUCT *stTaskCreate);
VOID mbeOSALdeleteTask(TASK_ID ui4task_id);

#endif /* SRC_OSAL_INCLUDE_OSAL_LIST_H_ */
