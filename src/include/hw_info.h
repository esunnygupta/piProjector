/*
 * hw_info.h
 *
 *  Created on: 31-Oct-2018
 *      Author: sunny
 */

#ifndef SRC_MAIN_INCLUDE_HW_INFO_H_
#define SRC_MAIN_INCLUDE_HW_INFO_H_

typedef struct MBEMAIN_hwInfoStruct
{
	UI1 serialNo[16];
	UI1 chipId[12];
}MBEMAIN_HW_INFO_STRUCT;

MBEMAIN_HW_INFO_STRUCT stHwInfo=
{
	serialNo:"1501MBE8S2301",
	chipId:"728928",
};

#endif /* SRC_MAIN_INCLUDE_HW_INFO_H_ */
