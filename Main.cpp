#include "Lab1.h"
#include "Lab2_1.h"
#include "Lab2_2.h"
#include "Lab3_1.h"
#include "Lab3_2.h"
#include "Lab3_3.h"
#include "Lab4_1.h"


#include <typeinfo>
#include <string>

using namespace std;

bool IsInTriada(Triada triada, int num) {
	if (triada.EqualX(num) || triada.EqualY(num) || triada.EqualZ(num)) {
		return true;
	}
	return false;
}

void Lab4() {
	vector<Vector3D> vectors;
	vector<string> vectors_name;

	Vector3D vector_1(1, 2, 3);
	vectors.push_back(vector_1);
	vectors_name.push_back("vector_1(1, 2, 3)");

	Vector3D vector_2(5, 3, 7);
	vectors.push_back(vector_2);
	vectors_name.push_back("vector_2(5, 3, 7)");

	Vector3D vector_3(2, 8, 5);
	vectors.push_back(vector_3);
	vectors_name.push_back("vector_3(2, 8, 5)");

	Vector3D vector_4(9, 3, 6);
	vectors.push_back(vector_4);
	vectors_name.push_back("vector_4(9, 3, 6)");

	Vector3D vector_5(3, 4, 6);
	vectors.push_back(vector_5);
	vectors_name.push_back("vector_5(3, 4, 6)");

	Vector3D vector_6(2, 5, 6);
	vectors.push_back(vector_6);
	vectors_name.push_back("vector_6(2, 5, 6)");

	Vector3D vector_7(9, 4, 2);
	vectors.push_back(vector_7);
	vectors_name.push_back("vector_7(9, 4, 2)");

	Vector3D vector_8(1, 7, 3);
	vectors.push_back(vector_8);
	vectors_name.push_back("vector_8(1, 7, 3)");

	Vector3D vector_9(7, 5, 2);
	vectors.push_back(vector_9);
	vectors_name.push_back("vector_9(7, 5, 2)");

	Vector3D vector_10(4, 2, 1);
	vectors.push_back(vector_10);
	vectors_name.push_back("vector_10(4, 2, 1)");

	int num;
	cin >> num;
	for (size_t i = 0; i < vectors.size(); i++)
	{
		if (IsInTriada(vectors[i], num)) {
			cout << typeid(vectors[i]).name() << ". Object " << vectors_name[i] << endl;
		}
	}
}

int main() {

}


