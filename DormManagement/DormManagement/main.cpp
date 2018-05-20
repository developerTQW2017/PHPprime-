/**
*                             _ooOoo_
*                            o8888888o
*                            88" . "88
*                            (| -_- |)
*                            O\  =  /O
*                         ____/`---'\____
*                       .'  \\|     |//  `.
*                      /  \\|||  :  |||//  \
*                     /  _||||| -:- |||||-  \
*                     |   | \\\  -  /// |   |
*                     | \_|  ''\---/''  |   |
*                     \  .-\__  `-`  ___/-. /
*                   ___`. .'  /--.--\  `. . __
*                ."" '<  `.___\_<|>_/___.'  >'"".
*               | | :  `- \`.;`\ _ /`;.`/ - ` : | |
*               \  \ `-.   \_ __\ /__ _/   .-` /  /
*          ======`-.____`-.___\_____/___.-`____.-'======
*                             `=---='
*          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*                     佛祖保佑        永无BUG
**/

/*
39宿舍管理查询软件
【问题描述】
为宿舍管理人员编写一个宿舍管理查询软件。
【基本要求】
（1）采用交互工作方式；
（2）建立数据文件，
数据文件按关键字（姓名、学号、房号）进行排序 (冒泡、选择、插入排序等任选一种)。
（3）建立查询菜单:
(用二分查找实现以下操作)
按姓名查询
按学号查询
按房号查询
打印任一查询结果（可以连续操作）
*/

#include"CDormSystem.h"
#include<iostream>
using namespace std;

//  功能：系统主菜单
//  bIsRightInput：用于确认用户是否正确输入默认为true，错误则置为false
char system_menu(bool &bIsRightInput);

int main(int argc, char *argv[])
{
	CDormSystem oDormSystem;
	bool bIsRightInput = true;

	while (true)
	{
		switch (system_menu(bIsRightInput))
		{
		case '1':
			oDormSystem.add_student();
			break;
		case '2':
			oDormSystem.add_stu_from_file();
			break;
		case '3':
			oDormSystem.search_msg_menu();
			break;
		case '4':
			oDormSystem.print_stu_msg(); 
			break;
		case '5':
			oDormSystem.save_stu_msg();
			break;
		case '0':
			system("cls");
			cout << " 即将退出系统！按任意键将退出！" << endl;
			cout << " ";
			system("pause");
			
			exit(0);
			break;
		default:
			bIsRightInput = false;
		}		
	}

	return 0;
}

  //  功能：系统主菜单
  //  bIsRightInput：用于确认用户是否正确输入默认为true，错误则置为false
char system_menu(bool &bIsRightInput)
{
	system("cls");   //  清屏

	char cUserChoice;

	cout << " ********************************************" << endl;
	cout << " ***********  学生宿舍管理系统  *************" << endl;
	cout << " ***********       V_1.0.0      *************" << endl;
	cout << " ********************************************" << endl;
	cout << " *               主菜单                     *" << endl;
	cout << " *      序 号：         功  能：            *" << endl;
	cout << " *                                          *" << endl;
	cout << " *        1         录入新的学生信息        *" << endl;
	cout << " *        2      从文件录入新的学生信息     *" << endl;
	cout << " *        3     查找学生（可删除学生信息）  *" << endl;
	cout << " *        4         显示所有学生信息        *" << endl;
	cout << " *        5     将所有学生信息保存到文件    *" << endl;
	cout << " *        0            退出系统             *" << endl;
	cout << " *                                          *" << endl;
	cout << " ********************************************" << endl;

	if (bIsRightInput)
		cout << " 请输入您要选择的功能序号（回车确认）：";
	else
		cerr << " 输入错误！请重新输入：";

	cin >> cUserChoice;
	cin.ignore(1024, '\n');

	return cUserChoice;
}