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
    /* Provide the steps required to enable a device on the Jetson TX1;
     * Call generic high-level clock and reset functions provided by systemController_rpc.c, which then map onto the actual
     * TX1 platform specific clock and reset functions implemented in libplatsupport; for the TX1, the steps are described in the
     * Nvidia Tegra TX1 TRM, chapter 5.17:
     * - check if device's reset is asserted (via RST_DEVICES_L/H/U/V/W/X/Y registers)
     * - enable clock to the device (via CLK_OUT_ENB_L/H/U/V/W/X/Y registers)
     * - change clock divisor to the device (via CLK_SOURCE_<mod> register)
     * - wait 2 μs to make sure clock divider has changed
     * - change clock source to the device (via CLK_SOURCE_<mod> register)
     * - wait 2 μs to make sure clock source/device logic is stabilized
     * - deassert the device's reset (via RST_DEVICES_L/H/U/V/W/X/Y registers)
     */

    int error = 0;

    // assert the device's reset (via communicating to the BPMP)
    error = reset_assert(ctx, rst_id);

    // enable clock to the device (via communicating to the BPMP)
    error = init_clock(ctx, clk_id);

    /* TODO: change clock source to the device; currently not working,
     * so the default clock source is kept
     */

    // deassert the device's reset (via communicating to the BPMP)
    error = reset_deassert(ctx, rst_id);

    return error;
}