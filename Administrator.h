#pragma once
#include"Student.h"

class Administrator :public Student
{
public:
	void showAllBook();                            //显示所有图书
	void showAllBorrow();                          //显示所有现在的借阅情况
	void showAllHistory();                         //显示所有借阅历史
	void showAllUser();                            //显示所有的用户
	void addBookManagement();                      //新增图书操作
	void changeBookManagement();                   //修改图书操作
	void deleteBookManagement();                   //删除图书操作
	void searchBookManagement();                   //搜索用户操作
	void addUserManagement();                      //新增用户操作
	void changeUserManagement();                   //修改用户操作
	void deleteUserManagement();                   //删除用户操作
	void searchUserManagement();                   //搜索用户操作
	void searchBorrowManagement();                 //搜索用户的现在借阅情况
	void searchWhoBorrowed(long long int bookid);  //显示当前哪些学生借阅了bookid对应图书还未归还
	void searchOverDue(int userid);                //显示userid该学生当前逾期图书信息
	void searchBorrowed(int& cosition, int userid);               //显示userid该学生当前借阅图书情况
	//void sreachBorrowedHistory(int userid);        //显示userid该学生历史借书信息
	void borrowBooks();                  //学生借书过程逻辑函数，userid对应的学生借阅书籍
	void returnBooks();                  //学生还书过程逻辑函数，userid对应的学生归还书籍
	void changePassword(int userid);



};