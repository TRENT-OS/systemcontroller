/*
 * SystemController
 *
 * Copyright (C) 2022, HENSOLDT Cyber GmbH
 */

#pragma once

#include <stdint.h>

#include <platsupport/mach/serial.h>
#include <platsupport/plat/reset.h>

/* This maps respective device IDs from libplatsupport to corresponding clock IDs in Tegra X1 TRM */

static const uint32_t uart_rst_id_map[] = {
    [NV_UARTA] = SWR_UARTA_RST,
    [NV_UARTB] = SWR_UARTB_RST,
    [NV_UARTC] = SWR_UARTC_RST,
    [NV_UARTD] = SWR_UARTD_RST,
    [NV_UARTA_ASYNC] = SWR_UARTA_RST,
    [NV_UARTB_ASYNC] = SWR_UARTB_RST,
    [NV_UARTC_ASYNC] = SWR_UARTC_RST,
    [NV_UARTD_ASYNC] = SWR_UARTD_RST,
};