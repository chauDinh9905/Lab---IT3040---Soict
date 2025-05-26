 #include <iostream>
 #include <cmath>
 #include <iomanip>
 using namespace std;
 using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b) {
        double x1 = get<0>(a);
        double y1 = get<1>(a);
        double z1 = get<2>(a);
        double x2 = get<0>(b);
        double y2 = get<1>(b);
        double z2 = get<2>(b);
    
        return {y1 * z2 - z1 * y2, z1 * x2 - x1 * z2, x1 * y2 - y1 * x2};
}

 int main() {
     cout << setprecision(2) << fixed;
     Vector a {1.2, 4, -0.5};
     Vector b {1.5, -2, 2.5};
        Vector c = cross_product(a, b);
        cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
     return 0;
 }