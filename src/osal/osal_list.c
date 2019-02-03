/*
 * osal_list.c
 *
 *  Created on: 30-Sep-2018
 *      Author: sunny
 */


#include <stdio.h>
#include <stdlib.h>

#include <logs.h>
#include <osal_type.h>

extern MBEOSAL_TASK_LIST_STRUCT *stTaskList;

VOID mbeOSALaddTask(MBEOSAL_TASK_LIST_STRUCT **stTaskListLocal, MBEOSAL_TASK_CREATE_STRUCT *stTaskCreate)
{
	MBEOSAL_TASK_LIST_STRUCT *stTaskListTemp;

	//mprintf("init...\n");
	stTaskListTemp = (MBEOSAL_TASK_LIST_STRUCT *)malloc(sizeof(MBEOSAL_TASK_LIST_STRUCT));
	if(NULL == stTaskListTemp)
	{
		mprintf("malloc() failed...\n");
		return;
	}
	stTaskListTemp->stTaskCreate = stTaskCreate;
	stTaskListTemp->next = *stTaskListLocal;
	*stTaskListLocal = stTaskListTemp;
	//mprintf("exit...\n");
}

VOID mbeOSALdeleteTask(TASK_ID ui4task_id)
{
	UI2 i = 0;
	MBEOSAL_TASK_LIST_STRUCT *stTaskListTemp = stTaskList;
	MBEOSAL_TASK_LIST_STRUCT *stTaskListNode;
	MBEOSAL_TASK_LIST_STRUCT *stTaskListPrev;

	//mprintf("init...\n");
	if(NULL == stTaskListTemp)
	{
		mprintf("Task List Empty...\n");
		return;
	}

	do
	{
		if(stTaskListTemp->stTaskCreate->task_id == ui4task_id)
		{
			//delete task
			mprintf("Task ID [%lu] at [%d]\n", ui4task_id, i);
			if(0 == i)
			{
				stTaskListNode = stTaskListTemp;
				stTaskListTemp = stTaskListTemp->next;
				stTaskList = stTaskListTemp;
				free(stTaskListNode->stTaskCreate);
				free(stTaskListNode);
			}
			else
			{
				stTaskListNode = stTaskListTemp;
				stTaskListPrev->next = stTaskListTemp->next;
				free(stTaskListNode->stTaskCreate);
				free(stTaskListNode);
			}
			break;
		}
		else
		{
			i++;
			stTaskListPrev = stTaskListTemp;
			stTaskListTemp = stTaskListTemp->next;
		}
	}while(stTaskListTemp != NULL);
	//mprintf("exit...\n");
}
