/********************************************************************
* File: logger.cpp                             Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

#include "tm.h"
#include "logger.h"

void logger::init()
{
	// Use std::clog as output
}

void logger::init(const std::string &filename)
{
	// Open a file and use that for output
}

void logger::init(std::ostream &file)
{
	// Use the provided file as output
}
