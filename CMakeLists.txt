#
# SystemController
#
# Copyright (C) 2022-2024, HENSOLDT Cyber GmbH
#
# SPDX-License-Identifier: GPL-2.0-or-later
#
# For commercial licensing, contact: info.cyber@hensoldt.net
#


cmake_minimum_required(VERSION 3.8.2)

function(SystemController_DeclareCAmkESComponent
    name
)
    if(KernelArchARM)
        set(CAmkESDTS ON CACHE BOOL "" FORCE)
    endif()

    # running CAMkES files though the C pre processor should be enabled by
    # default in the seL4/CAmkES build system and the SDK also enables this,
    # but just to play safe we ensure once more here that it is enabled.
    set(CAmkESCPP ON CACHE BOOL "" FORCE)

    CAmkESAddCPPInclude(
        "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/include"
    )

    CAmkESAddImportPath(
        "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/server/include/plat/${KernelPlatform}"
    )

    CAmkESAddCPPInclude(
        "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/server/include/plat/${KernelPlatform}"
    )

    if(("${KernelPlatform}" STREQUAL "tx2") OR ("${KernelPlatform}" STREQUAL "xavier"))
        set(ClockServerExtraLibs platsupportports)
    endif()

    if(("${KernelPlatform}" STREQUAL "tx2") OR ("${KernelPlatform}" STREQUAL "xavier"))
        BPMPServer_DeclareCAmkESComponent(
            BPMPServer
        )
    endif()

    DeclareCAmkESComponent(
        ${name}
        SOURCES
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/server/src/systemController_rpc.c
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/server/src/plat/${KernelPlatform}/plat.c
        INCLUDES
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/server/include
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/server/include/plat/${KernelPlatform}
        C_FLAGS
            -Wall
            -Werror
        LIBS
            os_core_api
            lib_debug
            lib_macros
            platsupport
            ${ClockServerExtraLibs}
    )

endfunction()