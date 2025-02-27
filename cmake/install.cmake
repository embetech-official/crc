include(CMakePackageConfigHelpers)

set(HELPERS_DIR ${CMAKE_CURRENT_LIST_DIR}/embenet-toolchains/cmake/install_helpers)

set(METADATA_DIR cmake)
set(INCLUDE_DIR include)
set(LIBRARY_DIR lib/${CMAKE_LIBRARY_ARCHITECTURE})

set_target_properties(crc PROPERTIES EXPORT_NAME crc)

write_basic_package_version_file(
  crc-config-version.cmake COMPATIBILITY SameMajorVersion ARCH_INDEPENDENT
)

configure_package_config_file(
  ${HELPERS_DIR}/component-config.template.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/crc-config.cmake INSTALL_DESTINATION ${METADATA_DIR}
)

file(COPY_FILE ${HELPERS_DIR}/prefix_path_inject.template.txt
     ${CMAKE_CURRENT_BINARY_DIR}/CMakeLists.txt
)

install(TARGETS crc EXPORT crc_targets ARCHIVE DESTINATION ${LIBRARY_DIR})

install(DIRECTORY src/include/embetech DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crc-config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/crc-config-version.cmake
        DESTINATION ${METADATA_DIR}
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/CMakeLists.txt DESTINATION ${METADATA_DIR})

install(EXPORT crc_targets DESTINATION ${METADATA_DIR})
