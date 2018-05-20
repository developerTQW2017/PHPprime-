#pragma once

#include"Student.h"

//  顺序表的最大长度
#define MAX_LIST_LENGTH 50

 //  学生宿舍管理系统
class CDormSystem
{
private:
	int m_iListLength;
	TStudent m_oStu[MAX_LIST_LENGTH];

public:
	//  功能：初始化m_iListLength
	CDormSystem();
	~CDormSystem();

	//  功能：添加学生信息
	void add_student();

	//  功能：从文件添加学生信息
	void add_stu_from_file();

	//  功能：删除已有学生信息
	//  site：学生信息所在表中的位置
	void delete_stu(int site);

	//  功能：二分查找学生信息的菜单
	void search_msg_menu(bool bIsRightInput = true);
	void search_name();
	void search_stu_ID();
	void search_room_ID();

	//  功能：将所有学生信息显示在屏幕上
	void print_stu_msg();

	//  功能：将某一学生信息显示到屏幕上
	//  site：学生信息所在表中的位置
	void print_stu_msg(int site);

	//  功能：将所有学生信息保存到同目录下的"DormSystem.dat"文件里
	void save_stu_msg();

	//  功能：冒泡排序
	void bubble_sort_name();
	void bubble_sort_stu_ID();
	void bubble_sort_room_ID();

};