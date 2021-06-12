#pragma once
#include <vector>
using namespace std;

static class Lab3_3 {
	static vector<int> SetVectorWithRandomRange(vector<int> vect, int length, int start, int end) {
		srand((unsigned)time(0));
		for (size_t i = 0; i < length; i++)
		{
			vect[i] = rand() % end + start;
		}
		return vect;
	}
	static void ShowVector(vector<int> vect) {
		for (size_t i = 0; i < vect.size(); i++)
		{
			cout << vect[i] << " ";
		}
		cout << endl;
	}

	static vector<int> ChangeVect(vector<int> vect) {
		auto iter = vect.begin();
		while (iter != vect.end() - 1) {
			if (*iter == *(iter + 1)) {
				iter = vect.erase(iter);
			}
			else {
				++iter;
			}
		}
		return vect;
	}
public:
	static void Start() {
		int length = CommonFunctions::SetNumberRange<int>(1, 101);
		vector<int> vect(length);

		vect = SetVectorWithRandomRange(vect, length, 0, 2);

		ShowVector(vect);
		cout << "sizeof = " << sizeof(int) * vect.size() << endl;

		vect = ChangeVect(vect);

		ShowVector(vect);
		cout << "sizeof = " << sizeof(int) * vect.size() << endl;
	}
};
