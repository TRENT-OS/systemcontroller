/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <platsupport/io.h>
#include <utils/attribute.h>

#include "systemController_rpc.h"

WEAK int plat_init(ps_io_ops_t *io_ops);

int device_enable(sys_ctrl_ctx_t *ctx, clk_id_t clk_id, reset_id_t rst_id);