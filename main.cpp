#include"Book.h"
#include"Borrow.h"
#include"User.h"
#include"History.h"
#include<map>
#include<algorithm>

#include"Administrator.h"
//#include"login.cpp"

using namespace std;
int USERID;
int LINE;

void searchBookManagement() {    //����ͼ��
	Base base;
	long long int bookid;
	char bookname[BOOKNAMESIZE];
	char author[AUTHORSIZE];
	int booknum;
	Book book;
	Book* bookptr;
	int flag1 = 0;
	do {
		flag1 = 0;
		int flag2 = 0;
		int choice;
		char choice2[100];
		cout << "-------------------------------" << endl;
		cout << "1.����ͼ��������" << endl;
		cout << "2.����ͼ����������" << endl;
		cout << "3.����ͼ����������" << endl;
		cout << "0.������һ��" << endl;
		cout << "-------------------------------" << endl;
		do {
			//wjq
			int checkchoice = 0;
			do {
				cout << "������ѡ�" << endl;
				cin.getline(choice2, 20);
				//�ж�ID�Ϸ��ԣ����Ϸ����������һ��ѭ��
				if (base.checkType(choice2, 1) == false) {
					cout << "����ֻ�ܰ������֣����������룡" << endl;
					checkchoice = 1;
					continue;
				}
				checkchoice = 0;
			} while (checkchoice == 1);
			choice = base.str_to_int(choice2);

			flag2 = 0;
			switch (choice) {
			case 1:
			{
				char bookid2[100];
				int checkbookid = 0;
				do {
					cout << "������ͼ��ID:" << endl;
					cin.getline(bookid2, 100);
					//�ж�ͼ��id�Ϸ���
					if (base.checkType(bookid2, 1) == false) {
						cout << "ͼ��IDֻ�ܰ������֣����������룡" << endl;
						checkbookid = 0;
						continue;
					}
					if (base.isCharLength(bookid2, 13) == false) {
						cout << "ͼ��ID����13λ�������������룡" << endl;
						checkbookid = 0;
						continue;
					}
					checkbookid = 1;
				} while (checkbookid == 0);
				bookid = base.str_to_int(bookid2);

				if (base.canFindBook(bookid, nullptr, nullptr) != -1) {
					book = base.idFindBook(bookid);

					//menuBookDetail(&book)
					cout << "-------------------------------" << endl;
					cout << "�鱾ID��" << book.getId() << endl;
					cout << "�鱾���ƣ�" << book.getName() << endl;
					cout << "�鱾���ߣ�" << book.getAuthor() << endl;
					cout << "�����磺" << book.getPress() << endl;
					cout << "����ʱ�䣺" << book.getPublishTime() << endl;
					cout << "�ݲ�λ�ã�" << book.getLocation() << endl;
					cout << "�ݲ�������" << book.getHoldNum() << endl;
					cout << "�ɽ�������" << book.getAvailNum() << endl;
					cout << "-------------------------------" << endl;
					cout << endl;//һ����¼      
				}
				else {
					cout << "���鲻����" << endl;
				}
				flag1 = 1;
				break;
			}
			case 2:
			{
				int checkbookname = 0;
				do {
					cout << "������ͼ��������" << endl;
					cin.getline(bookname, BOOKNAMESIZE);
					if (base.checkType(bookname, 2) == false) {
						cout << "ͼ���������ɰ����ո����������룡" << endl;
						checkbookname = 0;
						continue;
					}
					if (base.isCharLength(bookname, BOOKNAMESIZE) == false) {
						cout << "ͼ�����������涨���ȣ����������룡" << endl;
						checkbookname = 0;
						continue;
					}
					checkbookname = 1;
				} while (checkbookname == 0);


				bookptr = base.otherFindBook(bookname, nullptr, booknum);
				if (bookptr[0].getId() != 0) {
					//menuBookDetail(&book)
					cout << std::left << setw(14) << "*Id" << std::left << setw(20) << "*����"
						<< std::left << setw(20) << "*����" << std::left << setw(20) << "*������"
						<< std::left << setw(20) << "*����ʱ��" << std::left << setw(20) << "*����λ��"
						<< std::left << setw(20) << "*�ݲ�����" << std::left << setw(20) << "*�ɽ�����" << endl;
					for (int i = 0; i < booknum; i++) {
						//menuBookDetail(bookptr[i])
						cout << std::left << setw(14) << bookptr[i].getId();
						cout << std::left << setw(20) << bookptr[i].getName();
						cout << std::left << setw(20) << bookptr[i].getAuthor();
						cout << std::left << setw(20) << bookptr[i].getPress();
						cout << std::left << setw(20) << bookptr[i].getPublishTime();
						cout << std::left << setw(20) << bookptr[i].getLocation();
						cout << std::left << setw(20) << bookptr[i].getHoldNum();
						cout << std::left << setw(20) << bookptr[i].getAvailNum();
						cout << endl;//һ����¼      
					}
				}
				else {
					cout << "���鲻����" << endl;
				}
				flag1 = 1;
				break;
			}
			case 3:
			{

				int check = 0;
				do {
					cout << "������ͼ�����ߣ�" << endl;
					cin.getline(author, AUTHORSIZE);
					if (base.checkType(author, 2) == false) {
						cout << "ͼ�����������ɰ����ո����������룡" << endl;
						check = 0;
						continue;
					}
					if (base.isCharLength(author, AUTHORSIZE) == false) {
						cout << "ͼ�������������涨���ȣ����������룡" << endl;
						check = 0;
						continue;
					}
					check = 1;
				} while (check == 0);

				bookptr = base.otherFindBook(nullptr, author, booknum);
				//menuBookDetail(&book)
				if (bookptr[0].getId() != 0) {
					cout << std::left << setw(14) << "*Id" << std::left << setw(20) << "*����"
						<< std::left << setw(20) << "*����" << std::left << setw(20) << "*������"
						<< std::left << setw(20) << "*����ʱ��" << std::left << setw(20) << "*����λ��"
						<< std::left << setw(20) << "*�ݲ�����" << std::left << setw(20) << "*�ɽ�����" << endl;
					for (int i = 0; i < booknum; i++) {
						//menuBookDetail(bookptr[i])
						cout << std::left << setw(14) << bookptr[i].getId();
						cout << std::left << setw(20) << bookptr[i].getName();
						cout << std::left << setw(20) << bookptr[i].getAuthor();
						cout << std::left << setw(20) << bookptr[i].getPress();
						cout << std::left << setw(20) << bookptr[i].getPublishTime();
						cout << std::left << setw(20) << bookptr[i].getLocation();
						cout << std::left << setw(20) << bookptr[i].getHoldNum();
						cout << std::left << setw(20) << bookptr[i].getAvailNum();
						cout << endl;//һ����¼      
					}
				}
				else {
					cout << "���鲻����" << endl;
				}
				flag1 = 1;
				break;
			}
			case 0:
				flag1 = 0;
				break;
			default:
				cout << "�Ƿ����룡���������룡" << endl;
				flag2 = 1;
			}
		} while (flag2 == 1);
	} while (flag1 == 1);

}

int cmpByValue(const pair<int, int>& lhs, const pair<int, int>& rhs) {
	return lhs.second > rhs.second;
}

void showRank() {
	Base base;
	struct tm t;  //tm�ṹָ��
	time_t now;   //����time_t���ͱ���
	time(&now);    //��ȡϵͳ���ں�ʱ��
	localtime_s(&t, &now);  //��ȡ�������ں�ʱ��
	int nowTime = (1900 + t.tm_year) * 10000 + (1 + t.tm_mon) * 100 + (t.tm_mday);

	map<int, int> rankBorrow;
	History history;
	int midTime;
	int n = history.lengthHistory();
	for (int i = n - 1; i >= 0; --i) {
		history.readHistory(i);
		int borrowTime = history.getBorrowTime();
		midTime = base.calculateTime(borrowTime, nowTime);
		if (midTime > 7) {     //������һ��ȫ�ֱ���
			break;
		}
		else {
			rankBorrow[history.getBookId()]++;
		}
	}

	map<int, int>::iterator it;
	vector<pair<int, int>> res;
	for (it = rankBorrow.begin(); it != rankBorrow.end(); it++)
		res.push_back(pair<int, int>(it->first, it->second));

	sort(res.begin(), res.end(), cmpByValue);
	Book book;
	cout << "--------------------------�鱾��----------------------------" << endl;
	cout << std::left << setw(14) << "�鱾ID";
	cout << std::left << setw(20) << "����";
	cout << std::left << setw(20) << "����";
	cout << std::left << setw(20) << "������";
	cout << std::left << setw(20) << "����ʱ��";
	cout << std::left << setw(20) << "�ݲ�λ��";
	cout << std::left << setw(20) << "�ݲ�����";
	cout << std::left << setw(20) << "�ɽ�������";
	cout << endl;
	for (int i = 0; i < res.size() && i < 10; ++i) {
		book = base.idFindBook(res[i].first);
		book.displayBook();
		cout << endl;
	}
	cout << "-------------------------------------------------------------" << endl;
}


Student idFindStudent(int userid) {
	Student u;
	int n = 0;
	while (n < u.lengthUser())
	{
		u.readUser(n);
		n++;
		if (u.getId() == userid)
			return u;
	}
	cout << "���鲻����" << endl;
}

Administrator idFindAdministrator(int userid) {
	Administrator u;
	int n = 0;
	while (n < u.lengthUser())
	{
		u.readUser(n);
		n++;
		if (u.getId() == userid)
			return u;
	}
	cout << "���û�������" << endl;
}
/*   ��¼�˳�����  yk::��Ϊ���Ϸ��Ե�  */
void login(int& LINE, int& USERID) {
	Base base;
	char password[100];

	char userid[100];//���Ϸ���֮ǰ��Ӧ����Ϊchar[]��������Ϊ100��ͨ���Ϸ���֮����ת��
	//sring password;
	int loginflag = 0;
	User user;
	bool h;
	bool h1;
	while (loginflag == 0) {
		//int userid=0;
		cout << "�������û�ID��" << endl;
		cin.getline(userid, 100);
		//�ж�ID�Ϸ��ԣ����Ϸ����������һ��ѭ��
		if (base.checkType(userid, 1) == false) {
			cout << "�˺�ֻ�ܰ������֣����������룡" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "�˺ų���ʮλ�������������룡" << endl;
			continue;
		}
		cout << "���������룺" << endl;
		cin.getline(password, 100);
		//�ж�����Ϸ���
		if (base.checkType(password, 0) == false) {
			cout << "����ֻ�ܰ������ֺ���ĸ�����������룡" << endl;
			continue;
		}
		if (base.isCharLength(password, PASSWORDSIZE + 1) == false) {
			cout << "���볬���涨λ�������������룡" << endl;
			continue;
		}
		//userid charתΪint
		int userid2 = base.str_to_int(userid);

		//ԭ�߼�
		int line = base.canFindUser(userid2, nullptr);
		if (line == -1) {
			cout << "���û������ڣ������������û�ID�����룡" << endl;
		}
		else {
			user = base.idFindUser(userid2);//��char[]ת��Ϊlong long int ��
			char* turepassword = user.getPassword();
			if (strcmp(password, turepassword) == 0) {
				loginflag = 1;
				LINE = line;
				USERID = user.getId();
				cout << "�û�" << user.getName() << "��¼�ɹ���" << endl;
			}
			else {
				cout << "�û�����������������������û�ID�����룡" << endl;
			}
		}
	}
}

bool quit(int& USERID) {
	USERID = 0;
	if (USERID == 0) {
		cout << "�˳��ɹ���" << endl;
		return true;
	}
	else {
		cout << "�˳�ʧ�ܣ�" << endl;
		return false;
	}
}

void whoBorrowManagement(Administrator& admin) {
	Base base;
	//long long int bookid;
	int checkflag = 0;
	char bookid[100];
	long long int bookid2;
	do {

		cout << "������ͼ��ID:" << endl;
		cin.getline(bookid, 100);
		//�ж�ͼ��id�Ϸ���
		if (base.checkType(bookid, 1) == false) {
			cout << "ͼ��IDֻ�ܰ������֣����������룡" << endl;
			checkflag = 0;
			continue;
		}
		if (base.isCharLength(bookid, 13) == false) {
			cout << "ͼ��ID����13λ�������������룡" << endl;
			checkflag = 0;
			continue;
		}
		checkflag = 1;
	} while (checkflag == 0);
	bookid2 = base.str_to_int(bookid);
	int bookline = base.canFindBook(bookid2, nullptr, nullptr);
	if (bookline == -1) {
		cout << "���鲻���ڣ�" << endl;
	}
	else {
		admin.searchWhoBorrowed(bookid2);
	}

}
//!!!!!
void bookManagement(Administrator admin) {
	Base base;
	int choice;
	//menuBookManagement();
	int flag1 = 0;
	do {
		flag1 = 0;
		int flag2 = 0;
		cout << "-------------------------------" << endl;
		cout << "1.����ͼ��" << endl;
		cout << "2.�޸�ͼ��" << endl;
		cout << "3.ɾ��ͼ��" << endl;
		cout << "4.����ͼ��" << endl;
		cout << "5.����ָ���鼮�Ľ������" << endl;
		cout << "6.��ʾ����ͼ��" << endl;
		cout << "7.��ʾ�鼮��" << endl;
		cout << "0.������һ��" << endl;
		cout << "-------------------------------" << endl;
		do {
			flag2 = 0;

			char choice2[100];
			int checkchoice = 0;
			do {
				cout << "������ѡ�" << endl;
				cin.getline(choice2, 100);
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
				admin.addBookManagement();     //����ͼ��
				flag1 = 1;
				break;
			case 2:
				admin.changeBookManagement();  //�޸�ͼ��
				flag1 = 1;
				break;
			case 3:
				admin.deleteBookManagement();  //ɾ��ͼ��
				flag1 = 1;
				break;
			case 4:
				searchBookManagement();  //����ͼ��
				flag1 = 1;
				break;
			case 5:
				whoBorrowManagement(admin);      //����ָ���鼮�Ľ������
				flag1 = 1;
				break;
			case 6:
				admin.showAllBook();           //��ʾ����ͼ��
				flag1 = 1;
				break;
			case 7:
				showRank();             //��ʾ�鼮��
				flag1 = 1;
				break;
			case 0:
				flag1 = 0;                   //�˻���һ��
				break;
			default:
				cout << "�Ƿ����룡���������빦��" << endl;
				flag2 = 1;
			}

		} while (flag2 == 1);
	} while (flag1 == 1);
}

void userManagement(Administrator admin) {
	Base base;
	int choice;
	//menuUserManagement();
	int flag1 = 0;
	do {
		int maxhistoryshow = MAXHISTORYSHOW;//�ǵ÷�Ⱥ��
		flag1 = 0;
		int flag2 = 0;
		cout << "-------------------------------" << endl;
		cout << "1.�����û�" << endl;
		cout << "2.�޸��û�" << endl;
		cout << "3.ɾ���û�" << endl;
		cout << "4.��ʾ�����û���Ϣ" << endl;
		cout << "5.��ʾ������������Ϣ" << endl;
		cout << "6.��ʾ����" << maxhistoryshow << "��������ʷ" << endl;
		cout << "7.�����û�" << endl;
		cout << "0.������һ��" << endl;
		cout << "-------------------------------" << endl;
		do {
			flag2 = 0;

			char choice2[100];
			int checkchoice = 0;
			do {
				cout << "������ѡ�" << endl;
				cin.getline(choice2, 100);
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
				admin.addUserManagement();       //�����û�
				flag1 = 1;
				break;
			case 2:
				admin.changeUserManagement();    //�޸��û�
				flag1 = 1;
				break;
			case 3:
				admin.deleteUserManagement();    //ɾ���û�
				flag1 = 1;
				break;
			case 4:
				admin.showAllUser();             //��ʾ�����û���Ϣ
				flag1 = 1;
				break;
			case 5:
				admin.showAllBorrow();           //��ʾȫ��������Ϣ
				flag1 = 1;
				break;
			case 6:
				admin.showAllHistory();          //��ʾMAXHiSTORY��������ʷ
				flag1 = 1;
				break;
			case 7:
				admin.searchUserManagement();    //�����û���Ϣ
				flag1 = 1;
				break;
			case 0:
				flag1 = 0;                          //�˻���һ��
				break;
			default:
				cout << "�Ƿ����룡����������" << endl;
				flag2 = 1;
			}
		} while (flag2 == 1);
	} while (flag1 == 1);

}

void personalCenter(Student stu) {
	Base base;
	int choice;
	int flag1 = 0;
	do {
		flag1 = 0;
		int flag2 = 0;
		do {
			flag2 = 0;
			cout << "-----------------------------" << endl;
			cout << "1.��ʾ������Ϣ" << endl;
			cout << "2.�޸ĸ��˵绰" << endl;
			cout << "3.�޸�����" << endl;
			cout << "0.������һ��" << endl;
			cout << "-----------------------------" << endl;
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
				stu = idFindStudent(stu.getId());
				stu.showMyInfo();
				flag1 = 1;
				break;
			case 2:
				stu.changeTelephone();
				flag1 = 1;
				break;
			case 3:
				stu.changeMyPass();
				flag1 = 1;
				break;
			case 0:
				flag1 = 0;
				break;
			default:
				cout << "�Ƿ����룡����������" << endl;
				flag2 = 1;
			}
		} while (flag2 == 1);
	} while (flag1 == 1);



}

void bookBorrowReturn(Administrator admin) {
	Base base;
	int choice;
	int flag1 = 0;
	do {
		flag1 = 0;
		int flag2 = 0;
		cout << "-------------------------------" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "0.������һ��" << endl;
		cout << "-------------------------------" << endl;
		do {
			flag2 = 0;

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
			case 1: {
				admin.borrowBooks();   //����
				flag1 = 1;
				break;
			}
			case 2: {
				admin.returnBooks();   //����
				flag1 = 1;
				break;
			}
			case 0: {
				flag1 = 0;
				break;
			}
			default: {
				cout << "�Ƿ����룡����������" << endl;
				flag2 = 1;
			}
			}
		} while (flag2 == 1);
	} while (flag1 == 1);
}

void bookCenter(Student stu) {
	Base base;
	int flag1 = 0;
	int choice;
	do {
		flag1 = 0;
		int flag2 = 0;
		cout << "-------------------------------" << endl;
		cout << "1.����ͼ��" << endl;
		cout << "2.��ʾ���ڽ�����Ϣ" << endl;
		cout << "3.��ʾ�����������" << endl;
		cout << "4.��ʾ��" << endl;
		cout << "0.������һ��" << endl;
		cout << "-------------------------------" << endl;
		do {
			flag2 = 0;

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
				searchBookManagement();
				flag1 = 1;
				break;
			case 2:
				stu.searchBorrowed();
				flag1 = 1;
				break;
			case 3:
				stu.searchOverDue();
				flag1 = 1;
				break;
			case 4:
				showRank();
				flag1 = 1;
				break;
			case 0:
				flag1 = 0;
				break;
			default:
				cout << "�Ƿ����룡����������" << endl;
				flag2 = 1;
			}
		} while (flag2 == 1);
	} while (flag1 == 1);

}

int main() {
	Base base;
	User userlogin;
	int loginflag = 0;
	do {
		loginflag = 0;
		login(LINE, USERID);
		userlogin = base.idFindUser(USERID);
		if (userlogin.getRole() == 1) {   //�����ǰ�û�Ϊ����Ա
			Administrator admin;
			admin = idFindAdministrator(USERID);
			int choiceflag1 = 0;   //���ں��˹���
			int choice;
			do {
				choiceflag1 = 0;
				int choiceflag2 = 0;
				cout << "��ӭ����Ա" << admin.getName() << "��¼ͼ���ϵͳ" << endl;
				cout << "-------------------------------" << endl;
				cout << "1.�鱾����" << endl;
				cout << "2.�û�����" << endl;
				cout << "3.��������" << endl;
				cout << "4.���黹��" << endl;
				cout << "0.�˳���¼" << endl;
				cout << "-------------------------------" << endl;
				do {
					choiceflag2 = 0;
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
						bookManagement(admin);   //�鱾����
						choiceflag1 = 1;
						break;
					case 2:
						userManagement(admin);   //�û�����
						choiceflag1 = 1;
						break;
					case 3:
						personalCenter(admin);   //��������
						choiceflag1 = 1;
						break;
					case 4:
						bookBorrowReturn(admin);     //���黹��
						choiceflag1 = 1;
						break;
					case 0:
						quit(USERID);                      //�˳���¼
						loginflag = 1;
						break;
					default:
						cout << "�Ƿ����룡����������" << endl;
						choiceflag2 = 1;
					}
				} while (choiceflag2 == 1);
			} while (choiceflag1 == 1);
		}
		else if (userlogin.getRole() == 0) {   //�����ǰ�û�Ϊ��ͨѧ���û�
			Student stu;
			stu = idFindStudent(USERID);
			int choiceflag1 = 0;  //���ں��˹���
			do {
				choiceflag1 = 0;
				//menuOrdinary();
				cout << "��ӭѧ��" << stu.getName() << "��¼ͼ�����ϵͳ" << endl;
				cout << "-------------------------------" << endl;
				cout << "1.��������" << endl;
				cout << "2.ͼ������" << endl;
				cout << "0.�˳���¼" << endl;
				cout << "-------------------------------" << endl;
				int choice;
				int choiceflag2 = 0;
				do {
					choiceflag2 = 0;

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
						personalCenter(stu);    //��������
						choiceflag1 = 1;
						break;
					case 2:
						bookCenter(stu);            //ͼ������
						choiceflag1 = 1;
						break;
					case 0:
						quit(USERID);                       //�˳���¼
						loginflag = 1;
						break;
					default:
						cout << "�Ƿ����룡����������" << endl;
						choiceflag2 = 1;
					}
				} while (choiceflag2 == 1);

			} while (choiceflag1 == 1);
		}
	} while (loginflag == 1);
	return 0;
}

