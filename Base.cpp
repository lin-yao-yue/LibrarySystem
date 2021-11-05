
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

//书本ISBN码校验，保证ISBN码是合法的
bool Base::checkISBN(long long int id) {
	if ((id > 999999999 && id < 10000000000) || (id > 999999999999 && id < 10000000000000))
		return 1;
	else
		return 0;
}

/*********Book的基本操作**********/
//判断图书是否已经存在于书库中（遍历整个书库文件），通过编号、书名、作者进行查找,查找到了返回true，否则返回false
int Base::canFindBook(long long int bookid, char name[BOOKNAMESIZE], char author[AUTHORSIZE]) {     //@ljz
	//例如，当以bookid搜索时，name和author传入为null，自行补充
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
		return -2; //此处为输入格式错误，而非没有找到
	}
		
	return -1;//没有找到此书
}

//根据图书id返回该书的对象，唯一，只会搜索出一个符合搜索条件的对象
Book Base::idFindBook(long long int bookid) {   //@ljz
	Book b;
	//遍历文件，找到指定书籍，并将相关信息填入book中
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

//根据书名或者作者进行查找，可能有多个搜索结果
//所有返回的是一个指针可创建一个类的数组，然后返回指向该类组的头指针
//booknum是一个引用变量，指符合搜索条件的书本数量，函数结束前最后要将其更改为类组的数量（即符合条件的数组的数量）
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


//显示所有的图书及其信息
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

//添加图书（逐本图书添加）
//传参编号、书名、作者、书本存放位置、出版社、出版时间、添加的数量
//判断书库中此书是否已经存在，若存在则改变源文件的馆藏数量，若不存在则增加此书
int Base::addBook(long long int bookid, char name[USERNAMESIZE], char author[AUTHORSIZE], char location[LOCATIONSIZE], char press[PRESSSIZE], int publishtime, int addnum) {
	//@fy
	Book book;
	int line = canFindBook(bookid, nullptr, nullptr);
	if (line != -1) {//如果找到相同id的书
		book = idFindBook(bookid);
		if( book.getHoldNum() != 0){//且馆藏数量不为0则在原基础上添加

			if (strcmp(name, book.getName()) == 0 && strcmp(author, book.getAuthor()) == 0) {
				book.changeBook(bookid, name, author, location, press, publishtime,
					book.getHoldNum() + addnum, book.getAvailNum() + addnum);
				book.writeBook(line - 1);
			}
			else {
				cout << endl;
				cout << "id输入重复，请重新输入" << endl;
				cout << endl;
				return -1;
			}
	    }
		else {
			cout << "输入id重复！" << endl; 
			return -1;//id为已经删除书的id
		}
	}
	else {
		//默认availnum等于holdnum
		book.changeBook(bookid, name, author, location, press, publishtime, addnum, addnum);
		book.writeBook(-1);
	}
	cout << "添加成功" << endl;
	return 1;
}


//修改图书，修改书库中图书的各项信息，但不能!!!修改编号
//传参为编号、新书名、新作者、新书本存放位置、新出版社、新出版时间、新的馆藏数量、新的可借阅数量
//根据编号判断该书是否存在，若存在则修改该书库中该书的信息进行修改
int Base::changeBook(long long int bookid, char newname[USERNAMESIZE], char newauthor[AUTHORSIZE], char newloation[LOCATIONSIZE], char newpress[PRESSSIZE], int newpublishtime, int newhold, int newavailable) {
	//@fy
	//全部传参都修改，控制台输入由main函数控制，此函数只需要把传参的数据改入用户库中
	Book tempBook;
	int line = canFindBook(bookid, nullptr, nullptr);

	if (line != -1) {
		tempBook = idFindBook(bookid);
		if (tempBook.getHoldNum() != 0)//表示该书没有被删，存在
		{
			tempBook.changeBook(bookid, newname, newauthor, newloation, newpress, newpublishtime, newhold, newavailable);
			tempBook.writeBook(line - 1);
			//修改成功返回1
			return 1;
		}
		else
		{
			cout << "该书已经删除，无法修改！" << endl; cout << endl;
			return -2;
		}
	}
	else {
		cout << endl;
		cout << "没有找到要修改的图书"<<endl;
		cout << endl;
		return -1;
	}

}

//删除图书，传参为图书编号，删除书库中图书编号所指的书本信息
//根据编号判断该书是否存在，若存在则对该书信息进行删除
int Base::deleteBook(long long int bookid) {
	//@fy
	Book tempBook;
	int line = canFindBook(bookid, nullptr, nullptr);
	if (line != -1) {//找到该书id
		tempBook = idFindBook(bookid);
		if (tempBook.getAvailNum() == tempBook.getHoldNum()&& tempBook.getHoldNum()!=0) {//如果没有被借出且该书未被删
			//holdNum，availNum改为0
			tempBook.changeBook(bookid, tempBook.getName(), tempBook.getAuthor(),tempBook.getLocation(), tempBook.getPress(), tempBook.getPublishTime(), 0, 0);
			tempBook.writeBook(line - 1);
			cout << endl;
			cout << "删除成功"<<endl;	
			cout << endl;
			return 1;
		}
		else if(tempBook.getAvailNum() == tempBook.getHoldNum() && tempBook.getHoldNum() == 0){////如果没有被借出且该书被删
			cout << "该书已被删除！" << endl; cout << endl;
			return -3;
		}
		else {//如果被借出
			cout << endl;
			cout << "该书已被借阅，无法删除"<<endl;
			cout << endl;
			return -2;
		}

	}
	else {
		cout << endl;
		cout << "没有找到要删除的图书";	cout << endl;	cout << endl;
		return -1;
	}
}




/***********************************/

/*************User的基本操作*********/

// yk改 ：我把寻找用户的行数都-1，因为n从0开始，以便覆盖写入时传n不会出错，和别人统一 

//判断图书是否已经存在于用户库中,查找到了返回true，否则返回false
int Base::canFindUser(int userid, char name[USERNAMESIZE]) {           //@ljz
	//例如，当以userid搜索时，name传入为null，自行补充
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
		return -2; //此处为输入格式错误，而非没有找到
	return -1;

}

//根据用户id查找，并返回唯一对象

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
	cout << "没有找到当前用户！" << endl;	cout << endl;
}

//根据姓名进行查找，可能有多个搜索结果
//所有返回的是一个指针可创建一个类的数组，然后返回指向该类组的头指针
//usernum是一个引用变量，指符合搜索条件的书本数量，函数结束前最后要将其更改为类组的数量（即符合条件的数组的数量）
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

//显示所有的用户及其信息
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


//添加用户(逐个用户添加）
//传参账号、密码、年级、姓名、性别、电话、用户类型
//判断此用户是否已经存在，若不存在则增加此书
void Base::addUser(int userid, char password[PASSWORDSIZE], int grade, char name[USERNAMESIZE], int gender, char telephone[TELEPHONESIZE], int role) {
	//@fy
	User user;
	Borrow borrow = Borrow();
	int line = canFindUser(userid, nullptr);
	if (line != -1) {//如果找到了用户
		user = idFindUser(userid);
		if (user.getState() != -1) {
			cout << endl;
			cout << "该用户已存在" << endl;
			cout << endl;
		}
		else {//该id用户已被删除
			cout << "输入id重复" << endl;
		}
	}
	else {
		user.changeUser(userid, password, grade, name, gender, telephone, role, 0);
		user.writeUser(-1);
		borrow.changeBorrow(userid, name, 0, borrow.getBookId(), borrow.getBorrowTime());
		borrow.writeBorrow(-1);
		cout << endl;
		cout << "增加学生成功" << endl;
		cout << "密码默认为00000000" << endl;
		cout << endl;
	}
}

//修改用户，修改用户中图书的各项信息，但不能修改编号和密码
//传参为编号、新密码、新年级、新姓名、新性别、新电话、新用户类型
//根据编号判断该用户是否存在，若存在则修改该用户库中该用户信息进行修改
int Base::changeUser(int userid, int newgrade, char newname[USERNAMESIZE], int newgender, char newtelephone[TELEPHONESIZE], int newrole) {
	//全部传参都修改，控制台输入由main函数控制，此函数只需要把传参的数据改入用户库中
	//@fy
	User user;
	int line = canFindUser(userid, nullptr);
	if (line != -1) {//如果找到了id用户
		user = idFindUser(userid);
		if (user.getState() != -1)//如果没有被删除
		{
			user.changeUser(userid, user.getPassword(), newgrade, newname, newgender, newtelephone, newrole, 0);
			user.writeUser(line - 1);
			cout << "修改用户成功" << endl;
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
			return 1;
		}
		else {//如果该用户被删除
			cout << "已删除用户不能被修改" << endl;
		}
		
	}
	else {
		cout << endl;
		cout << "要修改的用户不存在";	cout << endl;	cout << endl;
		return -1;
	}
}

//删除用户，传参为用户编号，
//根据编号判断该用户是否存在，若存在则对该用户信息进行删除
void Base::deleteUser(int userid) {
	User user;
	Borrow borrow;
	int borrowline;
	int borrowmax = BORROWMAX;
	int userline = canFindUser(userid, nullptr);
	if (userline != -1) {//如果找到该id用户
		user = idFindUser(userid);
		if (user.getState() !=-1) {   //如果用户没有被注销
			borrowline = canFindBorrow(user.getId());
			borrow = findBorrow(user.getId());
			int borrowflag = 0;
			if (borrow.getNumber() == 0) {
				user.changeUser(user.getId(), user.getPassword(), user.getGrade(), user.getName(),
					user.getGender(), user.getTelephone(), user.getRole(), -1);
				user.writeUser(userline - 1);
				cout << "删除成功";	cout << endl;	cout << endl;
			}
			else {
				cout << "删除用户有借书记录，无法删除";	cout << endl;	cout << endl;
			}
			

		}
		else {
			cout << "该用户已经注销，无法重复操作！" << endl;	cout << endl;
		}
	}
	else {
		cout << "要删除的用户不存在";	cout << endl;	cout << endl;
	}

}
/**  对main函数的作用
若使用在登录后修改自己的密码，则传参id为全局变量USERID
若使用在管理员修改别人的密码，则传参id为用户控制台输入的userid
参数oldpassword是再主函数用户控制台输入的原密码
**/
//修改用户密码:参数传入某学生id，通过此id修改此学生的密码
//修改前要先需要
void Base::changePassword(int userid, char newPassword[PASSWORDSIZE]) {
	//@fy
	//oldpassword为在改密码前用户控制台输入的原密码，当核验原密码输入没有错误后才可以进行修改
	User user;
	int line = canFindUser(userid, nullptr);
	if (line != -1) {
		user = idFindUser(userid);
		user.changeUser(userid, newPassword, user.getGrade(), user.getName(), user.getGender(), user.getTelephone(), user.getRole(), 0);
		user.writeUser(line-1);
		cout << "修改密码成功";	cout << endl;	cout << endl;
	}
}

/*************************************/

/***********Borrow的基本操作*************/
//判断借阅信息是否存在于借阅库中，通过用户id查找
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

//根据用户id查找此用户借书记录，并返回borrow对象
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
	cout << "没有找到当前记录" << endl;	cout << endl;
}

//显示当前所有借书记录
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

			if (b.getBookId()[k] != 0)//如果不为0，则存的有信息输出G
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
	//添加Borrow.dat信息
	int borrowmax = BORROWMAX;
	Base base;
	Borrow temp = Borrow();
	if (temp.canOpenBorrow()) {//如果能打开borrow.dat文件则执行{
		for (int i = 0; i <= temp.lengthBorrow(); i++)    //从第一行到最后一行逐个查
		{
			temp.readBorrow(i);							//存入信息到temp对象中	
			if (temp.getUserId() == userid)				//如果找到对应userid的borrow对象则
			{
				int flag = 1;//flag=1标志已满
				for (int t = 0; t < borrowmax; t++)//对borrowid[]中每个进行查看是否为0
				{
					if (temp.getBookId()[t] == 0) //为0则将flag置0
						flag = 0;
				}
				if (flag == 1)//如果flag还等于1，则说明borrowid[]中满，全存了数据
				{
					cout << "请先归还已经借阅的图书！每人仅可同时借阅" << BORROWMAX << "本图书！" << endl;
					return false;
				}
				// 基于当前系统的当前日期/时间
				struct tm t;  //tm结构指针
				time_t now;   //声明time_t类型变量
				time(&now);    //获取系统日期和时间
				localtime_s(&t, &now);  //获取当地日期和时间
				int borrowtime = (1900 + t.tm_year) * 10000 + (1 + t.tm_mon) * 100 + (t.tm_mday);//得到当前时间当借阅时间


				//声明两个数组存储borrow里面的对应数组，以便于后续更改borrow对象信息
				long long int lastBookid[BORROWMAX] = { 0 };
				int borrowtimeArray[BORROWMAX] = { 0 };

				for (int k = 0; k < borrowmax; k++)
				{
					if (temp.getBookId()[k] != 0)//如果不为0，则存的有信息，原样写入数组中
					{
						lastBookid[k] = temp.getBookId()[k];
						borrowtimeArray[k] = temp.getBorrowTime()[k];
					}
					else {//如果为0，则说明此处没有存信息，可以添加借阅记录包括id与time
						lastBookid[k] = bookid;
						borrowtimeArray[k] = borrowtime;
						break;
					}
				}

				//修改并写入个人借书记录，借书的numer+1,传入两个数组里新信息
				temp.changeBorrow(userid, temp.getName(), temp.getNumber() + 1, lastBookid, borrowtimeArray);
				temp.writeBorrow(i);


				//添加History.dat信息
				Book book = base.idFindBook(bookid);//这个对象用来得到书的名字
				base.changeBook(book.getId(), book.getName(), book.getAuthor(), book.getLocation(), book.getPress(), book.getPublishTime(), book.getHoldNum(), book.getAvailNum() - 1);
				base.addHistory(userid, temp.getName(), bookid, book.getName(), borrowtime, -1);//添加信息
				cout << "借书成功！请及时归还！" << endl;
				break;

			}
		}
	}
	else {
		cout << "无法打开Borrow文件！请重试" << endl;	cout << endl;
		return false;
	}
	return true;
}

bool Base::deleteBorrow(int userid, long long int bookid) {
	//@wjq
	//删去Borrow.dat借阅信息
	int borrowmax = BORROWMAX;
	Borrow temp;
	Base base;
	Book book;
	if (temp.canOpenBorrow()) {//如果能打开borrow.dat则执行{
		for (int i = 0; i < temp.lengthBorrow(); i++)
		{
			temp.readBorrow(i);//从第一行读到最后一行
			if (temp.getUserId() == userid)//如果找到对应userid的borrow对象，则执行{
			{
				int flag = 1;//flag=1标志未找到此bookid
				for (int t = 0; t < borrowmax; t++)
				{
					if (temp.getBookId()[t] == bookid)//从第一个到最后一个开始判断是否相等bookid，如果相等则bookid=0标志找到
						flag = 0;
				}
				if (flag == 1)//仍未找到则
				{
					cout << "该用户未曾借阅此书！" << endl;
					return false;
				}
				// 基于当前系统的当前日期/时间
				struct tm t;  //tm结构指针
				time_t now;   //声明time_t类型变量
				time(&now);    //获取系统日期和时间
				localtime_s(&t, &now);  //获取当地日期和时间
				int returntime = (1900 + t.tm_year) * 10000 + (1 + t.tm_mon) * 100 + (t.tm_mday);//系统当前时间当还书时间

				//用来存放borrow里面的记录，方便后续修改用
				long long int lastBookid[BORROWMAX] = { 0 };
				int lastBorrowtime[BORROWMAX] = { 0 };
				int tempborrowtime = 0;

				int flag2 = 0;
				for (int k = 0; k < borrowmax; k++)
				{
					if (temp.getBookId()[k] == bookid && flag2 == 0) { //flag2的作用是，如果某人同时借了两本一样的书，判断在这轮操作中是否已经还了一本了
						//如果要换的书本的bookid与数组中的一样而且还未还，则把bookid改为0，把borrowtime改为0，
						tempborrowtime = temp.getBorrowTime()[k];//tempborrowtime用来修改history.dat信息时用，不存的话就不知道借阅时间是多少，因为改为了0
						lastBookid[k] = 0;
						lastBorrowtime[k] = 0;
						flag2 = 1;
					}
					else {  //如果不是要还的书的bookid，则仍存原来的
						lastBookid[k] = temp.getBookId()[k];
						lastBorrowtime[k] = temp.getBorrowTime()[k];
					}	
				}

				//修改写入个人借书记录
				book = base.idFindBook(bookid);
				base.changeBook(book.getId(), book.getName(), book.getAuthor(), book.getLocation(), book.getPress(), book.getPublishTime(), book.getHoldNum(), book.getAvailNum() + 1);
				temp.changeBorrow(userid, temp.getName(), temp.getNumber() - 1, lastBookid, lastBorrowtime);
				temp.writeBorrow(i);

				//修改History.dat对应信息的returntime从-1改为returntime
				Book book = base.idFindBook(bookid);
				base.changeHistory(userid, temp.getName(), bookid, book.getName(), tempborrowtime, returntime);
				cout << "还书成功！" << endl;
				break;

			}
		}
	}
	else {
		cout << "无法打开Borrow文件！请重试" << endl;	cout << endl;
		return false;
	}
	return true;
}


/********************************************/
/***********History的基本操作****************/
//根据用户id或者书本id判断历史借阅信息history.bat中是否已经存在有关信息,查找到了返回true，否则返回false
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
		return -2; //此处为输入格式错误，而非没有找到
	return -1;
}
//根据用户id或者书本id查找用户信息，并返回User对象
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
		cout << "没有找到当前记录" << endl;	cout << endl;
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
		cout << "没有找到当前记录" << endl;	cout << endl;
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
		cout << "没有找到当前记录" << endl;	cout << endl;
	}
}

//显示历史借阅记录
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

//增加历史借书记录history.bat
void Base::addHistory(int userid, char username[USERNAMESIZE], long long int bookid, char bookname[BOOKNAMESIZE], int borrowtime, int returntime) {
	//@wjq
	History temp = History();
	if (temp.canOpenHistory()) {
		temp = History(userid, username, bookid, bookname, borrowtime, returntime);
		temp.writeHistory(-1);
	}
	else {
		cout << "无法打开History文件！请重试" << endl; cout << endl;
	}

}

//修改历史借书记录history.bat 按正序更改的，如果判断到userid或bookid两个都相等才更改
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
		cout << "无法打开History文件！请重试" << endl; cout << endl;
	}
}

bool Base::checkType(string s, int i) { //i=0,1,2
	if (i == 0) {
		//检测密码的合法性，密码只能包含数字和字母
		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= 48 && s[j] <= 57) continue;
			else if (s[j] >= 65 && s[j] <= 90) continue;
			else if (s[j] >= 97 && s[j] <= 122) continue;
			else return false;
		}
		return true;
	}
	else if (i == 1) {
		//int只能含数字
		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= 48 && s[j] <= 57) continue;
			else return false;
		}
		return true;
	}
	else if (i == 2) {
		//检查是否有空格，有则返回false
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 32) return false;
		}
		return true;
	}
}

long long int Base::str_to_int(char* str)
{///将字符数组中的字符转换为整型变量的数字
	long long int y = 0;
	for (int i = 0; i < (int)strlen(str); i++)///把强制转换去掉会发现提示warning
	//rlen返回值是无符号数，无法直接和int(有符号数)比较，无符号数可以转换为有符号数
	{
		y = y * 10 + (str[i] - 48);///此处要减48(ASCLL码中48为数字0)
	}                             ///字符串存储的是ASCLL码
	return y;
}
bool Base::isCharLength(char* s, int l) {  //判断字符串长度是否超出范围，返回false表示超出
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

//向.csv文件中写入数据
void Base::writeExcel(char* filename, Book b)
{
	ofstream oFile;
	//打开要输出的文件
	oFile.open(filename, ios::in | ios::app); // 这样就很容易的输出一个需要的excel 文件
	oFile << b.getId() << "," << b.getName() << "," << b.getAuthor() << "," << b.getLocation() << "," << b.getPress() << "," << b.getPublishTime() << "," << b.getHoldNum() << "," << b.getAvailNum() << endl;
	oFile.close();
}

//从.csv文件中读出数据
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

	// 存成二维表结构
	stringstream ss(lineStr);
	string temp;
	// 按照逗号分隔
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



//返回文件history.bat的记录条数，如果文件打开失败，返回-1
int Base::lengthExcel(char* filename) {
	int num = 0;
	fstream out;
	char buffer[256];
	out.open(filename, ios::in);
	FILE* fp;
	fp = fopen(filename, "rb");
	if ((fp == NULL)) {
		cout << "无法打开此文件！" << endl;
		return -1;
	}

	while (!out.eof()) {
		out.getline(buffer, 256, '\n');//getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束
		num++;
	}
	out.close();
	return num;
}
