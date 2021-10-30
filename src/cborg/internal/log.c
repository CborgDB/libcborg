/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <stdarg.h>

#include "cborg/internal/error.h"
#include "cborg/internal/log.h"

// Log format:
//<date-time-ms> <level> <pid> --- <thread-name> <logger-name> :<message>

void cb_log(FILE *output, const char *str, ...) {
  va_list va;
  va_start(va, str);
  vfprintf(output, str, va);
  va_end(va);
}

void cb_log_debug() { cb_log(stderr, "[DEBUG]: %s.\n", cb_strerror()); }

void cb_log_info() { cb_log(stderr, "[INFO]: %s.\n", cb_strerror()); }

void cb_log_warn() { cb_log(stderr, "[WARN]: %s.\n", cb_strerror()); }

void cb_log_error() { cb_log(stderr, "[ERROR]: %s.\n", cb_strerror()); }

void cb_log_fatal() { cb_log(stderr, "[FATAL]: %s.\n", cb_strerror()); }
