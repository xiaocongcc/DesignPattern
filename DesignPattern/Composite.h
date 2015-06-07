/*******************************************************************************************************
 * ģʽ��Composite
 *
 * ���壺��������ϳ����νṹ�Ա�ʾ������-���塱�Ĳ�νṹ�����ģʽʹ���û��Ե����������϶����ʹ��
 *		 ����һ���ԡ�
 *
*******************************************************************************************************/
#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;


class Component
{
public:
	Component(string name):_name(name){}
	virtual void add(Component *component) = 0;
	virtual void remove(Component *component) = 0;
	virtual void display(int depth) = 0;

protected:
	string _name;
};

class Label : public Component
{
public:
	Label(string name):Component(name){}
	void add(Component *component)
	{
		cout << "can not use add in leaf" << endl;
	}
	void remove(Component *component)
	{
		cout << "can not use remove in leaf" << endl;
	}
	void display(int depth)
	{
		for (auto i=0; i!=depth; i++)
		{
			cout << "-";
		}
		cout << "label: " << _name << endl;
	}
};

class Container : public Component
{
public:
	Container(string name):Component(name){_list.reserve(20);}
	void add(Component *component)
	{
		_list.push_back(component);
	}
	void remove(Component *component)
	{
		
	}
	void display(int depth)
	{
		cout << "-container: " << _name << endl;
		for (auto i=0; i!=depth; i++)
		{
			cout << "-";
		}
		auto newDepth = depth + 1;
		for (auto it=_list.begin(); it!=_list.end(); it++)
		{
			(*it)->display(newDepth);
		}
	}
	
private:
	vector<Component *> _list;
};

#endif // !_COMPOSITE_H_

