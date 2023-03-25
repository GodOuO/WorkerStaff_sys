#include<iostream>
#include<string>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;
/*
	职工三类（部门编号）：普通职工，经理，老板
		职工编号，职工姓名，职工岗位，指责
			普通职工 ：完成经理交付任务
			经理    ：完成老板交付任务，并下发任务给员工
			老板职责 ：管理公司所有事务
	1.退出管理程序
	2.添加职工信息  实现批量添加，支持信息录入文件，（编号，姓名，部门编号）
	3.显示职工信息
	4.删除离职职工 按编号
	5.修改职工信息 按编号
	6.查找职工信息 按编号 或 姓名
	7.按照编号排序 升序 降序
	8.清空所有文档 （再确认功能）
 */

int main() {
	WorkerManager wm;       //实例化对象
	while (1) {
		int select = -1;
		wm.Show_Menu();         //展示菜单
		cin >> select;
		switch (select)
		{
		case 0: //Quit
			wm.ExitSys_0();
			break;
		case 1: //Add
			wm.Add_Emp_1();
			break;
		case 2: //Show
			wm.show_Emp_2();
			break;
		case 3: //Del
			wm.Del_Emp_3();
			break;
		case 4: //Modify
			wm.Mod_Emp_4();
			break;
		case 5: //Search
			wm.Find_Emp_5();
			break;
		case 6: //Sort
			wm.Sort_Emp_6();
			break;
		case 7: //clean
			wm.Clea_Emp_7();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}