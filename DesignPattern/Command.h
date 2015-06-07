/*******************************************************************************************************
 * 模式：Command
 *
 * 定义：将一个请求封装成一个对象，使你可用不同的请求对客户端进行参数化。对请求排队或记录请求日志，以及
 *		 支持可撤销的操作。
 *
*******************************************************************************************************/
#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Barbecuer
{
public:
	void bakeMutton()
	{
		cout << "烤羊肉" << endl;
	}
	void bakeWings()
	{
		cout << "烤鸡翅" << endl;
	}
};

class Command
{
public:
	Command(Barbecuer *receiver){_receiver=receiver;}
	virtual void execute() = 0;

protected:
	Barbecuer *_receiver;
};

class BakeMuttonCommand : public Command
{
public:
	BakeMuttonCommand(Barbecuer *receiver):Command(receiver){}
	void execute()
	{
		_receiver->bakeMutton();
	}
};

class BakeWingsCommand : public Command
{
public:
	BakeWingsCommand(Barbecuer *receiver):Command(receiver){}
	void execute()
	{
		_receiver->bakeWings();
	}
};

class Waiter
{
public:
	Waiter(){_commandList.reserve(10);}
	void addOrder(Command *command)
	{
		cout << "增加订单..." << endl;
		_commandList.push_back(command);
	}
	void detachOrder(Command *command)
	{
		// 订单删除功能
	}
	void modifyOrder(Command *command)
	{
		// 订单修改功能
	}
	void notify()
	{
		cout << "通知烧烤..." << endl;
		for (auto it=_commandList.begin(); it!=_commandList.end(); it++)
		{
			(*it)->execute();
		}
	}

private:
	vector<Command *> _commandList;
};

#endif // !_COMMAND_H_
