#pragma once

// ѧ����������󳤶�
#define MAX_NAME_LENGTH 25

// ѧ����Ϣ
typedef struct tag_TSTUDENT
{
	// ѧ�������
	int  m_iRoomID;

	// ѧ������
	char m_szName[MAX_NAME_LENGTH];

	// ѧ��ѧ��
	int  m_iStuID;
	
}TStudent;
