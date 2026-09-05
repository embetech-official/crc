find_package(Doxygen QUIET)
if (NOT Doxygen_FOUND)
  message(STATUS "Doxygen not found, documentation will not be generated")
  return()
endif ()

# Doxygen Awesome theme: shared look, sidebar navigation and dark mode across every embetech
# component's docs. DOWNLOAD_ONLY - it's a pile of static CSS/JS, nothing to build.
CPMAddPackage(NAME doxygen-awesome-css GITHUB_REPOSITORY jothepro/doxygen-awesome-css VERSION 2.4.2 GIT_TAG v2.4.2 DOWNLOAD_ONLY YES)

set(DOXYGEN_PROJECT_NAME "EMBETECH CRC")
set(DOXYGEN_PROJECT_NUMBER ${PROJECT_VERSION})
set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
set(DOXYGEN_TIMESTAMP YES)
set(DOXYGEN_CASE_SENSE_NAMES NO)
set(DOXYGEN_SHOW_INCLUDE_FILES NO)
set(DOXYGEN_SORT_MEMBER_DOCS NO)
set(DOXYGEN_LAYOUT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/DoxygenLayout.xml)
set(DOXYGEN_EXAMPLE_PATH ${PROJECT_SOURCE_DIR}/examples)
set(DOXYGEN_REFERENCES_LINK_SOURCE NO)
set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
set(DOXYGEN_VERBATIM_HEADERS NO)
set(DOXYGEN_GENERATE_LATEX NO)

# Nested under doc/crc/<version>/ so a release's install tree carries versioned documentation
# alongside include/ and lib/<arch>/ in the same combined archive.
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/doc/crc/${PROJECT_VERSION})
set(DOXYGEN_GENERATE_TAGFILE ${DOXYGEN_OUTPUT_DIRECTORY}/html/embetech_crc.tag)

set(DOXYGEN_ALIASES [[purpose=@par Purpose:]] [[license=@par License:]] [[compiler=@par Compiler:]] [[ hardware=@par Hardware:]]
                    [[comments=@par Comments:]] [[doc=@par Documented using:]]
)
set(DOXYGEN_WARN_AS_ERROR YES)

# Doxygen Awesome "sidebar-only" layout. Dark mode follows the OS/browser color-scheme
# preference automatically via CSS - no custom HTML_HEADER or JS needed for that.
set(DOXYGEN_HTML_COLORSTYLE LIGHT) # required by doxygen-awesome
set(DOXYGEN_DISABLE_INDEX NO)
set(DOXYGEN_FULL_SIDEBAR NO)
set(DOXYGEN_HTML_EXTRA_STYLESHEET
    ${doxygen-awesome-css_SOURCE_DIR}/doxygen-awesome.css ${doxygen-awesome-css_SOURCE_DIR}/doxygen-awesome-sidebar-only.css
)

# Create local copy of public headers and configure VERSION and LICENSE information
include(${PROJECT_SOURCE_DIR}/cmake/install_header_licenses.cmake)
get_target_property(CRC_PUBLIC_HEADER_DIR crc HEADER_DIRS)
get_target_property(CRC_PUBLIC_HEADERS crc HEADER_SET)
set(CRC_DOC_STAGED_HEADERS_DIR ${CMAKE_CURRENT_BINARY_DIR}/staged_headers)
foreach (header ${CRC_PUBLIC_HEADERS})
  file(RELATIVE_PATH relative_header ${CRC_PUBLIC_HEADER_DIR} ${header})
  crc_configure_license_header(${header} ${CRC_DOC_STAGED_HEADERS_DIR}/${relative_header})
endforeach ()

# Strip the staged/build paths so generated docs show clean header names instead of build/gcc*/doc/staged_headers/...
set(DOXYGEN_STRIP_FROM_PATH ${CRC_DOC_STAGED_HEADERS_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

doxygen_add_docs(crc_doc ALL ${CMAKE_CURRENT_SOURCE_DIR} ${CRC_DOC_STAGED_HEADERS_DIR} COMMENT "Generate documentation")
