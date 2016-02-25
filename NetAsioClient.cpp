// NetAsioClient.cpp : DLL ���� ���α׷��� ���� ������ �Լ��� �����մϴ�.
//

#include "stdafx.h"
#include "NetAsioClient.h"

#include "AsioClient.h"

//
//// ������ ������ �����Դϴ�.
//NETASIOCLIENT_API int nNetAsioClient=0;
//
//// ������ �Լ��� �����Դϴ�.
//NETASIOCLIENT_API int fnNetAsioClient(void)
//{
//	return 42;
//}

// ������ Ŭ������ �������Դϴ�.
// Ŭ���� ���Ǹ� ������ NetAsioClient.h�� �����Ͻʽÿ�.
CNetAsioClient::CNetAsioClient()
{
	return;
}


struct IsSAC_ETCCheck
{
	bool operator()(const std::string &s)
	{
		const std::string ETX = "ETX";
		bool bEOF = false;

		if (s.size() > ETX.size() && s.substr(s.size() - ETX.size()) == ETX) {
			bEOF = true;
		}

		return bEOF;
	}
};


struct IsSAC_PacketCheck
{
	bool operator()(const std::string &s)
	{
		const std::string PREFIX = "SAC!@#";
		const int PACKETSIZE = 6;
		const int HEADERSIZE = PREFIX.size() + PACKETSIZE;
		
		bool bEOF = false;

		if (s.size() > HEADERSIZE) {
			if (s.substr(0, PREFIX.size()) == PREFIX) {
				std::string sLength = s.substr(PREFIX.size(), PACKETSIZE);
				int nPacketSize = std::atoi(sLength.c_str());

				if (s.length() == nPacketSize + HEADERSIZE) { bEOF = true; }
			}
		}

		return bEOF;
	}
};



NETASIOCLIENT_API int __stdcall SendPacket (
	LPCSTR strIP, LPCSTR strPort, int nTimeoutSecond, LPCSTR szMessage, LPSTR szRetMessage)
{
	int nResult = -2;

	try {
		typedef ClientSocket<> ClientSocketType;
		ClientSocketType socket;

		if (!socket.Connect(strIP, strPort)) {
			throw -1;
		}

		if (nTimeoutSecond == 0) nTimeoutSecond = 5;

		socket.Send(szMessage, nTimeoutSecond);
		int nResponse = socket.WaitForResponse();

		if (nResponse == ClientSocketType::TIMEOUT) {
			throw 0;
		}

		if (nResponse == ClientSocketType::SUCCESS) {
			std::string s = socket.GetReadBuffer();
			std::copy(s.begin(), s.end(), szRetMessage);

			nResult = s.size();
		}
	}
	catch (int nErr) {
		nResult = nErr;
	}
	catch (...) {}

	return nResult;
}


NETASIOCLIENT_API int __stdcall SendPacketSAC (
	LPCSTR strIP, LPCSTR strPort, int nTimeoutSecond, LPCSTR szMessage, LPSTR szRetMessage)
{
	int nResult = -2;

	try {
		typedef ClientSocket<IsSAC_PacketCheck> ClientSocketType;
		ClientSocketType socket;

		if (!socket.Connect(strIP, strPort)) {
			throw -1;
		}

		if (nTimeoutSecond == 0) nTimeoutSecond = 5;

		socket.Send(szMessage, nTimeoutSecond);
		int nResponse = socket.WaitForResponse();

		if (nResponse == ClientSocketType::TIMEOUT) {
			throw 0;
		}

		if (nResponse == ClientSocketType::SUCCESS) {
			std::string s = socket.GetReadBuffer();
			std::copy(s.begin(), s.end(), szRetMessage);

			nResult = s.size();
		}
	}
	catch (int nErr) {
		nResult = nErr;
	}
	catch (...) {}

	return nResult;
}

NETASIOCLIENT_API int __stdcall SendPacketSACFile (
	LPCSTR strIP, LPCSTR strPort, int nTimeoutSecond, LPCSTR szMessage, LPSTR szRetMessage)
{
	int nResult = -2;

	try {
		typedef ClientSocket<IsSAC_ETCCheck> ClientSocketType;
		ClientSocketType socket;

		if (!socket.Connect(strIP, strPort)) {
			throw -1;
		}

		if (nTimeoutSecond == 0) nTimeoutSecond = 5;

		socket.Send(szMessage, nTimeoutSecond);
		int nResponse = socket.WaitForResponse();

		if (nResponse == ClientSocketType::TIMEOUT) {
			throw 0;
		}

		if (nResponse == ClientSocketType::SUCCESS) {
			std::string s = socket.GetReadBuffer();
			std::copy(s.begin(), s.end(), szRetMessage);

			nResult = s.size();
		}
	}
	catch (int nErr) {
		nResult = nErr;
	}
	catch (...) {}

	return nResult;
}