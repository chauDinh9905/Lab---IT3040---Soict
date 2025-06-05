
#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int x, y, z;
} block;

int n;
block a[100];
int maxh[100];

void input() {
    cin >> n;
    if (n == 0) exit(0);

    int x, y, z;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z;

        a[3 * i - 2] = {x, y, z};
        a[3 * i - 1] = {y, z, x};
        a[3 * i] = {z, x, y};
    }

    memset(maxh, 0, sizeof(maxh));
}

int dp(int i) { // Tìm chiều cao của tòa tháp với đỉnh là khối i
    if (maxh[i] != 0) return maxh[i];
    maxh[i] = a[i].z;

    // Tìm các khối có thể đặt bên dưới khối i
    for (int j = 1; j <= 3 * n; j++) {
        if ((a[i].x < a[j].x && a[i].y < a[j].y) ||
            (a[i].x < a[j].y && a[i].y < a[j].x)) {
            maxh[i] = max(maxh[i], a[i].z + dp(j));
        }
    }
    return maxh[i];
}

int main() {
    int cnt = 1;
    while (true) {
        int res = 0;
        input();
        for (int i = 1; i <= 3 * n; i++) {
            res = max(res, dp(i));
        }

        printf("Case %d: maximum height = %d\n", cnt++, res);
    }
    return 0;
}
