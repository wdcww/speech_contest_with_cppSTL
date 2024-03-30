# 模拟演讲比赛流程（cpp_STL的初次使用）

*利用了STL的container、algorithm 和 iterator所提供的便利性*

*演讲管理者类（speechManager类）在speechManager.h中声明，在speechManager.cpp中定义*

*Speaker.h中声明选手类*

---
## 一、程序的逻辑

### 比赛流程的模拟使用speechManager类的实例化对象spmanager。
### 12个选手参加比赛，（姓名依次是“选手A，选手B，...，选手L”），共比赛两轮。每个选手由10个评委打分，去除最高、最低，取平均成绩作为该选手此轮得分。
### 第一轮比赛，根据抽签结果，6人一组，12人分为两个小组。取两个小组的前三，6人晋级第二轮。
### 第二轮比赛，根据抽签结果再赛，前三胜出，作为此届的冠亚季军，写入speech.csv

### 流程的实现使用speechManager::startSpeech()
```c++
void speechManager::startSpeech()
{  
    createSpeaker();//先创建参加比赛的12个人

    for(;this->m_index<=2;this->m_index++)//两轮比赛的2层for循环
   {
   //抽签
     chouqian();
     system("pause");
   //比赛
     speechcontest();
     system("pause");
   //显示晋级结果
     showthefinall();   
     system("pause");
   } 
   saveRecord();//保存胜出的人员信息到.csv
   initSpeechManager();//重新初始化,便于下一次的比赛(容器清空,比赛轮数重置为1)
}
```

---
## 二、一些细节
## 1. speechManager::createSpeaker()
### · 为每个选手创建一个Speaker类的对象sp，并且为每个选手产生编号。
### · 将“编号-选手sp”放到speechManager::map<int,Speaker> m_Speaker中（方便后续根据“编号”查修选手的m_Name、m_Score[0]、m_Score[1]）
### · 将产生的“编号”放到speechManager::vector< int> v1中（方便使用 random_shuffle(v1.begin(),v1.end())完成抽签）
```C++
class Speaker
{ public:
     string m_Name;     //每个Speaker的姓名
     double m_Score[2]; //只有2轮的分数
};
```
### Speaker类很简单：m_Name，大小为2的数组。

## 2. deque< double > dq 
### · 在speechManager::speechcontest()中，给每个选手一个双端数组用来记录10个分数，用sort排序完，直接头删和尾删去除最高分和最低分
```c++
sort(dq.begin(),dq.end(),greater<double>());
dq.pop_front();  
dq.pop_back();
```

## 3. speechManager::loadRecord()与speechManager::map<int,vector<string>> m_Record的巧妙
### loadRecord()读取之前saveRecord()保存的.csv文件，将得到的数据存到map<int,vector<string>> m_Record中，
### 键-值对“int”-“vector<string>”是“届数”-“该届信息”
![](/example.png)

---
*后续更新*




