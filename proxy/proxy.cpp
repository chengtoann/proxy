#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
//Schoolgirl类
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
//Subject类，定义了RealSubject类和Proxy的共用接口，这样就可以在任何使用RealSubject的地方使用Proxy
class IGiveGift
{
public:
	virtual void GiveDolls()=0;
	virtual void GiveFlowers()=0;
	virtual void GiveChocolate()=0;
};
//RealSubject类，定义了Proxy类所代表的真实实体
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
		cout<<mm->getName()<<" 送你洋娃娃"<<endl;
	}
	void GiveFlowers()
	{
		cout<<mm->getName()<<" 送你鲜花"<<endl;
	}
	void GiveChocolate()
	{
		cout<<mm->getName()<<" 送你巧克力"<<endl;
	}
};
//Proxy类，保存一个引用式的代理可以访问实体，并提供一个与Subject的接口相同的接口，这样代理就可以用来代替实体
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
//Client，客户端
void main()
{
	SchoolGirl* jiaojiao=new SchoolGirl();
	jiaojiao->setName("李娇娇");
 
	Proxy* daili=new Proxy(jiaojiao);
 
	daili->GiveDolls();
	daili->GiveFlowers();
	daili->GiveChocolate();
 
	delete jiaojiao;
        jiaojiao=NULL;
	delete daili;
        daili=NULL;
}