#include "func.h"
#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int add(int i, int j) { // ֵ���ݺ����ô��� ��
	return i + j;
}

void iswap(int* a, int* b) {
	int t = 0;
	t = *a;
	*a = *b;
	*b = t;
}

void wswap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

int sum(int a, int b, int c) {
	return a + b + c;
}

// �෽��ʵ��
Circle::~Circle() {
	cout << "Circle������������" << endl;
	delete this->ac; // �ͷŶ��ڴ�
	this->ac = NULL;
}
Circle::Circle(double R, int ac) {
	cout << "Circle���캯������" << endl;
	this->R = R;
	this->ac = new int(ac);
	this->self = 31;
}
double Circle::get_ZC() {
	return 2 * PI * this->R;
}
void cp(Circle c) {
	cout << c.R << endl;
	cout << *c.ac << endl;
}
Circle::Circle(const Circle& c) {
	this->R = c.R;
	this->ac = new int(*c.ac); // ���
	cout << "Circle����������캯��" << endl;
}
// ��̬��Ա��ʼ��
int Circle::a = 10;
void Circle::st() {
	cout << "��̬��Ա����ֻ�ܷ��ʾ�̬��Ա a=" << a << endl;
}
Circle& Circle::next() {
	cout << "this���ض�����" << endl;
	return *this;
}
void Circle::pt() const {
	// this->R = 1; ���������������޸Ķ�������ֵ
	this->b = 1;
	cout << "���������� " << ++this->b << endl;
}
// ��Ԫ
void h_self(Circle& c) {
	cout << "��Ԫ��������˽�б��� self=" << c.self << endl;
}
void Cfriend::read(Circle& c) {
	cout << "��Ԫ�����˽�б��� self=" << c.self << endl;
}
// ���������
Circle Circle::operator+(Circle& c) {
	Circle temp(0, 0);
	temp.R = this->R + c.R;
	return temp;
}
Circle Circle::operator+(int c) {
	Circle temp(0, 0);
	temp.R = this->R + c;
	return temp;
}
Circle& Circle::operator=(Circle c) {
	this->R = c.R;
	cout << "��ֵ�����=���ص���" << endl;
	return *this;
}
Circle& Circle::operator++() {
	this->R++;
	return *this;
}
Circle Circle::operator++(int) {
	Circle temp = *this;
	this->R++;
	return temp;
}
// ��̬
void dospeak(Animal& a) {
	a.speak();
}
// �º���������
void printma(Myadd& m, int a, int b) {
	cout << "�º��������� " << m(a, b) << endl;
}
// �㷨
int add10(int n) {
	return n + 10;
}
bool ifgt10(int n) {
	return n > 10;
}
bool gt(int n, int m) {
	return n > m;
}