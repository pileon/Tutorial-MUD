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

	logger::init();  // Initialize logger using std::clog

	LOG(info, "Hello world!");
}
