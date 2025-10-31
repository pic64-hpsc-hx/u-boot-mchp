#------------------------------------------------------------------------------
# (c) 2023 Microchip Technology Inc.
# SPDX-License-Identifier: MIT
#------------------------------------------------------------------------------

target_sources(${TARGET_LIB} PUBLIC 
    p64h_sysc_errors.c    
    p64h_sysc_ddr_defs.c    
    p64h_sysc_errors_decode.c    
)

if (DEFINED INSTALL_CSRC)
    if (${INSTALL_CSRC} EQUAL 1)
        install(FILES ${SYSC_REMOTE_DIR}/src/generated/CMakeLists.txt DESTINATION src/generated)
        file(GLOB INSTALL_FILES ${SYSC_REMOTE_DIR}/src/generated/*.c )
        install(FILES ${INSTALL_FILES} DESTINATION src/generated)
        file(GLOB INSTALL_FILES ${SYSC_REMOTE_DIR}/include/generated/*.h )
        install(FILES ${INSTALL_FILES} DESTINATION include/generated)
    endif()
endif()