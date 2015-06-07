/*******************************************************************************************************
 * ģʽ��Observer
 *
 * ���壺������һ��һ�Զ��������ϵ���ö���۲��߶���ͬʱ����ĳһ���������������������״̬�����仯
 *		 ʱ����֪ͨ���й۲��߶���ʹ�����ܹ��Զ������Լ���
 *
 * ��������⣺��һ��ϵͳ�ָ��һ��һЩ���໥Э��������һ�����õĸ����ã��Ǿ�����Ҫά����ض�����һ��
 *		 �ԡ����ǲ�ϣ��Ϊ��ά��һ���Զ�ʹ���������ϣ��������ά������չ�����ö��������㡣�۲����ܽ��
 *		 �������Ϲ�ϵ��
*******************************************************************************************************/

#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Observer
{
public:
	virtual void update() = 0;
};

class Subject
{
public:
	Subject()
	{
		_observerVec.reserve(50);
	}

	void addObserver(Observer* observer)
	{
		_observerVec.push_back(observer);
	}

	void detach(Observer* observer)
	{
		
	}

	virtual void notify()
	{
		for (auto obj : _observerVec)
		{
			obj->update();
		}
	}

protected:
	vector<Observer *> _observerVec;
};

// ս����֪ͨ������
class FightSubject : public Subject
{
public:
	void notify()
	{
		cout << "ս����֪ͨ" << endl;
		Subject::notify();
	}
};

class RoleInfoUI : public Observer
{
public:
	void update()
	{
		cout << "����RoleInfoUI�����ս����" << endl;
	}
};

class Bag : public Observer
{
	void update()
	{
		cout << "���±��������ս����" << endl;
	}
};

#endif // !_OBSERVER_H_
