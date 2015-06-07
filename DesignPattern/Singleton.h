/*************************************************************************************************
 * 模式：Singleton
 *
 * 定义：确保一个类只有一个实例，而且自行实例化并向整个系统提供这个实例
 *
 * 优点：简单易用，限制一个类只有一个实例，可以降低创建多个对象可能会引起内存问题的风险，
 *		 包括内存泄露、内存占用问题。
 *
 * 缺点：单例模式因为提供了一个全局的访问点，你可以在程序的任何地方轻而易举访问到，这本身
 *		 就是一种高耦合的设计。一旦单例改变后，其他模块都需要修改。
*************************************************************************************************/

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>

class Singleton
{
public:
	static Singleton *getInstance()
	{
		if (!_instance)
		{
			_instance = new Singleton;	// 懒汉模式，需要时才创建单例
		}
		return _instance;
	}
	static void destroy(void)
	{
		delete _instance;
		_instance = nullptr;
	}
	~Singleton()
	{
		std::cout << "Singleton Distruction" << std::endl;
	}

private:
	Singleton()
	{
		std::cout << "Singleton Construction is Private" << std::endl;
	}
	static Singleton *_instance;
};
Singleton *Singleton::_instance = NULL;		// remember to init static variable
//Singleton *Singleton::_instance = new Singleton;	// 恶汉模式，程序运行时就加载

#endif // !_SINGLETON_H_
