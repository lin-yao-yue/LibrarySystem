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
	string Id;//编号
	string Name;//书名
	string Author;//作者
	string Cat;//分类号
	string Location;//位置
	string Addr;//出版社
	string Time;//出版时间
	string Price;//单价
public:
	Book();
	~Book();
	//	   编号    书名        作者    	分类号         位置           出版社	    出版时间        单价
	Book(string a, string b, string c, string d, string e, string f, string g, string h);
	string get_Id();
	string get_Name();
	string get_Author();
	string get_Location();
	string get_Cat();
	string get_Addr();
	string get_Time();
	string get_Price();

	//改变图书信息
	void change(string a, string b, string c, string d, string e, string f, string g, string h);
	//显示图书信息
	void display();
	//文件中有几行记录 即 有几本书
	int length();
	//能否打开
	bool canopen();                  //判断
	//向文件追加存储书籍信息
	void write();                    //增添
	//根据book.txt中的行号n进行读取，而不是id
	void read(int n);                //读取

};

#endif

