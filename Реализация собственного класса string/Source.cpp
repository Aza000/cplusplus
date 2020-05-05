#include "String.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	setlocale(0, "");

	//�����������
	String s1(s);
	cout << s1 << endl;

	//��������� � ������� ������ ��������
	String str("example");
	cout << strcmp(str.getStrRep(), "example") << endl;

	//���������� �������� ����� ������ �������
	s.getAt(1) = 'X';
	cout << s << endl;

	//���������� �������� ����� ��������� �������
	String sot("example");
	sot.AddCharAt(7, 'X');
	cout << sot << endl;

	//���������� ��������� � ����� ������ ����� ����
	String sot("example");
	for(int i = 0; i < 10; i++)
	sot.AddCharAt(sot.size(), char('a'+ i));
	cout << sot << endl;

	//�������� �������� �� �������
	String del_pos("example");
	del_pos.DelCharAt(3);
	cout << del_pos << endl;

	//���������� ������ ������ � ��� ������� � ������
	String s("example");
	String s1("text");
	s.ConcatStr(s1);
	cout << s << endl;

	//���������� ������� ������ � ������ ��� �������
	String s("example");
	s.ConcatStr("hello");
	cout << s << endl;

	//���������� ����� ������ � ��������� ������ � ������� ��������� +
	String s("example"); 
	String s1("text");
	cout << s + s1 << endl;

	//���������� ������� ������ � ��������� ������ � ������� ��������� +
	String w("example");
	String w1 = w + "hello";
	cout << w1 << endl;

	//���������� ������� � ��������� ������ � ������� ��������� +
	String q("Allo");
	char c = 'O';
	String q1 = q + c;
	cout << q1 << endl;

	//���������� ����� ������ � ��������� ������ � ��������� ������� �������
	String s("example");
	String s1("nana");
	s.AddStrAt(s1, 3);
	cout << s << endl;

	//���������� ������� ������ � ��������� ������ � ��������� ������� �������
	String s("example");
	s.AddStrAt("hello", 3);
	cout << s << endl;

	//�������� �������� ������ ����� ����������
	String s("Zastraxuy");
	s.DelStrAt(0, 5);
	cout << s << endl;

	//��������� ���� ����� � ����� ������� ������ ����� ������
	String s("this is example");
	String s1("example");
	cout << s.SubStr(s1) << endl;

	//��������� ���� ����� � ����� ������� ������ ����� ������
	String s("this is example");
	String s1("example");
	cout << s.SubStr(s1) << endl;

	//����� ����� �� ������ � �������� ������ � ������ ��� ������ �� ������� ������
	String s("this is example for example");
	String s1("example");
	String s2("allo");
	cout << s.Replace(s1, s2) << endl;

	//����� ������������ ����� � �������� ������ � ������ ��� ����������� ������
	String s("this is example for example");
	cout << s.Replace("example", "IUIU") << endl;

	//����� �������� �� ������ �  ��������� ���������� ���� 
	/*String s("this is example for example");
	cout << s.GetRange(2, 12);*/

	//�������� ������ ������� � ������� ������������� � ���� ������ ����� ������
	cout << String::Format("iicd", 34, 78, 'S', 27.5);


	system("pause");
	return 0;
}