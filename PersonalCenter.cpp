#include"Book.h"
#include"Borrow.h"
#include"User.h"
#include"History.h"
#include"base.h"
using namespace std;

void showMyInfo(User usernow) {
	usernow.displayUser();
}

void changeMyInfo(User usernow) {
	Base base;
	int num;
	int n;
	n = base.canFindUser(usernow.getId(), nullptr);   //我加的，或者你把writeUser换成base.changeUser,
	cout << "请输入你的选择：1.修改多个信息   2.修改单个信息" << endl;
	cin >> num;
	if (num == 1) {
		//*****然后如果修改全部信息，你可以全部输入完了再一次过change，不如这个运行量太大了，没必要分开change
		cout << "请输入新姓名：";
		char name[USERNAMESIZE];
		cin >> name;

		cout << endl << "请输入新年级：";
		int grade;
		cin >> grade;

		int gender = usernow.getGender();
		if (gender == 1)
		{
			cout << "原性别为 男 ，将更改为 女！" << endl;
			gender = 0;
		}
		else
		{
			cout << "原性别为 女 ，将更改为 男！" << endl;
			gender = 1;
		}

		cout << endl << "请输入新电话：";
		char telephone[TELEPHONESIZE];
		cin >> telephone;

		usernow.changeUser(usernow.getId(), usernow.getPassword(), grade, name, gender, telephone, usernow.getRole(), usernow.getState());
		usernow.writeUser(n);

		cout << endl << "学生信息修改完成！" << endl << endl;
		usernow.displayUser();
	}
	else if (num == 2) {
		cout << "可修改个人信息：1.年级	2.姓名	3.性别	4.电话" << endl;
		cout << "请输入编号：";
		int numm;
		cin >> numm;
		switch (numm) {

		case 1:
		{
			cout << "请输入新年级：";
			int grade;
			cin >> grade;
			usernow.changeUser(usernow.getId(), usernow.getPassword(), grade, usernow.getName(), usernow.getGender(), usernow.getTelephone(), usernow.getRole(), usernow.getState());
			usernow.writeUser(n);
			cout << "修改成功！" << endl;
			break;
		}
		case 2:
		{
			cout << "请输入新姓名：";
			char name[USERNAMESIZE];
			cin >> name;
			usernow.changeUser(usernow.getId(), usernow.getPassword(), usernow.getGrade(), name, usernow.getGender(), usernow.getTelephone(), usernow.getRole(), usernow.getState());
			usernow.writeUser(n);
			cout << "修改成功！" << endl;
			break;
		}
		case 3:
		{
			int gender = usernow.getGender();
			if (gender == 1)
			{
				cout << "原性别为 男 ，将更改为 女！" << endl;
				gender = 0;
			}
			else
			{
				cout << "原性别为 女 ，将更改为 男！" << endl;
				gender = 1;
			}
			usernow.changeUser(usernow.getId(), usernow.getPassword(), usernow.getGrade(), usernow.getName(), gender, usernow.getTelephone(), usernow.getRole(), usernow.getState());
			usernow.writeUser(n);
			cout << "修改成功！" << endl;
			break;
		}
		case 4:
		{
			cout << "请输入新电话：";
			char telephone[TELEPHONESIZE];
			cin >> telephone;
			usernow.changeUser(usernow.getId(), usernow.getPassword(), usernow.getGrade(), usernow.getName(), usernow.getGender(), telephone, usernow.getRole(), usernow.getState());
			usernow.writeUser(n);
			cout << "修改成功！" << endl;
			break;
		}
		default:
			cout << "输入错误！";
			break;
		}
	}
}

void changeMyPass(User usernow) {   //***把administer改成usernow
	char oldpassword[PASSWORDSIZE];
	cout << "请输入原密码：";
	cin >> oldpassword;
	int consition = 0;

	Base base;
	int n = base.canFindUser(usernow.getId(), nullptr);

	//administer = idFindUser(userid);
	char* turepassword = usernow.getPassword();
	for (int i = 0; i < PASSWORDSIZE; i++) {
		if (strcmp(oldpassword, turepassword)) {
			cout << "密码输入错误！" << endl;
			break;
		}
		else {
			cout << "请输入新密码：";
			char password[PASSWORDSIZE];
			cin >> password;
			char password2[PASSWORDSIZE];
			cout << "请再次确认密码：";
			cin >> password2;
			if (strcmp(password, password2) == 0)
			{
				base.changePassword(usernow.getId(), password2);
				usernow.writeUser(n);
				cout << "修改成功！" << endl;
				break;
			}
			else {
				cout << "非法输入！请重新输入" << endl;
				backPreviousStep(consition);
			}
		}
		cout << endl;
		system("pause");
	}
}

void backPreviousStep(int& consition) {   //退回到上一步
	consition = 1;
}