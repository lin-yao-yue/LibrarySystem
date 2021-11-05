#pragma once
#include"Book.h"
#include"Borrow.h"
#include"History.h"


class Administrator;
class Student;
class Base
{
public:
	bool checkISBN(long long int id);
	int canFindBorrow(int userid);
	int canFindBook(long long int bookid, char name[BOOKNAMESIZE], char author[AUTHORSIZE]);
	int canFindUser(int userid, char name[USERNAMESIZE]);
	int canFindHistory(int userid, long long int bookid);
	Book idFindBook(long long int bookid);
	Book* otherFindBook(char name[BOOKNAMESIZE], char author[AUTHORSIZE], int& booknum);
	User idFindUser(int userid);
	User* othoerFindUser(char name[USERNAMESIZE], int& usernum);
	Borrow findBorrow(int userid);
	History findHistory(int userid, char name[USERNAMESIZE]);
	void showBookList();
	void showUserList();
	void showBorrowList();
	void showHistoryList();
	int addBook(long long int bookid, char name[USERNAMESIZE], char author[AUTHORSIZE], char location[LOCATIONSIZE], char press[PRESSSIZE], int publishtime, int addnum);
	int changeBook(long long int bookid, char newname[USERNAMESIZE], char newauthor[AUTHORSIZE], char newloation[LOCATIONSIZE], char newpress[PRESSSIZE], int newpublishtime, int newhold, int newavailable);
	int deleteBook(long long int bookid);
	void addUser(int userid, char password[PASSWORDSIZE], int grade, char name[USERNAMESIZE], int gender, char telephone[TELEPHONESIZE], int role);
	int changeUser(int userid, int newgrade, char newname[USERNAMESIZE], int newgender, char newtelephone[TELEPHONESIZE], int newrole);
	void deleteUser(int userid);
	void changePassword(int userid, char newPassword[PASSWORDSIZE]);
	void addHistory(int userid, char username[USERNAMESIZE], long long int bookid, char bookname[BOOKNAMESIZE], int borrowtime, int returntime);
	void changeHistory(int userid, char username[USERNAMESIZE], long long int bookid, char bookname[BOOKNAMESIZE], int borrowtime, int returntime);
	bool addBorrow(int userid, long long int);
	bool deleteBorrow(int userid, long long int bookid);
	
	bool checkType(string s, int i);//sΪҪ�������У�iΪsӦΪ�����ͣ�i=0 ������������Ƿ��в��Ϸ��ַ���ֻ������ĸ�����֣�i=1Ϊ������ͻ����������Ƿ����ַ�
	long long int str_to_int(char* str);///���ַ������е��ַ�ת��Ϊ���ͱ���������
	bool isCharLength(char* s, int l);
	int calculateTime(int nowtime, int borrowtime);
	bool isLeapYear(int year);

	void writeExcel(char* filename, Book b);

	Book readExcel(char* filename, int n);

	int lengthExcel(char* filename);

};