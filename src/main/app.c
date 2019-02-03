/*
 * app.c
 *
 *  Created on: 30-Sep-2018
 *      Author: sunny
 */

#include <stdio.h>
#include <string.h>

#include <logs.h>
#include <osal_type.h>
#include <app.h>
#include <hw_info.h>
#include <client.h>
#include <protocol.h>
#include <parser.h>

MBEMAIN_FILE_INFO_STRUCT stFileInfo;

VOID mbeSetMedia(char *filename)
{
	strcpy(stFileInfo.filename, filename);
	mprintf("filename: %s\n", stFileInfo.filename);
}

I2 app(char *filename)
{
	// Initialize Client

	// Authenticate Client
	mbeGetToken();

	// Set Media - Temporary Basis
	mbeSetMedia(filename);

	// Create Tasks
	mbeProtocolTaskCreate();
	mbeParserTaskCreate();

	// Delete Tasks
	mbeProtocolTaskDelete();
	mbeParserTaskDelete();

	return 0;
}
