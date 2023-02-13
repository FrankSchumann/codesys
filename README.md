# codesys

# Conan package manager

## Install
Install conan packages and create files for building.
Must be done before Build

### Release
```bash
codesys $ conan install . --output-folder=build
```

### Debug
```bash
codesys $ conan install . --output-folder=build -s build_type=Debug
```

# CMake
Change directory to build.

```bash
codesys $ cd build
```

## Release
```bash
codesys $ cmake .. --preset release
```

## Debug
```bash
codesys $ cmake .. --preset debug
```

# Build

```bash
codesys $ cmake --build . -- -j4
```

# Test
Build and execute GoogleTest.

```bash
codesys/test $ conan install . --output-folder=build
```
```bash
codesys/test $ cd build
codesys/test/build $ cmake .. --preset=release
```
```bash
codesys/test/build $ cmake --build . -- -j4
```
```bash
codesys/test/build $ ./codesysTest
```

# Import Projects

## Eclipse CDT
Import the projects to Eclipse CDT based on CMake as follows:

File -> Open Projects from File System...

## Wind River Workbench
Import the projects to the Wind River Workbench based on CMake as follows:

- Create a new CMake RTP project at folder codesys
- revert changes to .gitignore
- revert changes to CMakeLists.txt

# Git
Delete all ignored/created files.

```bash
codesys $ git clean -fxd
```