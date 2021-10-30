/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "cborg/internal/error.h"

int cb_errno() { return (errno == 0) ? 0 : errno; }

const char *cb_strerror() {
  return (errno == 0) ? "Unknown error" : strerror(errno);
}

void cb_error() { cb_log_error(); }
