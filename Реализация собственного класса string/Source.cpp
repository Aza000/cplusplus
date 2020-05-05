#include "String.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	setlocale(0, "");

	//Копирование
	String s1(s);
	cout << s1 << endl;

	//Сравнение с помощью гетСтр возврата
	String str("example");
	cout << strcmp(str.getStrRep(), "example") << endl;

	//Добавление элемента через замену символа
	s.getAt(1) = 'X';
	cout << s << endl;

	//Добавление элемента через указанную позицию
	String sot("example");
	sot.AddCharAt(7, 'X');
	cout << sot << endl;

	//Добавление элементов в конец строки через цикл
	String sot("example");
	for(int i = 0; i < 10; i++)
	sot.AddCharAt(sot.size(), char('a'+ i));
	cout << sot << endl;

	//Удаление элемента по позиции
	String del_pos("example");
	del_pos.DelCharAt(3);
	cout << del_pos << endl;

	//Добавление другой строки в без пробела в первую
	String s("example");
	String s1("text");
	s.ConcatStr(s1);
	cout << s << endl;

	//Добавление прямого текста в строку без пробела
	String s("example");
	s.ConcatStr("hello");
	cout << s << endl;

	//Добавление одной строки в начальную строку с помощью оператора +
	String s("example"); 
	String s1("text");
	cout << s + s1 << endl;

	//Добавление прямого текста в начальную строку с помощью оператора +
	String w("example");
	String w1 = w + "hello";
	cout << w1 << endl;

	//Добавление символа в начальную строку с помощью оператора +
	String q("Allo");
	char c = 'O';
	String q1 = q + c;
	cout << q1 << endl;

	//Добавление одной строки в начальную строку с указанной позиции символа
	String s("example");
	String s1("nana");
	s.AddStrAt(s1, 3);
	cout << s << endl;

	//Добавление прямого текста в начальную строку с указанной позиции символа
	String s("example");
	s.AddStrAt("hello", 3);
	cout << s << endl;

	//Удаление символов строки между элементами
	String s("Zastraxuy");
	s.DelStrAt(0, 5);
	cout << s << endl;

	//Сравнение двух строк и вывод позиции начала когда найдет
	String s("this is example");
	String s1("example");
	cout << s.SubStr(s1) << endl;

	//Сравнение двух строк и вывод позиции начала когда найдет
	String s("this is example");
	String s1("example");
	cout << s.SubStr(s1) << endl;

	//Поиск слова из строки в основной строке и замена его словом из третьей строки
	String s("this is example for example");
	String s1("example");
	String s2("allo");
	cout << s.Replace(s1, s2) << endl;

	//Поиск константного слова в основной строке и замена его константным словом
	String s("this is example for example");
	cout << s.Replace("example", "IUIU") << endl;

	//Вывод символов из строки в  диапазоне указанного нами 
	/*String s("this is example for example");
	cout << s.GetRange(2, 12);*/

	//Создание нового обьекта с помощью передаваеммых в него разных типов данных
	cout << String::Format("iicd", 34, 78, 'S', 27.5);


	system("pause");
	return 0;
}