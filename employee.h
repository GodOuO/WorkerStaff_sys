#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

class Employee : public Worker
{
private:
	/* data */
public:
	virtual string getDeptName(); //获取岗位信息
	virtual void showInfo();    //显示个人信息
	Employee(int id, string name, int did); //构造函数
};
