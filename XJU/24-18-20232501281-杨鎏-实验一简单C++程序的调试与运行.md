# 实验一 简单C++程序的调试与运行

__班级：软件24-18  姓名：杨鎏__

## 一、实验目的

* 复习基本数据类型变量和常量的应用，复习运算符与表达式的应用
* 复习结构化程序设计基本控制结构的运用
* 复习自定义数据类型的应用
* 观察头文件的作用，复习使用DEV C++开发环境中的Debug调试功能：单步执行、设置断点、观察变量值

## 二、实验内容

1. 编写一个程序，要求用户输入一个正整数N (1<N<100)，程序需要完成以下功能：

   （1）分别使用for, while, do-while三种方式求自然数1~N之和。__（30分）__

   （2）找出1~N中所有素数并依次输出。__（30分）__

2. 编程计算长方形或圆形的周长和面积。运行时先提示用户选择图形的类型，进一步地：

   （1）用户选择长方形后，提示用户输入长和宽，根据长宽计算长方形的周长和面积并依次输出，结果保留2位小数。__（20分）__

   （2）用户选择圆形后，提示用户输入半径，根据半径计算圆形的周长和面积（指定π的取值为3.14159）并依次输出，结果保留2位小数。__（20分）__

## 三、实验步骤及结果

（在此部分列出 __解题思路、程序代码和运行结果截图等三项内容__。请注意保持格式规范统一，截图清晰，大小合适）

#### 代码撰写基本规范：

- 保持代码结构清晰，注意缩进和对齐；
- 标识符命名遵循“见其名，知其意思”原则，建议用英文词汇或其简写。
- 括号等成对输入，不易遗漏；
- 提高代码可读性。合理使用段注释和行注释

#### 参考示例：

0. 编写程序，在屏幕上输出“Hello World"

```c++
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

1. 编写一个程序，要求用户输入一个正整数N (1<N<100)，程序需要完成以下功能：

   （1）分别使用for, while, do-while三种方式求自然数1~N之和。

   （2）找出1~N中所有素数并依次输出。

__程序实现：__

```cpp
#include <cmath>
#include <iostream>
using namespace std;
int f(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += i;
    return ans;
}
int w(int n) {
    int i = 1, ans = 0;
    while (i <= n) {
        ans += i;
        i++;
    }
    return ans;
}
int d(int n) {
    int i = 1, ans = 0;
    do {
        ans += i;
        i++;
    } while (i <= n);
    return ans;
}
void fp(int n) {
    for (int i = 1; i <= n; i++) {
        if (i <= 2)
            cout << i << ' ';
        else
            for (int j = 2; j <= ceil(sqrt(i)); j++) {
                if (i % j == 0)
                    break;
                if (j == ceil(sqrt(i)))
                    cout << i << ' ';
            }
    }
    cout << endl;
}
int main() {
    cout << "Input the N you want to sum in a loop:\n";
    int n, c, sum = 0;
    cin >> n;
    cout << "Enter 1 to sum via \033[3mfor\033[0m\n"
         << "Enter 2 to sum via \033[3mwhile\033[0m\n"
         << "Enter 3 to sum via \033[3mdo-while\033[0m\n";
    cin >> c;
    switch (c) {
    case 1:
        sum = f(n);
    case 2:
        sum = w(n);
    case 3:
        sum = d(n);
    default:
        cout << "The sum is: " << sum << endl;
        break;
    }
    cout << "Here are primes within N:\n";
    fp(n);
    system("pause");
    return 0;
}
```

运行结果截图：
   <img src="http://167.179.97.78/wp-content/uploads/2025/03/屏幕截图-2025-03-08-140406.png" alt="实验1">

2. 编程计算长方形或圆形的周长和面积。运行时先提示用户选择图形的类型，进一步地：

   （1）用户选择长方形后，提示用户输入长和宽，根据长宽计算长方形的周长和面积并依次输出，结果保留2位小数。

   （2）用户选择圆形后，提示用户输入半径，根据半径计算圆形的周长和面积（指定π的取值为3.14159）并依次输出，结果保留2位小数。

 __程序实现：__

```cpp
#include <iomanip>
#include <iostream>
using namespace std;
const double PI = 3.14159;
int main() {
    cout << "Please enter the number corresponding to the shape you chose:\n"
         << "1. Rectangle\n2. Circle" << endl;
    int c;
    cin >> c;
    cout << fixed << setprecision(2);
    switch (c) {
    case 1:
        cout << "Enter the length and width of the rectangle:\n";
        double a, b;
        cin >> a >> b;
        cout << "The circumference is " << (a + b) * 2 << endl
             << "The area is " << a * b << endl;
        break;
    case 2:
        cout << "Enter the radius of the circle\n";
        double r;
        cin >> r;
        cout << "The circumference is " << r * 2 * PI << endl
             << "The area is " << r * r * PI << endl;
        break;
    default:
        break;
    }
    system("pause");
    return 0;
}
```

运行结果截图：
 <img src="http://167.179.97.78/wp-content/uploads/2025/03/屏幕截图-2025-03-08-142933.png" alt="实验2">

## 四、实验小结

（包括问题和解决办法、心得体会。__必须要有具体错误截图和针对性讨论，不能仅有文字文字说明。__）__（20分）__

__问题__

对于控制输出小数位数，只会使用`printf()`函数控制，不会使用`cout`设置流。

__解决办法：__ 

上网（ChatGPT，菜鸟教程）查找后，学习了`fixed`和`setprecision()`的使用。

__心得体会：__

多上网搜索，学习同一种问题的不同解决方式。
