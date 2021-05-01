include <iostream>

using namespace std;

/*
рассматриваются 2 цепочки наследования:
1) A1 - B1 - C1
2) A2 - B2 - C2
В первой используюется статический полиморфизм
(альтернативные термины: статическое или раннее связывание).
Во второй используется динамический полиморфизм
(альтернативные термины: динамическое или позднее связывание).
Это достигается за счёт использования виртуальных функций.
Обратите внимание на виртуализацию деструкторов.
*/

class A1
{
public:
	A1() { cout << "Constructor A1" << endl; }
	void func () { cout << "func in A1" << endl; }
	~A1() { cout << "Destructor A1" << endl; }
};

class B1 : public A1
{
public:
	B1() { cout << "Constructor B1" << endl; }
	void func() { cout << "func in B1" << endl; }
	~B1() { cout << "Destructor B1" << endl; }
};

class C1 : public B1
{
public:
	C1() { cout << "Constructor C1" << endl; }
	void func() { cout << "func in C1" << endl; }
	~C1() { cout << "Destructor C1" << endl; }
};

class A2 //абстрактный базовый класс, т.к. содержит абстрактный метод func
{
public:
	A2() { cout << "Constructor A2" << endl; }
	virtual void func() = 0;	//чисто виртуальный (абстрактный) метод
	virtual ~A2() { cout << "Destructor A2" << endl; }
};

class B2 : public A2
{
public:
	B2() { cout << "Constructor B2" << endl; }
	/*virtual*/ void func() { cout << "func in B2" << endl; }
	/*virtual*/ ~B2() { cout << "Destructor B2" << endl; }
};


class C2 : public B2
{
public:
	C2() { cout << "Constructor C2" << endl; }
	/*virtual*/ void func() { cout << "func in C2" << endl; }
	/*virtual*/ ~C2() { cout << "Destructor C2" << endl; }
};


int main()
{
	/*
	работаем с объектом класса C1,
	используя указатель на базовый класс A1
	*/
	cout << "Without virtualization:" << endl;
	A1* pA1 = new C1;
	pA1->func();
	delete pA1;

	/*
	работаем с объектом класса C2,
	используя указатель на базовый класс A2
	*/
	cout << endl << "With virtualization:" << endl;
	A2* pA2 = new C2;
	pA2->func();
	delete pA2;
	cin.get();
    return 0;
}