// Student.h ================================================

#ifndef STUDENT_H
#define STUDENT_H

#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class Student
{
private:
	int id;                          //ѧ���˺�
	int year;                        //�꼶
	string name;
	string password;
	string gender;
	string telephone;
	string address;                  //�������Ա𡢵绰����ַ
	vector<int> book;
	//������
	vector<int> grade;               //student's books and their marks
public:
	Student();
	~Student();
	Student(int a, int b, string c, string d, string e, string f, string g);

	int get_id();
	int get_year();
	string get_name();
	string get_pass();
	string get_gend();
	string get_tele();
	string get_addr();
	vector<int> get_book();
	void change(int a, int b, string c, string d, string e, string f, string g);

	void display();
	//���ٸ�ѧ��
	int length();

	bool canopen();
	//���ļ�׷��ѧ����Ϣ
	void write();
	//���ļ�����ѧ����Ϣ��������
	void read(int n);
	//���ļ��и���ĳ��ѧ���Ľ����¼
	void write_book();
	//���ļ��еõ�ĳ��ѧ���Ľ����¼
	void read_book();
	//���ݽ���id(a)���������޸�Ϊb
	void change_book(int a, int b);
	// vector<int>book �����
	void add_book(int a);
	void display_book();
	//���ļ���׷���µ�ѧ��id
	void add_student();
	//ɾ���ļ���ĳ��ѧ�����еĽ����¼
	void sub_student();
	//���� id �� vector<int>book ���ж�
	bool is_same_book(int a);
};

#endif
