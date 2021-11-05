#include"Student.h"


using namespace std;



void Student::showMyInfo() {
	cout << "-----------------------------" << endl;
	cout << "�û�ID��" << getId() << endl;
	cout << "������" << getName() << endl;
	cout << "�꼶��" << getGrade() << endl;
	cout << "�绰��" << getTelephone() << endl;
	if (getGender() == 1) {
		cout << "�Ա���" << endl;
	}
	else if (getGender() == 0) {
		cout << "�Ա�Ů" << endl;
	}
	if (getRole() == 1) {
		cout << "�û���ɫ������Ա" << endl;
	}
	else if (getRole() == 0) {
		cout << "�û���ɫ����ͨ�û�" << endl;
	}
	if (getState() == 0) {
		cout << "�û�״̬������" << endl;
	}
	else if (getState() == -1) {
		cout << "�û�״̬����ע��" << endl;
	}
	cout << "-----------------------------" << endl;
}


void Student::changeTelephone() {
	Base base;
	int flag = 0;
	char temptele[100];
	char tele[TELEPHONESIZE];
	cout << "�������µĵ绰���룺" << endl;

	while (flag == 0) {
		cin.getline(temptele, 100);
		if (base.checkType(temptele, 1) == false) {
			cout << "�˺�ֻ�ܰ������֣����������룡" << endl;
			continue;
		}
		else if (base.isCharLength(temptele, TELEPHONESIZE - 1) == false) {
			cout << "�˺ų���11λ�������������룡" << endl;
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
	cout << "�޸ĳɹ���" << endl;
}

//yk,�Ѹ�,�޸�����ɹ���ע�͵������У������������ظ��������´���ע�ͺ������⡣
void Student::changeMyPass() {
	Base base;
	int passwordsize = PASSWORDSIZE;
	char oldpassword[PASSWORDSIZE];
	char temp1[100];
	int flag = 0;
	cout << "������ԭ���룺";

	while (flag == 0) {
		cin.getline(temp1, 100);
		if (base.checkType(temp1, 0) == false) {
			cout << "����ֻ�ܰ������ֺ���ĸ�����������룡" << endl;
			continue;
		}
		else if (base.isCharLength(temp1, PASSWORDSIZE) == false) {
			cout << "���볬���涨λ�������������룡" << endl;
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
		cout << "�����������" << endl;

	}
	else {
		cout << "�����������룺";
		char password[PASSWORDSIZE];
		char temp2[100];
		char temp3[100];
		int flag2 = 0;
		while (flag2 == 0) {
			cin.getline(temp2, 100);
			if (base.checkType(temp2, 0) == false) {
				cout << "����ֻ�ܰ������ֺ���ĸ�����������룡" << endl;
				continue;
			}
			else if (base.isCharLength(temp2, PASSWORDSIZE) == false) {
				cout << "���볬���涨λ�������������룡" << endl;
				continue;
			}
			else {
				flag2 = 1;
			}
		}
		cout << "���ٴ�ȷ�����룺";
		int flag3 = 0;
		while (flag3 == 0) {
			cin.getline(temp3, 100);
			if (base.checkType(temp2, 0) == false) {
				cout << "����ֻ�ܰ������ֺ���ĸ�����������룡" << endl;
				continue;
			}
			else if (base.isCharLength(temp2, PASSWORDSIZE) == false) {
				cout << "���볬���涨λ�������������룡" << endl;
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
			cout << "�����������벻һ�£�" << endl;

		}
	}
	cout << endl;
}

void Student::searchBorrowed()
{
	Base base;
	int userid = getId();
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
			cout << "������" << Bookname << ";";
			cout << "(" << j + 1 << ")" << "����ʱ�䣺" << borrowtime[j] / 10000 << "��" << borrowtime[j] % 10000 / 100 << "��" << borrowtime[j] % 100 << "��" << endl;
		}
	}
	cout << "�뼰ʱ�黹ͼ�飡лл��ϣ�" << endl;
}

void Student::searchOverDue() {//��ʾ��ѧ������ͼ����Ϣ
	Base base;
	int userid = getId();
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

	int flag = 0;
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
				cout << "�������ĵ��鼮" << temp.getName() << "������" << borrowedTime - 14 << "�죡  �뼰ʱ�黹��" << endl;
				flag = 1;
			}

		}
	}
	if (flag == 0)
	{
		cout << "\n�����鼮���������" << endl;

	}

}
