#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
   
     a.erase(remove_if(a.begin(), a.end(), [](int x) { return x % 2 == 0; }), a.end());
}

void sort_decrease(vector<int> &a) {
   
     sort(a.begin(), a.end(), greater<int>());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> c;
    int i_a = 0, i_b = 0;
    while (i_a < a.size() && i_b < b.size()) {
        if (a[i_a] > b[i_b]) {
            c.push_back(a[i_a]);
            i_a++;
        } else {
            c.push_back(b[i_b]);
            i_b++;
        }
    }
    while (i_a < a.size()) {
        c.push_back(a[i_a]);
        i_a++;
    }
    while (i_b < b.size()) {
        c.push_back(b[i_b]);
        i_b++;
    }
    return c;
}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}