#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, s;
int sum = 0, died = 0;
priority_queue<int, vector<int>> PQ;
vector<pair<int, int>> wall; // first is a, second is k
bool compare(pair<int, int> x, pair<int, int> y){
    return x.second > y.second;
}

void process(){
    for(int i = 0; i < n; ++i){
        while(!PQ.empty() && (PQ.top() > wall[i].second) && s > 0){
            died += PQ.top();
            PQ.pop();
            s--;
        }
        int soldier_in_ith_wall = wall[i].first/wall[i].second;
        int enemies_go_through_ith_wall = wall[i].first%wall[i].second;
        if(enemies_go_through_ith_wall != 0) PQ.push(enemies_go_through_ith_wall);
        if(soldier_in_ith_wall <= s){
            s -= soldier_in_ith_wall;
            died += soldier_in_ith_wall * wall[i].second;
        } else {// if there are not enough soldiers to protect the ith wall
            died += s * wall[i].second;
            s = 0;
            break;
        }

    }
    while(s > 0 && !PQ.empty()){
        died += PQ.top();
        s--;
        PQ.pop();
    }

}

void input(){
    cin >> n >> s;
   int a,b;
    wall.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        wall.push_back({a, b});
        sum += a;
    }
    sort(wall.begin(), wall.end(), compare);
}

int main(){
  input();
    process();
    cout << sum - died;
    return 0;
}