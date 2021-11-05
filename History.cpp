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
}//无参构造函数
History::~History() {}//析构函数
History::History(int userid, char username[USERNAMESIZE], long long int bookid, char bookname[BOOKNAMESIZE], int borrowtime, int returntime) {
	this->userid = userid;
	strcpy_s(this->username, username);
	strcpy_s(this->bookname, bookname);
	this->bookid = bookid;
	this->borrowtime = borrowtime;
	this->returntime = returntime;
}

//返回各个信息
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

//返回文件history.bat的记录条数，如果文件打开失败，返回-1
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

//判断history.bat文件是否可以打开,能打开返回true,不能打开返回false
bool History::canOpenHistory() {
	ifstream fin(".\\libraryfile\\history.txt");
	if (fin)
		return 1;
	else
		return 0;
	fin.close();
}

//显示当前对象的历史借书记录，如果所借书籍未归还，则还书时间显示未归还
void History::displayHistory() {
	cout << "*Id" << std::left << setw(15) << getUserId();
	cout << "*姓名" << std::left << setw(20) << getUserName();
	cout << "*所借书籍id" << std::left << setw(15) << getBookId();
	cout << "*所借书籍名称" << std::left << setw(20) << getBookName();
	cout << "*借书时间" << std::left << setw(20) << getBorrowTime();
	/*修改*wjq*/
	if (returntime == -1) {
		cout << "*还书时间" << std::left << setw(20) << "未归还";
	}
	else {
		cout << "*还书时间" << std::left << setw(20) << getReturnTime();
	}
	cout << endl;//一条纪录      
}

//增加历史借书记录，将当前对象信息存入history.bat，n=-1时存最后，否则覆盖第n+1条记录存入，n=0时覆盖写入第1条
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

//更改当前对象的用户借书记录
void History::changeHistory(int userid, char name[USERNAMESIZE], long long int bookid, int borrowtime, int returntime) {
	this->userid = userid;
	strcpy_s(this->username, username);
	strcpy_s(this->bookname, bookname);
	this->bookid = bookid;
	this->borrowtime = borrowtime;
	this->returntime = returntime;
}

//读出文件history.bat中指定用户借书信息，将文件中第n+1条记录的数据形成当前对象
void History::readHistory(int n) {
	ifstream fin(".\\libraryfile\\history.txt", std::ios::binary | ios::in | ios::out);
	fin.seekg(n * (sizeof(History)), ios::beg);
	fin.read((char*)this, sizeof(History));
	fin.close();
}

