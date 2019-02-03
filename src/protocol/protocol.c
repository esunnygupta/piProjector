/*
 * protocol.c
 *
 *  Created on: 30-Sep-2018
 *      Author: sunny
 */

#include <stdio.h>
#include <stdlib.h>

#include <logs.h>
#include <osal_type.h>
#include <osal_list.h>

#include <libavformat/avformat.h>

TASK_ID gProtocolTaskID;

PVOID mbeProtocolTask()
{
	mprintf("init...\n");
	av_register_all();
	avformat_network_init();
	mprintf("exit...\n");

	return NULL;
}

VOID mbeProtocolTaskCreate()
{
	I2 ret;
	MBEOSAL_TASK_CREATE_STRUCT *stTaskCreate;

	//mprintf("init...\n");
	stTaskCreate = (MBEOSAL_TASK_CREATE_STRUCT *)malloc(sizeof(MBEOSAL_TASK_CREATE_STRUCT));
	if(NULL == stTaskCreate)
	{
		mprintf("malloc() failed...\n");
		return;
	}
	stTaskCreate->task_name = mbeProtocolTask;
	ret = mbeOSALtaskCreate(stTaskCreate);
	if(ret < 0)
	{
		mprintf("MBEAPP_mainTask not created\n");
	}
	gProtocolTaskID = stTaskCreate->task_id;
	//mprintf("exit...\n");
}

VOID mbeProtocolTaskDelete()
{
	I2 ret;

	//mprintf("init...\n");
	ret = mbeOSALtaskJoin(gProtocolTaskID);
	if(ret < 0)
	{
		mprintf("MBEAPP_mainTask join failed\n");
	}
	mbeOSALdeleteTask(gProtocolTaskID);
	//mprintf("exit...\n");
}
