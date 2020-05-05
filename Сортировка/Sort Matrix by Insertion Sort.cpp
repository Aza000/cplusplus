#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


using namespace std;

int main() {
	const int n = 4;
	const int m = 10;
	int a[n][m];
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 11;
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	int nn, mm;
	int k = 0;
	for (int pass = 0; pass < n*m; pass++) {
		k = 0;
		for (int i = pass / m; i >= 0; i--) {
			k++;
			if (k == 1)
				mm = pass % m;
			else
				mm = m - 1;
			for (int j = mm; j > 0; j--) {
				if (a[i][j] < a[i][j - 1])
					swap(a[i][j], a[i][j - 1]);
				else break;		}

			if (i > 0)
			{
				if (a[i][0] < a[i - 1][m - 1])
					swap(a[i][0], a[i - 1][m - 1]);
				else break;
			}
		}
	}

	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}