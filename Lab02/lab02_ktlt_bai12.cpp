#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cau_truc {
    int key, value;
};

int main() {
    vector<cau_truc> a;
    int tmp1, tmp2;

    cout << "Input:\n";

    while (cin >> tmp1 >> tmp2) {
        a.push_back({tmp1, tmp2});
    }

    

    sort(a.begin(), a.end(), [](const cau_truc &a, const cau_truc &b) {
        return (a.value == b.value) ? (a.key > b.key) : (a.value > b.value);
    });

    cout << "Output:\n";
    for (const auto &i : a) {
        cout << i.key << " " << i.value << "\n";
    }

    return 0;
}
