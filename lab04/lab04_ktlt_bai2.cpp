 #include <iostream>
 #include <cmath>
 #include <iomanip>
 #include <utility>
 using namespace std;
 using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    double canh1 = sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
    double canh2 = sqrt(pow(c.first - b.first, 2) + pow(c.second - b.second, 2));
    double canh3 = sqrt(pow(a.first - c.first, 2) + pow(a.second - c.second, 2));
    double p = (canh1 + canh2 + canh3) / 2;
    double s = sqrt(p * (p - canh1) * (p - canh2) * (p - canh3));
    return s;
}

 int main() {
     cout << setprecision(2) << fixed;
     cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
     return 0;
 }