#include "socket-lib.h"
#include <iostream>

bool WinSock::Init(std::string host_name_or_ip)
{
	if (!StartUp()) return false;

	this->ht_ = GetHostByIp(host_name_or_ip);

	if (this->ht_ == nullptr)
		this->ht_ = GetHostByName(host_name_or_ip);

	return this->ht_ != nullptr;
}

bool WinSock::StartUp(void)
{
	auto err = WSAStartup(MAKEWORD(2, 0), &this->wsa_data_);

	if (err)
	{
		std::cout << "セットアップ失敗。" << std::endl;
		CheckSocketError(err);
		return false;
	}

	std::cout << "セットアップ成功。" << std::endl;

	return true;
}

void WinSock::GetHostName(void)
{
	char host_name[100];
	gethostname(host_name, 100);
	this->host_name_ = host_name;
}

HOSTENT * WinSock::GetHostByName(std::string host_name) const
{
	return gethostbyname(host_name.c_str());
}

HOSTENT * WinSock::GetHostByIp(std::string ip) const
{
	struct in_addr addr;

	addr.S_un.S_addr = inet_addr(ip.c_str());

	return gethostbyaddr((const char*)&addr.S_un.S_addr,
		sizeof(addr.S_un.S_addr), AF_INET);
}

void WinSock::CheckSocketError(int err)
{
	switch (err)
	{
	case 1:
		break;
	default:
		break;
	}
}
