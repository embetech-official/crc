include(CMakePackageConfigHelpers)

set(METADATA_DIR cmake/crc)

write_basic_package_version_file(crc-config-version.cmake COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  ${PROJECT_SOURCE_DIR}/cmake/crc-config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/crc-config.cmake
  INSTALL_DESTINATION ${METADATA_DIR}
)

include(GNUInstallDirs)
install(TARGETS crc EXPORT crc_targets)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/include/embetech
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crc-config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/crc-config-version.cmake DESTINATION ${METADATA_DIR}
)

install(EXPORT crc_targets NAMESPACE embetech:: DESTINATION ${METADATA_DIR})
