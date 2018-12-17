#pragma once
#include "stdafx.h"
#include "GlobalData.h"


namespace fs = std::experimental::filesystem;

class ArgumentsValidator
{		
	static bool CheckPath(string path); 
	static bool Unique(string param);
public:
	
	static bool CheckAndSetArgs(size_t size, char ** args); 
};

