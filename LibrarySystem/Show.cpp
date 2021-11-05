#include"main.h"
void menu1()
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                  ***************************************" << endl;
	cout << "                  ***          请选择登录类型         ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  *** 1 管理人员系统   2 学生管理系统 ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            0 退出               ***" << endl;
	cout << "                  ***************************************" << endl;

	cout << "Please input your choice:";
}


void menu2()
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << "                  ***************************************" << endl;
	cout << "                  ***           图书管理系统          ***" << endl;
	cout << "                  ***************************************" << endl;
	cout << "                  ***            请选择功能：         ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            1 图书管理           ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            2 学生管理           ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            3 显示图书信息       ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            4 显示学生信息       ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            5 修改管理员密码     ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            6 返回主菜单         ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            0 退出               ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***************************************" << endl;

	cout << "Please input your choice:";
}


void menu3()
{
	system("cls");
	cout << endl << endl << endl;
	cout << "                  ***************************************" << endl;
	cout << "                  ***             学生系统            ***" << endl;
	cout << "                  ***************************************" << endl;
	cout << "                  ***            请选择功能：         ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          1 浏览已借阅书籍       ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          2 显示图书列表         ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          3 查找图书             ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          4 检查我的书和成绩     ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          5 检查并更改我的信息   ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          6 返回主菜单           ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          0 退出                 ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***************************************" << endl;

	cout << "Please input your choice:";
}


void SetScreenGrid(int x, int y)    //设置控制台大小
{
	char sysSetBuf[80];
	sprintf_s(sysSetBuf, "mode con cols=%d lines=%d", x, y);
	system(sysSetBuf);
}

              
void showbookh()
{
	cout << "*" << setw(10) << "编号";
	cout << "   *" << setw(10) << "书名";
	cout << "   *" << setw(10) << "作者";
	cout << "   *" << setw(10) << "分类号";
	cout << "   *" << setw(10) << "位置";
	cout << "   *" << setw(10) << "出版社";
	cout << "   *" << setw(10) << "出版时间";
	cout << "   *" << setw(10) << "价格" << "*";
	cout << endl;//一条纪录
}



void wrong_input()
{
	system("cls");
	cout << endl << endl << endl << endl << endl << endl;
	cout << "                        输入错误! 请重新输入" << endl;
	system("pause");
}
