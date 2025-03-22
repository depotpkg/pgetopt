# pgetopt

pgetopt is a fully portable GNU `getopt` implementation.

## Installation

```
mkdir build && cd build
cmake ..
make && make install
```

or using [CPM](https://github.com/cpm-cmake/CPM.cmake) in your CMake project:

```cmake
CPMAddPackage(
  NAME pgetopt
  GITHUB_REPOSITORY depotpkg/pgetopt
  GIT_TAG master
)
```

## License

The MIT License.
