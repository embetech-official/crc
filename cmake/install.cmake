include(CMakePackageConfigHelpers)

# Multiple architectures get merged into a single install tree when packaging
# a release (see generate_artifacts.yml's package-core job), so every exported
# target name and targets file must be unique per architecture to avoid
# collisions. Cross toolchains normally set CMAKE_LIBRARY_ARCHITECTURE
# themselves; fall back to the same detection consumers use so local/native
# installs work too.
if (NOT CMAKE_LIBRARY_ARCHITECTURE)
  include(${CMAKE_CURRENT_LIST_DIR}/detect_architecture_triplet.cmake)
  detect_architecture_triplet(CMAKE_LIBRARY_ARCHITECTURE)
  if (NOT CMAKE_LIBRARY_ARCHITECTURE)
    message(FATAL_ERROR "Unable to auto-detect the target architecture triplet. Set CMAKE_LIBRARY_ARCHITECTURE manually.")
  endif ()
endif ()

set(METADATA_DIR cmake)
set(INCLUDE_DIR include)
set(LIBRARY_DIR lib/${CMAKE_LIBRARY_ARCHITECTURE})

set_target_properties(crc PROPERTIES EXPORT_NAME crc-${CMAKE_LIBRARY_ARCHITECTURE})
set_target_properties(crc PROPERTIES OUTPUT_NAME "crc-${PROJECT_VERSION}")
set_target_properties(crc PROPERTIES DEBUG_POSTFIX "-debug")

write_basic_package_version_file(crc-config-version.cmake COMPATIBILITY SameMajorVersion ARCH_INDEPENDENT)

configure_package_config_file(
  cmake/crc-config_template.cmake ${CMAKE_CURRENT_BINARY_DIR}/crc-config.cmake INSTALL_DESTINATION ${METADATA_DIR}
)

install(TARGETS crc EXPORT crc-${CMAKE_LIBRARY_ARCHITECTURE}-targets ARCHIVE DESTINATION ${LIBRARY_DIR}
        FILE_SET HEADERS DESTINATION ${INCLUDE_DIR}
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crc-config.cmake ${CMAKE_CURRENT_BINARY_DIR}/crc-config-version.cmake
              cmake/detect_architecture_triplet.cmake
        DESTINATION ${METADATA_DIR}
)

install(EXPORT crc-${CMAKE_LIBRARY_ARCHITECTURE}-targets NAMESPACE embetech:: DESTINATION ${METADATA_DIR}
        FILE crc-${CMAKE_LIBRARY_ARCHITECTURE}-targets.cmake
)

install(SCRIPT ${CMAKE_CURRENT_LIST_DIR}/install_header_licenses.cmake)

install(FILES LICENSE.txt DESTINATION .)
install(FILES REUSE.toml DESTINATION .)
install(DIRECTORY LICENSES DESTINATION .)
