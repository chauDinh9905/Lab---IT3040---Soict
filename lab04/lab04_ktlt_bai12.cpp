#include<iostream>
#include <vector>

using namespace std;


int n;
vector<int> height;
void input(){
   cin >> n;
    height.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> height[i];
    }
}
int max_area_from_left_index(int i){
    int area = 0;
    for(int j = i - 1; j >=0; --j){
        if(height[i] > height[j]){
            break;
        }else{
            area = area + height[i];
        }
    }
    return area;
}
int max_area_from_right_index(int i){
    int area = 0;
    for(int j = i + 1; j < n; ++j){
        if(height[j] < height[i]){
            break;
        }else{
            area = area + height[i];
        }
    }
    return area;
}
int max_area_from_index(int i){
    return max_area_from_left_index(i) + max_area_from_right_index(i) + height[i];
}
int max_area(){
    int max_area = 0;
    for(int i = 0; i < n; ++i){
        int area = max_area_from_index(i);
        if(area > max_area){
            max_area = area;
        }
    }
    return max_area;
}
int main(){
    input();
    cout << max_area() << endl;
    return 0;
}