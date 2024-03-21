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

#include <sel4/simple_types.h>

#include "plat/plat.h"

#ifdef BPMP_EXISTS
#include <tx2bpmp/bpmp.h>
#endif

// keeping track of different interfaces the SystemController is offering
enum sysctrl_interfaces {
    IF_UART
};

// high-level representation of an individual clock
typedef struct {
    bool initialised;
    seL4_Word owner;
    clk_t *clk;
} clock_entry_t;

typedef struct {
    // system interface handle
    ps_io_ops_t io_ops;
    // interface to BPMP
#ifdef BPMP_EXISTS
    struct tx2_bpmp bpmp;
#endif
    // representation of all available clocks, providing the base for the clock tree
    clock_entry_t clock_table[NCLOCKS];
} sys_ctrl_ctx_t;

seL4_Word get_client_id(enum sysctrl_interfaces sysctrl_if);

int init_clock(sys_ctrl_ctx_t *ctx, clk_id_t clk_id);

int set_gate_mode(sys_ctrl_ctx_t *ctx, clock_gate_t gate, clock_gate_mode_t mode);

uint32_t get_clock_source(sys_ctrl_ctx_t *ctx, clk_id_t clk_id);

uint32_t set_clock_source(sys_ctrl_ctx_t *ctx, clk_id_t clk_id, uint32_t clk_src);

freq_t get_freq(sys_ctrl_ctx_t *ctx, clk_id_t clk_id);

freq_t set_freq(sys_ctrl_ctx_t *ctx, clk_id_t clk_id, freq_t hz);

int register_child_clock(sys_ctrl_ctx_t *ctx, clk_id_t parent, clk_id_t child);

int reset_assert(sys_ctrl_ctx_t *ctx, reset_id_t id);

int reset_deassert(sys_ctrl_ctx_t *ctx, reset_id_t id);