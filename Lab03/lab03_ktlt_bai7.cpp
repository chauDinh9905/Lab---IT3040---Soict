#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;// i là vị trí đang xử lý trong dãy nhị phân
    //# constructor  // j là giá trị đang xét tại vị trí i
    state(int _i = 0, int _j = 0, int _L = 0):  // old_L là số lượng bit 1 liên tiếp ở hậu tố trước khi xét jj
        i(_i), j(_j), old_L(_L){}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1]; // x[i] là giá trị tại vị trí i trong dãy nhị phân
    stack<state> s; //# stack lưu trữ trạng thái của thuật toán
    // mỗi state biểu diễn một bước xét dãy nhị phân
    //# number of consecutive suffix 1
    int L = 0; // Số lượng bit 1 liên tiếp ở cuối dãy
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n]; // (i == n) ? '\n' : ' ' 
            s.pop();
            continue;
        }
        
        //# Khử đệ quy
        /*****************
        # YOUR CODE HERE #
        *****************/
        if(top.j > 0){
            L = top.old_L;
        }
        if(top.j > 1){
            s.pop();
            continue;
        }
        if(L + 1 < k || top.j == 0){
            x[top.i] = top.j;
            top.old_L = L;
            L = top.j ? L+1 : 0;
            s.push(state(top.i + 1, 0));
        }
        top.j ++;
    }
    return 0;
}