/ SocketClient.cpp : CSocketClient의 구현입니다.

#include "stdafx.h"
#include "SocketClient.h"


#pragma comment(lib, "NetAsioClient.lib")
int __stdcall SendPacket (LPCSTR strIP, LPCSTR strPort, int nTimeoutSecond, LPCSTR szMessage, LPSTR szRetMessage);




// CSocketClient

HRESULT CSocketClient::Activate()
{
	HRESULT hr = GetObjectContext(&m_spObjectContext);
	if (SUCCEEDED(hr))
		return S_OK;
	return hr;
} 

BOOL CSocketClient::CanBePooled()
{
	return FALSE;
} 

void CSocketClient::Deactivate()
{
	m_spObjectContext.Release();
} 


STDMETHODIMP CSocketClient::SendPacket(BSTR bstrIP, BSTR bstrPort, long lTimeoutSecond, BSTR bstrMessage, VARIANT * varRetMessage, VARIANT * pReturn)
{
	int nRecv = -1;
	enum { RECV_BUUF = 1024 * 8 };
	char szBuff[RECV_BUUF + 1] = {0, };

	try {
		nRecv = ::SendPacket(
					(LPCSTR)(_bstr_t)bstrIP, (LPCSTR)(_bstr_t)bstrPort, lTimeoutSecond, 
					(LPCSTR)(_bstr_t)bstrMessage, szBuff
				);

		if (nRecv > 0) { 
			szBuff[nRecv] = NULL;
		}

		*varRetMessage = _variant_t(szBuff).Detach();
	}
	catch (...) {
		*varRetMessage = _variant_t("").Detach();
	}

	*pReturn = _variant_t((long)nRecv).Detach();
	if (m_spObjectContext) m_spObjectContext->SetComplete(); 


	return S_OK;
}
