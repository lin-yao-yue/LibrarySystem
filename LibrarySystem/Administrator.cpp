#include"main.h"
void change_password()//修改密码
{
	string p1, p2, p3;
	//system函数直接在控制台调用一个command命令  CLS 清除屏幕
	system("cls");
	cout << endl << "                 修改管理员密码." << endl << endl;
	cout << "请输入原密码:";
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
	{
		cout << "请输入新的密码:";

		cin >> p3;

		ofstream outfile("password.txt", ios::out);
		outfile << p3;
		outfile.close();
		cout << "管理员密码已修改.";
	}
	else
		cout << "密码错误！.";
	cout << endl;
	system("pause");
}

//图书的编号、书名或作者进行查找
bool findPerticularBook(Book a[], string tem) {
	Book book;
	for (int i = 0; i < book.length(); i++) {
		a[i].read(i);
	}
	for (int i = 0; i < book.length(); i++) {
		if (tem == a[i].get_Id() || tem == a[i].get_Name() || tem == a[i].get_Author())
		{
			system("cls");
			showbookh();
			a[i].display();
			return 1;
		}
	}
	return 0;
}

//管理图书
void mag_book()
{
	int i;
	string tem;
	string id, name, author, cat, location, addr, time, price;
	char choice;
	bool tempi = 0, tempi2 = 0;

	Book a[999];
	Book c;
	do {
		fflush(stdin);//清空输入缓冲区
		system("cls");

		cout << endl;
		cout << "                  ***************************************" << endl;
		cout << "                  ***              图书管理           ***" << endl;
		cout << "                  ***************************************" << endl;
		cout << "                  ***            请选择功能：         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***            1 查找书籍           ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***            2 添加书籍           ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***            3 修改书籍           ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***            4 删除书籍           ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***************************************" << endl;
		cout << "Please input your choice:";
		cin >> choice;
		cout << endl;
		/***********************************************     查找图书      */
		if (choice == '1')
		{
			cout << "请输入图书的编号、书名或作者进行查找！";
			cin >> tem;
			tempi2 = 1;
			//清除读写缓冲区，需要立即把输出缓冲区的数据进行物理写入时
			//fflush(stdin)刷新标准输入缓冲区，把输入缓冲区里的东西丢弃[非标准]
			fflush(stdin);

			//是否找到特定的书
			tempi = findPerticularBook(a, tem);

			if (!tempi)
				cout << "不能找到此书.";
		}
		/**********************************************        添加图书     **/
		else if (choice == '2')
		{
			cout << "请输入图书的编号";
			cin >> id;
			tempi2 = 1;
			fflush(stdin);

			tempi = findPerticularBook(a, id);

			if (tempi)
				cout << "已存在此编号书籍！";
			else
			{
				cout << "请输入图书的书名:";
				cin >> name;
				cout << "请输入图书的作者:";
				cin >> author;
				cout << "请输入图书的分类号:";
				cin >> cat;
				cout << "请输入图书的位置:";
				cin >> location;
				cout << "请输入图书的出版社:";
				cin >> addr;
				cout << "请输入图书的出版时间:";
				cin >> time;;
				cout << "请输入图书的价格:";
				cin >> price;
				c.change(id, name, author, cat, location, addr, time, price);
				c.write();
				system("cls");
				cout << "                   图书已保存!." << endl << endl;
				showbookh();
				c.display();
			}


		}

		/**********************************************      修改图书         **/
		else if (choice == '3')
		{
			cout << "请输入要修改的图书的编号：";
			cin >> id;
			tempi2 = 1;
			fflush(stdin);
			int l, n;
			l = c.length();

			tempi = findPerticularBook(a, id);

			if (tempi)
			{

				cout << "编号修改为:";
				cin >> id;
				cout << "书名修改为:";
				cin >> name;
				cout << "作者修改为:";
				cin >> author;
				cout << "分类号修改为:";
				cin >> cat;
				cout << "位置修改为:";
				cin >> location;
				cout << "出版社修改为:";
				cin >> addr;
				cout << "出版时间修改为:";
				cin >> time;
				cout << "价格修改为:";
				cin >> price;

				a[n].change(id, name, author, cat, location, addr, time, price);
				ofstream fout("book.txt");
				fout.close();
				for (i = 0; i < l; i++)
					a[i].write();
				system("cls");
				cout << "已修改此书！" << endl << endl;
				a[n].display();
			}
			else
				cout << "编号为 " << id << " 的书未找到！";

		}
		/**********************************************         删除图书         **/
		else if (choice == '4')
		{
			cout << "请输入要删除的图书的编号：";
			cin >> id;
			tempi2 = 1;
			fflush(stdin);
			int n, l = c.length();

			tempi = findPerticularBook(a, id);

			if (tempi)
			{
				ofstream fout("book.txt");
				fout.close();
				for (i = 0; i < l; i++)
					if (i != n)
						a[i].write();
				system("cls");
				cout << "已删除此书！" << endl << endl;
				a[n].display();
			}
			else
				cout << "编号为" << id << " 的书未发现！.";
		}
		/************************************************/
		else
		{
			cout << "输入错误，请重新输入" << endl;
			system("pause");
		}

	} while (!tempi2);
	cout << endl;
	system("pause");


}

//学生查询
//按行查找，并没有全度先读到数组再判断
bool findPerticularStudent(Student a[], int id) {
	Student s;
	for (int i = 0; i < s.length(); i++) {
		a[i].read(i);
	}
	for (int i = 0; i < s.length(); i++) {
		if (id == a[i].get_id())
		{
			system("cls");
			cout << setw(10) << "姓名" << setw(10) << "账号" << setw(10) << "年级" << setw(10) << "性别" << setw(12) << "电话" << setw(10) << "地址" << endl;
			a[i].display();
			return 1;
		}
	}
	return 0;
}

//写入学生信息
void writeInfo(Student& s) {
	int id, year;
	string name, pass, gend, tele, addr;
	do {
		cout << "请输入姓名:";
		getline(cin, name);
	} while (is_same_student_name(name));
	cout << "请输入密码:";
	getline(cin, pass);

	do {
		cout << "输入学生是哪个年级? (1-4)";
		cin >> year;
	} while (year < 1 || year>4);
	fflush(stdin);

	do {
		cout << "请输入性别:" << endl << " 输入 'male' 或 'female'  :";
		getline(cin, gend);
	} while (!(gend == "male" || gend == "female"));

	do {
		cout << "请输入电话号码:";
		getline(cin, tele);
	} while (is_same_student_tele(tele));

	do {
		cout << "请输入地址:";
		getline(cin, addr);
	} while (is_same_student_addr(addr));

}

void mag_student()
{
	int i, id, year;
	char choice;
	bool success = 0, success2 = 0;
	string name, pass, gend, tele, addr;
	Student a[50];
	Student s;
	do {
		system("cls");

		cout << endl;
		cout << "                  ***************************************" << endl;
		cout << "                  ***              学生管理           ***" << endl;
		cout << "                  ***************************************" << endl;
		cout << "                  ***            请选择功能：         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***          1 查询学生信息         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***          2 添加学生信息         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***          3 修改学生信息         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***          4 删除学生信息         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***************************************" << endl;

		cin >> choice;
		cout << "请输入学生ID:";
		cin >> id;
		getchar();
		can_open(s);
		//查询
		if (choice == '1')
		{
			success2 = 1;
			fflush(stdin);

			success = findPerticularStudent(a, id);

			if (!success)
				cout << "不能找到该学生信息.";
		}
		//添加
		else if (choice == '2')
		{
			success2 = 1;
			fflush(stdin);
			success = findPerticularStudent(a, id);
			if (success)
				cout << "已存在改学生账号信息";
			else
			{
				//向s写入学生信息
				writeInfo(s);

				s.change(id, year, name, pass, gend, tele, addr);
				s.add_student();
				s.write();
				system("cls");
				cout << "学生信息已保存." << endl << endl;
				s.display();
			}
		}
		//修改
		else if (choice == '3')          //修改我的信息
		{
			success2 = 1;
			fflush(stdin);
			int l, n;
			l = s.length();
			success = findPerticularStudent(a, id);
			if (success)
			{				
				//向s写入学生信息
				writeInfo(s);

				a[n].change(id, year, name, pass, gend, tele, addr);
				ofstream fout("student.txt");
				fout.close();
				for (i = 0; i < l; i++)
					a[i].write();
				system("cls");
				cout << "学生信息修改完成！" << endl << endl;
				a[n].display();
			}
			else
				cout << "The student " << id << " cannot be found.";
		}
		//删除
		else if (choice == '4')
		{
			success2 = 1;
			fflush(stdin);
			int n, l = s.length();
			success = findPerticularStudent(a, id);
			if (success)
			{
				a[n].sub_student();
				ofstream fout("student.txt");
				fout.close();
				for (i = 0; i < l; i++)
					if (i != n)
						a[i].write();
				system("cls");
				cout << "学生信息已删除." << endl << endl;
				a[n].display();
			}
			else
				cout << "The student " << id << " cannot be found.";
		}
		else
		{
			cout << "输入错误，请重新输入." << endl;
			system("pause");
		}
	} while (!success2);
	cout << endl;
	system("pause");
}



void show_book_list()
{
	Book a[100];
	Book c;
	int i;
	system("cls");
	cout << endl << "*****************************************************图书信息*************************************************" << endl << endl;
	can_open(c);

	showbookh();
	for (i = 0; i < c.length(); i++)
	{
		a[i].read(i);
		a[i].display();
	}
	cout << endl;
	system("pause");
}


void show_student_list()
{
	Student a[100];
	Student s;
	int i;
	system("cls");
	cout << endl << "  ******************学生信息*******************" << endl << endl;
	can_open(s);

	cout << setw(10) << "账户名" << setw(10) << "账号" << setw(10) << "年级" << setw(10) << "性别" << setw(12) << "电话" << setw(10) << "地址" << endl;
	for (i = 0; i < s.length(); i++)
	{
		a[i].read(i);
		a[i].display();
	}
	cout << endl;
	system("pause");
}
