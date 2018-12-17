#pragma once
#include "stdafx.h"
#include "GlobalData.h"
#include "ArgumentsValidator.h"
#include "Directory.h"
#include "File.h"
#include "Tree.h"


using namespace std;
//TO-DO:
//1. ������������ ���������, �������� ������������� � �������
//2. �������� ����� �� ����� � ������ ����� (songs)
//3. ���������� ���������� ��� ���������� ����������
namespace fs = std::experimental::filesystem;



int main(size_t count, char ** args) {
		
	GlobalData& gb = GlobalData::getObject();
	//��������� ������ �� ������� ���������� � �������������� ����������� ����������
	if (!ArgumentsValidator::CheckAndSetArgs(count, args)) {
		cout << "Error in input data" << endl;
		system("pause");
		return 0;
	}
	//������ �����, ������������ � �������� �����
	vector<shared_ptr<File>> songs;
	//���������� ������� ����� ������������ � ������������ ������������ (� ������� ����� ���������� �������� ����������)
	for (const auto & entry : fs::directory_iterator(gb.SourceDirectory))
	{
		//std::cout << entry.path() << std::endl;
		string path = entry.path().string();
		string ext = entry.path().extension().string();
		if (ext == ".mp3" || 
			ext == ".wav" || 
			ext == ".aif" || 
			ext == ".mid" || 
			ext ==".flac")
			songs.push_back(shared_ptr<File>(new File(path)));
	}

	//������ �������, � ������� ����� �������� ��� ��������� �������� (������ ������)
	shared_ptr<Directory> main(new Directory("Sorted Music"));
	
	//������ ������ ���������
	Tree * tree = new Tree(main, gb.numberOfParams);

	//���������� ����� � ������
	tree->AddVectorOfFilesToTheTree(songs);

	//�������� ������ ��������� � �������� ������� Windows
	tree->CreateTheTreeInWindows(gb.DistDirectory);

	system("pause");
	delete tree;
	return 0;
}