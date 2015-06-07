/*******************************************************************************************************
 * 模式：Bridge
 *
 * 定义：将抽象部分与它的实现部分分离，使它们都可以独立变化。
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
		cout << "小汽车在" ;
	}
};

class Bus : public AbstractCar
{
public:
	void run()
	{
		cout << "大巴士在" ;
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
		cout << "高速公路奔跑" << endl;;
	}
};

class Street : public AbstractRoad
{
public:
	void run()
	{
		_car->run();
		cout << "街道奔跑" << endl;
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
		cout << "男人";
		_road->run();
	}
};

class Woman : public AbstractDriver
{
public:
	void run()
	{
		cout << "女人";
		_road->run();
	}
};

#endif // !_BRIDGE_H_

