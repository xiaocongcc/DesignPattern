/*******************************************************************************************************
 * 模式：Builder
 *
 * 定义：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
 *
 * 优点：首先，使用Builder可以有效的封装变化，在使用Builder的场景中，一般产品类和建造者类是比较稳定的，
 *		 因此，将主要的业务逻辑封装在导演类中对整体而言可以取得比较好的稳定性。
 *		 其次，Builder容易进行扩展。如果有新的需求，通过一个新的建造者类即可。
*******************************************************************************************************/

#ifndef _BUILDER_H_
#define _BUILDER_H_

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


// Builder抽象类
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

// Builder具体类，用于创建具体对象，可以替换此具体类来创建不同对象
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

// 创建组件不同的电脑
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

// Director类，负责调用适当的建造者来组件产品，用来封装程序中易变的部分
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
