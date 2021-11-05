#pragma once
#include"User.h"
#include"Base.h"
class Base;
class Student :public User
{
public:
	void showMyInfo();                //显示个人信息
	void changeTelephone();              //修改个人信息
	void changeMyPass();              //修改密码
	void searchBorrowed();              //显示当前借阅记录
	void searchOverDue();               //显示图书逾期情况
	void searchBookManagement();      //搜索图书
	//void showBorrowedHistory();       //显示自己的历史借书情况

};