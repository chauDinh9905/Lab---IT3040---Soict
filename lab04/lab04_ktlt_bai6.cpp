#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;
void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    
   while(!Q.empty()){
    int node = Q.front();
    Q.pop();
    if(visited[node] == true){
        continue; // Nếu đỉnh đã được thăm thì bỏ qua
    }
    else{
        visited[node] = true; // Đánh dấu đỉnh đã được thăm
        cout << node << " "; // In ra đỉnh đã thăm
        for(auto it = adj[node].begin(); it != adj[node].end(); ++it){
            if(visited[*it] == false){
                Q.push(*it); // Thêm các đỉnh kề vào queue
            }
        }
    }
   }
}