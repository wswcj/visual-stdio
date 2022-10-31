#include<iostream>
using namespace std;

int& function() {
	static int a = 0;
	return a;
}
void test1() {
	int& ref = function();
	cout << ref << endl;
	function() = 100;
	cout << ref << endl;
	const int& ret = 10;// int tmp = 10; int& ret = tmp;
}
class Person {
public:
	Person(int age, string name, int* height) : age(age), name(name), height(height) {};
	/*Person(const Person& p) {
		this->age = p.age;
		this->name = p.name;
	}*/
	//深拷贝构造函数：
	Person(const Person& p) {
		age = p.age;
		name = p.name;
		height = new int(*p.height);
	}
	static void func() {
		cout << "静态函数" << endl;
	}
	~Person() {
		//cout << "析构函数" << endl;
		if (height != NULL) {
			delete height;
		}
	}

public:
	int age;
	string name;
	int* height;
};
void test2() {
	int* height = new int(10);
	Person p1(10, "hh", height);
	//Person(10, "hh", height);//匿名对象，执行完后会立即回收
	Person p2(p1);
	cout << "height= " << *p2.height << endl;
	//Person(p2);会认为Person（p2）-> Person p2;
}
class manage {
public:
	static void fun() {
		cout << "静态函数" << endl;
		cout << "age = " << age << endl;
		//cout << id << endl;非静态类型无法访问静态成员函数
	}
	manage& manageAdd(manage m) {
		this->age += m.age;
		return *this;
	}
	static int age;
	//int id;
};
int manage::age = 10;
void test3() {
	manage m1;
	cout << "age = " << m1.age << endl;
	m1.fun();
	cout << sizeof(m1) << endl;
	manage m2;
	cout << "m2.age = " << m2.age << endl;
	m2.manageAdd(m1).manageAdd(m1).manageAdd(m1);//因为age是静态成员
	cout << "m2.age = " << m2.age << endl;
}
class boss {
public:
	void showboss() {
		cout << "boss1" << endl;
	}
	void showbossname() {
		if (this == NULL) {
			return;
		}
		cout << "boss2" << endl;
	}
};
void test4() {
	boss* p = NULL;
	p->showbossname();
	p->showboss();
}
class work {
public:
	work(int a, int b) : a(a), b(b) {};
	void func() const {
		this->b = 100;
		//this->a = 100;
	}
	int a;
	mutable int b;//在常函数中也可以修改值
};
void test5() {
	work w(10, 10);
	w.func();
	cout << "a = " << w.a << " b = " << w.b << endl;
	const work w1(10, 10);
	//w1.a = 100;
	w1.b = 100;//常对象也可以修改
	cout << "a = " << w1.a << " b = " << w1.b << endl;
}
class building;
class goodGay {
public:
	goodGay();
	void visit();
private:
	building* building1;
};
class building {
	friend class goodGay;
public:
	building();
public:
	string sittingRoom;
private:
	string bedRoom;
};
goodGay::goodGay() {
	building1 = new building;
}
void goodGay::visit() {
	cout << "正在访问：" << building1->sittingRoom << endl;;
	cout << "正在访问：" << building1->bedRoom << endl;
}
building::building() {
	this->sittingRoom = "客厅";
	this->bedRoom = "卧室";
}
void test6()
{
	goodGay gg;
	gg.visit();
}
class personAdd {
public:
	personAdd() {};
	personAdd(int a, int b) {
		this->a = a;
		this->b = b;
	}
	personAdd operator+ (const  personAdd& p) {
		personAdd tmp;
		tmp.a = a + p.a;
		tmp.b = b + p.b;
		return tmp;
	}
public:
	int a;
	int b;
};
personAdd operator+ (const personAdd& p, int val) {
	personAdd tmp;
	tmp.a = p.a + val;
	tmp.b = p.b + val;
	return tmp;
}
void test7() {
	personAdd p1(10, 10);
	personAdd p2(10, 10);
	personAdd p3;
	p3 = p1 + p2 + p2;
	cout << "p3.a = " << p3.a << " p3.b = " << p3.b << endl;
	personAdd p4;
	p4 = p1 + 10;
	cout << "p4.a = " << p4.a << " p4.b = " << p4.b << endl;
}
class ofs_person {
public:
	friend ostream& operator<<(ostream& out, ofs_person p);
	ofs_person() {};
	ofs_person(int age, string name) {
		this->age = age;
		this->name = name;
	}
private:
	int age;
	string name;
};
ostream& operator<<(ostream& out, ofs_person p) {
	out << " age: " << p.age << " name: " << p.name;
	return out;
}
void test8() {
	ofs_person p1(10, "hh");
	cout << p1 << endl;
}
class myInterger {
	friend ostream& operator<<(ostream& out, myInterger p);//myInterger不能加引号，interger写错了是integer
public:
	myInterger() {
		num = 0;
	}
	myInterger& operator++() {
		num++;
		return *this;
	}
	myInterger operator++(int) {
		myInterger tmp = *this;
		num++;
		return tmp;
	}
private:
	int num;
};
ostream& operator<<(ostream& out, myInterger p) {
	out << " num = " << p.num;
	return out;
}
void test9() {
	myInterger m;
	cout << "num++: " << m++ << endl;
	cout << m << endl;
	cout << "++num: " << ++m << endl;
	cout << m << endl;
	cout << "++(++m): " << ++(++m) << endl;
	
}
class oldman {
public:
	oldman() {};
	oldman(int* age) {
		this->age = age;
	}
	oldman& operator=(oldman& m) {
		if (age != NULL) {
			delete age;
			age = NULL;
		}
		age = new int(*m.age);
		return *this;
	}
	bool operator==(oldman& m) {
		if (*this->age == *m.age) {//注意age是地址
			return true;
		}
		else {
			return false;
		}
	}
	~oldman() {
		if (age != NULL) {
			delete age;
			age = NULL;
		}
	}
public:
	int* age;
};
void test10() {
	int* a = new int(10);
	oldman m1(a);
	oldman m2;
	m2 = m1;
	cout << "m2.age = " << *m2.age << endl;
	bool ret = m1 == m2;
	if (ret) {
		cout << "m1 = m2" << endl;
	}
	else {
		cout << "m1 != m2" << endl;
	}
}
class myAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};
void test11() {
	class myAdd Add;
	int a = Add(10, 20);
	cout << "a = " << a << endl;
}
int main() {
	test11();
	return 0;
}