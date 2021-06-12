#pragma once
#include <string>
using namespace std;

static class CommonFunctions {
public:
	template <typename T>
	static void SetMassiveWithRandomRange(T** massive, int row, int coloumn, int start, int end) {
		srand((unsigned)time(0));
		for (size_t i = 0; i < coloumn; i++)
		{
			for (size_t j = 0; j < row; j++)
			{
				massive[j][i] = rand() % end + start;
			}
		}
	}

	template <typename T>
	static void SetArrWithRandomRange(T* arr, int length, int start, int end) {
		srand((unsigned)time(0));
		for (size_t i = 0; i < length; i++)
		{
			arr[i] = rand() % end + start;
		}
	}

	template <typename T>
	static void ShowArr(T* arr, int length) {
		for (size_t i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	template <typename T>
	static T SetNumberWithParse(string title = "", int maxcount = 1) {
		T number = 0;
		int count = 0;
		cout << title;
		while (true) {
			while (true) {
				cin >> number;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(3216, '\n');
					cout << "Error \nInvaid value\n";
					cout << title;
				}
				else {
					break;
				}
			}
			count++;

			if (cin.peek() == '\n') {
				break;
			}
		}
		if (count == maxcount) {
			cin.clear();
			cin.ignore(3215, '\n');
			return number;
		}
		else {
			cout << "Error \nYou entered more than " << maxcount << " numbers\n";
			cin.clear();
			cin.ignore(3215, '\n');
			return SetNumberWithParse<T>(title, maxcount);
		}
	}

	template <typename T>
	static T SetNumberRange(int minValue, int maxValue) {
		T number = 0;
		while (true) {
			number = SetNumberWithParse<T>();

			if (number >= minValue && number <= maxValue) {
				break;
			}
			else if (number < minValue) {
				cout << "number can't be < " << minValue << endl;
			}
			else if (number > maxValue) {
				cout << "number can't be > " << maxValue << endl;
			}
		}
		return number;
	}

	template<typename T>
	static void ShowMassive(T** massive, const int* Row, const int* Coloumn) {
		for (size_t i = 0; i < *Row; i++)
		{
			for (size_t j = 0; j < *Coloumn; j++)
			{
				cout << massive[i][j] << " ";
			}
			cout << endl;
		}
	}

	template<typename T>
	static void SortMassiveByLength(T** massive, int Row, int Coloumn) {
		string savedValue = "";

		int max = Row - 1;
		int highest = max;

		int ColoumnSort = 0;

		for (size_t i = 0; i < Row - 1; i++)
		{
			if (massive[i][ColoumnSort].length() != massive[i + 1][ColoumnSort].length()) {
				break;
			}
			else {
				ColoumnSort++;
				i--;
			}
		}
		for (int i = Row - 1; i >= 0; i--)
		{
			highest = max;
			for (int h = i; h >= 0; h--)
			{
				if (massive[highest][ColoumnSort].length() < massive[h][ColoumnSort].length()) {
					highest = h;
				}
			}

			for (int j = 0; j < Coloumn; j++)
			{
				savedValue = massive[i][j];
				massive[i][j] = massive[highest][j];
				massive[highest][j] = savedValue;
			}
			max--;
		}
	}
};
