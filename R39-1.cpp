#include<iostream>
using namespace std;
class GoodGay {
public:
	void visit();
	void visit1();
};
class Building {
	friend class GoodGay;
	friend void test1();//全局函数的友元
	friend void GoodGay::visit();//成员函数做友元
public:
	Building() {
		bedRoom = "卧室";
	}
private:
	string bedRoom;
};
void GoodGay::visit() {
	Building* build = new Building;
	cout << build->bedRoom << endl;
}
void test1() {
	Building* build = new Building;
	cout << build->bedRoom << endl;
	GoodGay* gg = new GoodGay;
	gg->visit();
}
//重载 + 号运算符
class Person1 {
public:
	Person1() {}
	Person1(int a, int b) : a(a), b(b) {}
	Person1 operator+(const Person1& p) {
		Person1 tmp;
		tmp.a = this->a + p.a;
		tmp.b = this->b + p.b;
		return tmp;
	}
	Person1 operator+(int val) {
		Person1 tmp;
		tmp.a = this->a + val;
		tmp.b = this->b + val;
		return tmp;
	}
public:
	int a;
	int b;
};
void test2() {
	Person1 p1(1, 2);
	Person1 p2(3, 2);
	Person1 p3 = p1 + p2;
	cout << "a = " << p3.a << " b = " << p3.b << endl;
	p3 = p1 + 3;
	cout << "a = " << p3.a << " b = " << p3.b << endl;

}
//重载 << 运算符
class Person2 {
public:
	Person2() {}
	Person2(int a, int b) : a(a), b(b) {}
public:
	int a;
	int b;
};
ostream& operator<<(ostream& out, const Person2& p) {//注意ostream后不能少&!!!
	out << "p.a = " << p.a << " p.b = " << p.b;
	return out;
}
void test3() {
	Person2 p(1, 2);
	cout << p << endl <<  "hello world" << endl;
}
//重载 前置++ 和 后置++
class Person3 {
public:
	Person3() {}
	Person3(int a) : a(a) {}
	Person3& operator++() {//链式编程
		this->a++;
		return *this;
	}
	Person3 operator++(int) {//不可以加&,,返回的是局部变量
		Person3 tmp = this->a;
		this->a++;
		return tmp;
	}
public:
	int a;
};
//注意只能在全局重载
ostream& operator<<(ostream& out, const Person3& p) {//注意ostream后不能少&!!!
	out << "p.a = " << p.a;
	return out;
}
void test4() {
	Person3 p(3);
	cout << p++ << endl;//3
	cout << p << endl;//4
	cout << ++(++p) << endl;//6
}
//重载 赋值 运算符 
class Person4 {
public:
	Person4() {}
	Person4(int age) {
		this->age = new int(age);
	}
	Person4& operator+(Person4& p) {
		if (p.age) {
			delete this->age;
			this->age = nullptr;
		}
		this->age = new int(*p.age);
	}
public:
	int* age;
};
ostream& operator<<(ostream& out, const Person4& p) {
	out << "p.age = " << *p.age;
	return out;
}
void test5() {
	Person4 p1(10);
	Person4 p2 = p1;
	cout << p2 << endl;
}
//== < > !=重载 略
//函数调用运算符重载(又叫仿函数)
class Person5 {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};
void test6() {
	Person5 p;
	cout << p(1, 2) << endl;
}
int main() {
	test6();
	return 0;
}