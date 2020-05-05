#include <queue>
#include <iostream>
#include <fstream>
#include "Catalog.h"
#include "Bid.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");


	Catalog cat;
	ifstream in("in.txt");
	priority_queue<Bid>bids;
	while (!in.eof())
	{
		Product p;
		in >> p;
		cat.push(p);
	}
	for (int i = 0; i < cat.size(); i++)
	{
		cout << cat[i] << endl;
	}
	int beg_time = time(NULL);
	int choice;
	while (true)
	{
		int cur_time = time(NULL);
		cout << Date::Time(cur_time) << endl;
		if (beg_time + 20 <= cur_time)
			break;
		cout << "¬ведите 1 чтобы сделать ставку" << endl;
		cout << "¬ведите любую цифру чтобы выйти" << endl;
		cin >> choice;
		Bid b;
		if (choice == 1)
		{
			cout << "¬ведите им€ название продукта цену количество" << endl;
			cin >> b;
			int index = cat.find(b.getProductTitle().c_str());
			if (index != -1 && b.getBid_Price() >= cat[index].getPrice())
				bids.push(b);
		}
	}


	while (!bids.empty())
	{
		int index = cat.find(bids.top().getProductTitle().c_str());
		if (cat[index].getAmount() > 0)
		{
			if (cat[index].getAmount() < bids.top().getAmount())
			{
				Bid tmp = bids.top();
				tmp.setAmount(cat[index].getAmount());
				bids.pop();
				bids.push(tmp);
				cat[index].getAmount() = 0;

			}
			else cat[index].getAmount() -= bids.top().getAmount();
			cout << bids.top() << endl;
		}
		bids.pop();
	}

	system("pause");
	
	return 0;
}