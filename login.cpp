#include"Book.h"
#include"Borrow.h"
#include"User.h"
#include"base.h"
using namespace std;

/*   登录退出功能   */
void login(int &LINE, int &USERID) {
	Base base;
	int userid;
	char password[PASSWORDSIZE];
	int loginflag = 0;
	User user;
	while (loginflag == 0) {
		cout << "请输入用户ID：" << endl;
		cin >> userid;
		cout << "请输入密码：" << endl;
		cin >> password;
		int line = base.canFindUser(userid, nullptr);
		if (line == -1) {
			cout << "该用户不存在！请重新输入用户ID和密码！" << endl;
		}
		else {
			user = base.idFindUser(userid);
			char* turepassword = user.getPassword();
			if (strcmp(password, turepassword) == 0) {
				loginflag = 1;
				LINE = line;
				USERID = user.getId();
				cout << "用户" << user.getName() << "登录成功！" << endl;
			}
			else {
				cout << "用户密码输入错误！请重新输入用户ID和密码！" << endl;
			}
		}
	}
	
}

bool quit(int&USERID) {
	USERID = 0;
	if (USERID == 0) {
		cout << "退出成功！" << endl;
		return true;
	}
	else {
		cout << "退出失败！" << endl;
		return false;
	}
}
