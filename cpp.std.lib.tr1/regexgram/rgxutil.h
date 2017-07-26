#ifndef	RGXUTIL_H
#define	RGXUTIL_H

#include <iostream>
#include <iomanip>
#include <regex>

static const char intro[] = "Trying to match `";
static const unsigned intro_chrs = sizeof(intro) - 1;

static const char *error(const std::regex_error &err)
{
	switch (err.code()) {
	case std::regex_constants::error_badbrace:
		return "invalid repeat count";
	case std::regex_constants::error_badrepeat:
		return "repeat not preceded by expression";
	case std::regex_constants::error_brace:
		return "unmatched curly brace";
	case std::regex_constants::error_brack:
		return "unmatched square bracket";
	case std::regex_constants::error_collate:
		return "invalid collating element name";
	case std::regex_constants::error_complexity:
		return "match too complex";
	case std::regex_constants::error_ctype:
		return "invalid chararcter class name";
	case std::regex_constants::error_escape:
		return "invalid escape sequence";
	case std::regex_constants::error_paren:
		return "unmatched parenthesis";
	case std::regex_constants::error_range:
		return "invalid character range specifier";
	case std::regex_constants::error_space:
		return "out of resource";
	case std::regex_constants::error_stack:
		return "out of memory";
	case std::regex_constants::error_backref:
		return "invalid back reference";
	default:
		return "unknown error";
	}
}

static void do_match(const char *str, const char *tgt,
		std::regex_constants::syntax_option_type flags)
{
	std::regex rgx;
	std::cout << "Regular expression `" << str << "`: ";
	try
	{
		rgx.assign(str, flags);
		std::cout << "okay\n";
	}
	catch (const std::regex_error &err)
	{
		std::cout << "invalid\n " << error(err) << '\n';
		return;
	}
	if (tgt) {
		std::cmatch mr;
		std::cout << intro << tgt << "`, ";
		try
		{
			if (std::regex_match(tgt, mr, rgx)) {
				std::cout << "success\n";
				for (int i = 0; i < mr.size(); ++i)
					std::cout << std::setw(intro_chrs - 2)
						<< i << ":"
						<< std::setw(mr.position(i) + 1) << ' '
						<< mr[i] << '\n';
			} else 
				std::cout << "no match\n";
		}
		catch (const std::regex_error &err)
		{
			std::cout << "match failed\n " 
				<< error(err) << '\n';
			return;
		}
	}
}

static void match_ECMA(const char *str, const char *tgt = 0)
{
	do_match(str, tgt, std::regex_constants::ECMAScript);
}

static void match_grep(const char *str, const char *tgt = 0)
{
	do_match(str, tgt, std::regex_constants::grep);
}

static void match_ere(const char *str, const char *tgt = 0)
{
	do_match(str, tgt, std::regex_constants::extended);
}

#endif
