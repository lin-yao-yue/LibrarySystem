#include"Administrator.h"
using namespace std;
//��ʾ����ͼ��
void Administrator::showAllBook() {
	Base base;
	cout << "-------------------------------------------------------------" << endl;
	cout << std::left << setw(14) << "*Id" << std::left << setw(20) << "*����"
		<< std::left << setw(20) << "*����" << std::left << setw(20) << "*������"
		<< std::left << setw(20) << "*����ʱ��" << std::left << setw(20) << "*����λ��"
		<< std::left << setw(20) << "*�ݲ�����" << std::left << setw(20) << "*�ɽ�����" << endl;
	base.showBookList();
	cout << "-------------------------------------------------------------" << endl;
}
//��ʾ�������ڵĽ������
void Administrator::showAllBorrow() {
	Base base;
	cout << std::left << setw(20) << "*ѧ��ID" << std::left << setw(20) << "*ѧ����" << std::left << setw(20) << "*�����鼮ID" << std::left << setw(20) << "*�����鼮����" << std::left << setw(20) << "*����ʱ��" << endl;
	base.showBorrowList();
}
//��ʾ����20��������ʷ
void Administrator::showAllHistory() {
	Base base;
	base.showHistoryList();
}
//����ͼ��
void Administrator::addBookManagement() {
	Base base;
	char bookid[100];
	char bookname[100];
	char author[100];
	char location[100];
	char press[100];
	char publishtime[100];
	char addnum[100];
	long long int bookid2;
	char bookname2[BOOKNAMESIZE];
	char author2[AUTHORSIZE];
	char location2[LOCATIONSIZE];
	char press2[PRESSSIZE];
	int publishtime2;
	int addnum2;
	//int choice;
	/*
	cout << "1.ISBN��Ϊ13λ  2.ISBN��Ϊ10λ  3.û��ISBN��(����ISBN��)" << endl << "������ͼ�������ͣ�" << endl;
	cin >> choice;
	switch (choice) {
	case 1:

	}
	*/
	int choice;
	cout << "1.����һ���� 2.��excel����������� �����룺" << endl;

	char choice2[20];
	int checkchoice = 0;
	do {
		cout << "������ѡ�" << endl;
		cin.getline(choice2, 20);
		//�ж�choice�Ϸ��ԣ����Ϸ����������һ��ѭ��
		if (base.checkType(choice2, 1) == false) {
			cout << "����ֻ�ܰ������֣����������룡" << endl;
			checkchoice = 1;
			continue;
		}
		checkchoice = 0;
	} while (checkchoice == 1);
	choice = base.str_to_int(choice2);

	switch (choice) {
	case 1:
	{	
		int flag2 = 0;
		while (flag2 == 0) {
			cout << "������ͼ���ţ�";
			cin.getline(bookid, 100);
			if (base.checkType(bookid, 1) == false) {
				cout << "ͼ��IDֻ�ܰ������֣����������룡" << endl;
				continue;

			}
			if (base.isCharLength(bookid, 13) == false) {
				cout << "ͼ��ID����ʮ��λ�������������룡" << endl;
				continue;
			}
			cout << "������ͼ��������";
			cin.getline(bookname, 100);
			if (base.checkType(bookname, 2) == false) {
				cout << "���������ո����������룡" << endl;
				continue;

			}
			if (base.isCharLength(bookname, BOOKNAMESIZE) == false) {
				cout << "���������涨λ�������������룡" << endl;
				continue;
			}
			cout << "������ͼ�����ߣ�";
			cin.getline(author, 100);
			if (base.checkType(bookname, 2) == false) {
				cout << "���������ո����������룡" << endl;
				continue;

			}
			if (base.isCharLength(bookname, BOOKNAMESIZE) == false) {
				cout << "���������涨λ�������������룡" << endl;
				continue;
			}
			cout << "������ͼ����λ�ã�";
			cin.getline(location, 100);
			if (base.checkType(location, 2) == false) {
				cout << "λ����Ϣ�����ո����������룡" << endl;
				continue;

			}
			if (base.isCharLength(location, LOCATIONSIZE) == false) {
				cout << "λ�ó����涨λ�������������룡" << endl;
				continue;
			}
			cout << "������ͼ������磺";
			cin.getline(press, 100);
			if (base.checkType(press, 2) == false) {
				cout << "��������Ϣ�����ո����������룡" << endl;
				continue;

			}
			if (base.isCharLength(press, PRESSSIZE) == false) {
				cout << "�����糬���涨λ�������������룡" << endl;
				continue;
			}
			cout << "������ͼ�����ʱ�䣺";
			cin.getline(publishtime, 100);
			if (base.checkType(publishtime, 1) == false) {
				cout << "����ʱ���ʽ�������������룡" << endl;
				continue;

			}
			if (base.isCharLength(publishtime, 8) == false) {
				cout << "����ʱ�䳬���涨λ�������������룡" << endl;
				continue;
			}
			cout << "������ͼ�����������";
			cin.getline(addnum, 100);
			if (base.checkType(addnum, 1) == false) {
				cout << "�������ֻ�ܰ������֣����������룡" << endl;
				continue;

			}
			if (base.isCharLength(addnum, 6) == false) {
				cout << "������������涨���������������룡" << endl;
				continue;
			}
			flag2 = 1;
		}
		bookid2 = base.str_to_int(bookid);
		publishtime2 = base.str_to_int(publishtime);
		addnum2 = base.str_to_int(addnum);
		int flag = base.canFindBook(bookid2, nullptr, nullptr);
		base.addBook(bookid2, bookname, author, location, press, publishtime2, addnum2);
		break;
	}
	case 2:
	{	Book book;
		char filename[100];
		int check = 0;
		do {
			cout << "�������ļ�������.\\libraryfile\\book.csv �����մ����룺" << endl;
			cin.getline(filename, 100);
			if (base.checkType(filename, 2) == false) {
			cout << "���벻�ܰ����ո����������룡" << endl;
			check == 1;
			continue;
			}
			if (base.lengthExcel(filename) == -1)
			{
			check == 1;
			continue;
			}
			for (int i = 0; i < base.lengthExcel(filename); i++)//Ϊ��������ͬ�鼮�����
			{
				book = base.readExcel(filename, i);

				book.writeBook(-1);
			}
			cout << "��ӳɹ���" << endl;
		} while (check == 1);
		break;
	}
	default:
		break;
	}
}

//�޸�ͼ��
void Administrator::changeBookManagement() {
	Base base;
	Book oldbook;
	char bookid[100];
	char bookname[100];
	char author[100];
	char location[100];
	char press[100];
	char publishtime[100];
	char addnum[100];
	long long int bookid2;
	char bookname2[BOOKNAMESIZE];
	char author2[AUTHORSIZE];
	char location2[LOCATIONSIZE];
	char press2[PRESSSIZE];
	int publishtime2;
	int addnum2;
	int result = 0;
	//����������ı���жϸ����Ƿ���ڣ������ڽ��Ը�����и������Ϣ�����޸ģ�" << endl;	
	int flag = 0;
	while (flag == 0) {
		cout << "������ͼ���ţ�";
		cin.getline(bookid, 100);
		if (base.checkType(bookid, 1) == false) {
			cout << "ͼ��IDֻ�ܰ������֣����������룡" << endl;
			continue;

		}
		if (base.isCharLength(bookid, 13) == false) {
			cout << "ͼ��ID����ʮ��λ�������������룡" << endl;
			continue;
		}
		flag = 1;
	}
	bookid2 = base.str_to_int(bookid);
	int line = base.canFindBook(bookid2, NULL, NULL);
	if (line == -1)
	{
		cout << "������޴���!" << endl;
	}
	else if (line != -2)//����ҵ�����
	{
		cout << "Ҫ�޸ĵ��鼮��Ϣ���£�" << endl;
		oldbook = base.idFindBook(bookid2);
		cout << "-------------------------------" << endl;
		cout << "�鱾ID��" << oldbook.getId() << endl;
		cout << "�鱾���ƣ�" << oldbook.getName() << endl;
		cout << "�鱾���ߣ�" << oldbook.getAuthor() << endl;
		cout << "�����磺" << oldbook.getPress() << endl;
		cout << "����ʱ�䣺" << oldbook.getPublishTime() << endl;
		cout << "�ݲ�λ�ã�" << oldbook.getLocation() << endl;
		cout << "�ݲ�������" << oldbook.getHoldNum() << endl;
		cout << "�ɽ�������" << oldbook.getAvailNum() << endl;
		cout << "-------------------------------" << endl;  
		cout << endl;
		int choice2;
		char choice[100];
		int flag1 = 0;
		int flag2 = 0;
		do {
			cout << "-------------------------------" << endl;
			cout << "1.�޸��鼮ȫ����Ϣ" << endl;
			cout << "2.�޸��鼮������Ϣ" << endl;
			cout << "0.ȡ��" << endl;
			cout << "-------------------------------" << endl;
			cout << "������ѡ�" << endl;
			do {
				cin.getline(choice, 100);
				if (base.checkType(choice, 1) == false) {
					cout << "����ֻ�ܰ������֣�����������ѡ�" << endl;
					continue;
				}
				else {
					break;
				}
			} while (1);
			choice2 = base.str_to_int(choice);
			flag1 = 0;
			switch (choice2) {
			case 1: {
				do {
					cout << "������ͼ��������";
					cin.getline(bookname, 100);
					if (base.checkType(bookname, 2) == false) {
						cout << "���벻�ܰ����ո����������룡" << endl;
						continue;
					}
					if (base.isCharLength(bookname, BOOKNAMESIZE) == false) {
						cout << "���������涨λ�������������룡" << endl;
						continue;
					}
					cout << "������ͼ�����ߣ�";
					cin.getline(author, 100);
					if (base.checkType(author, 2) == false) {
						cout << "���벻�ܰ����ո����������룡" << endl;
						continue;

					}
					if (base.isCharLength(author, AUTHORSIZE) == false) {
						cout << "��Ϣ�����涨λ�������������룡" << endl;
						continue;
					}
					cout << "������ͼ����λ�ã�";
					cin.getline(location, 100);
					if (base.checkType(location, 2) == false) {
						cout << "���벻�ܰ����ո�����������" << endl;
						continue;

					}
					if (base.isCharLength(location, LOCATIONSIZE) == false) {
						cout << "λ�ó����涨λ�������������룡" << endl;
						continue;
					}
					cout << "������ͼ������磺";
					cin.getline(press, 100);
					if (base.checkType(press, 2) == false) {
						cout << "���벻�ܰ����ո�����������" << endl;
						continue;

					}
					if (base.isCharLength(press, PRESSSIZE) == false) {
						cout << "�����糬���涨λ�������������룡" << endl;
						continue;
					}
					cout << "������ͼ�����ʱ�䣺";
					cin.getline(publishtime, 100);
					if (base.checkType(publishtime, 1) == false) {
						cout << "����ʱ���ʽ�������������룡" << endl;
						continue;

					}
					if (base.isCharLength(publishtime, 8) == false) {
						cout << "����ʱ�䳬���涨λ�������������룡" << endl;
						continue;
					}
					break;
				} while (1);
				publishtime2 = base.str_to_int(publishtime);
				cout << "�޸ĺ���鼮��Ϣ���£�" << endl;
				cout << "-------------------------------" << endl;
				cout << "�鼮ID��" << bookid2 << endl;
				cout << "������" << bookname << endl;
				cout << "���ߣ�" << author << endl;
				cout << "�ݲ�λ�ã�" << location << endl;
				cout << "�����磺" << press << endl;
				cout << "����ʱ�䣺" << publishtime << endl;
				cout << "�ݲ�������" << oldbook.getHoldNum() << endl;
				cout << "-------------------------------" << endl;
				char input[100];
				char input2;
				int inputflag = 0;
				do {
					do {
						cout << "�Ƿ�ȷ��ɾ�����û���ȷ��������Y����������N" << endl;
						cin.getline(input, 100);
						if (base.checkType(input, 0) == false || base.isCharLength(input, 1) == false) {
							cout << "����������������룡" << endl;
							continue;
						}
						break;
					} while (1);
					input2 = input[0];
					inputflag = 0;
					if (input2 == 'Y') {
						result = base.changeBook(bookid2, bookname, author, location, press, publishtime2, oldbook.getHoldNum(), oldbook.getAvailNum());//���ݱ���жϸ����Ƿ���ڣ����������޸ĸ�����и������Ϣ�����޸�
						if (result == 1) {
							cout << "�޸ĳɹ���" << endl;
						}
					}
					else if (input2 == 'N') {
					}
					else {
						cout << "�Ƿ����룬���������룡" << endl;
						inputflag = 1;
					}
				} while (inputflag == 1);
				flag1 = 1;
				break;
			}
			case 2: {
				int choice2;
				char choice3[100];
				do {
					flag2 = 0;
					cout << endl;
					cout << "-------------------------------" << endl;
					cout << "1.����" << endl;
					cout << "2.����" << endl;
					cout << "3.ͼ����λ��" << endl;
					cout << "4.������" << endl;
					cout << "5.����ʱ��" << endl;
					cout << "0.ȡ��" << endl;
					cout << "-------------------------------" << endl;
					cout << "������ѡ�" << endl;
					do {
						cin.getline(choice3, 100);
						if (base.checkType(choice3, 1) == false) {
							cout << "����ֻ�ܰ������֣����������룺" << endl;
							continue;
						}
						break;
					} while (1);
					choice2 = base.str_to_int(choice3);
					switch (choice2) {
					case 1: {
						char name[100];
						do {
							cout << "������ͼ��������" << endl;
							cin.getline(bookname, 100);
							if (base.checkType(bookname, 2) == false) {
								cout << "���벻�ܰ����ո����������룡" << endl;
								continue;
							}
							if (base.isCharLength(bookname, BOOKNAMESIZE) == false) {
								cout << "���������涨λ�������������룡" << endl;
								continue;
							}
							break;
						} while (1);
						int flag = 0;
		
						result = base.changeBook(oldbook.getId(), bookname, oldbook.getAuthor(), oldbook.getLocation(), oldbook.getPress(), oldbook.getPublishTime(), oldbook.getHoldNum(), oldbook.getAvailNum());
						if (result == 1) {
							cout << "�޸ĳɹ���" << endl;
						}
						flag2 = 1;
						break;
					}
					case 2: {
						char author[100];
						do {
							cout << "�������޸ĺ����������" << endl;
							cin.getline(author, 100);
							if (base.checkType(author, 2) == false) {
								cout << "���벻�ܰ����ո����������룡" << endl;
								continue;
							}
							if (base.isCharLength(author, AUTHORSIZE) == false) {
								cout << "��Ϣ�����涨λ�������������룡" << endl;
								continue;
							}
							break;
						} while (1);
						result = base.changeBook(oldbook.getId(), oldbook.getName(), author, oldbook.getLocation(), oldbook.getPress(), oldbook.getPublishTime(), oldbook.getHoldNum(), oldbook.getAvailNum());
						if (result == 1) {
							cout << "�޸ĳɹ���" << endl;
						}
						flag2 = 1;
						break;
					}
					case 3: {
						char location[100];
						do {
							cout << "�������޸ĺ��ͼ����λ�ã�" << endl;
							cin.getline(location, 100);
							if (base.checkType(location, 2) == false) {
								cout << "���벻�ܰ����ո����������룡" << endl;
								continue;
							}
							if (base.isCharLength(location, LOCATIONSIZE) == false) {
								cout << "��Ϣ�����涨λ�������������룡" << endl;
								continue;
							}
							break;
						} while (1);
						result = base.changeBook(oldbook.getId(), oldbook.getName(), oldbook.getAuthor(), location, oldbook.getPress(), oldbook.getPublishTime(), oldbook.getHoldNum(), oldbook.getAvailNum());
						if (result == 1) {
							cout << "�޸ĳɹ���" << endl;
						}
						flag2 = 1;
						break;
					}
					case 4: {
						char press[100];
						do {
							cout << "�������޸ĺ�ĳ����磺" << endl;
							cin.getline(press, 100);
							if (base.checkType(press, 2) == false) {
								cout << "���벻�ܰ����ո����������룡" << endl;
								continue;
							}
							if (base.isCharLength(press, PRESSSIZE) == false) {
								cout << "��Ϣ�����涨λ�������������룡" << endl;
								continue;
							}
							break;
						} while (1);
						result = base.changeBook(oldbook.getId(), oldbook.getName(), oldbook.getAuthor(), oldbook.getLocation(), press, oldbook.getPublishTime(), oldbook.getHoldNum(), oldbook.getAvailNum());
						if (result == 1) {
							cout << "�޸ĳɹ���" << endl;
						}
						flag2 = 1;
						break;
					}
					case 5: {
						int publishtime2;
						char publishtime[100];
						do {
							cout << "�������޸ĺ�ĳ���ʱ�䣺" << endl;
							cin.getline(publishtime, 100);
							if (base.checkType(publishtime, 1) == false) {
								cout << "����ʱ���ʽ�������������룡" << endl;
								continue;
							}
							if (base.isCharLength(publishtime, 8) == false) {
								cout << "����ʱ�䳬���涨λ�������������룡" << endl;
								continue;
							}
							break;
						} while (1);
						publishtime2 = base.str_to_int(publishtime);
						result = base.changeBook(oldbook.getId(), oldbook.getName(), oldbook.getAuthor(), oldbook.getLocation(), oldbook.getPress(), publishtime2, oldbook.getHoldNum(), oldbook.getAvailNum());
						if (result == 1) {
							cout << "�޸ĳɹ���" << endl;
						}
						flag2 = 1;
						break;
					}
					case 0: {
						flag2 = 0;
						break;
					}
					default: {
						cout << "�Ƿ����룬���������룡" << endl;
						flag2 = 1;
						break;
					}
					}
				} while (flag2 == 1);
				flag1 = 1;
				break;
			}
			case 0: {
				flag1 = 0;
				break;
			}
			default: {
				cout << "�Ƿ����룡" << endl;
				flag1 = 1;
			}
			}

		} while (flag1 == 1);
	}
}
//ɾ��ͼ��
void Administrator::deleteBookManagement() {
	Base base;
	Book oldbook;
	long long int bookid2;
	char bookid[100];
	do {
		cout << "������ͼ���ţ�";
		cin.getline(bookid, 100);
		if (base.checkType(bookid, 1) == false) {
			cout << "ͼ��IDֻ�ܰ������֣����������룡" << endl;
			continue;

		}
		if (base.isCharLength(bookid, 13) == false) {
			cout << "ͼ��ID����ʮ��λ�������������룡" << endl;
			continue;
		}
		break;
	} while (1);
	bookid2 = base.str_to_int(bookid);
	int line = base.canFindBook(bookid2, NULL, NULL);
	if (line == -1)
	{
		cout << "������޴���!" << endl;
	}
	else if (line != -2)//����ҵ�����
	{
		cout << "Ҫɾ�����鼮��Ϣ���£�" << endl;
		oldbook = base.idFindBook(bookid2);
		cout << "-------------------------------" << endl;
		cout << "�鱾ID��" << oldbook.getId() << endl;
		cout << "�鱾���ƣ�" << oldbook.getName() << endl;
		cout << "�鱾���ߣ�" << oldbook.getAuthor() << endl;
		cout << "�����磺" << oldbook.getPress() << endl;
		cout << "����ʱ�䣺" << oldbook.getPublishTime() << endl;
		cout << "�ݲ�λ�ã�" << oldbook.getLocation() << endl;
		cout << "�ݲ�������" << oldbook.getHoldNum() << endl;
		cout << "�ɽ�������" << oldbook.getAvailNum() << endl;
		cout << "-------------------------------" << endl;
		cout << endl;

		int flag = 0;
		do {
			char c[100];
			do {
				cout << "�Ƿ�ȷ��ɾ�����飨���� Y���� Nȡ������";
				cin.getline(c, 100);
				if (base.isCharLength(c, 1) == false || base.checkType(c, 0) == false) {
					cout << "�Ƿ����룡���������룡" << endl;
					continue;
				}
				break;
			} while (1);
			char c2 = c[0];
			switch (c2) {
			case 'Y':
				base.deleteBook(bookid2);
				flag = 0;
				break;
			case 'N':
				flag = 0;
				break;
			default:
				flag = 1;
				cout << "�Ƿ����룡���������룡" << endl;
				break;
			}
		} while (flag == 1);

	}
}

//���һ���û�
void Administrator::addUserManagement() {
	Base base;
	int userid;
	int grade;
	char username[100];
	char password[100];
	int gender;
	char telephone[100];
	int role;
	char userid2[100];
	char grade2[100];
	char gender2[100];
	char role2[100];
	do {
		cout << "�������û�ID��" << endl;
		cin.getline(userid2, 100);
		if (base.checkType(userid2, 1) == false) {
			cout << "�û�IDֻ�ܰ������֣����������룡" << endl;
			continue;
		}
		if (base.isCharLength(userid2, 10) == false) {
			cout << "�û�ID����ʮλ�������������룡" << endl;
			continue;
		}
		cout << "�������꼶��" << endl;
		cin.getline(grade2, 100);
		if (base.checkType(grade2, 1) == false) {
			cout << "�꼶ֻ�ܰ������֣����������룡" << endl;
			continue;

		}
		if (base.isCharLength(grade2, 4) == false) {
			cout << "�꼶������λ�������������룡" << endl;
			continue;
		}
		cout << "�������û�����" << endl;
		cin.getline(username, 100);
		if (base.checkType(username, 2) == false) {
			cout << "���벻�ܰ����ո����������룡" << endl;
			continue;
		}
		if (base.isCharLength(username, USERNAMESIZE) == false) {
			cout << "�����涨λ�������������룡" << endl;
			continue;
		}
		cout << "�������û��Ա�(0-Ů  1-�У���" << endl;
		cin.getline(gender2, 100);
		if (base.checkType(gender2, 1) == false) {
			cout << "ֻ�ܰ������֣����������룡" << endl;
			continue;
		}
		if (base.isCharLength(gender2, 1) == false) {
			cout << "����һλ�������������룡" << endl;
			continue;
		}
		gender = base.str_to_int(gender2);
		if (gender != 0 && gender != 1) {
			cout << "�������" << endl;
			continue;
		}
		cout << "�������û��绰��" << endl;
		cin.getline(telephone, 100);
		if (base.checkType(telephone, 1) == false) {
			cout << "����ֻ�ܰ������֣����������룡" << endl;
			continue;
		}
		if (base.isCharLength(telephone, TELEPHONESIZE) == false) {
			cout << "�����涨λ�������������룡" << endl;
			continue;
		}
		cout << "�������û�Ȩ�ޣ�0-��ͨ�û�  1-����Ա����" << endl;
		cin.getline(role2, 100);
		if (base.checkType(role2, 1) == false) {
			cout << "ֻ�ܰ������֣����������룡" << endl;
			continue;

		}
		if (base.isCharLength(role2, 1) == false) {
			cout << "����һλ�������������룡" << endl;
			continue;
		}
		role = base.str_to_int(role2);
		if (role != 0 && role != 1) {
			cout << "����������������룡" << endl;
			continue;
		}
		break;
	} while (1);
	strcpy(password, "00000000");
	//����Ĭ��Ϊ00000000
	userid = base.str_to_int(userid2);
	grade = base.str_to_int(grade2);
	gender = base.str_to_int(gender2);
	role = base.str_to_int(role2);
	base.addUser(userid, password, grade, username, gender, telephone, role);
}


void Administrator::changeUserManagement()
{
	Base base;
	char userid[100];
	char grade[100];
	char gender[100];
	char role[100];
	int userid2;
	int grade2;
	char username[100];
	char password[100];
	int gender2;
	char telephone[100];
	int role2;
	int choice1;
	int choice2;
	User user;
	do {
		cout << "��������Ҫ�޸ĵ��û�ID��";
		cin.getline(userid, 100);
		if (base.checkType(userid, 1) == false) {
			cout << "�û�IDֻ�ܰ������֣����������룡" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "�û�ID����ʮλ�������������룡" << endl;
			continue;
		}
		break;
	} while (1);
	userid2 = base.str_to_int(userid);
	int userline = base.canFindUser(userid2, NULL);
	if (userline == -1) {
		cout << "���û������ڣ�" << endl;
	}
	else {
		user = base.idFindUser(userid2);
		cout << "-----------------------------------" << endl;
		cout << "���û�����ϢΪ��" << endl;
		cout << "�û�ID��" << user.getId() << endl;
		cout << "������" << user.getName() << endl;
		cout << "�꼶��" << user.getGrade() << endl;
		cout << "�绰��" << user.getTelephone() << endl;
		if (user.getGender() == 1) {
			cout << "�Ա���" << endl;
		}
		else if (user.getGender() == 0) {
			cout << "�Ա�Ů" << endl;
		}
		if (user.getRole() == 1) {
			cout << "�û���ɫ������Ա" << endl;
		}
		else if (user.getRole() == 0) {
			cout << "�û���ɫ����ͨ�û�" << endl;
		}
		if (user.getState() == 0) {
			cout << "�û�״̬������" << endl;
		}
		else if (user.getState() == -1) {
			cout << "�û�״̬����ע��" << endl;
		}
		cout << "-----------------------------------" << endl;
		int flag1 = 0;
		do {
			flag1 = 0;
			char choice3[100];
			cout << "-----------------------------------" << endl;
			cout << "1.�޸�ȫ����Ϣ" << endl;
			cout << "2.�޸�ָ����Ϣ" << endl;
			cout << "0.������һ��" << endl;
			cout << "-----------------------------------" << endl;
			do {
				cout << "������ѡ�" << endl;
				cin.getline(choice3, 100);
				if (base.checkType(choice3, 1) == false) {
					cout << "�Ƿ����룬���������룡" << endl;
					cout << "-----------------------------------" << endl;
					cout << "1.�޸�ȫ����Ϣ" << endl;
					cout << "2.�޸�ָ����Ϣ" << endl;
					cout << "0.������һ��" << endl;
					cout << "-----------------------------------" << endl;
					continue;
				}
				break;
			} while (1);
			choice1 = base.str_to_int(choice3);
			user.readUser(userline - 1);
			switch (choice1) {
			case 1: {
				do {
					cout << "�������꼶��" << endl;
					cin.getline(grade, 100);
					if (base.checkType(grade, 1) == false) {
						cout << "�꼶ֻ�ܰ������֣����������룡" << endl;
						continue;

					}
					if (base.isCharLength(grade, 4) == false) {
						cout << "�꼶������λ�������������룡" << endl;
						continue;
					}
					cout << "�������û�����" << endl;
					cin.getline(username, 100);
					if (base.checkType(username, 2) == false) {
						cout << "���벻�ܰ����ո����������룡" << endl;
						continue;
					}
					if (base.isCharLength(username, USERNAMESIZE) == false) {
						cout << "�����涨λ�������������룡" << endl;
						continue;
					}
					cout << "�������û��Ա�(0-Ů  1-�У���" << endl;
					cin.getline(gender, 100);
					if (base.checkType(gender, 1) == false) {
						cout << "ֻ�ܰ������֣����������룡" << endl;
						continue;
					}
					if (base.isCharLength(gender, 1) == false) {
						cout << "����һλ�������������룡" << endl;
						continue;
					}
					gender2 = base.str_to_int(gender);
					if (gender2 != 0 && gender2 != 1) {
						cout << "����������������룡" << endl;
						continue;
					}
					cout << "�������û��绰��" << endl;
					cin.getline(telephone, 100);
					if (base.checkType(telephone, 1) == false) {
						cout << "����ֻ�ܰ������֣����������룡" << endl;
						continue;
					}
					if (base.isCharLength(telephone, TELEPHONESIZE) == false) {
						cout << "�����涨λ�������������룡" << endl;
						continue;
					}
					cout << "�������û�Ȩ�ޣ�0-��ͨ�û�  1-����Ա����" << endl;
					cin.getline(role, 100);
					if (base.checkType(role, 1) == false) {
						cout << "ֻ�ܰ������֣����������룡" << endl;
						continue;

					}
					if (base.isCharLength(role, 1) == false) {
						cout << "����һλ�������������룡" << endl;
						continue;
					}
					role2 = base.str_to_int(role);
					if (role2 != 0 && role2 != 1) {
						cout << "����������������룡" << endl;
						continue;
					}
					break;
				} while (1);
				grade2 = base.str_to_int(grade);
				gender2 = base.str_to_int(gender);
				role2 = base.str_to_int(role);
				base.changeUser(userid2, grade2, username, gender2, telephone, role2); //���ݱ���жϸ��û��Ƿ���ڣ����������޸ĸ��û����и��û���Ϣ�����޸�
				flag1 = 1;
				break;
			}
			case 2: {
				int flag2 = 0;
				char choice4[100];
				do {
					flag2 = 0;
					cout << "-----------------------------------" << endl;
					cout << std::left << setw(15) << "1.����" << std::left << setw(15) << "2.�꼶" << endl;
					cout << std::left << setw(15) << "3.�Ա�" << std::left << setw(15) << "4.�绰" << endl;
					cout << std::left << setw(15) << "5.�û�Ȩ��" << std::left << setw(15) << "0.������һ��" << endl;
					cout << "-----------------------------------" << endl;
					do {
						cout << "������ѡ�" << endl;
						cin.getline(choice4, 100);
						if (base.checkType(choice4, 1) == false) {
							cout << "�Ƿ����룬���������룡" << endl;
							cout << "-----------------------------------" << endl;
							cout << std::left << setw(15) << "1.����" << std::left << setw(15) << "2.�꼶" << endl;
							cout << std::left << setw(15) << "3.�Ա�" << std::left << setw(15) << "4.�绰" << endl;
							cout << std::left << setw(15) << "5.�û�Ȩ��" << std::left << setw(15) << "0.������һ��" << endl;
							cout << "-----------------------------------" << endl;
							continue;
						}
						break;
					} while (1);
					choice2 = base.str_to_int(choice4);
					switch (choice2) {
					case 1: {
						cout << "���������û�����" << endl;
						cin.getline(username, 100);
						if (base.checkType(username, 2) == false) {
							cout << "���벻�ܰ����ո����������룡" << endl;
							continue;
						}
						if (base.isCharLength(username, USERNAMESIZE) == false) {
							cout << "�����涨λ�������������룡" << endl;
							continue;
						}
						base.changeUser(userid2, user.getGrade(), username, user.getGender(), user.getTelephone(), user.getRole());
						flag2 = 1;
						break;
					}
					case 2: {
						cout << "���������꼶��" << endl;
						cin.getline(grade, 100);
						if (base.checkType(grade, 1) == false) {
							cout << "�꼶ֻ�ܰ������֣����������룡" << endl;
							continue;

						}
						if (base.isCharLength(grade, 4) == false) {
							cout << "�꼶������λ�������������룡" << endl;
							continue;
						}
						grade2 = base.str_to_int(grade);
						base.changeUser(userid2, grade2, user.getName(), user.getGender(), user.getTelephone(), user.getRole());
						flag2 = 1;
						break;
					}
					case 3: {
						gender2 = getGender();
						if (gender2 == 1)
						{
							cout << "ԭ�Ա�Ϊ �� ��������Ϊ Ů��" << endl;
							gender2 = 0;
						}
						else
						{
							cout << "ԭ�Ա�Ϊ Ů ��������Ϊ �У�" << endl;
							gender2 = 1;
						}
						base.changeUser(userid2, user.getGrade(), user.getName(), gender2, user.getTelephone(), user.getRole());
						flag2 = 1;
						break;
					}
					case 4: {
						cout << "�������µ绰��" << endl;
						cin.getline(telephone, 100);
						if (base.checkType(telephone, 2) == false) {
							cout << "���벻�ܰ����ո����������룡" << endl;
							continue;
						}
						if (base.isCharLength(telephone, TELEPHONESIZE) == false) {
							cout << "�����涨λ�������������룡" << endl;
							continue;
						}
						base.changeUser(userid2, user.getGrade(), user.getName(), user.getGender(), telephone, user.getRole());
						flag2 = 1;
						break;
					}
					case 5: {
						if (user.getRole() == 0) {
							char input2;
							char input[100];
							int inputflag = 0;
							do {
								do {
									cout << "�Ƿ�ȷ�������û�����Ϊ����Ա��ȷ��������Y����������N" << endl;
									cin.getline(input, 100);
									if (base.checkType(input, 0) == false || base.isCharLength(input, 1) == false) {
										cout << "����������������룡" << endl;
										continue;
									}
									break;
								} while (1);
								input2 = input[0];
								inputflag = 0;
								if (input2 == 'Y') {
									role2 = 1;
									base.changeUser(userid2, user.getGrade(), user.getName(), user.getGender(), user.getTelephone(), role2);
								}
								else if (input2 == 'N') {

								}
								else {
									cout << "�Ƿ����룬���������룡" << endl;
									inputflag = 1;
								}
							} while (inputflag == 1);
						}
						else if (user.getRole() == 1) {
							char input[100];
							char input2;
							int inputflag = 0;
							do {
								do {
									cout << "�Ƿ�ȷ�������û�����Ϊ��ͨ�û���ȷ��������Y����������N" << endl;
									cin.getline(input, 100);
									if (base.checkType(input, 0) == false || base.isCharLength(input, 1) == false) {
										cout << "����������������룡" << endl;
										continue;
									}
									break;
								} while (1);
								input2 = input[0];
								inputflag = 0;
								if (input2 == 'Y') {
									role2 = 0;
									base.changeUser(userid2, user.getGrade(), user.getName(), user.getGender(), user.getTelephone(), role2);
								}
								else if (input2 == 'N') {

								}
								else {
									cout << "�Ƿ����룬���������룡" << endl;
									inputflag = 1;
								}
							} while (inputflag == 1);
						}
						flag2 = 1;
						break;
					}
					case 0: {
						flag2 = 0;
						break;
					}
					default: {
						cout << "�Ƿ����룬���������룡" << endl;
						flag2 = 1;
					}
					}
				} while (flag2 == 1);
				flag1 = 1;
				break;
			}
			case 0: {
				flag1 = 0;
				break;
			}
			default: {
				cout << "�Ƿ����룡���������룡" << endl;
				flag1 = 1;
				break;
			}
			}
		}while (flag1 == 1);
	}
}

//ɾ���û�
void Administrator::deleteUserManagement() {
	Base base;
	int userid2;
	char userid[100];
	do {
		cout << "�������û���ţ�" << endl;
		cin.getline(userid, 100);
		if (base.checkType(userid, 1) == false) {
			cout << "�û�IDֻ�ܰ������֣����������룡" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "�û�ID����ʮλ�������������룡" << endl;
			continue;
		}
		break;
	} while (1);
	userid2 = base.str_to_int(userid);
	if (base.canFindUser(userid2, nullptr) != -1) {
		User user = base.idFindUser(userid2);
		cout << "-----------------------------" << endl;
		cout << "���û�����ϢΪ��" << endl;
		cout << "�û�ID��" << user.getId() << endl;
		cout << "������" << user.getName() << endl;
		cout << "�꼶��" << user.getGrade() << endl;
		cout << "�绰��" << user.getTelephone() << endl;
		if (user.getGender() == 1) {
			cout << "�Ա���" << endl;
		}
		else if (user.getGender() == 0) {
			cout << "�Ա�Ů" << endl;
		}
		if (user.getRole() == 1) {
			cout << "�û���ɫ������Ա" << endl;
		}
		else if (user.getRole() == 0) {
			cout << "�û���ɫ����ͨ�û�" << endl;
		}
		if (user.getState() == 0) {
			cout << "�û�״̬������" << endl;
		}
		else if (user.getState() == -1) {
			cout << "�û�״̬����ע��" << endl;
		}
		cout << "-----------------------------" << endl;
		if (user.getState() != -1) {

			char input[100];
			char input2;
			int inputflag = 0;
			do {
				do {
					cout << "�Ƿ�ȷ��ɾ�����û���ȷ��������Y����������N" << endl;
					cin.getline(input, 100);
					if (base.checkType(input, 0) == false || base.isCharLength(input, 1) == false) {
						cout << "����������������룡" << endl;
						continue;
					}
					break;
				} while (1);
				input2 = input[0];
				inputflag = 0;
				if (input2 == 'Y') {
					base.deleteUser(userid2);
				}
				else if (input2 == 'N') {
				}
				else {
					cout << "�Ƿ����룬���������룡" << endl;
					inputflag = 1;
				}
			} while (inputflag == 1);
		}
		else {
			cout << "���û���ɾ���޷����޸ģ�" << endl;
			cout << endl;
		}

	}
	else {
		cout << "δ�ҵ����û����޷�ɾ����" << endl;
	}
}

//�����û�
void Administrator::searchUserManagement() {
	Base base;
	int userid2;
	char userid[100];
	char username[100];
	int choice2;
	char choice[100];
	int usernum;
	int line;
	User* userptr;
	User user;
	int flag1 = 0;
	do {
		flag1 = 0;
		int flag2 = 0;
		cout << "-----------------------------" << endl;
		cout << "1.�����û�ID����" << endl;
		cout << "2.�����û�������" << endl;
		cout << "0.������һ��" << endl;
		cout << "-----------------------------" << endl;
		do {
			flag2 = 0;
			do {
				cout << "������ѡ�" << endl;
				cin.getline(choice, 100);
				if (base.checkType(choice, 1) == false || base.isCharLength(choice, 1) == false) {
					cout << "����������������룡" << endl;
					continue;
				}
				break;
			} while (1);
			choice2 = base.str_to_int(choice);
			switch (choice2) {
			case 1:
				do {
					cout << "�������û�ID��" << endl;
					cin.getline(userid, 100);
					if (base.checkType(userid, 1) == false) {
						cout << "�û�IDֻ�ܰ������֣����������룡" << endl;
						continue;
					}
					if (base.isCharLength(userid, 10) == false) {
						cout << "�û�ID����ʮλ�������������룡" << endl;
						continue;
					}
					break;
				} while (1);
				userid2 = base.str_to_int(userid);

				line = base.canFindUser(userid2, nullptr);
				if (line != -1) {
					user = base.idFindUser(userid2);
					cout << "---------------------------" << endl;
					cout << "���û�����ϢΪ��" << endl;
					cout << "�û�ID��" << user.getId() << endl;
					cout << "������" << user.getName() << endl;
					cout << "�꼶��" << user.getGrade() << endl;
					cout << "�绰��" << user.getTelephone() << endl;
					if (user.getGender() == 1) {
						cout << "�Ա���" << endl;
					}
					else if (user.getGender() == 0) {
						cout << "�Ա�Ů" << endl;
					}
					if (user.getRole() == 1) {
						cout << "�û���ɫ������Ա" << endl;
					}
					else if (user.getRole() == 0) {
						cout << "�û���ɫ����ͨ�û�" << endl;
					}
					if (user.getState() == 0) {
						cout << "�û�״̬������" << endl;
					}
					else if (user.getState() == -1) {
						cout << "�û�״̬����ע��" << endl;
					}
					cout << "---------------------------" << endl;
				}
				else {
					cout << "���û������ڣ�" << endl;
				}
				flag1 = 1;
				break;
			case 2:
				do {
					cout << "�������û���" << endl;
					cin.getline(username, 100);
					if (base.checkType(username, 2) == false) {
						cout << "���벻�ܰ����ո����������룡" << endl;
						continue;
					}
					if (base.isCharLength(username, USERNAMESIZE) == false) {
						cout << "�����涨λ�������������룡" << endl;
						continue;
					}
					break;
				} while (1);
				line = base.canFindUser(NULL, username);
				if (line != -1) {
					userptr = base.othoerFindUser(username, usernum);
					cout << "һ��" << usernum << "���û�������������" << endl;
					for (int i = 0; i < usernum; i++) {
						cout << "---------------------------" << endl;
						cout << "���������ĵ�" << i + 1 << "���û���" << endl;
						cout << "�û�ID��" << userptr[i].getId() << endl;
						cout << "������" << userptr[i].getName() << endl;
						cout << "�꼶��" << userptr[i].getGrade() << endl;
						cout << "�绰��" << userptr[i].getTelephone() << endl;
						if (userptr[i].getGender() == 1) {
							cout << "�Ա���" << endl;
						}
						else if (userptr[i].getGender() == 0) {
							cout << "�Ա�Ů" << endl;
						}
						if (userptr[i].getRole() == 1) {
							cout << "�û���ɫ������Ա" << endl;
						}
						else if (userptr[i].getRole() == 0) {
							cout << "�û���ɫ����ͨ�û�" << endl;
						}
						if (userptr[i].getState() == 0) {
							cout << "�û�״̬������" << endl;
						}
						else if (userptr[i].getState() == -1) {
							cout << "�û�״̬����ע��" << endl;
						}
						cout << "---------------------------" << endl;
					}
				}
				else {
					cout << "���û������ڣ�" << endl;
				}
				flag1 = 1;
				break;
			case 0:
				flag2 = 0;
				break;
			default:
				cout << "�Ƿ����룡" << endl;
				flag2 = 1;
			}

		} while (flag2 == 1);
	} while (flag1 == 1);
}
/*�д��Ѹģ���wjq*/ //�����û������ڽ������
void Administrator::searchBorrowManagement() {
	Base base;
	int userid2;
	char userid[100];
	Borrow borrow;
	int line;
	do {
		cout << "�������û�ID��";
		cin.getline(userid, 100);
		if (base.checkType(userid, 1) == false) {
			cout << "�û�IDֻ�ܰ������֣����������룡" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "�û�ID����ʮλ�������������룡" << endl;
			continue;
		}
		break;
	} while (1);
	userid2 = base.str_to_int(userid);


	if (base.canFindBorrow(userid2) != -1) {
		borrow = base.findBorrow(userid2);
		cout << borrow.getUserId() << " " << borrow.getName() << endl;
		cout << "���ڽ��ĵ�ͼ������Ϊ" << borrow.getNumber() << "��" << endl;
		/*�ģ�������wjq*/
		long long int bookid[BORROWMAX] = { 0 };
		int borrowtime[BORROWMAX] = { 0 };
		for (int k = 0; k < BORROWMAX; k++)
		{
			bookid[k] = borrow.getBookId()[k];
			borrowtime[k] = borrow.getBorrowTime()[k];
		}//��ȡ����bookid��time��������
		cout << "����ͼ��������£�" << endl;
		Book tempBook;
		for (int j = 0; j < BORROWMAX; j++)
		{
			if (bookid[j] != 0) {//����������Ĳ���0�����н�����ļ�¼�������
				tempBook = base.idFindBook(bookid[j]);
				char* Bookname = tempBook.getName();
				cout << "������" << Bookname;
				cout << "����ʱ�䣺" << borrowtime[j] / 10000 << "��" << borrowtime[j] % 10000 / 100 << "��" << borrowtime[j] % 100 << "��" << endl;
			}
		}

	}
	else {
		cout << "���û���δ���Ĺ�ͼ�飬������Ϣ�����ڣ�" << endl;
	}

}

void Administrator::showAllUser() {
	Base base;
	cout << std::left << setw(20) << "*Id" << std::left << setw(20) << "*����" << std::left << setw(20) << "*����"
		<< std::left << setw(20) << "*�꼶" << std::left << setw(20) << "*�Ա�" << std::left << setw(20) << "*�绰"
		<< std::left << setw(20) << "*��ɫ" << endl;
	base.showUserList();
}
//ѧ����������߼�������userid��Ӧ��ѧ�������鼮
void Administrator::borrowBooks()//ѧ����������߼�������userid��Ӧ��ѧ�������鼮
{
	Base base;
	long long int bookid2;
	int userid2;
	char userid[100];
	int userline;
	char bookid[100];
	do {
		cout << "����������û�ID��";
		cin.getline(userid, 100);
		if (base.checkType(userid, 1) == false) {
			cout << "�û�IDֻ�ܰ������֣����������룡" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "�û�ID����ʮλ�������������룡" << endl;
			continue;
		}
		break;
	} while (1);
	userid2 = base.str_to_int(userid);

	userline = base.canFindUser(userid2, nullptr);
	if (userline == -1) {
		cout << "���û�������" << endl;
	}
	else {
		User user = base.idFindUser(userid2);


		do {
			cout << "������Ҫ���ĵ��鼮id��";
			cin.getline(bookid, 100);
			if (base.checkType(bookid, 1) == false) {
				cout << "ͼ��IDֻ�ܰ������֣����������룡" << endl;
				continue;

			}
			if (base.isCharLength(bookid, 13) == false) {
				cout << "ͼ��ID����ʮ��λ�������������룡" << endl;
				continue;
			}
			break;
		} while (1);
		bookid2 = base.str_to_int(bookid);
		int bookline = base.canFindBook(bookid2, nullptr, nullptr);
		if (bookline != -1) {
			Book book = base.idFindBook(bookid2);
			cout << "------------------------------------------" << endl;
			cout << "��Ҫ���ĵ��鼮��ϢΪ��" << endl;
			cout << "�鱾ID��" << book.getId() << endl;
			cout << "�鱾����" << book.getName() << endl;
			cout << "���ߣ�" << book.getAuthor() << endl;
			cout << "�����磺" << book.getPress() << endl;
			cout << "����ʱ�䣺" << book.getPublishTime() << endl;
			cout << "�ݲص�ַ��" << book.getLocation() << endl;
			cout << "�ݲ�������" << book.getHoldNum() << endl;
			cout << "�ɽ���������" << book.getAvailNum() << endl;
			cout << "---------------------------------------------" << endl;
			if (book.getAvailNum() == 0)
			{
				cout << "����ɽ�������Ϊ0���ݲ��ɽ��ģ�" << endl;
			}
			else {

				char t2;
				char t[100];
				int flag = 0;
				do {
					flag = 0;
					do {
						cout << "�Ƿ�ȷ�Ͻ��Ĵ��飨���� Y���� Nȡ������";
						cin.getline(t, 100);
						if (base.checkType(t, 0) == false || base.isCharLength(t, 1) == false) {
							cout << "����������������룡" << endl;
							continue;
						}
						break;
					} while (1);
					t2 = t[0];
					if (t2 == 'Y')
					{
						struct tm t;  //tm�ṹָ��
						time_t now;   //����time_t���ͱ���
						time(&now);    //��ȡϵͳ���ں�ʱ��
						localtime_s(&t, &now);  //��ȡ�������ں�ʱ��
						int borrowtime = (1900 + t.tm_year) * 10000 + (1 + t.tm_mon) * 100 + (t.tm_mday);//�õ���ǰʱ�䵱����ʱ��
						base.addBorrow(userid2, bookid2);

					}
					else if (t2 == 'N') {

					}
					else {
						cout << "��Ϊ�Ƿ����룬���������룡" << endl;
						flag = 1;
					}
				} while (flag == 1);

			}
		}
		else {
			cout << "�����ڴ��飡" << endl;
		}
	}
}
//����
void Administrator::returnBooks()
{
	Base base;
	int userid2;
	char userid[100];
	int borrowmax = BORROWMAX;
	int userline;
	do {
		cout << "�����뻹���û�ID��";
		cin.getline(userid, 100);
		if (base.checkType(userid, 1) == false) {
			cout << "�û�IDֻ�ܰ������֣����������룡" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "�û�ID����ʮλ�������������룡" << endl;
			continue;
		}
		break;
	} while (1);
	userid2 = base.str_to_int(userid);

	userline = base.canFindUser(userid2, nullptr);
	if (userline == -1) {
		cout << "���û������ڣ�" << endl;
	}
	else {
		User user = base.idFindUser(userid2);
		long long int bookid2;
		char bookid[100];
		do {
			cout << "������Ҫ�黹���鼮id��";
			cin.getline(bookid, 100);
			if (base.checkType(bookid, 1) == false) {
				cout << "ͼ��IDֻ�ܰ������֣����������룡" << endl;
				continue;

			}
			if (base.isCharLength(bookid, 13) == false) {
				cout << "ͼ��ID����ʮ��λ�������������룡" << endl;
				continue;
			}
			break;
		} while (1);
		bookid2 = base.str_to_int(bookid);
		int bookline = base.canFindBook(bookid2, nullptr, nullptr);
		if (bookline == -1) {
			cout << "���鲻����!" << endl;
		}
		else {
			Borrow borrow = base.findBorrow(userid2);
			int flag2 = 0;
			for (int i = 0; i < borrowmax&&flag2 == 0; i++)
			{
				if (borrow.getBookId()[i] == bookid2)
				{
					long long int bid;
					bid = borrow.getBookId()[i];    //���ļ�¼�з��ϻ������������id
					Book tbook = base.idFindBook(bid);            //ͨ��bid�ҵ��ĸ����������Ϣ��Ϊ���������

					cout << "������ļ�¼���£�" << endl;
					cout << "------------------------------------" << endl;
					cout << "�鼮ID��" << bid << endl;
					cout << "�鼮���֣�" << tbook.getName() << endl;
					cout << "�������ڣ�" << borrow.getBorrowTime()[i] << endl;
					cout << "------------------------------------" << endl;
					char t2;
					char t[100];
					int flag1 = 0;
					do {
						flag1 = 0;
						do {
							cout << "�Ƿ�ȷ�Ϲ黹���飨���� Y�黹 Nȡ������";
							cin.getline(t, 100);
							if (base.checkType(t, 0) == false || base.isCharLength(t, 1) == false) {
								cout << "����������������룡" << endl;
								continue;
							}
							break;
						} while (1);
						t2 = t[0];
						if (t2 == 'Y') {
							base.deleteBorrow(userid2, bid);
							flag2 = 1;
						}
						else if (t2 == 'N') {
							flag2 = 1;
						}
						else {
							cout << "�Ƿ����룡���������룡" << endl;
							flag1 = 1;
						}
					} while (flag1 == 1);
				}
				
			}
			if (flag2 == 0) {
				cout << "�û�δ���Ĵ��飡" << endl;
		
			}

		}
	}
}


//��ʾ��ǰ��Щѧ��������bookid��Ӧͼ�黹δ�黹
void Administrator::searchWhoBorrowed(long long int bookid) {
	Borrow temp;
	int flag = 0;
	int borrowmax = BORROWMAX;
	for (int i = 0; i < temp.lengthBorrow(); i++)
	{
		temp.readBorrow(i);//��ȡÿһ��borrow��Ϣ
		for (int j = 0; j < borrowmax; j++)
		{
			if (temp.getBookId()[j] == bookid)//����ҵ���Ӧbookid������˽����˸���
			{
				flag = 1;
				cout << "(" << j + 1 << ")" << "ѧ��" << temp.getName() << "��" << temp.getBorrowTime()[j] / 10000 << "��" << temp.getBorrowTime()[j] % 10000 / 100 << "��" << temp.getBorrowTime()[j] % 100 << "��" << "���Ĵ��飡" << endl;
			}
		}
	}
	if (flag == 0) {
		cout << "������ʱδ�����" << endl;
	}
}

//��ʾ��ѧ������ͼ����Ϣ
void Administrator::searchOverDue(int userid) {
	Base base;
	Borrow borrowInfo = base.findBorrow(userid);//���ҵ���Ӧ�����¼borrow����

	// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
	tm* ltm = NULL;
	time_t now = time(0);
	//1970 ��Ŀǰ��������:now
	localtime_s(ltm, &now);
	// ��� tm �ṹ�ĸ�����ɲ���
	//��: 1900 + ltm->tm_year;
	//��: 1 + ltm->tm_mon ;
	//��: ltm->tm_mday ;
	int todayTime = (1900 + ltm->tm_year) * 10000 + (1 + ltm->tm_mon) * 100 + (ltm->tm_mday);//��ǰʱ��
	Book temp;
	struct tm t1 = { 0 };//����ʱ��
	struct tm t2 = { 0 };//��ǰʱ��
	double seconds;
	t2.tm_year = todayTime / 10000 - 1900;//��ǰʱ����
	t2.tm_mon = todayTime % 10000 / 100;//��ǰʱ����
	t2.tm_mday = todayTime % 100;//��ǰʱ����

	for (int i = 0; i < BORROWMAX; i++)
	{
		if (borrowInfo.getBookId()[i] != 0)//��ÿһ�������������ж�
		{
			temp = base.idFindBook(borrowInfo.getBookId()[i]);

			t1.tm_year = (borrowInfo.getBorrowTime()[i]) / 10000 - 1900;//����ʱ��
			t1.tm_mon = (borrowInfo.getBorrowTime()[i]) % 10000 / 100;//����ʱ��
			t1.tm_mday = (borrowInfo.getBorrowTime()[i]) % 100;//����ʱ��

			seconds = difftime(mktime(&t2), mktime(&t1));//ת���ṹ��Ϊtime_t,����difftime,����ʱ���  
			int borrowedTime = seconds / 86400;//������ʱ��,��Ϊһ����86400��(60*60*24)  

			if (borrowedTime > 14)//�������ʱ�䳬��14�죬����ʾ����ʱ��
			{
				cout << "�������ĵ��鼮" << temp.getName() << "������" << borrowedTime - 14 << "�죡�뼰ʱ�黹��" << endl;
			}
		}
	}
}

void Administrator::searchBorrowed(int& consition, int userid)
{
	Base base;
	Borrow borrowInfo = base.findBorrow(userid);//�ҵ�����borrow��¼

	long long int bookid[BORROWMAX] = { 0 };
	int borrowtime[BORROWMAX] = { 0 };
	for (int k = 0; k < BORROWMAX; k++)
	{
		bookid[k] = borrowInfo.getBookId()[k];
		borrowtime[k] = borrowInfo.getBorrowTime()[k];
	}//��ȡ����bookid��time��������

	cout << "���Ľ���ͼ��������£�" << endl;
	Book tempBook;
	for (int j = 0; j < BORROWMAX; j++)
	{
		if (bookid[j] != 0) {//����������Ĳ���0�����н�����ļ�¼�������
			tempBook = base.idFindBook(bookid[j]);
			char* Bookname = tempBook.getName();
			cout << "������" << Bookname;
			cout << "(" << j + 1 << ")" << "����ʱ�䣺" << borrowtime[j] / 10000 << "��" << borrowtime[j] % 10000 / 100 << "��" << borrowtime[j] % 100 << "��" << endl;
		}
	}
	cout << "�뼰ʱ�黹ͼ�飡лл��ϣ�" << endl;
}


void Administrator::changePassword(int userid) {

	Base base;
	char oldpassword[100];
	do {
		cout << "������ԭ���룺";
		cin.getline(oldpassword, PASSWORDSIZE);
		if (base.checkType(oldpassword, 0) == false) {
			cout << "����ֻ�ܰ������ֺ���ĸ�����������룡" << endl;
			continue;
		}
		if (base.isCharLength(oldpassword, PASSWORDSIZE) == false) {
			cout << "���볬���涨λ�������������룡" << endl;
			continue;
		}
		break;
	} while (1);
	int consition = 0;
	int n = base.canFindUser(getId(), nullptr);
	char* turepassword = getPassword();
	for (int i = 0; i < PASSWORDSIZE; i++) {
		if (strcmp(oldpassword, turepassword)) {
			cout << "�����������" << endl;
			break;
		}
		else {

			char password[100];
			do {
				cout << "�����������룺";
				cin.getline(password, PASSWORDSIZE);
				if (base.checkType(password, 0) == false) {
					cout << "����ֻ�ܰ������ֺ���ĸ�����������룡" << endl;
					continue;
				}
				if (base.isCharLength(password, PASSWORDSIZE) == false) {
					cout << "���볬���涨λ�������������룡" << endl;
					continue;
				}
				break;
			} while (1);
			char password2[100];
			do {
				cout << "���ٴ�ȷ�����룺";
				cin.getline(password2, PASSWORDSIZE);
				if (base.checkType(password2, 0) == false) {
					cout << "����ֻ�ܰ������ֺ���ĸ�����������룡" << endl;
					continue;
				}
				if (base.isCharLength(password2, PASSWORDSIZE) == false) {
					cout << "���볬���涨λ�������������룡" << endl;
					continue;
				}
				break;
			} while (1);
			if (strcmp(password, password2) == 0)
			{
				base.changePassword(getId(), password2);
				cout << "�޸ĳɹ���" << endl;
				break;
			}
			else {
				cout << "�Ƿ����룡����������" << endl;

			}
		}
		cout << endl;
	}
}

