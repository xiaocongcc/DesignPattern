/*******************************************************************************************************
 * 模式：Mediator
 *
 * 定义：用一个中介对象来封装一系列的对象交互。中介者使得各对象不需要显式地相互引用，从而使得耦合松散，
 *		 而且可以独立地改变它们之间的交互。
 *
*******************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Colleague;

class PlanPart
{
public:
	virtual void send(string demand, Colleague *colleague) = 0;
	virtual void addColleague(Colleague *colleague) = 0;
};

class Colleague
{
public:
	Colleague(PlanPart *planner):_planner(planner){}
	virtual void sendMessage(string message) = 0;
	virtual void getMessage(string message) = 0;

protected:
	PlanPart *_planner;
};

class Operator : public Colleague
{
public:
	Operator(PlanPart *planner):Colleague(planner){}

	void sendMessage(string message)
	{
		_planner->send(message, this);
	}
	void getMessage(string message)
	{
		cout << "运营得到消息：" << message << endl;
	}
};

class CodeMonkey : public Colleague
{
public:
	CodeMonkey(PlanPart *planner):Colleague(planner){}

	void sendMessage(string message)
	{
		_planner->send(message, this);
	}
	void getMessage(string message)
	{
		cout << "程序员得到消息：" << message << endl;
	}
};

class Planner : public PlanPart
{
public:
	Planner(){_list.reserve(10);}
	void addColleague(Colleague *colleague){_list.push_back(colleague);}
	void send(string demand, Colleague *colleague)
	{
		for (auto it=_list.begin(); it!=_list.end(); it++)
		{
			if ((*it) != colleague)
			{
				(*it)->getMessage(demand);
			}
		}
	}

private:
	vector<Colleague*> _list;
};

