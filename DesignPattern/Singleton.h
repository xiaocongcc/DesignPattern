/*************************************************************************************************
 * ģʽ��Singleton
 *
 * ���壺ȷ��һ����ֻ��һ��ʵ������������ʵ������������ϵͳ�ṩ���ʵ��
 *
 * �ŵ㣺�����ã�����һ����ֻ��һ��ʵ�������Խ��ʹ������������ܻ������ڴ�����ķ��գ�
 *		 �����ڴ�й¶���ڴ�ռ�����⡣
 *
 * ȱ�㣺����ģʽ��Ϊ�ṩ��һ��ȫ�ֵķ��ʵ㣬������ڳ�����κεط�����׾ٷ��ʵ����Ȿ��
 *		 ����һ�ָ���ϵ���ơ�һ�������ı������ģ�鶼��Ҫ�޸ġ�
*************************************************************************************************/

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>

class Singleton
{
public:
	static Singleton *getInstance()
	{
		if (!_instance)
		{
			_instance = new Singleton;	// ����ģʽ����Ҫʱ�Ŵ�������
		}
		return _instance;
	}
	static void destroy(void)
	{
		delete _instance;
		_instance = nullptr;
	}
	~Singleton()
	{
		std::cout << "Singleton Distruction" << std::endl;
	}

private:
	Singleton()
	{
		std::cout << "Singleton Construction is Private" << std::endl;
	}
	static Singleton *_instance;
};
Singleton *Singleton::_instance = NULL;		// remember to init static variable
//Singleton *Singleton::_instance = new Singleton;	// ��ģʽ����������ʱ�ͼ���

#endif // !_SINGLETON_H_
