/*******************************************************************************************************
 * ģʽ��Mediator
 *
 * ���壺��һ���н��������װһϵ�еĶ��󽻻����н���ʹ�ø�������Ҫ��ʽ���໥���ã��Ӷ�ʹ�������ɢ��
 *		 ���ҿ��Զ����ظı�����֮��Ľ�����
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
		cout << "��Ӫ�õ���Ϣ��" << message << endl;
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
		cout << "����Ա�õ���Ϣ��" << message << endl;
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

