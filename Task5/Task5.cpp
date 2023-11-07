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
	long number;
};

struct information directory[N] =
{
	{ "Никита", "Чкалова 25", 891258 },
	{ "Андрей", "Ленина 126", 827564 },
	{ "Виктор", "Ленина 15", 987554 },
	{ "Анастасия", "Восход 9", 918254 },
	{ "Кирилл", "Победы 2", 258649 },
	{ "Егор", "Берингова 49", 798385 },
	{ "Александр", "Тунцова 2", 998654 },
	{ "Дарья", "Чашушули 22", 654687 },
	{ "Полина", "Аджарская 69", 945298 },
	{ "Дмитрий", "Комскомольская 50",115642 },
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
	setlocale(LC_ALL, "Russian");
	system("mode con cols=80 lines=30");
	system("color 0");
	char c;
	while (1)
	{
		cout << "\n";
		cout << " 1) Сортировка по Имени\n";
		cout << " 2) Сортировка по Адресу\n";
		cout << " 3) Сортировка по Телефону\n";
		cout << " 4) Поиск по Имени\n";
		cout << " 5) Поиск по Адресу\n";
		cout << " 6) Поиск по Телефону\n";
		cout << " Esc - Выход";
		c = _getch();
		switch (c)
		{
			system("cls");
		case '1':system("cls"); NameSort(IndexArray); ViewDirectory(); system("pause"); system("cls"); break;
		case '2':system("cls"); LocationSort(IndexArray); ViewDirectory(); system("pause"); system("cls"); break;
		case '3':system("cls"); NumberSort(IndexArray); ViewDirectory(); system("pause"); system("cls"); break;
		case '4':system("cls"); NameSort(IndexArray); FindName(); system("pause"); system("cls"); break;
		case '5':system("cls"); LocationSort(IndexArray); FindLocation(); system("pause"); system("cls"); break;
		case '6':system("cls"); NumberSort(IndexArray); FindNumber(); system("pause"); system("cls"); break;
		case 27:return 0;
		default:cout << "\n Ошибка!"; _getch(); system("cls");
		}
	}
}
void ViewDirectory()
{
	cout << "Сортировка по возрастанию:" << endl;
	cout << "  Имя                 Адрес                        Телефон            \n";
	cout << " ==========================================================================\n";
	for (int i = 0; i < N; i++)
	{
		printf("  %-20s %-30s %-6d  \n", directory[IndexArray[i]].name, directory[IndexArray[i]].location, directory[IndexArray[i]].number);
	}
	cout << " ==========================================================================\n";
	cout << "\n\n";
	cout << "Сортировка по убыванию:" << endl;
	cout << "  Имя                 Адрес                        Телефон            \n";
	cout << " ==========================================================================\n";
	for (int i = N-1; i >= 0; i--)
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
void QuickSortLocationRevers(int* array, int left, int right)
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
	int x = directory[IndexArray[(left + right) / 2]].number;
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
	if (l < right) QuickSortNumber(array, l, right);
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
	cout << " Введите номер для поиска: ";
	gets_s(find);
	cout << "\n";
	cout << "  Имя                 Адрес                        Телефон            \n";
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
		cout << "Записей не найдено!";
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
	cout << " Введите адрес для поиска: ";
	gets_s(find);
	cout << "\n";
	cout << "  Имя                 Адрес                        Телефон            \n";
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
	cout << "  Имя                 Адрес                        Телефон            \n";
	cout << " ==========================================================================\n";
	for (int i = N; i = 0; i--)
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
		cout << "Записей не найдено!";
		cout << "\n";
	}
	else
		cout << "\n";
}
void FindNumber()
{
	int find;
	bool found = false;
	cout << "\n";
	cout << " Введите телефон для поиска: ";
	cin >> find;
	cout << "\n";
	cout << "  Имя                 Адрес                        Телефон            \n";
	cout << " ==========================================================================\n";
	for (int i = 0; i < N; i++)
	{
		if (directory[IndexArray[i]].number, find)
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
		cout << "Записей не найдено!";
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
