#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Boss : public Worker
{
public:
	virtual string getDeptName(); //��ȡ��λ��Ϣ
	virtual void showInfo();    //��ʾ������Ϣ
	Boss(int id, string name, int did);

private:
};
