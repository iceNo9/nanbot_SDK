
#include"sdk.h"


NanApi nt;


json msg_json;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//建立插件信息，请修改此子程序相关参数，此处请不要放置任何多余代码 此子程序请勿删除
text _stdcall GenerateInfo() {

	


	
	json json;
	json.AddEmptySubObject("info");
	json["info"].Add("name","测试");//插件名称

	json["info"].Add("author","test");//插件作者

	json["info"].Add("verindex","1.0");//插件内部版本

	json["info"].Add("vername","1.0");//插件显示版本

	json["info"].Add("id","net.nanbot.hj2580.SDK_test");//插件ID
	//插件文件名必须以 插件ID.nt.dll 进行命名，以上例子的文件名就应为 net.nanbot.hj2580.SDK_test.nt.dll

	json["info"].Add("url","");// 请输入HTTP地址，当用户点击“联系作者”后会跳转到该地址 
	//此项尚未启用，填不填关系不大

	json["info"].Add("describe","这是一个测试插件");
	// 支持HTML和多行
	json["info"].Add("priority",NanBot_优先级_正常);
	 
	json["info"].Add("bg","");
// 显示的背景图片文件名，请在初始化中将背景图片写到 “\webui\imgs\”文件夹中；如“net.nanbot.test.jpg”
	json.AddEmptySubObject("sdk");
	json["sdk"].Add("ver",1);

	


	json.AddEmptySubObject("event");
	json["event"]		.Add("group", true);
	json["event"]		.Add("frame",true);
	json["event"]		.Add("verify",true);
	json["event"]		.Add("friend",true);
	json["event"]		.Add("provisional",true);
	json["event"]		.Add("other",true);
	json["event"]		.Add("public",true);
	
	json.AddEmptySubObject("auth");
	json["auth"] 	.Add("group",true);
	json["auth"]	.Add("message",true);
	json["auth"]	.Add("baseinfo",true);
	json["auth"]	.Add("maininfo",true);
	json["auth"]	.Add("frame",true);
	json["auth"]	.Add("verify",true);
	json["auth"]	.Add("robot",true);
	json["auth"]	.Add("wallet",true);
	
	
	string str;
	str = json.ToString();

	nt.OutPut( str.c_str ( ) );
	return str.c_str();
	
	
}

//接收身份码以及错误管理注册，请不要对本子程序进行修改，也请不要再此放置任何其余代码
int _stdcall AuthCode(char* Token,int ErrPtr) {
	
	strcpy(nt.tk, Token);


	return 1;
}

	//框架以及插件相关事件
int _stdcall Event_Frame(int type, text parameter, int error) {

	nt.OutPut(parameter);


	return 1;
}

//好友相关事件
int _stdcall Event_Friend(int type, text parameter) {
	
	//nt.SendMsg()
	return 1;
}

//群相关事件
int _stdcall Event_Group(int type, text parameter) {

	try//抛异常以免出错导致框架崩溃
	{
		switch (type)
		{
		case 事件_群_文本消息: {
			json j;
			j.Parse(parameter);
			string qq = j("qq");
			string group = j("group");
			string msgId = j("msgId");
			string msgNo = j("msgNo");
			string msg = j("msg");
			msg_json.AddEmptySubObject(group);
			msg_json[group].AddEmptySubObject(qq);
			msg_json[group][qq].AddEmptySubObject(msgId);
			msg_json[group][qq][msgId].Add(msgNo, msg);
			if ( !strcmp ( "1806694738" , qq.c_str ( ) ) ) {
				if ( !strcmp ( "来个红包" , msg.c_str ( ) ) )
				{
				nt.OutPut(nt.sendExclusivePacket(stoi(group.c_str()),1,"0.01" ,"你的红包来了"));
				}


			}


			break; }
		case 事件_群_某人撤回消息: {
			json j;
			j.Parse(parameter);
			string trig = j("trig");
			string group = j("group");
			string msgId = j["msg"]("id");
			string msgNo = j["msg"]("no");
			string qq = j["msg"]("sender");
			if (!strcmp(trig.c_str(), qq.c_str())) {
				string mag;
				string msg = msg_json[group][qq][msgId](msgNo);

				std::ostringstream os;
				os << "QQ号:" << qq.c_str() << "\n刚才撤回了一条消息:\n" << msg.c_str();
				mag = os.str();
				nt.SendMsg(stoi(group.c_str()), 消息格式_普通, mag.c_str(), 2, 0);
			}
		}
		default:
			break;
		}
	}
	catch (const std::exception&)
	{

	}


	//string mm = msg_json.ToFormattedString();
	//MessageBoxA(GetForegroundWindow(), mm.c_str(), "提示", 0);
	//nt.OutPut(mm.c_str());
	
	return 1;
}

//公众号相关事件
int _stdcall Event_Public(int type, text parameter) {
	
	return 1;
}

//验证消息相关事件
int _stdcall Event_Verify(int type, text parameter) {
	
	return 1;
}

//临时会话相关事件
int _stdcall Event_Provisional(int type, text parameter) {
	
	return 1;
}

//其他事件
int _stdcall Event_Other(int type, text parameter) {
	
	return 1;
}

//插件卸载/框架关闭事件  此子程序请勿删除
void _stdcall PluiginDump() {
	
//请在这里关闭所打开的一切资源和创建的线程
//请在这里销毁一切以创建的窗口
//请勿残留任何资源，避免卸载操作引起整个框架崩溃
	nt.OutPut("插件卸载");

}
