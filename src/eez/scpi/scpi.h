/*
* EEZ Generic Firmware
* Copyright (C) 2019-present, Envox d.o.o.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see http://www.gnu.org/licenses.
*/

#pragma once

#include <cmsis_os.h>

#include <eez/modules/psu/conf.h>
#include <eez/modules/psu/conf_advanced.h>

namespace eez {
namespace scpi {

void initMessageQueue();
void startThread();

void resetContext();
void generateError(int error);

extern osThreadId g_scpiTaskHandle;
extern osMessageQId g_scpiMessageQueueId;

#define SCPI_QUEUE_SIZE 10

#define SCPI_QUEUE_MESSAGE_TARGET_NONE 0
#define SCPI_QUEUE_MESSAGE_TARGET_SERIAL 1
#define SCPI_QUEUE_MESSAGE_TARGET_ETHERNET 2
#define SCPI_QUEUE_MESSAGE_TARGET_MP 3

#define SCPI_QUEUE_MESSAGE(target, type, param) (((target) << 30) | (((param) << 8) & ~0xC0000000) | (type))
#define SCPI_QUEUE_MESSAGE_TARGET(message) ((message) >> 30)
#define SCPI_QUEUE_MESSAGE_TYPE(message) ((message) & 0xFF)
#define SCPI_QUEUE_MESSAGE_PARAM(param) (((message) & 0x3FFFFFFF) >> 8)

#define SCPI_QUEUE_SERIAL_MESSAGE(type, param) SCPI_QUEUE_MESSAGE(SCPI_QUEUE_MESSAGE_TARGET_SERIAL, type, param)
#define SCPI_QUEUE_ETHERNET_MESSAGE(type, param) SCPI_QUEUE_MESSAGE(SCPI_QUEUE_MESSAGE_TARGET_ETHERNET, type, param)
#define SCPI_QUEUE_MP_MESSAGE(type, param) SCPI_QUEUE_MESSAGE(SCPI_QUEUE_MESSAGE_TARGET_MP, type, param)

enum {
    SCPI_QUEUE_MESSAGE_TYPE_SAVE_LIST = 1,
    SCPI_QUEUE_MESSAGE_TYPE_SD_DETECT_IRQ,
    SCPI_QUEUE_MESSAGE_TYPE_DLOG_FILE_WRITE,
    SCPI_QUEUE_MESSAGE_TYPE_DLOG_STATE_TRANSITION,
    SCPI_QUEUE_MESSAGE_DLOG_SHOW_FILE,
    SCPI_QUEUE_MESSAGE_DLOG_LOAD_BLOCK,
    SCPI_QUEUE_MESSAGE_ABORT_DOWNLOADING,
    SCPI_QUEUE_MESSAGE_SCREENSHOT,
    SCPI_QUEUE_MESSAGE_TYPE_FILE_MANAGER_LOAD_DIRECTORY,
    SCPI_QUEUE_MESSAGE_TYPE_FILE_MANAGER_UPLOAD_FILE,
    SCPI_QUEUE_MESSAGE_TYPE_FILE_MANAGER_OPEN_IMAGE_FILE,
    SCPI_QUEUE_MESSAGE_TYPE_FILE_MANAGER_DELETE_FILE,
    SCPI_QUEUE_MESSAGE_TYPE_FILE_MANAGER_RENAME_FILE,
    SCPI_QUEUE_MESSAGE_DLOG_UPLOAD_FILE,
    SCPI_QUEUE_MESSAGE_FLASH_SLAVE_UPLOAD_HEX_FILE,
    SCPI_QUEUE_MESSAGE_TYPE_SHUTDOWN,
    SCPI_QUEUE_MESSAGE_TYPE_RECALL_PROFILE,
    SCPI_QUEUE_MESSAGE_TYPE_LISTS_PAGE_IMPORT_LIST,
    SCPI_QUEUE_MESSAGE_TYPE_LISTS_PAGE_EXPORT_LIST,
    SCPI_QUEUE_MESSAGE_TYPE_LOAD_PROFILE,
    SCPI_QUEUE_MESSAGE_TYPE_USER_PROFILES_PAGE_SAVE,
    SCPI_QUEUE_MESSAGE_TYPE_USER_PROFILES_PAGE_RECALL,
    SCPI_QUEUE_MESSAGE_TYPE_USER_PROFILES_PAGE_IMPORT,
    SCPI_QUEUE_MESSAGE_TYPE_USER_PROFILES_PAGE_EXPORT,
    SCPI_QUEUE_MESSAGE_TYPE_USER_PROFILES_PAGE_DELETE,
    SCPI_QUEUE_MESSAGE_TYPE_USER_PROFILES_PAGE_EDIT_REMARK,
    SCPI_QUEUE_MESSAGE_TYPE_EVENT_QUEUE_REFRESH
};

extern char g_listFilePath[CH_MAX][MAX_PATH_LENGTH];

bool isThreadAlive();

}
}
