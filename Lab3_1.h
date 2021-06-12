#include <algorithm>
#include <string>
#include "CommonFunctions.h" 
using namespace std;

class Lab3_1
{
private:
	static string* GetItemsFromLineWitSeparator(char separator, int Count = -1) {
		string line;
		string changedline;

		string item;
		string* itemsRow = new string[Count];

		int count;
		while (true) {
			count = 1;
			itemsRow->clear();

			getline(cin, line);

			for (size_t i = 0; i < line.length(); i++)
			{
				if (line[i] == separator) {
					itemsRow[count-1] = item;
					item = "";
					count++;
				}
				else if (line[i] != ' ') {
					item += line[i];
				}
				/*else if (line[i] != ' ' || (line[i] == ' ' && line[i + 1] != ' ')) {
					if (line[i] == ' ' && line[i-1] == ' ') {
						continue;
					}
					else {
						item += line[i];
					}
				}*/
			}

			if (count == Count || Count < 0) {
				itemsRow[count-1] = item;
				//cin.ignore(3216, '\n');
				return itemsRow;
			}
			else if (count > Count) {
				cout << "Error \nYou entered more than " << Count << " items\n";
			}
			else {
				cout << "Error \nYou entered less than " << Count << " items\n";
			}
		}
	}

	static void SetMassive(string** massive, const int *Row, const int *Coloumn) {
		string item = "";
		string* items;
		for (size_t i = 0; i < *Row; i++)
		{
			cout << "Enter items of massive \n";
			items = GetItemsFromLineWitSeparator(',', *Coloumn);
			for (size_t j = 0; j < *Coloumn; j++)
			{
				massive[i][j] = items[j];
			}
		}
	}

	static void SortMassiveByAphabet(string** massive, int Row, int Coloumn) {
		int ColoumnSort = 0;

		for (size_t c = 0; c < Coloumn; c++)
		{
			for (size_t i = 0; i < Row - 1; i++) {
				for (size_t j = i + 1; j < Row; j++)
				{
					for (ColoumnSort = 0; ColoumnSort < Coloumn && massive[i][ColoumnSort] == massive[j][ColoumnSort]; ColoumnSort++);
					
					if (strcmp(massive[i][ColoumnSort].c_str(), massive[j][ColoumnSort].c_str()) > 0) {
						for (int coloumn = 0; coloumn < Coloumn; coloumn++)
						{
							swap(massive[i][coloumn], massive[j][coloumn]);
						}
					}
				}
			}
			
		}
	}

		/*aab bbb
		  aca ccc
		  aab bab*/

	  /*abc bbb
		abb ccc
		abb ccb*/

	/*abc bbb abc
		abb ccc ccb
		abb ccc ccc*/

public:
	static void Start() {
		cout << "Enter Row of massive: ";
		int _row = CommonFunctions::SetNumberRange<int>(2, 100);
		int *Row = &_row;

		cout << "Enter Coloumn of massive: ";
		int _coloumn = CommonFunctions::SetNumberRange<int>(2, 100);
		int* Coloumn = &_coloumn;

		string** massive = new string*[*Row];
		for (size_t i = 0; i < *Row; i++)
		{
			massive[i] = new string[*Coloumn];
		}
		SetMassive(massive, Row, Coloumn);

		cout << "Before \n";
		CommonFunctions::ShowMassive(massive, Row, Coloumn);

		SortMassiveByAphabet(massive, *Row, *Coloumn);
		cout << "After \n";
		CommonFunctions::ShowMassive(massive, Row, Coloumn);
	}
};

