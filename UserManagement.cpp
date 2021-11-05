#include"Book.h"
#include"Borrow.h"
#include"User.h"
#include"History.h"
#include"base.cpp"
#include"login.cpp"
using namespace std;
#define USERNAMESIZE 50
#define BORROWMAX 20
#define BOOKNAMESIZE 50
#define AUTHORSIZE 30
#define LOCATIONSIZE 50
#define PRESSSIZE 50
#define PASSWORDSIZE 20



void addUserManagement() {  //�����û�
	int userid;
	int grade;
	char username[USERNAMESIZE];
	char password[PASSWORDSIZE];
	int gender;
	char telephone[TELEPHONESIZE];
	int role;
	cout << "�������û�ID";
	cin >> userid;
	cout << "�������꼶��";
	cin >> grade;
	cout << "�������û�����";
	cin >> username;
	cout << "�������û��Ա�";
	cin >> gender;
	cout << "�������û��绰��";
	cin >> telephone;
	cout << "�������û�Ȩ�ޣ�0-��ͨ�û�  1-����Ա����";
	cin >> role;
	cout << "����Ĭ��Ϊ00000000" << endl;
	for (int i = 0; i < 8; i++) {
		password[i] = '0';
	}
	//����Ĭ��Ϊ00000000
	addUser(userid, password, grade, username, gender, telephone, role);
}
void changeUserManagement() {   //�޸��û�
	int userid;
	int grade;
	char username[USERNAMESIZE];
	char password[PASSWORDSIZE];
	int gender;
	char telephone[TELEPHONESIZE];
	int role;
	int choice;

	cout << "�������û�ID";
	cin >> userid;
	cout << "�������꼶��";
	cin >> grade;
	cout << "�������û�����";
	cin >> username;
	cout << "�������û��Ա�";
	cin >> gender;
	cout << "�������û��绰��";
	cin >> telephone;
	cout << "�������û�Ȩ�ޣ�0-��ͨ�û�  1-����Ա����";
	cin >> role;
	changeUser(userid, grade, username, gender, telephone, role);
}

void deleteUserManagement() {    //ɾ���û�
	long long int userid;
	cout << "�������û���ţ�" << endl;
	cin >> userid;
	deleteUser(userid);
}
void searchUserManagement() {    //�����û�
	int userid;
	char username[USERNAMESIZE];
	int choice;
	int usernum;
	int line;
	User* userptr;
	User user;
	cout << "1.�����û�ID����  2.�����û������� " << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "�������û�ID��";
		cin >> userid;
		line = canFindUser(userid, nullptr);
		if (line != -1 ) {
			user = idFindUser(userid);
			cout << user.getId() << " " << user.getName() << " " << user.getGrade() << " " << user.getGender() << " " << user.getTelephone()
				<< " " << user.getRole() << endl;
		}
		else {
			cout << "���û������ڣ�" << endl;
		}
		break;
	case 2:
		cout << "�������û���";
		cin >> username;
		line = canFindUser(NULL, username);
		if (line != -1) {
			userptr = othoerFindUser(username, usernum);
			for (int i = 0; i < usernum; i++) {
				cout << userptr[i].getId() << " " << userptr[i].getName() << " " << userptr[i].getGrade() << " " << userptr[i].getGender()
					<< " " << userptr[i].getTelephone() << " " << userptr[i].getRole() << endl;
			}
		}
		else {
			cout << "���û������ڣ�" << endl;
		}
	default:
		cout << "�Ƿ����룡" << endl;
	}

}

void searchBorrowManagement() {   //�����û������ڽ������
	int userid;
	Borrow borrow;
	int line;
	cout << "�������û�ID��";
	cin >> userid;
	if (canFindBorrow(userid)) {
		borrow = findBorrow(userid);
		cout << borrow.getUserId() << " " << borrow.getName() << endl;
		cout << "���ڽ��ĵ�ͼ������Ϊ" << borrow.getNumber() << "��" << endl;
		for (int i = 0; i < borrow.getNumber(); i++) {
			cout << "ͼ��ID��" << borrow.getBookId()[i] << "------����ʱ�䣺" << borrow.getBorrowTime()[i] << endl;
		}
	}
	else {
		cout << "���û�������Ϣ�����ڣ�" << endl;
	}

}

void showAllUser() {
	showUserList();
}