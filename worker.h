#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
private:
	int m_Id;
	string m_Name;
	int m_DeptId;
public:
	int getId();
	string getName();
	int getDeptId();
	void setFunc(int id, string name, int did);
	virtual void showInfo() = 0;    //显示个人信息
	virtual string getDeptName() = 0; //获取岗位信息
	//Worker(/* args */);
	//~Worker();
};
