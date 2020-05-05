#include<iostream>
#include<ctime>
using namespace std;

const int n=6;//proverka
const int m=8;
//Ханойские башни
void hanoi(int n, char from, char to, char temp) {
	if (n == 0)
		return;
	hanoi(n - 1, from, temp, to);
	cout << from << "->" << to << endl;
	hanoi(n - 1, temp, to, from);


}
//Бинарный пойск рекурссивно
int recursive_binarny(int a[], int left, int right, int key) {
	if (left > right)
		return -1;
	int middle = (right + left) / 2;

	if (a[middle] == key) return middle;
	else if (key > a[middle]) {
		return recursive_binarny(a, middle + 1, right, key);
	}
	else return  recursive_binarny(a, left, middle - 1, key);


}
   
int proverka(int a[][8], int n, int m, int i, int j) {

	static int k = 0;
	if (i >= 0 && i < n && j >= 0 && j < m) {
		if (a[i][j] == 1) {
			k++;
			a[i][j] = 2;
			// проверка верхнего элемента
			if (a[i - 1][j] == 1)proverka(a, n, m, i - 1, j);
			 // проверка нижнего элемента
			if (a[i + 1][j] == 1)proverka(a, n, m, i + 1, j);
			//проверка левого элемента
			if (a[i][j - 1] == 1)proverka(a, n, m, i, j + 1);
             // проверка правый верхнего элемента			
			if (a[i][j + 1] == 1) proverka(a, n, m, i, j + 1);
			// проверка верхенего левого  угла
			if (a[i - 1][j - 1] == 1) proverka(a, n, m, i - 1, j - 1);
			//проверка верхнего  правого угла
			if (a[i - 1][j + 1] == 1)proverka(a, n, m, i + 1, j + 1);
			// нижний  левый угол
			if (a[i + 1][j - 1] == 1)proverka(a, n, m, i + 1, j - 1);
			//нижний правный угол
			if (a[i + 1][j + 1] == 1)proverka(a, n, m, i + 1, j + 1);
		}
	}

	return k;
}
	void fillarray(int a[][m], int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = bool(rand() % 4);
			}
		}
	}



void print(int a[][m], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

bool labirint(int a[][m], int n, int m, int i, int j) {
	static bool flag = false;
	
		if (i == n - 1 && j == m - 1) {
			a[i][j] = 2;
			flag = true;
			return flag;
		}
		if (i >= 0 && i < n && j >= 0 && j < m) {
			if (a[i][j] == 1) {
				a[i][j] = 2;
				if(a[i-1][j]==1)labirint(a, n, m, i - 1, j);
				if(a[i+1][j]==1)labirint(a, n, m, i + 1, j);
				if (a[i][j + 1] == 1)labirint(a, n, m, i, j + 1);
				if (a[i][j + 1] == 1)labirint(a, n, m, i, j + 1);

			}
			
		}
	
		return flag;
	}



int main() {
	setlocale(0, "");
	int a[n][m];
	srand(time(NULL));
	fillarray(a, n, m);
	/*cout << proverka(a, n, m, 0, 3) << endl;*/
	cout << labirint(a, n, m, 0, 0) << endl;
	print(a, n, m);


	//Бинарный пойск
	/*int key;
	cin >> key;
	int a[7] = { 3,4,6,8,12,15,18 };
	cout << recursive_binarny(a, 0, 6, key)<<endl;*/
	
	//hanoi(4, 'a', 'b', 'c');





	system("pause");
}