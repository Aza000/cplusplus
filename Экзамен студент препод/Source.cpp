#include"Vector.h"
#include"Student.h"
#include"Teacher.h"
#include<fstream>
char subjekts[5][200] = { "OOP","C++", "ITE" };
int main() {
	setlocale(LC_ALL, "");
	ifstream ins("Student.txt");
	ifstream ints("Teachers.txt");
	Student sobj;
	Teacher tobj;
	
	Vector<Student>ss;
	Vector<Teacher>ts;
	Vector <Exam>es;
	if (ins) {
		while (ins >> sobj) {
			ss.add(sobj);
		}
	}

	if (ints) {
		while (ints >> tobj)
		{
			ts.add(tobj);
		}
	}

	for (int i = 0; i < ss.size(); i++)
	{
		cout << ss[i];
	}

	for (int i = 0; i < ts.size(); i++)
	{
		cout << ts[i];
	}

	for (int i = 0; i < ss.size(); i++)
	{
		
		for (int j = 0; j < ts.size(); j++) {

			es.add(Exam(subjekts[j], ss[i], ts[j], rand() % 5 + 1));
		}
		
	}
	cout << endl;
	for (int i = 0; i < es.size(); i++)
	{
		cout << es[i];
	}
char el[50]="famle";
char el1[50] = "male";
char group[50];
char prepod[50];
	int choice;
	while (true) {
		cout << "������� 1 ����� ������� ��������� �������� ����" << endl;
		cout << "������� 2 ����� ������� ��������� �������� ����" << endl;
		cout << "������� 3 ����� ������� ��������� �� �������" << endl;
		cout << "������� 4 ����� ������� ������ �������� �������" << endl;
		cout << "������� 5 ����� ������� ������ �������� �������" << endl;
		cout << "������� 6 ����� ������� �������������� �� ��������" << endl;
		cout << "������� 7 ����� ������� ��������� ������� ������� �� 5" << endl;
		cout << "������� 8 ����� ������� ��������� ������� ������� �� 2" << endl;
		cin >> choice;
		if (choice == 0)
			break;
		switch (choice)   
		{
		case 1:
			
			for (int i = 0; i <ss.size() ; i++)
			{
				if (ss[i] !=el)
				{
					cout << ss[i];
				}

			}  
			break;

		case 2:
			for (int i = 0; i < ss.size(); i++)
			{
				if (ss[i] != el1)
				{
					cout << ss[i];
				}
			}
			break;
		case 3:
			cout << "������� ������" << endl;
			cin >> group;
			for (int i = 0; i < ss.size(); i++)
			{
				if (ss[i] == group)
					cout << ss[i];
			}
			break;
		case 4:
			for (int i = 0; i < ts.size(); i++)
			{
				if (ts[i] < ts[i+1])
					cout << ts[i];
			}
			break;

		case 5:
			for (int i = 0; i < ts.size(); i++)
			{
				if (ts[i] > ts[i + 1])
					cout << ts[i];
			}
			break;
		case 6:
			cout << "������� �������" << endl;
			cin >> prepod;
			for (int i = 0; i < ts.size(); i++)
			{
				if (ts[i] == prepod)
					cout << ts[i];
			}
			break;
		case 7:
			for (int i = 0; i < ss.size(); i++)
			{
				if (es[i]==5)
					cout << es[i];
			}
			break;
		case 8:
			for (int i = 0; i < es.size(); i++)
			{
				if (es[i] <= 2) {
					cout << es[i];
				}
			}
			break;
		}
	}




	system("pause");

}