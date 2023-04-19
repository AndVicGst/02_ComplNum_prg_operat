#pragma once
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class ComplNumber
{
private:
	double valid_num;  // �������������� �����
	double fake_num;   // ������ �����
	int getInteger();  //�������� �� ���� ������������ �����
public:
	ComplNumber() : valid_num{ 0 }, fake_num{0} {}
	ComplNumber(double valid_a, double fake_a) : valid_num{ valid_a }, fake_num{ fake_a } {}
	void setNumber(int num);   //���� �����
	void print(char var);      //����� ����������
	void printK();           //����� � ����������� �� ����� �������������� � ������ �����
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

void showMenu();    // ������� ���� 
void showMenuMin(); // ������� ���� ����� �������
char varMenu();     // �������� ������ �������� ����
char varMenuMin();  // �������� ������ �������� ���� ����� �������