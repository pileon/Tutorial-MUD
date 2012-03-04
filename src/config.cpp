/********************************************************************
* File: config.cpp                             Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

#include "tm.h"
#include "config.h"

#include <unistd.h>

namespace
{
	void print_help(const std::string &argv0)
	{
		std::cout << "Usage: " << argv0 << " [-l <filename>] [-h] [-v]\n";
		std::cout << "Where:\n";
		std::cout << "    -l <filename>    Log to named file\n";
		std::cout << "    -h               Print this help message and exit\n";
		std::cout << "    -v               Print version number and exit\n";
	}
}

std::string config::log_file_name;

void config::parse_arguments(int argc, char *argv[])
{
	int c;  // The returned option from getopt

	while ((c = getopt(argc, argv, "l:hv")) != -1)
	{
		switch (c)
		{
		case 'l':
			log_file_name = optarg;
			break;

		case 'h':
			print_help(argv[0]);
			std::exit(0);
			break;
		case 'v':
			std::cout << "Print version number\n";
			std::exit(0);
			break;

		case '?':
			print_help(argv[0]);
			std::exit(1);
			break;

		default:
			std::cerr << "Error: Unknown value returned by getopt: " << c << '\n';
			std::exit(1);
			break;
		}
	}
}
