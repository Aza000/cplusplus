#include <iostream>
#include<ctime>
#include <Windows.h>
#include <iomanip>
using namespace std;
const int n = 6;
const int m=8;

/****Ќапишите функцию, котора€ принимает массив цифр и количество цифр и выводит на экран все возможные комбинации этих цифр. –ешить с помощью рекурсии.

***Ќапишите функцию, котора€ принимает двухмерный массив, заполненный нул€ми и единицами, 0 Ц вода, 1 Ц земл€. ќпределить количество островов. ќстров Ц это одна или несколько единиц окруженных водой (нул€ми) со всех сторон.

*/

int incfection(int a[][m], int n, int m, int i, int j) {
	static int k = 0;
	if (i >= 0 && i < n && j >= 0 && j < m) {
		if (a[i][j] == 1) {
			k++;			a[i][j] = 2;
			if(a[i-1][j]==1)incfection(a, n, m, i - 1, j);
			if (a[i+1][j] == 1)incfection(a, n, m, i + 1, j);
			if (a[i][j-1] == 1)incfection(a, n, m, i, j-1);
			if (a[i][j+1] == 1)incfection(a, n, m, i, j+1);

			if (a[i-1][j - 1] == 1)incfection(a, n, m, i-1, j - 1);
			if (a[i - 1][j + 1] == 1)incfection(a, n, m, i - 1, j + 1);
			if (a[i + 1][j - 1] == 1)incfection(a, n, m, i + 1, j - 1);
			if (a[i + 1][j + 1] == 1)incfection(a, n, m, i + 1, j + 1);			}
	}
	return k;}

bool labirint(int a[][m], int n, int m, int i, int j) {
	static bool flag = false;
	if (i == n - 1 && j == m - 1)
	{
		flag = true;
		return flag;
	}
	if (i >= 0 && i < n && j >= 0 && j < m)
	{
		if (a[i][j] == 1)
		{
			a[i][j] = 2;
			if(a[i-1][j]==1)labirint(a, n, m, i - 1, j);
			if (a[i+1][j] == 1)labirint(a, n, m, i + 1, j);
			if (a[i][j-1] == 1)labirint(a, n, m, i, j - 1);
			if (a[i][j+1] == 1)labirint(a, n, m, i, j + 1);
		}
		return flag;
	}
}

void fill_array(int a[][m], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = bool(rand() % 2);
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void print_array(int a[][m], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void add_element(int * &a, int &n, int value) {
	int zero_index = -1;
	int* buffer;
	for (int i = 0; i < n; i++)
	{	if (a[i] < 0) {
			zero_index = i;
			break;	}
	}
	buffer = new int[n + 1];
	for (int i = 0; i <= zero_index; i++)
	{		buffer[i] = a[i];	}
	buffer[zero_index + 1] = value;
	for (int i = zero_index + 2; i < n + 1; i++)
		buffer[i] = a[i - 1];
	delete[]a;
	a = buffer;
	n++;
}

void ones(int a[][m], int i, int j) {
	if (a[i][j] == 1) {
		a[i][j] = 2;

		if (a[i - 1][j] == 1) ones(a, i - 1, j);
		if (a[i + 1][j] == 1) ones(a, i + 1, j);
		if (a[i][j-1] == 1) ones(a, i , j-1);
		if (a[i][j+1] == 1) ones(a, i, j+1);

	}
}

int island(int a[][m]) {
	static int k = 0; 
	bool flag = false;
	for (int ii = 0; ii < n; ii++)
	{
		for (int jj = 0; jj < m; jj++)
		{
			if(a[ii][jj]==1)
			{
				flag = true;
				ones(a, ii, jj);
				k++;
				break;
			}
		}
	}
	if (flag == false) return k;
	island(a);
}


int main() {	
	
	int a[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			a[i][j] = (!bool(rand() % 4));
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	cout<<island(a)<<endl;
	system("pause");

	return 0;
}




