#include <iostream>
#include <Windows.h>
#include <ctime>
#include <thread>
using namespace std;
class functions
{
public:
   void func_AND(int** arr, int n, int x, int z, int num)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i][x] == 1 && arr[i][z] == 1)
			{
				arr[i][num] = 1;
			}
			else
			{
				arr[i][num] = 0;
			}
		}
	}
  void func_OR(int** arr, int n, int x, int z, int num)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i][x] == 1 && arr[i][z] == 1 || arr[i][x] == 1 && arr[i][z] == 0 || arr[i][x] == 0 && arr[i][z] == 1)
			{
				arr[i][num] = 1;
			}
			else
			{
				arr[i][num] = 0;
			}
		}
	}
   void func_NO(int** arr, int n, int x, int num)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i][x] == 0)
			{
				arr[i][num] = 1;
			}
			else
			{
				arr[i][num] = 0;
			}
		}
	}
   void func_Impl(int** arr, int n, int x, int z, int num)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[x][i] <= arr[z][i])
			{
				arr[i][num] = 1;
				arr[2][4] = 1;
			}
			else
			{
				arr[i][num] = 0;
			}
		}
	}
   void print(int** arr, int x, int y)
	{
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cout << *(*(arr + i) + j) << " ";
			}
			cout << endl;
		}
	}

};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	auto start = chrono::high_resolution_clock::now();
	const int n = 4;
	int m = 11;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = new int[m];
	}
	cout << "A" << " B" << "                 F" << endl;
	arr[0][0] = 0;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1;
	arr[2][0] = 1;
	arr[2][1] = 0;
	arr[3][0] = 1;
	arr[3][1] = 1;
	functions Q;
	Q.func_NO(arr, n, 1, 2); // заперечення до B (рядок 2)
	Q.func_OR(arr, n, 0, 2, 3);// A v заперечення B (рядок 3)
	Q.func_Impl(arr, n, 2, 3, 4); // заперечення B -> A v заперечення B (рядок 4)
	Q.func_NO(arr, n, 4, 5); // заперечення до рядка 4 (рядок 5)
	Q.func_AND(arr, n, 0, 5, 6); // A ^ до рядка 5 (рядок 6)
	Q.func_NO(arr, n, 0, 7); // заперечення до A (рядок 7)
	Q.func_OR(arr, n, 7, 1, 8); // заперечення до A v B (рядок 8)
	Q.func_AND(arr, n, 0, 8, 9); // A ^ до рядка 8 (рядок 9)
	Q.func_AND(arr, n, 6, 9, 10); // рядок 6 ^ рядок 9 (рядок 10)
	Q.print(arr, n, m);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> result = end - start;
	cout << endl << result.count() << " секунд";
	delete[] arr;
	return 0;
}