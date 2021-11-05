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
	int userid;                       //�û�id
	char name[USERNAMESIZE];                    //�û���
	int number;                       //�ѽ��鼮������
	long long int bookid[BORROWMAX];	      //�ѽ��鱾���:ISBN�Ż�����id��,��10λ��13λ����
	int borrowtime[BORROWMAX];	      //�����ʱ��:�����ʽ��20201002


public:
	Borrow();//�޲ι��캯��
	~Borrow();//��������
	Borrow(int userid, char name[USERNAMESIZE], int number, int bookid[BORROWMAX], int borrowtime[BORROWMAX]);//���صĹ��캯��

	//������ĸ�����Ϣ
	int getUserId();
	char* getName();
	int getNumber();
	long long int* getBookId();
	int* getBorrowTime();


	//�����ļ�borrow.bat�ļ�¼����������ļ���ʧ�ܣ�����-1
	static int lengthBorrow();

	//�ж�borrow.bat�ļ��Ƿ���Դ�,�ܴ򿪷���true,���ܴ򿪷���false
	static bool canOpenBorrow();

	//�����û������¼������ǰ������Ϣ���룬n=-1ʱ����󣬷��򸲸ǵ�n+1�����ݴ��룬n=0ʱ����д���1�������¼
	void writeBorrow(int n);


	//���ĵ�ǰ������û������¼
	void changeBorrow(int userid, char name[USERNAMESIZE], int number, long long int bookid[BORROWMAX], int borrowtime[BORROWMAX]);

	//�����ļ�borrow.bat��ָ���û�������Ϣ�����ļ��е�n+1���������γɵ�ǰ����
	void readBorrow(int n);
};

