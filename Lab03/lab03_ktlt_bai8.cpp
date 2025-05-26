#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
    // i là quả cân thứ i đang xét
    // j cho biết đã thử gì chưa
    // j = -1 là chưa thử j ở quả cân thứ i
    // j = 0 là đã thử trừ m[i] tức cân nặng quả cân i
    // j = 1 là đã thử cộng m[i]
};

int main() {
    int n, M; // n quả cân, M là cân nặng như người ta nói
    cin >> n >> M;
    int m[n+1]; // mảng lưu trữ cân nặng của quả cân 1 đến quả cân nn
    for (int i = 1; i <= n; ++i) cin >> m[i];// nhập vào số cân của n quả câncân
    int x[n+1]; // mảng lưu trừ trạng thái quả cân thứ i
    // x[i] = -1 là trừ m[i], 1 là cộng m[i];
    stack<state> s;
    //# sum of selected weights
    int sum = 0;
    s.push(state(1, -1)); // bắt đầu từ quả cân thứ 1 và chưa thử gì cả
    while (!s.empty()){
        state &top = s.top();
        if (top.i > n){
            if (sum == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            continue;
        }
        
        //# Khử đệ quy
        /*****************
        # YOUR CODE HERE #
        *****************/
       if(top.j > -1){   // ở quả cân thứ top.i nếu đã thử thì backtrack lần thử trước
        sum = sum - m[top.i] * x[top.i];
       }
       if(top.j > 1){  // nếu đã thử cả + lẫn - thì quay lại quả cân trước đó
        s.pop();
        continue;
       }
       x[top.i] = top.j;
       sum = sum + m[top.i] * x[top.i]; // cập nhật lại tổng cân nặng
       s.push(state(top.i + 1, -1));  // thử quả cân tiếp theo
       ++top.j; // cập nhật sau khi thử quả cân thứ top.i

    }
    cout << -1;

    return 0;
}