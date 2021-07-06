#pragma once

using namespace std;

#include <string>
#include "cJSON.h"

class GroupMemberInfo
{
public:
	string  nickname;  //昵称
	string  groupBusinessCard;  //群名片
	string  activeTitle;  //活跃头衔
	string  joinedTime;  //入群时间
	string  finalSpeechTime;  //最后发言时间
	string  currentTitle;  //当前头衔
	string  permissions;  //成员权限
	string  city;  //所属城市，资料卡中的城市
	string  isFriends;  //是否好友
	string  friendsRemarks;  //好友备注,如果是好友则有效

	GroupMemberInfo();
	~GroupMemberInfo();
};

