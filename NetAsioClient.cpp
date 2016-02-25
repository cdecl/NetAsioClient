// NetAsioClient.cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "stdafx.h"
#include "NetAsioClient.h"

#include "AsioClient.h"

//
//// 내보낸 변수의 예제입니다.
//NETASIOCLIENT_API int nNetAsioClient=0;
//
//// 내보낸 함수의 예제입니다.
//NETASIOCLIENT_API int fnNetAsioClient(void)
//{
//	return 42;
//}

// 내보낸 클래스의 생성자입니다.
// 클래스 정의를 보려면 NetAsioClient.h를 참조하십시오.
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