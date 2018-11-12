
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
遍历目录
输入：
path:待遍历的目录
allPath:返回目录列表的引用
输出：
0代表失败
1代表成功
*/

int walkPath(string path, string key, vector<string>&allPath);
/*
遍历目录
输入：
path:待遍历的目录
key:关键词
allPath:返回目录列表的引用
输出：
0代表失败
1代表成功
*/
void vector2txt( vector<string>&allPath, string txtName);
/*
将vector保存到TXT文件中
*/

vector<string> txt2vector(string txtName);
//将TXT文件中的内容按行读取到vector中

std::vector<std::string> split(std::string str, std::string pattern);
//通过某个特定字符串将源字符串分割为若干块，存储为vector
//In：str源字符串，pattern：特定字符串
//Out：


string getFileName(string fullFileName);
#endif // !FILEOPERATION_H

