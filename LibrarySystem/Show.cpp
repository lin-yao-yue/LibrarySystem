#include"main.h"
void menu1()
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                  ***************************************" << endl;
	cout << "                  ***          ��ѡ���¼����         ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  *** 1 ������Աϵͳ   2 ѧ������ϵͳ ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            0 �˳�               ***" << endl;
	cout << "                  ***************************************" << endl;

	cout << "Please input your choice:";
}


void menu2()
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << "                  ***************************************" << endl;
	cout << "                  ***           ͼ�����ϵͳ          ***" << endl;
	cout << "                  ***************************************" << endl;
	cout << "                  ***            ��ѡ���ܣ�         ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            1 ͼ�����           ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            2 ѧ������           ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            3 ��ʾͼ����Ϣ       ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            4 ��ʾѧ����Ϣ       ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            5 �޸Ĺ���Ա����     ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            6 �������˵�         ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***            0 �˳�               ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***************************************" << endl;

	cout << "Please input your choice:";
}


void menu3()
{
	system("cls");
	cout << endl << endl << endl;
	cout << "                  ***************************************" << endl;
	cout << "                  ***             ѧ��ϵͳ            ***" << endl;
	cout << "                  ***************************************" << endl;
	cout << "                  ***            ��ѡ���ܣ�         ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          1 ����ѽ����鼮       ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          2 ��ʾͼ���б�         ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          3 ����ͼ��             ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          4 ����ҵ���ͳɼ�     ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          5 ��鲢�����ҵ���Ϣ   ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          6 �������˵�           ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***          0 �˳�                 ***" << endl;
	cout << "                  ***                                 ***" << endl;
	cout << "                  ***************************************" << endl;

	cout << "Please input your choice:";
}


void SetScreenGrid(int x, int y)    //���ÿ���̨��С
{
	char sysSetBuf[80];
	sprintf_s(sysSetBuf, "mode con cols=%d lines=%d", x, y);
	system(sysSetBuf);
}

              
void showbookh()
{
	cout << "*" << setw(10) << "���";
	cout << "   *" << setw(10) << "����";
	cout << "   *" << setw(10) << "����";
	cout << "   *" << setw(10) << "�����";
	cout << "   *" << setw(10) << "λ��";
	cout << "   *" << setw(10) << "������";
	cout << "   *" << setw(10) << "����ʱ��";
	cout << "   *" << setw(10) << "�۸�" << "*";
	cout << endl;//һ����¼
}



void wrong_input()
{
	system("cls");
	cout << endl << endl << endl << endl << endl << endl;
	cout << "                        �������! ����������" << endl;
	system("pause");
}
