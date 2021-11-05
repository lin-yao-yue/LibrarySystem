#pragma once
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;
#define USERNAMESIZE 50
#define BORROWMAX 20
#define BOOKNAMESIZE 50
#define AUTHORSIZE 30
#define LOCATIONSIZE 50
#define PRESSSIZE 50
#define PASSWORDSIZE 20
#define TELEPHONESIZE 12
class History
{
private:
	int userid;                       //用户id
	char username[USERNAMESIZE];                    //用户名
	long long int bookid;	          //已借书本编号:ISBN号或自制id号,有10位或13位三种
	char bookname[BOOKNAMESIZE];       //书本名称
	int borrowtime;                   //借书时间
	int returntime;                   //还书时间，未还书则为-1

public:
	History();//无参构造函数
	~History();//析构函数
	History(int userid, char username[USERNAMESIZE], long long int bookid, char bookname[BOOKNAMESIZE], int borrowtime, int returntime);//重载的构造函数

	//返回各个信息
	int getUserId();
	char* getUserName();
	char* getBookName();
	long long int getBookId();
	int getBorrowTime();
	int getReturnTime();

	//返回文件history.bat的记录条数，如果文件打开失败，返回-1
	static int lengthHistory();

	//判断history.bat文件是否可以打开,能打开返回true,不能打开返回false
	static bool canOpenHistory();

	//显示当前对象的历史借书记录，如果所借书籍未归还，则还书时间显示未归还
	void displayHistory();

	//增加历史借书记录，将当前对象信息存入history.bat,n=-1时存最后，否则覆盖第n+1条记录存入，n=0时覆盖写入第1条
	void writeHistory(int n);


	//更改当前对象的用户借书记录
	void changeHistory(int userid, char name[USERNAMESIZE], long long int bookid, int borrowtime, int returntime);

	//读出文件history.bat中指定用户借书信息，将文件中第n+1条记录的数据形成当前对象
	void readHistory(int n);
};
