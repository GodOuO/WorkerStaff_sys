#include"boss.h"
Boss::Boss(int id, string name, int did) {
	this->setFunc(id, name, did);
}
string Boss::getDeptName() {
	return string("Boss");
}
void Boss::showInfo() {
	cout << "Id : " << this->getId()
		<< "\tName : " << this->getName()
		<< "\tPost : " << this->getDeptName()
		<< "\tDuty : Control EveryThing!" << endl;
}