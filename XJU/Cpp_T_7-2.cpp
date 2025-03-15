#include <cmath>
#include <iostream>
using namespace std;
class Point {
  public:
    double p1[2];
    double p2[2];
    double s(double p1[], double p2[]) {
        return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
    }
    void print_formatted(double ans) {
        if (ans == (int)ans) {
            printf("%d", (int)ans);
        } else {
            printf("%.5f", ans);
        }
    }
};
int main() {
    Point p;
    cin >> p.p1[0] >> p.p1[1] >> p.p2[0] >> p.p2[1];
    printf("(%.0f,%.0f)\n", p.p1[0], p.p1[1]);
    printf("(%.0f,%.0f)\n", p.p2[0], p.p2[1]);
    double distance = p.s(p.p1, p.p2);
    printf("两个点的距离为：");
    p.print_formatted(distance);
    return 0;
}
