/*******************************************************************************************************
 * ģʽ��Command
 *
 * ���壺��һ�������װ��һ������ʹ����ò�ͬ������Կͻ��˽��в��������������Ŷӻ��¼������־���Լ�
 *		 ֧�ֿɳ����Ĳ�����
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
		cout << "������" << endl;
	}
	void bakeWings()
	{
		cout << "������" << endl;
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
		cout << "���Ӷ���..." << endl;
		_commandList.push_back(command);
	}
	void detachOrder(Command *command)
	{
		// ����ɾ������
	}
	void modifyOrder(Command *command)
	{
		// �����޸Ĺ���
	}
	void notify()
	{
		cout << "֪ͨ�տ�..." << endl;
		for (auto it=_commandList.begin(); it!=_commandList.end(); it++)
		{
			(*it)->execute();
		}
	}

private:
	vector<Command *> _commandList;
};

#endif // !_COMMAND_H_
