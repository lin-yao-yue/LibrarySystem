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



void addUserManagement() {  //增添用户
	int userid;
	int grade;
	char username[USERNAMESIZE];
	char password[PASSWORDSIZE];
	int gender;
	char telephone[TELEPHONESIZE];
	int role;
	cout << "请输入用户ID";
	cin >> userid;
	cout << "请输入年级：";
	cin >> grade;
	cout << "请输入用户名：";
	cin >> username;
	cout << "请输入用户性别：";
	cin >> gender;
	cout << "请输入用户电话：";
	cin >> telephone;
	cout << "请输入用户权限（0-普通用户  1-管理员）：";
	cin >> role;
	cout << "密码默认为00000000" << endl;
	for (int i = 0; i < 8; i++) {
		password[i] = '0';
	}
	//密码默认为00000000
	addUser(userid, password, grade, username, gender, telephone, role);
}
void changeUserManagement() {   //修改用户
	int userid;
	int grade;
	char username[USERNAMESIZE];
	char password[PASSWORDSIZE];
	int gender;
	char telephone[TELEPHONESIZE];
	int role;
	int choice;

	cout << "请输入用户ID";
	cin >> userid;
	cout << "请输入年级：";
	cin >> grade;
	cout << "请输入用户名：";
	cin >> username;
	cout << "请输入用户性别：";
	cin >> gender;
	cout << "请输入用户电话：";
	cin >> telephone;
	cout << "请输入用户权限（0-普通用户  1-管理员）：";
	cin >> role;
	changeUser(userid, grade, username, gender, telephone, role);
}

void deleteUserManagement() {    //删除用户
	long long int userid;
	cout << "请输入用户编号：" << endl;
	cin >> userid;
	deleteUser(userid);
}
void searchUserManagement() {    //搜索用户
	int userid;
	char username[USERNAMESIZE];
	int choice;
	int usernum;
	int line;
	User* userptr;
	User user;
	cout << "1.根据用户ID搜索  2.根据用户名搜索 " << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "请输入用户ID：";
		cin >> userid;
		line = canFindUser(userid, nullptr);
		if (line != -1 ) {
			user = idFindUser(userid);
			cout << user.getId() << " " << user.getName() << " " << user.getGrade() << " " << user.getGender() << " " << user.getTelephone()
				<< " " << user.getRole() << endl;
		}
		else {
			cout << "此用户不存在！" << endl;
		}
		break;
	case 2:
		cout << "请输入用户名";
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
			cout << "此用户不存在！" << endl;
		}
	default:
		cout << "非法输入！" << endl;
	}

}

void searchBorrowManagement() {   //搜索用户的现在借阅情况
	int userid;
	Borrow borrow;
	int line;
	cout << "请输入用户ID：";
	cin >> userid;
	if (canFindBorrow(userid)) {
		borrow = findBorrow(userid);
		cout << borrow.getUserId() << " " << borrow.getName() << endl;
		cout << "正在借阅的图书数量为" << borrow.getNumber() << "本" << endl;
		for (int i = 0; i < borrow.getNumber(); i++) {
			cout << "图书ID：" << borrow.getBookId()[i] << "------借书时间：" << borrow.getBorrowTime()[i] << endl;
		}
	}
	else {
		cout << "此用户借阅信息不存在！" << endl;
	}

}

void showAllUser() {
	showUserList();
}