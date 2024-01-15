//speechManager.h 此文件中写声明

#pragma once  //这是一个预处理指令，用于防止头文件的内容在同一个文件中被包含多次
#include<iostream>


#include<vector>
#include<map>
#include<deque>


#include"Speaker.h"


using namespace std;

class speechManager
{

 public:
    //函数
            speechManager();
            ~speechManager();

            void show_menu(); //展示菜单
            void exit_speechManager(); //退出管理系统
            void initSpeechManager(); //初始化属性

            void createSpeaker();     //创建参加第一轮比赛的12个选手
            void startSpeech();//比赛流程
            void chouqian();//抽签
            void speechcontest();//比赛
            void showthefinall();//展示此轮的晋级结果
            void saveRecord(); //保存此次比赛的全部数据结果

            void loadRecord();
            
            void deleteRecord();

    //属性
            vector<int> v1; //存放第一轮的12个比赛选手的ID顺序的容器

            vector<int> v2; //放第二轮(第一轮晋级)的6个比赛选手的ID顺序

            vector<int> victory; //存放最后胜出的3个人的容器

            map<int,Speaker> m_Speaker; //存放 ID-选手 键-值对
            
            int m_index; //记录比赛轮数

            map<int,vector<string>> m_Record; // 存放“读取到的往届获胜人员的信息”,m_Record的key是第几届,value是记录的具体信息

 private:


};