/*************************************************************************************************
 * 模式：AbstractFactory
 *
 * 定义：为创建一组相关或相互依赖的对象提供一个接口，而无需指定他们的具体类。
 *
 * 抽象工厂模式和工厂方法模式的区别：
 * 抽象工厂模式是工厂方法模式的升级版本，他用来创建一组相关或者相互依赖的对象。工厂方法针对的是一
 * 个产品等级结构；而抽象工厂模式则是针对的多个产品等级结构。在编程中，通常一个产品结构，表现为一
 * 个接口或者抽象类，也就是说工厂方法提供的所有产品都是衍生自同一个接口或抽象类，而抽象工厂所提供
 * 的产品则是衍生自不同的接口或抽象类。
 *
 * 优点：除了具有工厂方法的优点外，还可以在类的内部对产品族进行约束。
 *
 * 缺点：产品族的扩展将是一件十分费力的事情，加入产品族中需要增加一个新的产品，则几乎所有的工厂类
 *		 都需要进行修改，所以使用抽象工厂模式时，对产品等级结构的划分是非常重要的。
*************************************************************************************************/

#ifndef _ABSTRACTFACTORY_H_
#define _ABSTRACTFACTORY_H_

#include <iostream>

// CPU产品接口
class CPU
{
public:
	virtual void getCPUInfo() = 0;
};

class Intel : public CPU
{
public:
	void getCPUInfo()
	{
		std::cout << "Intel CPU Info" << std::endl;
	}
};

class AMD : public CPU
{
public:
	void getCPUInfo()
	{
		std::cout << "AMD CPU Info" << std::endl;
	}
};

// 主板产品接口
class Board
{
public:
	virtual void getBoardInfo() = 0;
};

class Asus : public Board
{
public:
	void getBoardInfo()
	{
		std::cout << "Asus Board Info" << std::endl;
	}
};

class MSI : public Board
{
public:
	void getBoardInfo()
	{
		std::cout << "MSI Board Info" << std::endl;
	}
};

// 内存产品接口
class Memory
{
public:
	virtual void getMemoryInfo() = 0;
};

class Kingston : public Memory
{
public:
	void getMemoryInfo()
	{
		std::cout << "Kingston Memory Info" << std::endl;
	}
};

class Team : public Memory
{
public:
	void getMemoryInfo()
	{
		std::cout << "Team Memory Info" << std::endl;
	}
};

// 抽象工厂模式抽象类
class ComputerAbFactory
{
public:
	virtual CPU *getCPU() = 0;
	virtual Board *getBoard() = 0;
	virtual Memory *getMemory() = 0;

	virtual void createComputer()
	{
		std::cout << "create new computer : " << std::endl;
		getCPU()->getCPUInfo();
		getBoard()->getBoardInfo();
		getMemory()->getMemoryInfo();
	}
};

// 具体类，喜欢什么配件自己定义组装，客户端直接替换此类即可
class MyComputer : public ComputerAbFactory
{
public:
	CPU *getCPU()
	{
		return new AMD;
	}
	Board *getBoard()
	{
		return new MSI;
	}
	Memory *getMemory()
	{
		return new Kingston;
	}
};

class YourComputer : public ComputerAbFactory
{
public:
	CPU *getCPU()
	{
		return new Intel;
	}
	Board *getBoard()
	{
		return new Asus;
	}
	Memory *getMemory()
	{
		return new Kingston;
	}
};

#endif // !_ABSTRACTFACTORY_H_
