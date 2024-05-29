#include <iostream>
#include <string>

using namespace std;

// Computer, Phone Ŭ������ ����� ���߻���� �ؼ� SmartPhone Ŭ������ �����
// SmartPhone��ü�� ���� �Ŀ� �۵���Ű��

class Computer {
private:
	string _userId;
	string _cpu;
	string _gpu;
	string _mamory;
	string _game;
	string _kakaoTalk;
	bool _wifi;

public:
	Computer(string userId)
		: _userId(userId) {}

	string GetUserId() {
		return _userId;
	}

	void UsingItem(string userId, string cpu, string gpu, string mamory) {
		cout << userId << "��" << cpu << gpu << mamory << "�� �����Ǿ��ֽ��ϴ�" << endl;
	}

	void LogIn(string userId) {
		cout << userId << "�� �α��� �մϴ�" << endl;
 	}
	void SendKakaoTalk(string userId, string kakaoTalk) {
		cout << userId << "��" << kakaoTalk << "��  �����ϴ�." << endl;
	}

	void ReceiveKakaoTalk(string userId, string kakaoTalk) {
		cout << userId << "��" << kakaoTalk << "��  �޾ҽ��ϴ�." << endl;
	}
	
};

class Phone {
private:
	int _phoneNum;
	string _call;
	string _massage;
	bool _network5g;
public:
	Phone(int phoneNum)
		: _phoneNum(phoneNum) {}

	int GetPhoneNum() {
		return _phoneNum;
	}

	void SendMassage(int phoneNum, string massage) {
		cout <<  massage << "�� �����ϴ�." << endl;
	}

	void ReceiveMassage(int phoneNum, string massage) {
		cout << "��ȭ��ȣ :" << phoneNum <<  "�� ���� "  << massage << " �亯�� �޾ҽ��ϴ�." << endl;
	}

};

class SmartPhone : public Computer, public Phone {
public:
	SmartPhone(string userId, int phoneNumber)
		: Computer(userId), Phone(phoneNumber) {}

	void logIn(string userId) {
		Computer::LogIn(userId);
	}

	void sendMassage(bool type, string massage, string kakaoTalk) {
		if (type) {
			Phone::SendMassage(GetPhoneNum(), massage);
		}
		else {
			Computer::SendKakaoTalk(GetUserId(), kakaoTalk);
		}
	}

	void ReceivedMassage(bool type, int phoneNum, string massage, string kakaoTalk) {
		if (type) {
			Phone::ReceiveMassage(phoneNum, massage);
		}
		else {
			Computer::ReceiveKakaoTalk(GetUserId(), kakaoTalk);
		}
	}

	void UsingItem(string cpu, string gpu, string mamory) {
		Computer::UsingItem(GetUserId(), cpu, gpu, mamory);
	}
};



int main() {
	SmartPhone rayPhone("ray1234�� ����Ʈ��", 00001111);
	rayPhone.logIn("ray1234");
	rayPhone.sendMassage(false, "", "�ȳ��ϼ���!");
	rayPhone.ReceivedMassage(true, 12345678, "�������̿���", "");
	rayPhone.UsingItem(" �����巡�� 8 gen 3 ", " Adreno 750 GPU ", " 12G ");

	return 0;
}