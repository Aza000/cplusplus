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
		cout << "¬ведите 1 чтобы вывести студентов мужского пола" << endl;
		cout << "¬ведите 2 чтобы вывести студентов женского пола" << endl;
		cout << "¬ведите 3 чтобы вывести студентов по группам" << endl;
		cout << "¬ведите 4 чтобы вывести самого молодого препода" << endl;
		cout << "¬ведите 5 чтобы вывести самого старшего препода" << endl;
		cout << "¬ведите 6 чтобы вывести преподавателей по кафедрам" << endl;
		cout << "¬ведите 7 чтобы вывести студентов сдавших экзамен на 5" << endl;
		cout << "¬ведите 8 чтобы вывести студентов сдавших экзамен на 2" << endl;
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
			cout << "¬ведите группу" << endl;
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
			cout << "¬ведите кафедру" << endl;
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