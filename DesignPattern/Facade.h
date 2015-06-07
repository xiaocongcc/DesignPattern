/*******************************************************************************************************
 * 模式：Facade
 *
 * 定义：为子系统的中的一组接口提供一个一致的界面，此模式定义一个高层的接口，这一接口使得子系统容易使用
 *
*******************************************************************************************************/

#ifndef _FACADE_H_
#define _FACADE_H_

#include <iostream>
using std::cout;
using std::endl;

class Compiler
{
public:
	void compile()
	{
		scan();
		cifafenxi();
		yuyifenxi();
		more();
	}

	void scan()
	{
		cout << "扫描..." << endl;
	}
	void cifafenxi()
	{
		cout << "词法分析..." <<  endl;
	}
	void yuyifenxi()
	{
		cout << "语义分析..." << endl;
	}
	void more()
	{
		cout << "更多..." << endl;
	}
};

#endif // !_FACADE_H_
