# LLVM-Pass-Template
This repo is a template of the LLMV pass plugin. With this template you can focus on coding instead of building.

## How to Use
1. Compile the pass plugin
```
mkdir build
cd build
cmake ..
make
```

2. Use the pass plugin
```
cd ..
opt -load-pass-plugin=./build/MyPass.so -passes="MyPass" -S test.ll
```
