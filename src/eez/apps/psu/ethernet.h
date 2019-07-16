/*
 * EEZ PSU Firmware
 * Copyright (C) 2015-present, Envox d.o.o.
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <eez/apps/psu/scpi/psu.h>

namespace eez {
namespace psu {
namespace ethernet {

extern TestResult g_testResult;
extern scpi_t g_scpiContext;

void init();
bool test();

#define ETHERNET_CONNECTED 1
#define ETHERNET_CLIENT_CONNECTED 2
#define ETHERNET_CLIENT_DISCONNECTED 3
#define ETHERNET_INPUT_AVAILABLE 4

void onQueueMessage(uint32_t type, uint32_t param);

uint32_t getIpAddress();

bool isConnected();

// this function is called when ethernet settings are changed,
// and it should reconnect to the ethernet with these settings
void update();

} // namespace ethernet
} // namespace psu
} // namespace eez
