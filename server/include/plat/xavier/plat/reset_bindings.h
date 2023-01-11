/*
 * SystemController
 *
 * Copyright (C) 2022, HENSOLDT Cyber GmbH
 */

#pragma once

#include <stdint.h>

#include <platsupport/mach/serial.h>
#include <platsupport/plat/reset.h>

/* This maps respective device IDs from libplatsupport to corresponding BPMP IDs documented in the Cboot bootloader source code, reset-t194.h */

static const uint32_t uart_rst_id_map[] = {
    [NV_UARTA] = TEGRA194_RESET_UARTA,
    [NV_UARTB] = TEGRA194_RESET_UARTB,
    [NV_UARTC] = TEGRA194_RESET_UARTC,
    [NV_UARTD] = TEGRA194_RESET_UARTD,
    [NV_UARTA_ASYNC] = TEGRA194_RESET_UARTA,
    [NV_UARTB_ASYNC] = TEGRA194_RESET_UARTB,
    [NV_UARTC_ASYNC] = TEGRA194_RESET_UARTC,
    [NV_UARTD_ASYNC] = TEGRA194_RESET_UARTD,
};