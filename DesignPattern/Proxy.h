/*******************************************************************************************************
 * 模式：Proxy
 *
 * 定义：为其他对象提供一种代理以控制对这个对象的访问
 *
*******************************************************************************************************/

#ifndef _PROXY_H
#define _PROXY_H

#include <iostream>
using std::cout;
using std::endl;

class UIPanels
{
public:
	virtual void loadUI() = 0;
};

class GuildWarUI : public UIPanels
{
public:
	GuildWarUI(const char *name):_name(name){}
	void loadUI()
	{
		cout << "load GuildWarUI " << _name << endl;
	}

private:
	const char* _name;
};

class GuildWarUIProxy : public UIPanels
{
public:
	GuildWarUIProxy(const char *name)
	{
		_guildWarUI = new GuildWarUI(name);
	}
	void loadUI()
	{
		cout << "GuildWarUIProxy loadUI" << endl;
		if (_guildWarUI != nullptr)
		{
			_guildWarUI->loadUI();
		}
	}

private:
	UIPanels *_guildWarUI;
};

class Game
{
public:
	void openUI(UIPanels *ui)
	{
		ui->loadUI();
	}
};

#endif // !_PROXY_H
