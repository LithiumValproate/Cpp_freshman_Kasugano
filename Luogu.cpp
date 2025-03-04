#include <iostream>
using namespace std;

char map[10][10];
bool obs[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 10 && !obs[x][y];
}
int move(int fx, int fy, int cx, int cy) {
    int step = 0;
    int fd = 0, cd = 0;
    int fx0 = fx, fy0 = fy, cx0 = cx, cy0 = cy;
    while (true) {
        int nfx = fx + dx[fd], nfy = fy + dy[fd];
        int ncx = cx + dx[cd], ncy = cy + dy[cd];
        if (valid(nfx, nfy)) {
            fx = nfx;
            fy = nfy;
        } else {
            fd = (fd + 1) % 4;
        }
        if (valid(ncx, ncy)) {
            cx = ncx;
            cy = ncy;
        } else {
            cd = (cd + 1) % 4;
        }
        step++;
        if (fx == cx && fy == cy)
            return step;
        if (fx == fx0 && fy == fy0 && cx == cx0 && cy == cy0 && fd == cd)
            return 0;
    }
}

int main() {
    int fx, fy, cx, cy;
    char ch;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> ch;
            map[i][j] = ch;
            if (ch == 'F') {
                fx = i;
                fy = j;
            } else if (ch == 'C') {
                cx = i;
                cy = j;
            } else if (ch == '*') {
                obs[i][j] = true;
            }
        }
    }
    cout << move(fx, fy, cx, cy) << endl;
    return 0;
}