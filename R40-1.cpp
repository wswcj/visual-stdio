#include<iostream> 
using namespace std;
class Base1 {
public:
	Base1() {
		a = 100;
	}
	void fun() {
		cout << "Base-fun" << endl;
	}
	void fun(int v) {
		cout << "Base-fun(int)" << endl;
	}
public:
	int a;
};
class son1 : public Base1 {
public:
	son1() {
		a = 200;
	}
	void fun() {
		cout << "son-fun" << endl;
	}
public:
	int a;
};
void test1() {//静态成员同下
	son1 s;
	cout << s.a << endl;
	cout << s.Base1::a << endl;
	s.fun();
	s.Base1::fun();
	//s.fun(1);//不加作用域会报错
	s.Base1::fun(1);
	
}
class Base2 {
public:
	int a;
};
class son2 : public Base1, public Base2 {//多继承语法
public:
	int b;
};
class Animal {
public:
	int a;
}; 
//                                            虚继承
class Sheep : virtual public Animal {};
class Tou : virtual public Animal {};
class SheepTou : public Sheep, public Tou{};
void test2() {
	SheepTou st;
	st.Sheep::a = 100;
	st.Tou::a = 200;
	cout << st.Sheep::a << endl;
	cout << st.Tou::a << endl;
	cout << st.a << endl;

}
//                                            多态
class Animal1 {
public:
	virtual void speak() {//先给speak加上virtual
		cout << "动物在说话" << endl;
	}
};
class Cat : public Animal1{//然后子类重写父类虚函数
public:
	void speak() {//重写:返回值,函数名,参数列表都不变
		cout << "猫在说话" << endl;
	}
};
class Dog : public Animal1{
public:
	void speak() {
		cout << "狗在说话" << endl;
	}
};
void test3() {
	Animal1* cat = new Cat;//父类指针指向子类对象
	cat->speak();
	Animal1* dog = new Dog;
	dog->speak();
	Cat cat1;
	Animal1& animal = cat1;//父类引用子类对象
	animal.speak();
	Dog dog1;
	Animal1& animal1 = dog1;
	animal1.speak();

}
//                                    多态实现计算机
class AbstractorCalculator {
public:
	virtual int getResult() {
		return 0;
	}

public:
	int a;
	int b;
};
class AddCalculator : public AbstractorCalculator{
public:
	int getResult() {
		return a + b;
	}
};
class SubCalculator : public AbstractorCalculator {
public:
	int getResult() {
		return a - b;
	}
};
class MulCalculator : public AbstractorCalculator {
public:
	int getResult() {
		return a * b;
	}
};
void test4() {
	AbstractorCalculator* ad = new AddCalculator;
	ad->a = 10;
	ad->b = 20;
	cout << ad->getResult() << endl;
	delete ad;//用完记得释放

	ad = new SubCalculator;//注意重新给ad创建空间后 a 和 b  的值没有初始化
	ad->a = 10;
	ad->b = 20;
	cout << ad->getResult() << endl;
	delete ad;

	ad = new MulCalculator;
	ad->a = 10;
	ad->b = 20;
	cout << ad->getResult() << endl;
	delete ad;
}
class Base3 {
public:
	//类内只要有纯虚函数就是抽象类
	virtual void fun() = 0;//纯虚函数
};
class Son3 : public Base3 {
public:

	//子类必须重写父类纯虚函数,不然也是抽象类
	virtual void fun() {
		cout << "son-fun" << endl;
	}
};
void test5() {
	Base3* base = new Son3;
	//base = new Base3; 错误抽象类无法实例化对象
	base->fun();
	delete base;
}
class Base4 {
public:
	Base4() {
		cout << "Base构造函数调用" << endl;
	}
	virtual  void speak() = 0;
	virtual ~Base4() = 0;//纯虚析构(抽象类)
};
Base4::~Base4() {//纯虚析构也可以在外面定义
	cout << "纯虚析构调用" << endl;
}
class Son4 : public Base4 {
public:
	Son4(string name) : name(new string(name)) {}
	virtual void speak() {
		cout << *name << "在说话" << endl;
	}
	~Son4() {//重写父类纯虚析构
		if (name != NULL) {
			delete name;
			name = NULL;
		}
	}
public:
	string* name;
};
void test6() {
	Base4* base = new Son4("tom");//虚析构函数是为了解决通过父类指针释放子类对象子类释放不干净的问题
	base->speak();
	delete base;
}
int main() {
	test6();
	return 0;
}