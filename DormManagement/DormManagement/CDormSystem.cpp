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
	cout << " ***********  ѧ���������ϵͳ  *************" << endl;
	cout << " ***********       V_1.0.0      *************" << endl;
	cout << " ********************************************" << endl;
	cout << " *              ¼����ѧ����Ϣ              *" << endl;
	cout << " ********************************************" << endl;
	
	if (m_iListLength == MAX_LIST_LENGTH)
	{
		cerr << "�б����������ʧ�ܣ�" << endl;
		return;
	}
	if (m_iListLength <0 || m_iListLength >MAX_LIST_LENGTH)
	{
		cerr << "�����ѳ������˳�����" << endl;
		return;
	}

		

	cout << " ����������ѧ���ķ���š�������ѧ�ţ��ո��������" << endl;
	cout << " ";
	cin	>> m_oStu[m_iListLength].m_iRoomID;					// �����
	cin >> m_oStu[m_iListLength].m_szName;   // ����
	cin	>> m_oStu[m_iListLength].m_iStuID;					// ѧ��
	

	m_iListLength++;  
}

void CDormSystem::add_stu_from_file()
{
	system("cls");
	
	ifstream oStuInFile;

	oStuInFile.open("DormSystem.txt", ios::in | ios::_Nocreate);

	if (!oStuInFile.is_open())
	{
		cerr << " �ļ���ʧ�ܣ�" << endl;
		cerr << " ���ܵ�ԭ�򣺵�ǰĿ¼�²�����\"DormSystem.txt\"�ļ�" << endl;
		cout << " ��������������˵���" << endl;
		system("pause");

		return;
	}
	cout << " ��ȷ���ļ����ݰ��գ�\"����� ���� ѧ��\"�ķ�ʽ���У�" << endl;
	cout << " ���򽫴��ļ��ĵ�һ�п�ʼ��ȡ" << endl << endl << endl;

	while ((!oStuInFile.eof())|| (m_iListLength >= MAX_LIST_LENGTH))
	{
		oStuInFile >> m_oStu[m_iListLength].m_iRoomID;			// �����
		oStuInFile >> m_oStu[m_iListLength].m_szName;			// ����
		oStuInFile >> m_oStu[m_iListLength].m_iStuID;			// ѧ��
		

		m_iListLength++;
	}

	cout << " ���ݶ�ȡ�ɹ���" << endl;
	cout << " ��������������˵���" << endl;
	system("pause");

	oStuInFile.close();
}

void CDormSystem::delete_stu(int site)
{
	for (int i = site; i < m_iListLength - 1; i++)
		m_oStu[i] = m_oStu[i + 1];

	m_iListLength--;  // ɾ������Ժ󣬱���һ

	cout << "ɾ����ɣ�" << endl;
	cout << "��������������˵���" << endl;
	system("pause");

}

void CDormSystem::search_msg_menu(bool bIsRightInput)
{
	system("cls");
	char szUserChoice;

	cout << " ********************************************" << endl;
	cout << " ***********  ѧ���������ϵͳ  *************" << endl;
	cout << " ***********       V_1.0.0      *************" << endl;
	cout << " ********************************************" << endl;
	cout << " *             ���Ҳ˵�                     *" << endl;
	cout << " *      �� �ţ�         ˵  ����            *" << endl;
	cout << " *                                          *" << endl;
	cout << " *        1             �����              *" << endl;
	cout << " *        2              ����               *" << endl;
	cout << " *        3              ѧ��               *" << endl;
	cout << " *        0           �������˵�            *" << endl;
	cout << " ********************************************" << endl;
	if (bIsRightInput)
		cout << " ��������Ҫ���ҵĹؼ������ͣ�����š�������ѧ�ţ�����ţ�";
	else
		cout << " ����������������룺";

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

	cout << "����������ҵ�ѧ������ţ�";
	cin >> iKey;
	cin.clear();

	while (low <= high)  // ���ֲ���
	{
		mid = (low + high) / 2;
		if (iKey == m_oStu[mid].m_iRoomID)
		{
			cout << "���ҵ���ѧ����" << endl;
			print_stu_msg(mid);
			cout << "�Ƿ�ɾ����ѧ����Ϣ��Y/N����";
			cin >> cUserChoice;
			if (cUserChoice == 'Y' || cUserChoice == 'y')
			{
				delete_stu(mid);
				return;
			}
			cout << "��Ϣδɾ����";
			cout << "��������������˵���" << endl;
			system("pause");
			break;
		}
		else if (iKey < m_oStu[mid].m_iStuID)
			high = mid - 1;
		else
			low = mid + 1;
	}

	cout << " δ�ҵ������Ϣƥ���ѧ����" << endl;
	cout << "��������������˵���" << endl;
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

	cout << "����������ҵ�ѧ��������";
	cin >> iKey;

	while (low <= high)  // ���ֲ���
	{
		mid = (low + high) / 2;
		if (strcmp(iKey, m_oStu[mid].m_szName) == 0)
		{
			cout << "���ҵ���ѧ����" << endl;
			print_stu_msg(mid);
			cout << "�Ƿ�ɾ����ѧ����Ϣ��Y/N����";
			cin >> cUserChoice;
			if (cUserChoice == 'Y' || cUserChoice == 'y')
			{
				delete_stu(mid);
				return;
			}
			cout << "��Ϣδɾ����";
			cout << "��������������˵���" << endl;
			system("pause");
			break;
		}
		else if (strcmp(iKey, m_oStu[mid].m_szName) < 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << " δ�ҵ������Ϣƥ���ѧ����" << endl;
	cout << "��������������˵���" << endl;
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

	cout << "����������ҵ�ѧ��ѧ�ţ�";
	cin >> iKey;

	while (low <= high)  // ���ֲ���
	{
		mid = (low + high) / 2;
		if (iKey == m_oStu[mid].m_iStuID)
		{
			cout << "���ҵ���ѧ����" << endl;
			print_stu_msg(mid);
			cout << "�Ƿ�ɾ����ѧ����Ϣ��Y/N����";
			cin >> cUserChoice;
			if (cUserChoice == 'Y'|| cUserChoice == 'y')
			{
				delete_stu(mid);
				return;
			}
			cout << "��Ϣδɾ����";
			cout << "��������������˵���" << endl;
			system("pause");
			break;
		}
		else if (iKey < m_oStu[mid].m_iStuID)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << " δ�ҵ������Ϣƥ���ѧ����" << endl;
	cout << "��������������˵���" << endl;
	system("pause");
}

void CDormSystem::print_stu_msg()
{
	system("cls");

	if (m_iListLength <0 || m_iListLength >MAX_LIST_LENGTH)
	{
		cout << "�����ѳ������˳�����" << endl;
		return;
	}

	bubble_sort_room_ID();

	cout << " �����\t\t����\t\tѧ��" << endl;
	for (int i = 0; i < m_iListLength; i++)
	{
		cout << " " << m_oStu[i].m_iRoomID << "\t\t" << m_oStu[i].m_szName << "\t\t" << m_oStu[i].m_iStuID << endl;
	}

	cout << endl;
	cout<< " ��������������˵���" << endl;
	system("pause");

}

void CDormSystem::print_stu_msg(int site)
{
	cout << endl;
	cout << " �����\t\t����\t\tѧ��" << endl;
	cout << " " << m_oStu[site].m_iRoomID << "\t\t" << m_oStu[site].m_szName << "\t\t" << m_oStu[site].m_iStuID << endl;
	cout << endl;
}

void CDormSystem::save_stu_msg()
{
	system("cls");

	char szUserChoice;

	cout << " ********************************************" << endl;
	cout << " ***********  ѧ���������ϵͳ  *************" << endl;
	cout << " ***********       V_1.0.0      *************" << endl;
	cout << " ********************************************" << endl;
	cout << " *             ���Ҳ˵�                     *" << endl;
	cout << " *      �� �ţ�         ˵  ����            *" << endl;
	cout << " *                                          *" << endl;
	cout << " *        1             �����              *" << endl;
	cout << " *        2              ����               *" << endl;
	cout << " *        3              ѧ��               *" << endl;
	cout << " *        0           �������˵�            *" << endl;
	cout << " ********************************************" << endl;

	cout << " ���ʰ�ʲô�ؼ������򱣴棿" << endl;
	cout << " ��������ţ������Ĭ��Ϊ����ţ���";

	cin >> szUserChoice;
	cin.ignore(1024, '\n');
	cout << endl << endl;

	switch (szUserChoice)
	{
	case '1':
		cout << " ���ݽ�����������б��棡" << endl;
		bubble_sort_room_ID();
		break;
	case '2':
		cout << " ���ݽ����������б��棡" << endl;
		bubble_sort_name();
		break;
	case'3':
		cout << " ���ݽ���ѧ�����б��棡" << endl;
		bubble_sort_stu_ID();
		break;
	case'0':
		return;
	default:
		cout << " ���ݽ�����������б��棡" << endl;
		bubble_sort_room_ID();
	}

	ofstream oStuOutFile;
	oStuOutFile.open("DormSystem.dat", ios::out);

	if (!oStuOutFile.is_open())
	{
		cerr << " ���ݱ���ʧ�ܣ�" << endl;
		cout << " ��������������˵���" << endl;
		system("pause");

		return;
	}

	oStuOutFile << "�����\t\t����\t\tѧ��" << endl;
	oStuOutFile.close();

	oStuOutFile.open("DormSystem.dat", ios::out | ios::app);

	if (!oStuOutFile.is_open())
	{
		cerr << " ���ݱ���ʧ�ܣ�" << endl;
		cout << " ��������������˵���" << endl;
		system("pause");
		
		return;
	}

	for (int i = 0; i < m_iListLength; i++)
	{
		oStuOutFile << m_oStu[i].m_iRoomID << "\t\t" << m_oStu[i].m_szName << "\t\t" << m_oStu[i].m_iStuID << endl;
	}

	cout << " ���ݱ���ɹ���" << endl;

	cout << " ��������������˵���" << endl;
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