#include"main.h"

bool is_administrator()//管理员密码判断
{
	string p1, p2;
	getchar();
	cout << "初始密码为123:";
	cout << "请输入密码:";
	cout << endl;
	getline(cin, p1);
	ifstream infile("password.txt");

	if (!infile)
	{
		cout << endl << "Out of service" << endl;
		cout << "Please press enter to exit." << endl;
		system("pause");
		exit(0);
	}
	getline(infile, p2);
	infile.close();
	if (p1 == p2)
		return 1;
	else
		return 0;
}


bool is_same_Book_id(string n)//判断输入的ID编号是否重复
{
	int i;
	bool success = 0;
	Book a[999];
	Book s;
	for (i = 0; i < s.length(); i++)
	{
		a[i].read(i);
		if (a[i].get_Id() == n)
		{
			cout << "存在相同的编号." << endl;
			success = 1;
		}
	}
	return success;
}


bool is_same_book_name(string n)//不用
{
	//	int i;
	//	bool success = 0;
	//	Book a[999];
	//	Book c;
	//	for (i = 0; i < c.length(); i++)
	//	{
	//		a[i].read(i);
	//		if (a[i].get_name() == n)
	//		{
	//			cout << "已经存在此书名." << endl;
	int success;
	success = 1;
	//		}
	//	}
	return success;
}



bool is_same_student_addr(string n)
{
	int i;
	bool success = 0;
	Student a[999];
	Student s;
	for (i = 0; i < s.length(); i++)
	{
		a[i].read(i);
		if (a[i].get_addr() == n)
		{
			cout << "There exist the same address." << endl;
			success = 1;
		}
	}
	return success;
}



bool is_same_student_name(string n)
{
	int i;
	bool success = 0;
	Student a[999];
	Student s;
	for (i = 0; i < s.length(); i++)
	{
		a[i].read(i);
		if (a[i].get_name() == n)
		{
			cout << "There exist the same name." << endl;
			success = 1;
		}
	}
	return success;
}



bool is_same_student_tele(string n)
{
	int i;
	bool success = 0;
	Student a[999];
	Student s;
	for (i = 0; i < s.length(); i++)
	{
		a[i].read(i);
		if (a[i].get_tele() == n)
		{
			cout << "存在相同号码." << endl;
			success = 1;
		}
	}
	return success;
}



bool is_student(int *n)//学生登录密码判断
{
	Student a[100];
	Student s;
	string p1, p2;
	int i;
	bool success = 0;
	getchar();
	/************************/
	cout << "初始账户为111，密码为111 ";
	/*********************/
	cout << endl;
	cout << "请输入你的账户名:";

	getline(cin, p1);
	cout << "请输入你的密码:";

	getline(cin, p2);
	can_open(s);
	for (i = 0; i < s.length(); i++)
	{
		a[i].read(i);
		if (a[i].get_name() == p1 && a[i].get_pass() == p2)
		{
			*n = i;
			success = 1;
		}
	}
	return success;
}



