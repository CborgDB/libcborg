/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_INTERNAL_ERROR_H
#define _CBORG_INTERNAL_ERROR_H
#include <stdlib.h>

int cb_errno();

const char *cb_strerror();

void cb_error();

void cb_log_debug();

void cb_log_info();

void cb_log_warn();

void cb_log_error();

void cb_log_fatal();

#endif
