#include"main.h"

void check_info(int n)   //检查修改信息
{
	int i, l;
	char choice;
	bool success = 0;
	string tele, addr, pass;
	Student a[999];
	Student s;
	system("cls");

	can_open(s);
	l = s.length();
	for (i = 0; i < l; i++)
		a[i].read(i);
	cout << "                                                   欢迎" << a[n].get_name() << "用户" << endl << endl << endl;


	cout << setw(10) << "账户" << setw(10) << "账号 " << setw(10) << " 年级" << setw(10) << "性别" << setw(12) << "电话" << setw(10) << "地址" << endl;
	a[n].display();
	cout << endl;
	cout << "Enter 1: 修改我的信息." << endl;
	cout << "Enter 2: 修改密码." << endl;
	cout << "Enter else: 返回学生菜单:";
	cin >> choice;
	getchar();
	if (choice == '1')
	{
		do {
			cout << "请输入新的电话号码:";
			getline(cin, tele);
		} while (is_same_student_tele(tele));
		do {
			cout << "请输入新的地址信息:";
			getline(cin, addr);
		} while (is_same_student_addr(addr));

		a[n].change(a[n].get_id(), a[n].get_year(), a[n].get_name(), a[n].get_pass(), a[n].get_gend(), tele, addr);
		ofstream outfile("student.txt");
		outfile.close();
		for (i = 0; i < l; i++)
			a[i].write();
		cout << "信息已修改:" << endl;
		a[n].display();
		system("pause");
	}
	else if (choice == '2')
	{
		cout << "请输入新的密码";
		getline(cin, pass);
		a[n].change(a[n].get_id(), a[n].get_year(), a[n].get_name(), pass, a[n].get_gend(), a[n].get_tele(), a[n].get_addr());
		ofstream outfile("student.txt");
		outfile.close();
		for (i = 0; i < l; i++)
			a[i].write();
		cout << "密码已修改." << endl;
		system("pause");
	}
}


void choose_book(int n)
{
	int i, l, m, id;
	bool success = 0;
	bool can_choose[999];
	Student a[999];
	Student s;
	Book b[999];
	Book c;
	system("cls");
	cout << endl << "                     已借阅图书" << endl << endl;
	can_open(s);
	can_open(c);
	l = c.length();
	for (i = 0; i < s.length(); i++)
	{
		a[i].read(i);
		a[i].read_book();
	}
	showbookh();
	for (i = 0; i < l; i++)
	{

		b[i].display();

	}

	system("pause");
}


void mag_book2()
{
	int i;
	string tem;
	string id, name, author, cat, location, addr, time, price;
	char choice;
	bool tempi = 0, tempi2 = 0;

	Book a[50];
	Book c;
	do {
		fflush(stdin);//清空输入缓冲区
		system("cls");
		/***********************************************     查找图书      */
		cout << "请输入图书的编号、书名或作者进行查找！";
		cin >> tem;
		tempi2 = 1;
		fflush(stdin);
		for (i = 0; i < c.length(); i++)
			a[i].read(i);

		for (i = 0; i < c.length(); i++)
			if (tem == a[i].get_Id() || tem == a[i].get_Name() || tem == a[i].get_Author())
			{
				system("cls");
				showbookh();
				a[i].display();
				tempi = 1;
			}

		if (!tempi)
			cout << "不能找到此书.";

	} while (!tempi2);
	cout << endl;
	system("pause");


}



void my_book(int n)
{
	int i, l;
	Student a[999];
	Student s;
	system("cls");
	cout << endl << "                     检查我的书籍信息和年级" << endl << endl;
	can_open(s);
	l = s.length();
	for (i = 0; i < l; i++)
		a[i].read(i);
	cout << "                                                        Welcome," << a[n].get_name() << endl << endl;
	a[n].read_book();
	cout << "Book ID\tGrade" << endl << endl;
	a[n].display_book();
	system("pause");
}
