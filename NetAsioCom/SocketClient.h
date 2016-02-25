// SocketClient.h : CSocketClient의 선언입니다.

#pragma once
#include "NetAsioCom_i.h"
#include "resource.h"       // 주 기호입니다.
#include <comsvcs.h>



// CSocketClient

class ATL_NO_VTABLE CSocketClient :
	public CComObjectRootEx<CComMultiThreadModel>,
	public IObjectControl,
	public CComCoClass<CSocketClient, &CLSID_SocketClient>,
	public IDispatchImpl<ISocketClient, &IID_ISocketClient, &LIBID_NetAsioComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSocketClient()
	{
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SOCKETCLIENT)

BEGIN_COM_MAP(CSocketClient)
	COM_INTERFACE_ENTRY(ISocketClient)
	COM_INTERFACE_ENTRY(IObjectControl)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



// IObjectControl
public:
	STDMETHOD(Activate)();
	STDMETHOD_(BOOL, CanBePooled)();
	STDMETHOD_(void, Deactivate)();

	CComPtr<IObjectContext> m_spObjectContext;


// ISocketClient
public:
	STDMETHOD(SendPacket)(BSTR bstrIP, BSTR bstrPort, long lTimeoutSecond, BSTR bstrMessage, VARIANT * varRetMessage, VARIANT * pReturn);
};

OBJECT_ENTRY_AUTO(__uuidof(SocketClient), CSocketClient)
