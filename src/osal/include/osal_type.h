/*
 * osal_type.h
 *
 *  Created on: 29-Mar-2018
 *      Author: sunny
 */

#ifndef SRC_OSAL_INCLUDE_OSAL_TYPE_H_
#define SRC_OSAL_INCLUDE_OSAL_TYPE_H_

#include <semaphore.h>
#include <pthread.h>

typedef unsigned long int		TASK_ID;

typedef unsigned long			UI8;
typedef unsigned int 			UI4;
typedef unsigned short int		UI2;
typedef unsigned char			UI1;

typedef signed long				I8;
typedef signed int				I4;
typedef signed short int		I2;
typedef signed char				I1;

typedef void					VOID;

typedef unsigned long *			PUI8;
typedef unsigned int *			PUI4;
typedef unsigned short int *	PUI2;
typedef unsigned char *			PUI1;

typedef signed long *			PI8;
typedef signed int *			PI4;
typedef signed short int *		PI2;
typedef signed char *			PI1;

typedef void * 					PVOID;

typedef PVOID (*TASK)(PVOID);

typedef sem_t					SEM;
typedef pthread_mutex_t 		MUTEX;

typedef enum MBEOSAL_typeEnum
{
	MBEOSAL_TYPE_FAILURE = -1,
	MBEOSAL_TYPE_SUCCESS
}MBEOSAL_ENUM_TYPE;

typedef struct MBEOSAL_taskCreateStruct
{
	pthread_t		task_id;
	TASK			task_name;
	PVOID			argv;
}MBEOSAL_TASK_CREATE_STRUCT;

typedef struct MBEOSAL_taskListStruct
{
	MBEOSAL_TASK_CREATE_STRUCT 		*stTaskCreate;
	struct MBEOSAL_taskListStruct 	*next;
}MBEOSAL_TASK_LIST_STRUCT;

I2 mbeOSALtaskCreate(MBEOSAL_TASK_CREATE_STRUCT *);
I2 mbeOSALtaskJoin(TASK_ID);

#endif /* SRC_OSAL_INCLUDE_OSAL_TYPE_H_ */
