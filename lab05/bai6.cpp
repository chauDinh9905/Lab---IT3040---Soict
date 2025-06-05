
#include <bits/stdc++.h>
using namespace std;

// Hàm tính loại điểm
char cal(double a) {
    if (a < 4) return 'F';
    if (a < 5.5) return 'D';
    if (a < 7) return 'C';
    if (a < 8.5) return 'B';
    return 'A';
}

int main() {
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;

    while (n--) {
        double a;
        cin >> a;

        // Gọi hàm cal một lần duy nhất
        char grade = cal(a);

        // Tăng bộ đếm tương ứng
        if (grade == 'A') ++A;
        else if (grade == 'B') ++B;
        else if (grade == 'C') ++C;
        else if (grade == 'D') ++D;
        else if (grade == 'F') ++F;
    }

    cout << A << " " << B << " " << C << " " << D << " " << F;
}
