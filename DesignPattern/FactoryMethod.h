/*************************************************************************************************
 * 模式：FactoryMethod
 *
 * 定义：定义一个用于创建对象的接口，让子类决定实例化哪一个类，工厂方法使一个类的实例化延迟到其子类。

 * 优点：
 *（1）使代码结构清晰，有效地封装变化。
 *（2）对调用者屏蔽具体的产品类。调用接口即可，屏蔽具体实现。
 *（3）降低耦合度。产品类的实例化可能依赖多个类，对于这些类调用者根本无需知道。
 *
*************************************************************************************************/

#ifndef _FACTORYMETHOD_H_
#define _FACTORYMETHOD_H_

#include <iostream>

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

// CPU工厂抽象类，每一间具体的CPU工厂都继承此类，并自己生产特定型号的CPU
class CPUFactory
{
public:
	virtual CPU *getCPU() = 0;
	void getCPUInfo()
	{
		getCPU()->getCPUInfo();
	}
};

class IntelCPU : public CPUFactory
{
public:
	CPU *getCPU()
	{
		return new Intel;
	}
};

class AMDCPU : public CPUFactory
{
public:
	CPU *getCPU()
	{
		return new AMD;
	}
};

#endif // !_FACTORYMETHOD_H_
