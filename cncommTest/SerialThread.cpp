
#include "SerialThread.h"  
#include <iostream>  

using namespace std;





SerialThread::SerialThread()

{

}



SerialThread::~SerialThread()

{



}



void SerialThread::ThreadInit()

{
	char port[] = "COM5";
	char portname[8];
	if (!Com.IsOpen())
	{
		//CnComm::Open函数就是用来打开串口
     	//bool Open(DWORD dwPort, LPCTSTR szPortName, DWORD dwBaudRate, BYTE btParity = NOPARITY, BYTE btByteSize = 8, BYTE btStopBits = ONESTOPBIT)
		//dwPort，szPortName可以在“计算机管理->设备管理器->端口（COM和LPT）->双击设备名：位置”
		for (int i = 0; i < 10; i++){
			sprintf(portname, "COM%d", i);
			if (!Com.Open(7, portname, 115200))//
			{
				cout << portname << " open fail!" << endl;
			}
			else{
				cout << portname << " open success!" << endl;
				break;
			}
		}
	}
	else {
		cout << "already open" << endl;
	}
}



void SerialThread::CloseSerialPort()

{

	Com.Close();//关闭串口

	cout << "Close Successfully!" << endl;

}



void SerialThread::SendDatas(char *msg)

{
	if (Com.IsOpen())
	{
		cout << msg << endl;
		Com.Write(msg);//写入字符串，实现控制
	}
}

void SerialThread::SendDatasPos(int x, int y){

	if (!Com.IsOpen()){
		return;
	}
	sendbuf[0] = 0x55;
	sendbuf[1] = 0xAA;
	if (x < 0){
		sendbuf[2] = 0x01;
	}
	else{
		sendbuf[2] = 0x00;
	}
	x = abs(x);
	sendbuf[3] = (x >> 8) & 0xFF;//高八位
	sendbuf[4] = x & 0xFF;//第八位

	if (y < 0){
		sendbuf[5] = 0x01;
	}
	else{
		sendbuf[5] = 0x00;
	}
	y = abs(y);
	sendbuf[6] = (y >> 8) & 0xFF;//高八位
	sendbuf[7] = y & 0xFF;//第八位

	sendbuf[8] = 0xAA;
	sendbuf[9] = 0x55;

	Com.Write(sendbuf,10);//写入字符串，实现控制

}


void  SerialThread::OnReceive()

{

	do {

		char buffer[1024];

		int len = Com.Read(buffer, 1023);//接受字符串

		buffer[len] = _T('\0');

		cout << buffer << endl;

	} while (Com.IsRxBufferMode() && Com.Input().SafeSize());



}



int SerialThread::Ascii2Hex(char* ascii, char* hex)

{

	int i, len = strlen(ascii);

	char chHex[] = "0123456789ABCDEF";



	for (i = 0; i < len; i++)

	{

		hex[i * 3] = chHex[((BYTE)ascii[i]) >> 4];

		hex[i * 3 + 1] = chHex[((BYTE)ascii[i]) & 0xf];

		hex[i * 3 + 2] = ' ';

	}



	hex[len * 3] = '\0';



	return len * 3;

}



int SerialThread::Hex2Ascii(char* hex, char* ascii)

{

	int len = strlen(hex), tlen, i, cnt;



	for (i = 0, cnt = 0, tlen = 0; i < len; i++)

	{

		char c = toupper(hex[i]);



		if ((c >= '0'&& c <= '9') || (c >= 'A'&& c <= 'F'))

		{

			BYTE t = (c >= 'A') ? c - 'A' + 10 : c - '0';



			if (cnt)

				ascii[tlen++] += t, cnt = 0;

			else

				ascii[tlen] = t << 4, cnt = 1;

		}

	}



	return tlen;

}
