#ifndef __LOGGER_H__
#define __LOGGER_H__
/********************************************************************
* File: logger.h                               Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

namespace logger
{
	void init();
	void init(const std::string &filename);
	void init(std::ostream &file);

	std::ostream &get_logger();
}

#endif // __LOGGER_H__
