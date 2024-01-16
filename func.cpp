#include "func.h"
#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int add(int i, int j) { // 值传递和引用传递 略
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

// 类方法实现
Circle::~Circle() {
	cout << "Circle析构函数调用" << endl;
	delete this->ac; // 释放堆内存
	this->ac = NULL;
}
Circle::Circle(double R, int ac) {
	cout << "Circle构造函数调用" << endl;
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
	this->ac = new int(*c.ac); // 深拷贝
	cout << "Circle调用深拷贝构造函数" << endl;
}
// 静态成员初始化
int Circle::a = 10;
void Circle::st() {
	cout << "静态成员函数只能访问静态成员 a=" << a << endl;
}
Circle& Circle::next() {
	cout << "this返回对象本身" << endl;
	return *this;
}
void Circle::pt() const {
	// this->R = 1; 报错，常函数不能修改对象属性值
	this->b = 1;
	cout << "常函数调用 " << ++this->b << endl;
}
// 友元
void h_self(Circle& c) {
	cout << "友元函数访问私有变量 self=" << c.self << endl;
}
void Cfriend::read(Circle& c) {
	cout << "友元类访问私有变量 self=" << c.self << endl;
}
// 运算符重载
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
	cout << "赋值运算符=重载调用" << endl;
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
// 多态
void dospeak(Animal& a) {
	a.speak();
}
// 仿函数做参数
void printma(Myadd& m, int a, int b) {
	cout << "仿函数做参数 " << m(a, b) << endl;
}
// 算法
int add10(int n) {
	return n + 10;
}
bool ifgt10(int n) {
	return n > 10;
}
bool gt(int n, int m) {
	return n > m;
}