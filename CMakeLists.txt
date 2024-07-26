cmake_minimum_required(VERSION 3.10)
project(srt_ads_replacer)

set(CMAKE_CXX_STANDARD 11)

# SRT
find_library(SRT_LIB NAMES srt)
include_directories(/usr/local/include/srt)

# FFmpeg
find_package(PkgConfig REQUIRED)
pkg_check_modules(AVFORMAT libavformat REQUIRED)
pkg_check_modules(AVCODEC libavcodec REQUIRED)
pkg_check_modules(AVUTIL libavutil REQUIRED)
include_directories(${AVFORMAT_INCLUDE_DIRS} ${AVCODEC_INCLUDE_DIRS} ${AVUTIL_INCLUDE_DIRS})

# Source files
file(GLOB SOURCES "src/*.cpp")

add_executable(srt_ads_replacer ${SOURCES})
target_link_libraries(srt_ads_replacer ${SRT_LIB} ${AVFORMAT_LIBRARIES} ${AVCODEC_LIBRARIES} ${AVUTIL_LIBRARIES})
