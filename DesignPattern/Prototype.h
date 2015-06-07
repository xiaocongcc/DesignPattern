/*******************************************************************************************************
 * 模式：Prototype
 *
 * 定义：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象
 *
*******************************************************************************************************/

#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

#include <iostream>

class Skill
{
public:
	Skill(int id,int resId):_id(id), _resId(resId){}
	Skill *clone()
	{
		auto *cloneSkill = new Skill(_id, _resId);
		return cloneSkill;
	}
	void startSkill()
	{
		std::cout << "使用技能id" << _id << std::endl;
	}

private:
	int _id;
	int _resId;
};

#endif // !_PROTOTYPE_H_
