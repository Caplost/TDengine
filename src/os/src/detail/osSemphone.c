/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#define _DEFAULT_SOURCE
#include "os.h"

#ifndef TAOS_OS_FUNC_SEMPHONE

int tsem_wait(tsem_t* sem) {
  int ret = 0;
  do {
    ret = sem_wait(sem);
  } while (ret != 0 && errno == EINTR);
  return ret;
}

#endif

#ifndef TAOS_OS_FUNC_SEMPHONE_PTHREAD

bool    taosCheckPthreadValid(pthread_t thread) { return thread != 0; }
int64_t taosGetPthreadId() { return (int64_t)pthread_self(); }
void    taosResetPthread(pthread_t *thread) { *thread = 0; }
bool    taosComparePthread(pthread_t first, pthread_t second) { return first == second; }

#endif