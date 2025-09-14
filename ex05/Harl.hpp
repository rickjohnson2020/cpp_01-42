#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
private:
	enum Level {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		UNKNOWN
	};

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl(void);
	~Harl(void);
	static Level getLevelFromStr(const std::string str);
	void complain(std::string level);
};

#endif