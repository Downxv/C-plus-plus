#include<iostream>
#include<string>
#include<fstream>
#include "func.h"
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

// 宏常量和常量
#define MAX 20
const int MIN = 1;
ostream& operator<<(ostream& cout, Circle c);
void fun(int i);
void usefunc(void (*func)(int i), int j);
// 结构体
struct people {
	string name;
	int age;
};

struct man {
	people p;
	string money;
};


int main() {
	cout << "hello world" << endl;
	// 单行注释
	/*多行注释*/
	// 整形变量
	int a = 10;
	short b = 5;
	long c = 15;
	long long d = 20;
	cout << "int " << sizeof(a) << " short " << sizeof(b) << " long " << sizeof(c) << " long long " << sizeof(d) << endl;
	// 常量
	cout << "MAX = " << MAX << " MIN = " << MIN << endl;
	// 浮点型
	float e = 3.14f; // 7位有效数字
	double f = 3.1415; // 15~16位有效数字
	cout << "float " << sizeof(float) << " double " << sizeof(double) << endl;
	// 字符型
	char ch = 'x';
	cout << "char " << sizeof(char) << endl;
	ch = 97;
	cout << ch << " " << int(ch) << endl;
	// 转义字符 略
	// 字符串
	string str = "kkkk";
	cout << "字符串 " << str << endl;
	// 布尔型
	bool bl = false;
	cout << "bool " << sizeof(bool) << endl;
	// 数据输入 cin >> 变量 略
	// 运算符 + - * / % ++ -- = += -= *= /= %= == != < > <= >= ! && ||
	// 流程控制
	if (ch == 'a') {
		cout << ch << endl;
	}
	else if (ch == 'b') {

	}
	else {

	}

	int t = (2 > 3) ? 8 : 0;
	cout << t << endl;

	switch (t) {
	case 0:
		cout << t << endl;
		break;
	case 8:
		cout << t << endl;
		break;
	default:
		break;
	}

	while (t < 3) {
		cout << t;
		t++;
	}
	cout << endl;

	do {
		cout << t;
		t--;
	} while (t > 0);
	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout << i;
	}
	cout << endl;

	// break continue 略

	// 数组
	int arr[5];
	arr[0] = 0;
	int arr1[4] = { 1,2 };
	int arr2[] = { 3,4,5 };
	for (int i = 0; i < 4; i++) {
		cout << arr1[i];
	}
	cout << endl;
	cout << "数组开始内存地址:" << arr << "数组元素个数:" << sizeof(arr) / sizeof(arr[0]) << endl;

	int da1[2][4];
	int da2[2][3] = {
		{1,2,3},
		{4,5,6},
	};
	// 函数
	cout << add(9, 8) << endl;
	cout << max(2, 3) << endl;
	// 指针
	int p = 0;
	int* ptr = &p;
	cout << *ptr << endl;
	cout << sizeof(ptr) << endl;
	int* ptr1 = NULL; // 空指针
	const int* ptr2; // 常量指针 指向可改，指向的值不可改
	int* const ptr3 = NULL; // 指针常量
	const int* const ptr4 = NULL;
	int arr3[] = { 1,2,3 };
	ptr2 = &arr3[0];
	for (int i = 0; i < 3; i++) {
		cout << *ptr2;
		ptr2++;
	}
	cout << endl;
	// 指针做参数
	int aa = 0, bb = 1;
	iswap(&aa, &bb);
	cout << aa << " " << bb << endl;
	// 函数做参数
	usefunc(fun, 19);
	// 结构体
	people p1;
	p1.name = "qaqa";
	p1.age = 21;
	people p2 = {
		"wawa",
		12
	};
	people p3[2] = {
		{"ppp",13},
		{"ooo",32}
	};
	people* p4;
	p4 = &p3[0];
	cout << p3[1].age << " " << p4->name << endl;
	man m = {
		{"op", 43},
		"many"
	};
	cout << m.p.name << endl;
	//new 关键字 开辟栈堆区
	int* i = new int(12);
	cout << *i << endl;
	delete i;
	int* ii = new int[10];
	ii[0] = 2;
	delete[] ii;
	// 引用 作用->给变量起别名
	int x = 10;
	int& xx = x; // 初始化后不能改变
	cout << xx << endl;
	int aaa = 20, bbb = 30;
	wswap(aaa, bbb); // 引用传参
	cout << aaa << " " << bbb << endl;
	int su = sum(20);
	cout << su << endl;
	// 类和对象 封装 继承 多态
	Circle cc(3, 2); // 调用默认构造函数时不加() 会被误认为函数声明
	cc.R = 12;
	cout << cc.get_ZC() << endl;
	cp(cc); // 调用深拷贝构造函数
	// 类对象作为类成员 l略
	// 静态成员
	cout << cc.a << " " << Circle::a << endl;
	cc.st();
	// this指针 是指针常量 指向成员[变量]函数所属的对象，函数可返回*this<对象本身>
	cc.next().next().next();
	// 常函数 常对象
	cc.pt();
	const Circle ccc(9, 8);
	ccc.pt(); // 常对象只能调用常函数
	// 友元 让函数或类访问一个类中的私有成员
	h_self(cc);
	Cfriend* cf = new Cfriend;
	cf->read(cc);
	// 运算符重载
	Circle cce(0, 0);
	cce = cce + cc;
	cout << "cce.R=" << cce.R << endl;
	cce = cce + 10;
	cout << "cce.R=" << cce.R << endl;
	cout << cce << endl;
	cout << cce++ << endl;
	cout << ++cce << endl;
	cout << cce << endl;
	// 继承
		// 子类与父类同名<静态>属性/<静态>函数调用方法
	Gra g;
	cout << "父类静态属性 a=" << Gra::Circle::a << endl;
	cout << "Gra-R" << g.R << "Circle-R" << g.Circle::R << endl; // 子类调用父类同名属性 加作用域
	g.ptn();
	g.Circle::ptn(); // 子类调用父类同名函数
	// g.ptn(1); 调用出错，因为子类同名函数会隐藏掉父类同名函数，包括重载，需要加父类作用域
	g.Circle::ptn(3);
	// 多继承 不建议使用 语法 class A : public B, public C{}
	// 菱形继承解决同名属性问题 使用虚继承 class A:virtual public B{} 略
	// 多态 静态（函数重载 运算符重载） 动态（派生类/虚函数运行时多态 地址软绑定）
	// 动态多态条件  1 继承关系 2 子类重写父类虚函数 3 dospeak中父类引用（或指针）指向子对象
	Cat cat;
	Dog dog;
	dospeak(cat); // 引用型
	dospeak(dog);
	Animal* al = new Cat; // 指针型
	al->speak();
	delete al; // 清除堆区数据 但al指针没变
		// 纯虚函数 抽象类 略
	//文件操作 ofstream 写 ifstream 读 fstream 读写
	ofstream ofs;
	ofs.open("test.txt", ios::out | ios::trunc);
	if (ofs.is_open()) {
		ofs << "C++写入文本文件" << endl;
	}
	ofs.close();
	ofs.open("test.txt", ios::app);
	if (ofs.is_open()) {
		ofs << "追加方式写入" << endl;
	}
	ofs.close();
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ifs.is_open()) {
		// 第一种
		cout << "读取文件" << endl;
		char buf[1024] = { 0 };
		//while (ifs >> buf) { // 按行读取
		//	cout << buf << endl;
		//}
		// 第二种
		//while (ifs.getline(buf, sizeof(buf))) {
		//	cout << buf << endl;
		//}
		// 第三种 推荐
		string str;
		while (getline(ifs, str)) {
			cout << str << endl;
		}
		// 第四种
		//char ccc = '0';
		//while ((ccc = ifs.get()) != EOF) {
		//	cout << ccc;
		//}
	}
	else {
		cout << "读取失败" << endl;
	}
	ifs.close();
	// 二进制方式读写文件
	char cx[64] = { 97 }; // 二进制写入建议用字符数组而不是string
	Circle ccl(12, 0);
	ofstream ofsbin;
	ofsbin.open("testbit.txt", ios::out | ios::binary);
	if (ofsbin.is_open()) {
		ofsbin.write(cx, sizeof(cx));
		ofsbin.write((const char*)&ccl, sizeof(ccl));
	}
	ofsbin.close();
	ifstream ifsbin;
	char cr[64] = { 1 };
	Circle ccle(0, 0);
	ifsbin.open("testbit.txt", ios::in | ios::binary);
	if (ifsbin.is_open()) {
		ifsbin.read(cr, sizeof(cr));
		cout << "二进制文件读取 cr=" << cr[0] << endl;
		ifsbin.read((char*)&ccle, sizeof(ccle));
		cout << "二进制文件读取 ccle.R=" << ccle.R << endl;
	}
	ifsbin.close();
	// 模板 泛型
	float aaaa = 1.2f;
	float bbbb = 2.3f;
	myswap<float, int>(aaaa, bbbb); // 显示指定类型 推荐
	cout << "aaaa= " << aaaa << "bbbb= " << bbbb << endl;
	Temp<int, string> tp(1, "str");
	cout << "temp " << tp.x << " " << tp.y << endl;
	printTemp(tp);
	printTemp1(tp);
	printTemp2(tp);
	// 模板与友元
	Tt1<int, int> tt1(3, 4);
	out(tt1);
	// STL
	// string
	string st1;
	st1 = "hello world";
	st1 += "kc";
	int ij = st1.find("wo");
	cout << ij << endl;
	ij = st1.find('e', 2);
	cout << ij << endl;
	ij = st1.rfind('o');
	cout << ij << endl;
	st1.replace(0, 2, "ppp");
	cout << st1 << endl;
	cout << st1.compare("aaallo") << endl; // [> 1] [< -1] [= 0] 
	cout << st1[5] << endl;
	st1[5] = 'e';
	cout << st1 << endl;
	cout << st1.size() << endl;
	st1.insert(2, "ddd");
	cout << st1 << endl;
	st1.erase(2, 4);
	cout << st1 << endl;
	cout << st1.substr(2, 5) << endl;
	// vector 容器可嵌套
	vector<int> v;
	v.push_back(12);
	v.push_back(92);
	vector<int> v1 = v; // 赋值
	if (!v.empty()) {
		cout << "cap " << v.capacity() << " size " << v.size() << endl;
		v.resize(5);
	}
	v.insert(v.begin() + 2, 1000);
	v.insert(v.begin(), 2, 1009);
	v.insert(v.begin(), v1.begin(), v1.end());
	v.pop_back();
	v.erase(v.end() - 1);
	v.erase(v.begin(), v.begin() + 2);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	int ft = v.front();
	int bk = v.back();
	int vv = v[0];	vector<int>(v).swap(v); // 收缩内存
	v.reserve(10); // 预留内存 插入大量数据时减少开辟内存的次数

	// deque 双端数组
	deque<int> deq;
	deq.push_back(1);
	deq.push_front(9);
	deq.push_front(0);
	cout << deq.front() << " " << deq.back() << endl;
	deque<int> deq1 = deq;
	cout << "deque empty " << deq.empty() << " deque size " << deq.size() << endl;
	deq.resize(5);
	deq.pop_back();
	deq.pop_front();
	deq.insert(deq.begin() + 1, 100);
	deq.insert(deq.begin(), 2, 1009);
	deq.insert(deq.begin(), deq1.begin(), deq1.end());
	deq.erase(deq.end() - 2);
	deq.erase(deq.begin(), deq.begin() + 2);
	for (deque<int>::iterator it = deq.begin(); it != deq.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << deq[2] << endl;
	for (int i = 0; i < deq.size(); i++) {
		cout << deq[i] << " ";
	}
	cout << endl;
	deq.clear();
	// stack 不可遍历
	stack<int> stk;
	stk.push(1);
	stk.push(2);
	cout << "top " << stk.top() << " size " << stk.size() << endl;
	stk.pop();
	stk.empty();
	stack<int> stk1 = stk;
	// queue 单向队列 不可遍历
	queue<int> qe;
	qe.push(1);
	qe.push(3);
	qe.empty();
	qe.size();
	qe.front();
	qe.back();
	qe.pop();
	queue<int> qe1 = qe;
	// list 双向循环链表
	list<int> lt;
	list<int> lt1 = lt;
	lt.swap(lt1);
	lt.empty();
	lt.size();
	lt.resize(4);
	lt.push_back(1);
	lt.push_back(3);
	lt.push_front(0);
	lt.pop_back();
	lt.pop_front();
	lt.insert(lt.begin(), 1000);
	cout << lt.front() << endl;;
	cout << lt.back() << endl;;
	//lt.erase(lt.end());
	//lt.remove(1000);
	//lt.clear();
	// list不支持[]下标存取
	// list 迭代器只能用it++ it-- ++it --it 不支持随机访问
	//lt.reverse();
	//lt.sort(); // lt.sort(func)
	// set multiset 元素插入时就排序 set中元素不可重复 multiset可包含重复元素
	set<int> ste;
	set<int> ste1 = ste;
	set<int>ste2(ste);
	ste.insert(2);
	ste.insert(20);
	cout << ste.empty() << endl;
	cout << ste.size() << endl;;
	//ste.erase(ste.end());
	//ste.erase(ste.begin(), ste.end());
	//ste.erase(20);
	//ste.clear();
	//ste.swap(ste1);
	//ste.find(30); // 返回元素位置迭代器，未找到时返回ste.end()
	cout << ste.count(30) << endl; // 返回30的个数
	multiset<int> ms;
	ms.insert(12);
	ms.insert(12);
	// pair
	pair<string, int> pr("we", 3);
	cout << "pair first " << pr.first << endl;
	cout << "pair second " << pr.second << endl;
	// map multimap

	// 算法

	return 0;
}

Circle* v = new Circle(1, 2); // new一个对象指针

// 左移运算符重载 全局函数实现
ostream& operator<<(ostream& cout, Circle c) {
	cout << "左移运算符重载输出 c.R=" << c.R;
	return cout;
}
// 类模板做函数参数
// 1 推荐
void printTemp(Temp<int, string>& t) {
	cout << "类模板做函数参数1 " << t.x << " " << t.y << endl;
}
// 2
template<typename T, typename E>
void printTemp1(Temp<T, E>& t) {
	cout << "类模板做函数参数2 " << t.x << " " << t.y << endl;
}
// 3
template<typename T>
void printTemp2(T& t) {
	cout << "类模板做函数参数3 " << t.x << " " << t.y << endl;
}
// 函数做参数
void fun(int i) {
	cout << "函数做参数 i= " << i << endl;
}
void usefunc(void (*func)(int i), int j) {
	func(j);
}