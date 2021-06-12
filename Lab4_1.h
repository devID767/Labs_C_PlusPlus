#include <cmath>
using namespace std;

class Triada {
protected:
	int x;
	int y;
	int z;
public:
	Triada(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	int GetX() {
		return x;
	}

	int GetY() {
		return y;
	}

	int GetZ() {
		return z;
	}

	void AddToX(int num) {
		x += num;
	}

	void AddToY(int num) {
		y += num;
	}

	void AddToZ(int num) {
		z += num;
	}
	
	void MultiplyX(int num) {
		x *= num;
	}

	void MultiplyY(int num) {
		y *= num;
	}

	void MultiplyZ(int num) {
		z *= num;
	}

	bool EqualX(int num) {
		return x == num;
	}

	bool EqualY(int num) {
		return y == num;
	}

	bool EqualZ(int num) {
		return z == num;
	}
};

class Vector3D : public Triada {
public:
	Vector3D(int x, int y, int z) : Triada(x, y, z)
	{

	}

	void AddVector(Vector3D vector3d) {
		AddToX(vector3d.x);
		AddToY(vector3d.y);
		AddToZ(vector3d.z);
	}

	void MultiplyOnVector(Vector3D vector3d) {
		MultiplyX(vector3d.x);
		MultiplyY(vector3d.y);
		MultiplyZ(vector3d.z);
	}

	void Rotate(char axis, float angle) {
		switch (axis)
		{
		case 'x':
			AddToY(GetY() * cos(angle) - GetZ() * sin(angle));
			AddToZ(GetY() * sin(angle) + GetZ() * cos(angle));
			break;
		case 'y':
			AddToX(GetX() * cos(angle) + GetZ() * sin(angle));
			AddToZ(-GetX() * sin(angle) + GetZ() * cos(angle));
			break;
		case 'z':
			AddToX(GetX() * cos(angle) - GetY() * sin(angle));
			AddToY(GetX() * sin(angle) + GetY() * cos(angle));
			break;
		default:
			break;
		}
	}

	void ChangeLength(int value){
		if (value > 0) {
			MultiplyX(value);
			MultiplyY(value);
			MultiplyZ(value);
		}
		else {
			cout << "value can't be < 0" << endl;
		}
	}
};
