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
	long long int id;        /*�鱾���:10λISBN�ţ�13λISBN�ţ����Ʊ��, ���֡�
									id��һλΪ������ͱ�־λ,0Ϊ10λISBN�ţ�1Ϊ13λISBN�ţ�2Ϊ���Ʊ�š�
									 */
	char name[BOOKNAMESIZE];           //����
	char author[AUTHORSIZE];         //����
	//char cat[30];            //����
	char location[LOCATIONSIZE];     //�鱾����λ��
	char press[PRESSSIZE];          //������
	int publishtime;         //����ʱ�� �磺20211009
	int holdnum;             //�ݲ�����
	int availnum;            //�ɽ�����
public:
	Book();//�޲ι��캯��
	~Book();//��������
	Book(long long int id, char name[50], char author[20], char location[50], char press[20], int publishtime, int holdnum, int availnum);//���صĹ��캯��

	//������ĸ�����Ϣ
	long long int getId();
	char* getName();
	char* getAuthor();
	char* getLocation();
	char* getPress();
	int getPublishTime();
	int getHoldNum();
	int getAvailNum();

	//�������book.bat�ļ�¼����������ļ���ʧ�ܣ�����-1
	static int lengthBook();

	//�ж����book.bat�ļ��Ƿ���Դ�,�ܴ򿪷���true,���ܴ򿪷���false
	static bool canOpenBook();

	//��ʾ��ǰ�����ͼ����Ϣ��id,name,author,cat,location,press,publishtime,holdnum,availnum)
	void displayBook();

	//�����鼮�����뵱ǰ����n=-1ʱ����󣬷��򸲸ǵ�n+1���鼮д�룬n=0ʱ����д���1�����ļ���ͷ��Ϊ��һ����
	void writeBook(int n);

	//�޸ĵ�ǰ����
	void changeBook(long long int id, char name[50], char author[20], char location[50], char press[20], int publishtime, int holdnum, int availnum);

	//�����ļ���ָ���鼮��Ϣ�����ļ��е�n+1�����ݸ�ֵ����ǰ���� n=0,���õ�һ�����ݣ��ļ���ͷ��Ϊ��һ����
	void readBook(int n);
};








