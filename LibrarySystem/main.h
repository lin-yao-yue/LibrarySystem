#include<iostream>
#include<string>
#include<vector>
#include"book.h"
#include"student.h"
#include <iomanip>
using namespace std;

void initialize();
bool is_administrator();
bool is_student(int *n);
void menu1();
void menu2();
void menu3();
void wrong_input();
void mag_book();
void mag_student();
void show_book_list();
void show_student_list();
void give_mark();
void change_password();
void choose_book(int n);
void my_book(int n);
void check_info(int n);

void can_open(Book a);
void can_open(Student a);

bool is_same_student_name(string n);
bool is_same_student_tele(string n);
bool is_same_student_addr(string n);
//bool is_same_book_name(string n);
bool is_same_book_name(string n);
bool is_same_Book_id(string n);

void showbookh();
void SetScreenGrid(int x, int y);
void mag_book2();

