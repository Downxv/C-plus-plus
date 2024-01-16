#pragma once
#ifndef FUNC_H
#define FUNC_H
#include<iostream>
using namespace std;
const double PI = 3.14;
// 函数声明
int max(int a, int b);
int add(int a, int b);
void iswap(int* a, int* b);
void wswap(int& a, int& b);
int sum(int a, int b = 9, int c = 10);
void in(int, int = 0); // 占位参数函数
int sum(int a, int b); // 函数重载 函数参数个数不同，类型不同
class Animal;
void dospeak(Animal& a);
// 函数模板
template<typename T, typename E>
void myswap(T& a, T& b) {
	T t = a;
	a = b;
	b=t;
}
// 类模板
template<typename T, typename E>
class Temp {
public:
	T x;
	E y;
	Temp(T x, E y) {
		this->x = x;
		this->y = y;
	}
};
// 类模板继承
class Tt :public Temp<int, string> { // 需要指定类模板类型

};
template<typename TT, typename EE> // 声明模板类
class Tt1;
template<typename TT, typename EE>
void out(Tt1<TT, EE> t) {
	cout << "模板类友元函数实现" << endl;
}
template<typename TT, typename EE>
class Tt1 :public Temp<TT, EE> { // 也可写成模板形式
public:
	Tt1(TT x, EE y):Temp<TT, EE>(x, y) {
	};
	friend void out<>(Tt1<TT, EE> t); // 友元函数
	void create(TT t, EE e);
};
template<typename TT, typename EE> // 类模板成员函数实现要放到h文件中，一般类模板单独写到hpp文件中
void Tt1<TT, EE>::create(TT t, EE e) {
	cout << "类模板中成员函数的类外实现方法" << endl;
}

// 类模板作为函数参数
void printTemp(Temp<int, string>& t);
template<typename T, typename E>
void printTemp1(Temp<T, E>& t);
template<typename T>
void printTemp2(T& t);

// 类声明
class Cfriend;
class Circle;
class Cfriend {
public:
	void read(Circle& c);
};
class Circle {
	friend void h_self(Circle& c); // 友元全局函数
	friend class Cfriend; // 友元类
	friend void Cfriend::read(Circle& c); // 友元局部函数
public:
	mutable int b; // 声明为常函数中可修改值
	double R;
	int* ac; // 存在指针属性时需要编写深拷贝的拷贝构造函数
	static int a; // 所有对象共享这一个变量 类内声明，类外初始化
	static void st();
	Circle(double R, int ac); // 构造函数 可重载 Circle(const Circle& c);是拷贝构造函数
	Circle(const Circle& c); // 拷贝构造函数
	double get_ZC();
	Circle& next(); // *this返回对象本身
	void pt() const; // 常函数 不能修改对象属性值
	Circle operator+(Circle& c); // 运算符重载
	Circle operator+(int c); // 运算符重载的重载
	Circle& operator=(Circle c); // 存在深拷贝浅拷贝的问题 略
	Circle& operator++(); // 前置递增
	Circle operator++(int); // 后置递增 int为占位符
	bool operator==(Circle c); // 略
	bool operator>(Circle c); // 略
	bool operator<(Circle c); // 略
	bool operator!=(Circle c); // 略
	bool operator<=(Circle c); // 略
	bool operator>=(Circle c); // 略
	void operator()(int x); // 仿函数调用运算符 void可变任意类型
	void ptn() {
		cout << "父类Circle函数ptn" << endl;
	}
	void ptn(int a) {
		cout << "父类Circle函数ptn(int)" << endl;
	}
	~Circle(); // 析构函数 不可重载 无参数
protected:  // 类内可访问，类外不可，子类可访问
private:  // 类内可访问，类外不可，子类不可访问 是默认权限
	int self;
};
void cp(Circle c);
void h_self(Circle& c);

// 继承
class Gra : public Circle { // 公共继承 保护继承 私有继承 关系见图片
public:
	double R;
	Gra() : Circle(0, 0) { // 调用了父类构造函数
		this->R = 2;
	}
	void ptn() {
		cout << "子类Gra函数ptn" << endl;
	}
	~Gra() {
		cout << "Gra析构函数调用" << endl;
	}
};

// 多态
class Animal {
public:
	virtual void speak() { // 虚函数
		cout << "动物在说话" << endl;
	}
	// virtual void speak() = 0; // 纯虚函数 只要有一个纯虚函数，这个类就是抽象类，
								// 抽象类无法实例化对象，抽象类的子类必须重写纯虚
								// 函数否则也是抽象类
	// virtual ~Animal() {}; 
	// virtual ~Animal() = 0; // 使用多态时delete父类后并不会调用子类析构函数可能导
	// 需要实现				// 致子类中new的堆区数据泄露此时解决方法是在父类中使
							// 用虚析构或纯虚析构函数
};
class Cat :public Animal {
public:
	void speak() {
		cout << "猫在说话" << endl;
	}
};
class Dog :public Animal {
public:
	void speak() {
		cout << "狗在说话" << endl;
	}
};
// 仿函数-函数对象
class Myadd {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};
void printma(Myadd& m, int a, int b);
class Mysum {
public:
	int msum;
	Mysum() {
		this->msum = 0;
	}
	void operator()(int n) {
		this->msum += n;
		cout << this->msum << endl;
	}
};
int add10(int n);
bool ifgt10(int n);
bool gt(int n, int m);
#endif