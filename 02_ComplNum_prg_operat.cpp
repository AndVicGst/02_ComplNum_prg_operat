/*
Создайте класс Complex (комплексное число) или исполь-
зуйте уже созданный вами класс. Создайте перегруженные
операторы для реализации арифметических операций для
по работе с комплексными числами (операции +, -, *, /).
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "ComplNumber.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ComplNumber compl1;    //первое число
	ComplNumber compl2;    //второе число
	ComplNumber compl_res; //результат
	char choice;           //переменная хранит выбор пункта меню
	while (true) {
		system("cls");
		cout << "--------Математические операции с комплексными числами-----------" << endl << endl;
		compl1.setNumber(1);  //вводим первое число
		compl2.setNumber(2);  //вводим второе число

		showMenu();         //показать меню
		choice = varMenu(); //выбор пункта меню

		if (choice == '+') {    //расчет суммы
			cout << endl;
			compl_res = compl1 + compl2;
			compl_res.print(choice);
			showMenuMin();                       //показать меню после расчета
			if (varMenuMin() == '1') continue;   //выбор пукнта меню после расчета
			else break;
		}
		else if (choice == '-') {  //расчет вычитания
			cout << endl;
			compl_res = compl1 - compl2;
			compl_res.print(choice);
			showMenuMin();                       //показать меню после расчета
			if (varMenuMin() == '1') continue;   //выбор пукнта меню после расчета
			else break;
		}
		else if (choice == '*') {  //расчет произведения
			cout << endl;
			compl_res = compl1 * compl2;
			compl_res.print(choice);
			showMenuMin();                       //показать меню после расчета
			if (varMenuMin() == '1') continue;   //выбор пукнта меню после расчета
			else break;
		}
		else if (choice == '/') {  //расчет деления
			cout << endl;
			compl_res = compl1 / compl2;
			compl_res.print(choice);
			showMenuMin();                       //показать меню после расчета
			if (varMenuMin() == '1') continue;   //выбор пукнта меню после расчета
			else break;
		}
		else if (choice == '1') {
			continue;
		}
		else if (choice == '0') break;
	}
	cout << endl;
	system("pause");
	return 0;
 
}

