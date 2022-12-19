/*
 * SystemController
 *
 * Copyright (C) 2022, HENSOLDT Cyber GmbH
 */

#pragma once

#include <stdint.h>

#include <platsupport/mach/serial.h>
#include <platsupport/plat/clock.h>

/* This maps respective device IDs from libplatsupport to corresponding clock IDs in Tegra X2 TRM */

static const uint32_t uart_clk_id_map[] = {
    [NV_UARTA] = CLK_UARTA,
    [NV_UARTB] = CLK_UARTB,
    [NV_UARTC] = CLK_UARTC,
    [NV_UARTD] = CLK_UARTD,
    [NV_UARTA_ASYNC] = CLK_UARTA,
    [NV_UARTB_ASYNC] = CLK_UARTB,
    [NV_UARTC_ASYNC] = CLK_UARTC,
    [NV_UARTD_ASYNC] = CLK_UARTD,
};