1：编写函数int max_func(int a[],int n,int &i)，实现对数组a的n个元素求最大的元素和该数是第几个数。（要求函数内部没有cout语句）
2：主函数键盘输入10个数，调用函数，将结果输出到屏幕。
输入样例：
4 7 0 -3 4 34 67 -42 31 76
输出样例：
第10个数最大，值为76
#include <iostream>
using namespace std;
int max_func[](int a[], int n, int& i) {
    
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 1; i < n; i++)
        cin >> a[i];
    int ans[2];
    printf("最大的数为%d, 第%d个", ans[0], ans[1]);
    system("pause");
    return 0;
}