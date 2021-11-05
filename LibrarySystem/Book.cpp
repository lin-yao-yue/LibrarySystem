//Book.cpp ===============================================

#include"book.h"
#include"student.h"   /*****************已改**************/
#include"main.h"
#include<string>

Book::Book()
{
	Id = "0";
	Name = "empty";
	Author = "empty";
	Cat = "empty";
	Location = "empty";
	Addr = "empty";
	Time = "empty";
	Price = "0";
}

Book::~Book() {}
Book::Book(string a, string b, string c, string d, string e, string f, string g, string h)
{

	Id = a;
	Name = b;
	Author = c;
	Cat = d;
	Location = e;
	Addr = f;
	Time = g;
	Price = h;
}
///
string Book::get_Id()
{
	return Id;
}
string Book::get_Name()
{
	return Name;
}
string Book::get_Author()
{
	return Author;
}
string Book::get_Cat()
{
	return Cat;
}
string Book::get_Location()
{
	return Location;
}
string Book::get_Addr()
{
	return Addr;
}
string Book::get_Time()
{
	return Time;
}
string Book::get_Price()
{
	return Price;
}

void Book::change(string a, string b, string c, string d, string e, string f, string g, string h)
{
	Id = a;
	Name = b;
	Author = c;
	Cat = d;
	Location = e;
	Addr = f;
	Time = g;
	Price = h;
}

void Book::display()
{
	//对后面紧跟的输出设置域宽
	cout << "*" << setw(10) << Id;
	cout << "   *" << setw(10) << Name;
	cout << "   *" << setw(10) << Author;
	cout << "   *" << setw(10) << Cat;
	cout << "   *" << setw(10) << Location;
	cout << "   *" << setw(10) << Addr;
	cout << "   *" << setw(10) << Time;
	cout << "   *" << setw(10) << Price << "*";
	cout << endl;//一条纪录						

}

//可以设置为静态
int Book::length()
{
	int i = 0;
	string temp;
	ifstream fin("book.txt");
	while (getline(fin, temp))
		i += 1;
	fin.close();
	return i;
}

bool Book::canopen()
{
	ifstream fin1("book.txt");
	if (fin1)
		return 1;
	else
		return 0;
	fin1.close();
}

void Book::write()
{
	ofstream outfile("book.txt", ios::app);
	outfile << Id << "\t" << Name << "\t" << Author << "\t" << Cat << "\t" << Location << "\t" << Addr << "\t" << Time << "\t" << Price << "\t" << endl;
	outfile.close();
}

void Book::read(int n)
{
	int i = 0;
	//最多999行即999本书
	string temp, data[999], a[8];
	ifstream fin("book.txt");
	while (getline(fin, temp))
	{
		data[i] = temp;
		i += 1;
	}
	fin.close();
	//控制 流的输入，以空格来对流进行分隔
	istringstream stream(data[n]);
	for (i = 0; i < 8; i++)
	{
		a[i] = data[n].substr(0, data[n].find("\t"));
		data[n].erase(0, data[n].find("\t") + 1);
	}

	//是不是可以删掉
	Id = a[0];
	Name = a[1];
	Author = a[2];
	Cat = a[3];
	Location = a[4];
	Addr = a[5];
	Time = a[6];
	Price = a[7];

	//用输入流进行赋值
	stream >> Id >> Name >> Author >> Cat >> Location >> Addr >> Time >> Price;

}
