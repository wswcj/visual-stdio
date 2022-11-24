#pragma once
#include<iostream>
using namespace std;
void func1(int a) {
	cout << "int a" << endl;
}
void fun1(int& a) {
	cout << "int& a" << endl;//非常量引用的初始值必须为左值,所以是错误的
}
void fun1(const int& a) {
	cout << "const int& a" << endl;
}//函数重载调用优先级const int& a > int& a > int
void test1() {
	fun1(10);
}
struct F1 {
	int a;
};
class F2 {//默认权限是私用
	int a;
};
void test2() {
	F1 f1;
	f1.a = 3;
	F2 f2;
	cout << f1.a << endl;
	//cout << f2.a << endl;私用
}
class Person1 {
public:
	Person1() {}
	Person1(int age, int height) {
		this->age = age;
		this->height = new int(height);
	}
	//浅拷贝--运行会崩掉,因为会重复释放同一片内存空间
	/*Person1(const Person1& p) {
		this->age = p.age;
		this->height = p.height;
	}*/
	//深拷贝
	Person1(const Person1& p) {
		this->age = p.age;
		this->height = new int(*p.height);
	}
	~Person1() {
		delete height;
		height = nullptr;
	}
public:
	int age;
	int* height;
};
void test3() {
	Person1 p1(10, 2);
	Person1 p2(p1);
	cout << p2.age << " " << *p2.height << endl;
}
class Person2 {
public:
	Person2() : a(10), b(20), c(30) {

	}
	Person2(int a, int b, int c) : a(a), b(b), c(c) {
		a = a;
		b = b;
		c = c;
	}
public:
	int a;
	int b;
	int c;
};
void test4() {
	Person2 p;
	cout << p.a << " " << p.b << " " << p.c << endl;
	Person2 p1(1, 2, 3);
	cout << p1.a << " " << p1.b << " " << p1.c << endl;
}

//静态成员函数和静态成员变量所以对象共享同一份数据
class Person3 {
public:
	Person3() {}
	static void func() {
		cout << "static void func" << endl;
		cout << a << endl;
		//cout << b << endl;静态成员只能访问静态成员变量
	}
public:
	int b;
	static int a;
private:
	static void func1() {
		cout << "func1() " << endl;
	}
};

int Person3::a = 10;//类内声明,内外实现,在编译阶段分配内存
void test5() {
	Person3::func();
	Person3 p;
	p.a = 20;
	Person3 p1;
	cout << p1.a << endl;
}
class Person4 {
public:
	int a;//属于对象上
	static int b;//不属于,下同
	void func1();
	static void func2();
};
int Person4::b = 10;
void test6() {
	Person4 p;
	//空对象占用内存空间: 1
	cout << sizeof(p) << endl;//输出4
}
class Person5 {
public:
	Person5() {}
	Person5(int age) {
		this->age = age;
	}
	Person5& addAge(Person5 p) {
		this->age += p.age;
		return *this;
	}
public:
	int age;
};
void test7() {
	Person5 p(10);
	Person5 p1(10);
	p.addAge(p1).addAge(p1).addAge(p1);//从左到右,先p.addAge(p1)再.addAge(p1).addAge(p1);
	cout << p.age << endl;//40
}
class Person6 {
public:
	Person6() {}
	Person6(int a) {
		this->a = a;
	}
	void showPerson() {
		//保证代码的健壮性,没有的话this指针为空访问this->a会报错
		if (this == nullptr) {
			return;
		}
		cout << this->a << endl;
	}
public:
	int a;
};
//空指针也能调用成员函数
void test8() {
	Person6* p = nullptr;
	p->showPerson();

}
class Person {
public:
	Person() {}
	Person(int a, int b) : a(a), b(b) {

	}
	//this指针的本质: Person* const this
	//在成员函数后加const相当于const Person* const this
	void show() const {
		//this->a = 100;不可以修改常量
		//this = nullptr;不可以修改常量指针
		cout << a << endl;
		this->b = 100;
		cout << b << endl;
	}
public:
	int a;
	mutable int b;//特殊变量,在常量函数里也能被修改
};
void test9() {
	const Person p(10, 20);//常对象
	//p.a = 20;常对象不能修改数据
	p.b = 30;//特殊值可以在常对象下被修改
	p.show();//常对象只能调用常函数,因为普通函数会修改属性
}
int main() {
	test9();
	return 0;
}