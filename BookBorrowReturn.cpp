#include"Book.h"
#include"Borrow.h"
#include"User.h"
#include"History.h"
#include"base.h"
#include<ctime>
using namespace std;
/*
#define USERNAMESIZE 50
#define BORROWMAX 20
#define BOOKNAMESIZE 50
#define AUTHORSIZE 30
#define LOCATIONSIZE 50
#define PRESSSIZE 50
#define PASSWORDSIZE 20
*/

void choose_book(int userid)//学生功能 浏览第n行的学生已借阅图书
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
			cout << "借阅时间：" << borrowtime[j] / 10000 << "年" << borrowtime[j] % 10000 / 100 << "月" << borrowtime[j] % 100 << "日" << endl;
		}
	}
	cout << "请及时归还图书！谢谢配合！" << endl;

}

void borrow_books(int userid)//学生借书过程逻辑函数，userid对应的学生借阅书籍
{
	Base base;
	long long int bookid;
	cout << "请输入要借阅的书籍id：";
	cin >> bookid;
	Book temp = base.idFindBook(bookid);
	cout << "你要借阅的书籍信息为：" << endl;
	temp.displayBook();
	if (temp.getAvailNum() == 0)
	{
		cout << "本书可借阅数量为0，暂不可借阅！" << endl;
	}
	else {
		cout << "是否确认借阅此书（输入1借阅0返回）：";
		int t;
		cin >> t;
		if (t == 1)
		{
			addBorrow(userid, bookid);
			temp.changeBook(temp.getId(), temp.getName(), temp.getAuthor(), temp.getLocation(), temp.getPress(), temp.getPublishTime(), temp.getHoldNum(), temp.getAvailNum() - 1);
			temp.writeBook(base.canFindBook(bookid, NULL, NULL));
		}
		else
			cout << "未借阅此书" << endl;
	}

}
void return_books(int userid)//学生还书过程逻辑函数，userid对应的学生归还书籍
{
	Base base;
	cout << "请输入要归还的书籍id：";
	long long int bookid;
	cin >> bookid;
	Book temp = base.idFindBook(bookid);
	Borrow borrowInfo = base.findBorrow(userid);
	for (int i = 0; i < BORROWMAX; i++)
	{
		if (borrowInfo.getBookId()[i] == bookid)
		{
			cout << "借阅书籍名：" << temp.getName() << endl;
			cout << "借阅时间：" << borrowInfo.getBorrowTime()[i] << endl;
		}
	}
	deleteBorrow(userid, bookid);
	cout << "还书成功！";
}
void mag_book2()//学生查找图书过程逻辑 可根据书名或作者名查找
{
	Base base;
	int t;
	char bookname[BOOKNAMESIZE];
	char authorname[AUTHORSIZE];
	cout << "查找图书可根据书名(1)或作者名(2)查找：" << endl;
	cout << "请输入1或2：";
	cin >> t;
	if (t == 1)
	{
		cout << "请输入书名：";
		cin >> bookname;
		Book* p;
		int booknum;
		p = base.otherFindBook(bookname, NULL, booknum);
		for (int i = 0; i < booknum; i++) {
			p[i].displayBook();
		}
	}
	else {
		cout << "请输入作者名：";
		cin >> authorname;
		Book* p;
		int booknum;
		p = base.otherFindBook(NULL, authorname, booknum);
		for (int i = 0; i < booknum; i++) {
			p[i].displayBook();
		}
	}

}


void displayOverDue(int userid) {//显示该学生逾期图书信息
	Base base;
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

void whoBorrowBook(long long int bookid) {//显示当前哪些学生借阅了bookid对应图书还未归还
	Borrow temp;
	for (int i = 0; i < temp.lengthBorrow(); i++)
	{
		temp.readBorrow(i);//读取每一个borrow信息
		for (int i = 0; i < BORROWMAX; i++)
		{
			if (temp.getBookId()[i] == bookid)//如果找到对应bookid，则此人借阅了该书
			{
				cout << "学生" << temp.getName() << "于" << temp.getBorrowTime()[i] / 10000 << "年" << temp.getBorrowTime()[i] % 10000 / 100 << "月" << temp.getBorrowTime()[i] % 100 << "日" << "借阅此书！" << endl;
			}
		}
	}
}
