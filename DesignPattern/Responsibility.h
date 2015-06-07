/*******************************************************************************************************
 * 模式：Responsibility
 *
 * 定义：使多个对象都有机会处理请求，从而避免请求的发送者和接受者之间的耦合关系。将对象连成一条链，
 *		 并沿着这条链传递该请求，直到有一个对象处理请求为止。
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
			cout << "请假" << request->getDay() << "天，" << _name << "批准" << endl;
		}else
		{
			cout << "请假大于0.5天，项目经理处理不了" << endl;
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
			cout << "请假" << request->getDay() << "天，" << _name << "批准" << endl;
		}else
		{
			cout << "请假大于2天，" << _name << "处理不了" << endl;
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
		cout << "请假" << request->getDay() << "天，" << _name << "批准" << endl;
	}
};