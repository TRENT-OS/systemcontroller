/*
 * SystemController
 *
 * Copyright (C) 2022, HENSOLDT Cyber GmbH
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

    uint32_t source = get_clock_source(ctx, clk_id);
    Debug_LOG_INFO("clock source = %u\n", source);

    freq_t freq = get_freq(ctx, clk_id);

    source = set_clock_source(ctx, clk_id, 14);

    freq = set_freq(ctx, clk_id, 19200000);

    freq = get_freq(ctx, clk_id);
    Debug_LOG_INFO("clock frequency = %" PRIu64 "\n", freq);

    // deassert the device's reset (via communicating to the BPMP)
    error = reset_deassert(ctx, rst_id);

    return error;
}