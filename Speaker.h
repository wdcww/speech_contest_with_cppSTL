#pragma once  //这是一个预处理指令，用于防止头文件的内容在同一个文件中被包含多次

#include<string>
using namespace std;

class Speaker
{

public:
     string m_Name;     //Speaker的姓名
     double m_Score[2]; //只有2轮的分数

};