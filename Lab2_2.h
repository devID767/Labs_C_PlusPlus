using namespace std;

template <typename T>
class Matrix {
private:
	T** Arr;
	int Row;
	int Coloumn;

	float* RowControl() {
		float* numbers = new float[Coloumn];
		int i = 0;

		string str;
		float number;
		int count = 0;
		while (true) {
			while (true) {
				cin >> number;
				str = to_string(number);

				if (cin.fail()) {
					cin.clear();
					cin.ignore(3216, '\n');
					cout << "Invalid value(-s)\n";
					if (str.find(',')) {
						cout << "Enter please '.' instead ','\n";
					}
				}
				else {
					break;
				}
			}
			numbers[i] = number;
			i++;

			count++;

			if (cin.peek() == '\n') {
				break;
			}
		}
		if (count == Coloumn) {
			return numbers;
		}
		else {
			cout << "Error \nYou entered more than " << Coloumn << " number(-s)\n";
			cin.clear();
			cin.ignore(3215, '\n');
			return RowControl();
		}
	}
public:
	T** GetArr() {
		return Arr;
	}

	void SetMij(int i, int j, T value) {
		if ((i < 0) || (i >= Row))
			return;
		if ((j < 0) || (j >= Coloumn))
			return;
		Arr[i][j] = value;
	}
	T GetMij(int i, int j) {
		if ((i < 0) || (i >= Row))
			return 0;
		if ((j < 0) || (j >= Coloumn))
			return 0;
		return Arr[i][j];
	}

	int GetRow() {
		return Row;
	}
	int GetColoumn() {
		return Coloumn;
	}

	Matrix(int Row, int Coloumn)
	{
		this->Row = Row;
		this->Coloumn = Coloumn;
		Arr = (T**) new T * [Coloumn];
		for (size_t i = 0; i < Row; i++)
		{
			Arr[i] = (T*)new T[Coloumn];
		}
		for (size_t i = 0; i < Row; i++)
		{
			for (size_t j = 0; j < Coloumn; j++)
			{
				Arr[i][j] = 0;
			}
		}
	}

	void SetMatrix() {
		float number;
		float* numbers;
		cout << "Enter the number" << endl;
		for (size_t i = 0; i < Row; i++)
		{
			numbers = RowControl();
			for (size_t j = 0; j < Coloumn; j++)
			{
				Arr[i][j] = numbers[j];
			}
		}
	}

	void Print(string name = "") {
		cout << endl;
		if (name != "")
			cout << name << endl;
		for (size_t i = 0; i < Row; i++)
		{
			for (size_t j = 0; j < Coloumn; j++)
			{
				cout << Arr[i][j]<< "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
};
#pragma once
class Lab2_2
{
private:
	template <typename T>
	static Matrix<T> MultiplicationOfMatrix(Matrix<T> matrix1, Matrix<T> matrix2) {
		if (matrix1.GetColoumn() != matrix2.GetRow()) {
			cout << "Coloumn of matrix1 isn't equal row of matrix2" << endl;
			Matrix<T> matrixResult(0, 0);
			return matrixResult;
		}
		Matrix<T> matrixResult(matrix1.GetRow(), matrix2.GetColoumn());
		T result = 0;
		for (size_t i = 0; i < matrix1.GetRow(); i++)
		{
			for (size_t j = 0; j < matrix2.GetColoumn(); j++)
			{
				result = 0;
				for (size_t k = 0; k < matrix1.GetColoumn(); k++)
				{
					result += matrix1.GetMij(i, k) * matrix2.GetMij(k, j);
					matrixResult.SetMij(i, j, result);
				}
			}
		}
		return matrixResult;
	}

	template <typename T>
	static string Determinant(T** Arr, int size, int size2)
	{
		if (size != size2) {
			cout << "Row isn't equal Coloumn" << endl;
			return "None";
		}
		int i, j;
		float determinant = 0;
		T** matr;

		if (size == 1) { determinant = Arr[0][0]; }
		else if (size == 2) { determinant = Arr[0][0] * Arr[1][1] - Arr[0][1] * Arr[1][0]; }
		else
		{
			matr = new T * [size - 1];
			for (i = 0; i < size; ++i)
			{
				for (j = 0; j < size - 1; ++j)
				{
					if (j < i)
						matr[j] = Arr[j];
					else
						matr[j] = Arr[j + 1];
				}
				determinant += pow(-1, (i + j)) * stof(Determinant(matr, size - 1, size - 1)) * Arr[i][size - 1];
			}
		}
		return to_string(determinant);
	}

	template <typename T>
	static void SeeDeterminant(Matrix<T> matrix) {
		while (true) {
			int see_det = 0;
			cout << "1 - See determinant \n2 - scip" << endl;
			cin >> see_det;
			if (see_det == 1) {
				string d = Determinant(matrix.GetArr(), matrix.GetRow(), matrix.GetColoumn());
				cout << "determinant = " << d << endl;;
				break;
			}
			else if (see_det == 2) {
				break;
			}
		}
	}

	static int SetRow(string title = "", int maxcount = 1) {
		int number = 0;
		int count = 0;
		cout << title;
		while (true) {
			while (true) {
				cin >> number;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(3216, '\n');
					cout << "Invaid value\n";
					cout << title;

				}
				else {
					if (number > 0) {
						break;
					}
					cout << "Row can't be less than 1" << endl;
				}
			}
			count++;

			if (cin.peek() == '\n') {
				break;
			}
		}
		if (count == maxcount) {
			return number;
		}
		else {
			cout << "Error \nYou entered more than " << maxcount << " numbers\n";
			cin.clear();
			cin.ignore(3215, '\n');
			return SetRow(title, maxcount);
		}
	}

public:
	static void Start() {
		int det = 0;
		int Row = 0;
		int Coloumn = 0;

		Row = SetRow("Enter row of matrix: ");
		Coloumn = SetRow("Enter coloumn of matrix: ");
		Matrix<float> matrix1(Row, Coloumn);

		matrix1.SetMatrix();
		matrix1.Print("matrix 1");

		SeeDeterminant(matrix1);

		Row = SetRow("Enter row of matrix: ");
		Coloumn = SetRow("Enter coloumn of matrix: ");
		Matrix<float> matrix2(Row, Coloumn);

		matrix2.SetMatrix();
		matrix2.Print("matrix 2");

		SeeDeterminant(matrix2);

		Matrix<float> matrixResult = MultiplicationOfMatrix(matrix1, matrix2);

		if (matrixResult.GetRow() != 0) {
			matrixResult.Print("matrix Result");
			SeeDeterminant(matrixResult);
		}
	}
};

