#include"Vector.h"

int main() {


	Vector v;
	v >> 5; //Добавляем элементы >>
	v >> 8;
	v >> 2;
	v >> 12;
	v << 0; //удаляет 0 индекс << или по позиций


	v << 0;
	~v;
	for (int i = 0; i < v.size(); i++)
	{
		cout<<v[i]<<" ";
	}

	v++;
	++v;
	cout << v << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	v.add(5);
	v.add(2);
	v.add(8);
	v.add(12);

	Vector v1;
	v1.add(8);
	v1.add(12);

	Vector r = v + v1;*/ //Оператор +
	v - v1;

	cout << v.operator[](0) << endl;

	for (int i = 0; i < v.size(); i++)//удаляет одинаковые элементы
	{
		cout << v[i] << " ";
	}
	cout << endl;


	Vector v3(v); //копирование элементов поэтому выводит true если его убрать копирование  элементы разные то выводит false


	if (v == v3) //сравнение элементов
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;

	if (v != v3) //не равен  он работает противоположно элементу 
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;




	system ("pause");
}