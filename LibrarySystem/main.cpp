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
					case 1:mag_book();        //ͼ�����
						success = 0; break;
					case 2:mag_student();    //ѧ������
						success = 0; break;
					case 3:show_book_list();  //��ʾͼ����Ϣ 
						success = 0; break;
					case 4:show_student_list();//��ʾѧ����Ϣ
						success = 0; break;

					case 5:change_password();//�޸Ĺ���Ա����
						success = 0; break;

					case 6:                 //�������˵� 
						success = 1; break;
					case 0:                 //�˳� 
						success = 1; break;
					default:
						wrong_input(); break;
					}
				} while (!success);
			}
			else
			{
				cout << "�������." << endl;
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
					case 1:choose_book(user); //�ѽ���ͼ�� 
						success = 0; break;
					case 2:show_book_list();  //��ʾͼ��
						success = 0; break;
					case 3:mag_book2();       //����ͼ��			
						success = 0; break;
					case 4:my_book(user);     //����ҵ���ͳɼ� 
						success = 0; break;
					case 5:check_info(user);  //��鲢�����ҵ���Ϣ
						success = 0; break;
					case 6:                   //�������˵�
						success = 1; break;
					case 0:                   //�˳�  
						success = 1; break;
						//default:
						//    wrong_input(); break;
					}

				} while (!success);
			}
			else
			{
				cout << endl;
				cout << "������ֻ��������." << endl;
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
