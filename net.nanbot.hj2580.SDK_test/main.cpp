
#include"sdk.h"


NanApi nt;


json msg_json;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//���������Ϣ�����޸Ĵ��ӳ�����ز������˴��벻Ҫ�����κζ������ ���ӳ�������ɾ��
text _stdcall GenerateInfo() {

	


	
	json json;
	json.AddEmptySubObject("info");
	json["info"].Add("name","����");//�������

	json["info"].Add("author","test");//�������

	json["info"].Add("verindex","1.0");//����ڲ��汾

	json["info"].Add("vername","1.0");//�����ʾ�汾

	json["info"].Add("id","net.nanbot.hj2580.SDK_test");//���ID
	//����ļ��������� ���ID.nt.dll �����������������ӵ��ļ�����ӦΪ net.nanbot.hj2580.SDK_test.nt.dll

	json["info"].Add("url","");// ������HTTP��ַ�����û��������ϵ���ߡ������ת���õ�ַ 
	//������δ���ã�����ϵ����

	json["info"].Add("describe","����һ�����Բ��");
	// ֧��HTML�Ͷ���
	json["info"].Add("priority",NanBot_���ȼ�_����);
	 
	json["info"].Add("bg","");
// ��ʾ�ı���ͼƬ�ļ��������ڳ�ʼ���н�����ͼƬд�� ��\webui\imgs\���ļ����У��硰net.nanbot.test.jpg��
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

//����������Լ��������ע�ᣬ�벻Ҫ�Ա��ӳ�������޸ģ�Ҳ�벻Ҫ�ٴ˷����κ��������
int _stdcall AuthCode(char* Token,int ErrPtr) {
	
	strcpy(nt.tk, Token);


	return 1;
}

	//����Լ��������¼�
int _stdcall Event_Frame(int type, text parameter, int error) {

	nt.OutPut(parameter);


	return 1;
}

//��������¼�
int _stdcall Event_Friend(int type, text parameter) {
	
	//nt.SendMsg()
	return 1;
}

//Ⱥ����¼�
int _stdcall Event_Group(int type, text parameter) {

	try//���쳣��������¿�ܱ���
	{
		switch (type)
		{
		case �¼�_Ⱥ_�ı���Ϣ: {
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
				if ( !strcmp ( "�������" , msg.c_str ( ) ) )
				{
				nt.OutPut(nt.sendExclusivePacket(stoi(group.c_str()),1,"0.01" ,"��ĺ������"));
				}


			}


			break; }
		case �¼�_Ⱥ_ĳ�˳�����Ϣ: {
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
				os << "QQ��:" << qq.c_str() << "\n�ղų�����һ����Ϣ:\n" << msg.c_str();
				mag = os.str();
				nt.SendMsg(stoi(group.c_str()), ��Ϣ��ʽ_��ͨ, mag.c_str(), 2, 0);
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
	//MessageBoxA(GetForegroundWindow(), mm.c_str(), "��ʾ", 0);
	//nt.OutPut(mm.c_str());
	
	return 1;
}

//���ں�����¼�
int _stdcall Event_Public(int type, text parameter) {
	
	return 1;
}

//��֤��Ϣ����¼�
int _stdcall Event_Verify(int type, text parameter) {
	
	return 1;
}

//��ʱ�Ự����¼�
int _stdcall Event_Provisional(int type, text parameter) {
	
	return 1;
}

//�����¼�
int _stdcall Event_Other(int type, text parameter) {
	
	return 1;
}

//���ж��/��ܹر��¼�  ���ӳ�������ɾ��
void _stdcall PluiginDump() {
	
//��������ر����򿪵�һ����Դ�ʹ������߳�
//������������һ���Դ����Ĵ���
//��������κ���Դ������ж�ز�������������ܱ���
	nt.OutPut("���ж��");

}
