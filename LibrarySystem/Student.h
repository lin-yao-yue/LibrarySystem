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
	int id;                          //学生账号
	int year;                        //年级
	string name;
	string password;
	string gender;
	string telephone;
	string address;                  //姓名、性别、电话、地址
	vector<int> book;
	//借书标记
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
	//多少个学生
	int length();

	bool canopen();
	//向文件追加学生信息
	void write();
	//从文件读出学生信息到对象中
	void read(int n);
	//从文件中更新某个学生的借书记录
	void write_book();
	//从文件中得到某个学生的借书记录
	void read_book();
	//根据借书id(a)将借书标记修改为b
	void change_book(int a, int b);
	// vector<int>book 中添加
	void add_book(int a);
	void display_book();
	//向文件中追加新的学生id
	void add_student();
	//删除文件中某个学生所有的借书记录
	void sub_student();
	//根据 id 从 vector<int>book 中判断
	bool is_same_book(int a);
};

#endif
