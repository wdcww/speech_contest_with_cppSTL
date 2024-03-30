# 模拟演讲比赛流程（cpp_STL的初次使用）

*利用了STL的container、algorithm 和 iterator所提供的便利性*

*演讲管理者类（speechManager类）在speechManager.h中声明，在speechManager.cpp中定义*

*Speaker.h中声明选手类*

---
## 程序的逻辑

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





