#pragma once
#include"User.h"
#include"Base.h"
class Base;
class Student :public User
{
public:
	void showMyInfo();                //��ʾ������Ϣ
	void changeTelephone();              //�޸ĸ�����Ϣ
	void changeMyPass();              //�޸�����
	void searchBorrowed();              //��ʾ��ǰ���ļ�¼
	void searchOverDue();               //��ʾͼ���������
	void searchBookManagement();      //����ͼ��
	//void showBorrowedHistory();       //��ʾ�Լ�����ʷ�������

};