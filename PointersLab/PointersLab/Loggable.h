#pragma once
#include <string>

class Loggable
{
public:
	virtual void log(const std::string & message) const = 0;
};

