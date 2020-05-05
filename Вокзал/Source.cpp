#include"Vokzal.h"
#include<vector>
#include<algorithm>
int main()
{
	setlocale(LC_ALL, "");


	Vokzal l;
	vector<Vokzal>el;
	//el.push_back(124, "17.11.2019", "Astana");
	el.push_back(Vokzal(124, "17.11.2019", "Astana"));
	el.push_back(Vokzal(125, "15.11.2019", "Almaty"));
	l.enter();
	el.push_back(l);
	
	for_each(el.begin(), el.end(), [](Vokzal el) {el.print(); });
	cout << "¬вдите дл€ пойска" << endl;
	int vvod;
	cin >> vvod;

   

	for_each(el.begin(), el.end(), [vvod](Vokzal el) {el.poisk(vvod); });







	system("pause");
}
