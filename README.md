# FdF
This project is about creating a simplified 3D graphic representation of arelief landscape.
### Installation
FdF requires:
+ [CMake](https://cmake.org/)
+ [Minilibx](https://github.com/sxhondo/minilibx)
```sh
$ git clone --recurse-submodules https://github.com/sxhondo/fdf.git && cd fdf && make
```
This will create binary ./fdf in the directory

### Run
```sh
$ ./fdf <map>
```
Several test-maps are in the directory ./maps (sic!)

## Summary
+ uses Bresenham's line algorithm to connect points given in map
+ rotation is done by multiplying the rotation matrices and points
+ MacOS and Linux supported
