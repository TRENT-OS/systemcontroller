/*
 * SystemController
 *
 * Copyright (C) 2022-2024, HENSOLDT Cyber GmbH
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * For commercial licensing, contact: info.cyber@hensoldt.net
 */

#include <platsupport/clock.h>
#include <platsupport/reset.h>

#include "systemController_plat.h"
#include "systemController_rpc.h"

#include "lib_debug/Debug.h"

// Platform specific uart_enable() function, which implements the logic described in the respective platform TRM
int device_enable(sys_ctrl_ctx_t *ctx, clk_id_t clk_id, reset_id_t rst_id) {

    int error = 0;

    // assert the device's reset (via communicating to the BPMP)
    error = reset_assert(ctx, rst_id);

    // enable clock to the device (via communicating to the BPMP)
    error = init_clock(ctx, clk_id);

    // deassert the device's reset (via communicating to the BPMP)
    error = reset_deassert(ctx, rst_id);

    return error;
}