#pragma once
#include <iostream>
#include <complex>
using namespace std;

class Lab2_1
{
private:
    static float SetNumber(string str) {
        float num = 0;
        cout << str << " = ";
        cin >> num;
        return num;
    }

    static void ShowResult(complex<float> x, complex<float> y, int count, int ycount) {
        string sign = "+";
        if (x.imag() < 0) {
            sign = "";
        }

        if (abs(x.real()) == 0) {
            cout << "x" << count << " = " << x.imag() << "i" << "\t\t";
        }
        else if (abs(x.imag()) == 0) {
            cout << "x" << count << " = " << x.real() << "\t\t";
        }
        else
        {
            cout << "x" << count << " = " << x.real() << sign << x.imag() << "i" << "\t\t";
        }

        if (abs(y.real()) == 0) {
            cout << "y" << ycount << " = " << y.imag() << "i" << endl;
        }
        else if (abs(y.imag()) == 0) {
            cout << "y" << ycount << " = " << y.real() << endl;
        }
        else
        {
            cout << "y" << ycount << " = " << y.real() << sign << y.imag() << "i" << endl;
        }
    }
public:
    static void Start() {

        float a = SetNumber("a");
        float b = SetNumber("b");
        float c = SetNumber("c");

        float D = pow(b, 2) - 4.0 * a * (c - a);
        cout << "D = " << D << endl;
        if (D == 0) {
            complex<float> y1 = -1 * (-1 * b) / (2.0 * a);
            complex<float> x1 = sqrt((c - b * y1) / a);
            complex<float> x2 = -x1;

            ShowResult(x1, y1, 1, 1);
            ShowResult(x2, y1, 2, 1);
        }
        else {
            complex<float> y1 = (b - sqrt(D)) / (2 * a);
            complex<float> y2 = (b + sqrt(D)) / (2 * a);
            complex<float> x11 = sqrt((c - b * y1) / a);
            complex<float> x12 = -x11;
            complex<float> x21 = sqrt((c - b * y2) / a);
            complex<float> x22 = -x21;

            ShowResult(x11, y1, 1, 1);
            ShowResult(x12, y1, 2, 1);
            ShowResult(x21, y2, 3, 2);
            ShowResult(x22, y2, 4, 2);
        }
    }
};

