#include<iostream>
#include<list>
#include<stack>
#include <vector>
using namespace std;
void dfs(vector< list<int> > adj) {
    int n = adj.size();
    stack<int> S;

    vector<bool> visited(n, false); // Khởi tạo mảng visited với kích thước n và gán tất cả giá trị là false
    S.push(1); // Bắt đầu từ đỉnh số 1
    while(!S.empty()){
        int node = S.top();
        S.pop();
        if(visited[node] == true){
            continue; // Nếu đỉnh đã được thăm thì bỏ qua
        }
        else{
            visited[node] = true; // Đánh dấu đỉnh đã được thăm
            S.push(node); // Thêm đỉnh vào kết quả
            for(auto it = adj[node].rbegin(); it != adj[node].rend(); ++it){
                if(visited[*it] == false){
                    S.push(*it); // Thêm các đỉnh kề vào stack
                }
            }
        }
    }
}