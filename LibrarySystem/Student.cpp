//Student.cpp ===========================================
#include"book.h"
#include"student.h"
#include"main.h"


Student::Student()
{
	id = 0;
	year = 0;
	name = "not given";
	password = "not given";
	gender = "not given";
	telephone = "not given";
	address = "not given";             //define the default constructor
}

Student::~Student() {}

Student::Student(int a, int b, string c, string d, string e, string f, string g)
{
	id = a;
	year = b;
	name = c;
	password = d;
	gender = e;
	telephone = f;
	address = g;                       //define the normal constructor
}

int Student::get_id()
{
	return id;
}

int Student::get_year()
{
	return year;
}

string Student::get_name()
{
	return name;
}

string Student::get_pass()
{
	return password;
}

string Student::get_gend()
{
	return gender;
}

string Student::get_tele()
{
	return telephone;
}

string Student::get_addr()
{
	return address;
}

vector<int> Student::get_book()
{
	return book;
}

void Student::change(int a, int b, string c, string d, string e, string f, string g)
{
	id = a;
	year = b;
	name = c;
	password = d;
	gender = e;
	telephone = f;
	address = g;
}

void Student::display()
{

	cout << setw(10) << name 
		<< setw(10) << id 
		<< setw(10) << year 
		<< setw(10) << gender 
		<< setw(12) << telephone 
		<< setw(10) << address 
		<< endl;


}

int Student::length()
{
	int i = 0;
	string temp;
	ifstream fin("student.txt");
	while (getline(fin, temp))
		i += 1;
	fin.close();
	return i;
}

bool Student::canopen()
{
	ifstream fin1("student.txt");
	ifstream fin2("mybook.txt");
	if (fin1&&fin2)
		return 1;
	else
		return 0;
	fin1.close();
	fin2.close();
}

void Student::write()
{
	ofstream fout("student.txt", ios::app);
	fout << id << "\t" << year << "\t" << name << "\t" << password << "\t" << gender << "\t" << telephone << "\t" << address << endl;
	fout.close();
}

void Student::read(int n)
{
	int i = 0;
	string temp, data[999], a[6];
	ifstream fin("student.txt");
	while (getline(fin, temp))
	{
		data[i] = temp;
		i += 1;
	}
	fin.close();
	istringstream stream(data[n]);
	
	//可删？
	for (i = 0; i < 6; i++)
	{
		data[n].erase(0, data[n].find("\t") + 1);
		a[i] = data[n].substr(0, data[n].find("\t"));
	}
	name = a[1];
	password = a[2];
	gender = a[3];
	telephone = a[4];
	address = a[5];

	stream >> id >> year >> name >> password >> gender >> telephone >> address;
}

void Student::write_book()
{
	int i, n, l = 0;
	string data[999], temp;
	ifstream fin("mybook.txt");
	while (getline(fin, temp))
	{
		data[l] = temp;
		l += 1;
	}
	fin.close();

	ofstream fout("mybook.txt");
	for (i = 0; i < l; i++)
	{
		istringstream stream(data[i]);
		stream >> n;
		//更新
		if (n == id)
		{
			fout << id;
			for (int i = 0; i < book.size(); i++)
				fout << "\t" << book[i] << "\t" << grade[i];
			fout << endl;
		}
		else
			//覆盖 
			fout << data[i] << endl;
	}
	fout.close();
}

void Student::read_book()
{
	int i = 0, x, y, n;
	string data[999], temp;
	ifstream fin("mybook.txt");
	while (getline(fin, temp))
	{
		data[i] = temp;
		i += 1;
	}
	fin.close();
	for (i = 0; i < 999; i++)
	{
		istringstream stream(data[i]);
		stream >> n;
		if (id == n)
			while (stream >> x >> y)
			{
				book.push_back(x);
				grade.push_back(y);
			}
	}
}

void Student::change_book(int a, int b)
{
	int i;
	for (i = 0; i < book.size(); i++)
		if (book[i] == a)
			grade[i] = b;
}

void Student::add_book(int a)
{
	book.push_back(a);
	grade.push_back(-1);
}

void Student::display_book()
{
	int i;
	for (i = 0; i < book.size(); i++)
	{
		cout << book[i] << "\t\t";
		if (grade[i] == -1)
			cout << "None." << endl;
		else
			cout << grade[i] << endl;
	}
}

void Student::add_student()
{
	//ios::app：　　　以追加的方式打开文件
	ofstream fout("mybook.txt", ios::app);
	fout << id << endl;
	fout.close();
}

void Student::sub_student()
{
	int i = 0, n, m, l;
	string data[999], temp;
	ifstream fin("mybook.txt");
	while (getline(fin, temp))
	{
		data[i] = temp;
		i += 1;
	}
	fin.close();
	l = i;
	for (i = 0; i < l; i++)
	{
		istringstream stream(data[i]);
		stream >> n;
		if (id == n)
			m = i;
	}
	ofstream fout("mybook.txt");
	for (i = 0; i < l; i++)
		if (i != m)
			fout << data[i] << endl;
	fout.close();
}

bool Student::is_same_book(int a)
{
	int i;
	bool success = 0;
	for (i = 0; i < book.size(); i++)
		if (book[i] == a)
			success = 1;
	return success;
}

