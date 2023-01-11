/*
 * SystemController
 *
 * Copyright (C) 2022, HENSOLDT Cyber GmbH
 */

#pragma once

#include <stdint.h>

#include <platsupport/mach/serial.h>
#include <platsupport/plat/clock.h>

/* This maps respective device IDs from libplatsupport to corresponding BPMP IDs documented in the Cboot bootloader source code, clk-t194.h */

static const uint32_t uart_clk_id_map[] = {
    [NV_UARTA] = TEGRA194_CLK_UARTA,
    [NV_UARTB] = TEGRA194_CLK_UARTB,
    [NV_UARTC] = TEGRA194_CLK_UARTC,
    [NV_UARTD] = TEGRA194_CLK_UARTD,
    [NV_UARTA_ASYNC] = TEGRA194_CLK_UARTA,
    [NV_UARTB_ASYNC] = TEGRA194_CLK_UARTB,
    [NV_UARTC_ASYNC] = TEGRA194_CLK_UARTC,
    [NV_UARTD_ASYNC] = TEGRA194_CLK_UARTD,
};