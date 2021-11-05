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
}//�޲ι��캯��
User::~User() {}//��������
User::User(int id, char password[PASSWORDSIZE], int grade, char name[USERNAMESIZE], int gender, char telephone[TELEPHONESIZE], int role, int state)//���صĹ��캯��
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

//������ĸ�����Ϣ
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

//�����û���user.bat���û�����������ļ���ʧ�ܣ�����-1
int User::lengthUser() {
	FILE* file = fopen(".\\libraryfile\\user.txt", "rb");
	if (file == NULL)
	{
		return -1;
	}
	long fileLen = filelength(fileno(file));//�ļ������ֽ���
	int i = fileLen / (sizeof(User));
	fclose(file);
	return i;
}

//�ж����user.bat�ļ��Ƿ���Դ�,�ܴ򿪷���true,���ܴ򿪷���false
bool User::canOpenUser() {
	ifstream fin(".\\libraryfile\\user.txt");
	if (fin)
		return 1;
	else
		return 0;
	fin.close();
}

//��ʾ��ǰ������û���Ϣ��id,password,grade,name,gender,telephone,role)
void User::displayUser() {

	
	cout << std::left << setw(20) << getId();
	cout << std::left << setw(20) << getPassword();
	cout << std::left << setw(20) << getName();
	cout << std::left << setw(20) << getGrade();
	if (getGender() == 0)
		cout << std::left << setw(20) << "Ů";
	else
		cout << std::left << setw(20) << "��";

	cout << std::left << setw(20) << getTelephone();
	if (getRole() == 0)
		cout << std::left << setw(20) << "��ͨ�û�";
	else
		cout << std::left << setw(20) << "����Ա";

	cout << endl;//һ����¼      
}

//�����û�������ǰ������Ϣ���룬n=-1ʱ�����һ�У�������n�У�n=0ʱ����д���1��
void User::writeUser(int n)
{
	std::ofstream fin;
	if (n == -1) {
		fin.open(".\\libraryfile\\user.txt", ios::app | std::ios::binary);
		fin.write((const char*)this, sizeof(User));
	}
	else {
		fin.open(".\\libraryfile\\user.txt", ios::binary | ios::out | ios::in);
		fin.seekp(n * (sizeof(User)), ios::beg);//�ļ�ָ������Ҫ�����λ��
		fin.write((const char*)this, sizeof(User));
	}
	fin.close();
}

//�޸ĵ�ǰ�����û���Ϣ
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

//����n+1�����û���Ϣ������ֵ����ǰ����
void User::readUser(int n) {
	ifstream fin(".\\libraryfile\\user.txt", std::ios::binary | ios::in | ios::out);
	fin.seekg(n * (sizeof(User)), ios::beg);
	fin.read((char*)this, sizeof(User));
	fin.close();
}