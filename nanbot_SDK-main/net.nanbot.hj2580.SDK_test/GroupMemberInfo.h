#pragma once

using namespace std;

#include <string>
#include "cJSON.h"

class GroupMemberInfo
{
public:
	string  nickname;  //�ǳ�
	string  groupBusinessCard;  //Ⱥ��Ƭ
	string  activeTitle;  //��Ծͷ��
	string  joinedTime;  //��Ⱥʱ��
	string  finalSpeechTime;  //�����ʱ��
	string  currentTitle;  //��ǰͷ��
	string  permissions;  //��ԱȨ��
	string  city;  //�������У����Ͽ��еĳ���
	string  isFriends;  //�Ƿ����
	string  friendsRemarks;  //���ѱ�ע,����Ǻ�������Ч

	GroupMemberInfo();
	~GroupMemberInfo();
};

