/*
 * main.c
 *
 *  Created on: 23-Mar-2018
 *      Author: root
 */


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#include <logs.h>
#include <version.h>
#include <osal_type.h>
#include <osal_list.h>
#include <app.h>

TASK_ID gAppMainTaskID;
//SEM gSemaphore;

PVOID mbeAppMainTask()
{
	mprintf("init...\n");
	mprintf("exit...\n");

	return NULL;
}

VOID appExit()
{
	I2 ret;

	//mprintf("init...\n");
	ret = mbeOSALtaskJoin(gAppMainTaskID);
	if(ret < 0)
	{
		mprintf("MBEAPP_mainTask join failed\n");
	}
	mbeOSALdeleteTask(gAppMainTaskID);
	//mprintf("exit...\n");
}

VOID appInit()
{
	I2 ret;
	MBEOSAL_TASK_CREATE_STRUCT *stTaskCreate;

	//mprintf("init...\n");
	//sem_init(&gSemaphore, 0, 1);
	stTaskCreate = (MBEOSAL_TASK_CREATE_STRUCT *)malloc(sizeof(MBEOSAL_TASK_CREATE_STRUCT));
	if(NULL == stTaskCreate)
	{
		mprintf("malloc() failed...\n");
		return;
	}
	stTaskCreate->task_name = mbeAppMainTask;
	ret = mbeOSALtaskCreate(stTaskCreate);
	if(ret < 0)
	{
		mprintf("MBEAPP_mainTask not created\n");
	}
	gAppMainTaskID = stTaskCreate->task_id;
	//mprintf("exit...\n");
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("invalid arguments...\n");
		printf("Usage: ./main <file or URL>\n");
		return 0;
	}
	mprintf("%s-v%s init...\n",PROJECT, VERSION);
	appInit();
	app(argv[1]);
	appExit();
	mprintf("%s-v%s exit...\n",PROJECT, VERSION);

	return 0;
}
