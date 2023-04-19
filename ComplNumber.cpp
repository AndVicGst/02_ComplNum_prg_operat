#include "ComplNumber.h"

// ������� ���� 
void showMenu() {
	cout << "[+] - ��������" << endl;
	cout << "[-] - ���������" << endl;
	cout << "[*] - ���������" << endl;
	cout << "[/] - �������" << endl;
	cout << "[1] - ������ ����� �����" << endl;
	cout << "[0] - �����" << endl;
}
// ������� ���� ����� �������
void showMenuMin() {
	cout << "[1] - ���������" << endl;
	cout << "[0] - �����" << endl;
}

// �������� ������ �������� ����
char varMenu() {
	char var;
	cout << "�������� �������: ";
	while (true) {
		cin >> var;
		if (var == '+' || var == '-' || var == '*' || var == '/' || var == '1' || var == '0') {
			return var;
		}
		else {
			cout << "�����������. ��������� ����: ";
			cin.clear();
			cin.ignore();
		}
	}
}

// �������� ������ �������� ���� ����� �������
char varMenuMin() {
	char var;
	cout << "�������� �������: ";
	while (true) {
		cin >> var;
		if (var == '1' || var == '0') {
			return var;
		}
		else {
			cout << "�����������. ��������� ����: ";
			cin.clear();
			cin.ignore();
		}
	}
}

//�������� �� ���� ������������ �����
int ComplNumber::getInteger()
{
	int number;
	while (true)
	{
		if (!(cin >> number) || getchar() != '\n') {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else return number;
		cout << "���������� ������ ����� �����. ��������� ����: ";
	}
}

//���� �����
void ComplNumber::setNumber(int num) {
	cout << "������� �������������� �����: ";
	valid_num = getInteger();
	cout << "������� ������ �����: ";
	fake_num = getInteger();
	cout << endl;
	//string tmp = printK();
	cout << "����������� ����� " << num << ": ";
	printK();
	cout << endl;
}

//����� � ����������� �� ����� �������������� � ������ �����
void ComplNumber::printK() {   
	if (valid_num > 0 && fake_num > 0) cout << valid_num << " + " << fake_num << "*i" << endl;
	if (valid_num > 0 && fake_num < 0) cout << valid_num << " - " << fabs(fake_num) << "*i" << endl;
	if (valid_num < 0 && fake_num > 0) cout << valid_num << " + " << fake_num << "*i" << endl;
	if (valid_num < 0 && fake_num < 0) cout << valid_num << " - " << fabs(fake_num) << "*i" << endl;
	if (valid_num == 0 && fake_num != 0) cout << fake_num << "*i" << endl;
	if (valid_num != 0 && fake_num == 0) cout << valid_num << endl;
	if (valid_num == 0 && fake_num == 0) cout << valid_num << endl;
}

void ComplNumber::print(char var) {
	string strRes;
	if (var == '+') strRes = "��������� ��������: ";
	if (var == '-') strRes = "��������� ���������: ";
	if (var == '*') strRes = "��������� ���������: ";
	if (var == '/') strRes = "��������� �������: ";
	cout << strRes;
	printK();
}

