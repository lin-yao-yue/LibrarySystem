#include"main.h"

bool is_administrator()//����Ա�����ж�
{
	string p1, p2;
	getchar();
	cout << "��ʼ����Ϊ123:";
	cout << "����������:";
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


bool is_same_Book_id(string n)//�ж������ID����Ƿ��ظ�
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
			cout << "������ͬ�ı��." << endl;
			success = 1;
		}
	}
	return success;
}


bool is_same_book_name(string n)//����
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
	//			cout << "�Ѿ����ڴ�����." << endl;
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
			cout << "������ͬ����." << endl;
			success = 1;
		}
	}
	return success;
}



bool is_student(int *n)//ѧ����¼�����ж�
{
	Student a[100];
	Student s;
	string p1, p2;
	int i;
	bool success = 0;
	getchar();
	/************************/
	cout << "��ʼ�˻�Ϊ111������Ϊ111 ";
	/*********************/
	cout << endl;
	cout << "����������˻���:";

	getline(cin, p1);
	cout << "�������������:";

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



