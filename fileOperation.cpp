#include"fileOperation.h"

int walkPath(string path, vector<string>&allPath)
{
	string filePath = path + "\\*.*";
	intptr_t handle;
	_finddata_t findData;//�洢�ļ���Ϣ�����ݽṹ
	int res = 0;
	handle = _findfirst(filePath.c_str(), &findData);
	if (handle == -1) {// ����Ƿ�ɹ�
		cout << "can not found the file ... " << endl;
		return res;
	}
	do
	{
		if (findData.attrib&_A_SUBDIR)//�������ļ���
		{
			//������Ŀ¼Ϊ"."��".."���������һ��ѭ�������������Ŀ¼������������һ������
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;
			// ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
			string dirNew = path + "\\" + findData.name;
			vector<string> tempPath;
			res = walkPath(dirNew, tempPath);
			allPath.insert(allPath.end(), tempPath.begin(), tempPath.end());
		}
		else //������Ŀ¼�������ļ���������ļ������ļ��Ĵ�С
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
	_finddata_t findData;//�洢�ļ���Ϣ�����ݽṹ
	int res = 0;
	handle = _findfirst(filePath.c_str(), &findData);
	if (handle == -1) {// ����Ƿ�ɹ�
		cout << "can not found the file ... " << endl;
		return res;
	}
	do
	{
		if (findData.attrib&_A_SUBDIR)//�������ļ���
		{
			//������Ŀ¼Ϊ"."��".."���������һ��ѭ�������������Ŀ¼������������һ������
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;
			// ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
			string dirNew = path + "\\" + findData.name;
			vector<string> tempPath;
			res = walkPath(dirNew, key, tempPath);
			allPath.insert(allPath.end(), tempPath.begin(), tempPath.end());
		}
		else //������Ŀ¼�������ļ���������ļ������ļ��Ĵ�С
		{
			if (strstr(findData.name, key.c_str()) == NULL)//������
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
	file.open(txtName, ios::trunc|ios::out);//�����ļ�
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
	str += pattern;//��չ�ַ����Է������
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