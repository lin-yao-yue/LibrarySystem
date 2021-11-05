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
Book::Book(long long int id, char name[50], char author[20], char location[50], char press[20], int publishtime, int holdnum, int availnum)//���صĹ��캯��
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
//�������book.bat�ļ�¼����������ļ���ʧ�ܣ�����-1
int Book::lengthBook()
{
	FILE* file = fopen(".\\libraryfile\\book.txt", "rb");//�Զ����ƶ��ķ�ʽ���ļ�

	if (file == NULL)
	{
		return -1;
	}
	long fileLen = filelength(fileno(file));//�õ��ļ����ֽ���
	int i = fileLen / (sizeof(Book));//����ļ��ļ�¼����
	fclose(file);
	return i;
}
//�ж����book.bat�ļ��Ƿ���Դ�,�ܴ򿪷���true,���ܴ򿪷���false
bool Book::canOpenBook()
{
	ifstream fin(".\\libraryfile\\book.txt");
	if (fin)
		return 1;
	else
		return 0;
	fin.close();
}
//��ʾ��ǰ�����ͼ����Ϣ��id,name,author,cat,location,press,publishtime,holdnum,availnum)
void Book::displayBook() {
	cout << std::left << setw(14) << getId();
	cout  << std::left << setw(20) << getName();
	cout << std::left << setw(20) << getAuthor();
	cout  << std::left << setw(20) << getPress();
	cout  << std::left << setw(20) << getPublishTime();
	cout  << std::left << setw(20) << getLocation();
	cout  << std::left << setw(20) << getHoldNum();
	cout  << std::left << setw(20) << getAvailNum();
	cout << endl;//һ����¼      
}
//�����鼮�����뵱ǰ����n=-1ʱ����󣬷��򸲸ǵ�n+1���鼮д�룬n=0ʱ����д���1�����ļ���ͷ��Ϊ��һ����
void Book::writeBook(int n) {
	std::ofstream fin;
	if (n == -1) {//�����-1�������ļ����д��
		fin.open(".\\libraryfile\\book.txt", ios::app | std::ios::binary);
		fin.write((const char*)this, sizeof(Book));
	}
	else {//�����ƶ��ļ�ָ���ҵ����ǵ�λ��
		fin.open(".\\libraryfile\\book.txt", ios::binary | ios::out | ios::in);
		fin.seekp(n * (sizeof(Book)), ios::beg);
		fin.write((const char*)this, sizeof(Book));
	}
	fin.close();
}

//�޸ĵ�ǰ����
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
//�����ļ���ָ���鼮��Ϣ�����ļ��е�n+1�����ݸ�ֵ����ǰ���� n=0,���õ�һ�����ݣ��ļ���ͷ��Ϊ��һ����
void Book::readBook(int n) {
	ifstream fin(".\\libraryfile\\book.txt", std::ios::binary | ios::in | ios::out);
	fin.seekg(n * (sizeof(Book)), ios::beg); //�ƶ��ļ�ָ��
	fin.read((char*)this, sizeof(Book));//��ȡ�ü�¼����������
	fin.close();
}