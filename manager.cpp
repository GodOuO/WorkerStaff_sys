#include"manager.h"
Manager::Manager(int id, string name, int did) {
	this->setFunc(id, name, did);
}

string Manager::getDeptName() {
	return string("Manager");
}

void Manager::showInfo() {
	cout << "Id : " << this->getId()
		<< "\tName : " << this->getName()
		<< "\tPost : " << this->getDeptName()
		<< "\tDuty : Finish the TASK from Boss and Send TASK to Staff" << endl;
}