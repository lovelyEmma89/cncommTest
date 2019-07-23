// cncommTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include"SerialThread.h"

#include<iostream>



using namespace std;



void main() {

	SerialThread st;

	st.ThreadInit();

	char msg[] = { "(send2:0)" };//这是笔者自己的通讯字符格式


	//while (1){
		//st.SendDatas(msg);//发送控制字符
		//55 AA 00 00 64 01 01 F4 AA 55 
		st.SendDatasPos(100, -500);//发送控制字符
		Sleep(1000);
	//}

	st.OnReceive();//接受回复字符

	//st.CloseSerialPort();//关闭串口

	system("pause");



}


