
//SRIALTHREAD_H   ͷ�ļ���ʶ�������ظ����壬

//��ͷ�ļ���ֱ�ӹ�ϵ��������㶨�壬��һ�����ļ����Ĵ�д

#ifndef SRIALTHREAD_H

#define SRIALTHREAD_H





#include"CnComm.h"  

class SerialThread : public CnComm
{
public:

	SerialThread();//��������������Ϊ��             

	virtual ~SerialThread();//��������������Ϊ��

	void ThreadInit();//�򿪴���

	void CloseSerialPort(); //�رմ��� 

	void SendDatas(char *msg);//��������  

	void OnReceive();  //��������  

	char sendbuf[10];

	void SendDatasPos(int x, int y);//��������  

private:

	CnComm Com;//ʵ����CnComm��

	//���ú��������Ǳ����

	int Ascii2Hex(char* ascii, char* hex);   //asciiתʮ������  

	int Hex2Ascii(char* hex, char* ascii);  //ʮ������תascii  

};



#endif
