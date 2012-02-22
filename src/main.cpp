/********************************************************************
* File: main.cpp                               Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

#include "tm.h"

int main(int argc, char *argv[])
{
	logger::init();  // Initialize logger using std::clog
	logger::get_logger() << "Hello world!\n";
}
