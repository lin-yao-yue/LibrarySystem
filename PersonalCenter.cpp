#include"Book.h"
#include"Borrow.h"
#include"User.h"
#include"History.h"
#include"base.h"
using namespace std;

void showMyInfo(User usernow) {
	usernow.displayUser();
}

void changeMyInfo(User usernow) {
	Base base;
	int num;
	int n;
	n = base.canFindUser(usernow.getId(), nullptr);   //�Ҽӵģ��������writeUser����base.changeUser,
	cout << "���������ѡ��1.�޸Ķ����Ϣ   2.�޸ĵ�����Ϣ" << endl;
	cin >> num;
	if (num == 1) {
		//*****Ȼ������޸�ȫ����Ϣ�������ȫ������������һ�ι�change���������������̫���ˣ�û��Ҫ�ֿ�change
		cout << "��������������";
		char name[USERNAMESIZE];
		cin >> name;

		cout << endl << "���������꼶��";
		int grade;
		cin >> grade;

		int gender = usernow.getGender();
		if (gender == 1)
		{
			cout << "ԭ�Ա�Ϊ �� ��������Ϊ Ů��" << endl;
			gender = 0;
		}
		else
		{
			cout << "ԭ�Ա�Ϊ Ů ��������Ϊ �У�" << endl;
			gender = 1;
		}

		cout << endl << "�������µ绰��";
		char telephone[TELEPHONESIZE];
		cin >> telephone;

		usernow.changeUser(usernow.getId(), usernow.getPassword(), grade, name, gender, telephone, usernow.getRole(), usernow.getState());
		usernow.writeUser(n);

		cout << endl << "ѧ����Ϣ�޸���ɣ�" << endl << endl;
		usernow.displayUser();
	}
	else if (num == 2) {
		cout << "���޸ĸ�����Ϣ��1.�꼶	2.����	3.�Ա�	4.�绰" << endl;
		cout << "�������ţ�";
		int numm;
		cin >> numm;
		switch (numm) {

		case 1:
		{
			cout << "���������꼶��";
			int grade;
			cin >> grade;
			usernow.changeUser(usernow.getId(), usernow.getPassword(), grade, usernow.getName(), usernow.getGender(), usernow.getTelephone(), usernow.getRole(), usernow.getState());
			usernow.writeUser(n);
			cout << "�޸ĳɹ���" << endl;
			break;
		}
		case 2:
		{
			cout << "��������������";
			char name[USERNAMESIZE];
			cin >> name;
			usernow.changeUser(usernow.getId(), usernow.getPassword(), usernow.getGrade(), name, usernow.getGender(), usernow.getTelephone(), usernow.getRole(), usernow.getState());
			usernow.writeUser(n);
			cout << "�޸ĳɹ���" << endl;
			break;
		}
		case 3:
		{
			int gender = usernow.getGender();
			if (gender == 1)
			{
				cout << "ԭ�Ա�Ϊ �� ��������Ϊ Ů��" << endl;
				gender = 0;
			}
			else
			{
				cout << "ԭ�Ա�Ϊ Ů ��������Ϊ �У�" << endl;
				gender = 1;
			}
			usernow.changeUser(usernow.getId(), usernow.getPassword(), usernow.getGrade(), usernow.getName(), gender, usernow.getTelephone(), usernow.getRole(), usernow.getState());
			usernow.writeUser(n);
			cout << "�޸ĳɹ���" << endl;
			break;
		}
		case 4:
		{
			cout << "�������µ绰��";
			char telephone[TELEPHONESIZE];
			cin >> telephone;
			usernow.changeUser(usernow.getId(), usernow.getPassword(), usernow.getGrade(), usernow.getName(), usernow.getGender(), telephone, usernow.getRole(), usernow.getState());
			usernow.writeUser(n);
			cout << "�޸ĳɹ���" << endl;
			break;
		}
		default:
			cout << "�������";
			break;
		}
	}
}

void changeMyPass(User usernow) {   //***��administer�ĳ�usernow
	char oldpassword[PASSWORDSIZE];
	cout << "������ԭ���룺";
	cin >> oldpassword;
	int consition = 0;

	Base base;
	int n = base.canFindUser(usernow.getId(), nullptr);

	//administer = idFindUser(userid);
	char* turepassword = usernow.getPassword();
	for (int i = 0; i < PASSWORDSIZE; i++) {
		if (strcmp(oldpassword, turepassword)) {
			cout << "�����������" << endl;
			break;
		}
		else {
			cout << "�����������룺";
			char password[PASSWORDSIZE];
			cin >> password;
			char password2[PASSWORDSIZE];
			cout << "���ٴ�ȷ�����룺";
			cin >> password2;
			if (strcmp(password, password2) == 0)
			{
				base.changePassword(usernow.getId(), password2);
				usernow.writeUser(n);
				cout << "�޸ĳɹ���" << endl;
				break;
			}
			else {
				cout << "�Ƿ����룡����������" << endl;
				backPreviousStep(consition);
			}
		}
		cout << endl;
		system("pause");
	}
}

void backPreviousStep(int& consition) {   //�˻ص���һ��
	consition = 1;
}