/*******************************************************************************************************
 * 模式：Strategy
 *
 * 定义：定义了算法家族，分别封装起来，让它们之间可以互相替换，此模式让算法的变化，不会影响到使用算法
 *		 的客户。
 *
 * 策略模式用来封装算法的，在实践中可以用它来封装几乎任何类型的规则，只要在分析过程中听到需要在不同实践
 * 应用不同的业务规则，就可以考虑使用策略模式处理这种变化的可能性。
*******************************************************************************************************/

#ifndef _STRATEGY_H_
#define _STRATEGY_H_

#include <iostream>

typedef unsigned int uint;

// 策略基类，获取血量
class HPOperate
{
public:
	virtual void getHp()
	{
		std::cout << "血量基类呼啦啦" << std::endl;
	}
};

// 具体策略类
class NormalHP : public HPOperate
{
public:
	void getHp()
	{
		std::cout << "游戏中，我的血量是正常的" << std::endl;
	}
};

class PKHP : public HPOperate
{
public:
	void getHp()
	{
		std::cout << "PK场中，我的血量是正常血量的5倍" << std::endl;
	}
};

class PunishHP : public HPOperate
{
public:
	void getHp()
	{
		std::cout << "逃跑惩罚中，我的血量是正常血量的1/3" << std::endl;
	}
};


// 工厂方法基类，用于创建不同血量的不同角色
class GameRole
{
public:
	GameRole(HPOperate *operate, uint power, uint intellect, uint agility)
	{
		_operate = operate;
		_power = power;
		_intellect = intellect;
		_agility = agility;
	}

	virtual void getFight()
	{
		std::cout << "计算战斗力" << std::endl;
	}

protected:
	HPOperate *_operate;

	uint _power;		// 力量
	uint _intellect;	// 智力
	uint _agility;		// 敏捷
};

// 战士类
class Warrior : public GameRole
{
public:
	Warrior(HPOperate *operate) : GameRole(operate, 10, 5, 7){}
	void getFight()
	{
		std::cout << "计算战斗力：" << "我是战士，我的力量是" << _power << std::endl;
		_operate->getHp();
	}
};

// 法师类
class Master : public GameRole
{
public:
	Master(HPOperate *operate) : GameRole(operate, 7, 10, 5){}
	void getFight()
	{
		std::cout << "计算战斗力：" << "我是法师，我的智力是" << _intellect << std::endl;
		_operate->getHp();
	}
};

// 潜行者类
class Stalker : public GameRole
{
public:
	Stalker(HPOperate *operate) : GameRole(operate, 7, 5, 10){}
	void getFight()
	{
		std::cout << "计算战斗力：" << "我是潜行者，我的敏捷是" << _agility << std::endl;
		_operate->getHp();
	}
};

#endif // !_STRATEGY_H_
