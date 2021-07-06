#pragma once

using namespace std;

#include <string>
#include <cstring>
#include "cJSON.h"

class GroupMemberListInfo
{
public:
	string  qq;  //QQ
	string  age;  //年龄
	string  nickName;  //昵称
	string  businessCard;  //名片
	string  cellPhone;  //手机号
	string  email;  //邮箱
	string  notes;  //备注
	string  activeLevel;  //活跃等级
	string  joinedTime;  //进群时间
	string  finalSpeechTime;  //最后发言时间
	string  exclusiveTitle;  //专属头衔
	string  titleExpirationTime;  //头衔到期时间

	GroupMemberListInfo();
	~GroupMemberListInfo();
};

