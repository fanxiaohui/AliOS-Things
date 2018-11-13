/*
 * Copyright (C) 2015-2017 Alibaba Group Holding Limited
 */

#include <tlsf.h>

static tlsf_t tlsf_ptr = NULL;

void *umm_init(void *mem, size_t size)
{
    tlsf_ptr = tlsf_create_with_pool(mem, size);

    return tlsf_ptr;
}

void *umm_malloc(size_t size)
{
    if (tlsf_ptr == NULL) {
        return NULL;
    }

    return tlsf_malloc(tlsf_ptr, size);
}

void *umm_realloc(void *ptr, size_t size)
{
    if (tlsf_ptr == NULL) {
        return NULL;
    }

    return tlsf_realloc(tlsf_ptr, ptr, size);
}

void umm_free(void *ptr)
{
    if (tlsf_ptr == NULL) {
        return;
    }

    tlsf_free(tlsf_ptr, ptr);
}

