/*******************************************************************************************************
 * ģʽ��Memento
 *
 * ���壺�ڲ��ƻ���װ��ǰ���£�����һ������ڲ�״̬�����ڶ����ⲿ�������״̬�������Ϳ��Խ��ö���ָ�
 *		 ��ԭ�ȱ����״̬��
 *
*******************************************************************************************************/

#ifndef _MEMENTO_H_
#define _MEMENTO_H_

#include <iostream>
using std::cout;
using std::endl;

class Memento
{
public:
	Memento(int hp, int mp, int power):_hp(hp), _mp(mp), _power(power){}

	int getHp(){ return _hp; }
	int getMp(){ return _mp; }
	int getPower(){ return _power; }

private:
	int _hp;
	int _mp;
	int _power;
};

class GameRole
{
public:
	void initProperty()
	{
		_hp = 100;
		_mp = 100;
		_power = 100;
	}

	void showProperty()
	{
		cout << "hp=" << _hp << ", mp=" << _mp << ", power=" << _power << endl;
	}

	void fight()
	{
		_hp = 0;
		_mp = 0;
		_power = 0;
	}

	Memento *saveState()
	{
		return new Memento(_hp, _mp, _power);
	}

	void recoveryState(Memento *memento)
	{
		_hp = memento->getHp();
		_mp = memento->getMp();
		_power = memento->getPower();
	}

private:
	int _hp;
	int _mp;
	int _power;
	Memento *_memento;
};

class MementoSaver
{
public:
	MementoSaver(Memento *memento):_memento(memento){}

	void setMemento(Memento *memento){_memento = memento;}
	Memento *getMemento(){return _memento;}

private:
	Memento *_memento;
};

#endif // !_MEMENTO_H_
