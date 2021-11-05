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

void choose_book(int userid)//ѧ������ �����n�е�ѧ���ѽ���ͼ��
{
	Base base;
	Borrow borrowInfo = base.findBorrow(userid);//�ҵ�����borrow��¼

	long long int bookid[BORROWMAX] = { 0 };
	int borrowtime[BORROWMAX] = { 0 };
	for (int k = 0; k < BORROWMAX; k++)
	{
		bookid[k] = borrowInfo.getBookId()[k];
		borrowtime[k] = borrowInfo.getBorrowTime()[k];
	}//��ȡ����bookid��time��������

	cout << "���Ľ���ͼ��������£�" << endl;
	Book tempBook;
	for (int j = 0; j < BORROWMAX; j++) 
	{
		if (bookid[j] != 0) {//����������Ĳ���0�����н�����ļ�¼�������
			tempBook = base.idFindBook(bookid[j]);
			char* Bookname = tempBook.getName();
			cout << "������" << Bookname;
			cout << "����ʱ�䣺" << borrowtime[j] / 10000 << "��" << borrowtime[j] % 10000 / 100 << "��" << borrowtime[j] % 100 << "��" << endl;
		}
	}
	cout << "�뼰ʱ�黹ͼ�飡лл��ϣ�" << endl;

}

void borrow_books(int userid)//ѧ����������߼�������userid��Ӧ��ѧ�������鼮
{
	Base base;
	long long int bookid;
	cout << "������Ҫ���ĵ��鼮id��";
	cin >> bookid;
	Book temp = base.idFindBook(bookid);
	cout << "��Ҫ���ĵ��鼮��ϢΪ��" << endl;
	temp.displayBook();
	if (temp.getAvailNum() == 0)
	{
		cout << "����ɽ�������Ϊ0���ݲ��ɽ��ģ�" << endl;
	}
	else {
		cout << "�Ƿ�ȷ�Ͻ��Ĵ��飨����1����0���أ���";
		int t;
		cin >> t;
		if (t == 1)
		{
			addBorrow(userid, bookid);
			temp.changeBook(temp.getId(), temp.getName(), temp.getAuthor(), temp.getLocation(), temp.getPress(), temp.getPublishTime(), temp.getHoldNum(), temp.getAvailNum() - 1);
			temp.writeBook(base.canFindBook(bookid, NULL, NULL));
		}
		else
			cout << "δ���Ĵ���" << endl;
	}

}
void return_books(int userid)//ѧ����������߼�������userid��Ӧ��ѧ���黹�鼮
{
	Base base;
	cout << "������Ҫ�黹���鼮id��";
	long long int bookid;
	cin >> bookid;
	Book temp = base.idFindBook(bookid);
	Borrow borrowInfo = base.findBorrow(userid);
	for (int i = 0; i < BORROWMAX; i++)
	{
		if (borrowInfo.getBookId()[i] == bookid)
		{
			cout << "�����鼮����" << temp.getName() << endl;
			cout << "����ʱ�䣺" << borrowInfo.getBorrowTime()[i] << endl;
		}
	}
	deleteBorrow(userid, bookid);
	cout << "����ɹ���";
}
void mag_book2()//ѧ������ͼ������߼� �ɸ�������������������
{
	Base base;
	int t;
	char bookname[BOOKNAMESIZE];
	char authorname[AUTHORSIZE];
	cout << "����ͼ��ɸ�������(1)��������(2)���ң�" << endl;
	cout << "������1��2��";
	cin >> t;
	if (t == 1)
	{
		cout << "������������";
		cin >> bookname;
		Book* p;
		int booknum;
		p = base.otherFindBook(bookname, NULL, booknum);
		for (int i = 0; i < booknum; i++) {
			p[i].displayBook();
		}
	}
	else {
		cout << "��������������";
		cin >> authorname;
		Book* p;
		int booknum;
		p = base.otherFindBook(NULL, authorname, booknum);
		for (int i = 0; i < booknum; i++) {
			p[i].displayBook();
		}
	}

}


void displayOverDue(int userid) {//��ʾ��ѧ������ͼ����Ϣ
	Base base;
	Borrow borrowInfo = base.findBorrow(userid);//���ҵ���Ӧ�����¼borrow����

	// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
	time_t now = time(0);
	//1970 ��Ŀǰ��������:now
	tm* ltm = localtime(&now);
	// ��� tm �ṹ�ĸ�����ɲ���
	//��: 1900 + ltm->tm_year;
	//��: 1 + ltm->tm_mon ;
	//��: ltm->tm_mday ;
	int todayTime = (1900 + ltm->tm_year) * 10000 + (1 + ltm->tm_mon) * 100 + (ltm->tm_mday);//��ǰʱ��
	Book temp;
	struct tm t1 = { 0 };//����ʱ��
	struct tm t2 = { 0 };//��ǰʱ��
	double seconds;
	t2.tm_year = todayTime / 10000 - 1900;//��ǰʱ����
	t2.tm_mon = todayTime % 10000 / 100;//��ǰʱ����
	t2.tm_mday = todayTime % 100;//��ǰʱ����

	for (int i = 0; i < BORROWMAX; i++)
	{
		if (borrowInfo.getBookId()[i] != 0)//��ÿһ�������������ж�
		{
			temp = base.idFindBook(borrowInfo.getBookId()[i]);

			t1.tm_year = (borrowInfo.getBorrowTime()[i]) / 10000 - 1900;//����ʱ��
			t1.tm_mon = (borrowInfo.getBorrowTime()[i]) % 10000 / 100;//����ʱ��
			t1.tm_mday = (borrowInfo.getBorrowTime()[i]) % 100;//����ʱ��

			seconds = difftime(mktime(&t2), mktime(&t1));//ת���ṹ��Ϊtime_t,����difftime,����ʱ���  
			int borrowedTime = seconds / 86400;//������ʱ��,��Ϊһ����86400��(60*60*24)  

			if (borrowedTime > 14)//�������ʱ�䳬��14�죬����ʾ����ʱ��
			{
				cout << "�������ĵ��鼮" << temp.getName() << "������" << borrowedTime - 14 << "�죡�뼰ʱ�黹��" << endl;
			}

		}
	}

}

void whoBorrowBook(long long int bookid) {//��ʾ��ǰ��Щѧ��������bookid��Ӧͼ�黹δ�黹
	Borrow temp;
	for (int i = 0; i < temp.lengthBorrow(); i++)
	{
		temp.readBorrow(i);//��ȡÿһ��borrow��Ϣ
		for (int i = 0; i < BORROWMAX; i++)
		{
			if (temp.getBookId()[i] == bookid)//����ҵ���Ӧbookid������˽����˸���
			{
				cout << "ѧ��" << temp.getName() << "��" << temp.getBorrowTime()[i] / 10000 << "��" << temp.getBorrowTime()[i] % 10000 / 100 << "��" << temp.getBorrowTime()[i] % 100 << "��" << "���Ĵ��飡" << endl;
			}
		}
	}
}
