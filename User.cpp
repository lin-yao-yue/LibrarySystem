#include"User.h";
#include <iostream>
#include<fstream>
#include<string.h>
#include <cstring>
#include<sstream>
#include < iomanip >
#include <fcntl.h>
#include <io.h>
#pragma warning(disable:4996)
using namespace std;

User::User() {
	id = 0;
	strcpy(password, "empty");
	grade = 0;
	strcpy(name, "empty");
	gender = 0;
	strcpy(telephone, "empty");
	role = 0;
	state = 0;
}//无参构造函数
User::~User() {}//析构函数
User::User(int id, char password[PASSWORDSIZE], int grade, char name[USERNAMESIZE], int gender, char telephone[TELEPHONESIZE], int role, int state)//重载的构造函数
{
	this->id = id;
	strcpy(this->password, password);
	this->grade = grade;
	strcpy(this->name, name);
	this->gender = gender;
	strcpy(this->telephone, telephone);
	this->role = role;
	this->state = state;
}

//返回书的各个信息
int User::getId() {
	return id;
}
char* User::getPassword() {
	return password;
}
int User::getGrade() {
	return grade;
}
char* User::getName() {
	return name;
}
int User::getGender() {
	return gender;
}
char* User::getTelephone() {
	return telephone;
}
int User::getRole() {
	return role;
}
int User::getState() {
	return state;
}

//返回用户库user.bat的用户个数，如果文件打开失败，返回-1
int User::lengthUser() {
	FILE* file = fopen(".\\libraryfile\\user.txt", "rb");
	if (file == NULL)
	{
		return -1;
	}
	long fileLen = filelength(fileno(file));//文件的总字节数
	int i = fileLen / (sizeof(User));
	fclose(file);
	return i;
}

//判断书库user.bat文件是否可以打开,能打开返回true,不能打开返回false
bool User::canOpenUser() {
	ifstream fin(".\\libraryfile\\user.txt");
	if (fin)
		return 1;
	else
		return 0;
	fin.close();
}

//显示当前对象的用户信息（id,password,grade,name,gender,telephone,role)
void User::displayUser() {

	
	cout << std::left << setw(20) << getId();
	cout << std::left << setw(20) << getPassword();
	cout << std::left << setw(20) << getName();
	cout << std::left << setw(20) << getGrade();
	if (getGender() == 0)
		cout << std::left << setw(20) << "女";
	else
		cout << std::left << setw(20) << "男";

	cout << std::left << setw(20) << getTelephone();
	if (getRole() == 0)
		cout << std::left << setw(20) << "普通用户";
	else
		cout << std::left << setw(20) << "管理员";

	cout << endl;//一条纪录      
}

//增加用户，将当前对象信息存入，n=-1时存最后一行，否则存第n行，n=0时覆盖写入第1行
void User::writeUser(int n)
{
	std::ofstream fin;
	if (n == -1) {
		fin.open(".\\libraryfile\\user.txt", ios::app | std::ios::binary);
		fin.write((const char*)this, sizeof(User));
	}
	else {
		fin.open(".\\libraryfile\\user.txt", ios::binary | ios::out | ios::in);
		fin.seekp(n * (sizeof(User)), ios::beg);//文件指针跳到要存入的位置
		fin.write((const char*)this, sizeof(User));
	}
	fin.close();
}

//修改当前对象用户信息
void User::changeUser(int id, char password[PASSWORDSIZE], int grade, char name[USERNAMESIZE], int gender, char telephone[TELEPHONESIZE], int role, int state) {
	this->id = id;
	strcpy(this->password, password);
	this->grade = grade;
	strcpy(this->name, name);
	this->gender = gender;
	strcpy(this->telephone, telephone);
	this->role = role;
	this->state = state;
}

//读第n+1个的用户信息，并赋值给当前对象
void User::readUser(int n) {
	ifstream fin(".\\libraryfile\\user.txt", std::ios::binary | ios::in | ios::out);
	fin.seekg(n * (sizeof(User)), ios::beg);
	fin.read((char*)this, sizeof(User));
	fin.close();
}