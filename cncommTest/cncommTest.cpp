// cncommTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include"SerialThread.h"

#include<iostream>



using namespace std;



void main() {

	SerialThread st;

	st.ThreadInit();

	char msg[] = { "(send2:0)" };//���Ǳ����Լ���ͨѶ�ַ���ʽ


	//while (1){
		//st.SendDatas(msg);//���Ϳ����ַ�
		//55 AA 00 00 64 01 01 F4 AA 55 
		st.SendDatasPos(100, -500);//���Ϳ����ַ�
		Sleep(1000);
	//}

	st.OnReceive();//���ܻظ��ַ�

	//st.CloseSerialPort();//�رմ���

	system("pause");



}


