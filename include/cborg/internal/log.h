/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_INTERNAL_LOG_H
#define _CBORG_INTERNAL_LOG_H

#include <stdio.h>
#include <stdlib.h>

#define DEBUG_LEVEL 0
#define INFO_LEVEL 1
#define WARN_LEVEL 2
#define ERROR_LEVEL 3
#define FATAL_LEVEL 4

void cb_log(FILE *output, const char *str, ...);

void cb_log_debug();

void cb_log_info();

void cb_log_warn();

void cb_log_error();

void cb_log_fatal();

#endif
