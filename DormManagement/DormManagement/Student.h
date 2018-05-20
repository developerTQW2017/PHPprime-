#pragma once

// 学生姓名的最大长度
#define MAX_NAME_LENGTH 25

// 学生信息
typedef struct tag_TSTUDENT
{
	// 学生房间号
	int  m_iRoomID;

	// 学生姓名
	char m_szName[MAX_NAME_LENGTH];

	// 学生学号
	int  m_iStuID;
	
}TStudent;
