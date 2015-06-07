/*******************************************************************************************************
 * 模式：Observer
 *
 * 定义：定义了一种一对多的依赖关系，让多个观察者对象同时监听某一个主题对象。这个主题对象在状态发生变化
 *		 时，会通知所有观察者对象，使它们能够自动更新自己。
 *
 * 解决的问题：将一个系统分割成一个一些类相互协作的类有一个不好的副作用，那就是需要维护相关对象间的一致
 *		 性。我们不希望为了维持一致性而使各类紧密耦合，这样会给维护、扩展和重用都带来不便。观察者能解决
 *		 这类的耦合关系。
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

// 战斗力通知主题类
class FightSubject : public Subject
{
public:
	void notify()
	{
		cout << "战斗力通知" << endl;
		Subject::notify();
	}
};

class RoleInfoUI : public Observer
{
public:
	void update()
	{
		cout << "更新RoleInfoUI界面的战斗力" << endl;
	}
};

class Bag : public Observer
{
	void update()
	{
		cout << "更新背包界面的战斗力" << endl;
	}
};

#endif // !_OBSERVER_H_
