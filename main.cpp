//基于STL的演讲比赛流程管理系统
// bilibili黑马程序员C++ p264-p281

#include<iostream>
#include"speechManager.cpp"

using namespace std;



void test02()
{
    speechManager spmanager; //创建一个管理类的对象

    while(true)
    { 
            
            cout<<endl;
            spmanager.show_menu();
            int a;
            cout<<"请输入你的数字选择";
            cin>>a;
            cout<<"你选择了功能（"<<a<<")"<<endl;
              switch(a)
                        {
                            case 1:{
                            cout<<endl;
                            spmanager.startSpeech(); //开始演讲比赛
                            cout<<endl;
                            system("pause");
                            } break;

                            case 2:{
                            cout<<endl;
                            spmanager.loadRecord(); //查看往届记录
                            cout<<endl;
                            system("pause");
                            } break;

                            case 3:{
                            cout<<endl; 
                            spmanager.deleteRecord();//清空比赛记录
                            cout<<endl;
                            system("pause");
                            } break;

                            default:break;             
                        }
                
                if(a!=0 && a!=1 && a!=2 && a!=3)
               {
                cout<<endl;
                cout<<"请输人有效的数字"<<endl;
                system("pause");
                cout<<endl;
               }
               
                if(!a)
                   break;//跳出while(true)
         system("cls");

    }

        //  ////a=0, 从 while(true) 中出来, test02()就正常结束了,再打印一下下面的东西
        //     map<int,Speaker>::iterator it;
        //     for(it = spmanager.m_Speaker.begin(); it!=spmanager.m_Speaker.end(); it++)
        //     {
        //        cout<<"选手编号:"<<it->first  //it是map<int,Speaker>容器的迭代器,it->first是int
        //            <<"  姓名:"<<it->second.m_Name  //it->second是Speaker,然后Speaker有两个成员,m_Name,m_Score
        //            <<"  第一轮成绩:"<<it->second.m_Score[0]
        //            <<"  第二轮成绩:"<<it->second.m_Score[1]<<endl;
        //         cout<<endl;
        //     }

}



int main()
{   
    //为了能够看到析构函数的调用,把主体写在其他的函数中
    test02();

    system("pause");
    return 0;
}






