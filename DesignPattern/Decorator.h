/*******************************************************************************************************
 * 模式：Decorator
 *
 * 定义：动态地给一个对象（注意不是类）添加一些额外的职责，就增加功能来说，装饰模式比生成子类更为灵活。
 *
*******************************************************************************************************/

#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include <iostream>

// 控件父类
class Widget
{
public:
	virtual void draw() = 0;
};

// 具体控件类
class TextView : public Widget
{
public:
	void draw()
	{
		std::cout << "draw textview" << std::endl;
	}
};

// 装饰类，继承于控件
class Decorator : public Widget
{
public:
	Decorator(Widget *widget)
	{
		_widget = widget;
	}

	virtual void draw()
	{
		if (_widget != nullptr)
		{
			_widget->draw();
		}
	}

protected:
	Widget *_widget;
};

// 装饰类子类，边框装饰类
class BorderDecorator : public Decorator
{
public:
	BorderDecorator(Widget *widget, int width) : Decorator(widget)
	{
		_width = width;
	}
	virtual void draw()
	{
		Decorator::draw();
		drawBorder();
	}

private:
	void drawBorder()
	{
		std::cout << "draw a border with the width is" << _width << std::endl;
	}

private:
	int _width;
};

enum SCROLL_DIR
{
	SCROLL_VERTICAL = 1,
	SCROLL_HORIZONTAL = 2,
};
// 装饰类子类，滚动装饰类
class ScrollDecorator : public Decorator
{
public:
	ScrollDecorator(Widget *widget, SCROLL_DIR dir) : Decorator(widget)
	{
		_dir = dir;
	}
	virtual void draw()
	{
		Decorator::draw();
		drawScroll();
	}

private:
	void drawScroll()
	{
		std::cout << "draw a scroll with the direction is ";
		if (_dir == SCROLL_VERTICAL)
		{
			std::cout << "vertical" << std::endl;
		}
		else
		{
			std::cout << "horizontal" << std::endl;
		}

	}
private:
	SCROLL_DIR _dir;
};

#endif // !_DECORATOR_H_