#include"main.h"
int main()
{
	SetScreenGrid(111, 30);
	int user;
	char choice;
	int choice2;
	bool success = 0;
	initialize();

	do {
		menu1();
		cin >> choice;

		switch (choice)
		{
			/********************************************************************/
		case'1':
		{
			if (is_administrator())
			{
				do {
					menu2();
					cin >> choice2;
					getchar();
					switch (choice2)
					{
					case 1:mag_book();        //图书管理
						success = 0; break;
					case 2:mag_student();    //学生管理
						success = 0; break;
					case 3:show_book_list();  //显示图书信息 
						success = 0; break;
					case 4:show_student_list();//显示学生信息
						success = 0; break;

					case 5:change_password();//修改管理员密码
						success = 0; break;

					case 6:                 //返回主菜单 
						success = 1; break;
					case 0:                 //退出 
						success = 1; break;
					default:
						wrong_input(); break;
					}
				} while (!success);
			}
			else
			{
				cout << "密码错误！." << endl;
				system("pause");
			}
		}
		break;
		/********************************************************************/
		case'2':
		{
			if (is_student(&user))
			{
				do {
					menu3();
					cin >> choice2;
					switch (choice2)
					{
					case 1:choose_book(user); //已借阅图书 
						success = 0; break;
					case 2:show_book_list();  //显示图书
						success = 0; break;
					case 3:mag_book2();       //查找图书			
						success = 0; break;
					case 4:my_book(user);     //检查我的书和成绩 
						success = 0; break;
					case 5:check_info(user);  //检查并更改我的信息
						success = 0; break;
					case 6:                   //返回主菜单
						success = 1; break;
					case 0:                   //退出  
						success = 1; break;
						//default:
						//    wrong_input(); break;
					}

				} while (!success);
			}
			else
			{
				cout << endl;
				cout << "你的名字或密码错误." << endl;
				system("pause");
			}
		}
		break;
		case'0':success = 1; break;
		default:wrong_input(); break;
		}

	} while (choice != '0');
	return 0;
}


void can_open(Book a)
{
	if (!a.canopen())
	{
		cout << endl << "The file cannot open.";
		cout << endl << "You have to restart the program to repair the error.";
		cout << endl << "Press enter to exit." << endl;
		system("pause");
		exit(0);
	}
}
void can_open(Student a)
{
	if (!a.canopen())
	{
		cout << endl << "The file cannot open.";
		cout << endl << "You have to restart the program to repair the error.";
		cout << endl << "Press enter to exit." << endl;
		system("pause");
		exit(0);
	}
}
