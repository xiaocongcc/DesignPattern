/*************************************************************************************************
 * ģʽ��FactoryMethod
 *
 * ���壺����һ�����ڴ�������Ľӿڣ����������ʵ������һ���࣬��������ʹһ�����ʵ�����ӳٵ������ࡣ

 * �ŵ㣺
 *��1��ʹ����ṹ��������Ч�ط�װ�仯��
 *��2���Ե��������ξ���Ĳ�Ʒ�ࡣ���ýӿڼ��ɣ����ξ���ʵ�֡�
 *��3��������϶ȡ���Ʒ���ʵ����������������࣬������Щ������߸�������֪����
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

// CPU���������࣬ÿһ������CPU�������̳д��࣬���Լ������ض��ͺŵ�CPU
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
