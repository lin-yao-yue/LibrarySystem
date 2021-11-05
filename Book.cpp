#include <iostream>
#include<fstream>
#include<string.h>
#include <cstring>
#include<sstream>
#include < iomanip >
#include <fcntl.h>
#include <io.h>
#include"Book.h"
#pragma warning(disable:4996)
using namespace std;


Book::Book()
{
	id = 0;
	strcpy(name, "empty");
	strcpy(author, "empty");
	strcpy(location, "empty");
	strcpy(press, "empty");
	publishtime = 0;
	holdnum = 0;
	availnum = 0;
}
Book::Book(long long int id, char name[50], char author[20], char location[50], char press[20], int publishtime, int holdnum, int availnum)//重载的构造函数
{
	this->id = id;
	strcpy(this->name, name);
	strcpy(this->author, author);
	strcpy(this->location, location);
	strcpy(this->press, press);
	this->publishtime = publishtime;
	this->holdnum = holdnum;
	this->availnum = availnum;
}
Book::~Book() {}
long long int Book::getId()
{
	return id;
}
char* Book::getName()
{
	return name;
}
char* Book::getAuthor()
{
	return author;
}

char* Book::getLocation()
{
	return location;
}
char* Book::getPress()
{
	return press;
}
int Book::getPublishTime()
{
	return publishtime;
}
int Book::getHoldNum()
{
	return holdnum;
}
int Book::getAvailNum()
{
	return availnum;
}
//返回书库book.bat的记录条数，如果文件打开失败，返回-1
int Book::lengthBook()
{
	FILE* file = fopen(".\\libraryfile\\book.txt", "rb");//以二进制读的方式打开文件

	if (file == NULL)
	{
		return -1;
	}
	long fileLen = filelength(fileno(file));//得到文件的字节数
	int i = fileLen / (sizeof(Book));//求出文件的记录条数
	fclose(file);
	return i;
}
//判断书库book.bat文件是否可以打开,能打开返回true,不能打开返回false
bool Book::canOpenBook()
{
	ifstream fin(".\\libraryfile\\book.txt");
	if (fin)
		return 1;
	else
		return 0;
	fin.close();
}
//显示当前对象的图书信息（id,name,author,cat,location,press,publishtime,holdnum,availnum)
void Book::displayBook() {
	cout << std::left << setw(14) << getId();
	cout  << std::left << setw(20) << getName();
	cout << std::left << setw(20) << getAuthor();
	cout  << std::left << setw(20) << getPress();
	cout  << std::left << setw(20) << getPublishTime();
	cout  << std::left << setw(20) << getLocation();
	cout  << std::left << setw(20) << getHoldNum();
	cout  << std::left << setw(20) << getAvailNum();
	cout << endl;//一条纪录      
}
//增加书籍，存入当前对象，n=-1时存最后，否则覆盖第n+1个书籍写入，n=0时覆盖写入第1个（文件开头即为第一个）
void Book::writeBook(int n) {
	std::ofstream fin;
	if (n == -1) {//如果是-1，则在文件最后写入
		fin.open(".\\libraryfile\\book.txt", ios::app | std::ios::binary);
		fin.write((const char*)this, sizeof(Book));
	}
	else {//否则，移动文件指针找到覆盖的位置
		fin.open(".\\libraryfile\\book.txt", ios::binary | ios::out | ios::in);
		fin.seekp(n * (sizeof(Book)), ios::beg);
		fin.write((const char*)this, sizeof(Book));
	}
	fin.close();
}

//修改当前对象
void Book::changeBook(long long int id, char name[50], char author[20], char location[50], char press[20], int publishtime, int holdnum, int availnum) {
	this->id = id;
	strcpy(this->name, name);
	strcpy(this->author, author);
	strcpy(this->location, location);
	strcpy(this->press, press);
	this->publishtime = publishtime;
	this->holdnum = holdnum;
	this->availnum = availnum;
	return;
}
//读出文件中指定书籍信息，将文件中第n+1条数据赋值给当前对象 n=0,则拿第一条数据（文件开头即为第一条）
void Book::readBook(int n) {
	ifstream fin(".\\libraryfile\\book.txt", std::ios::binary | ios::in | ios::out);
	fin.seekg(n * (sizeof(Book)), ios::beg); //移动文件指针
	fin.read((char*)this, sizeof(Book));//读取该记录到本对象中
	fin.close();
}