/*******************************************************************************************************
 * ģʽ��Builder
 *
 * ���壺��һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��
 *
 * �ŵ㣺���ȣ�ʹ��Builder������Ч�ķ�װ�仯����ʹ��Builder�ĳ����У�һ���Ʒ��ͽ��������ǱȽ��ȶ��ģ�
 *		 ��ˣ�����Ҫ��ҵ���߼���װ�ڵ������ж�������Կ���ȡ�ñȽϺõ��ȶ��ԡ�
 *		 ��Σ�Builder���׽�����չ��������µ�����ͨ��һ���µĽ������༴�ɡ�
*******************************************************************************************************/

#ifndef _BUILDER_H_
#define _BUILDER_H_

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


// Builder������
class Builder
{
public:
	virtual CPU *getCPU() = 0;
	virtual Board *getBoard() = 0;
	virtual Memory *getMemory() = 0;
	void getComputerInfo()
	{
		getCPU()->getCPUInfo();
		getBoard()->getBoardInfo();
		getMemory()->getMemoryInfo();
	}
};

// Builder�����࣬���ڴ���������󣬿����滻�˾�������������ͬ����
class ComputerBuilder1 : public Builder
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

// ���������ͬ�ĵ���
class ComputerBuilder2 : public Builder
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

// Director�࣬��������ʵ��Ľ������������Ʒ��������װ�������ױ�Ĳ���
class Director
{
public:
	Director(Builder *builder)
	{
		_builder = builder;
	}
	void setBuilder(Builder *builder)
	{
		_builder = builder;
	}
	Builder *getBuilder()
	{
		return _builder;
	}

	void buildComputer()
	{
		_builder->getComputerInfo();
	}

private:
	Builder *_builder;
};

#endif // !_BUILDER_H_
