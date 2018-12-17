#include "Tree.h"


void Tree::AddRecursive(shared_ptr<Directory>& currentFolder, shared_ptr<File>& file, size_t counter) {
	//если дошли до последнего уровня вложенности
	if (counter == this->depth|| file->params[counter] == "") {
		//создаём файл в текущей папке 		
		currentFolder->Add(file);
		return;
	}
	for (size_t i = 0; i < currentFolder->dirs.size(); i++) {
		//проверяем, есть ли папка с таким названием
		if ((*file).params[counter] == currentFolder->dirs[i]->name) {
			//переходим внутрь папки
			AddRecursive(currentFolder->dirs[i],file, counter + 1);
			return;
		}
	}
	//создаём папку
	shared_ptr<Directory> newDir(new Directory((*file).params[counter]));
	currentFolder->Add(newDir);
	//переходим в неё
	AddRecursive(currentFolder->dirs[currentFolder->dirs.size() - 1],file, counter + 1);

	return;

}
void Tree::CreateRecursive(shared_ptr<Directory>& currentDir,string currentPath) {
	CreateDirectory(currentPath.c_str(), NULL);

	for (size_t i = 0; i < currentDir->files.size(); i++)
		rename((currentDir->files[i]->path).c_str(), (currentPath + "\\" + currentDir->files[i]->name).c_str());
	
	for (size_t i = 0; i < currentDir->dirs.size(); i++)
		CreateRecursive(currentDir->dirs[i], currentPath + '\\' + currentDir->dirs[i]->name);
		
	
	return;
}

