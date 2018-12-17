#pragma once
#include "stdafx.h"
#include "File.h"
#include "IComponent.h"
using namespace std;


class Directory : public IComponent
{	
public:	
	vector<shared_ptr<Directory>> dirs;
	vector<shared_ptr<File>> files;
	
	Directory() {};
	Directory(string n){
		GlobalData& gb = GlobalData::getObject();
		name = n;
		path = gb.DistDirectory + '\\' + name;
	}
	bool IComponent::isFile() const { return false; }

	void Add(shared_ptr<Directory>& dir) {
		dirs.push_back(dir);
	}
	void Add(shared_ptr<File>& file) {
		files.push_back(file);
	}
	
	
};

