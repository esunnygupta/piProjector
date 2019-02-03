/*
 * parser.c
 *
 *  Created on: 01-Oct-2018
 *      Author: sunny
 */


#include <stdio.h>
#include <stdlib.h>

#include <logs.h>
#include <osal_type.h>
#include <osal_list.h>

#include <libavformat/avformat.h>

TASK_ID gParserTaskID;

PVOID mbeParserTask()
{
	mprintf("init...\n");

	mprintf("exit...\n");

	return NULL;
}

VOID mbeParserTaskCreate()
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
	stTaskCreate->task_name = mbeParserTask;
	ret = mbeOSALtaskCreate(stTaskCreate);
	if(ret < 0)
	{
		mprintf("MBEAPP_mainTask not created\n");
	}
	gParserTaskID = stTaskCreate->task_id;
	//mprintf("exit...\n");
}

VOID mbeParserTaskDelete()
{
	I2 ret;

	//mprintf("init...\n");
	ret = mbeOSALtaskJoin(gParserTaskID);
	if(ret < 0)
	{
		mprintf("MBEAPP_mainTask join failed\n");
	}
	mbeOSALdeleteTask(gParserTaskID);
	//mprintf("exit...\n");
}
