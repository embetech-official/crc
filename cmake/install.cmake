include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set_target_properties(crc PROPERTIES EXPORT_NAME crc)
set(CMAKES_EXPORT_DIR cmake)

# Make a list of all headers to be configured
file(GLOB HEADERS_TO_CONFIGURE RELATIVE ${PROJECT_SOURCE_DIR}/src
     "${PROJECT_SOURCE_DIR}/src/include/embetech/*.h" 
)
# Make a list of all sources to be configured
file(GLOB SOURCES_TO_CONFIGURE RELATIVE ${PROJECT_SOURCE_DIR}/src
     "${PROJECT_SOURCE_DIR}/src/*.c" 
)

message(STATUS "Updating file headers in: ${HEADERS_TO_CONFIGURE} ${SOURCES_TO_CONFIGURE}")
message(STATUS "Installing component: ${CMAKE_INSTALL_DEFAULT_COMPONENT_NAME}")
# Rules for installing cmake files
write_basic_package_version_file(crc-config-version.cmake COMPATIBILITY SameMajorVersion ARCH_INDEPENDENT)
configure_package_config_file(
  ${PROJECT_SOURCE_DIR}/cmake/crc-config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/crc-config.cmake INSTALL_DESTINATION ${CMAKES_EXPORT_DIR}
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crc-config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/crc-config-version.cmake DESTINATION ${CMAKES_EXPORT_DIR}
)

# Install the main target (binary library)
install(TARGETS crc EXPORT crc_targets)

# Install the headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/include/embetech
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        COMPONENT install-source
)

# Install the sources
install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/
        DESTINATION  ${CMAKE_INSTALL_PREFIX}/source
        COMPONENT install-source EXCLUDE_FROM_ALL
        PATTERN "include" EXCLUDE
        PATTERN "CMakeLists.txt" EXCLUDE
)

# Invoke the code below during the install phase - this will replace the placeholders in the headers
# with the actual values
install(
  CODE "
  set(PROJECT_LICENSE \"${PROJECT_LICENSE}\")
  set(PROJECT_COPYRIGHT \"${PROJECT_COPYRIGHT}\")
  set(PROJECT_VERSION \"${PROJECT_VERSION}\")

  foreach(header ${HEADERS_TO_CONFIGURE})
    set(exported_header \${CMAKE_INSTALL_PREFIX}/\${header})
    message(STATUS \"Configuring doxygen header: \${exported_header}\")
    configure_file(\${exported_header} \${exported_header})
  endforeach()
  "
  COMPONENT install-source
)


# Invoke the code below during the install phase - this will replace the placeholders in the sources
# with the actual values
install(
  CODE "
  set(PROJECT_LICENSE \"${PROJECT_LICENSE}\")
  set(PROJECT_COPYRIGHT \"${PROJECT_COPYRIGHT}\")
  set(PROJECT_VERSION \"${PROJECT_VERSION}\")

  foreach(source ${SOURCES_TO_CONFIGURE})
    set(exported_source \${CMAKE_INSTALL_PREFIX}/source/\${source})
    message(STATUS \"Configuring doxygen header: \${exported_source}\")
    configure_file(\${exported_source} \${exported_source})
  endforeach()  
  "
  COMPONENT install-source EXCLUDE_FROM_ALL
)

# Install the license file
install(FILES LICENSE DESTINATION ${CMAKE_INSTALL_PREFIX} RENAME LICENSE.txt  COMPONENT install-source)

install(EXPORT crc_targets NAMESPACE embetech:: DESTINATION ${CMAKES_EXPORT_DIR})