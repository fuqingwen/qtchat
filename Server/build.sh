#!/bin/bash

# 设置Qt环境
export PATH="/Users/devin/Qt/6.8.0/macos/bin:$PATH"

# 清理并创建build目录
rm -rf build
mkdir -p build
cd build

# 运行cmake和make
cmake ..
make -j4

# 运行程序
open DuckChat.app