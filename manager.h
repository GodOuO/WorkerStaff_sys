#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Manager : public Worker
{
public:
	virtual string getDeptName(); //��ȡ��λ��Ϣ
	virtual void showInfo();    //��ʾ������Ϣ
	Manager(int id, string name, int did);

private:
};
