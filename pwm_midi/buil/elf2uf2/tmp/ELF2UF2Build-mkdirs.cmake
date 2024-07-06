# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/kaki/Documents/pico/pico-sdk/tools/elf2uf2"
  "/Users/kaki/Documents/Raspi_Pico/pwm_midi/buil/elf2uf2"
  "/Users/kaki/Documents/Raspi_Pico/pwm_midi/buil/elf2uf2"
  "/Users/kaki/Documents/Raspi_Pico/pwm_midi/buil/elf2uf2/tmp"
  "/Users/kaki/Documents/Raspi_Pico/pwm_midi/buil/elf2uf2/src/ELF2UF2Build-stamp"
  "/Users/kaki/Documents/Raspi_Pico/pwm_midi/buil/elf2uf2/src"
  "/Users/kaki/Documents/Raspi_Pico/pwm_midi/buil/elf2uf2/src/ELF2UF2Build-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/kaki/Documents/Raspi_Pico/pwm_midi/buil/elf2uf2/src/ELF2UF2Build-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/kaki/Documents/Raspi_Pico/pwm_midi/buil/elf2uf2/src/ELF2UF2Build-stamp${cfgdir}") # cfgdir has leading slash
endif()
