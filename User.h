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
#define MAXHISTORYSHOW 20;
class User
{
private:
	int id;			       //账号
	char password[PASSWORDSIZE];     //密码:最多输入20位
	int grade;		       //年级
	char name[USERNAMESIZE];	       //姓名
	int gender;	           //性别:1为男，0为女
	char telephone[TELEPHONESIZE];    //电话
	int role;              //用户角色：0为普通用户，1为管理员用户
	int state;             //用户状态：0为存在，-1为已删除


public:
	User();//无参构造函数
	~User();//析构函数
	User(int id, char password[PASSWORDSIZE], int grade, char name[USERNAMESIZE], int gender, char telephone[TELEPHONESIZE], int role, int state);//重载的构造函数

	//返回书的各个信息
	int getId();
	char* getPassword();
	int getGrade();
	char* getName();
	int getGender();
	char* getTelephone();
	int getRole();
	int getState();

	//返回用户库user.bat的用户个数，如果文件打开失败，返回-1
	static int lengthUser();

	//判断书库user.bat文件是否可以打开,能打开返回true,不能打开返回false
	static bool canOpenUser();

	//显示当前对象的用户信息（id,password,grade,name,gender,telephone,role)
	void displayUser();

	//增加用户，将当前对象信息存入，n=-1时存最后一行，否则存第n行，n=0时覆盖写入第1行
	void writeUser(int n);

	//修改当前对象用户信息
	void changeUser(int id, char password[PASSWORDSIZE], int grade, char name[USERNAMESIZE], int gender, char telephone[TELEPHONESIZE], int role, int state);

	//读第n+1个的用户信息，并赋值给当前对象
	void readUser(int n);
};