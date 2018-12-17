#include "Tree.h"


void Tree::AddRecursive(shared_ptr<Directory>& currentFolder, shared_ptr<File>& file, size_t counter) {
	//���� ����� �� ���������� ������ �����������
	if (counter == this->depth|| file->params[counter] == "") {
		//������ ���� � ������� ����� 		
		currentFolder->Add(file);
		return;
	}
	for (size_t i = 0; i < currentFolder->dirs.size(); i++) {
		//���������, ���� �� ����� � ����� ���������
		if ((*file).params[counter] == currentFolder->dirs[i]->name) {
			//��������� ������ �����
			AddRecursive(currentFolder->dirs[i],file, counter + 1);
			return;
		}
	}
	//������ �����
	shared_ptr<Directory> newDir(new Directory((*file).params[counter]));
	currentFolder->Add(newDir);
	//��������� � ��
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

