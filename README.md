# Template

This is a template repo (insert  description here).

Its purpose is to define the initial project structure for sub-modules. A sub-module should be able to stand on its own, or included in larger projects as a component piece.

If the module itself requires extra dependencies then they should be included into the module as sub-modules. The `${PROJECT}_ExternalTarget` variable is used to determine whether or not to compile dependencies locally or have them resolved later in the larger project.

if `${PROJECT}_ExternalTarget` is false then the module should be built as a standalone project.

Dependencies should adhere to the same naming strategy to keep everything consistent. Sub-modules should define the same include and library  variables relative to the `${PROJECT}_ExternalTarget` variable.

For example:

```cmake
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

## CMakeLists.txt - in larger project

set(Utils_ExternalTarget  TRUE)
set(Utils_TargetName      UtilsAlias)
set(Utils_TargetGroup     VisualStudioFolderName)
set(Utils_INCLUDE         some/path/to/utils/module)
set(Utils_LIBRARY         ${Utils_TargetName})
subdirs(Utils)

## CMakeLists.txt - In Utils


if (Utils_ExternalTarget)
    # Copy of the larger project's settings

    set(TargetFolders ${Utils_TargetFolders})
    set(TargetName    ${Utils_TargetName})
    set(TargetGroup   ${Utils_TargetGroup})
else()

    # Settings for the standalone project
  
    set(TargetFolders FALSE)
    set(TargetName Utils)
    unset(TargetGroup )


endif()



## When building the library 


add_library(${TargetName} ... )

if (TargetFolders)

    set_target_properties(
        ${TargetName} 
        PROPERTIES FOLDER "${TargetGroup}"
    )

endif()


## When linking against the module

include_directories(${Utils_INCLUDE})

add_executable(HelloWorld main.cpp)

target_link_libraries(HelloWorld  ${Utils_LIBRARY})


```





## Building
Building with CMake

```txt
mkdir build
cd build
cmake ..
```


