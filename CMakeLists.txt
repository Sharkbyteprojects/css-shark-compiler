cmake_minimum_required (VERSION 3.8)

project ("CSS SHARK")

add_library(csslib STATIC "cssshark.cpp")
add_executable (cssshark "sjs.cpp")
target_link_libraries(cssshark csslib)

install(TARGETS csslib DESTINATION lib)
install(TARGETS cssshark DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/cssshark.hpp" DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
include(CPack)
