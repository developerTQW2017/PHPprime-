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
*                     ���汣��        ����BUG
**/

/*
39��������ѯ���
������������
Ϊ���������Ա��дһ����������ѯ�����
������Ҫ��
��1�����ý���������ʽ��
��2�����������ļ���
�����ļ����ؼ��֣�������ѧ�š����ţ��������� (ð�ݡ�ѡ�񡢲����������ѡһ��)��
��3��������ѯ�˵�:
(�ö��ֲ���ʵ�����²���)
��������ѯ
��ѧ�Ų�ѯ
�����Ų�ѯ
��ӡ��һ��ѯ�������������������
*/

#include"CDormSystem.h"
#include<iostream>
using namespace std;

//  ���ܣ�ϵͳ���˵�
//  bIsRightInput������ȷ���û��Ƿ���ȷ����Ĭ��Ϊtrue����������Ϊfalse
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
			cout << " �����˳�ϵͳ������������˳���" << endl;
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

  //  ���ܣ�ϵͳ���˵�
  //  bIsRightInput������ȷ���û��Ƿ���ȷ����Ĭ��Ϊtrue����������Ϊfalse
char system_menu(bool &bIsRightInput)
{
	system("cls");   //  ����

	char cUserChoice;

	cout << " ********************************************" << endl;
	cout << " ***********  ѧ���������ϵͳ  *************" << endl;
	cout << " ***********       V_1.0.0      *************" << endl;
	cout << " ********************************************" << endl;
	cout << " *               ���˵�                     *" << endl;
	cout << " *      �� �ţ�         ��  �ܣ�            *" << endl;
	cout << " *                                          *" << endl;
	cout << " *        1         ¼���µ�ѧ����Ϣ        *" << endl;
	cout << " *        2      ���ļ�¼���µ�ѧ����Ϣ     *" << endl;
	cout << " *        3     ����ѧ������ɾ��ѧ����Ϣ��  *" << endl;
	cout << " *        4         ��ʾ����ѧ����Ϣ        *" << endl;
	cout << " *        5     ������ѧ����Ϣ���浽�ļ�    *" << endl;
	cout << " *        0            �˳�ϵͳ             *" << endl;
	cout << " *                                          *" << endl;
	cout << " ********************************************" << endl;

	if (bIsRightInput)
		cout << " ��������Ҫѡ��Ĺ�����ţ��س�ȷ�ϣ���";
	else
		cerr << " ����������������룺";

	cin >> cUserChoice;
	cin.ignore(1024, '\n');

	return cUserChoice;
}