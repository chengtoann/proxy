#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
//Schoolgirl��
class SchoolGirl
{
private:
	string name;
public:
	void setName(string na)
	{
		name=na;
	}
	string getName()
	{
		return name;
	}
};
//Subject�࣬������RealSubject���Proxy�Ĺ��ýӿڣ������Ϳ������κ�ʹ��RealSubject�ĵط�ʹ��Proxy
class IGiveGift
{
public:
	virtual void GiveDolls()=0;
	virtual void GiveFlowers()=0;
	virtual void GiveChocolate()=0;
};
//RealSubject�࣬������Proxy�����������ʵʵ��
class Pursuit:public IGiveGift
{
private:
	SchoolGirl* mm;
public:
	Pursuit(SchoolGirl* m)
	{
		mm=m;
	}
	void GiveDolls()
	{
		cout<<mm->getName()<<" ����������"<<endl;
	}
	void GiveFlowers()
	{
		cout<<mm->getName()<<" �����ʻ�"<<endl;
	}
	void GiveChocolate()
	{
		cout<<mm->getName()<<" �����ɿ���"<<endl;
	}
};
//Proxy�࣬����һ������ʽ�Ĵ�����Է���ʵ�壬���ṩһ����Subject�Ľӿ���ͬ�Ľӿڣ���������Ϳ�����������ʵ��
class Proxy:public IGiveGift
{
	Pursuit* gg;
public:
	Proxy(SchoolGirl* mm)
	{
		gg=new Pursuit(mm);
	}
	void GiveDolls()
	{
		gg->GiveDolls();
	}
	void GiveFlowers()
	{
		gg->GiveFlowers();
	}
	void GiveChocolate()
	{
		gg->GiveChocolate();
	}

};
//Client���ͻ���
void main()
{
	SchoolGirl* jiaojiao=new SchoolGirl();
	jiaojiao->setName("���");
 
	Proxy* daili=new Proxy(jiaojiao);
 
	daili->GiveDolls();
	daili->GiveFlowers();
	daili->GiveChocolate();
 
	delete jiaojiao;
        jiaojiao=NULL;
	delete daili;
        daili=NULL;
}