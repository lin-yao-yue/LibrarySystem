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

Borrow::Borrow()//无参构造函数
{
	userid = 0;
	number = 0;
	strcpy_s(name, "empty");
	memset(bookid, 0, sizeof(bookid));
	memset(borrowtime, 0, sizeof(borrowtime));
}
//析构函数
Borrow::~Borrow() {}
Borrow::Borrow(int userid, char name[USERNAMESIZE], int number, int bookid[BORROWMAX], int borrowtime[BORROWMAX])
{
	this->userid = userid;
	this->number = number;
	strcpy_s(this->name, name);
	memcpy(this->bookid, bookid, sizeof(bookid));
	memcpy(this->borrowtime, borrowtime, sizeof(borrowtime));
}//重载的构造函数

//返回书的各个信息
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


//返回文件borrow.bat的记录条数，如果文件打开失败，返回-1
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

//判断borrow.bat文件是否可以打开,能打开返回true,不能打开返回false
bool Borrow::canOpenBorrow() {
	ifstream fin(".\\libraryfile\\borrow.txt");
	if (fin)
		return 1;
	else
		return 0;
	fin.close();
}

//增加用户借书记录，将当前对象信息存入，n=-1时存最后，否则覆盖第n+1个数据存入，n=0时覆盖写入第1条借书记录
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


//更改当前对象的用户借书记录
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

//读出文件borrow.bat中指定用户借书信息，将文件中第n+1个的数据形成当前对象
void Borrow::readBorrow(int n) {
	ifstream fin(".\\libraryfile\\borrow.txt", std::ios::binary | ios::in | ios::out);
	fin.seekg(n * (sizeof(Borrow)), ios::beg);
	fin.read((char*)this, sizeof(Borrow));
	fin.close();
}