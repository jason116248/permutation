#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> mylist;
void show(string temp)
{
    bool flag = true;
    if(mylist.empty())
    {
        mylist.push_back(temp); //nothing in the vector put the first string into it
        cout << temp << endl;
    }
    else
    {
        for(int i=0;i<=mylist.size()-1;i++)
        {
            if(mylist.at(i)==temp) // if the string is as same as the one in the list
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            mylist.push_back(temp);
            cout << temp << endl;
        }

    }
}
void perm(char *List,int i,int n)
{
    string tempStr;

    int j;
    if(i==n)
    {

            for(j=0; j<=n; j++)
            {

                {
                    tempStr += *(List+j) ;
                }
            }
        //cout << tempStr << endl;
         show(tempStr);

    }
    else
    {

        for(j=i; j<=n; j++)
        {
            swap(*(List+i),*(List+j));  //這個swap可以決定好字母排列的順序


            perm(List,i+1,n); //持續的做排列或印出字串


            swap(*(List+i),*(List+j)); //當排在第一個字母的排列完成時，讓字串回到最一開始的狀態


        }

    }

}
int main()
{
    string str;
    int length;

    cout << "enter the string" << endl;
    getline(cin,str);
    cout << endl;
    length = str.length();
    perm(&(str.at(0)),0,length-1);


    return 0;
}
