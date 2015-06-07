/*******************************************************************************************************
 * ģʽ��Strategy
 *
 * ���壺�������㷨���壬�ֱ��װ������������֮����Ի����滻����ģʽ���㷨�ı仯������Ӱ�쵽ʹ���㷨
 *		 �Ŀͻ���
 *
 * ����ģʽ������װ�㷨�ģ���ʵ���п�����������װ�����κ����͵Ĺ���ֻҪ�ڷ���������������Ҫ�ڲ�ͬʵ��
 * Ӧ�ò�ͬ��ҵ����򣬾Ϳ��Կ���ʹ�ò���ģʽ�������ֱ仯�Ŀ����ԡ�
*******************************************************************************************************/

#ifndef _STRATEGY_H_
#define _STRATEGY_H_

#include <iostream>

typedef unsigned int uint;

// ���Ի��࣬��ȡѪ��
class HPOperate
{
public:
	virtual void getHp()
	{
		std::cout << "Ѫ�����������" << std::endl;
	}
};

// ���������
class NormalHP : public HPOperate
{
public:
	void getHp()
	{
		std::cout << "��Ϸ�У��ҵ�Ѫ����������" << std::endl;
	}
};

class PKHP : public HPOperate
{
public:
	void getHp()
	{
		std::cout << "PK���У��ҵ�Ѫ��������Ѫ����5��" << std::endl;
	}
};

class PunishHP : public HPOperate
{
public:
	void getHp()
	{
		std::cout << "���ܳͷ��У��ҵ�Ѫ��������Ѫ����1/3" << std::endl;
	}
};


// �����������࣬���ڴ�����ͬѪ���Ĳ�ͬ��ɫ
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
		std::cout << "����ս����" << std::endl;
	}

protected:
	HPOperate *_operate;

	uint _power;		// ����
	uint _intellect;	// ����
	uint _agility;		// ����
};

// սʿ��
class Warrior : public GameRole
{
public:
	Warrior(HPOperate *operate) : GameRole(operate, 10, 5, 7){}
	void getFight()
	{
		std::cout << "����ս������" << "����սʿ���ҵ�������" << _power << std::endl;
		_operate->getHp();
	}
};

// ��ʦ��
class Master : public GameRole
{
public:
	Master(HPOperate *operate) : GameRole(operate, 7, 10, 5){}
	void getFight()
	{
		std::cout << "����ս������" << "���Ƿ�ʦ���ҵ�������" << _intellect << std::endl;
		_operate->getHp();
	}
};

// Ǳ������
class Stalker : public GameRole
{
public:
	Stalker(HPOperate *operate) : GameRole(operate, 7, 5, 10){}
	void getFight()
	{
		std::cout << "����ս������" << "����Ǳ���ߣ��ҵ�������" << _agility << std::endl;
		_operate->getHp();
	}
};

#endif // !_STRATEGY_H_
