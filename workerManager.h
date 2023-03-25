#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"

#define FILENAME "empFile.txt"
using namespace std;
class WorkerManager
{
private:
	int m_EmpNum;           //��¼�ļ�������
	Worker** m_EmpArray;    //Ա��ָ������ ��ָ��
	bool m_FileIsEmpty;     //�ļ��Ƿ�Ϊ�� �ı�ʾ(1�� 0�ǿ�)

	bool FileIsEmpty();     //�ļ��Ƿ�Ϊ�� �ı�ʶ����
	bool IdUnique(int id);        //IDΨһ����
	void SelectSort(int s);       //ѡ������s = 1���� / 2����
	void init_Data();		//��ʼ������

public:
	WorkerManager(/* args */);
	void Show_Menu();       //Menu
	void ExitSys_0();       //00Exit
	void Add_Emp_1();       //01���Ա��
	void saveData();        //����txt д��
	int get_EmpNum();       //ͳ��txt �ĳ�Ա����
	void init_Emp();        //��ȡԱ������ ��������
	void show_Emp_2();      //02��ʾԱ��
	void Del_Emp_3();       //03ɾ��Ա��
	int IsExist(int id);    //�ж�ְ��ID�Ƿ����( -1 ������)
	void Mod_Emp_4();       //04�޸�Ա��
	void Find_Emp_5();      //05����Ա��
	void Sort_Emp_6();      //06ѡ������
	void Clea_Emp_7();		//07���

	~WorkerManager();
};