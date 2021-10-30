/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_CBOR_STRING_H
#define _CBORG_CBOR_STRING_H

#include "cborg/cbor/item.h"

cbor_item_t *cb_cbor_new_string();

cbor_item_t *cb_cbor_delete_string();

char *cb_cbor_get_string(cbor_item_t *item);

#endif
