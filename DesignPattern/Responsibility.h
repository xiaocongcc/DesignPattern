/*******************************************************************************************************
 * ģʽ��Responsibility
 *
 * ���壺ʹ��������л��ᴦ�����󣬴Ӷ���������ķ����ߺͽ�����֮�����Ϲ�ϵ������������һ������
 *		 ���������������ݸ�����ֱ����һ������������Ϊֹ��
 *
*******************************************************************************************************/
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Request
{
public:
	Request(int day, string reason):_day(day), _reason(reason){}
	int getDay(){return _day;}
	string getReason(){return _reason;}

private:
	int _day;
	string _reason;
};

class Header
{
public:
	Header(string name):_name(name){}
	void setReceiver(Header *receiver){_nextReceiver=receiver;}
	virtual void handlerRequest(Request *request) = 0;

protected:
	string _name;
	Header *_nextReceiver;
};

class PM : public Header
{
public:
	PM(string name):Header(name){}
	void handlerRequest(Request *request)
	{
		if (request->getDay() <= 0.5)
		{
			cout << "���" << request->getDay() << "�죬" << _name << "��׼" << endl;
		}else
		{
			cout << "��ٴ���0.5�죬��Ŀ��������" << endl;
			_nextReceiver->handlerRequest(request);
		}
	}
};

class HR : public Header
{
public:
	HR(string name):Header(name){}
	void handlerRequest(Request *request)
	{
		if (request->getDay() > 0.5 && request->getDay() <= 2)
		{
			cout << "���" << request->getDay() << "�죬" << _name << "��׼" << endl;
		}else
		{
			cout << "��ٴ���2�죬" << _name << "������" << endl;
			_nextReceiver->handlerRequest(request);
		}
	}
};

class Boss : public Header
{
public:
	Boss(string name):Header(name){}
	void handlerRequest(Request *request)
	{
		cout << "���" << request->getDay() << "�죬" << _name << "��׼" << endl;
	}
};