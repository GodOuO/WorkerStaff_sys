#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Manager : public Worker
{
public:
	virtual string getDeptName(); //获取岗位信息
	virtual void showInfo();    //显示个人信息
	Manager(int id, string name, int did);

private:
};
