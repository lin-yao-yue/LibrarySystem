#include"Book.h"
#include"Borrow.h"
#include"User.h"
#include"History.h"
#include"base.h"

void addBookManagement() {     //增加图书
	Base base;
	long long int bookid;
	char bookname[BOOKNAMESIZE];
	char author[AUTHORSIZE];
	char location[LOCATIONSIZE];
	char press[PRESSSIZE];
	int publishtime;
	int addnum;
	//int choice;
	/*
	cout << "1.ISBN号为13位  2.ISBN号为10位  3.没有ISBN号(自制ISBN号)" << endl << "请输入图书编号类型：" << endl;
	cin >> choice;
	switch (choice) {
	case 1:

	}
	*/
	cout << "请输入图书编号：";
	cin >> bookid;
	cout << "请输入图书书名：";
	cin >> bookname;
	cout << "请输入图书作者：";
	cin >> author;
	cout << "请输入图书存放位置：";
	cin >> location;
	cout << "请输入图书出版社：";
	cin >> press;
	cout << "请输入图书出版时间：";
	cin >> publishtime;
	cout << "请输入图书入库数量：";
	cin >> addnum;
	int flag = base.canFindBook(bookid, nullptr, nullptr);
	base.addBook(bookid, bookname, author, location, press, publishtime, addnum);
}



void changeBookManagement() {    //修改图书
	Base base;
	Book oldbook;
	long long int bookid;
	char bookname[BOOKNAMESIZE];
	char author[AUTHORSIZE];
	char location[LOCATIONSIZE];
	char press[PRESSSIZE];
	int publishtime;
	int holdnum;
	int availnum;
	cout << "请输入图书编号：";
	cin >> bookid;
	cout << "请输入图书书名：";
	cin >> bookname;
	cout << "请输入图书作者：";
	cin >> author;
	cout << "请输入图书存放位置：";
	cin >> location;
	cout << "请输入图书出版社：";
	cin >> press;
	cout << "请输入图书出版时间：";
	cin >> publishtime;
	cout << "请输入图书的馆藏数量：";
	cin >> holdnum;
	cout << "请输入图书的可借阅数量：";
	cin >> availnum;
	base.changeBook(bookid, bookname, author, location, press, publishtime, holdnum, availnum);

}

void deleteBookManagement() {    //删除图书
	Base base;
	long long int bookid;
	cout << "请输入图书编号：" << endl;
	cin >> bookid;
	base.deleteBook(bookid);
}

void searchBookManagement() {    //搜索图书
	Base base;
	long long int bookid;
	char bookname[BOOKNAMESIZE];
	char author[AUTHORSIZE];
	int booknum;
	int choice;
	Book book;
	Book* bookptr;
	cout << "1.根据图书编号搜索  2.根据图书书名搜索  3.根据图书作者搜索" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "请输入图书编号：" << endl;
		cin >> bookid;
		if (base.canFindBook(bookid, nullptr, nullptr)) {
			book = base.idFindBook(bookid);
			//menuBookDetail(&book)
			cout << book.getId() << " " << book.getName() << " " << book.getAuthor() << " " << book.getLocation() << " " << book.getPress()
				<< " " << book.getPublishTime() << " " << book.getHoldNum() << " " << book.getAvailNum() << endl;
		}
		else {
			cout << "此书不存在" << endl;
		}
		break;
	case 2:
		cout << "请输入图书书名：" << endl;
		cin >> bookname;
		if (base.canFindBook(NULL, bookname, nullptr)) {
			bookptr = base.otherFindBook(bookname, nullptr, booknum);
			for (int i = 0; i < booknum; i++) {
				//menuBookDetail(bookptr[i])
				cout << bookptr[i].getId() << " " << bookptr[i].getName() << " " << bookptr[i].getAuthor() << " " << bookptr[i].getLocation()
					<< " " << bookptr[i].getPress() << " " << bookptr[i].getPublishTime() << " " << bookptr[i].getHoldNum()
					<< " " << bookptr[i].getAvailNum() << endl;
			}
		}
		else {
			cout << "此书不存在" << endl;
		}
		break;
	case 3:
		cout << "请输入图书作者：" << endl;
		cin >> author;
		if (base.canFindBook(NULL, nullptr, author)) {
			bookptr = base.otherFindBook(nullptr, author, booknum);
			for (int i = 0; i < booknum; i++) {
				//menuBookDetail(bookptr[i])
				cout << bookptr[i].getId() << " " << bookptr[i].getName() << " " << bookptr[i].getAuthor() << " " << bookptr[i].getLocation()
					<< " " << bookptr[i].getPress() << " " << bookptr[i].getPublishTime() << " " << bookptr[i].getHoldNum()
					<< " " << bookptr[i].getAvailNum() << endl;
			}
		}
		else {
			cout << "此书不存在" << endl;
			//backPreviousStep(consition);
		}
		break;
	default:
		cout << "非法输入！" << endl;

	}
}
void showAllBook() {   //显示所有图书
	Base base;
	base.showBookList();
}
void showAllBorrow() {   //显示所有现在的借阅情况
	Base base;
	base.showBorrowList();
}
void showAllHistory() {   //显示所有借阅历史
	Base base;
	base.showHistoryList();
}
