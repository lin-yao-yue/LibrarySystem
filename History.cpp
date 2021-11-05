#include <iostream>
#include<fstream>
#include<string.h>
#include <cstring>
#include<sstream>
#include < iomanip >
#include <fcntl.h>
#include <io.h>
#include"History.h"
using namespace std;

History::History() {
	userid = 0;
	strcpy_s(username, "empty");
	strcpy_s(bookname, "empty");
	bookid = 0;
	borrowtime = 0;
	returntime = 0;
}//�޲ι��캯��
History::~History() {}//��������
History::History(int userid, char username[USERNAMESIZE], long long int bookid, char bookname[BOOKNAMESIZE], int borrowtime, int returntime) {
	this->userid = userid;
	strcpy_s(this->username, username);
	strcpy_s(this->bookname, bookname);
	this->bookid = bookid;
	this->borrowtime = borrowtime;
	this->returntime = returntime;
}

//���ظ�����Ϣ
int History::getUserId() {
	return userid;
}
char* History::getUserName() {
	return username;
}
char* History::getBookName() {
	return bookname;
}
long long int History::getBookId() {
	return bookid;
}
int History::getBorrowTime() {
	return borrowtime;
}
int History::getReturnTime() {
	return returntime;
}

//�����ļ�history.bat�ļ�¼����������ļ���ʧ�ܣ�����-1
int History::lengthHistory() {
	FILE* file = fopen(".\\libraryfile\\history.txt", "rb");

	if (file == NULL)
	{
		return -1;
	}
	long fileLen = _filelength(_fileno(file));
	int i = fileLen / (sizeof(History));
	fclose(file);
	return i;
}

//�ж�history.bat�ļ��Ƿ���Դ�,�ܴ򿪷���true,���ܴ򿪷���false
bool History::canOpenHistory() {
	ifstream fin(".\\libraryfile\\history.txt");
	if (fin)
		return 1;
	else
		return 0;
	fin.close();
}

//��ʾ��ǰ�������ʷ�����¼����������鼮δ�黹������ʱ����ʾδ�黹
void History::displayHistory() {
	cout << "*Id" << std::left << setw(15) << getUserId();
	cout << "*����" << std::left << setw(20) << getUserName();
	cout << "*�����鼮id" << std::left << setw(15) << getBookId();
	cout << "*�����鼮����" << std::left << setw(20) << getBookName();
	cout << "*����ʱ��" << std::left << setw(20) << getBorrowTime();
	/*�޸�*wjq*/
	if (returntime == -1) {
		cout << "*����ʱ��" << std::left << setw(20) << "δ�黹";
	}
	else {
		cout << "*����ʱ��" << std::left << setw(20) << getReturnTime();
	}
	cout << endl;//һ����¼      
}

//������ʷ�����¼������ǰ������Ϣ����history.bat��n=-1ʱ����󣬷��򸲸ǵ�n+1����¼���룬n=0ʱ����д���1��
void History::writeHistory(int n) {
	std::ofstream fin;
	if (n == -1) {
		fin.open(".\\libraryfile\\history.txt", ios::app | std::ios::binary);
		fin.write((const char*)this, sizeof(History));
	}
	else {
		fin.open(".\\libraryfile\\history.txt", ios::binary | ios::out | ios::in);
		fin.seekp(n * (sizeof(History)), ios::beg);
		fin.write((const char*)this, sizeof(History));
	}
	fin.close();
}

//���ĵ�ǰ������û������¼
void History::changeHistory(int userid, char name[USERNAMESIZE], long long int bookid, int borrowtime, int returntime) {
	this->userid = userid;
	strcpy_s(this->username, username);
	strcpy_s(this->bookname, bookname);
	this->bookid = bookid;
	this->borrowtime = borrowtime;
	this->returntime = returntime;
}

//�����ļ�history.bat��ָ���û�������Ϣ�����ļ��е�n+1����¼�������γɵ�ǰ����
void History::readHistory(int n) {
	ifstream fin(".\\libraryfile\\history.txt", std::ios::binary | ios::in | ios::out);
	fin.seekg(n * (sizeof(History)), ios::beg);
	fin.read((char*)this, sizeof(History));
	fin.close();
}

