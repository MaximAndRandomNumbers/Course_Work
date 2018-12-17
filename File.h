#pragma once
#include "stdafx.h"
#include "GlobalData.h"
#include "IComponent.h"

using namespace std;
class File : public IComponent
{
	
	
	string GetNameFromPath() {
		return path.substr(path.find_last_of('\\') + 1);
	}
	string GetExtensionFromPath() {	
		return path.substr(path.find_last_of('.') + 1);
	}
	void SetParams() {
		GlobalData& gb = GlobalData::getObject();
		params = new string[gb.numberOfParams];
		for (size_t i = 0; i < gb.numberOfParams; i++)
		{
			this->params[i] = gb.params[i];
		}
	}
	string extension;
public:

	//в параметры входит имя исполнителя, название альбома
	//при необходимости можно указать больше параметров для каталогизации (например год выпуска и т.п.)
	string* params;
	
	File();

	File(string path){
		this->path = path;
		name = GetNameFromPath();
		extension = GetExtensionFromPath();		
		SetParams();
	}
	bool IComponent::isFile() const { return true; }

	
	
	string GetArtistName() { return 0; }
	string GetAlbumName() { return 0; }
	

	~File() { 
		delete[] params; 
	};
};

