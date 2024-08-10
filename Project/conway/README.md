# 模拟Game of Life的程序

## Contents

- [conway.c](conway.c): Conway 功能实现
- [main.c](main.c): Conway游戏模拟

## 编译要求

调用了 math-soft/bmp/draw.c 中的函数用于产生 BMP文件.
配备了Makefile文件，可以直接如下编译并得到lifegame的可执行文件，具体编译依赖见Makefile文件.

```shell
make
```

## 运行

主函数一共 4 个参数, 分别是: 绘制区域的中心坐标 宽度, 高度, 导入的rle文件, 是否循环边界.
一个典型的运行是:

```shell
./lifegame 80 80 newgun.rle 0
```

这个运行的意思是构建一个80*80的game life，初始状态从newgum.rle文件中导入，边界处理为不循环世界.
运行过程中可以用键盘键入字符'q'来关闭，用键入's'来进行截屏，当前的世界信息会绘制在conway.bmp中.
