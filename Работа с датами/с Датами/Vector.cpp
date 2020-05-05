#include "Vector.h"

Vector::Vector()
{
	cur_size = 0;
	buf_size = 0;
	ds = 0;
}

Vector::Vector(const Vector & obj)
{
	this->cur_size = obj.cur_size;
	this->buf_size = obj.buf_size;
	this->ds = new Date[buf_size];
	for (int i = 0; i < cur_size; i++)
		ds[i] = obj.ds[i];
}

void Vector::add(Date d)
{
	if (cur_size == 0 && buf_size == 0)
	{
		buf_size = 4;
		ds = new Date [buf_size];
	}

	if (cur_size >= buf_size) {
		buf_size *= 2;
		Date *tmp = new Date[buf_size];
		for (int i = 0; i < cur_size; i++)
		{
			tmp[i] = ds[i];
		}

		delete[]ds;
		ds = tmp;
	}
	ds[cur_size++] = d;
}

void Vector::remove(Date d) //для удаления
{
	int index = search(d);
	if (index != -1)
	{
		for (int i = index; i < cur_size-1; i++)
		{
			swap(ds[i], ds[i + 1]);
	
		}
		cur_size--;
	}

}

Date Vector::at(int index) //возвращает индекс
{
	return ds[index];
}

int Vector::search(Date d)
{
	for (int i = 0; i < cur_size; i++)
	{
		if (ds[i].isEqual(d))
			return i;
	}
	return -1;
}

int Vector::size()
{
	return cur_size;
}

Vector::~Vector()
{
	delete[]ds;
}


