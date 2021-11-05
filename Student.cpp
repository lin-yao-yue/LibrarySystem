#include"Student.h"


using namespace std;



void Student::showMyInfo() {
	cout << "-----------------------------" << endl;
	cout << "用户ID：" << getId() << endl;
	cout << "姓名：" << getName() << endl;
	cout << "年级：" << getGrade() << endl;
	cout << "电话：" << getTelephone() << endl;
	if (getGender() == 1) {
		cout << "性别：男" << endl;
	}
	else if (getGender() == 0) {
		cout << "性别：女" << endl;
	}
	if (getRole() == 1) {
		cout << "用户角色：管理员" << endl;
	}
	else if (getRole() == 0) {
		cout << "用户角色：普通用户" << endl;
	}
	if (getState() == 0) {
		cout << "用户状态：正常" << endl;
	}
	else if (getState() == -1) {
		cout << "用户状态：已注销" << endl;
	}
	cout << "-----------------------------" << endl;
}


void Student::changeTelephone() {
	Base base;
	int flag = 0;
	char temptele[100];
	char tele[TELEPHONESIZE];
	cout << "请输入新的电话号码：" << endl;

	while (flag == 0) {
		cin.getline(temptele, 100);
		if (base.checkType(temptele, 1) == false) {
			cout << "账号只能包含数字，请重新输入！" << endl;
			continue;
		}
		else if (base.isCharLength(temptele, TELEPHONESIZE - 1) == false) {
			cout << "账号超出11位数，请重新输入！" << endl;
			continue;
		}
		else {
			flag = 1;
		}
	}
	for (int i = 0; i < TELEPHONESIZE; i++) {
		tele[i] = temptele[i];
	}
	base.changeUser(getId(), getGrade(), getName(), getGender(), tele, getRole());
	flag = 1;
	cout << "修改成功！" << endl;
}

//yk,已改,修改密码成功，注释掉了两行，与其他函数重复操作导致错误，注释后无问题。
void Student::changeMyPass() {
	Base base;
	int passwordsize = PASSWORDSIZE;
	char oldpassword[PASSWORDSIZE];
	char temp1[100];
	int flag = 0;
	cout << "请输入原密码：";

	while (flag == 0) {
		cin.getline(temp1, 100);
		if (base.checkType(temp1, 0) == false) {
			cout << "密码只能包含数字和字母，请重新输入！" << endl;
			continue;
		}
		else if (base.isCharLength(temp1, PASSWORDSIZE) == false) {
			cout << "密码超出规定位数，请重新输入！" << endl;
			continue;
		}
		else {
			flag = 1;
		}
	}
	for (int i = 0; i < passwordsize; i++) {
		oldpassword[i] = temp1[i];
	}
	int consition = 0;
	int n = base.canFindUser(getId(), nullptr);
	char* turepassword = getPassword();
	if (strcmp(oldpassword, turepassword) != 0) {
		cout << "密码输入错误！" << endl;

	}
	else {
		cout << "请输入新密码：";
		char password[PASSWORDSIZE];
		char temp2[100];
		char temp3[100];
		int flag2 = 0;
		while (flag2 == 0) {
			cin.getline(temp2, 100);
			if (base.checkType(temp2, 0) == false) {
				cout << "密码只能包含数字和字母，请重新输入！" << endl;
				continue;
			}
			else if (base.isCharLength(temp2, PASSWORDSIZE) == false) {
				cout << "密码超出规定位数，请重新输入！" << endl;
				continue;
			}
			else {
				flag2 = 1;
			}
		}
		cout << "请再次确认密码：";
		int flag3 = 0;
		while (flag3 == 0) {
			cin.getline(temp3, 100);
			if (base.checkType(temp2, 0) == false) {
				cout << "密码只能包含数字和字母，请重新输入！" << endl;
				continue;
			}
			else if (base.isCharLength(temp2, PASSWORDSIZE) == false) {
				cout << "密码超出规定位数，请重新输入！" << endl;
				continue;
			}
			else {
				flag3 = 1;
			}
		}
		if (strcmp(temp2, temp3) == 0)
		{
			for (int i = 0; i < passwordsize; i++) {
				password[i] = temp3[i];
			}
			base.changePassword(getId(), password);
		}
		else {
			cout << "两次密码输入不一致！" << endl;

		}
	}
	cout << endl;
}

void Student::searchBorrowed()
{
	Base base;
	int userid = getId();
	Borrow borrowInfo = base.findBorrow(userid);//找到该生borrow记录

	long long int bookid[BORROWMAX] = { 0 };
	int borrowtime[BORROWMAX] = { 0 };
	for (int k = 0; k < BORROWMAX; k++)
	{
		bookid[k] = borrowInfo.getBookId()[k];
		borrowtime[k] = borrowInfo.getBorrowTime()[k];
	}//读取借阅bookid和time到数组里

	cout << "您的借阅图书情况如下：" << endl;
	Book tempBook;
	for (int j = 0; j < BORROWMAX; j++)
	{
		if (bookid[j] != 0) {//如果数组里存的不是0，则有借阅书的记录，输出它
			tempBook = base.idFindBook(bookid[j]);
			char* Bookname = tempBook.getName();
			cout << "书名：" << Bookname << ";";
			cout << "(" << j + 1 << ")" << "借阅时间：" << borrowtime[j] / 10000 << "年" << borrowtime[j] % 10000 / 100 << "月" << borrowtime[j] % 100 << "日" << endl;
		}
	}
	cout << "请及时归还图书！谢谢配合！" << endl;
}

void Student::searchOverDue() {//显示该学生逾期图书信息
	Base base;
	int userid = getId();
	Borrow borrowInfo = base.findBorrow(userid);//先找到对应借书记录borrow对象

	// 基于当前系统的当前日期/时间
	time_t now = time(0);
	//1970 到目前经过秒数:now
	tm* ltm = localtime(&now);
	// 输出 tm 结构的各个组成部分
	//年: 1900 + ltm->tm_year;
	//月: 1 + ltm->tm_mon ;
	//日: ltm->tm_mday ;
	int todayTime = (1900 + ltm->tm_year) * 10000 + (1 + ltm->tm_mon) * 100 + (ltm->tm_mday);//当前时间
	Book temp;
	struct tm t1 = { 0 };//借书时间
	struct tm t2 = { 0 };//当前时间
	double seconds;
	t2.tm_year = todayTime / 10000 - 1900;//当前时间年
	t2.tm_mon = todayTime % 10000 / 100;//当前时间月
	t2.tm_mday = todayTime % 100;//当前时间日

	int flag = 0;
	for (int i = 0; i < BORROWMAX; i++)
	{
		if (borrowInfo.getBookId()[i] != 0)//对每一本所借的书进行判断
		{
			temp = base.idFindBook(borrowInfo.getBookId()[i]);

			t1.tm_year = (borrowInfo.getBorrowTime()[i]) / 10000 - 1900;//借阅时间
			t1.tm_mon = (borrowInfo.getBorrowTime()[i]) % 10000 / 100;//借阅时间
			t1.tm_mday = (borrowInfo.getBorrowTime()[i]) % 100;//借阅时间

			seconds = difftime(mktime(&t2), mktime(&t1));//转换结构体为time_t,利用difftime,计算时间差  
			int borrowedTime = seconds / 86400;//最后输出时间,因为一天有86400秒(60*60*24)  

			if (borrowedTime > 14)//如果借阅时间超过14天，则提示逾期时间
			{
				cout << "您所借阅的书籍" << temp.getName() << "已逾期" << borrowedTime - 14 << "天！  请及时归还！" << endl;
				flag = 1;
			}

		}
	}
	if (flag == 0)
	{
		cout << "\n所借书籍无逾期情况" << endl;

	}

}
