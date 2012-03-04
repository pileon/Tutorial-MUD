/********************************************************************
* File: config.cpp                             Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

#include "tm.h"
#include "config.h"

#include <unistd.h>

void config::parse_arguments(int argc, char *argv[])
{
	int c;  // The returned option from getopt

	while ((c = getopt(argc, argv, "hv")) != -1)
	{
		switch (c)
		{
		case 'h':
			std::cout << "Print some help\n";
			std::exit(0);
			break;
		case 'v':
			std::cout << "Print version number\n";
			std::exit(0);
			break;

		case '?':
			std::cout << "Print some help\n";
			std::exit(1);
			break;

		default:
			std::cerr << "Error: Unknown value returned by getopt: " << c << '\n';
			std::exit(1);
			break;
		}
	}
}
