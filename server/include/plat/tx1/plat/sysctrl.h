/*
 * Copyright (C) 2022, HENSOLDT Cyber GmbH
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma once

#define HARDWARE_SYSTEM_CONTROLLER_EXTRA_IMPORTS

#define HARDWARE_SYSTEM_CONTROLLER_COMPONENT

#define HARDWARE_SYSTEM_CONTROLLER_INTERFACES   \
    emits Dummy dummy_source;       \
    consumes Dummy car;

#define HARDWARE_SYSTEM_CONTROLLER_EXTRA_INTERFACES

#define HARDWARE_SYSTEM_CONTROLLER_ATTRIBUTES

#define HARDWARE_SYSTEM_CONTROLLER_COMPOSITION  \
    connection seL4DTBHardware car_conn(from dummy_source, to car);

#define HARDWARE_SYSTEM_CONTROLLER_CONFIG                           \
    car.dtb = dtb({ "path" : "/clock@60006000" });