
//SRIALTHREAD_H   头文件标识，避免重复定义，

//和头文件无直接关系，可以随便定义，但一般是文件名的大写

#ifndef SRIALTHREAD_H

#define SRIALTHREAD_H





#include"CnComm.h"  

class SerialThread : public CnComm
{
public:

	SerialThread();//构建函数，可以为空             

	virtual ~SerialThread();//解析函数，可以为空

	void ThreadInit();//打开串口

	void CloseSerialPort(); //关闭串口 

	void SendDatas(char *msg);//发送数据  

	void OnReceive();  //接收数据  

	char sendbuf[10];

	void SendDatasPos(int x, int y);//发送数据  

private:

	CnComm Com;//实例化CnComm类

	//备用函数，不是必须的

	int Ascii2Hex(char* ascii, char* hex);   //ascii转十六进制  

	int Hex2Ascii(char* hex, char* ascii);  //十六进制转ascii  

};



#endif
