cmake_minimum_required(VERSION 3.5)
  set(FAMILY rp2040) 

  include($ENV{PICO_SDK_PATH}/lib/tinyusb/hw/bsp/family_support.cmake)
  include(pico_sdk_import.cmake)

  family_get_project_name(PROJECT ${CMAKE_CURRENT_LIST_DIR})
  
  project(${PROJECT})
  set(CMAKE_C_STANDARD 11)
  set(CMAKE_CXX_STANDARD 17)
  set(PICO_EXAMPLE_PATH $ENV{PICO_EXAMPLE_PATH})
  
  add_executable(${PROJECT})
  family_initialize_project(${PROJECT} ${CMAKE_CURRENT_LIST_DIR})
  
  target_sources(${PROJECT} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pwm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/regtable.c
    ${CMAKE_CURRENT_SOURCE_DIR}/noteonch.c
    ${CMAKE_CURRENT_SOURCE_DIR}/usb_descriptors.c
  )
  
  target_include_directories(${PROJECT} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PICO_SDK_PATH}/src/rp2_common/hardware_pwm/include
  )

  # enable usb output, disable uart output
  pico_enable_stdio_usb(${PROJECT} 1)
  family_configure_device_example(${PROJECT})
  
  