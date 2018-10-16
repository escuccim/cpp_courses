#pragma once
class Handle;

class Body
{
	friend class Handle;
public:
	Body();
	~Body();

private:
	int someData;
};

