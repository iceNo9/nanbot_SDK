#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cassert>
#include "DEF.h"
#include "CJsonObject.hpp"
#include <windows.h>
#include <cstdio> 
#include <TCHAR.H>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring> 

using namespace std;
using json = neb::CJsonObject;


typedef const char* text;
typedef char* _text;
struct MyStruct
{

};

class NanApi
{

public:
	char tk[128];
	int nan;
	HMODULE  hdll;

	NanApi();
	~NanApi();
	void OutPut(text val);//�����־
	void SendMsg(long target, int msgType, text msg, int type = 1, bool anonymous = 0);//������Ϣ
	text nt_callFuction(text parameter);//����ר��
	long creategroup(text name);//����Ⱥ��/
	text sendCommandPacket(long obj, long num, text money, text brief, int type);//���Ϳ�����
	void SendTempMsg(long group, long qq, text content, int type);//����Ⱥ��ʱ�Ự
	text sendExclusivePacket(long group, long num, text money, text brief);//����ƴ�������
	text sendSimplePacket(long obj, long num, text money, text brief, int type,long group);//������ͨ���
	void SendVoice(int type,long target,text content,int time );//��������
	text sendSimplePacket(long obj,long num ,text money, text brief,text type);//�����������
	text sendExclusivePacket1(long group,long obj,text money,text brief );//����ר����
	text TransferAccounts(long obj,text money ,text brief);//����ת��
	text GetP_skey( );//ȡp_skey
	text GetSkey();//ȡp_skey





private:



};