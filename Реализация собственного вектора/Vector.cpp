#include "Vector.h"
/*1.	� ����� ��������� ����� ������ �������� ���������� ��������� ����������:
[ ], +, -, <<, >>, ==, !=, ~
�������� + ���������� ��� �������. �������� � ������� �� ������� ������� ��������, ������� ���� �� ������ �������.
�������� << ������� �� ������� ������� � �������� ��������� � �������� ������� �������� � ���������� ��������� ��������, ��������:

	Vector	V;
	V.Add(10);
	V.Add(11);
	V.Add(12);
int a = V << 1;
cout << a << �\n�;			// ������� 11
for ( int i = 0; i < V.Size(); i++)
{
	cout << V[i] << �\n�;		// ������� 10, 12
}

	�������� >> ��������� ����� �������� � ����� ������� (������ ������� Add).
	������� �������� ~ ������� �� ������� ������������� ��������.

	��� �� � ���� ������������� ������� ��������� ���������� ������ � �����:
Vector	V;
	V >> 10;
	V >> 11;
	V >> 12;
	cout << V << �\n�;			// ������� [0] = 10, [1] = 11 � �.�.

	.
*/
Vector::Vector()
{
	els = nullptr;
}

Vector::Vector(int size)
{
	els = new int[size];
	cur_size = 0;
	buf_size = size;
}

Vector::Vector(const Vector & obj)
{
	this->cur_size = obj.cur_size;
	this->buf_size = obj.buf_size;
	this->els = new int[buf_size];
	for (int i = 0; i < cur_size; i++)
	{
		els[i] = obj.els[i];
	}
}

int Vector::operator[](int index)
{
	return els[index];
}

Vector Vector::operator+(Vector obj)
{
	Vector rez(*this);
	for (int i = 0; i < obj.size(); i++)
		rez.add(obj[i]);
	return rez;

}

Vector Vector::operator-(Vector obj)//������� ���������� �������� �������� v 5 v1 5 �� �� �� ������
{
	Vector rez(*this);
	for (int i = 0; i < size(); i++) {
		for (int j = 0; j < obj.size(); j++) {

			if (els[i] == obj[j])
			{
				remove_by_index(i);
				i--;
			}
		}
	}
	
	return (*this);
}

Vector Vector::operator<<(int index)
{
	remove_by_index(index);
	return(*this);
}

Vector Vector::operator>>(int el)
{
	add(el);
	return *this;
}

bool Vector::operator==(Vector obj)
{

	if(size()!=obj.size())
	return false;
	else 
		for (int i = 0; i < size(); i++)
		{
			if (els[i] != obj[i])
				return false;
		}
	return true;
}

bool Vector::operator!=(Vector obj)
{
	return (!(*this==obj));
}

Vector Vector::operator~()//������� ���������� ��������
{
	for (int i = 0; i < size(); i++)
	{
		for (int j = i + 1; j < size(); j++) 
		{
			if (els[i] == els[j])
			{
				remove_by_index(j);
				j--;
			}
		}
	} 
	return (*this);
}

Vector Vector::operator++()
{
	for (int i = 0; i < size(); i++) {
		els[i]++;
	}
	return (*this);
}

Vector Vector::operator++(int obj)
{
	{
		for (int i = 0; i < size(); i++) {
			els[i]++;
		}
		return (*this);
	}

}

int Vector::at(int index)
{
	return els[index];
}

void Vector::add(int el)
{
	if (cur_size == 0 && buf_size == 0) {
		buf_size = 4;
		els = new int[buf_size];
	}

	if (cur_size >= buf_size) {
		buf_size *= 2;
		int *tmp = new int[buf_size];
		for (int i = 0; i < cur_size; i++)
			tmp[i] = els[i];

		delete[]els;
		els = tmp;
	}
	els[cur_size++] = el;
}


void Vector::remove_by_index(int index)
{
	for (int i = index; i < cur_size - 1; i++) {
		swap(els[i], els[i + 1]);

	}

	cur_size--;
		
		
}

int Vector::size()
{
	return cur_size;
}

Vector::~Vector()
{
	delete[]els;
}
