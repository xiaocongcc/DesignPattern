/*******************************************************************************************************
 * ģʽ��Decorator
 *
 * ���壺��̬�ظ�һ������ע�ⲻ���ࣩ���һЩ�����ְ�𣬾����ӹ�����˵��װ��ģʽ�����������Ϊ��
 *
*******************************************************************************************************/

#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include <iostream>

// �ؼ�����
class Widget
{
public:
	virtual void draw() = 0;
};

// ����ؼ���
class TextView : public Widget
{
public:
	void draw()
	{
		std::cout << "draw textview" << std::endl;
	}
};

// װ���࣬�̳��ڿؼ�
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

// װ�������࣬�߿�װ����
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
// װ�������࣬����װ����
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