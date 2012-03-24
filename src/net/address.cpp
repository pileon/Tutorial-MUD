/********************************************************************
* File: net/address.cpp                        Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

#include <arpa/inet.h>
#include <string>

#include "address.h"

namespace net {

address4 address4::any      = INADDR_ANY;
address4 address4::none     = INADDR_NONE;
address4 address4::loopback = INADDR_LOOPBACK;

address4::address4()
{
}

address4::address4(const in_addr_t addr)
{
	m_addr.s_addr = addr;
}

address4::address4(const in_addr &addr)
	: m_addr(addr)
{
}

address4::address4(const address4 &addr)
	: m_addr(addr.m_addr)
{
}

const in_addr &address4::get() const
{
	return m_addr;
}

const std::string address4::str() const
{
	char addr_buffer[INET_ADDRSTRLEN];
	const char *ret = inet_ntop(AF_INET, &m_addr,
				    addr_buffer, sizeof(addr_buffer));
	return (ret ? ret : "");
}

address4 &address4::operator=(const in_addr_t addr)
{
	m_addr.s_addr = addr;
	return *this;
}

address4 &address4::operator=(const in_addr &addr)
{
	m_addr = addr;
	return *this;
}

address4 &address4::operator=(const address4 &addr)
{
	m_addr = addr.m_addr;
	return *this;
}

}  // namespace net
