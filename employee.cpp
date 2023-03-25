#include"employee.h"

Employee::Employee(int id, string name, int did) {
	this->setFunc(id, name, did);
}

string Employee::getDeptName() {
	return string("Employee");
}

void Employee::showInfo() {
	cout << "Id : " << this->getId()
		<< "\tName : " << this->getName()
		<< "\tPost : " << this->getDeptName()
		<< "\tDuty : Finish the TASK from Manager" << endl;
}