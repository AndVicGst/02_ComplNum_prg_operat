#pragma once
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class ComplNumber
{
private:
	double valid_num;  // действительная часть
	double fake_num;   // мнимая часть
	int getInteger();  //проверка на ввод вещественных чисел
public:
	ComplNumber() : valid_num{ 0 }, fake_num{0} {}
	ComplNumber(double valid_a, double fake_a) : valid_num{ valid_a }, fake_num{ fake_a } {}
	void setNumber(int num);   //ввод чисел
	void print(char var);      //вывод результата
	void printK();           //вывод в зависимости от знака действительной и мнимой части
	friend ComplNumber operator+(const ComplNumber compl1, const ComplNumber compl2) {
		return ComplNumber(compl1.valid_num+compl2.valid_num, compl1.fake_num+compl2.fake_num);
	};
	friend ComplNumber operator-(const ComplNumber compl1, const ComplNumber compl2) {
		return ComplNumber(compl1.valid_num - compl2.valid_num, compl1.fake_num - compl2.fake_num);
	};
	friend ComplNumber operator*(const ComplNumber compl1, const ComplNumber compl2) {
		return ComplNumber(compl1.valid_num*compl2.valid_num - compl1.fake_num*compl2.fake_num, 
			               compl1.valid_num*compl2.fake_num+compl2.valid_num*compl1.fake_num);
	};
	friend ComplNumber operator/(const ComplNumber compl1, const ComplNumber compl2) {
		return ComplNumber((compl1.valid_num * compl2.valid_num + compl1.fake_num * compl2.fake_num)/(compl2.valid_num* compl2.valid_num+ compl2.fake_num* compl2.fake_num),
		(compl2.valid_num * compl1.fake_num - compl1.valid_num * compl2.fake_num)/(compl2.valid_num* compl2.valid_num+ compl2.fake_num* compl2.fake_num));
	};
};

void showMenu();    // выводит меню 
void showMenuMin(); // выводит меню после расчета
char varMenu();     // проверка выбора варианта меню
char varMenuMin();  // проверка выбора варианта меню после расчета