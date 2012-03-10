/********************************************************************
* File: main.cpp                               Part of Tutorial MUD *
*                                                                   *
* Created by Joachim Pileborg <tm@pileborg.org>                     *
* This file is in the public domain.                                *
********************************************************************/

#include "tm.h"
#include "config.h"

#include <thread>
#include <chrono>
#include <signal.h>

namespace
{
	void handle_sigint(int)
	{
		LOG(info, "SIGINT, SIGHUP or SIGTERM received");
		tm_shutdown();
	}

	void init_signals()
	{
		signal(SIGINT, handle_sigint);
		signal(SIGHUP, handle_sigint);
		signal(SIGTERM, handle_sigint);
	}

	bool keep_running = true;

	void mainloop()
	{
		LOG(debug, "Entering main loop...");
		while (keep_running)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		LOG(debug, "Left main loop");
	}
}

void tm_shutdown()
{
	LOG(info, "Shutting down");
	keep_running = false;
}

int main(int argc, char *argv[])
{
	config::parse_arguments(argc, argv);

	if (config::log_file_name.empty())
		logger::init();  // Use std::clog
	else
		logger::init(config::log_file_name);  // Use the named file

	init_signals();

	LOG(info, "Hello world!");

	mainloop();
}
