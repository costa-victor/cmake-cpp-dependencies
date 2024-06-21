
# Cpp CMake dependencies

This repository contains a C++11 project organized with CMake, consisting of two static libraries (`someLibA` and `someLibB`) and an application (`App`) that depends on these libraries.
Furthermore, the following topics represents the dependency chain:
- `someLibA` is a static library
- `someLibA/example` demonstrate how to use the `someLibA`
- `someLibB` is a static library, but it also depends on `someLibA` and therefore it's propagated when `someLibB` is consumed.
- `someLibB/example` demonstrate how to use the `someLibB` and its dependency `someLibA`.
- `App` depends on the `someLibA` and `someLibB`


_**NOTE:** Tested on macOS/Ubuntu, this may not work on Windows_

## Project Structure

```bash
├── App
│   ├── CMakeLists.txt   # CMake configuration for the application
│   └── src              # Source code for the application
├── README.md            # This README file
├── someLibA
│   ├── CMakeLists.txt   # CMake configuration for someLibA
│   ├── Config.cmake.in  # Configuration template for someLibA
│   ├── cmake            # CMake modules for someLibA
│   ├── example          # Example code using someLibA
│   ├── include          # Header files for someLibA
│   └── src              # Source code for someLibA
└── someLibB
    ├── CMakeLists.txt   # CMake configuration for someLibB
    ├── Config.cmake.in  # Configuration template for someLibB
    ├── cmake            # CMake modules for someLibB
    ├── example          # Example code using someLibB
    ├── include          # Header files for someLibB
    └── src              # Source code for someLibB
```

## Requirements

- CMake 3.20 or higher
- C++11 compatible compiler

## Building the Project

### Building someLibA

1. Navigate to the `someLibA` directory:

   ```bash
   cd someLibA
   ```

2. Create and navigate to the build directory:

   ```bash
   mkdir -p build
   cd build
   ```

3. Configure, build and install the library:

   ```bash
   cmake ..
   cmake --build . --target install
   ```

### Building someLibB

1. Navigate to the `someLibB` directory:

   ```bash
   cd someLibB
   ```

2. Create and navigate to the build directory:

   ```bash
   mkdir -p build
   cd build
   ```

3. Configure, build and install the library:

   ```bash
   cmake ..
   cmake --build . --target install
   ```

### Building and Running the Application

1. Navigate to the `App` directory:

   ```bash
   cd App
   ```

2. Create and navigate to the build directory:

   ```bash
   mkdir -p build
   cd build
   ```

3. Configure and build the application (make sure `someLibA` and `someLibB` are installed and found by CMake):

   ```bash
   ## Option 1
   cmake -DsomeLibA_DIR=/path/to/someLibA/install/dir -DsomeLibB_DIR=/path/to/someLibB/install/dir ..
   ## Option 2
   # Set the CMAKE_PREFIX_PATH variable in the CMakeLists.txt

   cmake --build .
   ./app
   ```


## Extra examples

### Example for someLibA

You can find example usage of `someLibA` in the `someLibA/example` directory.

### Example for someLibB

You can find example usage of `someLibB` in the `someLibB/example` directory.