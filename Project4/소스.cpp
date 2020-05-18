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
	cout <<'\n' << "[계좌개설]" << '\n' << "계좌 ID: ";

	cin >> accArr[accNum].acntID;
	cout << "이름: ";
	cin >> accArr[accNum].name;
	cout << "입금액: ";
	cin >> accArr[accNum].howmuchLeft;

	cout << '\n';

	accNum++;
}
void deposit(void) {
	int checkID, howmuchdeposit, Switch = 0;;

	cout << '\n' << "[입	금]" << '\n' << "계좌 ID: ";
	cin >> checkID;

	cout << "입금액: ";
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
		cout << "해당 계좌 ID가 존재하지 않습니다.\n\n";
	else
		cout << "입금완료\n\n";
}

void withdraw(void) {            
	int checkID,howmuchwithdraw, Switch=0;

	cout << '\n' << "[출	금]" << '\n' << "계좌 ID: ";
	cin >> checkID;

	cout << "출금액: ";
	cin >> howmuchwithdraw;

	for (int i = 0; i < 100; i++) {
		if (accArr[i].acntID == checkID) {
			Switch = 0;

			if (accArr[i].howmuchLeft < howmuchwithdraw) {
				cout << "잔액이 부족합니다.";
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
		cout << "해당 계좌 ID가 존재하지 않습니다.\n\n";
	else
		cout << "출금완료\n\n";
	
}    

void checkmyMoney(void) {
		int checkID=0, Switch=0, temp;
		cout << '\n' << "[계좌정보 확인]" << '\n' << "계좌 ID: ";
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
			cout << "해당 계좌가 존재하지 않습니다.";
		}
		else {
			cout << "\n계좌 ID: " << accArr[temp].acntID << endl;
			cout << "이 름: " << accArr[temp].name << endl;
			cout << "현재 잔액: " << accArr[temp].howmuchLeft << endl << endl;
		}
		
	}

	int main(void) {
		int n=0;

		while (true) {

			cout << "1. 계좌개설" << endl;
			cout << "2. 입	  금" << endl;
			cout << "3. 출	  금" << endl;
			cout << "4. 계좌정보 전체 조회" << endl;
			cout << "5. 프로그램 종료" << endl;
			cout << "선택: ";

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


