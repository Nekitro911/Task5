// Task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

const int N = 10;

struct information
{
	char name[50];
	char location[50];
	char number[50];
};

struct information directory[N] =
{
	{ "Natasha", "Ciolkovskogo 25", "89134728567" },
	{ "Maxsim", "Marta 126", "89134728567" },
	{ "Alexei", "Geologisheskaia 15", "89134728567" },
	{ "Victor", "Aviacionnaia 9", "89134728567" },
	{ "Ksenia", "Lenina 2", "89134728567" },
	{ "Ekaterina", "Belinskogo 49", "89134728567" },
	{ "Elena", "Komandirov 2", "89134728567" },
	{ "Vladimir", "Serafima 22", "89134728567" },
	{ "Mihail", "Dekabristov 63", "89134728567" },
	{ "Sasha", "Lyksemburg 50", "8464" },
};

int IndexArray[N];
void ViewDirectory(void);
void QuickSortName(int* array, int left, int right);
void QuickSortLocation(int* array, int left, int right);
void QuickSortNumber(int* array, int left, int right);
void NameSort(int* array);
void LocationSort(int* array);
void NumberSort(int* array);
void FindName(void);
void FindLocation(void);
void FindNumber(void);
int main()
{
	system("mode con cols=80 lines=30");
	system("color 0");
	char c;
	while (1)
	{
		cout << "\n";
		cout << " 1) Sortirovka po Name\n";
		cout << " 2) Sortirovka po Address\n";
		cout << " 3) Sortirovka po Telephone\n";
		cout << " 4) Search po Name\n";
		cout << " 5) Search po Address\n";
		cout << " 6) Search po Telephone\n";
		cout << " Esc - Exit";
		c = _getch();
		switch (c)
		{
			system("cls");
		case '1':system("cls"); NameSort(IndexArray); ViewDirectory(); system("pause"); system("cls"); break;
		case '2':system("cls"); LocationSort(IndexArray); ViewDirectory(); system("pause"); system("cls"); break;
		case '3':system("cls"); NumberSort(IndexArray); ViewDirectory(); system("pause"); system("cls"); break;
		case '4':system("cls"); NameSort(IndexArray); FindName(); system("pause"); system("cls"); break;
		case '5':system("cls"); NameSort(IndexArray); FindLocation(); system("pause"); system("cls"); break;
		case '6':system("cls"); NameSort(IndexArray); FindNumber(); system("pause"); system("cls"); break;
		case 27:return 0;
		default:cout << "\n Error!"; _getch(); system("cls");
		}
	}
}
void ViewDirectory()
{
	cout << "\n";
	cout << "  Name                 Address                        Telephone            \n";
	cout << " ==========================================================================\n";
	for (int i = 0; i < N; i++)
	{
		printf("  %-20s %-30s %-6d  \n", directory[IndexArray[i]].name, directory[IndexArray[i]].location, directory[IndexArray[i]].number);
	}
	cout << " ==========================================================================\n";
	cout << "\n\n";
}

void QuickSortName(int* array, int left, int right)
{
	int l = left;
	int r = right;
	char middle[25];
	strcpy_s(middle, directory[IndexArray[(l + r) / 2]].name);
	do
	{
		while (strcmp(directory[IndexArray[l]].name, middle) < 0)
			l++;
		while (strcmp(directory[IndexArray[r]].name, middle) > 0)
			r--;
		if (l <= r)
		{
			int temp = IndexArray[l];
			IndexArray[l] = IndexArray[r];
			IndexArray[r] = temp;
			l++;
			r--;
		}
	} while (l < r);
	if (left < r) QuickSortName(array, left, r);
	if (l < right) QuickSortName(array, l, right);
}

void QuickSortLocation(int* array, int left, int right)
{
	int l = left;
	int r = right;
	char middle[25];
	strcpy_s(middle, directory[IndexArray[(l + r) / 2]].location);
	do
	{
		while (strcmp(directory[IndexArray[l]].location, middle) < 0)
			l++;
		while (strcmp(directory[IndexArray[r]].location, middle) > 0)
			r--;
		if (l <= r)
		{
			int temp = IndexArray[l];
			IndexArray[l] = IndexArray[r];
			IndexArray[r] = temp;
			l++;
			r--;
		}
	} while (l < r);
	if (left < r) QuickSortLocation(array, left, r);
	if (l < right) QuickSortLocation(array, l, right);
}

void QuickSortNumber(int* array, int left, int right)
{
	int l = left;
	int r = right;
	char middle[25];
	strcpy_s(middle, directory[IndexArray[(left + right) / 2]].number);

	do
	{
		while (strcmp(directory[IndexArray[l]].number, middle) < 0)
			l++;
		while (strcmp(directory[IndexArray[r]].number, middle) > 0)
			r--;
		if (l <= r)
		{
			int temp = IndexArray[l];
			IndexArray[l] = IndexArray[r];
			IndexArray[r] = temp;
			l++;
			r--;
		}
	} while (l < r);
	if (left < r) QuickSortNumber(array, left, r);
	if (l < right) QuickSortNumber(array, l, right);
	/*int l = left;
	int r = right;
	char x = directory[IndexArray[(left + right) / 2]].number;
	do
	{
		while (directory[IndexArray[l]].number < x)
			l++;
		while (directory[IndexArray[r]].number > x)
			r--;
		if (l <= r)
		{
			int temp = IndexArray[l];
			IndexArray[l] = IndexArray[r];
			IndexArray[r] = temp;
			l++;
			r--;
		}
	} while (l < r);
	if (left < r) QuickSortNumber(array, left, r);
	if (l < right) QuickSortNumber(array, l, right);*/
}
void NameSort(int* array)
{
	int i = 0;
	while (i < N)
	{
		array[i] = i;
		i++;
	}
	QuickSortName(array, 0, N - 1);
}

void LocationSort(int* array)
{
	int i = 0;
	while (i < N)
	{
		array[i] = i;
		i++;
	}
	QuickSortLocation(array, 0, N - 1);
}

void NumberSort(int* array)
{
	int i = 0;
	while (i < N)
	{
		array[i] = i;
		i++;
	}
	QuickSortNumber(array, 0, N - 1);
}
void FindName()
{
	char find[50];
	bool found = false;
	cout << "\n";
	cout << " Vvedite Name dlia search: ";
	gets_s(find);
	cout << "\n";
	cout << "  Name                 Address                        Telephone            \n";
	cout << " ==========================================================================\n";
	for (int i = 0; i < N; i++)
	{
		if (strcmp(directory[IndexArray[i]].name, find) == 0)
		{
			printf("  %-20s %-30s %-6d  \n", directory[IndexArray[i]].name, directory[IndexArray[i]].location, directory[IndexArray[i]].number);
			found = true;
		}
		else
			i = i;
	}
	if (found == false)
	{
		cout << "\n";
		cout << "Zapisi ne naideno!";
		cout << "\n";
	}
	else
		cout << "\n";
}
void FindLocation()
{
	char find[50];
	bool found = false;
	cout << "\n";
	cout << " Vvedite Address dlia search: ";
	gets_s(find);
	cout << "\n";
	cout << "  Name                 Address                        Telephone            \n";
	cout << " ==========================================================================\n";
	for (int i = 0; i < N; i++)
	{
		if (strcmp(directory[IndexArray[i]].location, find) == 0)
		{
			printf("  %-20s %-30s %-6d  \n", directory[IndexArray[i]].name, directory[IndexArray[i]].location, directory[IndexArray[i]].number);
			found = true;
		}
		else
			i = i;
	}
	if (found == false)
	{
		cout << "\n";
		cout << "Zapisi ne naideno!";
		cout << "\n";
	}
	else
		cout << "\n";
}
void FindNumber()
{
	char find[50];
	bool found = false;
	cout << "\n";
	cout << " Vvedite Telephone dlia search: ";
	cin >> find;
	cout << "\n";
	cout << "  Name                 Address                        Telephone            \n";
	cout << " ==========================================================================\n";
	for (int i = 0; i < N; i++)
	{
		if (strcmp(directory[IndexArray[i]].number, find) == 0)
		{
			printf("  %-20s %-30s %-6d  \n", directory[IndexArray[i]].name, directory[IndexArray[i]].location, directory[IndexArray[i]].number);
			found = true;
		}
		else
			i = i;
	}
	if (found == false)
	{
		cout << "\n";
		cout << "Zapisi ne naideno!";
		cout << "\n";
	}
	else
		cout << "\n";
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
