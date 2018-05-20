#include "CDormSystem.h"
#include <iostream>
#include <fstream>
using namespace std;

CDormSystem::CDormSystem()
{
	m_iListLength = 0;  
}

CDormSystem::~CDormSystem()
{
	m_iListLength = 0;
}

void CDormSystem::add_student()
{
	system("cls");

	cout << " ********************************************" << endl;
	cout << " ***********  学生宿舍管理系统  *************" << endl;
	cout << " ***********       V_1.0.0      *************" << endl;
	cout << " ********************************************" << endl;
	cout << " *              录入新学生信息              *" << endl;
	cout << " ********************************************" << endl;
	
	if (m_iListLength == MAX_LIST_LENGTH)
	{
		cerr << "列表已满！添加失败！" << endl;
		return;
	}
	if (m_iListLength <0 || m_iListLength >MAX_LIST_LENGTH)
	{
		cerr << "程序已出错！请退出程序！" << endl;
		return;
	}

		

	cout << " 请依次输入学生的房间号、姓名、学号（空格隔开）：" << endl;
	cout << " ";
	cin	>> m_oStu[m_iListLength].m_iRoomID;					// 房间号
	cin >> m_oStu[m_iListLength].m_szName;   // 姓名
	cin	>> m_oStu[m_iListLength].m_iStuID;					// 学号
	

	m_iListLength++;  
}

void CDormSystem::add_stu_from_file()
{
	system("cls");
	
	ifstream oStuInFile;

	oStuInFile.open("DormSystem.txt", ios::in | ios::_Nocreate);

	if (!oStuInFile.is_open())
	{
		cerr << " 文件打开失败！" << endl;
		cerr << " 可能的原因：当前目录下不存在\"DormSystem.txt\"文件" << endl;
		cout << " 按任意键返回主菜单！" << endl;
		system("pause");

		return;
	}
	cout << " 请确保文件内容按照：\"房间号 姓名 学号\"的方式排列！" << endl;
	cout << " 程序将从文件的第一行开始读取" << endl << endl << endl;

	while ((!oStuInFile.eof())|| (m_iListLength >= MAX_LIST_LENGTH))
	{
		oStuInFile >> m_oStu[m_iListLength].m_iRoomID;			// 房间号
		oStuInFile >> m_oStu[m_iListLength].m_szName;			// 姓名
		oStuInFile >> m_oStu[m_iListLength].m_iStuID;			// 学号
		

		m_iListLength++;
	}

	cout << " 数据读取成功！" << endl;
	cout << " 按任意键返回主菜单！" << endl;
	system("pause");

	oStuInFile.close();
}

void CDormSystem::delete_stu(int site)
{
	for (int i = site; i < m_iListLength - 1; i++)
		m_oStu[i] = m_oStu[i + 1];

	m_iListLength--;  // 删除完成以后，表长减一

	cout << "删除完成！" << endl;
	cout << "按任意键返回主菜单。" << endl;
	system("pause");

}

void CDormSystem::search_msg_menu(bool bIsRightInput)
{
	system("cls");
	char szUserChoice;

	cout << " ********************************************" << endl;
	cout << " ***********  学生宿舍管理系统  *************" << endl;
	cout << " ***********       V_1.0.0      *************" << endl;
	cout << " ********************************************" << endl;
	cout << " *             查找菜单                     *" << endl;
	cout << " *      序 号：         说  明：            *" << endl;
	cout << " *                                          *" << endl;
	cout << " *        1             房间号              *" << endl;
	cout << " *        2              姓名               *" << endl;
	cout << " *        3              学号               *" << endl;
	cout << " *        0           返回主菜单            *" << endl;
	cout << " ********************************************" << endl;
	if (bIsRightInput)
		cout << " 请输入需要查找的关键字类型（房间号、姓名、学号）的序号：";
	else
		cout << " 输入错误！请重新输入：";

	cin >> szUserChoice;
	cin.ignore(1024, '\n');

	switch (szUserChoice)
	{
	case '1':
		search_room_ID();
		break;
	case '2':
		search_name();
		break;
	case'3':
		search_stu_ID();
		break;
	case'0':
		return;
	default:
		bIsRightInput = false;
		search_msg_menu(bIsRightInput);
	}
}

void CDormSystem::search_room_ID()
{
	bubble_sort_room_ID();
	system("cls");
	int low = 0;
	int high = m_iListLength - 1;
	int mid = (low + high) / 2;
	int iKey;
	char cUserChoice;

	cout << "请输入待查找的学生房间号：";
	cin >> iKey;
	cin.clear();

	while (low <= high)  // 二分查找
	{
		mid = (low + high) / 2;
		if (iKey == m_oStu[mid].m_iRoomID)
		{
			cout << "已找到该学生；" << endl;
			print_stu_msg(mid);
			cout << "是否删除该学生信息（Y/N）：";
			cin >> cUserChoice;
			if (cUserChoice == 'Y' || cUserChoice == 'y')
			{
				delete_stu(mid);
				return;
			}
			cout << "信息未删除！";
			cout << "按任意键返回主菜单。" << endl;
			system("pause");
			break;
		}
		else if (iKey < m_oStu[mid].m_iStuID)
			high = mid - 1;
		else
			low = mid + 1;
	}

	cout << " 未找到与该信息匹配的学生！" << endl;
	cout << "按任意键返回主菜单。" << endl;
	system("pause");
}

void CDormSystem::search_name()
{
	bubble_sort_name();
	system("cls");
	int low = 0;
	int high = m_iListLength - 1;
	int mid = (low + high) / 2;
	char iKey[MAX_NAME_LENGTH];
	char cUserChoice;

	cout << "请输入待查找的学生姓名：";
	cin >> iKey;

	while (low <= high)  // 二分查找
	{
		mid = (low + high) / 2;
		if (strcmp(iKey, m_oStu[mid].m_szName) == 0)
		{
			cout << "已找到该学生；" << endl;
			print_stu_msg(mid);
			cout << "是否删除该学生信息（Y/N）：";
			cin >> cUserChoice;
			if (cUserChoice == 'Y' || cUserChoice == 'y')
			{
				delete_stu(mid);
				return;
			}
			cout << "信息未删除！";
			cout << "按任意键返回主菜单。" << endl;
			system("pause");
			break;
		}
		else if (strcmp(iKey, m_oStu[mid].m_szName) < 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << " 未找到与该信息匹配的学生！" << endl;
	cout << "按任意键返回主菜单。" << endl;
	system("pause");
}

void CDormSystem::search_stu_ID()
{
	bubble_sort_stu_ID();
	system("cls");
	int low = 0;
	int high = m_iListLength - 1;
	int mid = (low + high) / 2;
	int iKey;
	char cUserChoice;

	cout << "请输入待查找的学生学号：";
	cin >> iKey;

	while (low <= high)  // 二分查找
	{
		mid = (low + high) / 2;
		if (iKey == m_oStu[mid].m_iStuID)
		{
			cout << "已找到该学生；" << endl;
			print_stu_msg(mid);
			cout << "是否删除该学生信息（Y/N）：";
			cin >> cUserChoice;
			if (cUserChoice == 'Y'|| cUserChoice == 'y')
			{
				delete_stu(mid);
				return;
			}
			cout << "信息未删除！";
			cout << "按任意键返回主菜单。" << endl;
			system("pause");
			break;
		}
		else if (iKey < m_oStu[mid].m_iStuID)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << " 未找到与该信息匹配的学生！" << endl;
	cout << "按任意键返回主菜单。" << endl;
	system("pause");
}

void CDormSystem::print_stu_msg()
{
	system("cls");

	if (m_iListLength <0 || m_iListLength >MAX_LIST_LENGTH)
	{
		cout << "程序已出错！请退出程序！" << endl;
		return;
	}

	bubble_sort_room_ID();

	cout << " 房间号\t\t姓名\t\t学号" << endl;
	for (int i = 0; i < m_iListLength; i++)
	{
		cout << " " << m_oStu[i].m_iRoomID << "\t\t" << m_oStu[i].m_szName << "\t\t" << m_oStu[i].m_iStuID << endl;
	}

	cout << endl;
	cout<< " 按任意键返回主菜单！" << endl;
	system("pause");

}

void CDormSystem::print_stu_msg(int site)
{
	cout << endl;
	cout << " 房间号\t\t姓名\t\t学号" << endl;
	cout << " " << m_oStu[site].m_iRoomID << "\t\t" << m_oStu[site].m_szName << "\t\t" << m_oStu[site].m_iStuID << endl;
	cout << endl;
}

void CDormSystem::save_stu_msg()
{
	system("cls");

	char szUserChoice;

	cout << " ********************************************" << endl;
	cout << " ***********  学生宿舍管理系统  *************" << endl;
	cout << " ***********       V_1.0.0      *************" << endl;
	cout << " ********************************************" << endl;
	cout << " *             查找菜单                     *" << endl;
	cout << " *      序 号：         说  明：            *" << endl;
	cout << " *                                          *" << endl;
	cout << " *        1             房间号              *" << endl;
	cout << " *        2              姓名               *" << endl;
	cout << " *        3              学号               *" << endl;
	cout << " *        0           返回主菜单            *" << endl;
	cout << " ********************************************" << endl;

	cout << " 请问按什么关键字排序保存？" << endl;
	cout << " 请输入序号（输错则默认为房间号）：";

	cin >> szUserChoice;
	cin.ignore(1024, '\n');
	cout << endl << endl;

	switch (szUserChoice)
	{
	case '1':
		cout << " 数据将按房间号排列保存！" << endl;
		bubble_sort_room_ID();
		break;
	case '2':
		cout << " 数据将按姓名排列保存！" << endl;
		bubble_sort_name();
		break;
	case'3':
		cout << " 数据将按学号排列保存！" << endl;
		bubble_sort_stu_ID();
		break;
	case'0':
		return;
	default:
		cout << " 数据将按房间号排列保存！" << endl;
		bubble_sort_room_ID();
	}

	ofstream oStuOutFile;
	oStuOutFile.open("DormSystem.dat", ios::out);

	if (!oStuOutFile.is_open())
	{
		cerr << " 数据保存失败！" << endl;
		cout << " 按任意键返回主菜单！" << endl;
		system("pause");

		return;
	}

	oStuOutFile << "房间号\t\t姓名\t\t学号" << endl;
	oStuOutFile.close();

	oStuOutFile.open("DormSystem.dat", ios::out | ios::app);

	if (!oStuOutFile.is_open())
	{
		cerr << " 数据保存失败！" << endl;
		cout << " 按任意键返回主菜单！" << endl;
		system("pause");
		
		return;
	}

	for (int i = 0; i < m_iListLength; i++)
	{
		oStuOutFile << m_oStu[i].m_iRoomID << "\t\t" << m_oStu[i].m_szName << "\t\t" << m_oStu[i].m_iStuID << endl;
	}

	cout << " 数据保存成功！" << endl;

	cout << " 按任意键返回主菜单！" << endl;
	system("pause");

	oStuOutFile.close();
}

void CDormSystem::bubble_sort_name()
{
	bool change;
	change = true;
	for (int i = 0; i < m_iListLength - 1 && change; i++)
	{
		change = false;
		for (int j = 0; j < m_iListLength - i - 1; j++)
		{
			if (strcmp(m_oStu[j].m_szName, m_oStu[j + 1].m_szName) > 0)
			{
				TStudent tmp;
				tmp = m_oStu[j + 1];
				m_oStu[j + 1] = m_oStu[j];
				m_oStu[j] = tmp;
				change = true;
			}
		}
	}
}

void CDormSystem::bubble_sort_stu_ID()
{
	bool change;
	change = true;
	for (int i = 0; i < m_iListLength - 1 && change; i++)
	{
		change = false;
		for (int j = 0; j < m_iListLength - i - 1; j++)
		{
			if (m_oStu[j].m_iStuID > m_oStu[j + 1].m_iStuID)
			{
				TStudent tmp;
				tmp = m_oStu[j + 1];
				m_oStu[j + 1] = m_oStu[j];
				m_oStu[j] = tmp;
				change = true;
			}
		}
	}
}

void CDormSystem::bubble_sort_room_ID()
{
	bool change;
	change = true;
	for (int i = 0; i < m_iListLength - 1 && change; i++)
	{
		change = false;
		for (int j = 0; j < m_iListLength - i - 1; j++)
		{
			if (m_oStu[j].m_iRoomID > m_oStu[j + 1].m_iRoomID)
			{
				TStudent tmp;
				tmp = m_oStu[j + 1];
				m_oStu[j + 1] = m_oStu[j];
				m_oStu[j] = tmp;
				change = true;
			}
		}
	}
}