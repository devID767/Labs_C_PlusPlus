#pragma once
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Lab3_2 {
private:
	static int LeftResult(int *massive, const int *coloumn) {
		return SummOfPartColoumns(massive, coloumn, true);
	}
	static int RightResult(int* massive, const int *coloumn) {
		return SummOfPartColoumns(massive, coloumn, false);
	}

	static void SortMassive(int** massive, const int* row, const int* coloumn) {
		auto summOfColoums = SummOfColoumns(massive, row, coloumn);

		int leftResult = LeftResult(summOfColoums, coloumn);
		int rightResult = RightResult(summOfColoums, coloumn);

		//cout << "Left result = " << leftResult << " Right result = " << rightResult << endl;
		if(leftResult != rightResult)
		{
			int savedValue;
			//ShowArr(summOfColoums, *coloumn);
			SortPartSumm(summOfColoums, *coloumn);

			int *summOfColoums_New;
			for (size_t i = 0; i < *coloumn; i++)
			{
				summOfColoums_New = SummOfColoumns(massive, row, coloumn);
				if (summOfColoums[i] != summOfColoums_New[i]) {
					for (size_t j = i; j < *coloumn; j++)
					{
						if (summOfColoums[i] == summOfColoums_New[j]) {
							for (size_t k = 0; k < *row; k++)
							{
								savedValue = massive[k][i];
								massive[k][i] = massive[k][j];
								massive[k][j] = savedValue;
							}
							break;
						}
					}
				}
			}

		/*	leftResult = LeftResult(summOfColoums, coloumn);
			rightResult = RightResult(summOfColoums, coloumn);

			cout << "Sorted matrix: \n";
			CommonFunctions::ShowMassive(massive, row, coloumn);
			cout << "Left result = " << leftResult << " Right result = " << rightResult << endl;
			ShowArr(summOfColoums, *coloumn);*/
		}
	}

	static void SortPartSumm(int* massive, int length) {
		sort(massive, massive + length);
		 
		int savedValue;
		for (size_t i = 0; i < length/2; i++)
		{
			savedValue = massive[length - 1 - i];
			massive[length - 1 - i] = massive[i];
			massive[i] = savedValue;
		}

		int leftLength = length / 2;
		int rightLength = length - leftLength;

		int* A = new int[leftLength] {0};
		int* B = new int[rightLength] {0};

		int CountA = 0;
		int CountB = 0;

		for (size_t i = 0; i < length; i++)
		{
			if (Summ(B, rightLength) < Summ(A, leftLength)) {
				B[CountB] = massive[i];
				CountB++;
			}
			else if (Summ(B, rightLength) == Summ(A, leftLength)) {
				if (Summ(A, leftLength) == 0) {
					A[CountA] = massive[i];
					CountA++;
				}
				else {
					if (CountA < CountB) {
						A[CountA] = massive[i];
						CountA++;
					}
					else if (CountA == CountB) {
						if (CountA == leftLength) {
							B[CountB] = massive[i];
							CountB++;
						}
						else {
							A[CountA] = massive[i];
							CountA++;
						}
					}
					else {
						B[CountB] = massive[i];
						CountB++;
					}
				}
			}
			else
			{
				A[CountA] = massive[i];
				CountA++;
			}
		}
		for (size_t i = 0; i < leftLength; i++)
		{
			massive[i] = A[i];
		}
		for (size_t i = 0; i < rightLength; i++)
		{
			massive[i + leftLength] = B[i];
		}

		delete[] A;
		delete[] B;
	}

	static int Summ(int * arr, int length) {
		int result = 0;
		for (size_t i = 0; i < length; i++)
		{
			result += arr[i];
		}
		return result;
	}

	static int* SummOfColoumns(int** massive, const int* row, const int* coloumn) {
		int currentColoumn = 0;
		int result;
		int *SummOfColoumn = new int[*coloumn];

		for (size_t i = 0; i < *coloumn; i++)
		{
			result = 0;
			for (size_t j = 0; j < *row; j++)
			{
				result += massive[j][i];
			}
			SummOfColoumn[currentColoumn] = result;
			currentColoumn++;
		}
		return SummOfColoumn;
	}

	static int SummOfPartColoumns(int* massive, const int* coloumn, bool left) {
		int result = 0;

		int leftColoumn = *coloumn / 2;

		if (left) {

			for (size_t j = 0; j < leftColoumn; j++)
			{
				result += massive[j];
			}
		}
		else {
			for (int j = *coloumn - 1; j >= leftColoumn; j--)
			{
				result += massive[j];
			}
		}
		return result;
	}

public:
	static void Start() {
		cout << "Enter Row of massive: ";
		int _row = CommonFunctions::SetNumberRange<int>(2, 100);
		int* Row = &_row;

		cout << "Enter Coloumn of massive: ";
		int _coloumn;
		while (true) {
			_coloumn = CommonFunctions::SetNumberRange<int>(2, 100);
			if (_coloumn % 2 != 0) {
				cout << "The columns must be paired \n";
			}
			else {
				break;
			}
		}
		int* Coloumn = &_coloumn;

		int** massive = new int* [*Row];
		for (size_t i = 0; i < *Row; i++)
		{
			massive[i] = new int[*Coloumn];
		}

		CommonFunctions::SetMassiveWithRandomRange(massive, *Row, *Coloumn, 0, 2);
		CommonFunctions::ShowMassive(massive, Row, Coloumn);

		auto summOfColoums = SummOfColoumns(massive, Row, Coloumn);
		int leftResult = LeftResult(summOfColoums, Coloumn);
		int rightResult = RightResult(summOfColoums, Coloumn);

		cout << "Left result = " << leftResult << " Right result = " << rightResult << endl;
		CommonFunctions::ShowArr(summOfColoums, *Coloumn);

		cout << "Sorted massive: \n";
		SortMassive(massive, Row, Coloumn);

		summOfColoums = SummOfColoumns(massive, Row, Coloumn);
		leftResult = LeftResult(summOfColoums, Coloumn);
		rightResult = RightResult(summOfColoums, Coloumn);

		CommonFunctions::ShowArr(summOfColoums, *Coloumn);
		cout << "Left result = " << leftResult << " Right result = " << rightResult << endl;
		CommonFunctions::ShowMassive(massive, Row, Coloumn);
	}
};
