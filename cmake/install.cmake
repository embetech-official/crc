include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(PROJECT_LICENSE "MIT License")
set(PROJECT_COPYRIGHT "Embetech sp. z o.o.")

file(GLOB HEADERS_TO_CONFIGURE RELATIVE ${PROJECT_SOURCE_DIR}/src
     "${PROJECT_SOURCE_DIR}/src/include/embetech/*.h" 
)
file(GLOB SOURCES_TO_CONFIGURE RELATIVE ${PROJECT_SOURCE_DIR}/src
     "${PROJECT_SOURCE_DIR}/src/*.c" 
)

message(STATUS "Updating file headers in: ${HEADERS_TO_CONFIGURE} ${SOURCES_TO_CONFIGURE}")

install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/include/embetech
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/
        DESTINATION  ${CMAKE_INSTALL_PREFIX}
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

  foreach(source ${SOURCES_TO_CONFIGURE})
    set(exported_source \${CMAKE_INSTALL_PREFIX}/\${source})
    message(STATUS \"Configuring doxygen header: \${exported_source}\")
    configure_file(\${exported_source} \${exported_source})
  endforeach()  
  "
)

install(FILES LICENSE DESTINATION ${CMAKE_INSTALL_PREFIX}
        RENAME LICENSE.txt)
