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

    // enable clock to the device (via CLK_OUT_ENB_L/H/U/V/W/X/Y registers)
    error = init_clock(ctx, clk_id);

    /* Change clock source to the device (via CLK_SOURCE_<mod> register);
     * Here: selects pllp_ou0 with 408MHz as clock
     */
    set_freq(ctx, clk_id, 0);

    // deassert the device's reset (via RST_DEVICES_L/H/U/V/W/X/Y registers)
    error = reset_deassert(ctx, rst_id);

    return error;
}