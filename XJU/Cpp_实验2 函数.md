# 实验二 函数

__班级：软件24-18  姓名：杨鎏__

## 一、实验目的

* 学习内联函数，重载函数的使用
* 学习使用系统函数
* 复习递归调用的思想

## 二、实验内容

1. （1）编写函数Max求3个整数的最大值，要求使用引用传递进行参数传递。__（20分）__
    （2）编写函数Max分别求2个整数、2个双精度数、3个双精度数的最大值，要求体现函数重载的思想。__（30分）__

2. 编写程序计算下面多项式函数的值并输出结果：
   $$
   f(x) = a*(x^n)+e^2
   $$
   其中a，x，n为用户输入的三个整数。要求使用<cmath>头文件中的库函数，并且程序能体现内联函数的思想。__（30分）__

3. 使用递归方式和非递归方式分别求斐波那契数列的前三十项并依次打印，对比这两种方式的实现效率。__（20分）__

## 三、实验步骤及结果
（在此部分列出 __解题思路、程序代码和运行结果截图等三项内容__。请注意保持格式规范统一，截图清晰，大小合适）
#### 代码撰写基本规范：

* 保持代码结构清晰，注意缩进和对齐；
* 标识符命名遵循“见其名，知其意思”原则，建议用英文词汇或其简写。
* 括号等成对输入，不易遗漏；
* 提高代码可读性。合理使用段注释和行注释

#### 参考示例：
0. 编写程序，在屏幕上输出“Hello World"
```cpp
/*
  功能：在屏幕上输出“Hello World"
  作者：张三
  版本：1.0
*/
#include <iostream>
using namespace std;
int main(){
    cout << "Hello World" << endl;
    return 0;
}
```
运行结果截图：
<img src="https://gitee.com/yannyyy/object-oriented-programming/raw/master/imgs/helloworld.png" alt="Hello World示例" style="zoom:150%;" />

1. （1）编写函数Max求3个整数的最大值，要求使用引用传递进行参数传递。
    （2）编写函数Max分别求2个整数、2个双精度数、3个双精度数的最大值，要求体现函数重载的思想。

  ```cpp
  #include <iostream>
using namespace std;
int max_func(int& a, int& b, int& c) {
    int ans = a;
    if (ans < b) {
        ans = b;
        if (ans < c)
            ans = c;
    }
    return ans;
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max_func(a, b, c) << endl;
    system("pause");
    return 0;
}
  ```

运行结果截图：
<img src=http://167.179.97.78/wp-content/uploads/2025/03/屏幕截图-2025-03-11-231925.png>

2. 编写程序计算下面多项式函数的值并输出结果：
   $$
   f(x) = a*(x^n)+e^2
   $$
   其中a，x，n为用户输入的三个整数。要求使用<cmath>头文件中的库函数，并且程序能体现内联函数的思想。

  ```cpp
  #include <cmath>
#include <iostream>
using namespace std;
int a, x, n;
long long func(int a, int x, int n) {
    return a * pow(x, n) + exp(2);
}
int main() {
    cin >> a >> x >> n;
    cout << func(a, x, n) << endl;
    system("pause");
    return 0;
}
  ```
运行结果截图：
<img src=http://167.179.97.78/wp-content/uploads/2025/03/屏幕截图-2025-03-11-232158.png>

3. 使用递归方式和非递归方式分别求斐波那契数列的前三十项并依次打印，对比这两种方式的实现效率。

```cpp
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
long long rec(int i) {
    if (i == 0)
        return 0;
    else if (i == 1)
        return 1;
    else
        return rec(i - 1) + rec(i - 2);
}
long long no_rec(int i) {
    if (i == 0)
        return 0;
    else if (i == 1)
        return 1;
    long long a = 0, b = 1;
    for (int j = 2; j <= i; j++) {
        long long tmp = a + b;
        a = b;
        b = tmp;
    }
    return b;
}
int main() {
    auto startTimeRec = high_resolution_clock::now();
    cout << "Use recursion:\n";
    for (int i = 0; i <= 30; i++) {
        printf("%d: %lld\t", i, rec(i));
        if (i % 5 == 0)
            cout << endl;
    }
    auto endTimeRec = high_resolution_clock::now();
    auto durationRec = duration_cast<microseconds>(endTimeRec - startTimeRec);
    cout << "\nRecursion time used: " << durationRec.count() << " microseconds\n";
    auto startTimeNoRec = high_resolution_clock::now();
    cout << "\nNon-recursion:\n";
    for (int i = 0; i <= 30; i++) {
        printf("%d: %lld\t", i, no_rec(i));
        if (i % 5 == 0)
            cout << endl;
    }
    auto endTimeNoRec = high_resolution_clock::now();
    auto durationNoRec = duration_cast<microseconds>(endTimeNoRec - startTimeNoRec);
    cout << "\nNon-recursion time used: " << durationNoRec.count()
         << " microseconds" << endl;
    system("pause");
    return 0;
}
```
运行结果截图：
<img src=http://167.179.97.78/wp-content/uploads/2025/03/屏幕截图-2025-03-11-233813.png>

## 四、实验小结

（包括问题和解决办法、心得体会。 __必须要有具体错误截图和针对性讨论，不能仅有文字文字说明。__）__（20分）__

#### 实验小结参考示例：

__问题与解决办法：__ 不清楚如何使用代码实现查看运行时间

__解决办法：__ 借助ChatGPT、Grok解决

<img src=http://167.179.97.78/wp-content/uploads/2025/03/屏幕截图-2025-03-11-234455.png>

__心得体会__：不懂的就问