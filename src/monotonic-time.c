/*******************************************************************************
 * Copyright (c) 2018 Wind River Systems, Inc. All Rights Reserved.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Keith Holman - initial implementation and documentation
 *******************************************************************************/

#include <stdio.h>
#include <time.h>

time_t monotonic_time(time_t * set_time)
{
  #if defined(WIN32) || defined(WIN64)
    *set_time = (time_t)GetTickCount();
    return *set_time;
  #else
  struct timespec now;

	clock_gettime(CLOCK_MONOTONIC, &now);
  if (set_time != NULL)
    *set_time = now.tv_sec;
  return now.tv_sec;
  #endif
}
