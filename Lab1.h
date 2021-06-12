#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Lab1
{
public:
	static float MyFunction(float x) {
		return log(1 - x);
	}

	static void Task2() {
		float a = -1, b = 1, h = 0;
		cout << "Enter h\n";
		cin >> h;
		int n = (b - a) / h;
		float integral = 0, x = 0;
		for (size_t i = 0; i < n; i++)
		{
			x = a + i * h;
			if (x == b) {
				break;
			}
			if (i == n - 1) {
				float OldH = h;
				h += b - x - h;
				if (OldH < h) {
					n++;
					h = OldH;
				}
			}
			integral += h * MyFunction(x);
			cout << "integral = " << integral << "\tx = " << x << "\t\th = " << h << endl;
		}
	}

	static float Integral(float a, float b, float h) {
		int n = (b - a) / h;
		float integral = 0, x = 0;
		for (size_t i = 0; i < n; i++)
		{
			x = a + i * h;
			if (x == b) {
				break;
			}
			if (i == n - 1) {
				float OldH = h;
				h += b - x - h;
				if (OldH < h) {
					n++;
					h = OldH;
				}
			}
			integral += h * MyFunction(x);
			//cout << "integral = " << integral << "\tx = " << x << "\t\th = " << h << endl;
		}
		return integral;
	}

	static void Task3() {
		float a = -1, b = 1, h = 0;
		float accuracy = 0;
		cout << "Enter h:\n";
		cin >> h;
		cout << "Enter accuracy:\n";
		cin >> accuracy;
		float integral_2, missing;
		float integral = Integral(a, b, h);
		while (true) {
			integral_2 = integral;
			h /= 2;
			integral = Integral(a, b, h);

			missing = abs(integral - integral_2);
			if (missing < accuracy) {
				break;
			}
		}
		cout << "integral = " << integral_2 << "\tmissing = " << missing << "\t\th = " << h << endl;
	}
};

