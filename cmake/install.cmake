include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(METADATA_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/crc)

install(TARGETS crc EXPORT crc-targets ARCHIVE FILE_SET HEADERS)
install(EXPORT crc-targets NAMESPACE embetech:: DESTINATION ${METADATA_DIR})

write_basic_package_version_file(crc-config-version.cmake COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/crc-config_template.cmake ${CMAKE_CURRENT_BINARY_DIR}/crc-config.cmake INSTALL_DESTINATION ${METADATA_DIR}
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crc-config.cmake ${CMAKE_CURRENT_BINARY_DIR}/crc-config-version.cmake DESTINATION ${METADATA_DIR})

install(SCRIPT ${CMAKE_CURRENT_LIST_DIR}/install_header_licenses.cmake)
