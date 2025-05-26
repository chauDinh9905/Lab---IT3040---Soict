#include<iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<string>> input_document;
vector<vector<string>> input_query;
vector<int> result;
int N, Q;
void input(vector<vector<string>> &input, int N){
    cin.ignore(); // Ignore the newline character after reading N
    for(int i = 0; i < N; ++i){
        vector<string> sub_vec;
        string line;
        getline(cin, line);
        stringstream ss(line);
        string item;
        while(getline(ss, item, ',')){
            sub_vec.push_back(item);
        }
        input.push_back(sub_vec);
     }
}
// f(t,d)
int count_item_in_line(vector<string> &line, string &item){
    int count = 0;
    for(int i = 0; i < line.size(); ++i){
        if(line[i] == item){
            count++;
        }
    }
    return count;
}
// max(f(t,d))
int score_sub_string(vector<string> &line, vector<string> &sub_query){
    int max = 0, count;
    for(int i = 0; i < sub_query.size(); ++i){
        count = count_item_in_line(line, sub_query[i]);
        if(count > max){
            max = count;
        }
    }
    return max;
}
//d(f(t))
int count_documents_have_item(vector<vector<string>> &input_document, string &item){
    int count = 0;
    for(int i = 0; i < input_document.size(); ++i){
        auto it = find(input_document[i].begin(), input_document[i].end(), item);
            if(it != input_document[i].end()){
                ++count;
            }
    }
    return count;
}

//điểm của một query trong dòng văn bản d
double score(vector<string> &query, vector<string>&line){
    double all_score = 0;
    for(int i = 0; i < query.size(); ++i){
        if(count_item_in_line(line, query[i]) == 0){
            continue;
        }
        double TF = 0.5 + 0.5*count_item_in_line(line, query[i])/score_sub_string(line, query);
        double IDF = log2((1.0)*N/count_documents_have_item(input_document, query[i]));
        all_score += TF*IDF;
    }
    return all_score;
}

void search(vector<vector<string>> &input_document, vector<vector<string>> &input_query){
       vector<int> result(input_query.size(), 0);
       for(int i = 0; i < input_query.size(); ++i){
        double max_score = 0;
        for(int j = 0; j < input_document.size(); ++j){
            double score_value = score(input_query[i], input_document[j]);
            if(score_value > max_score){
                result[i] = j + 1;
                max_score = score_value;
            }
        }
       }
       for(int i = 0; i < result.size(); ++i){
              cout << result[i] << '\n';
       }
}

int main(){
   
   cin >> N;
   input(input_document, N);
    cin >> Q;
    input(input_query, Q);
   search(input_document, input_query);

}