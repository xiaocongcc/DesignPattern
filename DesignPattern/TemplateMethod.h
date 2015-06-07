/*******************************************************************************************************
 * 模式：TemplateMethod
 *
 * 定义：定义一个操作中算法的骨架，而将一些步骤延迟到子类。模板方法使得子类可以不改变一个算法的结构即可
 *		 重定义该算法的某些特定步骤。
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
		cout << "开始时调用start函数" << endl;
		init();
	}
	void exit()
	{
		release();
		cout << "结束时调用exit函数" << endl;
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
		cout << "调用 roleInfoUI::init()" << endl;
	}
	void release()
	{
		cout << "调用 roleInfoUI:release()" << endl;
	}
};

#endif // !_TEMPLATEMETHOD_H_
