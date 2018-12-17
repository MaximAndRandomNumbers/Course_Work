#pragma once
#include "stdafx.h"
#include "GlobalData.h"


namespace fs = std::experimental::filesystem;

class ArgumentsValidator
{		
	static bool CheckPath(string path) {
		return fs::exists(path);
	}
	static bool Unique(string param) {
		GlobalData& gb = GlobalData::getObject();
		for (size_t i = 0; i < gb.numberOfParams; i++)
			if (param == gb.params[i]) return false;
		return true;
	}
public:
	
	static bool CheckAndSetArgs(size_t size, char ** args) {
		GlobalData& gb = GlobalData::getObject();
		//���������� ���������� ������ ���� �� ����� 4 
		//(���� exe ����� �� ���������, ���� � �����-���������, ���� � ����� ����������, ���������� ����������)
		if (size <= 4 || size > 4+gb.MAX_NUMBER_OF_PARAMS) return false;
		//�������� ������� �����-��������� 
		if (CheckPath(args[1])) gb.SourceDirectory = args[1]; else return false;
		//�������� ����������� �������� ����� � ����� ���������� � � �������� � ������, ���� ��� ����� �������
		try {
			CreateDirectory(args[2],NULL);
			gb.DistDirectory = args[2];
		} 
		catch(...) {
			return false;
		}
		//���������� ���������� � �������� �� ���������� ��������� ��������
		size_t currentArg = atoi(args[3]);
		if (currentArg >= 0 && currentArg <= gb.MAX_NUMBER_OF_PARAMS) {
			gb.numberOfParams = currentArg;
			gb.params = new string[gb.numberOfParams];
		}
		else return false;
		//��������� ���������� ������������� � ������ �� � ������ ���������� 
		for (size_t i = 0; i < gb.numberOfParams; i++)
		{
			currentArg = atoi(args[4 + i]);
			if (currentArg >= 0 && currentArg <= gb.MAX_NUMBER_OF_PARAMS - 1) {
				//�������� �� ������������ (��� �� ����� �������� ����� �����)
				if (!Unique(gb.PARAMETERS_IN_ORDER[currentArg])) return false;
				gb.params[i] = gb.PARAMETERS_IN_ORDER[currentArg];
			}
		}

		return true;
		

		
	}
};

