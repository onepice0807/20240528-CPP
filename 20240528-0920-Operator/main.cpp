#include <iostream>
#include <string>

using namespace std;

class Lion {
private:
	string _color;

public:
	Lion(string color)
		: _color(color) {}

	string GetColor() {
		return _color;
	}
};

class Tiger {
private:
	string _color;

public:
	Tiger(string color)
		: _color(color) {}

	string GetColor() {
		return _color;
	}
};

class Liger : public Lion, public Tiger {
public:
	Liger(string lionColor, string tigerColor)
		:Lion(lionColor), Tiger(tigerColor) {}

	void ShowColor() {
		cout << "Lion�� �÷���: " << endl;
		cout << "�Ӹ�: " << Lion::GetColor() << "";
		cout << "����: " << Tiger::GetColor();
		cout << endl;
	}
};

int main() {
	Liger liger("Red", "Black");

	liger.ShowColor();

	return 0;
}