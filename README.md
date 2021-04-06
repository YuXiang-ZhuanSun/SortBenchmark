# 项目介绍

本项目用于测试整数排序算法的速度。



运行本项目，会自行生成多组随机数测试数据。

本项目同时提供了c++标准排序函数，`std::sort()`，快速排序，归并排序运行时间，供比较分析。

本项目使用[小熊猫dev-c](https://royqh.net/devcpp/download)开发，建议使用dev-c软件运行。


# 使用方法

添加新的排序测试，接口形式需要满足：

```c++
your_sort(int *a,int num);
```

**函数名可自定义**，其中`a`为待排序数组首地址，`num`为待排序数组长度。

## 具体操作

* 使用[小熊猫dev-c](https://royqh.net/devcpp/download)打开项目`SortBenchmark.dev`。
* 将排序函数添加至`sources/your_sort.cpp`。同时，在`sources/Sort.h`中添加函数说明。
* 在`SortBenchmark.cpp`主程序中添加如下语句，

```c++
    benchmark_sort(your_sort,"YourSort()");
```

其中`your_sort`是你的排序函数名，`"YourSort()"`只是一句测试结果输出提示语。

* 使用[小熊猫dev-c](https://royqh.net/devcpp/download)运行整个项目，即可自动开始排序算法测试。



使用愉快，后续会更新排序结果验证功能。

参考：
* [Benchmark](https://github.com/Ming-boop/ICPC/blob/master/Benchmark)
