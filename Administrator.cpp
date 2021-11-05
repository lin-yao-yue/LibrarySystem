#include"Administrator.h"
using namespace std;
//显示所有图书
void Administrator::showAllBook() {
	Base base;
	cout << "-------------------------------------------------------------" << endl;
	cout << std::left << setw(14) << "*Id" << std::left << setw(20) << "*名称"
		<< std::left << setw(20) << "*作者" << std::left << setw(20) << "*出版社"
		<< std::left << setw(20) << "*出版时间" << std::left << setw(20) << "*所放位置"
		<< std::left << setw(20) << "*馆藏数量" << std::left << setw(20) << "*可借数量" << endl;
	base.showBookList();
	cout << "-------------------------------------------------------------" << endl;
}
//显示所有现在的借阅情况
void Administrator::showAllBorrow() {
	Base base;
	cout << std::left << setw(20) << "*学生ID" << std::left << setw(20) << "*学生名" << std::left << setw(20) << "*借阅书籍ID" << std::left << setw(20) << "*借阅书籍名：" << std::left << setw(20) << "*借阅时间" << endl;
	base.showBorrowList();
}
//显示近期20条借阅历史
void Administrator::showAllHistory() {
	Base base;
	base.showHistoryList();
}
//增加图书
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
	cout << "1.ISBN号为13位  2.ISBN号为10位  3.没有ISBN号(自制ISBN号)" << endl << "请输入图书编号类型：" << endl;
	cin >> choice;
	switch (choice) {
	case 1:

	}
	*/
	int choice;
	cout << "1.增加一本书 2.从excel表格中增加书 请输入：" << endl;

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
	{	
		int flag2 = 0;
		while (flag2 == 0) {
			cout << "请输入图书编号：";
			cin.getline(bookid, 100);
			if (base.checkType(bookid, 1) == false) {
				cout << "图书ID只能包含数字，请重新输入！" << endl;
				continue;

			}
			if (base.isCharLength(bookid, 13) == false) {
				cout << "图书ID超出十三位数，请重新输入！" << endl;
				continue;
			}
			cout << "请输入图书书名：";
			cin.getline(bookname, 100);
			if (base.checkType(bookname, 2) == false) {
				cout << "书名包含空格，请重新输入！" << endl;
				continue;

			}
			if (base.isCharLength(bookname, BOOKNAMESIZE) == false) {
				cout << "书名超过规定位数，请重新输入！" << endl;
				continue;
			}
			cout << "请输入图书作者：";
			cin.getline(author, 100);
			if (base.checkType(bookname, 2) == false) {
				cout << "书名包含空格，请重新输入！" << endl;
				continue;

			}
			if (base.isCharLength(bookname, BOOKNAMESIZE) == false) {
				cout << "书名超过规定位数，请重新输入！" << endl;
				continue;
			}
			cout << "请输入图书存放位置：";
			cin.getline(location, 100);
			if (base.checkType(location, 2) == false) {
				cout << "位置信息包含空格，请重新输入！" << endl;
				continue;

			}
			if (base.isCharLength(location, LOCATIONSIZE) == false) {
				cout << "位置超过规定位数，请重新输入！" << endl;
				continue;
			}
			cout << "请输入图书出版社：";
			cin.getline(press, 100);
			if (base.checkType(press, 2) == false) {
				cout << "出版社信息包含空格，请重新输入！" << endl;
				continue;

			}
			if (base.isCharLength(press, PRESSSIZE) == false) {
				cout << "出版社超过规定位数，请重新输入！" << endl;
				continue;
			}
			cout << "请输入图书出版时间：";
			cin.getline(publishtime, 100);
			if (base.checkType(publishtime, 1) == false) {
				cout << "出版时间格式错误，请重新输入！" << endl;
				continue;

			}
			if (base.isCharLength(publishtime, 8) == false) {
				cout << "出版时间超过规定位数，请重新输入！" << endl;
				continue;
			}
			cout << "请输入图书入库数量：";
			cin.getline(addnum, 100);
			if (base.checkType(addnum, 1) == false) {
				cout << "入库数量只能包含数字，请重新输入！" << endl;
				continue;

			}
			if (base.isCharLength(addnum, 6) == false) {
				cout << "入库数量超过规定容量，请重新输入！" << endl;
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
			cout << "请输入文件名：（.\\libraryfile\\book.csv ）仿照此输入：" << endl;
			cin.getline(filename, 100);
			if (base.checkType(filename, 2) == false) {
			cout << "输入不能包含空格，请重新输入！" << endl;
			check == 1;
			continue;
			}
			if (base.lengthExcel(filename) == -1)
			{
			check == 1;
			continue;
			}
			for (int i = 0; i < base.lengthExcel(filename); i++)//为考虑有相同书籍的情况
			{
				book = base.readExcel(filename, i);

				book.writeBook(-1);
			}
			cout << "添加成功！" << endl;
		} while (check == 1);
		break;
	}
	default:
		break;
	}
}

//修改图书
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
	//将根据输入的编号判断该书是否存在，若存在将对该书库中该书的信息进行修改！" << endl;	
	int flag = 0;
	while (flag == 0) {
		cout << "请输入图书编号：";
		cin.getline(bookid, 100);
		if (base.checkType(bookid, 1) == false) {
			cout << "图书ID只能包含数字，请重新输入！" << endl;
			continue;

		}
		if (base.isCharLength(bookid, 13) == false) {
			cout << "图书ID超出十三位数，请重新输入！" << endl;
			continue;
		}
		flag = 1;
	}
	bookid2 = base.str_to_int(bookid);
	int line = base.canFindBook(bookid2, NULL, NULL);
	if (line == -1)
	{
		cout << "书库中无此书!" << endl;
	}
	else if (line != -2)//如果找到此书
	{
		cout << "要修改的书籍信息如下：" << endl;
		oldbook = base.idFindBook(bookid2);
		cout << "-------------------------------" << endl;
		cout << "书本ID：" << oldbook.getId() << endl;
		cout << "书本名称：" << oldbook.getName() << endl;
		cout << "书本作者：" << oldbook.getAuthor() << endl;
		cout << "出版社：" << oldbook.getPress() << endl;
		cout << "出版时间：" << oldbook.getPublishTime() << endl;
		cout << "馆藏位置：" << oldbook.getLocation() << endl;
		cout << "馆藏数量：" << oldbook.getHoldNum() << endl;
		cout << "可借数量：" << oldbook.getAvailNum() << endl;
		cout << "-------------------------------" << endl;  
		cout << endl;
		int choice2;
		char choice[100];
		int flag1 = 0;
		int flag2 = 0;
		do {
			cout << "-------------------------------" << endl;
			cout << "1.修改书籍全部信息" << endl;
			cout << "2.修改书籍单独信息" << endl;
			cout << "0.取消" << endl;
			cout << "-------------------------------" << endl;
			cout << "请输入选项：" << endl;
			do {
				cin.getline(choice, 100);
				if (base.checkType(choice, 1) == false) {
					cout << "输入只能包含数字！请重新输入选项：" << endl;
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
					cout << "请输入图书书名：";
					cin.getline(bookname, 100);
					if (base.checkType(bookname, 2) == false) {
						cout << "输入不能包含空格，请重新输入！" << endl;
						continue;
					}
					if (base.isCharLength(bookname, BOOKNAMESIZE) == false) {
						cout << "书名超过规定位数，请重新输入！" << endl;
						continue;
					}
					cout << "请输入图书作者：";
					cin.getline(author, 100);
					if (base.checkType(author, 2) == false) {
						cout << "输入不能包含空格，请重新输入！" << endl;
						continue;

					}
					if (base.isCharLength(author, AUTHORSIZE) == false) {
						cout << "信息超过规定位数，请重新输入！" << endl;
						continue;
					}
					cout << "请输入图书存放位置：";
					cin.getline(location, 100);
					if (base.checkType(location, 2) == false) {
						cout << "输入不能包含空格，请重新输入" << endl;
						continue;

					}
					if (base.isCharLength(location, LOCATIONSIZE) == false) {
						cout << "位置超过规定位数，请重新输入！" << endl;
						continue;
					}
					cout << "请输入图书出版社：";
					cin.getline(press, 100);
					if (base.checkType(press, 2) == false) {
						cout << "输入不能包含空格，请重新输入" << endl;
						continue;

					}
					if (base.isCharLength(press, PRESSSIZE) == false) {
						cout << "出版社超过规定位数，请重新输入！" << endl;
						continue;
					}
					cout << "请输入图书出版时间：";
					cin.getline(publishtime, 100);
					if (base.checkType(publishtime, 1) == false) {
						cout << "出版时间格式错误，请重新输入！" << endl;
						continue;

					}
					if (base.isCharLength(publishtime, 8) == false) {
						cout << "出版时间超过规定位数，请重新输入！" << endl;
						continue;
					}
					break;
				} while (1);
				publishtime2 = base.str_to_int(publishtime);
				cout << "修改后的书籍信息如下：" << endl;
				cout << "-------------------------------" << endl;
				cout << "书籍ID：" << bookid2 << endl;
				cout << "书名：" << bookname << endl;
				cout << "作者：" << author << endl;
				cout << "馆藏位置：" << location << endl;
				cout << "出版社：" << press << endl;
				cout << "出版时间：" << publishtime << endl;
				cout << "馆藏数量：" << oldbook.getHoldNum() << endl;
				cout << "-------------------------------" << endl;
				char input[100];
				char input2;
				int inputflag = 0;
				do {
					do {
						cout << "是否确定删除此用户？确认请输入Y，否则输入N" << endl;
						cin.getline(input, 100);
						if (base.checkType(input, 0) == false || base.isCharLength(input, 1) == false) {
							cout << "输入错误，请重新输入！" << endl;
							continue;
						}
						break;
					} while (1);
					input2 = input[0];
					inputflag = 0;
					if (input2 == 'Y') {
						result = base.changeBook(bookid2, bookname, author, location, press, publishtime2, oldbook.getHoldNum(), oldbook.getAvailNum());//根据编号判断该书是否存在，若存在则修改该书库中该书的信息进行修改
						if (result == 1) {
							cout << "修改成功！" << endl;
						}
					}
					else if (input2 == 'N') {
					}
					else {
						cout << "非法输入，请重新输入！" << endl;
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
					cout << "1.书名" << endl;
					cout << "2.作者" << endl;
					cout << "3.图书存放位置" << endl;
					cout << "4.出版社" << endl;
					cout << "5.出版时间" << endl;
					cout << "0.取消" << endl;
					cout << "-------------------------------" << endl;
					cout << "请输入选项：" << endl;
					do {
						cin.getline(choice3, 100);
						if (base.checkType(choice3, 1) == false) {
							cout << "输入只能包含数字！请重新输入：" << endl;
							continue;
						}
						break;
					} while (1);
					choice2 = base.str_to_int(choice3);
					switch (choice2) {
					case 1: {
						char name[100];
						do {
							cout << "请输入图书书名：" << endl;
							cin.getline(bookname, 100);
							if (base.checkType(bookname, 2) == false) {
								cout << "输入不能包含空格，请重新输入！" << endl;
								continue;
							}
							if (base.isCharLength(bookname, BOOKNAMESIZE) == false) {
								cout << "书名超过规定位数，请重新输入！" << endl;
								continue;
							}
							break;
						} while (1);
						int flag = 0;
		
						result = base.changeBook(oldbook.getId(), bookname, oldbook.getAuthor(), oldbook.getLocation(), oldbook.getPress(), oldbook.getPublishTime(), oldbook.getHoldNum(), oldbook.getAvailNum());
						if (result == 1) {
							cout << "修改成功！" << endl;
						}
						flag2 = 1;
						break;
					}
					case 2: {
						char author[100];
						do {
							cout << "请输入修改后的作者名：" << endl;
							cin.getline(author, 100);
							if (base.checkType(author, 2) == false) {
								cout << "输入不能包含空格，请重新输入！" << endl;
								continue;
							}
							if (base.isCharLength(author, AUTHORSIZE) == false) {
								cout << "信息超过规定位数，请重新输入！" << endl;
								continue;
							}
							break;
						} while (1);
						result = base.changeBook(oldbook.getId(), oldbook.getName(), author, oldbook.getLocation(), oldbook.getPress(), oldbook.getPublishTime(), oldbook.getHoldNum(), oldbook.getAvailNum());
						if (result == 1) {
							cout << "修改成功！" << endl;
						}
						flag2 = 1;
						break;
					}
					case 3: {
						char location[100];
						do {
							cout << "请输入修改后的图书存放位置：" << endl;
							cin.getline(location, 100);
							if (base.checkType(location, 2) == false) {
								cout << "输入不能包含空格，请重新输入！" << endl;
								continue;
							}
							if (base.isCharLength(location, LOCATIONSIZE) == false) {
								cout << "信息超过规定位数，请重新输入！" << endl;
								continue;
							}
							break;
						} while (1);
						result = base.changeBook(oldbook.getId(), oldbook.getName(), oldbook.getAuthor(), location, oldbook.getPress(), oldbook.getPublishTime(), oldbook.getHoldNum(), oldbook.getAvailNum());
						if (result == 1) {
							cout << "修改成功！" << endl;
						}
						flag2 = 1;
						break;
					}
					case 4: {
						char press[100];
						do {
							cout << "请输入修改后的出版社：" << endl;
							cin.getline(press, 100);
							if (base.checkType(press, 2) == false) {
								cout << "输入不能包含空格，请重新输入！" << endl;
								continue;
							}
							if (base.isCharLength(press, PRESSSIZE) == false) {
								cout << "信息超过规定位数，请重新输入！" << endl;
								continue;
							}
							break;
						} while (1);
						result = base.changeBook(oldbook.getId(), oldbook.getName(), oldbook.getAuthor(), oldbook.getLocation(), press, oldbook.getPublishTime(), oldbook.getHoldNum(), oldbook.getAvailNum());
						if (result == 1) {
							cout << "修改成功！" << endl;
						}
						flag2 = 1;
						break;
					}
					case 5: {
						int publishtime2;
						char publishtime[100];
						do {
							cout << "请输入修改后的出版时间：" << endl;
							cin.getline(publishtime, 100);
							if (base.checkType(publishtime, 1) == false) {
								cout << "出版时间格式错误，请重新输入！" << endl;
								continue;
							}
							if (base.isCharLength(publishtime, 8) == false) {
								cout << "出版时间超过规定位数，请重新输入！" << endl;
								continue;
							}
							break;
						} while (1);
						publishtime2 = base.str_to_int(publishtime);
						result = base.changeBook(oldbook.getId(), oldbook.getName(), oldbook.getAuthor(), oldbook.getLocation(), oldbook.getPress(), publishtime2, oldbook.getHoldNum(), oldbook.getAvailNum());
						if (result == 1) {
							cout << "修改成功！" << endl;
						}
						flag2 = 1;
						break;
					}
					case 0: {
						flag2 = 0;
						break;
					}
					default: {
						cout << "非法输入，请重新输入！" << endl;
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
				cout << "非法输入！" << endl;
				flag1 = 1;
			}
			}

		} while (flag1 == 1);
	}
}
//删除图书
void Administrator::deleteBookManagement() {
	Base base;
	Book oldbook;
	long long int bookid2;
	char bookid[100];
	do {
		cout << "请输入图书编号：";
		cin.getline(bookid, 100);
		if (base.checkType(bookid, 1) == false) {
			cout << "图书ID只能包含数字，请重新输入！" << endl;
			continue;

		}
		if (base.isCharLength(bookid, 13) == false) {
			cout << "图书ID超出十三位数，请重新输入！" << endl;
			continue;
		}
		break;
	} while (1);
	bookid2 = base.str_to_int(bookid);
	int line = base.canFindBook(bookid2, NULL, NULL);
	if (line == -1)
	{
		cout << "书库中无此书!" << endl;
	}
	else if (line != -2)//如果找到此书
	{
		cout << "要删除的书籍信息如下：" << endl;
		oldbook = base.idFindBook(bookid2);
		cout << "-------------------------------" << endl;
		cout << "书本ID：" << oldbook.getId() << endl;
		cout << "书本名称：" << oldbook.getName() << endl;
		cout << "书本作者：" << oldbook.getAuthor() << endl;
		cout << "出版社：" << oldbook.getPress() << endl;
		cout << "出版时间：" << oldbook.getPublishTime() << endl;
		cout << "馆藏位置：" << oldbook.getLocation() << endl;
		cout << "馆藏数量：" << oldbook.getHoldNum() << endl;
		cout << "可借数量：" << oldbook.getAvailNum() << endl;
		cout << "-------------------------------" << endl;
		cout << endl;

		int flag = 0;
		do {
			char c[100];
			do {
				cout << "是否确认删除此书（输入 Y借阅 N取消）：";
				cin.getline(c, 100);
				if (base.isCharLength(c, 1) == false || base.checkType(c, 0) == false) {
					cout << "非法输入！请重新输入！" << endl;
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
				cout << "非法输入！请重新输入！" << endl;
				break;
			}
		} while (flag == 1);

	}
}

//添加一名用户
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
		cout << "请输入用户ID：" << endl;
		cin.getline(userid2, 100);
		if (base.checkType(userid2, 1) == false) {
			cout << "用户ID只能包含数字，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(userid2, 10) == false) {
			cout << "用户ID超出十位数，请重新输入！" << endl;
			continue;
		}
		cout << "请输入年级：" << endl;
		cin.getline(grade2, 100);
		if (base.checkType(grade2, 1) == false) {
			cout << "年级只能包含数字，请重新输入！" << endl;
			continue;

		}
		if (base.isCharLength(grade2, 4) == false) {
			cout << "年级超出四位数，请重新输入！" << endl;
			continue;
		}
		cout << "请输入用户名：" << endl;
		cin.getline(username, 100);
		if (base.checkType(username, 2) == false) {
			cout << "输入不能包含空格，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(username, USERNAMESIZE) == false) {
			cout << "超过规定位数，请重新输入！" << endl;
			continue;
		}
		cout << "请输入用户性别(0-女  1-男）：" << endl;
		cin.getline(gender2, 100);
		if (base.checkType(gender2, 1) == false) {
			cout << "只能包含数字，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(gender2, 1) == false) {
			cout << "超出一位数，请重新输入！" << endl;
			continue;
		}
		gender = base.str_to_int(gender2);
		if (gender != 0 && gender != 1) {
			cout << "输入错误" << endl;
			continue;
		}
		cout << "请输入用户电话：" << endl;
		cin.getline(telephone, 100);
		if (base.checkType(telephone, 1) == false) {
			cout << "输入只能包含数字，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(telephone, TELEPHONESIZE) == false) {
			cout << "超过规定位数，请重新输入！" << endl;
			continue;
		}
		cout << "请输入用户权限（0-普通用户  1-管理员）：" << endl;
		cin.getline(role2, 100);
		if (base.checkType(role2, 1) == false) {
			cout << "只能包含数字，请重新输入！" << endl;
			continue;

		}
		if (base.isCharLength(role2, 1) == false) {
			cout << "超出一位数，请重新输入！" << endl;
			continue;
		}
		role = base.str_to_int(role2);
		if (role != 0 && role != 1) {
			cout << "输入错误，请重新输入！" << endl;
			continue;
		}
		break;
	} while (1);
	strcpy(password, "00000000");
	//密码默认为00000000
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
		cout << "请输入需要修改的用户ID：";
		cin.getline(userid, 100);
		if (base.checkType(userid, 1) == false) {
			cout << "用户ID只能包含数字，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "用户ID超出十位数，请重新输入！" << endl;
			continue;
		}
		break;
	} while (1);
	userid2 = base.str_to_int(userid);
	int userline = base.canFindUser(userid2, NULL);
	if (userline == -1) {
		cout << "该用户不存在！" << endl;
	}
	else {
		user = base.idFindUser(userid2);
		cout << "-----------------------------------" << endl;
		cout << "该用户的信息为：" << endl;
		cout << "用户ID：" << user.getId() << endl;
		cout << "姓名：" << user.getName() << endl;
		cout << "年级：" << user.getGrade() << endl;
		cout << "电话：" << user.getTelephone() << endl;
		if (user.getGender() == 1) {
			cout << "性别：男" << endl;
		}
		else if (user.getGender() == 0) {
			cout << "性别：女" << endl;
		}
		if (user.getRole() == 1) {
			cout << "用户角色：管理员" << endl;
		}
		else if (user.getRole() == 0) {
			cout << "用户角色：普通用户" << endl;
		}
		if (user.getState() == 0) {
			cout << "用户状态：正常" << endl;
		}
		else if (user.getState() == -1) {
			cout << "用户状态：已注销" << endl;
		}
		cout << "-----------------------------------" << endl;
		int flag1 = 0;
		do {
			flag1 = 0;
			char choice3[100];
			cout << "-----------------------------------" << endl;
			cout << "1.修改全部信息" << endl;
			cout << "2.修改指定信息" << endl;
			cout << "0.返回上一步" << endl;
			cout << "-----------------------------------" << endl;
			do {
				cout << "请输入选项：" << endl;
				cin.getline(choice3, 100);
				if (base.checkType(choice3, 1) == false) {
					cout << "非法输入，请重新输入！" << endl;
					cout << "-----------------------------------" << endl;
					cout << "1.修改全部信息" << endl;
					cout << "2.修改指定信息" << endl;
					cout << "0.返回上一步" << endl;
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
					cout << "请输入年级：" << endl;
					cin.getline(grade, 100);
					if (base.checkType(grade, 1) == false) {
						cout << "年级只能包含数字，请重新输入！" << endl;
						continue;

					}
					if (base.isCharLength(grade, 4) == false) {
						cout << "年级超出四位数，请重新输入！" << endl;
						continue;
					}
					cout << "请输入用户名：" << endl;
					cin.getline(username, 100);
					if (base.checkType(username, 2) == false) {
						cout << "输入不能包含空格，请重新输入！" << endl;
						continue;
					}
					if (base.isCharLength(username, USERNAMESIZE) == false) {
						cout << "超过规定位数，请重新输入！" << endl;
						continue;
					}
					cout << "请输入用户性别(0-女  1-男）：" << endl;
					cin.getline(gender, 100);
					if (base.checkType(gender, 1) == false) {
						cout << "只能包含数字，请重新输入！" << endl;
						continue;
					}
					if (base.isCharLength(gender, 1) == false) {
						cout << "超出一位数，请重新输入！" << endl;
						continue;
					}
					gender2 = base.str_to_int(gender);
					if (gender2 != 0 && gender2 != 1) {
						cout << "输入错误，请重新输入！" << endl;
						continue;
					}
					cout << "请输入用户电话：" << endl;
					cin.getline(telephone, 100);
					if (base.checkType(telephone, 1) == false) {
						cout << "输入只能包含数字，请重新输入！" << endl;
						continue;
					}
					if (base.isCharLength(telephone, TELEPHONESIZE) == false) {
						cout << "超过规定位数，请重新输入！" << endl;
						continue;
					}
					cout << "请输入用户权限（0-普通用户  1-管理员）：" << endl;
					cin.getline(role, 100);
					if (base.checkType(role, 1) == false) {
						cout << "只能包含数字，请重新输入！" << endl;
						continue;

					}
					if (base.isCharLength(role, 1) == false) {
						cout << "超出一位数，请重新输入！" << endl;
						continue;
					}
					role2 = base.str_to_int(role);
					if (role2 != 0 && role2 != 1) {
						cout << "输入错误，请重新输入！" << endl;
						continue;
					}
					break;
				} while (1);
				grade2 = base.str_to_int(grade);
				gender2 = base.str_to_int(gender);
				role2 = base.str_to_int(role);
				base.changeUser(userid2, grade2, username, gender2, telephone, role2); //根据编号判断该用户是否存在，若存在则修改该用户库中该用户信息进行修改
				flag1 = 1;
				break;
			}
			case 2: {
				int flag2 = 0;
				char choice4[100];
				do {
					flag2 = 0;
					cout << "-----------------------------------" << endl;
					cout << std::left << setw(15) << "1.姓名" << std::left << setw(15) << "2.年级" << endl;
					cout << std::left << setw(15) << "3.性别" << std::left << setw(15) << "4.电话" << endl;
					cout << std::left << setw(15) << "5.用户权限" << std::left << setw(15) << "0.返回上一步" << endl;
					cout << "-----------------------------------" << endl;
					do {
						cout << "请输入选项：" << endl;
						cin.getline(choice4, 100);
						if (base.checkType(choice4, 1) == false) {
							cout << "非法输入，请重新输入！" << endl;
							cout << "-----------------------------------" << endl;
							cout << std::left << setw(15) << "1.姓名" << std::left << setw(15) << "2.年级" << endl;
							cout << std::left << setw(15) << "3.性别" << std::left << setw(15) << "4.电话" << endl;
							cout << std::left << setw(15) << "5.用户权限" << std::left << setw(15) << "0.返回上一步" << endl;
							cout << "-----------------------------------" << endl;
							continue;
						}
						break;
					} while (1);
					choice2 = base.str_to_int(choice4);
					switch (choice2) {
					case 1: {
						cout << "请输入新用户名：" << endl;
						cin.getline(username, 100);
						if (base.checkType(username, 2) == false) {
							cout << "输入不能包含空格，请重新输入！" << endl;
							continue;
						}
						if (base.isCharLength(username, USERNAMESIZE) == false) {
							cout << "超过规定位数，请重新输入！" << endl;
							continue;
						}
						base.changeUser(userid2, user.getGrade(), username, user.getGender(), user.getTelephone(), user.getRole());
						flag2 = 1;
						break;
					}
					case 2: {
						cout << "请输入新年级：" << endl;
						cin.getline(grade, 100);
						if (base.checkType(grade, 1) == false) {
							cout << "年级只能包含数字，请重新输入！" << endl;
							continue;

						}
						if (base.isCharLength(grade, 4) == false) {
							cout << "年级超出四位数，请重新输入！" << endl;
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
							cout << "原性别为 男 ，将更改为 女！" << endl;
							gender2 = 0;
						}
						else
						{
							cout << "原性别为 女 ，将更改为 男！" << endl;
							gender2 = 1;
						}
						base.changeUser(userid2, user.getGrade(), user.getName(), gender2, user.getTelephone(), user.getRole());
						flag2 = 1;
						break;
					}
					case 4: {
						cout << "请输入新电话：" << endl;
						cin.getline(telephone, 100);
						if (base.checkType(telephone, 2) == false) {
							cout << "输入不能包含空格，请重新输入！" << endl;
							continue;
						}
						if (base.isCharLength(telephone, TELEPHONESIZE) == false) {
							cout << "超过规定位数，请重新输入！" << endl;
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
									cout << "是否确定将此用户设置为管理员？确认请输入Y，否则输入N" << endl;
									cin.getline(input, 100);
									if (base.checkType(input, 0) == false || base.isCharLength(input, 1) == false) {
										cout << "输入错误，请重新输入！" << endl;
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
									cout << "非法输入，请重新输入！" << endl;
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
									cout << "是否确定讲此用户设置为普通用户？确认请输入Y，否则输入N" << endl;
									cin.getline(input, 100);
									if (base.checkType(input, 0) == false || base.isCharLength(input, 1) == false) {
										cout << "输入错误，请重新输入！" << endl;
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
									cout << "非法输入，请重新输入！" << endl;
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
						cout << "非法输入，请重新输入！" << endl;
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
				cout << "非法输入！请重新输入！" << endl;
				flag1 = 1;
				break;
			}
			}
		}while (flag1 == 1);
	}
}

//删除用户
void Administrator::deleteUserManagement() {
	Base base;
	int userid2;
	char userid[100];
	do {
		cout << "请输入用户编号：" << endl;
		cin.getline(userid, 100);
		if (base.checkType(userid, 1) == false) {
			cout << "用户ID只能包含数字，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "用户ID超出十位数，请重新输入！" << endl;
			continue;
		}
		break;
	} while (1);
	userid2 = base.str_to_int(userid);
	if (base.canFindUser(userid2, nullptr) != -1) {
		User user = base.idFindUser(userid2);
		cout << "-----------------------------" << endl;
		cout << "该用户的信息为：" << endl;
		cout << "用户ID：" << user.getId() << endl;
		cout << "姓名：" << user.getName() << endl;
		cout << "年级：" << user.getGrade() << endl;
		cout << "电话：" << user.getTelephone() << endl;
		if (user.getGender() == 1) {
			cout << "性别：男" << endl;
		}
		else if (user.getGender() == 0) {
			cout << "性别：女" << endl;
		}
		if (user.getRole() == 1) {
			cout << "用户角色：管理员" << endl;
		}
		else if (user.getRole() == 0) {
			cout << "用户角色：普通用户" << endl;
		}
		if (user.getState() == 0) {
			cout << "用户状态：正常" << endl;
		}
		else if (user.getState() == -1) {
			cout << "用户状态：已注销" << endl;
		}
		cout << "-----------------------------" << endl;
		if (user.getState() != -1) {

			char input[100];
			char input2;
			int inputflag = 0;
			do {
				do {
					cout << "是否确定删除此用户？确认请输入Y，否则输入N" << endl;
					cin.getline(input, 100);
					if (base.checkType(input, 0) == false || base.isCharLength(input, 1) == false) {
						cout << "输入错误，请重新输入！" << endl;
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
					cout << "非法输入，请重新输入！" << endl;
					inputflag = 1;
				}
			} while (inputflag == 1);
		}
		else {
			cout << "该用户已删除无法被修改！" << endl;
			cout << endl;
		}

	}
	else {
		cout << "未找到此用户，无法删除！" << endl;
	}
}

//搜索用户
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
		cout << "1.根据用户ID搜索" << endl;
		cout << "2.根据用户名搜索" << endl;
		cout << "0.返回上一步" << endl;
		cout << "-----------------------------" << endl;
		do {
			flag2 = 0;
			do {
				cout << "请输入选项：" << endl;
				cin.getline(choice, 100);
				if (base.checkType(choice, 1) == false || base.isCharLength(choice, 1) == false) {
					cout << "输入错误，请重新输入！" << endl;
					continue;
				}
				break;
			} while (1);
			choice2 = base.str_to_int(choice);
			switch (choice2) {
			case 1:
				do {
					cout << "请输入用户ID：" << endl;
					cin.getline(userid, 100);
					if (base.checkType(userid, 1) == false) {
						cout << "用户ID只能包含数字，请重新输入！" << endl;
						continue;
					}
					if (base.isCharLength(userid, 10) == false) {
						cout << "用户ID超出十位数，请重新输入！" << endl;
						continue;
					}
					break;
				} while (1);
				userid2 = base.str_to_int(userid);

				line = base.canFindUser(userid2, nullptr);
				if (line != -1) {
					user = base.idFindUser(userid2);
					cout << "---------------------------" << endl;
					cout << "该用户的信息为：" << endl;
					cout << "用户ID：" << user.getId() << endl;
					cout << "姓名：" << user.getName() << endl;
					cout << "年级：" << user.getGrade() << endl;
					cout << "电话：" << user.getTelephone() << endl;
					if (user.getGender() == 1) {
						cout << "性别：男" << endl;
					}
					else if (user.getGender() == 0) {
						cout << "性别：女" << endl;
					}
					if (user.getRole() == 1) {
						cout << "用户角色：管理员" << endl;
					}
					else if (user.getRole() == 0) {
						cout << "用户角色：普通用户" << endl;
					}
					if (user.getState() == 0) {
						cout << "用户状态：正常" << endl;
					}
					else if (user.getState() == -1) {
						cout << "用户状态：已注销" << endl;
					}
					cout << "---------------------------" << endl;
				}
				else {
					cout << "此用户不存在！" << endl;
				}
				flag1 = 1;
				break;
			case 2:
				do {
					cout << "请输入用户名" << endl;
					cin.getline(username, 100);
					if (base.checkType(username, 2) == false) {
						cout << "输入不能包含空格，请重新输入！" << endl;
						continue;
					}
					if (base.isCharLength(username, USERNAMESIZE) == false) {
						cout << "超过规定位数，请重新输入！" << endl;
						continue;
					}
					break;
				} while (1);
				line = base.canFindUser(NULL, username);
				if (line != -1) {
					userptr = base.othoerFindUser(username, usernum);
					cout << "一共" << usernum << "名用户符合搜索条件" << endl;
					for (int i = 0; i < usernum; i++) {
						cout << "---------------------------" << endl;
						cout << "符合条件的第" << i + 1 << "名用户：" << endl;
						cout << "用户ID：" << userptr[i].getId() << endl;
						cout << "姓名：" << userptr[i].getName() << endl;
						cout << "年级：" << userptr[i].getGrade() << endl;
						cout << "电话：" << userptr[i].getTelephone() << endl;
						if (userptr[i].getGender() == 1) {
							cout << "性别：男" << endl;
						}
						else if (userptr[i].getGender() == 0) {
							cout << "性别：女" << endl;
						}
						if (userptr[i].getRole() == 1) {
							cout << "用户角色：管理员" << endl;
						}
						else if (userptr[i].getRole() == 0) {
							cout << "用户角色：普通用户" << endl;
						}
						if (userptr[i].getState() == 0) {
							cout << "用户状态：正常" << endl;
						}
						else if (userptr[i].getState() == -1) {
							cout << "用户状态：已注销" << endl;
						}
						cout << "---------------------------" << endl;
					}
				}
				else {
					cout << "此用户不存在！" << endl;
				}
				flag1 = 1;
				break;
			case 0:
				flag2 = 0;
				break;
			default:
				cout << "非法输入！" << endl;
				flag2 = 1;
			}

		} while (flag2 == 1);
	} while (flag1 == 1);
}
/*有错！已改！！wjq*/ //搜索用户的现在借阅情况
void Administrator::searchBorrowManagement() {
	Base base;
	int userid2;
	char userid[100];
	Borrow borrow;
	int line;
	do {
		cout << "请输入用户ID：";
		cin.getline(userid, 100);
		if (base.checkType(userid, 1) == false) {
			cout << "用户ID只能包含数字，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "用户ID超出十位数，请重新输入！" << endl;
			continue;
		}
		break;
	} while (1);
	userid2 = base.str_to_int(userid);


	if (base.canFindBorrow(userid2) != -1) {
		borrow = base.findBorrow(userid2);
		cout << borrow.getUserId() << " " << borrow.getName() << endl;
		cout << "正在借阅的图书数量为" << borrow.getNumber() << "本" << endl;
		/*改！！！！wjq*/
		long long int bookid[BORROWMAX] = { 0 };
		int borrowtime[BORROWMAX] = { 0 };
		for (int k = 0; k < BORROWMAX; k++)
		{
			bookid[k] = borrow.getBookId()[k];
			borrowtime[k] = borrow.getBorrowTime()[k];
		}//读取借阅bookid和time到数组里
		cout << "借阅图书情况如下：" << endl;
		Book tempBook;
		for (int j = 0; j < BORROWMAX; j++)
		{
			if (bookid[j] != 0) {//如果数组里存的不是0，则有借阅书的记录，输出它
				tempBook = base.idFindBook(bookid[j]);
				char* Bookname = tempBook.getName();
				cout << "书名：" << Bookname;
				cout << "借阅时间：" << borrowtime[j] / 10000 << "年" << borrowtime[j] % 10000 / 100 << "月" << borrowtime[j] % 100 << "日" << endl;
			}
		}

	}
	else {
		cout << "此用户从未借阅过图书，借阅信息不存在！" << endl;
	}

}

void Administrator::showAllUser() {
	Base base;
	cout << std::left << setw(20) << "*Id" << std::left << setw(20) << "*密码" << std::left << setw(20) << "*姓名"
		<< std::left << setw(20) << "*年级" << std::left << setw(20) << "*性别" << std::left << setw(20) << "*电话"
		<< std::left << setw(20) << "*角色" << endl;
	base.showUserList();
}
//学生借书过程逻辑函数，userid对应的学生借阅书籍
void Administrator::borrowBooks()//学生借书过程逻辑函数，userid对应的学生借阅书籍
{
	Base base;
	long long int bookid2;
	int userid2;
	char userid[100];
	int userline;
	char bookid[100];
	do {
		cout << "请输入借书用户ID：";
		cin.getline(userid, 100);
		if (base.checkType(userid, 1) == false) {
			cout << "用户ID只能包含数字，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "用户ID超出十位数，请重新输入！" << endl;
			continue;
		}
		break;
	} while (1);
	userid2 = base.str_to_int(userid);

	userline = base.canFindUser(userid2, nullptr);
	if (userline == -1) {
		cout << "该用户不存在" << endl;
	}
	else {
		User user = base.idFindUser(userid2);


		do {
			cout << "请输入要借阅的书籍id：";
			cin.getline(bookid, 100);
			if (base.checkType(bookid, 1) == false) {
				cout << "图书ID只能包含数字，请重新输入！" << endl;
				continue;

			}
			if (base.isCharLength(bookid, 13) == false) {
				cout << "图书ID超出十三位数，请重新输入！" << endl;
				continue;
			}
			break;
		} while (1);
		bookid2 = base.str_to_int(bookid);
		int bookline = base.canFindBook(bookid2, nullptr, nullptr);
		if (bookline != -1) {
			Book book = base.idFindBook(bookid2);
			cout << "------------------------------------------" << endl;
			cout << "你要借阅的书籍信息为：" << endl;
			cout << "书本ID：" << book.getId() << endl;
			cout << "书本名：" << book.getName() << endl;
			cout << "作者：" << book.getAuthor() << endl;
			cout << "出版社：" << book.getPress() << endl;
			cout << "出版时间：" << book.getPublishTime() << endl;
			cout << "馆藏地址：" << book.getLocation() << endl;
			cout << "馆藏数量：" << book.getHoldNum() << endl;
			cout << "可借阅数量：" << book.getAvailNum() << endl;
			cout << "---------------------------------------------" << endl;
			if (book.getAvailNum() == 0)
			{
				cout << "本书可借阅数量为0，暂不可借阅！" << endl;
			}
			else {

				char t2;
				char t[100];
				int flag = 0;
				do {
					flag = 0;
					do {
						cout << "是否确认借阅此书（输入 Y借阅 N取消）：";
						cin.getline(t, 100);
						if (base.checkType(t, 0) == false || base.isCharLength(t, 1) == false) {
							cout << "输入错误，请重新输入！" << endl;
							continue;
						}
						break;
					} while (1);
					t2 = t[0];
					if (t2 == 'Y')
					{
						struct tm t;  //tm结构指针
						time_t now;   //声明time_t类型变量
						time(&now);    //获取系统日期和时间
						localtime_s(&t, &now);  //获取当地日期和时间
						int borrowtime = (1900 + t.tm_year) * 10000 + (1 + t.tm_mon) * 100 + (t.tm_mday);//得到当前时间当借阅时间
						base.addBorrow(userid2, bookid2);

					}
					else if (t2 == 'N') {

					}
					else {
						cout << "此为非法输入，请重新输入！" << endl;
						flag = 1;
					}
				} while (flag == 1);

			}
		}
		else {
			cout << "不存在此书！" << endl;
		}
	}
}
//还书
void Administrator::returnBooks()
{
	Base base;
	int userid2;
	char userid[100];
	int borrowmax = BORROWMAX;
	int userline;
	do {
		cout << "请输入还书用户ID：";
		cin.getline(userid, 100);
		if (base.checkType(userid, 1) == false) {
			cout << "用户ID只能包含数字，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(userid, 10) == false) {
			cout << "用户ID超出十位数，请重新输入！" << endl;
			continue;
		}
		break;
	} while (1);
	userid2 = base.str_to_int(userid);

	userline = base.canFindUser(userid2, nullptr);
	if (userline == -1) {
		cout << "该用户不存在！" << endl;
	}
	else {
		User user = base.idFindUser(userid2);
		long long int bookid2;
		char bookid[100];
		do {
			cout << "请输入要归还的书籍id：";
			cin.getline(bookid, 100);
			if (base.checkType(bookid, 1) == false) {
				cout << "图书ID只能包含数字，请重新输入！" << endl;
				continue;

			}
			if (base.isCharLength(bookid, 13) == false) {
				cout << "图书ID超出十三位数，请重新输入！" << endl;
				continue;
			}
			break;
		} while (1);
		bookid2 = base.str_to_int(bookid);
		int bookline = base.canFindBook(bookid2, nullptr, nullptr);
		if (bookline == -1) {
			cout << "该书不存在!" << endl;
		}
		else {
			Borrow borrow = base.findBorrow(userid2);
			int flag2 = 0;
			for (int i = 0; i < borrowmax&&flag2 == 0; i++)
			{
				if (borrow.getBookId()[i] == bookid2)
				{
					long long int bid;
					bid = borrow.getBookId()[i];    //借阅记录中符合还书条件的书的id
					Book tbook = base.idFindBook(bid);            //通过bid找到的该书的完整信息，为了输出书名

					cout << "该书借阅记录如下：" << endl;
					cout << "------------------------------------" << endl;
					cout << "书籍ID：" << bid << endl;
					cout << "书籍名字：" << tbook.getName() << endl;
					cout << "借书日期：" << borrow.getBorrowTime()[i] << endl;
					cout << "------------------------------------" << endl;
					char t2;
					char t[100];
					int flag1 = 0;
					do {
						flag1 = 0;
						do {
							cout << "是否确认归还此书（输入 Y归还 N取消）：";
							cin.getline(t, 100);
							if (base.checkType(t, 0) == false || base.isCharLength(t, 1) == false) {
								cout << "输入错误，请重新输入！" << endl;
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
							cout << "非法输入！请重新输入！" << endl;
							flag1 = 1;
						}
					} while (flag1 == 1);
				}
				
			}
			if (flag2 == 0) {
				cout << "用户未借阅此书！" << endl;
		
			}

		}
	}
}


//显示当前哪些学生借阅了bookid对应图书还未归还
void Administrator::searchWhoBorrowed(long long int bookid) {
	Borrow temp;
	int flag = 0;
	int borrowmax = BORROWMAX;
	for (int i = 0; i < temp.lengthBorrow(); i++)
	{
		temp.readBorrow(i);//读取每一个borrow信息
		for (int j = 0; j < borrowmax; j++)
		{
			if (temp.getBookId()[j] == bookid)//如果找到对应bookid，则此人借阅了该书
			{
				flag = 1;
				cout << "(" << j + 1 << ")" << "学生" << temp.getName() << "于" << temp.getBorrowTime()[j] / 10000 << "年" << temp.getBorrowTime()[j] % 10000 / 100 << "月" << temp.getBorrowTime()[j] % 100 << "日" << "借阅此书！" << endl;
			}
		}
	}
	if (flag == 0) {
		cout << "此书暂时未借出！" << endl;
	}
}

//显示该学生逾期图书信息
void Administrator::searchOverDue(int userid) {
	Base base;
	Borrow borrowInfo = base.findBorrow(userid);//先找到对应借书记录borrow对象

	// 基于当前系统的当前日期/时间
	tm* ltm = NULL;
	time_t now = time(0);
	//1970 到目前经过秒数:now
	localtime_s(ltm, &now);
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
				cout << "您所借阅的书籍" << temp.getName() << "已逾期" << borrowedTime - 14 << "天！请及时归还！" << endl;
			}
		}
	}
}

void Administrator::searchBorrowed(int& consition, int userid)
{
	Base base;
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
			cout << "书名：" << Bookname;
			cout << "(" << j + 1 << ")" << "借阅时间：" << borrowtime[j] / 10000 << "年" << borrowtime[j] % 10000 / 100 << "月" << borrowtime[j] % 100 << "日" << endl;
		}
	}
	cout << "请及时归还图书！谢谢配合！" << endl;
}


void Administrator::changePassword(int userid) {

	Base base;
	char oldpassword[100];
	do {
		cout << "请输入原密码：";
		cin.getline(oldpassword, PASSWORDSIZE);
		if (base.checkType(oldpassword, 0) == false) {
			cout << "密码只能包含数字和字母，请重新输入！" << endl;
			continue;
		}
		if (base.isCharLength(oldpassword, PASSWORDSIZE) == false) {
			cout << "密码超出规定位数，请重新输入！" << endl;
			continue;
		}
		break;
	} while (1);
	int consition = 0;
	int n = base.canFindUser(getId(), nullptr);
	char* turepassword = getPassword();
	for (int i = 0; i < PASSWORDSIZE; i++) {
		if (strcmp(oldpassword, turepassword)) {
			cout << "密码输入错误！" << endl;
			break;
		}
		else {

			char password[100];
			do {
				cout << "请输入新密码：";
				cin.getline(password, PASSWORDSIZE);
				if (base.checkType(password, 0) == false) {
					cout << "密码只能包含数字和字母，请重新输入！" << endl;
					continue;
				}
				if (base.isCharLength(password, PASSWORDSIZE) == false) {
					cout << "密码超出规定位数，请重新输入！" << endl;
					continue;
				}
				break;
			} while (1);
			char password2[100];
			do {
				cout << "请再次确认密码：";
				cin.getline(password2, PASSWORDSIZE);
				if (base.checkType(password2, 0) == false) {
					cout << "密码只能包含数字和字母，请重新输入！" << endl;
					continue;
				}
				if (base.isCharLength(password2, PASSWORDSIZE) == false) {
					cout << "密码超出规定位数，请重新输入！" << endl;
					continue;
				}
				break;
			} while (1);
			if (strcmp(password, password2) == 0)
			{
				base.changePassword(getId(), password2);
				cout << "修改成功！" << endl;
				break;
			}
			else {
				cout << "非法输入！请重新输入" << endl;

			}
		}
		cout << endl;
	}
}

