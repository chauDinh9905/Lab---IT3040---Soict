#include<iostream>
#include <vector>

using namespace std;

vector<char> input_string;
void input() {
    string line;
    cout << "Input:\n";
    getline(cin, line);

    for (char ch : line) {
        if (ch == '0') {
            input_string.push_back(ch);
        } else if (ch == '1') {
            input_string.push_back(ch);
        } else {
            break;
        }
    }
}

bool check_string_from_i_to_j(int i, int j){
    int check_1 = 0, check_0 = 0;
    for(int k = i; k <= j; ++k){
        if(input_string[k] == '1'){
            check_1++;
        } else {
            check_0++;
        }
    }
    if(check_1 == check_0) return true;
    return false;
}

int result(){
    int count = 0, n = input_string.size();
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(check_string_from_i_to_j(i, j)){
                ++count;
            }
        }
    }
    return count;
}

int main(){
    input();
    cout << "Output: " << result();
    
    return 0;
}