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
#include <map>
#include<algorithm>
#include<numeric>
#include<thread>
#include<mutex>
using namespace std;
// C++中尽量用string替代char【】
// 宏常量和常量
#define MAX 20
const int MIN = 1;
ostream& operator<<(ostream& cout, Circle c);
void fun(int i);
void usefunc(void (*func)(int i), int j);
void yichang(int num);
// 结构体
struct people {
    string name;
    int age;
};

struct man {
    people p;
    string money;
};
// 枚举类型
enum day {
    Monday,
    Tuesday,
};


int main() {
    int* ptrs = nullptr;
    cout << "line35 hello world " << endl;
    // 单行注释
    /*多行注释*/
    // 整形变量
    int a = 10;
    short b = 5;
    long c = 15;
    long long d = 20;
    cout << "line43 int " << sizeof(a) << " short " << sizeof(b) << " long " << sizeof(c) << " long long " << sizeof(d) << endl;
    // 常量
    cout << "line45 MAX = " << MAX << " MIN = " << MIN << endl;
    // 浮点型
    float e = 3.14f; // 7位有效数字
    double f = 3.1415; // 15~16位有效数字
    cout << "line49 float " << sizeof(float) << " double " << sizeof(double) << endl;
    // 字符型
    char ch = 'x';
    cout << "line52 char " << sizeof(char) << endl;
    ch = 97;
    cout << "line54 " << ch << " " << int(ch) << endl;
    // 转义字符 略
    // 字符串
    string str = "kkkk";
    cout << "line58 字符串 " << str << endl;
    // 布尔型
    bool bl = false;
    cout << "line61 bool " << sizeof(bool) << endl;
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
    cout << "line76 " << t << endl;

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
        cout << "line114 " << arr1[i];
    }
    cout << endl;
    cout << "line117 数组开始内存地址:" << arr << "数组元素个数:" << sizeof(arr) / sizeof(arr[0]) << endl;

    int da1[2][4];
    int da2[2][3] = {
        {1,2,3},
        {4,5,6},
    };
    // 函数 ， 形参可带默认参数
    cout << "line125 " << add(9, 8) << endl;
    cout << "line126 " << max(2, 3) << endl;
    // 指针
    int p = 0;
    int* ptr = &p;
    cout << "line130 " << *ptr << endl;
    cout << "line131 " << sizeof(ptr) << endl;
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
    cout << "line146 " << aa << " " << bb << endl;
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
    cout << "line163 " << p3[1].age << " " << p4->name << endl;
    man m = {
        {"op", 43},
        "many"
    };
    cout << "line168 " << m.p.name << endl;
    //new 关键字 开辟栈堆区
    int* i = new int(12);
    cout << "line171 " << *i << endl;
    delete i;
    int* ii = new int[10];
    ii[0] = 2;
    delete[] ii;
    // 引用 作用->给变量起别名
    int x = 10;
    int& xx = x; // 初始化后不能改变
    cout << "line179 " << xx << endl;
    int aaa = 20, bbb = 30;
    wswap(aaa, bbb); // 引用传参
    cout << "line182 " << aaa << " " << bbb << endl;
    int su = sum(20);
    cout << "line184 " << su << endl;
    // 类和对象 封装 继承 多态
    Circle cc(3, 2); // 调用默认构造函数时不加() 会被误认为函数声明
    cc.R = 12;
    cout << "line188 " << cc.get_ZC() << endl;
    cp(cc); // 调用深拷贝构造函数
    // 类对象作为类成员 略
    // 静态成员
    cout << "line192 " << cc.a << " " << Circle::a << endl;
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
    // 运算符重载 函数重载
    Circle cce(0, 0);
    cce = cce + cc;
    cout << "line207 " << "cce.R=" << cce.R << endl;
    cce = cce + 10;
    cout << "line209 " << "cce.R=" << cce.R << endl;
    cout << "line210 " << cce << endl;
    cout << "line211 " << cce++ << endl;
    cout << "line212 " << ++cce << endl;
    cout << "line213 " << cce << endl;
    // 继承
        // 子类与父类同名<静态>属性/<静态>函数调用方法
    Gra g;
    cout << "line217 " << "父类静态属性 a=" << Gra::Circle::a << endl;
    cout << "line218 " << "Gra-R" << g.R << "Circle-R" << g.Circle::R << endl; // 子类调用父类同名属性 加作用域
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
        cout << "二进制文件读取 ccle.R=" << ccle.R << endl; // 存取类信息
    }
    ifsbin.close();
    // 模板 泛型
    float aaaa = 1.2f;
    float bbbb = 2.3f;
    myswap<float, int>(aaaa, bbbb); // 显示指定类型 推荐
    cout << "line300 " << "aaaa= " << aaaa << "bbbb= " << bbbb << endl;
    Temp<int, string> tp(1, "str");
    cout << "line302 " << "temp " << tp.x << " " << tp.y << endl;
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
    cout << "line315 " << ij << endl;
    ij = st1.find('e', 2);
    cout << "line317 " << ij << endl;
    ij = st1.rfind('o');
    cout << "line319 " << ij << endl;
    st1.replace(0, 2, "ppp");
    cout << "line321 " << st1 << endl;
    cout << "line322 " << st1.compare("aaallo") << endl; // [> 1] [< -1] [= 0]
    cout << "line323" << st1[5] << endl;
    st1[5] = 'e';
    cout << "line325 " << st1 << endl;
    cout << "line326 " << st1.size() << endl;
    st1.insert(2, "ddd");
    cout << "line328 " << st1 << endl;
    st1.erase(2, 4);
    cout << "line330 " << st1 << endl;
    cout << "line331 " << st1.substr(2, 5) << endl;
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
    int vv = v[0];
    vector<int>(v).swap(v); // 收缩内存
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
    cout << "line376 " << deq[2] << endl;
    for (int i = 0; i < deq.size(); i++) {
        cout << deq[i] << " ";
    }
    cout << endl;
    deq.clear();
    // stack 不可遍历
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    cout << "line386 " << "top " << stk.top() << " size " << stk.size() << endl;
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
    cout << "line413 " << lt.front() << endl;;
    cout << "line414 " << lt.back() << endl;;
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
    cout << "line428 " << ste.empty() << endl;
    cout << "line429 " << ste.size() << endl;;
    //ste.erase(ste.end());
    //ste.erase(ste.begin(), ste.end());
    //ste.erase(20);
    //ste.clear();
    //ste.swap(ste1);
    //ste.find(30); // 返回元素位置迭代器，未找到时返回ste.end()
    cout << "line436 " << ste.count(30) << endl; // 返回30的个数
    multiset<int> ms;
    ms.insert(12);
    ms.insert(12);
    // pair
    pair<string, int> pr("we", 3);
    cout << "line442 " << "pair first " << pr.first << endl;
    cout << "line443 " << "pair second " << pr.second << endl;
    // map multimap 按key值排序
    map<int, string> mp1;
    map<int, string> mp2(mp1);
    map<int, string> mp3 = mp2;
    mp1.insert(pair<int, string>(2, "kk"));
    mp1.insert(pair<int, string>(1, "kd"));
    map<int, string>::iterator itr = mp1.find(2);
    cout << "line451 " << "map find " << itr->second << endl;
    for (map<int, string>::iterator it = mp1.begin(); it != mp1.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    cout << "line455 " << "map empty " << mp1.empty() << " map size " << mp1.size() << endl;
    mp1.swap(mp2);
    mp2.erase(1);
    mp2.erase(mp2.begin());
    mp2.clear();
    map<int, string>::iterator it = mp2.find(1);
    if (it != mp2.end()) {
        cout << "map find " << it->second << endl;
    }
    else {
        cout << "map find 未找到" << endl;
    }
    cout << "line467 " << "map count " << mp2.count(1) << endl;
    // 算法
    // 重载了函数调用的类称为函数对象或仿函数
    Myadd ma;
    cout << "line471 " << "仿函数 " << ma(3, 2) << endl;
    printma(ma, 4, 5);
    // 谓词 （返回值为bool的仿函数）(一个形参为一元谓词，两个参数为二元谓词)
    // 算数仿函数 关系仿函数 包含在functional库中 略
    // 常用算法
    // for_each
    vector<int> vct;
    vct.push_back(1);
    vct.push_back(2);
    vct.push_back(3);
    vct.push_back(4);
    Mysum mm;
    for_each(vct.begin(), vct.end(), mm);
    vector<int> vct1;
    vct1.resize(vct.size());
    transform(vct.begin(), vct.end(), vct1.begin(), add10);
    cout << "line487 " << "vct1 " << *(vct1.begin()) << endl;
    vector<int>::iterator iti = find(vct1.begin(), vct1.end(), 11); // 查找自定义类型时需要重载==操作符
    cout << "line489 " << "find " << *iti << endl;
    vector<int>::iterator itt = find_if(vct1.begin(), vct1.end(), ifgt10); //
    cout << "line491 " << "find_if " << *itt << endl;
    cout << "line492 " << "binary_search " << binary_search(vct1.begin(), vct1.end(), 12) << endl; // 序列必须有序
    cout << "line493 " << "count " << count(vct1.begin(), vct1.end(), 11) << endl;
    cout << "line494 " << "count_if " << count_if(vct1.begin(), vct1.end(), ifgt10) << endl;
    sort(vct1.begin(), vct1.end(), greater<int>()); // greater是标准库中的仿函数，还有其他的类型
    random_shuffle(vct1.begin(), vct1.end()); // 乱序
    // merge()，
    reverse(vct1.begin(), vct1.end());
    copy(vct1.begin(), vct1.end(), vct.begin());
    replace(vct1.begin(), vct1.end(), 11, 99);
    replace_if(vct1.begin(), vct1.end(), ifgt10, 33);
    swap(vct1, vct);
    int ti = accumulate(vct.begin(), vct.end(), 0); // 累加
    fill(vct.begin(), vct.end(), 55);
    vector<int> vct2;
    vct2.resize(vct1.size() + vct.size());
    vector<int>::iterator tii_end = set_intersection(vct.begin(), vct.end(), vct1.begin(), vct1.end(), vct2.begin()); // 交集 返回的是迭代器
    vector<int>::iterator su_end = set_union(vct.begin(), vct.end(), vct1.begin(), vct1.end(), vct2.begin()); // 并集
    vector<int>::iterator sd_end = set_difference(vct.begin(), vct.end(), vct1.begin(), vct1.end(), vct2.begin()); // 差集
    // 异常
    try {
        yichang(0);
    } catch (const char* err) {
        cout << "line515 " << err << endl;
    }catch (...){
        cout << "line524 other exception" << endl;
    }
    // 多线程
    thread thread1(t1, "thread");
//    thread1.join();
    cout << "line530 " << thread1.joinable() << endl;
    thread1.detach(); // 线程分离
    // 传递引用局部变量的方式如下
    int aaaab = 1;
    thread thread2(t2, ref(aaaab));
    thread2.join();
    cout << "line536 a = " << a << endl;
    // 互斥量 资源竞争
    int bbbba = 0;
    thread thread3(t3, ref(bbbba));
    thread thread4(t3, ref(bbbba));
    thread3.join();
    thread4.join();
    cout << "line543 b= " << b << endl;
    // 枚举
    day da;
    da = Monday;
    switch(da) {
    case Monday:
        cout << "line549 Monday" << endl;
        break;
    case Tuesday:
        cout << "line552 Tuesday" << endl;
        break;
    default:
        break;
    }

    return 0;
}

void yichang(int num){
    if(num == 0){
        throw string("num can not be 0");
    }
    else{
        cout << (10.0 / num);
    }
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
// 多线程

