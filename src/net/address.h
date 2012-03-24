#ifndef __NET_ADDRESS_H__
#define __NET_ADDRESS_H__
/********************************************************************
* File: net/address.h                          Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

#include <netinet/in.h>

namespace net {

class address4
{
public:
	static address4 any;
	static address4 none;
	static address4 loopback;

	address4();
	address4(const in_addr_t addr);
	address4(const in_addr &addr);
	address4(const address4 &addr);

	const in_addr &get() const;
	const std::string str() const;

	address4 &operator=(const in_addr_t addr);
	address4 &operator=(const in_addr &addr);
	address4 &operator=(const address4 &addr);

private:
	in_addr m_addr;  // The actual address
};

typedef address4 address;

}  // namespace net

#endif // __NET_ADDRESS_H__
