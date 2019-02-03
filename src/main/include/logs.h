/*
 * logs.h
 *
 *  Created on: 23-Mar-2018
 *      Author: root
 */

#ifndef INCLUDE_MAIN_LOGS_H_
#define INCLUDE_MAIN_LOGS_H_

#define MAIN_DEBUG_LOG 1

#if MAIN_DEBUG_LOG
	#define mprintf printf("\x1B[32m[%s %d %s]# \x1B[37m",__FILE__,__LINE__,__func__); printf
#else
	#define mprintf
#endif

#endif /* INCLUDE_MAIN_LOGS_H_ */
