cmake_minimum_required(VERSION 3.0)
project(Template)

# Set the module path to include scripts
list(APPEND CMAKE_MODULE_PATH  ${Template_SOURCE_DIR}/CMake ${Template_SOURCE_DIR}/CMake/Modules)
include(Configure)

if (Template_ExternalTarget)

    set(TargetFolders ${Template_TargetFolders})
    set(TargetName    ${Template_TargetName})
    set(TargetGroup   ${Template_TargetGroup})
else()
    subdirs(CMake)

    set(TargetFolders FALSE)
    set(TargetName Template)
    set(TargetGroup )

    set(Template_INCLUDE  ${Template_SOURCE_DIR}/Source)
    set(Template_LIBRARY  ${TargetName})
endif()

subdirs(Source)

if (Template_BUILD_TEST)
    add_subdirectory(${GTEST_DIR})
    set(TargetGroup Units)
    if (TargetFolders)
        set_target_properties(gtest_main PROPERTIES FOLDER "${TargetGroup}")
        set_target_properties(gtest      PROPERTIES FOLDER "${TargetGroup}")
    endif()

    subdirs(Test)
endif()
