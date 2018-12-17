#pragma once
#include <string>
class IComponent {
public:
	std::string name;
	std::string path;
	virtual bool isFile() const = 0;
	
};