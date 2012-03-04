/********************************************************************
* File: main.cpp                               Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

#include "tm.h"
#include "config.h"

int main(int argc, char *argv[])
{
	config::parse_arguments(argc, argv);

	if (config::log_file_name.empty())
		logger::init();  // Use std::clog
	else
		logger::init(config::log_file_name);  // Use the named file

	LOG(info, "Hello world!");
}
