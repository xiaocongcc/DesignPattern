/*******************************************************************************************************
 * ģʽ��Prototype
 *
 * ���壺��ԭ��ʵ��ָ��������������࣬����ͨ��������Щԭ�ʹ����µĶ���
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
		std::cout << "ʹ�ü���id" << _id << std::endl;
	}

private:
	int _id;
	int _resId;
};

#endif // !_PROTOTYPE_H_
