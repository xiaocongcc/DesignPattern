/*******************************************************************************************************
 * 模式：Adapter
 *
 * 定义：将一个类的接口转换成客户希望的另一个接口。Apdate使得原本由于接口不兼容而不能一起工作的那些类
 *		 可以一起工作。
*******************************************************************************************************/

#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include <iostream>
#include <string>

class Graphics
{
public:
	std::string getGraphicsInfo()
	{
		return "物理显卡";
	}
};

class Adapter
{
public:
	virtual void getInfo() = 0;
};

// 显卡适配器
class GraphicsAdapter : public Adapter
{
public:
	void getInfo()
	{
		Graphics *graphics = new Graphics;
		std::cout << "使用显卡适配器，可以正常使用" << graphics->getGraphicsInfo() << std::endl;
		delete graphics;
	}
};



#endif // !_ADAPTER_H_
