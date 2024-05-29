#include <iostream>
#include <string>

using namespace std;

// Computer, Phone 클래스를 만들고 다중상속을 해서 SmartPhone 클래스를 만들고
// SmartPhone객체를 만든 후에 작동시키기

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
		cout << userId << "은" << cpu << gpu << mamory << "로 구성되어있습니다" << endl;
	}

	void LogIn(string userId) {
		cout << userId << "가 로그인 합니다" << endl;
 	}
	void SendKakaoTalk(string userId, string kakaoTalk) {
		cout << userId << "가" << kakaoTalk << "을  보냅니다." << endl;
	}

	void ReceiveKakaoTalk(string userId, string kakaoTalk) {
		cout << userId << "가" << kakaoTalk << "을  받았습니다." << endl;
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
		cout <<  massage << "를 보냅니다." << endl;
	}

	void ReceiveMassage(int phoneNum, string massage) {
		cout << "전화번호 :" << phoneNum <<  "가 보낸 "  << massage << " 답변을 받았습니다." << endl;
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
	SmartPhone rayPhone("ray1234의 스마트폰", 00001111);
	rayPhone.logIn("ray1234");
	rayPhone.sendMassage(false, "", "안녕하세요!");
	rayPhone.ReceivedMassage(true, 12345678, "오랜만이에요", "");
	rayPhone.UsingItem(" 스냅드래곤 8 gen 3 ", " Adreno 750 GPU ", " 12G ");

	return 0;
}