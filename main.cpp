#include <iostream>
#include <cmath>

using namespace std;

class LinearEquation {
private:
    double hsa, hsb;

public:
    LinearEquation() : hsa(0.0), hsb(0.0) {}
    LinearEquation(double a, double b) : hsa(a), hsb(b) {}

    double getA() const { return hsa; }
    void setA(double a) { hsa = a; }

    double getB() const { return hsb; }
    void setB(double b) { hsb = b; }

    void solve() const {
        cout << "\n[1] " << hsa << "x + " << hsb << " = 0" << endl;
        if (hsa == 0) {
            if (hsb == 0) cout << "-> Vo so nghiem." << endl;
            else cout << "-> Vo nghiem." << endl;
        } else {
            cout << "-> Nghiem x = " << -hsb / hsa << endl;
        }
    }
};

class QuadraticEquation {
private:
    double hsa, hsb, hsc;

public:
    QuadraticEquation() : hsa(0.0), hsb(0.0), hsc(0.0) {}
    QuadraticEquation(double a, double b, double c) : hsa(a), hsb(b), hsc(c) {}

    double getA() const { return hsa; }
    void setA(double a) { hsa = a; }

    double getB() const { return hsb; }
    void setB(double b) { hsb = b; }

    double getC() const { return hsc; }
    void setC(double c) { hsc = c; }

    void solve() const {
        cout << "\n[2] " << hsa << "x^2 + " << hsb << "x + " << hsc << " = 0" << endl;
        if (hsa == 0) {
            LinearEquation sub(hsb, hsc);
            sub.solve();
            return;
        }

        double delta = hsb * hsb - 4 * hsa * hsc;
        if (delta < 0) {
            cout << "-> Vo nghiem thuc." << endl;
        } else if (delta == 0) {
            cout << "-> Nghiem kep: x = " << -hsb / (2 * hsa) << endl;
        } else {
            double sq = sqrt(delta);
            cout << "-> 2 nghiem phan biet:\n";
            cout << "   x1 = " << (-hsb + sq) / (2 * hsa) << "\n";
            cout << "   x2 = " << (-hsb - sq) / (2 * hsa) << endl;
        }
    }
};

class CubicEquation {
private:
    double hsa, hsb, hsc, hsd;

public:
    CubicEquation() : hsa(0.0), hsb(0.0), hsc(0.0), hsd(0.0) {}
    CubicEquation(double a, double b, double c, double d) : hsa(a), hsb(b), hsc(c), hsd(d) {}

    double getA() const { return hsa; }
    void setA(double a) { hsa = a; }

    double getB() const { return hsb; }
    void setB(double b) { hsb = b; }

    double getC() const { return hsc; }
    void setC(double c) { hsc = c; }

    double getD() const { return hsd; }
    void setD(double d) { hsd = d; }

    void solve() const {
        cout << "\n[3] " << hsa << "x^3 + " << hsb << "x^2 + " << hsc << "x + " << hsd << " = 0" << endl;
        if (hsa == 0) {
            QuadraticEquation sub(hsb, hsc, hsd);
            sub.solve();
            return;
        }

        double p = hsb / hsa, q = hsc / hsa, r = hsd / hsa;
        double Q = (3 * q - p * p) / 9;
        double R = (9 * p * q - 27 * r - 2 * p * p * p) / 54;
        double D = Q * Q * Q + R * R;

        if (D > 0) {
            double u = cbrt(R + sqrt(D));
            double v = cbrt(R - sqrt(D));
            cout << "-> 1 nghiem thuc duy nhat: x = " << (u + v) - p / 3 << endl;
        } else if (D == 0) {
            double u = cbrt(R);
            cout << "-> Nghiem boi:\n";
            cout << "   x1 = " << 2 * u - p / 3 << "\n";
            cout << "   x2 = x3 = " << -u - p / 3 << endl;
        } else {
            double phi = acos(R / sqrt(-Q * Q * Q));
            double sqQ = 2 * sqrt(-Q);
            cout << "-> 3 nghiem phan biet:\n";
            cout << "   x1 = " << sqQ * cos(phi / 3) - p / 3 << "\n";
            cout << "   x2 = " << sqQ * cos((phi + 2 * M_PI) / 3) - p / 3 << "\n";
            cout << "   x3 = " << sqQ * cos((phi + 4 * M_PI) / 3) - p / 3 << endl;
        }
    }
};

int main() {
    LinearEquation eq1(2, -4);
    eq1.solve();

    QuadraticEquation eq2(1, -3, 2);
    eq2.solve();

    CubicEquation eq3(1, -6, 11, -6);
    eq3.solve();

    return 0;
}