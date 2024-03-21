/*
 * SystemController
 *
 * Copyright (C) 2022-2024, HENSOLDT Cyber GmbH
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * For commercial licensing, contact: info.cyber@hensoldt.net
 */

#pragma once

#include <stdint.h>

#include <platsupport/mach/serial.h>
#include <platsupport/plat/clock.h>

/* This maps respective device IDs from libplatsupport to corresponding clock IDs in Tegra X1 TRM */

static const uint32_t uart_clk_id_map[] = {
    [NV_UARTA] = CLK_ENB_UARTA,
    [NV_UARTB] = CLK_ENB_UARTB,
    [NV_UARTC] = CLK_ENB_UARTC,
    [NV_UARTD] = CLK_ENB_UARTD,
    [NV_UARTA_ASYNC] = CLK_ENB_UARTA,
    [NV_UARTB_ASYNC] = CLK_ENB_UARTB,
    [NV_UARTC_ASYNC] = CLK_ENB_UARTC,
    [NV_UARTD_ASYNC] = CLK_ENB_UARTD,
};