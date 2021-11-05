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
	int id;			       //�˺�
	char password[PASSWORDSIZE];     //����:�������20λ
	int grade;		       //�꼶
	char name[USERNAMESIZE];	       //����
	int gender;	           //�Ա�:1Ϊ�У�0ΪŮ
	char telephone[TELEPHONESIZE];    //�绰
	int role;              //�û���ɫ��0Ϊ��ͨ�û���1Ϊ����Ա�û�
	int state;             //�û�״̬��0Ϊ���ڣ�-1Ϊ��ɾ��


public:
	User();//�޲ι��캯��
	~User();//��������
	User(int id, char password[PASSWORDSIZE], int grade, char name[USERNAMESIZE], int gender, char telephone[TELEPHONESIZE], int role, int state);//���صĹ��캯��

	//������ĸ�����Ϣ
	int getId();
	char* getPassword();
	int getGrade();
	char* getName();
	int getGender();
	char* getTelephone();
	int getRole();
	int getState();

	//�����û���user.bat���û�����������ļ���ʧ�ܣ�����-1
	static int lengthUser();

	//�ж����user.bat�ļ��Ƿ���Դ�,�ܴ򿪷���true,���ܴ򿪷���false
	static bool canOpenUser();

	//��ʾ��ǰ������û���Ϣ��id,password,grade,name,gender,telephone,role)
	void displayUser();

	//�����û�������ǰ������Ϣ���룬n=-1ʱ�����һ�У�������n�У�n=0ʱ����д���1��
	void writeUser(int n);

	//�޸ĵ�ǰ�����û���Ϣ
	void changeUser(int id, char password[PASSWORDSIZE], int grade, char name[USERNAMESIZE], int gender, char telephone[TELEPHONESIZE], int role, int state);

	//����n+1�����û���Ϣ������ֵ����ǰ����
	void readUser(int n);
};