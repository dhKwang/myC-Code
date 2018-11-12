#include"fileOperation.h"

int walkPath(string path, vector<string>&allPath)
{
	string filePath = path + "\\*.*";
	intptr_t handle;
	_finddata_t findData;//存储文件信息的数据结构
	int res = 0;
	handle = _findfirst(filePath.c_str(), &findData);
	if (handle == -1) {// 检查是否成功
		cout << "can not found the file ... " << endl;
		return res;
	}
	do
	{
		if (findData.attrib&_A_SUBDIR)//若是子文件夹
		{
			//若该子目录为"."或".."，则进行下一次循环，否则输出子目录名，并进入下一次搜索
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;
			// 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
			string dirNew = path + "\\" + findData.name;
			vector<string> tempPath;
			res = walkPath(dirNew, tempPath);
			allPath.insert(allPath.end(), tempPath.begin(), tempPath.end());
		}
		else //不是子目录，即是文件，则输出文件名和文件的大小
		{
			string filePath = path + "\\" + findData.name;
			allPath.push_back(filePath);
			//cout << filePath << "\t" << findData.size << " bytes.\n";
		}
	} while (_findnext(handle, &findData) == 0);
	_findclose(handle);
	res = 1;
	return res;
}

int walkPath(string path, string key, vector<string>&allPath)
{
	string filePath = path + "\\*.*";
	intptr_t handle;
	_finddata_t findData;//存储文件信息的数据结构
	int res = 0;
	handle = _findfirst(filePath.c_str(), &findData);
	if (handle == -1) {// 检查是否成功
		cout << "can not found the file ... " << endl;
		return res;
	}
	do
	{
		if (findData.attrib&_A_SUBDIR)//若是子文件夹
		{
			//若该子目录为"."或".."，则进行下一次循环，否则输出子目录名，并进入下一次搜索
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;
			// 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
			string dirNew = path + "\\" + findData.name;
			vector<string> tempPath;
			res = walkPath(dirNew, key, tempPath);
			allPath.insert(allPath.end(), tempPath.begin(), tempPath.end());
		}
		else //不是子目录，即是文件，则输出文件名和文件的大小
		{
			if (strstr(findData.name, key.c_str()) == NULL)//不存在
				continue;
			else
			{
				string filePath = path + "\\" + findData.name;
				allPath.push_back(filePath);
			}

			//cout << filePath << "\t" << findData.size << " bytes.\n";
		}
	} while (_findnext(handle, &findData) == 0);
	_findclose(handle);
	res = 1;
	return res;
}
void vector2txt( vector<string>&allPath, string txtName)
{
	fstream file;
	file.open(txtName, ios::trunc|ios::out);//覆盖文件
	for (size_t i = 0; i < allPath.size(); i++)
	{
		string  perPath = allPath.at(i);
		//cout << perPath << endl;
		file << perPath << endl;
	}
	cout << "save vector to txtFile:" << txtName << endl;
	file.close();
}
vector<string> txt2vector(string txtName)
{
	fstream file;
	file.open(txtName, ios::in);
	string buffer;
	vector<string> pathVector;
	while (! file.eof())
	{
		file >> buffer;
		//cout << buffer << endl;
		pathVector.push_back(buffer);
	}
	return pathVector;
}

std::vector<std::string> split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;//扩展字符串以方便操作
	int size = str.size();

	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

string getFileName(string fullFileName)
{
	vector<string>res = split(fullFileName,"\\");
	size_t sizeOfVector;
	sizeOfVector = res.size();
	string fileName;
	fileName = res.at(sizeOfVector - 1);
	return fileName;
}