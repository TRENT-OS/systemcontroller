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
#include <platsupport/plat/reset.h>

/* This maps respective device IDs from libplatsupport to corresponding clock IDs in Tegra X2 TRM */

static const uint32_t uart_rst_id_map[] = {
    [NV_UARTA] = RESET_UARTA,
    [NV_UARTB] = RESET_UARTB,
    [NV_UARTC] = RESET_UARTC,
    [NV_UARTD] = RESET_UARTD,
    [NV_UARTA_ASYNC] = RESET_UARTA,
    [NV_UARTB_ASYNC] = RESET_UARTB,
    [NV_UARTC_ASYNC] = RESET_UARTC,
    [NV_UARTD_ASYNC] = RESET_UARTD,
};