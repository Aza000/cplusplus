#include"LinkedList.h"





int main() {

	LinkedList<int>l;
	l.push_back(5);
	l.push_back(8);
	l.push_back(24);
	l.push_back(25);
	l.push_back(244);
	LinkedList<int>l1(l);
	l1.print();
	l.push_front(100);//���������� �� 1 �������
	cout << endl;
	cout << l.pop_back() << endl;///���������� ��������� ��������
	l.pop_front();

	l.print();
	try {
		cout << l[4] << endl;//�������� ���������� ������
	}

	catch (const char *e)
	{
		cout << e << endl;
	}


    l.findAll(5); //����� �� �������


	try {
		 l.insert (2,100);//���������� �� �������
	}

	catch (const char *e)
	{
		cout << e << endl;
	}

	l.print();


	try {
		l.deleteByPos(4);//�������� �� �������
	}

	catch (const char *e)
	{
		cout << e << endl;
	}

	l.print();





	try {
		l.remove_In_Range(1,3);
	}

	catch (const char *e)
	{
		cout << e << endl;
	}

	l.print();



	try {
		l.sort();//buble sort
	}

	catch (const char *e)
	{
		cout << e << endl;
	}
	l.print();


	system("pause");
}