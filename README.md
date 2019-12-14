# 快速使用

## 1 创建一个位图结构

```c
my_bitmap_t test_bitmap;
```
## 2 初始化为全0或全1

```c
init_bitmap(&test_bitmap, 0); // 0代表初始化为全0 1代表初始化为全1
```
## 3 使用各种方法操作

```c
set_bitmap_onebit(&test_bitmap, 12); //设置位图第12位为1
clear_bitmap_onebit(&test_bitmap, 13); //清除位图第13位
get_bitmap_first_zero(&test_bitmap); //获取位图第一个为0的索引值
get_bitmap_first_set(&test_bitmap); //获取位图第一个为1的索引值
```

















