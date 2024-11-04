#!/bin/bash
# 设置Qt环境
export PATH="/Users/devin/Qt/6.8.0/macos/bin:$PATH"

# 创建build目录（如果不存在）
mkdir -p build
cd build

# 运行qmake和make
qmake ../Client.pro
make

# 运行程序（可选）
open DuckChat.app