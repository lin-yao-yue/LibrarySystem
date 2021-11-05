//Book.h ===============================================

#ifndef BOOK_H
#define BOOK_H

#pragma once
#include<iostream>         
#include<fstream>
#include<string>
#include<sstream>
#include <iomanip>
using namespace std;

class Book
{
private:
	string Id;//���
	string Name;//����
	string Author;//����
	string Cat;//�����
	string Location;//λ��
	string Addr;//������
	string Time;//����ʱ��
	string Price;//����
public:
	Book();
	~Book();
	//	   ���    ����        ����    	�����         λ��           ������	    ����ʱ��        ����
	Book(string a, string b, string c, string d, string e, string f, string g, string h);
	string get_Id();
	string get_Name();
	string get_Author();
	string get_Location();
	string get_Cat();
	string get_Addr();
	string get_Time();
	string get_Price();

	//�ı�ͼ����Ϣ
	void change(string a, string b, string c, string d, string e, string f, string g, string h);
	//��ʾͼ����Ϣ
	void display();
	//�ļ����м��м�¼ �� �м�����
	int length();
	//�ܷ��
	bool canopen();                  //�ж�
	//���ļ�׷�Ӵ洢�鼮��Ϣ
	void write();                    //����
	//����book.txt�е��к�n���ж�ȡ��������id
	void read(int n);                //��ȡ

};

#endif

