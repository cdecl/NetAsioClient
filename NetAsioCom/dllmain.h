// dllmain.h : 모듈 클래스의 선언입니다.

class CNetAsioComModule : public CAtlDllModuleT< CNetAsioComModule >
{
public :
	DECLARE_LIBID(LIBID_NetAsioComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_NETASIOCOM, "{2A0781D3-7533-4518-B7E9-83716BD4F380}")
};

extern class CNetAsioComModule _AtlModule;
