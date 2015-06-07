/*******************************************************************************************************
 * ģʽ��Bridge
 *
 * ���壺�����󲿷�������ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ����仯��
 *
*******************************************************************************************************/
#ifndef _BRIDGE_H_
#define _BRIDGE_H_

#include <iostream>
using std::cout;
using std::endl;

class AbstractCar
{
public:
	virtual void run() = 0;
};

class Car : public AbstractCar
{
public:
	void run()
	{
		cout << "С������" ;
	}
};

class Bus : public AbstractCar
{
public:
	void run()
	{
		cout << "���ʿ��" ;
	}
};

class AbstractRoad
{
public:
	void setCar(AbstractCar *car){_car = car;}
	AbstractCar *getCar(){ return _car; }
	virtual void run() = 0;

protected:
	AbstractCar *_car;
};

class SpeedWay : public AbstractRoad
{
public:
	void run()
	{
		_car->run();
		cout << "���ٹ�·����" << endl;;
	}
};

class Street : public AbstractRoad
{
public:
	void run()
	{
		_car->run();
		cout << "�ֵ�����" << endl;
	}
};

class AbstractDriver
{
public:
	void setRoad(AbstractRoad *road){_road=road;}
	AbstractRoad *getRoad(){return _road;}
	virtual void run() = 0;

protected:
	AbstractRoad *_road;
};

class Man : public AbstractDriver
{
public:
	void run()
	{
		cout << "����";
		_road->run();
	}
};

class Woman : public AbstractDriver
{
public:
	void run()
	{
		cout << "Ů��";
		_road->run();
	}
};

#endif // !_BRIDGE_H_

