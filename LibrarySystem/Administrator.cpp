#include"main.h"
void change_password()//�޸�����
{
	string p1, p2, p3;
	//system����ֱ���ڿ���̨����һ��command����  CLS �����Ļ
	system("cls");
	cout << endl << "                 �޸Ĺ���Ա����." << endl << endl;
	cout << "������ԭ����:";
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
		cout << "�������µ�����:";

		cin >> p3;

		ofstream outfile("password.txt", ios::out);
		outfile << p3;
		outfile.close();
		cout << "����Ա�������޸�.";
	}
	else
		cout << "�������.";
	cout << endl;
	system("pause");
}

//ͼ��ı�š����������߽��в���
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

//����ͼ��
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
		fflush(stdin);//������뻺����
		system("cls");

		cout << endl;
		cout << "                  ***************************************" << endl;
		cout << "                  ***              ͼ�����           ***" << endl;
		cout << "                  ***************************************" << endl;
		cout << "                  ***            ��ѡ���ܣ�         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***            1 �����鼮           ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***            2 ����鼮           ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***            3 �޸��鼮           ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***            4 ɾ���鼮           ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***************************************" << endl;
		cout << "Please input your choice:";
		cin >> choice;
		cout << endl;
		/***********************************************     ����ͼ��      */
		if (choice == '1')
		{
			cout << "������ͼ��ı�š����������߽��в��ң�";
			cin >> tem;
			tempi2 = 1;
			//�����д����������Ҫ��������������������ݽ�������д��ʱ
			//fflush(stdin)ˢ�±�׼���뻺�����������뻺������Ķ�������[�Ǳ�׼]
			fflush(stdin);

			//�Ƿ��ҵ��ض�����
			tempi = findPerticularBook(a, tem);

			if (!tempi)
				cout << "�����ҵ�����.";
		}
		/**********************************************        ���ͼ��     **/
		else if (choice == '2')
		{
			cout << "������ͼ��ı��";
			cin >> id;
			tempi2 = 1;
			fflush(stdin);

			tempi = findPerticularBook(a, id);

			if (tempi)
				cout << "�Ѵ��ڴ˱���鼮��";
			else
			{
				cout << "������ͼ�������:";
				cin >> name;
				cout << "������ͼ�������:";
				cin >> author;
				cout << "������ͼ��ķ����:";
				cin >> cat;
				cout << "������ͼ���λ��:";
				cin >> location;
				cout << "������ͼ��ĳ�����:";
				cin >> addr;
				cout << "������ͼ��ĳ���ʱ��:";
				cin >> time;;
				cout << "������ͼ��ļ۸�:";
				cin >> price;
				c.change(id, name, author, cat, location, addr, time, price);
				c.write();
				system("cls");
				cout << "                   ͼ���ѱ���!." << endl << endl;
				showbookh();
				c.display();
			}


		}

		/**********************************************      �޸�ͼ��         **/
		else if (choice == '3')
		{
			cout << "������Ҫ�޸ĵ�ͼ��ı�ţ�";
			cin >> id;
			tempi2 = 1;
			fflush(stdin);
			int l, n;
			l = c.length();

			tempi = findPerticularBook(a, id);

			if (tempi)
			{

				cout << "����޸�Ϊ:";
				cin >> id;
				cout << "�����޸�Ϊ:";
				cin >> name;
				cout << "�����޸�Ϊ:";
				cin >> author;
				cout << "������޸�Ϊ:";
				cin >> cat;
				cout << "λ���޸�Ϊ:";
				cin >> location;
				cout << "�������޸�Ϊ:";
				cin >> addr;
				cout << "����ʱ���޸�Ϊ:";
				cin >> time;
				cout << "�۸��޸�Ϊ:";
				cin >> price;

				a[n].change(id, name, author, cat, location, addr, time, price);
				ofstream fout("book.txt");
				fout.close();
				for (i = 0; i < l; i++)
					a[i].write();
				system("cls");
				cout << "���޸Ĵ��飡" << endl << endl;
				a[n].display();
			}
			else
				cout << "���Ϊ " << id << " ����δ�ҵ���";

		}
		/**********************************************         ɾ��ͼ��         **/
		else if (choice == '4')
		{
			cout << "������Ҫɾ����ͼ��ı�ţ�";
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
				cout << "��ɾ�����飡" << endl << endl;
				a[n].display();
			}
			else
				cout << "���Ϊ" << id << " ����δ���֣�.";
		}
		/************************************************/
		else
		{
			cout << "�����������������" << endl;
			system("pause");
		}

	} while (!tempi2);
	cout << endl;
	system("pause");


}

//ѧ����ѯ
//���в��ң���û��ȫ���ȶ����������ж�
bool findPerticularStudent(Student a[], int id) {
	Student s;
	for (int i = 0; i < s.length(); i++) {
		a[i].read(i);
	}
	for (int i = 0; i < s.length(); i++) {
		if (id == a[i].get_id())
		{
			system("cls");
			cout << setw(10) << "����" << setw(10) << "�˺�" << setw(10) << "�꼶" << setw(10) << "�Ա�" << setw(12) << "�绰" << setw(10) << "��ַ" << endl;
			a[i].display();
			return 1;
		}
	}
	return 0;
}

//д��ѧ����Ϣ
void writeInfo(Student& s) {
	int id, year;
	string name, pass, gend, tele, addr;
	do {
		cout << "����������:";
		getline(cin, name);
	} while (is_same_student_name(name));
	cout << "����������:";
	getline(cin, pass);

	do {
		cout << "����ѧ�����ĸ��꼶? (1-4)";
		cin >> year;
	} while (year < 1 || year>4);
	fflush(stdin);

	do {
		cout << "�������Ա�:" << endl << " ���� 'male' �� 'female'  :";
		getline(cin, gend);
	} while (!(gend == "male" || gend == "female"));

	do {
		cout << "������绰����:";
		getline(cin, tele);
	} while (is_same_student_tele(tele));

	do {
		cout << "�������ַ:";
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
		cout << "                  ***              ѧ������           ***" << endl;
		cout << "                  ***************************************" << endl;
		cout << "                  ***            ��ѡ���ܣ�         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***          1 ��ѯѧ����Ϣ         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***          2 ���ѧ����Ϣ         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***          3 �޸�ѧ����Ϣ         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***          4 ɾ��ѧ����Ϣ         ***" << endl;
		cout << "                  ***                                 ***" << endl;
		cout << "                  ***************************************" << endl;

		cin >> choice;
		cout << "������ѧ��ID:";
		cin >> id;
		getchar();
		can_open(s);
		//��ѯ
		if (choice == '1')
		{
			success2 = 1;
			fflush(stdin);

			success = findPerticularStudent(a, id);

			if (!success)
				cout << "�����ҵ���ѧ����Ϣ.";
		}
		//���
		else if (choice == '2')
		{
			success2 = 1;
			fflush(stdin);
			success = findPerticularStudent(a, id);
			if (success)
				cout << "�Ѵ��ڸ�ѧ���˺���Ϣ";
			else
			{
				//��sд��ѧ����Ϣ
				writeInfo(s);

				s.change(id, year, name, pass, gend, tele, addr);
				s.add_student();
				s.write();
				system("cls");
				cout << "ѧ����Ϣ�ѱ���." << endl << endl;
				s.display();
			}
		}
		//�޸�
		else if (choice == '3')          //�޸��ҵ���Ϣ
		{
			success2 = 1;
			fflush(stdin);
			int l, n;
			l = s.length();
			success = findPerticularStudent(a, id);
			if (success)
			{				
				//��sд��ѧ����Ϣ
				writeInfo(s);

				a[n].change(id, year, name, pass, gend, tele, addr);
				ofstream fout("student.txt");
				fout.close();
				for (i = 0; i < l; i++)
					a[i].write();
				system("cls");
				cout << "ѧ����Ϣ�޸���ɣ�" << endl << endl;
				a[n].display();
			}
			else
				cout << "The student " << id << " cannot be found.";
		}
		//ɾ��
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
				cout << "ѧ����Ϣ��ɾ��." << endl << endl;
				a[n].display();
			}
			else
				cout << "The student " << id << " cannot be found.";
		}
		else
		{
			cout << "�����������������." << endl;
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
	cout << endl << "*****************************************************ͼ����Ϣ*************************************************" << endl << endl;
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
	cout << endl << "  ******************ѧ����Ϣ*******************" << endl << endl;
	can_open(s);

	cout << setw(10) << "�˻���" << setw(10) << "�˺�" << setw(10) << "�꼶" << setw(10) << "�Ա�" << setw(12) << "�绰" << setw(10) << "��ַ" << endl;
	for (i = 0; i < s.length(); i++)
	{
		a[i].read(i);
		a[i].display();
	}
	cout << endl;
	system("pause");
}
