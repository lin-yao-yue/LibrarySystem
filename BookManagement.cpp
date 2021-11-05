#include"Book.h"
#include"Borrow.h"
#include"User.h"
#include"History.h"
#include"base.h"

void addBookManagement() {     //����ͼ��
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
	cout << "1.ISBN��Ϊ13λ  2.ISBN��Ϊ10λ  3.û��ISBN��(����ISBN��)" << endl << "������ͼ�������ͣ�" << endl;
	cin >> choice;
	switch (choice) {
	case 1:

	}
	*/
	cout << "������ͼ���ţ�";
	cin >> bookid;
	cout << "������ͼ��������";
	cin >> bookname;
	cout << "������ͼ�����ߣ�";
	cin >> author;
	cout << "������ͼ����λ�ã�";
	cin >> location;
	cout << "������ͼ������磺";
	cin >> press;
	cout << "������ͼ�����ʱ�䣺";
	cin >> publishtime;
	cout << "������ͼ�����������";
	cin >> addnum;
	int flag = base.canFindBook(bookid, nullptr, nullptr);
	base.addBook(bookid, bookname, author, location, press, publishtime, addnum);
}



void changeBookManagement() {    //�޸�ͼ��
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
	cout << "������ͼ���ţ�";
	cin >> bookid;
	cout << "������ͼ��������";
	cin >> bookname;
	cout << "������ͼ�����ߣ�";
	cin >> author;
	cout << "������ͼ����λ�ã�";
	cin >> location;
	cout << "������ͼ������磺";
	cin >> press;
	cout << "������ͼ�����ʱ�䣺";
	cin >> publishtime;
	cout << "������ͼ��Ĺݲ�������";
	cin >> holdnum;
	cout << "������ͼ��Ŀɽ���������";
	cin >> availnum;
	base.changeBook(bookid, bookname, author, location, press, publishtime, holdnum, availnum);

}

void deleteBookManagement() {    //ɾ��ͼ��
	Base base;
	long long int bookid;
	cout << "������ͼ���ţ�" << endl;
	cin >> bookid;
	base.deleteBook(bookid);
}

void searchBookManagement() {    //����ͼ��
	Base base;
	long long int bookid;
	char bookname[BOOKNAMESIZE];
	char author[AUTHORSIZE];
	int booknum;
	int choice;
	Book book;
	Book* bookptr;
	cout << "1.����ͼ��������  2.����ͼ����������  3.����ͼ����������" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "������ͼ���ţ�" << endl;
		cin >> bookid;
		if (base.canFindBook(bookid, nullptr, nullptr)) {
			book = base.idFindBook(bookid);
			//menuBookDetail(&book)
			cout << book.getId() << " " << book.getName() << " " << book.getAuthor() << " " << book.getLocation() << " " << book.getPress()
				<< " " << book.getPublishTime() << " " << book.getHoldNum() << " " << book.getAvailNum() << endl;
		}
		else {
			cout << "���鲻����" << endl;
		}
		break;
	case 2:
		cout << "������ͼ��������" << endl;
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
			cout << "���鲻����" << endl;
		}
		break;
	case 3:
		cout << "������ͼ�����ߣ�" << endl;
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
			cout << "���鲻����" << endl;
			//backPreviousStep(consition);
		}
		break;
	default:
		cout << "�Ƿ����룡" << endl;

	}
}
void showAllBook() {   //��ʾ����ͼ��
	Base base;
	base.showBookList();
}
void showAllBorrow() {   //��ʾ�������ڵĽ������
	Base base;
	base.showBorrowList();
}
void showAllHistory() {   //��ʾ���н�����ʷ
	Base base;
	base.showHistoryList();
}
