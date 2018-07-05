#pragma once

#pragma warning(disable: 4996)

#include <WinSock2.h>

#include <iostream>
#include <memory>
#include <string>

#pragma comment(lib, "ws2_32.lib")

class WinSock
{
private:
	WSADATA wsa_data_;
	std::string host_name_;
	HOSTENT * ht_;

public:
	bool Init(std::string host_name);
	void ShowIP(void)
	{
		struct in_addr addr;

		std::cout << this->ht_->h_name << std::endl;

		if (this->ht_->h_addr_list)
		{
			for (int n = 0; this->ht_->h_addr_list[n]; n++)
			{
				addr.S_un.S_addr = *(u_long*)this->ht_->h_addr_list[n];
				std::cout << inet_ntoa(addr) << std::endl;
			}
		}
	}

private:
	bool StartUp(void);

	void GetHostName(void);

	HOSTENT * GetHostByName(std::string host_name) const;
	HOSTENT * GetHostByIp(std::string ip) const;
private:
	void CheckSocketError(int err);
};