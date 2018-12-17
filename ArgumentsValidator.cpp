#include "ArgumentsValidator.h"
bool ArgumentsValidator::CheckPath(string path) {
	return fs::exists(path);
}
bool ArgumentsValidator::Unique(string param) {
	GlobalData& gb = GlobalData::getObject();
	for (size_t i = 0; i < gb.numberOfParams; i++)
		if (param == gb.params[i]) return false;
	return true;
}

bool ArgumentsValidator::CheckAndSetArgs(size_t size, char ** args) {
	GlobalData& gb = GlobalData::getObject();
	//количество аргументов должно быть не менее 4 
	//(путь exe файла по умолчанию, путь к папке-источнику, путь к папке назанчения, количество аргументов)
	if (size <= 4 || size > 4 + gb.MAX_NUMBER_OF_PARAMS) return false;
	//проверка наличия папки-источника 
	if (CheckPath(args[1])) gb.SourceDirectory = args[1]; else return false;
	//проверка возможности создания папки в месте назначения и её создание в случае, если это можно сделать
	try {
		CreateDirectory(args[2], NULL);
		gb.DistDirectory = args[2];
	}
	catch (...) {
		return false;
	}
	//количество аргументов и проверка на валидность введённого значения
	size_t currentArg = atoi(args[3]);
	if (currentArg >= 0 && currentArg <= gb.MAX_NUMBER_OF_PARAMS) {
		gb.numberOfParams = currentArg;
		gb.params = new string[gb.numberOfParams];
	}
	else return false;
	//считвание параметров каталогизации и запись их в массив параметров 
	for (size_t i = 0; i < gb.numberOfParams; i++)
	{
		currentArg = atoi(args[4 + i]);
		if (currentArg >= 0 && currentArg <= gb.MAX_NUMBER_OF_PARAMS - 1) {
			//проверка на уникальность (был ли такой параметр ранее введён)
			if (!Unique(gb.PARAMETERS_IN_ORDER[currentArg])) return false;
			gb.params[i] = gb.PARAMETERS_IN_ORDER[currentArg];
		}
	}

	return true;



}