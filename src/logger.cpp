/********************************************************************
* File: logger.cpp                             Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

#include "tm.h"
#include "logger.h"

#include <memory>
#include <fstream>
#include <ctime>
#include <cstring>

namespace
{
	class logger_helper
	{
	public:
		logger_helper(const std::string &filename)
			: m_file(filename), m_output(m_file)
			{ }
		logger_helper(std::ostream &file)
			: m_output(file)
			{ }
		logger_helper()
			: m_output(std::clog)
			{ }

		~logger_helper()
			{
				if (m_file.is_open())
					m_file.close();
			}

		std::ostream &get()
			{ return m_output; }

	private:
		std::ofstream m_file;    // File
		std::ostream &m_output;  // Actual output stream used
	};

	std::unique_ptr<logger_helper> logger_helper_ptr;
}

void logger::init()
{
	// Use std::clog as output
	logger_helper_ptr.reset(new logger_helper());
}

void logger::init(const std::string &filename)
{
	// Open a file and use that for output
	logger_helper_ptr.reset(new logger_helper(filename));
}

void logger::init(std::ostream &file)
{
	// Use the provided file as output
	logger_helper_ptr.reset(new logger_helper(file));
}

std::ostream &logger::get_logger()
{
	return logger_helper_ptr->get();
}

const std::string logger::get_date_time()
{
	std::time_t now = std::time(nullptr);
	char *now_s = asctime(localtime(&now));

	// asctime returns with a newline, remove it
	now_s[strlen(now_s) - 1] = '\0';

	return now_s;
}
