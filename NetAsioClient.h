// ���� ifdef ����� DLL���� ���������ϴ� �۾��� ���� �� �ִ� ��ũ�θ� ����� 
// ǥ�� ����Դϴ�. �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� _EXPORTS ��ȣ��
// �����ϵǸ�, ������ DLL�� ����ϴ� �ٸ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
// �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ��� �ִ� �ٸ� ��� ������Ʈ������ 
// NETASIOCLIENT_API �Լ��� DLL���� �������� ������ ����, �� DLL��
// �� DLL�� �ش� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ���ϴ�.
#ifdef NETASIOCLIENT_EXPORTS
#define NETASIOCLIENT_API __declspec(dllexport)
#else
#define NETASIOCLIENT_API __declspec(dllimport)
#endif

// �� Ŭ������ NetAsioClient.dll���� ������ ���Դϴ�.
class NETASIOCLIENT_API CNetAsioClient {
public:
	CNetAsioClient(void);
	// TODO: ���⿡ �޼��带 �߰��մϴ�.
};

//extern NETASIOCLIENT_API int nNetAsioClient;
//
//NETASIOCLIENT_API int fnNetAsioClient(void);


NETASIOCLIENT_API int __stdcall SendPacket (LPCSTR strIP, LPCSTR strPort, int nTimeoutSecond, LPCSTR szMessage, LPSTR szRetMessage);
NETASIOCLIENT_API int __stdcall SendPacketSAC (LPCSTR strIP, LPCSTR strPort, int nTimeoutSecond, LPCSTR szMessage, LPSTR szRetMessage);
NETASIOCLIENT_API int __stdcall SendPacketSACFile (LPCSTR strIP, LPCSTR strPort, int nTimeoutSecond, LPCSTR szMessage, LPSTR szRetMessage);




