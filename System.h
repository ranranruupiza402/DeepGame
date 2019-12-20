#pragma once
class System
{
public:
	System() = default;
	~System() = default;
	bool initialize() const;
	void end() const;
	void main() const;
};

