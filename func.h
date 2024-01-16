#pragma once
#ifndef FUNC_H
#define FUNC_H
#include<iostream>
using namespace std;
const double PI = 3.14;
// ��������
int max(int a, int b);
int add(int a, int b);
void iswap(int* a, int* b);
void wswap(int& a, int& b);
int sum(int a, int b = 9, int c = 10);
void in(int, int = 0); // ռλ��������
int sum(int a, int b); // �������� ��������������ͬ�����Ͳ�ͬ
class Animal;
void dospeak(Animal& a);
// ����ģ��
template<typename T, typename E>
void myswap(T& a, T& b) {
	T t = a;
	a = b;
	b=t;
}
// ��ģ��
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
// ��ģ��̳�
class Tt :public Temp<int, string> { // ��Ҫָ����ģ������

};
template<typename TT, typename EE> // ����ģ����
class Tt1;
template<typename TT, typename EE>
void out(Tt1<TT, EE> t) {
	cout << "ģ������Ԫ����ʵ��" << endl;
}
template<typename TT, typename EE>
class Tt1 :public Temp<TT, EE> { // Ҳ��д��ģ����ʽ
public:
	Tt1(TT x, EE y):Temp<TT, EE>(x, y) {
	};
	friend void out<>(Tt1<TT, EE> t); // ��Ԫ����
	void create(TT t, EE e);
};
template<typename TT, typename EE> // ��ģ���Ա����ʵ��Ҫ�ŵ�h�ļ��У�һ����ģ�嵥��д��hpp�ļ���
void Tt1<TT, EE>::create(TT t, EE e) {
	cout << "��ģ���г�Ա����������ʵ�ַ���" << endl;
}

// ��ģ����Ϊ��������
void printTemp(Temp<int, string>& t);
template<typename T, typename E>
void printTemp1(Temp<T, E>& t);
template<typename T>
void printTemp2(T& t);

// ������
class Cfriend;
class Circle;
class Cfriend {
public:
	void read(Circle& c);
};
class Circle {
	friend void h_self(Circle& c); // ��Ԫȫ�ֺ���
	friend class Cfriend; // ��Ԫ��
	friend void Cfriend::read(Circle& c); // ��Ԫ�ֲ�����
public:
	mutable int b; // ����Ϊ�������п��޸�ֵ
	double R;
	int* ac; // ����ָ������ʱ��Ҫ��д����Ŀ������캯��
	static int a; // ���ж�������һ������ ���������������ʼ��
	static void st();
	Circle(double R, int ac); // ���캯�� ������ Circle(const Circle& c);�ǿ������캯��
	Circle(const Circle& c); // �������캯��
	double get_ZC();
	Circle& next(); // *this���ض�����
	void pt() const; // ������ �����޸Ķ�������ֵ
	Circle operator+(Circle& c); // ���������
	Circle operator+(int c); // ��������ص�����
	Circle& operator=(Circle c); // �������ǳ���������� ��
	Circle& operator++(); // ǰ�õ���
	Circle operator++(int); // ���õ��� intΪռλ��
	bool operator==(Circle c); // ��
	bool operator>(Circle c); // ��
	bool operator<(Circle c); // ��
	bool operator!=(Circle c); // ��
	bool operator<=(Circle c); // ��
	bool operator>=(Circle c); // ��
	void operator()(int x); // �º������������ void�ɱ���������
	void ptn() {
		cout << "����Circle����ptn" << endl;
	}
	void ptn(int a) {
		cout << "����Circle����ptn(int)" << endl;
	}
	~Circle(); // �������� �������� �޲���
protected:  // ���ڿɷ��ʣ����ⲻ�ɣ�����ɷ���
private:  // ���ڿɷ��ʣ����ⲻ�ɣ����಻�ɷ��� ��Ĭ��Ȩ��
	int self;
};
void cp(Circle c);
void h_self(Circle& c);

// �̳�
class Gra : public Circle { // �����̳� �����̳� ˽�м̳� ��ϵ��ͼƬ
public:
	double R;
	Gra() : Circle(0, 0) { // �����˸��๹�캯��
		this->R = 2;
	}
	void ptn() {
		cout << "����Gra����ptn" << endl;
	}
	~Gra() {
		cout << "Gra������������" << endl;
	}
};

// ��̬
class Animal {
public:
	virtual void speak() { // �麯��
		cout << "������˵��" << endl;
	}
	// virtual void speak() = 0; // ���麯�� ֻҪ��һ�����麯�����������ǳ����࣬
								// �������޷�ʵ�������󣬳���������������д����
								// ��������Ҳ�ǳ�����
	// virtual ~Animal() {}; 
	// virtual ~Animal() = 0; // ʹ�ö�̬ʱdelete����󲢲���������������������ܵ�
	// ��Ҫʵ��				// ��������new�Ķ�������й¶��ʱ����������ڸ�����ʹ
							// ��������������������
};
class Cat :public Animal {
public:
	void speak() {
		cout << "è��˵��" << endl;
	}
};
class Dog :public Animal {
public:
	void speak() {
		cout << "����˵��" << endl;
	}
};
// �º���-��������
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