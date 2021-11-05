
#include<algorithm>
#include"Book.h"
#include"Borrow.h"
#include"User.h"
#include"History.h"
#include"Base.h";
/**
#define USERNAMESIZE 50
#define BORROWMAX 20
#define BOOKNAMESIZE 50
#define AUTHORSIZE 30
#define LOCATIONSIZE 50
#define PRESSSIZE 50
#define PASSWORDSIZE 20
*/

//�鱾ISBN��У�飬��֤ISBN���ǺϷ���
bool Base::checkISBN(long long int id) {
	if ((id > 999999999 && id < 10000000000) || (id > 999999999999 && id < 10000000000000))
		return 1;
	else
		return 0;
}

/*********Book�Ļ�������**********/
//�ж�ͼ���Ƿ��Ѿ�����������У�������������ļ�����ͨ����š����������߽��в���,���ҵ��˷���true�����򷵻�false
int Base::canFindBook(long long int bookid, char name[BOOKNAMESIZE], char author[AUTHORSIZE]) {     //@ljz
	//���磬����bookid����ʱ��name��author����Ϊnull�����в���
	if (bookid == 0)
	{
		bookid = -1;
	}
	if (bookid != NULL && name == NULL && author == NULL)
	{
		int n = 0;
		Book b;
		while (n < b.lengthBook())
		{
			b.readBook(n);
			n++;
			if (b.getId() == bookid)
				return n;
			
		}
	}
	else if (name != NULL)
	{
		int n = 0;
		Book b;
		while (n < b.lengthBook())
		{
			b.readBook(n);
			n++;
			if (strcmp(b.getName(), name) == 0)
				return n;
		}
	}
	else if (author != NULL )
	{
		int n = 0;
		Book b;
		while (n < b.lengthBook())
		{
			b.readBook(n);
			n++;
			if (strcmp(b.getAuthor(), author) == 0)
				return n;
			
		}
	}
	else {
		return -2; //�˴�Ϊ�����ʽ���󣬶���û���ҵ�
	}
		
	return -1;//û���ҵ�����
}

//����ͼ��id���ظ���Ķ���Ψһ��ֻ��������һ���������������Ķ���
Book Base::idFindBook(long long int bookid) {   //@ljz
	Book b;
	//�����ļ����ҵ�ָ���鼮�����������Ϣ����book��
	int n = 0;
	while (n < b.lengthBook())
	{
		b.readBook(n);
		n++;
		if (b.getId() == bookid )
			return b;
	}
	cout << "cannot find this book" << endl;

}

//���������������߽��в��ң������ж���������
//���з��ص���һ��ָ��ɴ���һ��������飬Ȼ�󷵻�ָ��������ͷָ��
//booknum��һ�����ñ�����ָ���������������鱾��������������ǰ���Ҫ�������Ϊ����������������������������������
Book* Base::otherFindBook(char name[BOOKNAMESIZE], char author[AUTHORSIZE], int& booknum) {   //@ljz
	int count = 0;
	Book b[20];
	Book temp;
	int n = 0;
	if (name != NULL && author == NULL)
	{
		while (n < temp.lengthBook())
		{
			temp.readBook(n);
			if (strcmp(temp.getName(), name) == 0)
			{
				b[count] = temp;
				count++;
			}
			else if (strstr(temp.getName(), name) != NULL)
			{
				b[count] = temp;
				count++;
			}
			n++;
		}
	}
	else if (author != NULL && name == NULL)
	{
		while (n < temp.lengthBook())
		{
			temp.readBook(n);
			if (strcmp(temp.getAuthor(), author) == 0)
			{
				b[count] = temp;
				count++;
			}
			else if (strstr(temp.getAuthor(), author) != NULL)
			{
				b[count] = temp;
				count++;
			}
			n++;
		}
	}
	booknum = count;
	return b;

}


//��ʾ���е�ͼ�鼰����Ϣ
void Base::showBookList() {   //@ljz
	Book b;
	int n = 0;
	while (n < b.lengthBook())
	{
		b.readBook(n);
		if (b.getHoldNum() == 0)
			n++;
		else {
			b.displayBook();
			n++;
		}
		
	}
}

//���ͼ�飨��ͼ����ӣ�
//���α�š����������ߡ��鱾���λ�á������硢����ʱ�䡢��ӵ�����
//�ж�����д����Ƿ��Ѿ����ڣ���������ı�Դ�ļ��Ĺݲ��������������������Ӵ���
int Base::addBook(long long int bookid, char name[USERNAMESIZE], char author[AUTHORSIZE], char location[LOCATIONSIZE], char press[PRESSSIZE], int publishtime, int addnum) {
	//@fy
	Book book;
	int line = canFindBook(bookid, nullptr, nullptr);
	if (line != -1) {//����ҵ���ͬid����
		book = idFindBook(bookid);
		if( book.getHoldNum() != 0){//�ҹݲ�������Ϊ0����ԭ���������

			if (strcmp(name, book.getName()) == 0 && strcmp(author, book.getAuthor()) == 0) {
				book.changeBook(bookid, name, author, location, press, publishtime,
					book.getHoldNum() + addnum, book.getAvailNum() + addnum);
				book.writeBook(line - 1);
			}
			else {
				cout << endl;
				cout << "id�����ظ�������������" << endl;
				cout << endl;
				return -1;
			}
	    }
		else {
			cout << "����id�ظ���" << endl; 
			return -1;//idΪ�Ѿ�ɾ�����id
		}
	}
	else {
		//Ĭ��availnum����holdnum
		book.changeBook(bookid, name, author, location, press, publishtime, addnum, addnum);
		book.writeBook(-1);
	}
	cout << "��ӳɹ�" << endl;
	return 1;
}


//�޸�ͼ�飬�޸������ͼ��ĸ�����Ϣ��������!!!�޸ı��
//����Ϊ��š��������������ߡ����鱾���λ�á��³����硢�³���ʱ�䡢�µĹݲ��������µĿɽ�������
//���ݱ���жϸ����Ƿ���ڣ����������޸ĸ�����и������Ϣ�����޸�
int Base::changeBook(long long int bookid, char newname[USERNAMESIZE], char newauthor[AUTHORSIZE], char newloation[LOCATIONSIZE], char newpress[PRESSSIZE], int newpublishtime, int newhold, int newavailable) {
	//@fy
	//ȫ�����ζ��޸ģ�����̨������main�������ƣ��˺���ֻ��Ҫ�Ѵ��ε����ݸ����û�����
	Book tempBook;
	int line = canFindBook(bookid, nullptr, nullptr);

	if (line != -1) {
		tempBook = idFindBook(bookid);
		if (tempBook.getHoldNum() != 0)//��ʾ����û�б�ɾ������
		{
			tempBook.changeBook(bookid, newname, newauthor, newloation, newpress, newpublishtime, newhold, newavailable);
			tempBook.writeBook(line - 1);
			//�޸ĳɹ�����1
			return 1;
		}
		else
		{
			cout << "�����Ѿ�ɾ�����޷��޸ģ�" << endl; cout << endl;
			return -2;
		}
	}
	else {
		cout << endl;
		cout << "û���ҵ�Ҫ�޸ĵ�ͼ��"<<endl;
		cout << endl;
		return -1;
	}

}

//ɾ��ͼ�飬����Ϊͼ���ţ�ɾ�������ͼ������ָ���鱾��Ϣ
//���ݱ���жϸ����Ƿ���ڣ���������Ը�����Ϣ����ɾ��
int Base::deleteBook(long long int bookid) {
	//@fy
	Book tempBook;
	int line = canFindBook(bookid, nullptr, nullptr);
	if (line != -1) {//�ҵ�����id
		tempBook = idFindBook(bookid);
		if (tempBook.getAvailNum() == tempBook.getHoldNum()&& tempBook.getHoldNum()!=0) {//���û�б�����Ҹ���δ��ɾ
			//holdNum��availNum��Ϊ0
			tempBook.changeBook(bookid, tempBook.getName(), tempBook.getAuthor(),tempBook.getLocation(), tempBook.getPress(), tempBook.getPublishTime(), 0, 0);
			tempBook.writeBook(line - 1);
			cout << endl;
			cout << "ɾ���ɹ�"<<endl;	
			cout << endl;
			return 1;
		}
		else if(tempBook.getAvailNum() == tempBook.getHoldNum() && tempBook.getHoldNum() == 0){////���û�б�����Ҹ��鱻ɾ
			cout << "�����ѱ�ɾ����" << endl; cout << endl;
			return -3;
		}
		else {//��������
			cout << endl;
			cout << "�����ѱ����ģ��޷�ɾ��"<<endl;
			cout << endl;
			return -2;
		}

	}
	else {
		cout << endl;
		cout << "û���ҵ�Ҫɾ����ͼ��";	cout << endl;	cout << endl;
		return -1;
	}
}




/***********************************/

/*************User�Ļ�������*********/

// yk�� ���Ұ�Ѱ���û���������-1����Ϊn��0��ʼ���Ա㸲��д��ʱ��n��������ͱ���ͳһ 

//�ж�ͼ���Ƿ��Ѿ��������û�����,���ҵ��˷���true�����򷵻�false
int Base::canFindUser(int userid, char name[USERNAMESIZE]) {           //@ljz
	//���磬����userid����ʱ��name����Ϊnull�����в���
	if (userid != NULL && name == NULL)
	{
		int n = 0;
		User u;
		while (n < u.lengthUser())
		{
			u.readUser(n);
			n++;
			if (u.getId() == userid)
				return n;
			
		}
	}
	else if (name != NULL && userid == NULL)
	{
		int n = 0;
		User u;
		while (n < u.lengthUser())
		{
			u.readUser(n);
			n++;
			if (strcmp(u.getName(), name) == 0)
				return n;
		
		}
	}

	else
		return -2; //�˴�Ϊ�����ʽ���󣬶���û���ҵ�
	return -1;

}

//�����û�id���ң�������Ψһ����

User Base::idFindUser(int userid) {      //@ljz
	User u;
	int n = 0;
	while (n < u.lengthUser())
	{
		u.readUser(n);
		n++;
		if (u.getId() == userid)
			return u;
	}
	cout << endl;
	cout << "û���ҵ���ǰ�û���" << endl;	cout << endl;
}

//�����������в��ң������ж���������
//���з��ص���һ��ָ��ɴ���һ��������飬Ȼ�󷵻�ָ��������ͷָ��
//usernum��һ�����ñ�����ָ���������������鱾��������������ǰ���Ҫ�������Ϊ����������������������������������
User* Base::othoerFindUser(char name[USERNAMESIZE], int& usernum) {      //@ljz
	int count = 0;
	User u[100];
	User temp;
	int n = 0;
	while (n < temp.lengthUser())
	{
		temp.readUser(n);
		if (strcmp(temp.getName(), name) == 0)
		{
			u[count]=temp;
			count++;
		}
		n++;
	}
	usernum = count;
	return u;
}

//��ʾ���е��û�������Ϣ
void Base::showUserList() {   //@ljz
	User u;
	int n = 0;
	while (n < u.lengthUser())
	{
		u.readUser(n);
		if (u.getState() != -1)
		{
			u.displayUser();
		}

		n++;
	}
}


//����û�(����û���ӣ�
//�����˺š����롢�꼶���������Ա𡢵绰���û�����
//�жϴ��û��Ƿ��Ѿ����ڣ��������������Ӵ���
void Base::addUser(int userid, char password[PASSWORDSIZE], int grade, char name[USERNAMESIZE], int gender, char telephone[TELEPHONESIZE], int role) {
	//@fy
	User user;
	Borrow borrow = Borrow();
	int line = canFindUser(userid, nullptr);
	if (line != -1) {//����ҵ����û�
		user = idFindUser(userid);
		if (user.getState() != -1) {
			cout << endl;
			cout << "���û��Ѵ���" << endl;
			cout << endl;
		}
		else {//��id�û��ѱ�ɾ��
			cout << "����id�ظ�" << endl;
		}
	}
	else {
		user.changeUser(userid, password, grade, name, gender, telephone, role, 0);
		user.writeUser(-1);
		borrow.changeBorrow(userid, name, 0, borrow.getBookId(), borrow.getBorrowTime());
		borrow.writeBorrow(-1);
		cout << endl;
		cout << "����ѧ���ɹ�" << endl;
		cout << "����Ĭ��Ϊ00000000" << endl;
		cout << endl;
	}
}

//�޸��û����޸��û���ͼ��ĸ�����Ϣ���������޸ı�ź�����
//����Ϊ��š������롢���꼶�������������Ա��µ绰�����û�����
//���ݱ���жϸ��û��Ƿ���ڣ����������޸ĸ��û����и��û���Ϣ�����޸�
int Base::changeUser(int userid, int newgrade, char newname[USERNAMESIZE], int newgender, char newtelephone[TELEPHONESIZE], int newrole) {
	//ȫ�����ζ��޸ģ�����̨������main�������ƣ��˺���ֻ��Ҫ�Ѵ��ε����ݸ����û�����
	//@fy
	User user;
	int line = canFindUser(userid, nullptr);
	if (line != -1) {//����ҵ���id�û�
		user = idFindUser(userid);
		if (user.getState() != -1)//���û�б�ɾ��
		{
			user.changeUser(userid, user.getPassword(), newgrade, newname, newgender, newtelephone, newrole, 0);
			user.writeUser(line - 1);
			cout << "�޸��û��ɹ�" << endl;
			cout << "---------------------------" << endl;
			cout << "���û�����ϢΪ��" << endl;
			cout << "�û�ID��" << user.getId() << endl;
			cout << "������" << user.getName() << endl;
			cout << "�꼶��" << user.getGrade() << endl;
			cout << "�绰��" << user.getTelephone() << endl;
			if (user.getGender() == 1) {
				cout << "�Ա���" << endl;
			}
			else if (user.getGender() == 0) {
				cout << "�Ա�Ů" << endl;
			}
			if (user.getRole() == 1) {
				cout << "�û���ɫ������Ա" << endl;
			}
			else if (user.getRole() == 0) {
				cout << "�û���ɫ����ͨ�û�" << endl;
			}
			if (user.getState() == 0) {
				cout << "�û�״̬������" << endl;
			}
			else if (user.getState() == -1) {
				cout << "�û�״̬����ע��" << endl;
			}
			cout << "---------------------------" << endl;
			return 1;
		}
		else {//������û���ɾ��
			cout << "��ɾ���û����ܱ��޸�" << endl;
		}
		
	}
	else {
		cout << endl;
		cout << "Ҫ�޸ĵ��û�������";	cout << endl;	cout << endl;
		return -1;
	}
}

//ɾ���û�������Ϊ�û���ţ�
//���ݱ���жϸ��û��Ƿ���ڣ���������Ը��û���Ϣ����ɾ��
void Base::deleteUser(int userid) {
	User user;
	Borrow borrow;
	int borrowline;
	int borrowmax = BORROWMAX;
	int userline = canFindUser(userid, nullptr);
	if (userline != -1) {//����ҵ���id�û�
		user = idFindUser(userid);
		if (user.getState() !=-1) {   //����û�û�б�ע��
			borrowline = canFindBorrow(user.getId());
			borrow = findBorrow(user.getId());
			int borrowflag = 0;
			if (borrow.getNumber() == 0) {
				user.changeUser(user.getId(), user.getPassword(), user.getGrade(), user.getName(),
					user.getGender(), user.getTelephone(), user.getRole(), -1);
				user.writeUser(userline - 1);
				cout << "ɾ���ɹ�";	cout << endl;	cout << endl;
			}
			else {
				cout << "ɾ���û��н����¼���޷�ɾ��";	cout << endl;	cout << endl;
			}
			

		}
		else {
			cout << "���û��Ѿ�ע�����޷��ظ�������" << endl;	cout << endl;
		}
	}
	else {
		cout << "Ҫɾ�����û�������";	cout << endl;	cout << endl;
	}

}
/**  ��main����������
��ʹ���ڵ�¼���޸��Լ������룬�򴫲�idΪȫ�ֱ���USERID
��ʹ���ڹ���Ա�޸ı��˵����룬�򴫲�idΪ�û�����̨�����userid
����oldpassword�����������û�����̨�����ԭ����
**/
//�޸��û�����:��������ĳѧ��id��ͨ����id�޸Ĵ�ѧ��������
//�޸�ǰҪ����Ҫ
void Base::changePassword(int userid, char newPassword[PASSWORDSIZE]) {
	//@fy
	//oldpasswordΪ�ڸ�����ǰ�û�����̨�����ԭ���룬������ԭ��������û�д����ſ��Խ����޸�
	User user;
	int line = canFindUser(userid, nullptr);
	if (line != -1) {
		user = idFindUser(userid);
		user.changeUser(userid, newPassword, user.getGrade(), user.getName(), user.getGender(), user.getTelephone(), user.getRole(), 0);
		user.writeUser(line-1);
		cout << "�޸�����ɹ�";	cout << endl;	cout << endl;
	}
}

/*************************************/

/***********Borrow�Ļ�������*************/
//�жϽ�����Ϣ�Ƿ�����ڽ��Ŀ��У�ͨ���û�id����
int Base::canFindBorrow(int userid) {   //@ljz
	int n = 0;
	Borrow b;
	while (n < b.lengthBorrow())
	{
		b.readBorrow(n);
		n++;
		if (b.getUserId() == userid)
			return n;
	}
	return -1;
}

//�����û�id���Ҵ��û������¼��������borrow����
Borrow Base::findBorrow(int userid) {   //@ljz
	Borrow b;
	int n = 0;
	while (n < b.lengthBorrow())
	{
		b.readBorrow(n);
		n++;
		if (b.getUserId() == userid)
			return b;
	}
	cout << "û���ҵ���ǰ��¼" << endl;	cout << endl;
}

//��ʾ��ǰ���н����¼
void Base::showBorrowList() {    //@ljz
	Borrow b;
	Book bo;
	User user;
	int n = 0;
	while (n < b.lengthBorrow())
	{
		b.readBorrow(n);
		user = idFindUser(b.getUserId());
		for (int k = 0; k < 20; k++)
		{

			if (b.getBookId()[k] != 0)//�����Ϊ0����������Ϣ���G
			{
				cout << std::left << setw(20) << b.getUserId() << std::left << setw(20);
				cout << b.getName() << std::left << setw(20);
				cout << b.getBookId()[k] << std::left << setw(20);
				bo = idFindBook(b.getBookId()[k]);
				cout << bo.getName()<< std::left << setw(20);
				cout<<b.getBorrowTime()[k]<< std::left << setw(20);
				cout << endl;
			}
		}
		n++;
	}
}
bool Base::addBorrow(int userid, long long int bookid) {
	//@wjq
	//���Borrow.dat��Ϣ
	int borrowmax = BORROWMAX;
	Base base;
	Borrow temp = Borrow();
	if (temp.canOpenBorrow()) {//����ܴ�borrow.dat�ļ���ִ��{
		for (int i = 0; i <= temp.lengthBorrow(); i++)    //�ӵ�һ�е����һ�������
		{
			temp.readBorrow(i);							//������Ϣ��temp������	
			if (temp.getUserId() == userid)				//����ҵ���Ӧuserid��borrow������
			{
				int flag = 1;//flag=1��־����
				for (int t = 0; t < borrowmax; t++)//��borrowid[]��ÿ�����в鿴�Ƿ�Ϊ0
				{
					if (temp.getBookId()[t] == 0) //Ϊ0��flag��0
						flag = 0;
				}
				if (flag == 1)//���flag������1����˵��borrowid[]������ȫ��������
				{
					cout << "���ȹ黹�Ѿ����ĵ�ͼ�飡ÿ�˽���ͬʱ����" << BORROWMAX << "��ͼ�飡" << endl;
					return false;
				}
				// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
				struct tm t;  //tm�ṹָ��
				time_t now;   //����time_t���ͱ���
				time(&now);    //��ȡϵͳ���ں�ʱ��
				localtime_s(&t, &now);  //��ȡ�������ں�ʱ��
				int borrowtime = (1900 + t.tm_year) * 10000 + (1 + t.tm_mon) * 100 + (t.tm_mday);//�õ���ǰʱ�䵱����ʱ��


				//������������洢borrow����Ķ�Ӧ���飬�Ա��ں�������borrow������Ϣ
				long long int lastBookid[BORROWMAX] = { 0 };
				int borrowtimeArray[BORROWMAX] = { 0 };

				for (int k = 0; k < borrowmax; k++)
				{
					if (temp.getBookId()[k] != 0)//�����Ϊ0����������Ϣ��ԭ��д��������
					{
						lastBookid[k] = temp.getBookId()[k];
						borrowtimeArray[k] = temp.getBorrowTime()[k];
					}
					else {//���Ϊ0����˵���˴�û�д���Ϣ��������ӽ��ļ�¼����id��time
						lastBookid[k] = bookid;
						borrowtimeArray[k] = borrowtime;
						break;
					}
				}

				//�޸Ĳ�д����˽����¼�������numer+1,������������������Ϣ
				temp.changeBorrow(userid, temp.getName(), temp.getNumber() + 1, lastBookid, borrowtimeArray);
				temp.writeBorrow(i);


				//���History.dat��Ϣ
				Book book = base.idFindBook(bookid);//������������õ��������
				base.changeBook(book.getId(), book.getName(), book.getAuthor(), book.getLocation(), book.getPress(), book.getPublishTime(), book.getHoldNum(), book.getAvailNum() - 1);
				base.addHistory(userid, temp.getName(), bookid, book.getName(), borrowtime, -1);//�����Ϣ
				cout << "����ɹ����뼰ʱ�黹��" << endl;
				break;

			}
		}
	}
	else {
		cout << "�޷���Borrow�ļ���������" << endl;	cout << endl;
		return false;
	}
	return true;
}

bool Base::deleteBorrow(int userid, long long int bookid) {
	//@wjq
	//ɾȥBorrow.dat������Ϣ
	int borrowmax = BORROWMAX;
	Borrow temp;
	Base base;
	Book book;
	if (temp.canOpenBorrow()) {//����ܴ�borrow.dat��ִ��{
		for (int i = 0; i < temp.lengthBorrow(); i++)
		{
			temp.readBorrow(i);//�ӵ�һ�ж������һ��
			if (temp.getUserId() == userid)//����ҵ���Ӧuserid��borrow������ִ��{
			{
				int flag = 1;//flag=1��־δ�ҵ���bookid
				for (int t = 0; t < borrowmax; t++)
				{
					if (temp.getBookId()[t] == bookid)//�ӵ�һ�������һ����ʼ�ж��Ƿ����bookid����������bookid=0��־�ҵ�
						flag = 0;
				}
				if (flag == 1)//��δ�ҵ���
				{
					cout << "���û�δ�����Ĵ��飡" << endl;
					return false;
				}
				// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
				struct tm t;  //tm�ṹָ��
				time_t now;   //����time_t���ͱ���
				time(&now);    //��ȡϵͳ���ں�ʱ��
				localtime_s(&t, &now);  //��ȡ�������ں�ʱ��
				int returntime = (1900 + t.tm_year) * 10000 + (1 + t.tm_mon) * 100 + (t.tm_mday);//ϵͳ��ǰʱ�䵱����ʱ��

				//�������borrow����ļ�¼����������޸���
				long long int lastBookid[BORROWMAX] = { 0 };
				int lastBorrowtime[BORROWMAX] = { 0 };
				int tempborrowtime = 0;

				int flag2 = 0;
				for (int k = 0; k < borrowmax; k++)
				{
					if (temp.getBookId()[k] == bookid && flag2 == 0) { //flag2�������ǣ����ĳ��ͬʱ��������һ�����飬�ж������ֲ������Ƿ��Ѿ�����һ����
						//���Ҫ�����鱾��bookid�������е�һ�����һ�δ�������bookid��Ϊ0����borrowtime��Ϊ0��
						tempborrowtime = temp.getBorrowTime()[k];//tempborrowtime�����޸�history.dat��Ϣʱ�ã�����Ļ��Ͳ�֪������ʱ���Ƕ��٣���Ϊ��Ϊ��0
						lastBookid[k] = 0;
						lastBorrowtime[k] = 0;
						flag2 = 1;
					}
					else {  //�������Ҫ�������bookid�����Դ�ԭ����
						lastBookid[k] = temp.getBookId()[k];
						lastBorrowtime[k] = temp.getBorrowTime()[k];
					}	
				}

				//�޸�д����˽����¼
				book = base.idFindBook(bookid);
				base.changeBook(book.getId(), book.getName(), book.getAuthor(), book.getLocation(), book.getPress(), book.getPublishTime(), book.getHoldNum(), book.getAvailNum() + 1);
				temp.changeBorrow(userid, temp.getName(), temp.getNumber() - 1, lastBookid, lastBorrowtime);
				temp.writeBorrow(i);

				//�޸�History.dat��Ӧ��Ϣ��returntime��-1��Ϊreturntime
				Book book = base.idFindBook(bookid);
				base.changeHistory(userid, temp.getName(), bookid, book.getName(), tempborrowtime, returntime);
				cout << "����ɹ���" << endl;
				break;

			}
		}
	}
	else {
		cout << "�޷���Borrow�ļ���������" << endl;	cout << endl;
		return false;
	}
	return true;
}


/********************************************/
/***********History�Ļ�������****************/
//�����û�id�����鱾id�ж���ʷ������Ϣhistory.bat���Ƿ��Ѿ������й���Ϣ,���ҵ��˷���true�����򷵻�false
int Base::canFindHistory(int userid, long long int bookid) {           //@ljz
	if (userid != NULL && bookid == NULL)
	{
		History h;
		int n = 0;
		while (n < h.lengthHistory())
		{
			h.readHistory(n);
			n++;
			if (h.getUserId() == userid)
				return n;
		}
	}
	else if (bookid != NULL && userid == NULL)
	{
		History h;
		int n = 0;
		while (n < h.lengthHistory())
		{
			h.readHistory(n);
			n++;
			if (h.getBookId() == bookid)
				return n;
		}
	}
	else
		return -2; //�˴�Ϊ�����ʽ���󣬶���û���ҵ�
	return -1;
}
//�����û�id�����鱾id�����û���Ϣ��������User����
History Base::findHistory(int userid, char name[USERNAMESIZE]) {      //@ljz
	History h;
	int n = 0;
	if (userid != NULL && name == NULL)
	{
		while (n < h.lengthHistory())
		{
			h.readHistory(n);
			n++;
			if (h.getUserId() == userid)
				return h;
		}
		cout << "û���ҵ���ǰ��¼" << endl;	cout << endl;
	}
	else if (name != NULL && userid == NULL)
	{
		while (n < h.lengthHistory())
		{
			h.readHistory(n);
			n++;
			if (strcmp(h.getUserName(), name) == 0)
				return h;
		}
		cout << "û���ҵ���ǰ��¼" << endl;	cout << endl;
	}
	else if (userid != NULL && name != NULL)
	{
		while (n < h.lengthHistory())
		{
			h.readHistory(n);
			n++;
			if (h.getUserId() == userid && strcmp(h.getUserName(), name) == 0)
				return h;
		}
		cout << "û���ҵ���ǰ��¼" << endl;	cout << endl;
	}
}

//��ʾ��ʷ���ļ�¼
void Base::showHistoryList() {    //@ljz
	History h;
	int n = 0;
	while (n < h.lengthHistory())
	{
		h.readHistory(n);
		h.displayHistory();
		n++;
	}
}

//������ʷ�����¼history.bat
void Base::addHistory(int userid, char username[USERNAMESIZE], long long int bookid, char bookname[BOOKNAMESIZE], int borrowtime, int returntime) {
	//@wjq
	History temp = History();
	if (temp.canOpenHistory()) {
		temp = History(userid, username, bookid, bookname, borrowtime, returntime);
		temp.writeHistory(-1);
	}
	else {
		cout << "�޷���History�ļ���������" << endl; cout << endl;
	}

}

//�޸���ʷ�����¼history.bat ��������ĵģ�����жϵ�userid��bookid��������ȲŸ���
void Base::changeHistory(int userid, char username[USERNAMESIZE], long long int bookid, char bookname[BOOKNAMESIZE], int borrowtime, int returntime) {
	//@wjq
	History temp = History();
	if (temp.canOpenHistory()) {
		for (int i = 0; i < temp.lengthHistory(); i++)
		{
			temp.readHistory(i);
			if (temp.getUserId() == userid && temp.getBookId() == bookid)
			{
				temp.changeHistory(userid, username, bookid, borrowtime, returntime);
				temp.writeHistory(i);
				break;
			}
		}
	}
	else {
		cout << "�޷���History�ļ���������" << endl; cout << endl;
	}
}

bool Base::checkType(string s, int i) { //i=0,1,2
	if (i == 0) {
		//�������ĺϷ��ԣ�����ֻ�ܰ������ֺ���ĸ
		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= 48 && s[j] <= 57) continue;
			else if (s[j] >= 65 && s[j] <= 90) continue;
			else if (s[j] >= 97 && s[j] <= 122) continue;
			else return false;
		}
		return true;
	}
	else if (i == 1) {
		//intֻ�ܺ�����
		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= 48 && s[j] <= 57) continue;
			else return false;
		}
		return true;
	}
	else if (i == 2) {
		//����Ƿ��пո����򷵻�false
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 32) return false;
		}
		return true;
	}
}

long long int Base::str_to_int(char* str)
{///���ַ������е��ַ�ת��Ϊ���ͱ���������
	long long int y = 0;
	for (int i = 0; i < (int)strlen(str); i++)///��ǿ��ת��ȥ���ᷢ����ʾwarning
	//rlen����ֵ���޷��������޷�ֱ�Ӻ�int(�з�����)�Ƚϣ��޷���������ת��Ϊ�з�����
	{
		y = y * 10 + (str[i] - 48);///�˴�Ҫ��48(ASCLL����48Ϊ����0)
	}                             ///�ַ����洢����ASCLL��
	return y;
}
bool Base::isCharLength(char* s, int l) {  //�ж��ַ��������Ƿ񳬳���Χ������false��ʾ����
	int len = (int)strlen(s);
	if (len > l) {
		return false;
	}
	else {
		return true;
	}
}

int Base::calculateTime(int time1, int time2) {
	int monthNum[13][2] = { {0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31} };
	int year1, year2;
	int month1, month2;
	int day1, day2;
	year1 = time1 / 10000;
	year2 = time2 / 10000;
	month1 = time1 % 10000 / 100;
	month2 = time2 % 10000 / 100;
	day1 = time1 % 100;
	day2 = time2 % 100;
	int sum = 1;
	while (year1 < year2 || month1 < month2 || day1 < day2) {
		day1++;
		if (day1 > monthNum[month1][isLeapYear(year1)]) {
			month1++;
			day1 = 1;
		}
		if (month1 > 12) {
			year1++;
			month1 = 1;
		}
		sum++;
	}
	return sum;
}
bool Base::isLeapYear(int year) {
	return((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

/*************************************/



template <class Type>
Type stringToNum(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

//��.csv�ļ���д������
void Base::writeExcel(char* filename, Book b)
{
	ofstream oFile;
	//��Ҫ������ļ�
	oFile.open(filename, ios::in | ios::app); // �����ͺ����׵����һ����Ҫ��excel �ļ�
	oFile << b.getId() << "," << b.getName() << "," << b.getAuthor() << "," << b.getLocation() << "," << b.getPress() << "," << b.getPublishTime() << "," << b.getHoldNum() << "," << b.getAvailNum() << endl;
	oFile.close();
}

//��.csv�ļ��ж�������
Book Base::readExcel(char* filename, int n)
{
	Book b;
	char author[AUTHORSIZE];
	ifstream inFile(filename, ios::in);
	string lineStr;
	for (int m = 0; m < n - 1; m++) {
		getline(inFile, lineStr);
	}
	getline(inFile, lineStr);
	int j = -1;

	// ��ɶ�ά��ṹ
	stringstream ss(lineStr);
	string temp;
	// ���ն��ŷָ�
	while (getline(ss, temp, ','))
	{
		j++;

		if (j == 0)
		{
			int id = stringToNum<int>(temp);
			b.changeBook(id, b.getName(), b.getAuthor(), b.getLocation(), b.getPress(), b.getPublishTime(), b.getHoldNum(), b.getAvailNum());

		}
		if (j == 1)
		{
			char name[BOOKNAMESIZE];
			strcpy(name, temp.c_str());
			b.changeBook(b.getId(), name, b.getAuthor(), b.getLocation(), b.getPress(), b.getPublishTime(), b.getHoldNum(), b.getAvailNum());
		}
		if (j == 2)
		{
			char author[AUTHORSIZE];
			strcpy(author, (char*)temp.c_str());
			b.changeBook(b.getId(), b.getName(), author, b.getLocation(), b.getPress(), b.getPublishTime(), b.getHoldNum(), b.getAvailNum());
		}
		if (j == 3)
		{
			char location[LOCATIONSIZE];
			strcpy(location, temp.c_str());
			b.changeBook(b.getId(), b.getName(), b.getAuthor(), location, b.getPress(), b.getPublishTime(), b.getHoldNum(), b.getAvailNum());
		}
		if (j == 4)
		{
			char press[PRESSSIZE];
			strcpy(press, temp.c_str());
			b.changeBook(b.getId(), b.getName(), b.getAuthor(), b.getLocation(), press, b.getPublishTime(), b.getHoldNum(), b.getAvailNum());
		}
		if (j == 5)
		{
			int publishtimel;
			publishtimel = stringToNum<int>(temp);
			b.changeBook(b.getId(), b.getName(), b.getAuthor(), b.getLocation(), b.getPress(), publishtimel, b.getHoldNum(), b.getAvailNum());
		}
		if (j == 6)
		{
			int holdnum;
			holdnum = stringToNum<int>(temp);
			b.changeBook(b.getId(), b.getName(), b.getAuthor(), b.getLocation(), b.getPress(), b.getPublishTime(), holdnum, b.getAvailNum());
		}
		if (j == 7)
		{
			int availnum;
			availnum = stringToNum<int>(temp);

			b.changeBook(b.getId(), b.getName(), b.getAuthor(), b.getLocation(), b.getPress(), b.getPublishTime(), b.getHoldNum(), availnum);
		}

	}
	inFile.close();
	return b;
}



//�����ļ�history.bat�ļ�¼����������ļ���ʧ�ܣ�����-1
int Base::lengthExcel(char* filename) {
	int num = 0;
	fstream out;
	char buffer[256];
	out.open(filename, ios::in);
	FILE* fp;
	fp = fopen(filename, "rb");
	if ((fp == NULL)) {
		cout << "�޷��򿪴��ļ���" << endl;
		return -1;
	}

	while (!out.eof()) {
		out.getline(buffer, 256, '\n');//getline(char *,int,char) ��ʾ�����ַ��ﵽ256�����������оͽ���
		num++;
	}
	out.close();
	return num;
}
