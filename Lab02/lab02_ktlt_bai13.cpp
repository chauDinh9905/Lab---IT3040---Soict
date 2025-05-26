#include<iostream>
#include <string.h>

using namespace std;

struct bigNum{
    char sign;
    char num[101];
    bigNum(){
        sign = '1';
        memset(num,'0',101);
        
    }
};

void input(bigNum &num){
    string str;
    cin >> str;
    num.sign = str[0];
    int len_str = str.length() - 1;
    //memset(num.num, '0', 101);
    for(int i = 0; i < len_str; ++i){
        num.num[101 - len_str + i] = str[i + 1];
    }
}

void add(char *result, char *num1, char *num2){
    int carry = 0;
    for(int i = 100; i >= 0; --i){
        int tmp = (num1[i] - '0') + (num2[i] - '0') + carry;
        carry = tmp/10;
        result[i] = (tmp % 10) + '0';
    }
}

void sub(char *result, char* num1, char* num2){
    int carry = 0;
    for(int i = 100; i >= 0; --i){
        int tmp1 = num1[i] - '0';
        int tmp2 = num2[i] - '0';

        if(tmp1 >= tmp2 + carry){
            result[i] = tmp1 - tmp2 - carry + '0';
            carry = 0;
        }else{
            tmp1 = tmp1 + 10;
            result[i] = tmp1 - tmp2 - carry + '0';
            carry =1;
        }
    }
    //result[101] = '\0';
}

void multiply(char* result, char* num1, char* num2){
    for(int i = 0; i < 101; ++i){
        result[i] = '0';
    }
    //result[101] = '\0';
        for(int i = 100; i >= 0; --i){
            char tmp[101];
            int k;
            for(k = 0; k < i; ++k){
                tmp[100-k] = '0';
               }
                int carry = 0, sum = 0;
                for(int j = 100; j >= 0; --j,--k){
                    //if(k < 0) break;
                    sum = (num1[j] - '0')*(num2[i] - '0') + carry;
                    tmp[k] = (sum % 10) + '0';
                    carry = sum/10;
                    //--k;
                    if(k < 0) break;
                }

            add(result, tmp, result);
        }
    }

bool check(char* num1, char* num2){ // whether num1 > num2
    int i, j;
    for(i = 0; i < 101; ++i){
        if(num1[i] != '0') break;
    }
    for(j = 0; j < 101; ++j){
        if(num2[j] != '0') break;
    }

    if(i > j) return false;
    else if(i < j) return true;
    else{
        int k = i;
        while(k != 101){
            if(num1[k] > num2[k]) return true;
            else if(num1[k] < num2[k]) return false;
            else ++k;
        }
        //return true;
    }
    return true;
    
}

bigNum operator+(bigNum num1, bigNum num2){
    bigNum result;
    if(num1.sign == num2.sign){
        result.sign = num1.sign;
        add(result.num, num1.num, num2.num);
    }else{
      if(check(num1.num, num2.num)){
        result.sign = num1.sign;
        sub(result.num, num1.num, num2.num);
      }else{
        result.sign = num2.sign;
        sub(result.num, num2.num, num1.num);
      }
    }
    return result;
}

bigNum operator-(bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '0'){
        num2.sign = '1';
        res = num1 + num2;
        return res;
    } else if(num1.sign == '1' && num2.sign == '1'){
        num2.sign = '0';
        res = num1 + num2;
        return res;
    } else if(num1.sign == '0' && num2.sign == '1'){
        num2.sign = '0';
        res = num1 + num2;
        return res;
    } else {
        num2.sign = '1';
        res = num1 + num2;
        return res;
    }
}

bigNum operator*(bigNum num1, bigNum num2){
    bigNum result;
    if(num1.sign == num2.sign){
        result.sign = '1';
        multiply(result.num, num1.num, num2.num);
    }else{
        result.sign = '0';
        multiply(result.num, num1.num, num2.num);
    }
    return result;
}

void print_bigNum(bigNum num){
    cout << num.sign;
    int i;
    for( i = 0; i < 101; ++i){
        if(num.num[i] != '0') break;
    }
    for(int j = i; j < 101; ++j){
        cout << num.num[j];
    }
}

int main(){
    bigNum num1, num2, result;
    input(num1);
    input(num2);
    result = num1*num2 - (num1 + num1 + num1) + (num2 + num2 + num2 + num2);
    print_bigNum(result);
}
