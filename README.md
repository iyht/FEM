## Introduction

This is my implementation of FEM assignment in [CSC417/CSC2549-Physics-based Animation](https://github.com/dilevin/CSC417-physics-based-animation).
![Armadillo simulated via Finite Element Elasticity](images/armadillo.gif)

## Build & Execution
```
git submodule update --init --recursive
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make 
./a3-finite-elements-3d
```
