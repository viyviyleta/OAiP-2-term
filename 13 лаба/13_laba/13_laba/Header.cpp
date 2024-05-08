#include "Header.h"
#include <iostream>
int HashFunction(int key, int size, int p)    // ���-�������
{
	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));	// �������� ���-�������
	return (p + key) % size;
}

int Next_hash(int hash, int size, int p) // ��� ����
{
	return (hash + 5 * p + 3 * p * p) % size;
}
//-------------------------------
int universal(int key, int size, int p)	// ������������ ����������� �����������: ��� ���������� ����� ����������� ��������� ��� � ����� ������ ���������
{
	int h = 0, a = 314445, b = 37542;
	h = (a * h + key) % size;
	return (h < 0) ? (h + size) : h;
}
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey)); // ��������� ������
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d) {
	bool b = false;
	if (N != size) {
		int key = getKey(d);
		int index = universal(key, size, 0);
		int i = 0;
		while (i < size && (data[index] != NULL && data[index] != DEL)) {
			index = Next_hash(index, size, ++i);
		}
		if (data[index] == NULL || data[index] == DEL) {
			data[index] = d;
			N++;
			b = true;
		}
	}
	return b;
}
//-------------------------------
int Object::searchInd(int key) // ������� ��� ������ �� �����
{
	int t = -1;
	bool b = false; // ���������� ��� ������
	if (N != 0)
		// ����� ����� �����������, ���� �� ������ ������� � b �� ������ ����� true
		for (int i = 0, j = universal(key, size, 0); data[j] != NULL && i != size && !b; j = universal(key, size, ++i))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}
//-------------------------------
void* Object::search(int key) // ����� ���������� ������
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key) // ������� ��� ��������
{
	int i = searchInd(key); // ���� �������
	void* t = data[i]; // ����������� ��������� �� ���� �������
	if (t != NULL)
	{
		data[i] = DEL; // �������
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*)) {
	for (int i = 0; i < this->size; i++) {
		if (data[i] == NULL)
			std::cout << " ������� " << i + 1 << " - �����!" << std::endl;
		else if (data[i] == DEL)
			std::cout << " ������� " << i + 1 << " - ������" << std::endl;
		else
			f(data[i]);
	}
}

