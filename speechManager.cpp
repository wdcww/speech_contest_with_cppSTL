#include"speechManager.h"

#include<algorithm>
#include<numeric>

#include<fstream>

speechManager::speechManager()
{ //构造函数的定义
   cout<<"构造函数"<<endl;
   this->initSpeechManager(); //初始化
}

speechManager::~speechManager()
{ //析构函数的定义
  
cout<<"析构函数"<<endl;
}

void speechManager::show_menu()
{   //展示UI菜单
    cout<<endl;
    cout<<"    |_欢迎参加演讲比赛_|   "<<endl;
    cout<<endl;
    cout<<"|****1开始演讲比赛********|"<<endl;
    cout<<endl;
    cout<<"|****2查看往届记录********|"<<endl;
    cout<<endl;
    cout<<"|****3清空比赛记录********|"<<endl;
    cout<<endl;
    cout<<"|****0退出比赛程序********|"<<endl;
    cout<<endl;
    cout<<"|_________________________|"<<endl;
    cout<<endl;
 
}

void speechManager::exit_speechManager()
{   //利用exit(0)去退出的一个成员函数
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);
}

void speechManager::initSpeechManager()
{
   
   //把容器都置空
   this->v1.clear();
   this->v2.clear();
   this->victory.clear();
   this->m_Speaker.clear();

   this->m_index=1; //当前比赛轮数为1
}


/////////////////////////////////////////////////
void speechManager::createSpeaker()
{
   string nameseed = "ABCDEFGHIJKL";

   for(int i=0;i<nameseed.size();i++)
   {
      string name="选手";
      name += nameseed[i];

      Speaker sp; //创建一个Speaker类的对象sp
      sp.m_Name = name; 
      
      for(int j=0;j<2;j++)
        sp.m_Score[j]=0; 

    this->v1.push_back(i+10001); //12名参加第一轮的选手的编号放到v1容器中

    this->m_Speaker.insert(make_pair(i+10001,sp)); //当前的 ID编号-选手 放到map容器中
   }

}

void speechManager::chouqian()
{  

   cout<<"第"<<this->m_index<<"轮比赛:  "<<"选手正在抽签..."<<endl;
   cout<<"-----------------------------"<<endl;
   cout<<"抽签后的演讲顺序如下："<<endl;

   if(this->m_index == 1)
   {  
       random_shuffle(v1.begin(),v1.end());  // #include <algorithm>
       for(vector<int>::iterator it = v1.begin();it!=v1.end();it++)
         cout<<*it<<" ";
       
      cout<<endl; 
   }
   else
   {
      random_shuffle(v2.begin(),v2.end());
    for(vector<int>::iterator it = v2.begin();it!=v2.end();it++)
         cout<<*it<<" ";
       
      cout<<endl; 

   cout<<"-----------------------------"<<endl;
   system("pause");
   

   }
}

void speechManager::speechcontest()
{
    cout<<"------------第"<<this->m_index<<"轮比赛正式开始:--------------"<<endl; 

    map<double,int,greater<double>> groupScore; //greater<double>这表示使用降序（按照 键 的从大到小的顺序）进行排序
    int num=0;  //记录人员数,6个为1组


    vector<int> v_Src; //比赛的人员容器
    
    if(this->m_index==1)
        v_Src=v1;
    else
        v_Src=v2;

    //  deque<double> dq; //双端数组,一会用sort排序完,直接头删和尾删去除最高分和最低分
      

        for(vector<int>::iterator it=v_Src.begin();it!=v_Src.end();it++)
        {
            num++;
            deque<double> dq; //给每个选手一个 双端数组,一会用sort排序完,直接头删和尾删去除最高分和最低分
            
            //10个评委来打分
            for(int i=0;i<10;i++)
                {  
                    double score = ( rand() % 401 + 600 )/10.f; 
                    //cout<<score<<" "; 
                    dq.push_back(score);
                }
            cout<<endl;
            

            sort(dq.begin(),dq.end(),greater<double>()); // 关系仿函数,greater是“大”,所以从大到小排
            
            
            // int p=1;
            // for(deque<double>::iterator it = dq.begin();it!=dq.end();it++,p++)
            // {  
            //cout<<*it<<" ";
            // if(p%10 == 0)  
            //    cout<<endl;
            // }
            // cout<<endl;

            dq.pop_front();  
            dq.pop_back();

            // cout<<"去除最高分和最低分后:"<<endl;
            // p=1;
            // for(deque<double>::iterator it = dq.begin();it!=dq.end();it++,p++)
            // {  
            // cout<<*it<<" ";
            // if(p%8 == 0)  
            //    cout<<endl;
            // }
            // cout<<endl;


            double sum = accumulate(dq.begin(),dq.end(),0.0f);
            double avg=sum/(double)dq.size();
            
            cout<<"第"<<num<<"个人的编号是"<<*it<<"  "<<this->m_Speaker[*it].m_Name<<"  sum是"<<sum<<" "<<"  avg是"<<avg<<endl;
            // cout<<endl;
            // cout<<endl;

            
            //第一轮,把每个人的平均分记录到 “id-Speaker对” 的Speaker的 double数组 m_Score[0]里
            this->m_Speaker[*it].m_Score[this->m_index-1] = avg;


            
            groupScore.insert(make_pair(avg,*it));//6个人一组,用临时容器保存



            if(num % 6 == 0)
            {
                 
              cout<<"第"<< num/6 <<"小组比赛名次:"<<endl;

                for( multimap<double,int,greater<double>>::iterator it = groupScore.begin(); it!=groupScore.end(); it++ )     
                {
                cout<<"编号是"<<it->second
                <<"  "<<this->m_Speaker[it->second].m_Name
                <<"  第"<<this->m_index<<"轮总成绩"
                <<this->m_Speaker[it->second].m_Score[this->m_index-1]
                <<endl;
                }

               //  groupScore.clear();////////////////////////////////////////////
            


             int count=0;
            // 取前三名
             for(multimap<double,int,greater<double>>::iterator it=groupScore.begin();
             it!=groupScore.end() && count<3;it++,count++)

             {                      
                if(this->m_index==1)
                 {
                     v2.push_back((*it).second); 
                 }
                 else
                 {
                    victory.push_back((*it).second);
                 }
             }
             

            //  cout<<"晋级者"<<endl;
            //  for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
            //  cout<<*it<<" "<<this->m_Speaker[*it].m_Name<<" "<<this->m_Speaker[*it].m_Score[this->m_index-1]<<", ";
            //  cout<<endl;


             groupScore.clear();

           }


        }

      cout<<"------------第"<<this->m_index<<"轮比赛结束:--------------"<<endl;     

}

void speechManager::showthefinall()
{
     cout<<endl;
     cout<<"------------第"<<this->m_index<<"轮晋级选手信息如下-----------------"<<endl;
     vector<int> v;
     if(this->m_index == 1)
      v=v2;
     else
      v=victory;
     for(vector<int>::iterator it=v.begin();it!=v.end();it++)
      cout<<"编号"<<*it<<" "<<this->m_Speaker[*it].m_Name<<" "<<this->m_Speaker[*it].m_Score[this->m_index-1]<<", "<<endl;
      cout<<endl;

}

void speechManager::saveRecord()
{
   ofstream ofs;  //此文件的上面写了#include<fstream>
   ofs.open("speech.csv",ios::out | ios::app);
   
   for(vector<int>::iterator it = victory.begin();it!=victory.end();it++)
   ofs<<*it<<","<<m_Speaker[*it].m_Name<<","<<m_Speaker[*it].m_Score[1]<<",";
   
   ofs<<endl;

   ofs.close();

}

void speechManager::startSpeech()
{  // 这个函数的顺利运行是需要包含上面紧邻的5个函数createSpeaker()、chouqian()、speechcontest()、showthefinall()、saveRecord()
    
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
////////////////////////////////////////////////


void speechManager::loadRecord()
{ //查看往届的获胜人员信息,
  ifstream ifs("speech.csv",ios::in);
  
  if(!ifs.is_open())
   {
      cout<<"文件不存在"<<endl;
      ifs.close();
      return;
   }




    char ch;
    ifs>>ch; 
    if(ifs.eof())
    {
       cout<<"文件数据为空"<<endl;
       ifs.close();
    }
/////////////////////////////////////////////////////////    
// ifs.seekg(0, ios::beg);  // 将文件指针移动到文件的开头
//在读取 ch 后，文件指针已经移动到了文件的第一个字符之后,这样一会拿数据出来会跳过这个

//也可以用以下的这行:
     ifs.putback(ch);  //把刚刚读取的字符又放回去,
/////////////////////////////////////////////////////////

    int index=0;    
    string data;
            while(ifs>>data) //读取一行,就是1届比赛的最后3个获奖人员
            {
            // cout<<data<<endl;
            
            vector<string> v;
            int pos=-1;
            int start=0;
            
                     while(true)  
                     {
                        pos=data.find(",",start); //一开始进来,start=0,就是从0处开始找“,” 找不到的话pos会被赋值为-1
                        
                        if(pos==-1)
                           break; //找不到,意味着找完了文件里所有的东西,那就跳出while(true)    
                        
                        string tmp=data.substr(start,pos-start);  //字符串.substr(参数1,参数2),参数1是起始位置,参数2是截取长度
                        v.push_back(tmp);
                        
                        start=pos+1; //下一次从“,”的下一个位置开始找

                     }
            
               this->m_Record.insert(make_pair(index,v));
               index++;

            }

    ifs.close();

    cout<<endl<<"刚刚读取的文件,里面有"<<index<<"届信息"<<endl;
  
    for(int i=0;i<index;i++)
       { 
         cout<<endl<<"第"<<i+1<<"届"<<endl;
         cout<<"冠军: 编号"<<this->m_Record[i][0]<<" 姓名"<<this->m_Record[i][1]<<" 分数"<<this->m_Record[i][2]<<endl;
         cout<<"亚军: 编号"<<this->m_Record[i][3]<<" 姓名"<<this->m_Record[i][4]<<" 分数"<<this->m_Record[i][5]<<endl;                    
         cout<<"季军: 编号"<<this->m_Record[i][6]<<" 姓名"<<this->m_Record[i][7]<<" 分数"<<this->m_Record[i][8]<<endl;
       }
       
}
 
void speechManager::deleteRecord()
{
  
   cout<<endl;
   cout<<"确认清空？"<<endl<<"1.确认"<<endl<<"2.返回"<<endl;
   int select = 0;
   cin>>select;

   if(select == 1)
   {
     ofstream ofs("speech.csv",ios::trunc); //以trunc方式打开(文件如果存在就删掉并重新创建)
     ofs.close();
     
     this->initSpeechManager(); //先把目前所有容器中的东西清空
     this->saveRecord();        //然后再把 空的容器 写入到文件,这样文件也是空的
   }
   else
   return;
}

