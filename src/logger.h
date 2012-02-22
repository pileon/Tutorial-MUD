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
	namespace categories
	{
		class category
		{
		public:
			category(const std::string &text)
				: m_text(text)
				{ }
 
			const std::string &get() const
				{ return m_text; }

		private:
			std::string m_text;
		};

		const category debug{"[DEBUG]"};
		const category info {"[INFO ]"};
		const category error{"[ERROR]"};
		const category net  {"[NET  ]"};
	}

	void init();
	void init(const std::string &filename);
	void init(std::ostream &file);

	std::ostream &get_logger();
}

inline std::ostream & operator<<(std::ostream &os,
	const logger::categories::category 	&cat)
{
	os << cat.get();
	return os;
}

#define LOG(cat, str) \
	logger::get_logger() << logger::categories::cat << ' ' << str << '\n'

#endif // __LOGGER_H__
