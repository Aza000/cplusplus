#include<iostream>
#include<ctime>
#include<string>
#include<Windows.h>
#include<cstdlib>
using namespace std;
int main() {

	//Циклический сдвиг
	const int n = 7; //элементов
	int a[7] = { 12,5,6,10,9,38,40 }; //7 чисел
	int b[n]; //перемещение в массив
	int k = 1; // на сколько элементов хотим сдвинуть
	for (int i = 0; i < n; i++) {

		if (i + k < n) 
		{
			b[i + k] = a[i];
		}

		else 
		{
			b[i + k - n] = a[i];
		}
	
	}
		for (int i = 0; i < n; i++) 
		{

			cout << b[i] << " ";
		}


	cout << endl;
	//сдвиг налево
	const int n = 7;
	int a[n] = { 12, 5, 6, 10, 9, 38, 40 };
	int b[n];
	int k = 2;
	for (int i = k; i < n; i++)
	{
		b[i - k] = a[i];
	}
	
	for (int i = 0; i < k; i++) {
		b[n - k + i] = a[i];
	}

	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}


	cout << endl;

	//Бинарный пойск
	const int n = 11;
	int key;
	int a[n] = { 1, 2, 4, 5, 7, 8, 9, 11, 14, 15, 20 };

	int left = 0, right = 10, mid;
	cin >> key;

	while (left <= right) 
	{
		mid = (left + right) / 2;

		if (a[mid] > key) 
		{
			right = mid - 1;
		}

		else if (a[mid] < key) 
		{
			left = mid + 1;
		}

		else 
		{
			cout << mid << endl;
			break;
		}
	}
	
	//Пузырьковый сортировка
	const int n = 11;
	int tmp;
	int a[n] = { 4, 7, 21, 45, 3, 17, 43, 67, -1, 54, 52 };

	for(int pass=0;pass<n-1;pass++){

		for (int i = 0; i < n - 1; i++) {
			if(a[i]>a[i+1])
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}

	}	
		for (int i = 0; i < n; i++)
		cout << a[i] << " ";
		cout << endl;
	}
	
	//Сортировка с выбором

	const int n = 11;
	int tmp;
	int max_pos;
	int a[n] = { 4, 7, 21, 45, 3, 17, 43, 67, -1, 54, 52 }; 
	int max;

	for (int i = 0; i < n - 1; i++) {

		max = a[i];
		for (int j = i; j < n; j++) {
			if (a[j] >= max) {

				max = a[j];
				max_pos = j;
			}
		}
		swap(a[i], a[max_pos]);

		for (int k = 0; k < n; k++)
			cout << a[k] << " ";
		cout << endl;
	}
	
	
	
	system("pause");
	return 0;
}