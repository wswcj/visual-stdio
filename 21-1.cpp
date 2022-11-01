#include<iostream>
using namespace std;

class base {
public:
	base() {};
	base(int val) {
		this->a = val;
	}
	void showBase() {
		cout << "base" << endl;
	}
	void showBase(int) {
		cout << "base-int" << endl;
	}
	int a;
};

class son : public base {
public:
	son() {
		this->a = 10;
	}
	void showBase() {
		cout << "son" << endl;
	}
};
void test1() {
	son  s1;
	cout << s1.a << endl;
	cout << s1.base::a << endl;
	s1.showBase();
	s1.base::showBase();
	s1.base::showBase(10);
}
class animal {
public:
	int a;
};
class sheep : virtual public animal {};
class tou : virtual public animal {};
class sheepTou : virtual public sheep, public tou {};

void test2() {
	sheepTou st;
	st.a = 10;
	st.sheep::a = 20;
	st.tou::a = 30;
	cout << st.a << endl;
	cout << st.sheep::a << endl;
	cout << st.tou::a << endl;
}
class animal1 {
public:
	virtual void speak() {
		cout << "动物再说话" << endl;
	}
};
class dog : public animal1 {
public:
	void speak() {
		cout << "小狗在说话" << endl;
	}
};
class cat : public animal1 {
public:
	void speak() {
		cout << "小猫在说话" << endl;
	}
};
void dospeak(animal1* animal1) {
	animal1->speak();
}
void test3() {
	dog* d1 = new dog;
	cat* c1 = new cat;
	dospeak(d1);
	dospeak(c1);
}
class base1 {
public:
	virtual void func() = 0;
};
class son1 : public base1 {
public:
	void func() {
		cout << "fun" << endl;
	}
};
void test4() {
	base1* base = NULL;
	//base1* base = new base1;包含了纯虚函数的类不能实例化对象
	base = new son1;
	base->func();
	delete base;
}
class animal2 {
public:
	virtual void speak() {
		cout << "动物在说话" << endl;
	}
	virtual ~animal2() = 0;
};
animal2::~animal2() {
	cout << "animal2析构函数" << endl;
}
class cat2 : public animal2 {
public:
	cat2(string name) {
		this->name = new string(name);
	}
	void speak() {
		cout << *name << "在说话" << endl;
	}
	~cat2() {
		cout << "cat2析构函数" << endl;
		if (name != NULL) {
			delete name;
			name = NULL;
		}
	}
	string* name;
};
void test5() {
	cat2* cat = new cat2("tom");
	cat->speak();
	delete cat;
	animal2* animal = new cat2("tom");
	animal->speak();
	delete animal;
}
int main() {
	test5();
	return 0;
}