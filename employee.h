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
	virtual string getDeptName(); //��ȡ��λ��Ϣ
	virtual void showInfo();    //��ʾ������Ϣ
	Employee(int id, string name, int did); //���캯��
};
