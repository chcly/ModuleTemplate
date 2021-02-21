cmake_minimum_required(VERSION 3.0)
project(Template)

# Set the module path to include scripts
set(CMAKE_MODULE_PATH  ${CMAKE_SOURCE_DIR}/CMake)
include(Configure)


if (Template_ExternalTarget)
    set(TargetFolders ${Template_TargetFolders})
    set(TargetName    ${Template_TargetName})
    set(TargetGroup   ${Template_TargetGroup})
else()
    subdirs(CMake)
    set(TargetFolders FALSE)
    set(TargetName Template)
    unset(TargetGroup )
endif()



subdirs(Source)
if (Template_BUILD_TEST)

    set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    subdirs(Test/googletest)

    subdirs(Test)
endif()
