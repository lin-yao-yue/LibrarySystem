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
class Book
{
private:
	long long int id;        /*书本编号:10位ISBN号，13位ISBN号，自制编号, 三种。
									id第一位为标号类型标志位,0为10位ISBN号，1为13位ISBN号，2为自制编号。
									 */
	char name[BOOKNAMESIZE];           //书名
	char author[AUTHORSIZE];         //作者
	//char cat[30];            //分类
	char location[LOCATIONSIZE];     //书本所放位置
	char press[PRESSSIZE];          //出版社
	int publishtime;         //出版时间 如：20211009
	int holdnum;             //馆藏数量
	int availnum;            //可借数量
public:
	Book();//无参构造函数
	~Book();//析构函数
	Book(long long int id, char name[50], char author[20], char location[50], char press[20], int publishtime, int holdnum, int availnum);//重载的构造函数

	//返回书的各个信息
	long long int getId();
	char* getName();
	char* getAuthor();
	char* getLocation();
	char* getPress();
	int getPublishTime();
	int getHoldNum();
	int getAvailNum();

	//返回书库book.bat的记录条数，如果文件打开失败，返回-1
	static int lengthBook();

	//判断书库book.bat文件是否可以打开,能打开返回true,不能打开返回false
	static bool canOpenBook();

	//显示当前对象的图书信息（id,name,author,cat,location,press,publishtime,holdnum,availnum)
	void displayBook();

	//增加书籍，存入当前对象，n=-1时存最后，否则覆盖第n+1个书籍写入，n=0时覆盖写入第1个（文件开头即为第一个）
	void writeBook(int n);

	//修改当前对象
	void changeBook(long long int id, char name[50], char author[20], char location[50], char press[20], int publishtime, int holdnum, int availnum);

	//读出文件中指定书籍信息，将文件中第n+1条数据赋值给当前对象 n=0,则拿第一条数据（文件开头即为第一条）
	void readBook(int n);
};








