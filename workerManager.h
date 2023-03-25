#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"

#define FILENAME "empFile.txt"
using namespace std;
class WorkerManager
{
private:
	int m_EmpNum;           //记录文件中人数
	Worker** m_EmpArray;    //员工指针数组 的指针
	bool m_FileIsEmpty;     //文件是否为空 的标示(1空 0非空)

	bool FileIsEmpty();     //文件是否为空 的标识函数
	bool IdUnique(int id);        //ID唯一限制
	void SelectSort(int s);       //选择排序，s = 1升序 / 2降序
	void init_Data();		//初始化数据

public:
	WorkerManager(/* args */);
	void Show_Menu();       //Menu
	void ExitSys_0();       //00Exit
	void Add_Emp_1();       //01添加员工
	void saveData();        //数据txt 写入
	int get_EmpNum();       //统计txt 的成员个数
	void init_Emp();        //读取员工数据 到数组中
	void show_Emp_2();      //02显示员工
	void Del_Emp_3();       //03删除员工
	int IsExist(int id);    //判断职工ID是否存在( -1 不存在)
	void Mod_Emp_4();       //04修改员工
	void Find_Emp_5();      //05查找员工
	void Sort_Emp_6();      //06选择排序
	void Clea_Emp_7();		//07清空

	~WorkerManager();
};