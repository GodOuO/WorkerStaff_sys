#include"worker.h"
int Worker::getId() {
	return m_Id;
}
string Worker::getName() {
	return m_Name;
}
int Worker::getDeptId() {
	return m_DeptId;
}
void Worker::setFunc(int id, string name, int did) {
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}