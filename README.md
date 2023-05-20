# Template

Defines a submodule template.

## Layout structure

+ Template
  + [CMake/Modules](CMake/Modules) - Provides the link to common modules.
    + [CMake/Modules/ExternalTarget.cmake](https://github.com/chcly/CMakeModules/blob/master/ExternalTarget.cmake#L69) - Provides the means to embed modules.
  + [Test/googletest](Test/googletest) - Provides the link to googletest
  + [Source](Source) - Should contain the module contents.
  + [Test](Test) - Contains the setup to begin testing the source directory.

## Standalone/Embedded

+ The file [CMake/Configure.cmake](CMake/Configure.cmake) is used to define options specific to this submodule.
+ The if statement in [CMakeLists.txt](https://github.com/chcly/ModuleTemplate/blob/master/CMakeLists.txt#L29) is the primary branch between project types.
+ Declaring an external [target](https://github.com/chcly/CMakeModules/blob/master/ExternalTarget.cmake#L69) in the local Configure [file](CMake/Configure.cmake) allows embedding other projects into the solution.
+ The files [gitupdate.py](gitupdate.py) or [gitupdate.bat](gitupdate.bat) help to automate the process of cloning embedded projects.
+ The file [rename_initial_template.py](CMake/rename_initial_template.py) swaps occurrences of `Template` in the project.

## Testing

The testing directory is setup to work with [googletest](https://github.com/google/googletest).

## Building

Building with CMake and Make

```sh
mkdir build
cd build
cmake ..
make
```

Optional defines.

| Option                      | Description                                          | Default |
|:----------------------------|:-----------------------------------------------------|:-------:|
| Template_BUILD_TEST         | Build the unit test program.                         |   ON    |
| Template_AUTO_RUN_TEST      | Automatically run the test program.                  |   OFF   |
| Template_USE_STATIC_RUNTIME | Build with the MultiThreaded(Debug) runtime library. |   ON    |
