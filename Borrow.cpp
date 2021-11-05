#include <iostream>
#include<fstream>
#include<string.h>
#include <cstring>
#include<sstream>
#include < iomanip >
#include <fcntl.h>
#include <io.h>
#include"Borrow.h"
using namespace std;

Borrow::Borrow()//�޲ι��캯��
{
	userid = 0;
	number = 0;
	strcpy_s(name, "empty");
	memset(bookid, 0, sizeof(bookid));
	memset(borrowtime, 0, sizeof(borrowtime));
}
//��������
Borrow::~Borrow() {}
Borrow::Borrow(int userid, char name[USERNAMESIZE], int number, int bookid[BORROWMAX], int borrowtime[BORROWMAX])
{
	this->userid = userid;
	this->number = number;
	strcpy_s(this->name, name);
	memcpy(this->bookid, bookid, sizeof(bookid));
	memcpy(this->borrowtime, borrowtime, sizeof(borrowtime));
}//���صĹ��캯��

//������ĸ�����Ϣ
int Borrow::getUserId() {
	return userid;
}
char* Borrow::getName() {
	return name;
}
int Borrow::getNumber() {
	return number;
}
long long int* Borrow::getBookId() {
	return bookid;
}
int* Borrow::getBorrowTime() {
	return borrowtime;
}


//�����ļ�borrow.bat�ļ�¼����������ļ���ʧ�ܣ�����-1
int Borrow::lengthBorrow() {
	FILE* file = fopen(".\\libraryfile\\borrow.txt", "rb");

	if (file == NULL)
	{
		return -1;
	}
	long fileLen = _filelength(_fileno(file));
	int i = fileLen / (sizeof(Borrow));
	fclose(file);
	return i;
}

//�ж�borrow.bat�ļ��Ƿ���Դ�,�ܴ򿪷���true,���ܴ򿪷���false
bool Borrow::canOpenBorrow() {
	ifstream fin(".\\libraryfile\\borrow.txt");
	if (fin)
		return 1;
	else
		return 0;
	fin.close();
}

//�����û������¼������ǰ������Ϣ���룬n=-1ʱ����󣬷��򸲸ǵ�n+1�����ݴ��룬n=0ʱ����д���1�������¼
void  Borrow::writeBorrow(int n) {
	std::ofstream fin;
	if (n == -1) {
		fin.open(".\\libraryfile\\borrow.txt", ios::app | std::ios::binary);
		fin.write((const char*)this, sizeof(Borrow));
	}
	else {
		fin.open(".\\libraryfile\\borrow.txt", ios::binary | ios::out | ios::in);
		fin.seekp(n * (sizeof(Borrow)), ios::beg);
		fin.write((const char*)this, sizeof(Borrow));
	}
	fin.close();
}


//���ĵ�ǰ������û������¼
void Borrow::changeBorrow(int userid, char name[USERNAMESIZE], int number, long long int bookid[], int borrowtime[]) {
	int borrowmax = BORROWMAX;
	this->userid = userid;
	this->number = number;
	strcpy_s(this->name, name);
	//memcpy(this->bookid, bookid, sizeof(bookid));
	for (int i = 0; i < borrowmax; i++) {
		this->bookid[i] = bookid[i];
	}
	for (int i = 0; i < borrowmax; i++) {
		this->borrowtime[i] = borrowtime[i];
	}
	//memcpy(this->borrowtime, borrowtime, sizeof(borrowtime));
	return;
}

//�����ļ�borrow.bat��ָ���û�������Ϣ�����ļ��е�n+1���������γɵ�ǰ����
void Borrow::readBorrow(int n) {
	ifstream fin(".\\libraryfile\\borrow.txt", std::ios::binary | ios::in | ios::out);
	fin.seekg(n * (sizeof(Borrow)), ios::beg);
	fin.read((char*)this, sizeof(Borrow));
	fin.close();
}