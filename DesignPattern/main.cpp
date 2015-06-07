#include <iostream>
using std::cout;
using std::endl;

 #include "Singleton.h"
// #include "FactoryMethod.h"
// #include "AbstractFactory.h"
// #include "Builder.h"
// #include "Adapter.h"
// #include "Strategy.h"
// #include "Decorator.h"
// #include "Proxy.h"
// #include "Prototype.h"
// #include "TemplateMethod.h"
// #include "Facade.h"
// #include "Observer.h"
// #include "Memento.h"
// #include "Composite.h"
// #include "Bridge.h"
// #include "Command.h"
// #include "Responsibility.h"
// #include "Mediator.h"

int main()
{
	// Singleton
	Singleton *singleton = Singleton::getInstance();
	Singleton::destroy();

	// FactoryMethod
// 	CPUFactory *cpu = new IntelCPU;
// 	cpu->getCPUInfo();
// 	cpu = new AMDCPU;
// 	cpu->getCPUInfo();
// 	delete cpu;

	// AbstractFactory
// 	ComputerAbFactory *computer = new MyComputer;
// 	computer->createComputer();
// 	computer = new YourComputer;
// 	computer->createComputer();
// 	delete computer;

	// Builder
// 	Director *director = new Director(new ComputerBuilder1);
//	Director *director = new Director(new ComputerBuilder2);	// ��������һ�����͵ĵ��ԣ�ֻ���滻�����߾����༴��
// 	director->buildComputer();
	
	// Adapter
// 	Adapter *adapter = new GraphicsAdapter;
// 	adapter->getInfo();
// 	delete adapter;

	// Strategy
// 	GameRole *warrior = new Warrior(new NormalHP);
// 	warrior->getFight();
// 	GameRole *master = new Master(new PunishHP);
// 	master->getFight();
// 	GameRole *stalker = new Stalker(new PKHP);
// 	stalker->getFight();
// 	delete warrior, master, stalker;

	// Decorator
// 	Widget *textview = new TextView;
// 	Decorator *border = new BorderDecorator(textview, 1);
// 	Decorator *scroll = new ScrollDecorator(border, SCROLL_HORIZONTAL);
// 	scroll->draw();
// 	delete textview, border, scroll;

	// Proxy
// 	Game *game = new Game;
// 	game->openUI(new GuildWarUIProxy("ui_name"));

	// Prototype
// 	auto *skill1 = new Skill(22, 22);
// 	Skill *skill2 = skill1->clone();
// 	skill1->startSkill();
// 	skill2->startSkill();
// 	delete skill1, skill2;

	// TemplateMethod
// 	UIPanels *ui = new roleInfoUI;
// 	ui->start();
// 	ui->exit();
// 	delete ui;

	// Facade
// 	Compiler *compiler = new Compiler;
// 	compiler->compile();
// 	delete compiler;

	// Observer
// 	Subject *subject = new FightSubject;
// 	Observer *roleinfo = new RoleInfoUI;
// 	Observer *bag = new Bag;
// 	subject->addObserver(roleinfo);
// 	subject->addObserver(bag);
// 	subject->notify();
// 	delete subject, roleinfo, bag;

	// Memento
// 	GameRole *mainRole = new GameRole;
// 	cout << "��ʼս��ʱ��ʼ������" << endl;
// 	mainRole->initProperty();
// 	mainRole->showProperty();
// 	cout << "�浵..." << endl;
// 	Memento *memento = mainRole->saveState();
// 	MementoSaver *saver = new MementoSaver(memento);
// 	cout << "��ʼս��..." << endl;
// 	mainRole->fight();
// 	mainRole->showProperty();
// 	cout << "�ָ��浵..." << endl;
// 	mainRole->recoveryState(saver->getMemento());
// 	mainRole->showProperty();

	// Composite
// 	Component *label1 = new Label("label1");
// 	Component *container1 = new Container("container1");
// 	container1->add(label1);
// 	Component *container2 = new Container("container2");
// 	container2->add(container1);
// 	container2->display(1);

	// Bridge
// 	AbstractCar *car = new Car();
// 	AbstractRoad *speedWay = new SpeedWay();
// 	AbstractRoad *street = new Street();
// 	speedWay->setCar(car);
// 	speedWay->run();
// 	street->setCar(car);
// 	street->run();
// 	AbstractDriver *driver = new Man();
// 	driver->setRoad(speedWay);
// 	driver->run();

	// Command
// 	Barbecuer *shifu = new Barbecuer;
// 	Command *mutton = new BakeMuttonCommand(shifu);
// 	Command *wings = new BakeWingsCommand(shifu);
// 	Waiter *waiter = new Waiter;
// 	waiter->addOrder(mutton);
// 	waiter->addOrder(wings);
// 	waiter->notify();

	// Responsibility
// 	Header *pm = new PM("��Ŀ����");
// 	Header *hr = new HR("���²�");
// 	Header *boss = new Boss("�ϰ�");
// 	pm->setReceiver(hr);
// 	hr->setReceiver(boss);
// 	Request *qingjia = new Request(1, "�¼�");
// 	pm->handlerRequest(qingjia);

	// Mediator
// 	PlanPart *planner1 = new Planner();
// 	Colleague *yuying = new Operator(planner1);
// 	Colleague *client = new CodeMonkey(planner1);
// 	Colleague *server = new CodeMonkey(planner1);
// 	planner1->addColleague(yuying);
// 	planner1->addColleague(client);
// 	planner1->addColleague(server);
// 
// 	yuying->sendMessage("�������ģ��������������...");
// 	client->sendMessage("���ð���æ����...");
// 	server->sendMessage("��һ��������Ҫ����...");

	system("pause");
	return 0;
}