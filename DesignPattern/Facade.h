/*******************************************************************************************************
 * ģʽ��Facade
 *
 * ���壺Ϊ��ϵͳ���е�һ��ӿ��ṩһ��һ�µĽ��棬��ģʽ����һ���߲�Ľӿڣ���һ�ӿ�ʹ����ϵͳ����ʹ��
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
		cout << "ɨ��..." << endl;
	}
	void cifafenxi()
	{
		cout << "�ʷ�����..." <<  endl;
	}
	void yuyifenxi()
	{
		cout << "�������..." << endl;
	}
	void more()
	{
		cout << "����..." << endl;
	}
};

#endif // !_FACADE_H_
