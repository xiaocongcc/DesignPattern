/*******************************************************************************************************
 * ģʽ��Adapter
 *
 * ���壺��һ����Ľӿ�ת���ɿͻ�ϣ������һ���ӿڡ�Apdateʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ��
 *		 ����һ������
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
		return "�����Կ�";
	}
};

class Adapter
{
public:
	virtual void getInfo() = 0;
};

// �Կ�������
class GraphicsAdapter : public Adapter
{
public:
	void getInfo()
	{
		Graphics *graphics = new Graphics;
		std::cout << "ʹ���Կ�����������������ʹ��" << graphics->getGraphicsInfo() << std::endl;
		delete graphics;
	}
};



#endif // !_ADAPTER_H_
