#include "ComplNumber.h"

// выводит меню 
void showMenu() {
	cout << "[+] - сложение" << endl;
	cout << "[-] - вычитание" << endl;
	cout << "[*] - умножение" << endl;
	cout << "[/] - деление" << endl;
	cout << "[1] - ввести новое число" << endl;
	cout << "[0] - выход" << endl;
}
// выводит меню после расчета
void showMenuMin() {
	cout << "[1] - продолжим" << endl;
	cout << "[0] - выход" << endl;
}

// проверка выбора варианта меню
char varMenu() {
	char var;
	cout << "Выберите вариант: ";
	while (true) {
		cin >> var;
		if (var == '+' || var == '-' || var == '*' || var == '/' || var == '1' || var == '0') {
			return var;
		}
		else {
			cout << "Неправильно. Повторите ввод: ";
			cin.clear();
			cin.ignore();
		}
	}
}

// проверка выбора варианта меню после расчета
char varMenuMin() {
	char var;
	cout << "Выберите вариант: ";
	while (true) {
		cin >> var;
		if (var == '1' || var == '0') {
			return var;
		}
		else {
			cout << "Неправильно. Повторите ввод: ";
			cin.clear();
			cin.ignore();
		}
	}
}

//проверка на ввод вещественных чисел
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
		cout << "Необходимо ввести целое число. Повторите ввод: ";
	}
}

//ввод чисел
void ComplNumber::setNumber(int num) {
	cout << "Введите действительную часть: ";
	valid_num = getInteger();
	cout << "Введите мнимую часть: ";
	fake_num = getInteger();
	cout << endl;
	//string tmp = printK();
	cout << "Комплексное число " << num << ": ";
	printK();
	cout << endl;
}

//вывод в зависимости от знака действительной и мнимой части
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
	if (var == '+') strRes = "Результат сложения: ";
	if (var == '-') strRes = "Результат вычитания: ";
	if (var == '*') strRes = "Результат умножения: ";
	if (var == '/') strRes = "Результат деления: ";
	cout << strRes;
	printK();
}

