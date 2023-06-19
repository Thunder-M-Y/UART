# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Espressif/frameworks/esp-idf-v4.4.4/components/bootloader/subproject"
  "D:/Desktop/esp-idf/uart/build/bootloader"
  "D:/Desktop/esp-idf/uart/build/bootloader-prefix"
  "D:/Desktop/esp-idf/uart/build/bootloader-prefix/tmp"
  "D:/Desktop/esp-idf/uart/build/bootloader-prefix/src/bootloader-stamp"
  "D:/Desktop/esp-idf/uart/build/bootloader-prefix/src"
  "D:/Desktop/esp-idf/uart/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Desktop/esp-idf/uart/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
