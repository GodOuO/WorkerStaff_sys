#include<iostream>
#include<string>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;
/*
	ְ�����ࣨ���ű�ţ�����ְͨ���������ϰ�
		ְ����ţ�ְ��������ְ����λ��ָ��
			��ְͨ�� ����ɾ���������
			����    ������ϰ彻�����񣬲��·������Ա��
			�ϰ�ְ�� ������˾��������
	1.�˳��������
	2.���ְ����Ϣ  ʵ��������ӣ�֧����Ϣ¼���ļ�������ţ����������ű�ţ�
	3.��ʾְ����Ϣ
	4.ɾ����ְְ�� �����
	5.�޸�ְ����Ϣ �����
	6.����ְ����Ϣ ����� �� ����
	7.���ձ������ ���� ����
	8.��������ĵ� ����ȷ�Ϲ��ܣ�
 */

int main() {
	WorkerManager wm;       //ʵ��������
	while (1) {
		int select = -1;
		wm.Show_Menu();         //չʾ�˵�
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