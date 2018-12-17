#pragma once
#include "stdafx.h"
#include "Directory.h"
#include "File.h"


class Tree
{
	//глубина вложенности
	int depth;
	//корень дерева
	shared_ptr<Directory> root;
	//рекурсивное добавление файла в дерево 
	void AddRecursive(shared_ptr<Directory>&, shared_ptr<File>&, size_t);
	//рекурсивное создание дерева в файловой системе Windows
	void CreateRecursive(shared_ptr<Directory>&, string);
public:
	
	Tree(shared_ptr<Directory>& dir, size_t depthLevel): depth(depthLevel), root(dir) {}
	
	void AddFileToTheTree(shared_ptr<File>& file) {
		int counter = 0;
		AddRecursive(root, file, counter);
	}
	void AddVectorOfFilesToTheTree(vector<shared_ptr<File>>& files) {
		for (size_t i = 0; i < files.size(); i++) AddFileToTheTree(files[i]);		
	}
	void CreateTheTreeInWindows(string pathToTheDistDir) {
		CreateRecursive(root,pathToTheDistDir);
	}
	
};

