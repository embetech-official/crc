@PACKAGE_INIT@

include(CMakeFindDependencyMacro)
find_dependency(embeutils REQUIRED)

include("${CMAKE_CURRENT_LIST_DIR}/@PROJECT_NAME@-targets.cmake")
