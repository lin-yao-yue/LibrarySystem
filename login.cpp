#include"Book.h"
#include"Borrow.h"
#include"User.h"
#include"base.h"
using namespace std;

/*   ��¼�˳�����   */
void login(int &LINE, int &USERID) {
	Base base;
	int userid;
	char password[PASSWORDSIZE];
	int loginflag = 0;
	User user;
	while (loginflag == 0) {
		cout << "�������û�ID��" << endl;
		cin >> userid;
		cout << "���������룺" << endl;
		cin >> password;
		int line = base.canFindUser(userid, nullptr);
		if (line == -1) {
			cout << "���û������ڣ������������û�ID�����룡" << endl;
		}
		else {
			user = base.idFindUser(userid);
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

bool quit(int&USERID) {
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
