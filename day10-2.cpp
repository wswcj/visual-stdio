#include<iostream>
using namespace std;

class cpu
{
public:
	virtual void calculate() = 0;
};

class videocard
{
public:
	virtual void display() = 0;
};

class memory
{
public:
	virtual void storage() = 0;
};

class computer
{
public:
	computer(cpu* cpu, videocard* vc, memory* mem)
	{
		this->cpu = cpu;
		this->vc = vc;
		this->mem = mem;
	}
	void work()
	{
		cpu->calculate();
		vc->display();
		mem->storage();
	}
	~computer()
	{
		if (cpu != NULL)
		{
			delete cpu;
			cpu = NULL;
		}
		if (vc != NULL)
		{
			delete vc;
			vc = NULL;
		}
		if (mem != NULL)
		{
			delete mem;
			mem = NULL;
		}
	}
private:
	cpu* cpu;
	videocard* vc;
	memory* mem;
};

class intelcpu :public cpu
{
public:
	virtual void calculate()
	{
		cout << "intel的cpu开始工作了" << endl;
	}
};

class intercard :public videocard
{
public:
	virtual void display()
	{
		cout << "intel的显卡开始工作了" << endl;
	}
};

class intelmem :public memory
{
public:
	virtual void storage()
	{
		cout << "intel的内存条开始工作了" << endl;
	}
};

void test()
{
	cpu* intelcpu1 = new intelcpu;
	videocard* intelcard1 = new intercard;
	memory* intelmem1 = new intelmem;
}
int main()
{
	
	return 0;
}