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

void searchBookManagement() {    //搜索图书
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
		cout << "1.根据图书编号搜索" << endl;
		cout << "2.根据图书书名搜索" << endl;
		cout << "3.根据图书作者搜索" << endl;
		cout << "0.返回上一步" << endl;
		cout << "-------------------------------" << endl;
		do {
			//wjq
			int checkchoice = 0;
			do {
				cout << "请输入选项：" << endl;
				cin.getline(choice2, 20);
				//判断ID合法性，不合法，则进入下一次循环
				if (base.checkType(choice2, 1) == false) {
					cout << "输入只能包含数字，请重新输入！" << endl;
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
					cout << "请输入图书ID:" << endl;
					cin.getline(bookid2, 100);
					//判断图书id合法性
					if (base.checkType(bookid2, 1) == false) {
						cout << "图书ID只能包含数字，请重新输入！" << endl;
						checkbookid = 0;
						continue;
					}
					if (base.isCharLength(bookid2, 13) == false) {
						cout << "图书ID超出13位数，请重新输入！" << endl;
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
					cout << "书本ID：" << book.getId() << endl;
					cout << "书本名称：" << book.getName() << endl;
					cout << "书本作者：" << book.getAuthor() << endl;
					cout << "出版社：" << book.getPress() << endl;
					cout << "出版时间：" << book.getPublishTime() << endl;
					cout << "馆藏位置：" << book.getLocation() << endl;
					cout << "馆藏数量：" << book.getHoldNum() << endl;
					cout << "可借数量：" << book.getAvailNum() << endl;
					cout << "-------------------------------" << endl;
					cout << endl;//一条纪录      
				}
				else {
					cout << "此书不存在" << endl;
				}
				flag1 = 1;
				break;
			}
			case 2:
			{
				int checkbookname = 0;
				do {
					cout << "请输入图书书名：" << endl;
					cin.getline(bookname, BOOKNAMESIZE);
					if (base.checkType(bookname, 2) == false) {
						cout << "图书书名不可包含空格，请重新输入！" << endl;
						checkbookname = 0;
						continue;
					}
					if (base.isCharLength(bookname, BOOKNAMESIZE) == false) {
						cout << "图书书名超出规定长度，请重新输入！" << endl;
						checkbookname = 0;
						continue;
					}
					checkbookname = 1;
				} while (checkbookname == 0);


				bookptr = base.otherFindBook(bookname, nullptr, booknum);
				if (bookptr[0].getId() != 0) {
					//menuBookDetail(&book)
					cout << std::left << setw(14) << "*Id" << std::left << setw(20) << "*名称"
						<< std::left << setw(20) << "*作者" << std::left << setw(20) << "*出版社"
						<< std::left << setw(20) << "*出版时间" << std::left << setw(20) << "*所放位置"
						<< std::left << setw(20) << "*馆藏数量" << std::left << setw(20) << "*可借数量" << endl;
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
						cout << endl;//一条纪录      
					}
				}
				else {
					cout << "此书不存在" << endl;
				}
				flag1 = 1;
				break;
			}
			case 3:
			{

				int check = 0;
				do {
					cout << "请输入图书作者：" << endl;
					cin.getline(author, AUTHORSIZE);
					if (base.checkType(author, 2) == false) {
						cout << "图书作者名不可包含空格，请重新输入！" << endl;
						check = 0;
						continue;
					}
					if (base.isCharLength(author, AUTHORSIZE) == false) {
						cout << "图书作者名超出规定长度，请重新输入！" << endl;
						check = 0;
						continue;
					}
					check = 1;
				} while (check == 0);

				bookptr = base.otherFindBook(nullptr, author, booknum);
				//menuBookDetail(&book)
				if (bookptr[0].getId() != 0) {
					cout << std::left << setw(14) << "*Id" << std::left << setw(20) << "*名称"
						<< std::left << setw(20) << "*作者" << std::left << setw(20) << "*出版社"
						<< std::left << setw(20) << "*出版时间" << std::left << setw(20) << "*所放位置"
						<< std::left << setw(20) << "*馆藏数量" << std::left << setw(20) << "*可借数量" << endl;
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
						cout << endl;//一条纪录      
					}
				}
				else {
					cout << "此书不存在" << endl;
				}
				flag1 = 1;
				break;
			}
			case 0:
				flag1 = 0;
				break;
			default:
				cout << "非法输入！请重新输入！" << endl;
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
	struct tm t;  //tm结构指针
	time_t now;   //声明time_t类型变量
	time(&now);    //获取系统日期和时间
	localtime_s(&t, &now);  //获取当地日期和时间
	int nowTime = (1900 + t.tm_year) * 10000 + (1 + t.tm_mon) * 100 + (t.tm_mday);

	map<int, int> rankBorrow;
	History history;
	int midTime;
	int n = history.lengthHistory();
	for (int i = n - 1; i >= 0; --i) {
		history.readHistory(i);
		int borrowTime = history.getBorrowTime();
		midTime = base.calculateTime(borrowTime, nowTime);
		if (midTime > 7) {     //建议用一个全局变量
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
	cout << "--------------------------书本榜单----------------------------" << endl;
	cout << std::left << setw(14) << "书本ID";
	cout << std::left << setw(20) << "书名";
	cout << std::left << setw(20) << "作者";
	cout << std::left << setw(20) << "出版社";
	cout << std::left << setw(20) << "出版时间";
	cout << std::left << setw(20) << "馆藏位置";
	cout << std::left << setw(20) << "馆藏数量";
	cout << std::left << setw(20) << "可借阅数量";
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
	cout << "此书不存在" << endl;
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
	cout << "此用户不存在" << endl;
}
/*   登录退出功能  yk::改为检查合法性的  */
void login(int& LINE, int& USERID) {
	Base base;
	char password[100];

	char userid[100];//检查合法性之前均应声明为char[]，长度设为100，通过合法性之后再转化
	//sring password;
	int loginflag = 0;
	User user;
	bool h;
	bool h1;
	while (loginflag == 0) {
		//int userid=0;
		cout << "请输入用户ID：" << endl;
		cin.getline(userid, 100);
		//判断ID合法性，不合法，则进入下一次循环
		if (base.checkType(userid, 1) == false) {
			cout << "账号只能包含数字，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "账号超出十位数，请重新输入！" << endl;
			continue;
		}
		cout << "请输入密码：" << endl;
		cin.getline(password, 100);
		//判断密码合法性
		if (base.checkType(password, 0) == false) {
			cout << "密码只能包含数字和字母，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(password, PASSWORDSIZE + 1) == false) {
			cout << "密码超出规定位数，请重新输入！" << endl;
			continue;
		}
		//userid char转为int
		int userid2 = base.str_to_int(userid);

		//原逻辑
		int line = base.canFindUser(userid2, nullptr);
		if (line == -1) {
			cout << "该用户不存在！请重新输入用户ID和密码！" << endl;
		}
		else {
			user = base.idFindUser(userid2);//将char[]转化为long long int 型
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

bool quit(int& USERID) {
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

void whoBorrowManagement(Administrator& admin) {
	Base base;
	//long long int bookid;
	int checkflag = 0;
	char bookid[100];
	long long int bookid2;
	do {

		cout << "请输入图书ID:" << endl;
		cin.getline(bookid, 100);
		//判断图书id合法性
		if (base.checkType(bookid, 1) == false) {
			cout << "图书ID只能包含数字，请重新输入！" << endl;
			checkflag = 0;
			continue;
		}
		if (base.isCharLength(bookid, 13) == false) {
			cout << "图书ID超出13位数，请重新输入！" << endl;
			checkflag = 0;
			continue;
		}
		checkflag = 1;
	} while (checkflag == 0);
	bookid2 = base.str_to_int(bookid);
	int bookline = base.canFindBook(bookid2, nullptr, nullptr);
	if (bookline == -1) {
		cout << "该书不存在！" << endl;
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
		cout << "1.增加图书" << endl;
		cout << "2.修改图书" << endl;
		cout << "3.删除图书" << endl;
		cout << "4.搜索图书" << endl;
		cout << "5.搜索指定书籍的借阅情况" << endl;
		cout << "6.显示所有图书" << endl;
		cout << "7.显示书籍榜单" << endl;
		cout << "0.返回上一步" << endl;
		cout << "-------------------------------" << endl;
		do {
			flag2 = 0;

			char choice2[100];
			int checkchoice = 0;
			do {
				cout << "请输入选项：" << endl;
				cin.getline(choice2, 100);
				//判断choice合法性，不合法，则进入下一次循环
				if (base.checkType(choice2, 1) == false) {
					cout << "输入只能包含数字，请重新输入！" << endl;
					checkchoice = 1;
					continue;
				}
				checkchoice = 0;
			} while (checkchoice == 1);
			choice = base.str_to_int(choice2);


			switch (choice) {
			case 1:
				admin.addBookManagement();     //增加图书
				flag1 = 1;
				break;
			case 2:
				admin.changeBookManagement();  //修改图书
				flag1 = 1;
				break;
			case 3:
				admin.deleteBookManagement();  //删除图书
				flag1 = 1;
				break;
			case 4:
				searchBookManagement();  //搜索图书
				flag1 = 1;
				break;
			case 5:
				whoBorrowManagement(admin);      //搜索指定书籍的借阅情况
				flag1 = 1;
				break;
			case 6:
				admin.showAllBook();           //显示所有图书
				flag1 = 1;
				break;
			case 7:
				showRank();             //显示书籍榜单
				flag1 = 1;
				break;
			case 0:
				flag1 = 0;                   //退回上一步
				break;
			default:
				cout << "非法输入！请重新输入功能" << endl;
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
		int maxhistoryshow = MAXHISTORYSHOW;//记得发群里
		flag1 = 0;
		int flag2 = 0;
		cout << "-------------------------------" << endl;
		cout << "1.增加用户" << endl;
		cout << "2.修改用户" << endl;
		cout << "3.删除用户" << endl;
		cout << "4.显示所有用户信息" << endl;
		cout << "5.显示所有如今借阅信息" << endl;
		cout << "6.显示近期" << maxhistoryshow << "条借阅历史" << endl;
		cout << "7.搜索用户" << endl;
		cout << "0.返回上一步" << endl;
		cout << "-------------------------------" << endl;
		do {
			flag2 = 0;

			char choice2[100];
			int checkchoice = 0;
			do {
				cout << "请输入选项：" << endl;
				cin.getline(choice2, 100);
				//判断choice合法性，不合法，则进入下一次循环
				if (base.checkType(choice2, 1) == false) {
					cout << "输入只能包含数字，请重新输入！" << endl;
					checkchoice = 1;
					continue;
				}
				checkchoice = 0;
			} while (checkchoice == 1);
			choice = base.str_to_int(choice2);


			switch (choice) {
			case 1:
				admin.addUserManagement();       //增加用户
				flag1 = 1;
				break;
			case 2:
				admin.changeUserManagement();    //修改用户
				flag1 = 1;
				break;
			case 3:
				admin.deleteUserManagement();    //删除用户
				flag1 = 1;
				break;
			case 4:
				admin.showAllUser();             //显示所有用户信息
				flag1 = 1;
				break;
			case 5:
				admin.showAllBorrow();           //显示全部借阅信息
				flag1 = 1;
				break;
			case 6:
				admin.showAllHistory();          //显示MAXHiSTORY条借阅历史
				flag1 = 1;
				break;
			case 7:
				admin.searchUserManagement();    //搜索用户信息
				flag1 = 1;
				break;
			case 0:
				flag1 = 0;                          //退回上一步
				break;
			default:
				cout << "非法输入！请重新输入" << endl;
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
			cout << "1.显示个人信息" << endl;
			cout << "2.修改个人电话" << endl;
			cout << "3.修改密码" << endl;
			cout << "0.返回上一步" << endl;
			cout << "-----------------------------" << endl;
			char choice2[20];
			int checkchoice = 0;
			do {
				cout << "请输入选项：" << endl;
				cin.getline(choice2, 20);
				//判断choice合法性，不合法，则进入下一次循环
				if (base.checkType(choice2, 1) == false) {
					cout << "输入只能包含数字，请重新输入！" << endl;
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
				cout << "非法输入！请重新输入" << endl;
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
		cout << "1.借书" << endl;
		cout << "2.还书" << endl;
		cout << "0.返回上一步" << endl;
		cout << "-------------------------------" << endl;
		do {
			flag2 = 0;

			char choice2[20];
			int checkchoice = 0;
			do {
				cout << "请输入选项：" << endl;
				cin.getline(choice2, 20);
				//判断choice合法性，不合法，则进入下一次循环
				if (base.checkType(choice2, 1) == false) {
					cout << "输入只能包含数字，请重新输入！" << endl;
					checkchoice = 1;
					continue;
				}
				checkchoice = 0;
			} while (checkchoice == 1);
			choice = base.str_to_int(choice2);

			switch (choice) {
			case 1: {
				admin.borrowBooks();   //借书
				flag1 = 1;
				break;
			}
			case 2: {
				admin.returnBooks();   //还书
				flag1 = 1;
				break;
			}
			case 0: {
				flag1 = 0;
				break;
			}
			default: {
				cout << "非法输入！请重新输入" << endl;
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
		cout << "1.搜索图书" << endl;
		cout << "2.显示现在借书信息" << endl;
		cout << "3.显示借书逾期情况" << endl;
		cout << "4.显示榜单" << endl;
		cout << "0.返回上一步" << endl;
		cout << "-------------------------------" << endl;
		do {
			flag2 = 0;

			char choice2[20];
			int checkchoice = 0;
			do {
				cout << "请输入选项：" << endl;
				cin.getline(choice2, 20);
				//判断choice合法性，不合法，则进入下一次循环
				if (base.checkType(choice2, 1) == false) {
					cout << "输入只能包含数字，请重新输入！" << endl;
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
				cout << "非法输入！请重新输入" << endl;
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
		if (userlogin.getRole() == 1) {   //如果当前用户为管理员
			Administrator admin;
			admin = idFindAdministrator(USERID);
			int choiceflag1 = 0;   //用于后退功能
			int choice;
			do {
				choiceflag1 = 0;
				int choiceflag2 = 0;
				cout << "欢迎管理员" << admin.getName() << "登录图书馆系统" << endl;
				cout << "-------------------------------" << endl;
				cout << "1.书本管理" << endl;
				cout << "2.用户管理" << endl;
				cout << "3.个人中心" << endl;
				cout << "4.借书还书" << endl;
				cout << "0.退出登录" << endl;
				cout << "-------------------------------" << endl;
				do {
					choiceflag2 = 0;
					char choice2[20];
					int checkchoice = 0;
					do {
						cout << "请输入选项：" << endl;
						cin.getline(choice2, 20);
						//判断choice合法性，不合法，则进入下一次循环
						if (base.checkType(choice2, 1) == false) {
							cout << "输入只能包含数字，请重新输入！" << endl;
							checkchoice = 1;
							continue;
						}
						checkchoice = 0;
					} while (checkchoice == 1);
					choice = base.str_to_int(choice2);

					switch (choice) {
					case 1:
						bookManagement(admin);   //书本管理
						choiceflag1 = 1;
						break;
					case 2:
						userManagement(admin);   //用户管理
						choiceflag1 = 1;
						break;
					case 3:
						personalCenter(admin);   //个人中心
						choiceflag1 = 1;
						break;
					case 4:
						bookBorrowReturn(admin);     //借书还书
						choiceflag1 = 1;
						break;
					case 0:
						quit(USERID);                      //退出登录
						loginflag = 1;
						break;
					default:
						cout << "非法输入！请重新输入" << endl;
						choiceflag2 = 1;
					}
				} while (choiceflag2 == 1);
			} while (choiceflag1 == 1);
		}
		else if (userlogin.getRole() == 0) {   //如果当前用户为普通学生用户
			Student stu;
			stu = idFindStudent(USERID);
			int choiceflag1 = 0;  //用于后退功能
			do {
				choiceflag1 = 0;
				//menuOrdinary();
				cout << "欢迎学生" << stu.getName() << "登录图书管理系统" << endl;
				cout << "-------------------------------" << endl;
				cout << "1.个人中心" << endl;
				cout << "2.图书中心" << endl;
				cout << "0.退出登录" << endl;
				cout << "-------------------------------" << endl;
				int choice;
				int choiceflag2 = 0;
				do {
					choiceflag2 = 0;

					char choice2[20];
					int checkchoice = 0;
					do {
						cout << "请输入选项：" << endl;
						cin.getline(choice2, 20);
						//判断choice合法性，不合法，则进入下一次循环
						if (base.checkType(choice2, 1) == false) {
							cout << "输入只能包含数字，请重新输入！" << endl;
							checkchoice = 1;
							continue;
						}
						checkchoice = 0;
					} while (checkchoice == 1);
					choice = base.str_to_int(choice2);

					switch (choice) {
					case 1:
						personalCenter(stu);    //个人中心
						choiceflag1 = 1;
						break;
					case 2:
						bookCenter(stu);            //图书中心
						choiceflag1 = 1;
						break;
					case 0:
						quit(USERID);                       //退出登录
						loginflag = 1;
						break;
					default:
						cout << "非法输入！请重新输入" << endl;
						choiceflag2 = 1;
					}
				} while (choiceflag2 == 1);

			} while (choiceflag1 == 1);
		}
	} while (loginflag == 1);
	return 0;
}

