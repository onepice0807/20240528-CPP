#include <iostream>
#include <string>

using namespace std;

// 다중상속

class Parent1 {
public:
	int _value;
	int _value1;

public:
	Parent1(int value, int value1)
		: _value(value), _value1(value1) {}

	void ShowInfo() {
		cout << "Parent1:: _value = " << _value << ", _value1 = " << _value1 << endl;
	}
};

class Parent2 {
public:
	int _value;
	int _value2;

public:
	Parent2(int value, int value2)
		: _value(value), _value2(value2) {}

	void ShowInfo() {
		cout << "Parent2:: _value = " << _value << ", _value1 = " << _value2 << endl;
	}
};

class Child : public Parent1, public Parent2 {
public:
	Child(int valuep1, int value1, int valuep2, int value2)
		: Parent1(valuep1, value1), Parent2(valuep2, value2) {}
};

int main() {
	Child child(10, 20, 30, 40);

	child.Parent1::ShowInfo(); // 모호함이 발생하는 경우에는 정확하게 호출범위를 지정해주면 된다.
	child.Parent2::_value = 100;

	Parent1& ref1 = child;

	ref1.ShowInfo();

	Parent2& ref2 = child;

	ref2.ShowInfo();

	return 0;
}

