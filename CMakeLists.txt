cmake_minimum_required(VERSION 3.13)

include(pico-sdk/pico_sdk_init.cmake)

project(ws2812-example)

pico_sdk_init()

add_executable(${PROJECT_NAME})

pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/WS2812.pio)

target_sources(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/example.c
        ${CMAKE_CURRENT_LIST_DIR}/ws2812.c
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC pico_stdlib hardware_pio)
# target_link_libraries(${PROJECT_NAME} PUBLIC pico_stdlib pico_unique_id tinyusb_device tinyusb_board hardware_pwm hardware_pio)

pico_add_extra_outputs(${PROJECT_NAME})

pico_enable_stdio_usb(ws2812-example 1)
pico_enable_stdio_uart(ws2812-example 1)
