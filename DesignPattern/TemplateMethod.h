/*******************************************************************************************************
 * ģʽ��TemplateMethod
 *
 * ���壺����һ���������㷨�ĹǼܣ�����һЩ�����ӳٵ����ࡣģ�巽��ʹ��������Բ��ı�һ���㷨�Ľṹ����
 *		 �ض�����㷨��ĳЩ�ض����衣
 *
*******************************************************************************************************/

#ifndef _TEMPLATEMETHOD_H_
#define _TEMPLATEMETHOD_H_

#include <iostream>
using std::cout;
using std::endl;

class UIPanels
{
public:
	void start()
	{
		cout << "��ʼʱ����start����" << endl;
		init();
	}
	void exit()
	{
		release();
		cout << "����ʱ����exit����" << endl;
	}

protected:
	virtual void init() = 0;
	virtual void release(){}
};

class roleInfoUI : public UIPanels
{
public:
	void init()
	{
		cout << "���� roleInfoUI::init()" << endl;
	}
	void release()
	{
		cout << "���� roleInfoUI:release()" << endl;
	}
};

#endif // !_TEMPLATEMETHOD_H_
