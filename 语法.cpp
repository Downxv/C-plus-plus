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

// �곣���ͳ���
#define MAX 20
const int MIN = 1;
ostream& operator<<(ostream& cout, Circle c);
void fun(int i);
void usefunc(void (*func)(int i), int j);
// �ṹ��
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
	// ����ע��
	/*����ע��*/
	// ���α���
	int a = 10;
	short b = 5;
	long c = 15;
	long long d = 20;
	cout << "int " << sizeof(a) << " short " << sizeof(b) << " long " << sizeof(c) << " long long " << sizeof(d) << endl;
	// ����
	cout << "MAX = " << MAX << " MIN = " << MIN << endl;
	// ������
	float e = 3.14f; // 7λ��Ч����
	double f = 3.1415; // 15~16λ��Ч����
	cout << "float " << sizeof(float) << " double " << sizeof(double) << endl;
	// �ַ���
	char ch = 'x';
	cout << "char " << sizeof(char) << endl;
	ch = 97;
	cout << ch << " " << int(ch) << endl;
	// ת���ַ� ��
	// �ַ���
	string str = "kkkk";
	cout << "�ַ��� " << str << endl;
	// ������
	bool bl = false;
	cout << "bool " << sizeof(bool) << endl;
	// �������� cin >> ���� ��
	// ����� + - * / % ++ -- = += -= *= /= %= == != < > <= >= ! && ||
	// ���̿���
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

	// break continue ��

	// ����
	int arr[5];
	arr[0] = 0;
	int arr1[4] = { 1,2 };
	int arr2[] = { 3,4,5 };
	for (int i = 0; i < 4; i++) {
		cout << arr1[i];
	}
	cout << endl;
	cout << "���鿪ʼ�ڴ��ַ:" << arr << "����Ԫ�ظ���:" << sizeof(arr) / sizeof(arr[0]) << endl;

	int da1[2][4];
	int da2[2][3] = {
		{1,2,3},
		{4,5,6},
	};
	// ����
	cout << add(9, 8) << endl;
	cout << max(2, 3) << endl;
	// ָ��
	int p = 0;
	int* ptr = &p;
	cout << *ptr << endl;
	cout << sizeof(ptr) << endl;
	int* ptr1 = NULL; // ��ָ��
	const int* ptr2; // ����ָ�� ָ��ɸģ�ָ���ֵ���ɸ�
	int* const ptr3 = NULL; // ָ�볣��
	const int* const ptr4 = NULL;
	int arr3[] = { 1,2,3 };
	ptr2 = &arr3[0];
	for (int i = 0; i < 3; i++) {
		cout << *ptr2;
		ptr2++;
	}
	cout << endl;
	// ָ��������
	int aa = 0, bb = 1;
	iswap(&aa, &bb);
	cout << aa << " " << bb << endl;
	// ����������
	usefunc(fun, 19);
	// �ṹ��
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
	//new �ؼ��� ����ջ����
	int* i = new int(12);
	cout << *i << endl;
	delete i;
	int* ii = new int[10];
	ii[0] = 2;
	delete[] ii;
	// ���� ����->�����������
	int x = 10;
	int& xx = x; // ��ʼ�����ܸı�
	cout << xx << endl;
	int aaa = 20, bbb = 30;
	wswap(aaa, bbb); // ���ô���
	cout << aaa << " " << bbb << endl;
	int su = sum(20);
	cout << su << endl;
	// ��Ͷ��� ��װ �̳� ��̬
	Circle cc(3, 2); // ����Ĭ�Ϲ��캯��ʱ����() �ᱻ����Ϊ��������
	cc.R = 12;
	cout << cc.get_ZC() << endl;
	cp(cc); // ����������캯��
	// �������Ϊ���Ա l��
	// ��̬��Ա
	cout << cc.a << " " << Circle::a << endl;
	cc.st();
	// thisָ�� ��ָ�볣�� ָ���Ա[����]���������Ķ��󣬺����ɷ���*this<������>
	cc.next().next().next();
	// ������ ������
	cc.pt();
	const Circle ccc(9, 8);
	ccc.pt(); // ������ֻ�ܵ��ó�����
	// ��Ԫ �ú����������һ�����е�˽�г�Ա
	h_self(cc);
	Cfriend* cf = new Cfriend;
	cf->read(cc);
	// ���������
	Circle cce(0, 0);
	cce = cce + cc;
	cout << "cce.R=" << cce.R << endl;
	cce = cce + 10;
	cout << "cce.R=" << cce.R << endl;
	cout << cce << endl;
	cout << cce++ << endl;
	cout << ++cce << endl;
	cout << cce << endl;
	// �̳�
		// �����븸��ͬ��<��̬>����/<��̬>�������÷���
	Gra g;
	cout << "���ྲ̬���� a=" << Gra::Circle::a << endl;
	cout << "Gra-R" << g.R << "Circle-R" << g.Circle::R << endl; // ������ø���ͬ������ ��������
	g.ptn();
	g.Circle::ptn(); // ������ø���ͬ������
	// g.ptn(1); ���ó�����Ϊ����ͬ�����������ص�����ͬ���������������أ���Ҫ�Ӹ���������
	g.Circle::ptn(3);
	// ��̳� ������ʹ�� �﷨ class A : public B, public C{}
	// ���μ̳н��ͬ���������� ʹ����̳� class A:virtual public B{} ��
	// ��̬ ��̬���������� ��������أ� ��̬��������/�麯������ʱ��̬ ��ַ��󶨣�
	// ��̬��̬����  1 �̳й�ϵ 2 ������д�����麯�� 3 dospeak�и������ã���ָ�룩ָ���Ӷ���
	Cat cat;
	Dog dog;
	dospeak(cat); // ������
	dospeak(dog);
	Animal* al = new Cat; // ָ����
	al->speak();
	delete al; // ����������� ��alָ��û��
		// ���麯�� ������ ��
	//�ļ����� ofstream д ifstream �� fstream ��д
	ofstream ofs;
	ofs.open("test.txt", ios::out | ios::trunc);
	if (ofs.is_open()) {
		ofs << "C++д���ı��ļ�" << endl;
	}
	ofs.close();
	ofs.open("test.txt", ios::app);
	if (ofs.is_open()) {
		ofs << "׷�ӷ�ʽд��" << endl;
	}
	ofs.close();
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ifs.is_open()) {
		// ��һ��
		cout << "��ȡ�ļ�" << endl;
		char buf[1024] = { 0 };
		//while (ifs >> buf) { // ���ж�ȡ
		//	cout << buf << endl;
		//}
		// �ڶ���
		//while (ifs.getline(buf, sizeof(buf))) {
		//	cout << buf << endl;
		//}
		// ������ �Ƽ�
		string str;
		while (getline(ifs, str)) {
			cout << str << endl;
		}
		// ������
		//char ccc = '0';
		//while ((ccc = ifs.get()) != EOF) {
		//	cout << ccc;
		//}
	}
	else {
		cout << "��ȡʧ��" << endl;
	}
	ifs.close();
	// �����Ʒ�ʽ��д�ļ�
	char cx[64] = { 97 }; // ������д�뽨�����ַ����������string
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
		cout << "�������ļ���ȡ cr=" << cr[0] << endl;
		ifsbin.read((char*)&ccle, sizeof(ccle));
		cout << "�������ļ���ȡ ccle.R=" << ccle.R << endl;
	}
	ifsbin.close();
	// ģ�� ����
	float aaaa = 1.2f;
	float bbbb = 2.3f;
	myswap<float, int>(aaaa, bbbb); // ��ʾָ������ �Ƽ�
	cout << "aaaa= " << aaaa << "bbbb= " << bbbb << endl;
	Temp<int, string> tp(1, "str");
	cout << "temp " << tp.x << " " << tp.y << endl;
	printTemp(tp);
	printTemp1(tp);
	printTemp2(tp);
	// ģ������Ԫ
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
	// vector ������Ƕ��
	vector<int> v;
	v.push_back(12);
	v.push_back(92);
	vector<int> v1 = v; // ��ֵ
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
	int vv = v[0];	vector<int>(v).swap(v); // �����ڴ�
	v.reserve(10); // Ԥ���ڴ� �����������ʱ���ٿ����ڴ�Ĵ���

	// deque ˫������
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
	// stack ���ɱ���
	stack<int> stk;
	stk.push(1);
	stk.push(2);
	cout << "top " << stk.top() << " size " << stk.size() << endl;
	stk.pop();
	stk.empty();
	stack<int> stk1 = stk;
	// queue ������� ���ɱ���
	queue<int> qe;
	qe.push(1);
	qe.push(3);
	qe.empty();
	qe.size();
	qe.front();
	qe.back();
	qe.pop();
	queue<int> qe1 = qe;
	// list ˫��ѭ������
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
	// list��֧��[]�±��ȡ
	// list ������ֻ����it++ it-- ++it --it ��֧���������
	//lt.reverse();
	//lt.sort(); // lt.sort(func)
	// set multiset Ԫ�ز���ʱ������ set��Ԫ�ز����ظ� multiset�ɰ����ظ�Ԫ��
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
	//ste.find(30); // ����Ԫ��λ�õ�������δ�ҵ�ʱ����ste.end()
	cout << ste.count(30) << endl; // ����30�ĸ���
	multiset<int> ms;
	ms.insert(12);
	ms.insert(12);
	// pair
	pair<string, int> pr("we", 3);
	cout << "pair first " << pr.first << endl;
	cout << "pair second " << pr.second << endl;
	// map multimap

	// �㷨

	return 0;
}

Circle* v = new Circle(1, 2); // newһ������ָ��

// ������������� ȫ�ֺ���ʵ��
ostream& operator<<(ostream& cout, Circle c) {
	cout << "���������������� c.R=" << c.R;
	return cout;
}
// ��ģ������������
// 1 �Ƽ�
void printTemp(Temp<int, string>& t) {
	cout << "��ģ������������1 " << t.x << " " << t.y << endl;
}
// 2
template<typename T, typename E>
void printTemp1(Temp<T, E>& t) {
	cout << "��ģ������������2 " << t.x << " " << t.y << endl;
}
// 3
template<typename T>
void printTemp2(T& t) {
	cout << "��ģ������������3 " << t.x << " " << t.y << endl;
}
// ����������
void fun(int i) {
	cout << "���������� i= " << i << endl;
}
void usefunc(void (*func)(int i), int j) {
	func(j);
}