#pragma once
#include"Student.h"

class Administrator :public Student
{
public:
	void showAllBook();                            //��ʾ����ͼ��
	void showAllBorrow();                          //��ʾ�������ڵĽ������
	void showAllHistory();                         //��ʾ���н�����ʷ
	void showAllUser();                            //��ʾ���е��û�
	void addBookManagement();                      //����ͼ�����
	void changeBookManagement();                   //�޸�ͼ�����
	void deleteBookManagement();                   //ɾ��ͼ�����
	void searchBookManagement();                   //�����û�����
	void addUserManagement();                      //�����û�����
	void changeUserManagement();                   //�޸��û�����
	void deleteUserManagement();                   //ɾ���û�����
	void searchUserManagement();                   //�����û�����
	void searchBorrowManagement();                 //�����û������ڽ������
	void searchWhoBorrowed(long long int bookid);  //��ʾ��ǰ��Щѧ��������bookid��Ӧͼ�黹δ�黹
	void searchOverDue(int userid);                //��ʾuserid��ѧ����ǰ����ͼ����Ϣ
	void searchBorrowed(int& cosition, int userid);               //��ʾuserid��ѧ����ǰ����ͼ�����
	//void sreachBorrowedHistory(int userid);        //��ʾuserid��ѧ����ʷ������Ϣ
	void borrowBooks();                  //ѧ����������߼�������userid��Ӧ��ѧ�������鼮
	void returnBooks();                  //ѧ����������߼�������userid��Ӧ��ѧ���黹�鼮
	void changePassword(int userid);



};