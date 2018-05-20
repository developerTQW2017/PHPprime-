#pragma once

#include"Student.h"

//  ˳������󳤶�
#define MAX_LIST_LENGTH 50

 //  ѧ���������ϵͳ
class CDormSystem
{
private:
	int m_iListLength;
	TStudent m_oStu[MAX_LIST_LENGTH];

public:
	//  ���ܣ���ʼ��m_iListLength
	CDormSystem();
	~CDormSystem();

	//  ���ܣ����ѧ����Ϣ
	void add_student();

	//  ���ܣ����ļ����ѧ����Ϣ
	void add_stu_from_file();

	//  ���ܣ�ɾ������ѧ����Ϣ
	//  site��ѧ����Ϣ���ڱ��е�λ��
	void delete_stu(int site);

	//  ���ܣ����ֲ���ѧ����Ϣ�Ĳ˵�
	void search_msg_menu(bool bIsRightInput = true);
	void search_name();
	void search_stu_ID();
	void search_room_ID();

	//  ���ܣ�������ѧ����Ϣ��ʾ����Ļ��
	void print_stu_msg();

	//  ���ܣ���ĳһѧ����Ϣ��ʾ����Ļ��
	//  site��ѧ����Ϣ���ڱ��е�λ��
	void print_stu_msg(int site);

	//  ���ܣ�������ѧ����Ϣ���浽ͬĿ¼�µ�"DormSystem.dat"�ļ���
	void save_stu_msg();

	//  ���ܣ�ð������
	void bubble_sort_name();
	void bubble_sort_stu_ID();
	void bubble_sort_room_ID();

};