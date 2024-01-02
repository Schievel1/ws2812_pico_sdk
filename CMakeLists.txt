cmake_minimum_required(VERSION 3.13)

include(pico-sdk/pico_sdk_init.cmake)

project(ws2812-example C)

pico_sdk_init()

add_executable(ws2812-example)

pico_generate_pio_header(ws2812-example ${CMAKE_CURRENT_LIST_DIR}/WS2812.pio)

target_sources(pcmeter-pico PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src/example.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ws2812.c
        )

target_include_directories(ws2812-example PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(ws2812-example  PUBLIC pico_stdlib hardware_pio)

pico_add_extra_outputs(pcmeter-pico)

pico_enable_stdio_usb(ws2812-example 1)
pico_enable_stdio_uart(ws2812-example 1)
