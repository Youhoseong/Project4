#include <iostream>
#include <String>

using namespace std;

typedef struct {
	int acntID;
	char name[10];
	int howmuchLeft;

}Account;

Account accArr[100];
int accNum = 0;


void creatAccount(void) {
	cout <<'\n' << "[���°���]" << '\n' << "���� ID: ";

	cin >> accArr[accNum].acntID;
	cout << "�̸�: ";
	cin >> accArr[accNum].name;
	cout << "�Աݾ�: ";
	cin >> accArr[accNum].howmuchLeft;

	cout << '\n';

	accNum++;
}
void deposit(void) {
	int checkID, howmuchdeposit, Switch = 0;;

	cout << '\n' << "[��	��]" << '\n' << "���� ID: ";
	cin >> checkID;

	cout << "�Աݾ�: ";
	cin >> howmuchdeposit;

	for (int i = 0; i < 100; i++) {
		if (accArr[i].acntID == checkID) {
			Switch = 0;
			accArr[i].howmuchLeft += howmuchdeposit;
			break;
		}
		Switch = 1;
  }
	if (Switch == 1)
		cout << "�ش� ���� ID�� �������� �ʽ��ϴ�.\n\n";
	else
		cout << "�ԱݿϷ�\n\n";
}

void withdraw(void) {            
	int checkID,howmuchwithdraw, Switch=0;

	cout << '\n' << "[��	��]" << '\n' << "���� ID: ";
	cin >> checkID;

	cout << "��ݾ�: ";
	cin >> howmuchwithdraw;

	for (int i = 0; i < 100; i++) {
		if (accArr[i].acntID == checkID) {
			Switch = 0;

			if (accArr[i].howmuchLeft < howmuchwithdraw) {
				cout << "�ܾ��� �����մϴ�.";
				break;
			}
			else {
				accArr[i].howmuchLeft -= howmuchwithdraw;
				break;
			}
			Switch = 1;
		}
	}
	if (Switch == 1)
		cout << "�ش� ���� ID�� �������� �ʽ��ϴ�.\n\n";
	else
		cout << "��ݿϷ�\n\n";
	
}    

void checkmyMoney(void) {
		int checkID=0, Switch=0, temp;
		cout << '\n' << "[�������� Ȯ��]" << '\n' << "���� ID: ";
		cin >> checkID;
		
		for (int i = 0; i < 100; i++) {
			if (accArr[i].acntID == checkID) {
				Switch = 0;
				temp = i;
				break;
			}

			Switch = 1;
		}

		if (Switch == 1) {
			cout << "�ش� ���°� �������� �ʽ��ϴ�.";
		}
		else {
			cout << "\n���� ID: " << accArr[temp].acntID << endl;
			cout << "�� ��: " << accArr[temp].name << endl;
			cout << "���� �ܾ�: " << accArr[temp].howmuchLeft << endl << endl;
		}
		
	}

	int main(void) {
		int n=0;

		while (true) {

			cout << "1. ���°���" << endl;
			cout << "2. ��	  ��" << endl;
			cout << "3. ��	  ��" << endl;
			cout << "4. �������� ��ü ��ȸ" << endl;
			cout << "5. ���α׷� ����" << endl;
			cout << "����: ";

			cin >> n;

			if (n == 1)
				creatAccount();
			else if (n == 2)
				deposit();
			else if (n == 3)
				withdraw();
			else if (n == 4)
				checkmyMoney();
			else
				break;

		}

		return 0;
	}


