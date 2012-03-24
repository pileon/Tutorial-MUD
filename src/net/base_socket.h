#ifndef __NET_BASE_SOCKET_H__
#define __NET_BASE_SOCKET_H__
/********************************************************************
* File: net/base_socket.h                      Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

namespace net {

class base_socket
{
public:
	typedef int socket_type;

	virtual ~base_socket()
		{
			if (is_open())
				close();
		}

	const socket_type &get() const
		{ return m_socket; }

	bool is_open() const
		{ return m_is_open; }

	void close()
		{
			close(m_socket);
			m_is_open = false;
		}

	void set_blocking(const bool blocking)
		{
			int flags;
			flags = fcntl(m_socket, F_GETFL, 0);
			if (blocking)
				flags &= ~O_NONBLOCK;  // Make socket blocking
			else
				flags |= O_NONBLOCK;   // Make socket non-blocking
			fcntl(m_sicket, F_SETFL, flags);
		}

protected:
	base_socket()
		: m_is_open(false)
		{ }
	base_socket(const socket_type &socket)
		: m_socket(socket), m_is_open(true)
		{ }

	void set(const socket_type &socket)
		{ m_socket = socket; }

	void is_open(const bool status)
		{ m_is_open = status; }

private:
	socket_type m_socket;
	bool        m_is_open;

	base_socket(const base_socket &) = delete;
	base_socket &operator=(const base_socket &) = delete;
};

}  // namespace net

#endif // __NET_BASE_SOCKET_H__
