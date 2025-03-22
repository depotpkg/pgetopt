cmake_minimum_required(VERSION 3.2)
project(pgetopt VERSION 1.0.0 LANGUAGES C)

option(BUILD_POPT_EXAMPLE "Set to ON to build pgetopt example." OFF)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(pgetopt STATIC pgetopt.c pgetopt.h)

target_include_directories(pgetopt
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_compile_definitions(pgetopt PRIVATE POPT_IMPLEMENTATION)

set_target_properties(pgetopt PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(pgetopt PROPERTIES PUBLIC_HEADER pgetopt.h)

if(BUILD_POPT_EXAMPLE)
  add_subdirectory(example)
endif()

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)

# Install
install(TARGETS pgetopt
    EXPORT pgetopt-targets
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(EXPORT pgetopt-targets
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)

install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)
