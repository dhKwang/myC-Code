
#ifndef FILEOPERATION_H
#define FILEOPERATION_H
#include <string>
#include <vector>
#include<iostream>
#include <fstream>
#include<io.h>
using namespace std;
int walkPath(string path, vector<string>&allPath);
/*
����Ŀ¼
���룺
path:��������Ŀ¼
allPath:����Ŀ¼�б������
�����
0����ʧ��
1����ɹ�
*/

int walkPath(string path, string key, vector<string>&allPath);
/*
����Ŀ¼
���룺
path:��������Ŀ¼
key:�ؼ���
allPath:����Ŀ¼�б������
�����
0����ʧ��
1����ɹ�
*/
void vector2txt( vector<string>&allPath, string txtName);
/*
��vector���浽TXT�ļ���
*/

vector<string> txt2vector(string txtName);
//��TXT�ļ��е����ݰ��ж�ȡ��vector��

std::vector<std::string> split(std::string str, std::string pattern);
//ͨ��ĳ���ض��ַ�����Դ�ַ����ָ�Ϊ���ɿ飬�洢Ϊvector
//In��strԴ�ַ�����pattern���ض��ַ���
//Out��


string getFileName(string fullFileName);
#endif // !FILEOPERATION_H

