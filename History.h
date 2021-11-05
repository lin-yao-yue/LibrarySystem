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
	int userid;                       //�û�id
	char username[USERNAMESIZE];                    //�û���
	long long int bookid;	          //�ѽ��鱾���:ISBN�Ż�����id��,��10λ��13λ����
	char bookname[BOOKNAMESIZE];       //�鱾����
	int borrowtime;                   //����ʱ��
	int returntime;                   //����ʱ�䣬δ������Ϊ-1

public:
	History();//�޲ι��캯��
	~History();//��������
	History(int userid, char username[USERNAMESIZE], long long int bookid, char bookname[BOOKNAMESIZE], int borrowtime, int returntime);//���صĹ��캯��

	//���ظ�����Ϣ
	int getUserId();
	char* getUserName();
	char* getBookName();
	long long int getBookId();
	int getBorrowTime();
	int getReturnTime();

	//�����ļ�history.bat�ļ�¼����������ļ���ʧ�ܣ�����-1
	static int lengthHistory();

	//�ж�history.bat�ļ��Ƿ���Դ�,�ܴ򿪷���true,���ܴ򿪷���false
	static bool canOpenHistory();

	//��ʾ��ǰ�������ʷ�����¼����������鼮δ�黹������ʱ����ʾδ�黹
	void displayHistory();

	//������ʷ�����¼������ǰ������Ϣ����history.bat,n=-1ʱ����󣬷��򸲸ǵ�n+1����¼���룬n=0ʱ����д���1��
	void writeHistory(int n);


	//���ĵ�ǰ������û������¼
	void changeHistory(int userid, char name[USERNAMESIZE], long long int bookid, int borrowtime, int returntime);

	//�����ļ�history.bat��ָ���û�������Ϣ�����ļ��е�n+1����¼�������γɵ�ǰ����
	void readHistory(int n);
};
