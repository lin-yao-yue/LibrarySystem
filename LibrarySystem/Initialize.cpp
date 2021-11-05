#include"main.h"

void initialize()       //初始化信息列表
{
	ifstream infile1("book.txt");
	if (!infile1)
	{
		ofstream outfile1("book.txt");
		outfile1.close();
	}
	infile1.close();
	ifstream infile2("student.txt");
	if (!infile2)
	{
		ofstream outfile2("student.txt");
		outfile2.close();
	}
	infile2.close();
	ifstream infile3("password.txt");
	if (!infile3)
	{
		ofstream outfile3("password.txt");
		outfile3 << "123";
		outfile3.close();
	}
	infile3.close();
	ifstream infile4("mybook.txt");
	if (!infile4)
	{
		ofstream outfile4("mybook.txt");
		outfile4.close();
	}
	infile4.close();
}
