# Matrix Multiplication Optimization

## Contents

- [cblas_dgemm.c](cblas_degemm.c): 多线程矩阵乘法优化实现
- [main.c](main.c): 主函数，调用自己写的cblas_dgemm.c中的cblas_dgemm函数与cblas库中的cblas_dgemm函数，计算运行时间
- [strassen.c](strassen.c): Strassen算法的简单实现
- [rand_mat.c](rand_mat.c): 提供测试的随机矩阵，调用rng目录的随机数生成器
- [test.sh](test.sh): 测试矩阵乘法时间比较的脚本，提供三个参数，第一个参数表示矩阵（方阵边长），第二个参数表示测试轮次，第三个参数表示是否为检查模式（1则表示在output文件中输出计算结果）
- [analysis.c](analysis.c): 数据处理，计算平均值

## Usage 0 测试计算正确性

项目调用cblas库中的函数进行测试，需要安装CBLAS（C Basic Linear Algebra Subprograms）提供线性代数运算的库.

```sh
make all
./test 64 10 1
```

## Usage 1 时间比较

```sh
make all
./test.sh 1024 10 0
```

## Expected Output

输出结果写入三个Output文件中，分别为output_bentch_mark,output_main,output_str，对应clbas库函数实现，多线程优化实现，strassen算法实现的结果，可以进行比较

analysis.c对数据处理后写入output_analysis中，可以看到三个代码的时间平均值的比较，一些典型的结果:

参数为

```sh
./test.sh 64 10 0
```

output_analysis:

Bentch_mark:
Average time is 0.009388

Main:
Average time is 0.000328

Strassen:
Average time is 0.000893

参数为

```sh
./test.sh 4096 10 0
```

output_analysis:
Bentch_mark:
Average time is 4.853823

Main:
Average time is 66.959989

Strassen:
Average time is 104.902371
