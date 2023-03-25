#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
WorkerManager::WorkerManager() {
	//初始化属性
	ifstream ifs;
	if (this->FileIsEmpty())
	{
		cout << "FILE is NOT Exist!!!" << endl << "ReLoading..." << endl;
		//初始化
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//this->m_FileIsEmpty = 1;
		ifs.close();
		return;
	}

	//3.文件存在，存在记录数据			初始化
	this->m_EmpNum = this->get_EmpNum();	//获取职工人数,并更新员工人数
	this->m_EmpArray = new Worker * [this->m_EmpNum];	//创建数组指针 并初始化长度，开辟空间
	this->init_Emp();		//初始化数据，存到数组中
	cout << "Staff Number : " << this->m_EmpNum << endl;
}

void WorkerManager::Show_Menu() {
	for (int i = 0; i < 10; i++) {
		if (0 == i || 9 == i)
			cout << "**********************" << endl;
		else if (i < 8 && i>0) {
			cout << "******" << i;
			if (1 == i)cout << "-Add\t";
			if (2 == i)cout << "-Show\t";
			if (3 == i)cout << "-Del\t";
			if (4 == i)cout << "-Modify\t";
			if (5 == i)cout << "-Search\t";
			if (6 == i)cout << "-Sort\t";
			if (7 == i)cout << "-Clean\t";
			cout << "******" << endl;
		}
		else
			cout << "******" << i - 8 << "-Quit\t" << "******" << endl;
	}
	cout << "Please Input Your Choice:" << endl;
}

void WorkerManager::ExitSys_0() {
	cout << "Bye Bye!" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp_1() {
	int addNum = 0;     //用户输入数量
	cout << "Please Input the number of Staff which you want to add : ";
	cin >> addNum;
	if (addNum > 0) {
		int id = -1;
		string name;
		int did = -1;
		int newSize = this->m_EmpNum + addNum;      //计算添加新空间大小（原+新）
		Worker** newSpace = new Worker * [newSize]; //开辟新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];  //将原数组内容进行拷贝
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			cout << "Please Input Num" << i + 1 << " Staff's ID:" << endl;
			while (1) {
				cin >> id;
				if (this->IdUnique(id))
					break;
				else
					cout << "ID is Exist, Input Again!" << endl;
			}

			cout << "Please Input Num" << i + 1 << " Staff's Name:" << endl;
			cin >> name;
			cout << "Please Input Num" << i + 1 << " Staff's Post" << endl
				<< "(1.Empolyee ; 2.Manager ; 3.Boss)" << endl;
			cin >> did;
			Worker* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, did);
			case 2:
				worker = new Manager(id, name, did);
			case 3:
				worker = new Boss(id, name, did);
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;  //根据原有的数据位置进行递增存储
		}
		delete[] this->m_EmpArray;      //释放 原有数组空间
		this->m_EmpArray = newSpace;    //更改 新空间指向
		this->m_EmpNum = newSize;       //更新 新职工人数
		//this->m_FileIsEmpty = 0;		//更新	有职工标识
		this->saveData();				//保存数据 在文件中
		cout << "Done，Adding " << addNum << " New Staff" << endl;
	}
	else
	{
		cout << "ERROE input" << endl;
	}
	system("pause");        //任意键回到上级目录
	system("cls");
}

void WorkerManager::saveData() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	//输出打开 写文件
	for (int i = 0; i < this->m_EmpNum; i++)	//每个人数据写入
	{
		ofs << this->m_EmpArray[i]->getId() << " "
			<< this->m_EmpArray[i]->getName() << " "
			<< this->m_EmpArray[i]->getDeptId() << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	int EmpNum = 0;
	int id;
	string name;
	int did;
	ifs.open(FILENAME, ios::in);
	while (ifs >> id && ifs >> name && ifs >> did)
		EmpNum++;	//统计人数
	ifs.close();
	return EmpNum;
}

void WorkerManager::init_Emp() {
	ifstream ifs;
	int index = 0;
	int id;
	string name;
	int did;

	ifs.open(FILENAME, ios::in);
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (1 == did)
			worker = new Employee(id, name, did);
		else if (2 == did)
			worker = new Manager(id, name, did);
		else if (3 == did)
			worker = new Boss(id, name, did);
		else
			cout << "ERROR init_Emp()" << endl;
		this->m_EmpArray[index++] = worker;
	}
	ifs.close();
	//this->init_Data();
}

void WorkerManager::show_Emp_2() {
	if (this->FileIsEmpty())
	{
		cout << "FILE is NOT Exist!!!" << endl;
	}
	else {
		this->init_Emp();
		for (int i = 0; i < m_EmpNum; i++) {	//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

bool WorkerManager::FileIsEmpty() {
	ifstream ifs;
	char ch;
	ifs.open(FILENAME, ios::in);	//读文件
	ifs >> ch;		//文件为空时，文件尾会有一个字符，ch读出接收后再用eof()判断是否为空
	if ((!ifs.is_open()) || (ifs.eof())) {	//1.未找到文件txt		2.文件为空
		m_FileIsEmpty = 1;
	}
	else
		m_FileIsEmpty = 0;
	ifs.close();
	return m_FileIsEmpty;
}

void WorkerManager::Del_Emp_3() {
	if (this->FileIsEmpty())
		cout << "FILE is NOT Exist!!!" << endl;
	else {	//按职工编号删除
		int id = -1;
		cout << "Please Input DEL_Staff's ID :" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (-1 != index) {	//存在 执行删除
			for (int i = index; i < this->m_EmpNum - 1; i++)
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			this->m_EmpNum--;
			this->saveData();
			cout << "Done! Del_Dtaff which id is " << id << endl;
		}
		else {
			cout << "Staff is NOT Exist , Del_ERROR" << endl;
		}
		system("pause");
		system("cls");
	}
}

int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->getId()) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp_4() {
	if (this->FileIsEmpty())
		cout << "FILE is NOT Exist!!!" << endl;
	else {
		int id = -1;
		cout << "Please Input Mod_Staff's ID :" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (-1 != index) {	//存在 执行修改
			int mod_id;
			string mod_name;
			int mod_did;
			delete this->m_EmpArray[index];
			cout << "Find ID : " << id << endl;
			cout << "Please Input Staff's NewID:" << endl;
			cin >> mod_id;
			cout << "Please Input Staff's NewName:" << endl;
			cin >> mod_name;
			cout << "Please Input Staff's NewPost" << endl
				<< "(1.Empolyee ; 2.Manager ; 3.Boss)" << endl;
			cin >> mod_did;

			Worker* worker = NULL;
			switch (mod_did)
			{
			case 1:
				worker = new Employee(mod_id, mod_name, mod_did);
			case 2:
				worker = new Manager(mod_id, mod_name, mod_did);
			case 3:
				worker = new Boss(mod_id, mod_name, mod_did);
			default:
				break;
			}
			this->m_EmpArray[index] = worker;
			this->saveData();
			cout << "Done! Modified Id : " << mod_id << endl;
		}
		else {
			cout << "Staff is NOT Exist , Mod_ERROR" << endl;
		}
		system("pause");
		system("cls");
	}
}

void WorkerManager::Find_Emp_5() {
	if (this->FileIsEmpty())
		cout << "FILE is NOT Exist!!!" << endl;
	else {
		int select = -1;
		int id;
		bool flag = 0;	//查找标识 默认未找到0
		string name;
		cout << "Please Choice the way to search :" << endl
			<< "(1.ID Search)" << endl
			<< "(2.Name Search)" << endl;
		cin >> select;
		if (1 == select) {
			cout << "Please Input Searching ID:" << endl;
			cin >> id;
			int index = this->IsExist(id);
			if (-1 != index) {
				cout << "Find it! Data :" << endl;
				this->m_EmpArray[index]->showInfo();	//多态 纯虚函数，子类重写父类即可
			}
			else {
				cout << "Staff is NOT Exist , Search_ERROR" << endl;
			}
		}
		else if (2 == select) {
			cout << "Please Input Searching Name:" << endl;
			cin >> name;
			for (int i = 0; i < m_EmpNum; i++) {
				if (name == this->m_EmpArray[i]->getName()) {
					flag = 1;
					cout << "Find it! Data :" << endl;
					this->m_EmpArray[i]->showInfo();	//多态 纯虚函数，子类重写父类即可
				}
			}
			if (0 == flag)
				cout << "Staff is NOT Exist , Search_ERROR" << endl;
		}
		else
			cout << "Choice ERROR!!!" << endl;
	}
	system("pause");
	system("cls");
}

bool WorkerManager::IdUnique(int id) {
	if (this->FileIsEmpty())
		return 1;
	else {
		if (-1 == this->IsExist(id))
			return 1;
		else
			return 0;
	}
}

void WorkerManager::Sort_Emp_6() {
	if (this->FileIsEmpty())
		cout << "FILE is NOT Exist!!!" << endl;
	else {
		int select = -1;
		cout << "Please Choice the way to Sort :" << endl
			<< "(1.Ascend)" << endl
			<< "(2.Descend)" << endl;
		cin >> select;
		this->SelectSort(select);
		cout << "Done! Sorted!" << endl;
		this->show_Emp_2();
	}
	system("pause");
	system("cls");
}

void WorkerManager::SelectSort(int select) {
	for (int i = 0; i < this->m_EmpNum; i++) {
		int minOrMax = i;
		for (int j = i + 1; j < this->m_EmpNum; j++) {
			if (1 == select) {	//升序
				if (this->m_EmpArray[minOrMax]->getId() > this->m_EmpArray[j]->getId())
					minOrMax = j;
			}
			else {			//降序
				if (this->m_EmpArray[minOrMax]->getId() < this->m_EmpArray[j]->getId())
					minOrMax = j;
			}
		}
		if (i != minOrMax) {
			Worker* temp = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
			this->m_EmpArray[minOrMax] = temp;
		}
	}
	this->saveData();
}

void WorkerManager::init_Data() {
	//升序
	this->SelectSort(1);
	//顺序去重
	for (int i = 0; i < this->m_EmpNum; i++) {                     //每次循环判断m_Array[i]的值是否重复
		for (int j = i + 1; j < this->m_EmpNum;) {                 //暂时不给出循环条件，若出现重复数据，
			if (this->m_EmpArray[i] == this->m_EmpArray[j]) {              //判断某一个数据和后面的数据是否相同
				for (int m = j; m < this->m_EmpNum - 1; m++) {     //若相同，将后面的数据向前移动，覆盖前面的数据，则数组长度减小，即长度变为len - 1
					this->m_EmpArray[m] = this->m_EmpArray[m + 1];
				}
				(this->m_EmpNum)--;                                  //循环条件，数据长度减一
			}
			else {                                      //如果某一个数据与后面的数据不同，则这个数据与后面数据的后面一个数据比较是否相同
				j++;
			}
		}
	}
	this->saveData();
}

void WorkerManager::Clea_Emp_7() {
	int select = -1;
	cout << "Please For sure to Clean :" << endl
		<< "(1.Yes)" << endl
		<< "(2.No)" << endl;
	cin >> select;
	if (1 == select){
		ofstream ofs(FILENAME, ios::trunc);		//删除文件后重新创建
		ofs.close();

		if (0 == this->FileIsEmpty()){		//删除堆区每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
			}
		}
		delete[] this->m_EmpArray;			//删除堆区数据指针
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		cout << "Done! Clean ALL!" << endl;
	}
	system("pause");
	system("cls");
}


WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL){
		for (int i = 0; i < this->m_EmpNum; i++){
			if (this->m_EmpArray[i] != NULL)
				delete this->m_EmpArray[i];
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}