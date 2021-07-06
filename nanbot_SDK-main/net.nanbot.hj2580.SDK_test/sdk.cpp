#include"sdk.h"

_text text_(int a) {
	_text str;
	sprintf(str, "%d", a);
	return str;
}

text NanApi::nt_callFuction(text parameter) {


	typedef text(*Func)(text);
	Func func;

	func = (Func)GetProcAddress(hdll, "nt_callFuction");


	if (func == NULL) {
		MessageBoxA(GetForegroundWindow(), "��̬���ӿ�ָ������\"nt_callFuction\"������", "��ʾ", 0);
		return"";


	}

	return func(parameter);
}

NanApi::NanApi()
{

	hdll = LoadLibrary("ntapi.dll");
	if (hdll == NULL)
	{
		MessageBoxA(GetForegroundWindow(), "Ŀ�궯̬���ӿ����ʧ�ܡ�ntapi.dll��", "��ʾ", 0);

	}
}

NanApi::~NanApi()
{

	FreeLibrary(hdll);
}

void NanApi::OutPut(text val) {

	json j;

	j.Add("func", "OutPut");
	j.Add("tk", tk);
	j.Add("val", val);
	string s = j.ToString();
	//MessageBoxA(GetForegroundWindow(), s.c_str(), "��ʾ", 0);

	nt_callFuction(s.c_str());
}

/*
target��Ҫ���͵�Ⱥ��
msgtype����Ϣ���ͣ���Ϣ��ʽ_��ͨ = 1����Ϣ��ʽ_xml = 2����Ϣ��ʽ_json =	3��
msg��Ҫ���͵���Ϣ
type��
anonymous��
*/
void NanApi::SendMsg(string target, int msgType, string msg, int type, bool anonymous)
{
	try
	{
		json j;

		j.Add("func", "SendMsg");
		j.Add("tk", tk);
		j.Add("type", type);
		j.Add("msgType", msgType);
		j.Add("target", target);
		j.Add("content", msg);
		j.Add("anonymous", anonymous);
		string s = j.ToString();
		//MessageBoxA(GetForegroundWindow(), s.c_str(), "��ʾ", 0);
		nt_callFuction(s.c_str());

	}
	catch (const std::exception&)
	{

	}


}

long NanApi::creategroup(text name) {

	json j;

	j.Add("func", "CreateGroup");
	j.Add("tk", tk);
	j.Add("gn", name);
	string s = j.ToString();
	return stoi(nt_callFuction(s.c_str()));

	//return (long)nt_callFuction()
}

text NanApi::sendCommandPacket(long obj, long num, text money, text brief, int type) {
	json j;

	j.Add("func", "sendSimplePacket");
	j.Add("tk", tk);
	j.Add("obj", obj);
	j.Add("num", num);
	j.Add("money", money);
	j.Add("brief", brief);
	j.Add("type", type);



	string s = j.ToString();
	return nt_callFuction(s.c_str());

}

void NanApi::SendTempMsg(long group, long qq, text content, int type) {

	json j;
	j.Add("func", "SendTempMsg");
	j.Add("tk", tk);
	j.Add("group", group);
	j.Add("qq", qq);
	j.Add("content", content);
	j.Add("type", type);
	string s = j.ToString();
	nt_callFuction(s.c_str());
	return ;
}

text NanApi::sendExclusivePacket(long group, long num, text money, text brief) {

	json j;

	j.Add("func", "sendExclusivePacket");
	j.Add("tk", tk);
	j.Add("group", group);
	j.Add("num", num);
	j.Add("money", money);
	j.Add("brief", brief);
	string s = j.ToString();
	return nt_callFuction(s.c_str());

}

text NanApi::sendSimplePacket(long obj, long num, text money, text brief, int type,long group){
	json j;

	j.Add("func", "sendSimplePacket");
	j.Add("tk", tk);
	j.Add("obj", obj);
	j.Add("num", num);
	j.Add("money", money);
	j.Add("brief", brief);
	j.Add("type", type);
	j.Add("group", group);


	string s = j.ToString();
	return nt_callFuction(s.c_str());

	/*

' �⼸��Ǯ�������ķ��ؽ����������������xxxxxxxxxxxxxxx����Ϊ�ֶ�������:)

' {"retcode":"0","retmsg":"success","bargainor_id":"1000026901","callback_url":"https%3A%2F%2Fmqq.tenpay.com%2Fv2%2Fhybrid%2Fwww%2Fmobile_qq%2Fpayment%2Fpay_result.shtml%3F_wv%3D1027%26channel%3D2","pay_flag":"1","pay_time":"2021-01-28 18:18:31","real_fee":"1","sp_billno":"1010000269015021012xxxxxxxxxxxxx","sp_data":"attach%3DCgQKABABElEQ8YnZCBoMU0FP5Li2S2lyaXRvIJeVlyYqBOaziS4wATgBQABIAVAAWg4xODIuMTMxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx%26bank_billno%3D%26bank_type%3DCFT%26bargainor_id%3D1000026901%26charset%3D2%26fee_type%3D1%26pay_result%3D0%26purchase_alias%3D400988517%26sign%3DCF04B547759E925CF1BD4771xxxxxxxx%26sp_billno%3D101000026901502xxxxxxxxxxxxxxxxxxx%26time_end%3D20210128181831%26total_fee%3D1%26transaction_id%3D100002690121012800047xxxxxxxxxxxxxxxxxxx%26ver%3D2.0","transaction_id":"100002690121012800047311615xxxxxxxxxxxxxxxxxxx","send_flag":"0"}
*/
}

void NanApi::SendVoice ( int type , long target , text content , int time ) {

		json j;
		j.Add ( "func" , "SendVoice" );
		j.Add ( "tk" ,tk );
		j.Add ( "type" , type );
		j.Add ("target" , target );
		j.Add ( "content" , content  );
		j.Add ( "time" , time);

		string s = j.ToString ( );
		nt_callFuction ( s.c_str ( ) );


}

text NanApi::sendSimplePacket ( long obj , long num , text money , text brief , text type ) {


	json j;
	j.Add ( "func" , "sendVoicePacket ");
	
	j.Add ( "tk" , tk );
	j.Add ( "obj" , obj );
	j.Add ( "num" , num );
	j.Add ( "money" , money );
	j.Add ( "brief" , brief );
	j.Add ( "type" , type );
	string s = j.ToString ( );
	return	nt_callFuction ( s.c_str ( ) );

}

text NanApi::sendExclusivePacket1 ( long group , long obj , text money , text brief ){
	json j;

	j.Add ( "func" ,"sendExclusivePacket"  );

	j.Add ( "tk" , tk );
	j.Add ( "group" , group );
	j.Add ( "obj" , obj );
	j.Add ( "num" , 1 );
	j.Add ( "money" , money );
	j.Add ( "brief" , brief );
	string s = j.ToString ( );
	return nt_callFuction ( s.c_str ( ) );

}

text NanApi::TransferAccounts ( long obj , text money , text brief ) {

	json j;
	j.Add ( "func" , "TransferAccounts"  );
	j.Add ( "tk" , tk );
	j.Add ( "obj" , obj );
	j.Add ( "money" , money );
	j.Add ( "brief" , brief );
	string s = j.ToString ( );
	return nt_callFuction ( s.c_str ( ) );

}

text NanApi::GetP_skey ( ) {

	json j;
	j.Add ( "func" ,"GetP_skey" );
	j.Add ( "tk" , tk );
	string s = j.ToString ( );
	return nt_callFuction ( s.c_str ( ) );
}

text NanApi::GetSkey ( ) {

	json j;
	j.Add ( "func" ,"GetSkey" );
	j.Add ( "tk" , tk );
	string s = j.ToString ( );
	return nt_callFuction ( s.c_str ( ) );

}

void NanApi::SetExclusiveTitle(string groupNumber, string qq, string title)
{
	json j;
	string result;
	string s;

	j.Add("func", "SetMemberTitle");
	j.Add("tk", tk);
	j.Add("group", stoull(groupNumber));
	j.Add("qq", stoull(qq));
	j.Add("title", title.c_str());

	s = j.ToString();

	OutPut(s.c_str());
	result = nt_callFuction(s.c_str());

	return;
}

GroupMemberInfo NanApi::GetGroupMemberInformation(string groupNumber, string qq)
{
	GroupMemberInfo temp;
	json j;
	string result;
	string s;


	j.Add("func", "GetGroupMemberInfo");
	j.Add("tk", tk);
	j.Add("group", stoull(groupNumber));
	j.Add("qq", stoull(qq));

	s = j.ToString();
	result = nt_callFuction(s.c_str());

	j.Clear();
	j.Parse(result);

	j.Get("nick", temp.nickname);
	j.Get("card", temp.groupBusinessCard);
	j.Get("activeTag", temp.activeTitle);
	j.Get("joinTime", temp.joinedTime);
	j.Get("speakTime", temp.finalSpeechTime);
	j.Get("nowTag", temp.currentTitle);
	j.Get("auth", temp.permissions);
	j.Get("city", temp.city);
	j.Get("isFriend", temp.isFriends);
	j.Get("remarks", temp.friendsRemarks);

	return temp;
}

list<GroupMemberListInfo> NanApi::GetGroutMemberListInformation(string groupNumber)
{
	list<GroupMemberListInfo> retVal;
	json j;
	string result;
	string s;
	int i;
	string log;


	j.Add("func", "GetGroupMemberList");
	j.Add("group", stoull(groupNumber));
	j.Add("tk", tk);

	s = j.ToString();
	result = nt_callFuction(s.c_str());

	j.Clear();
	j.Parse(result);

	log = "ȡȺ��Ա�б�����json�ĳ�Ա����ѭ���յ㣺" + to_string(j["list"].GetArraySize());
	OutPut(log.c_str());

	log = "ȡȺ��Ա�б�����json�ĳ�Ա����ѭ���յ㣺" + j.ToString();
	OutPut(log.c_str());

	for (i = 0; i < 5/*j["list"].GetArraySize()*/; i++)
	{
		GroupMemberListInfo temp;

		/*j.Get(j["list"][i]("qq"), temp.qq);
		j.Get(j["list"][i]("age"), temp.age);
		j.Get(j["list"][i]("nick"), temp.nickName);*/
		j["list"][i].Get("nick",temp.nickName);

		//temp.nickName = j["list"][i]("nick");
		//log = to_string(i) + "   " + j["list"][i]("card");
		//OutPut(log.c_str());
		/*j.Get(j["list"][i]("phone"), temp.cellPhone);
		j.Get(j["list"][i]("mail"), temp.email);
		j.Get(j["list"][i]("remarks"), temp.notes);
		j.Get(j["list"][i]("dwMemberLevel"), temp.activeLevel);
		j.Get(j["list"][i]("joinTime"), temp.joinedTime);
		j.Get(j["list"][i]("speakTime"), temp.finalSpeechTime);
		j.Get(j["list"][i]("title"), temp.exclusiveTitle);
		j.Get(j["list"][i]("titleTime"), temp.titleExpirationTime);*/
		
		retVal.emplace_back(temp);
	}

	return retVal;
}
