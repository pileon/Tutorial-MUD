#ifndef __CONFIG_H__
#define __CONFIG_H__
/********************************************************************
* File: config.h                               Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

namespace config
{
	// The name of the file where to put logging
	extern std::string log_file_name;

	void parse_arguments(int argc, char *argv[]);
}

#endif // __CONFIG_H__
