/*************************************************************************************************
 * ģʽ��AbstractFactory
 *
 * ���壺Ϊ����һ����ػ��໥�����Ķ����ṩһ���ӿڣ�������ָ�����ǵľ����ࡣ
 *
 * ���󹤳�ģʽ�͹�������ģʽ������
 * ���󹤳�ģʽ�ǹ�������ģʽ�������汾������������һ����ػ����໥�����Ķ��󡣹���������Ե���һ
 * ����Ʒ�ȼ��ṹ�������󹤳�ģʽ������ԵĶ����Ʒ�ȼ��ṹ���ڱ���У�ͨ��һ����Ʒ�ṹ������Ϊһ
 * ���ӿڻ��߳����࣬Ҳ����˵���������ṩ�����в�Ʒ����������ͬһ���ӿڻ�����࣬�����󹤳����ṩ
 * �Ĳ�Ʒ���������Բ�ͬ�Ľӿڻ�����ࡣ
 *
 * �ŵ㣺���˾��й����������ŵ��⣬������������ڲ��Բ�Ʒ�����Լ����
 *
 * ȱ�㣺��Ʒ�����չ����һ��ʮ�ַ��������飬�����Ʒ������Ҫ����һ���µĲ�Ʒ���򼸺����еĹ�����
 *		 ����Ҫ�����޸ģ�����ʹ�ó��󹤳�ģʽʱ���Բ�Ʒ�ȼ��ṹ�Ļ����Ƿǳ���Ҫ�ġ�
*************************************************************************************************/

#ifndef _ABSTRACTFACTORY_H_
#define _ABSTRACTFACTORY_H_

#include <iostream>

// CPU��Ʒ�ӿ�
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

// �����Ʒ�ӿ�
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

// �ڴ��Ʒ�ӿ�
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

// ���󹤳�ģʽ������
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

// �����࣬ϲ��ʲô����Լ�������װ���ͻ���ֱ���滻���༴��
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
