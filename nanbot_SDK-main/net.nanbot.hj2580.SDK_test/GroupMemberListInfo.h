#pragma once

using namespace std;

#include <string>
#include <cstring>
#include "cJSON.h"

class GroupMemberListInfo
{
public:
	string  qq;  //QQ
	string  age;  //����
	string  nickName;  //�ǳ�
	string  businessCard;  //��Ƭ
	string  cellPhone;  //�ֻ���
	string  email;  //����
	string  notes;  //��ע
	string  activeLevel;  //��Ծ�ȼ�
	string  joinedTime;  //��Ⱥʱ��
	string  finalSpeechTime;  //�����ʱ��
	string  exclusiveTitle;  //ר��ͷ��
	string  titleExpirationTime;  //ͷ�ε���ʱ��

	GroupMemberListInfo();
	~GroupMemberListInfo();
};

