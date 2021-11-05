#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#define USERNAMESIZE 50
#define BORROWMAX 20
#define BOOKNAMESIZE 50
#define AUTHORSIZE 30
#define LOCATIONSIZE 50
#define PRESSSIZE 50
#define PASSWORDSIZE 20
#define TELEPHONESIZE 12
class Borrow
{
private:
	int userid;                       //用户id
	char name[USERNAMESIZE];                    //用户名
	int number;                       //已借书籍的数量
	long long int bookid[BORROWMAX];	      //已借书本编号:ISBN号或自制id号,有10位或13位三种
	int borrowtime[BORROWMAX];	      //借书的时间:存入格式：20201002


public:
	Borrow();//无参构造函数
	~Borrow();//析构函数
	Borrow(int userid, char name[USERNAMESIZE], int number, int bookid[BORROWMAX], int borrowtime[BORROWMAX]);//重载的构造函数

	//返回书的各个信息
	int getUserId();
	char* getName();
	int getNumber();
	long long int* getBookId();
	int* getBorrowTime();


	//返回文件borrow.bat的记录条数，如果文件打开失败，返回-1
	static int lengthBorrow();

	//判断borrow.bat文件是否可以打开,能打开返回true,不能打开返回false
	static bool canOpenBorrow();

	//增加用户借书记录，将当前对象信息存入，n=-1时存最后，否则覆盖第n+1个数据存入，n=0时覆盖写入第1条借书记录
	void writeBorrow(int n);


	//更改当前对象的用户借书记录
	void changeBorrow(int userid, char name[USERNAMESIZE], int number, long long int bookid[BORROWMAX], int borrowtime[BORROWMAX]);

	//读出文件borrow.bat中指定用户借书信息，将文件中第n+1个的数据形成当前对象
	void readBorrow(int n);
};

