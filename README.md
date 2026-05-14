# 使用说明

1. rattler-build 打包 C++ 项目

2. pixi 安装、卸载 .conda 包，实现插件的管理

## rattler-build 使用

``` BASH
# 编译，默认为 .conda 包
rattler-build build --recipe recipe.yaml

# 编译，选择为 tar.bz2 包
rattler-build build --recipe recipe.yaml --package-format tarbz2
```

## pixi 使用

pixi 项目 = 一个目录 + pixi.toml 配置文件

```BASH
pixi init PixiDemo        # 初始化项目
cd PixiDemo
```

pixi 环境 = 实际安装包的隔离空间

```BASH
# 开发环境
pixi add --feature dev cmake ninja gdb

# pixi add rattler-build 会安装到所有环境，因为其在 [dependencies] 下添加，这是全局依赖（所有环境共享）
pixi add --feature dev rattler-build

pixi project environment add dev --feature dev

pixi shell -e dev # 进入 dev 环境


# 测试环境
pixi add --feature test gtest

pixi add --feature test pixi_demo

pixi remove --feature test pixi_demo

pixi project environment add test --feature test

pixi shell -e test  # 进入 test 环境

pixi project environment remove test  # 保留 feature，只删环境
```

``` BASH
pixi init # 在当前目录下初始化工程

pixi info # 查看当前项目的所有环境

pixi shell  # 进入当前目录项目的默认环境（default）

pixi shell -e <环境名>  # 进入指定环境（如果配置了多环境）

pixi project channel add ./output   # 添加本地 channel

pixi add pixi_demo   # 用包名安装，全局安装

pixi remove pixi_demo   # 用包名安装，全局安装

pixi run pixi_demo  # 运行安装的可执行文件
```