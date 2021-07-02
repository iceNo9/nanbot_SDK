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
	void OutPut(text val);//输出日志
	void SendMsg(long target, int msgType, text msg, int type = 1, bool anonymous = 0);//发送消息
	text nt_callFuction(text parameter);//互交专用
	long creategroup(text name);//创建群聊/
	text sendCommandPacket(long obj, long num, text money, text brief, int type);//发送口令红包
	void SendTempMsg(long group, long qq, text content, int type);//发送群临时会话
	text sendExclusivePacket(long group, long num, text money, text brief);//发送拼手气红包
	text sendSimplePacket(long obj, long num, text money, text brief, int type,long group);//发送普通红包
	void SendVoice(int type,long target,text content,int time );//发送语音
	text sendSimplePacket(long obj,long num ,text money, text brief,text type);//发送语音红包
	text sendExclusivePacket1(long group,long obj,text money,text brief );//发送专享红包
	text TransferAccounts(long obj,text money ,text brief);//发送转账
	text GetP_skey( );//取p_skey
	text GetSkey();//取p_skey





private:



};