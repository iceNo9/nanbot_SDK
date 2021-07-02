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
		MessageBoxA(GetForegroundWindow(), "动态链接库指定命令\"nt_callFuction\"不存在", "提示", 0);
		return"";


	}

	return func(parameter);
}

NanApi::NanApi()
{

	hdll = LoadLibrary("ntapi.dll");
	if (hdll == NULL)
	{
		MessageBoxA(GetForegroundWindow(), "目标动态链接库加载失败“ntapi.dll”", "提示", 0);

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
	//MessageBoxA(GetForegroundWindow(), s.c_str(), "提示", 0);

	nt_callFuction(s.c_str());
}

void NanApi::SendMsg(long target, int msgType, text msg, int type, bool anonymous)
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
		//MessageBoxA(GetForegroundWindow(), s.c_str(), "提示", 0);
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

' 这几个钱包操作的返回结果都是这样，其中xxxxxxxxxxxxxxx部分为手动马赛克:)

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