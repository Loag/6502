# 6502

implement 6502 without ai

the intent of the project is to get familiar holistically with cpp as well as build on writing emulators.

## Requirements

- real build system
- real debugging loop
- standard project structure

``` zsh

# build dev
cmake --preset dev-debug
cmake --build --preset build-debug

# release
cmake --preset dev-release
cmake --build --preset build-release

# run
./build/dev-debug/emulator6502

# local install
cmake --install build/dev-release --prefix ./dist
```

