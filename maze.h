#ifndef MAZE_H
#define MAZE_H
#include<string.h>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;
#define MAX 100000000
//string split function(seperator " ") to get info enter from keyboard
void SplitString(const string &s,vector<string> &v,const string&c)
{
    string::size_type pos1,pos2;
    pos2=s.find(c);
    pos1=0;
    while(string::npos!=pos2)
    {
        v.push_back(s.substr(pos1,pos2-pos1));
        pos1=pos2+c.size();
        pos2=s.find(c,pos1);
    }
    if(pos1!=s.length())
        v.push_back(s.substr(pos1));
}
bool isnum(string s)
{
    stringstream sin(s);
    int t;char p;
    if(!(sin>>t)) return false;
    if(sin>>p) return false;
    else
        return true;
}
class maze
{
private:
 string mazetext;
 int width;
 int height;
public:
 maze();
 int create(string &command);
 void setmazetext(int **matrix);
 string getmazetext();
};
maze::maze()//initialization to be a maze sized 5*5
{
    width=0;height=0;
    mazetext="";
}
int maze::create(string &command)
{
    vector<string> vsize;//size of maze in vector <string>
    vector<int> vsizeint;//size of maze in vector <int>
    string tmpsize,tmplink;
    vector<string> v;
    ////////get two lines info(strings) from command
    SplitString(command,v,"\n");
    tmpsize=v[0];tmplink=v[1];
    SplitString(tmpsize,vsize," ");
    if(int(vsize.size())!=2)
    {
        cout<<"Incorrect command format."<<endl;
        return 0;
    }

    for(vector<string>::size_type i=0;i!=vsize.size();++i)
    {
        if(!isnum(vsize[i]))
        {
            cout<<"Invalid number format."<<endl;return 0;
        }
        int tmp=atoi(vsize[i].c_str());
        if(tmp<0)
        {
            cout<<"Incorrect command format."<<endl;return 0;
        }
        vsizeint.push_back(tmp);
    }
    /////initialize the matrix of maze
    width=vsizeint[1];height=vsizeint[0];
    int **matrix=new int*[2*height+1];
    for(int i=0;i<2*height+1;i++)
    {
        matrix[i]=new int[2*width+1];
    }

    for(int i=0;i<2*height+1;i=i+1)
        for(int j=0;j<2*width+1;j=j+1)
        {
            if(i%2==0||j%2==0)
                matrix[i][j]=0;
            else
                matrix[i][j]=1;

        }
    //////  create maze with input info
    v.clear();
    SplitString(tmplink,v,";");
    vector<int> vgrid;
    vector<string> vstrtemp;
    vector<string> vstrtemp2;
    for(vector<string>::size_type i=0;i!=v.size();++i)
    {
        if(v[i].length()!=7)
        {
            cout<<"Incorrect command format."<<endl;
            return 0;
        }
        vstrtemp.clear();
        SplitString(v[i],vstrtemp," ");
        for(vector<string>::size_type k=0;k!=vstrtemp.size();++k)
        {
            if(vstrtemp[k].length()!=3)
            {
                cout<<"Incorrect command format."<<endl;
                return 0;
            }
            vstrtemp2.clear();
            SplitString(vstrtemp[k],vstrtemp2,",");
            for(vector<string>::size_type m=0;m!=vstrtemp2.size();++m)
            {

                if(!isnum(vstrtemp2[m]))
                {
                    cout<<"Invalid number format."<<endl;return 0;
                 }
                int tmp=atoi(vstrtemp2[m].c_str());
                if(tmp<0||(tmp>=height&&m%2==0)||(tmp>=width&&m%2!=0))
                {
                    cout<<"Number out of range."<<endl;return 0;
                 }
                vgrid.push_back(tmp);
            }

        }
    }

    for(vector<int>::size_type n=0;n!=vgrid.size();n=n+4)
    {

        if(!(vgrid.at(n)==vgrid.at(n+2)||vgrid.at(n+1)==vgrid.at(n+3)))
        {
            cout<<"Maze format error."<<endl;return 0;
        }
        if(!(abs(vgrid.at(n)-vgrid.at(n+2))<=1||abs(vgrid.at(n+1)-vgrid.at(n+3))<=1))
        {
            cout<<"Maze format error."<<endl;return 0;
        }
        if(vgrid.at(n)==vgrid.at(n+2))
        {
            if(vgrid.at(n+1)<vgrid.at(n+3))
            {
                matrix[2*vgrid.at(n)+1][2*vgrid.at(n+1)+2]=1;
            }
            else
            {
                matrix[2*vgrid.at(n)+1][2*vgrid.at(n+3)+2]=1;
            }
        }
        if(vgrid.at(n+1)==vgrid.at(n+3))
        {
            if(vgrid.at(n)<vgrid.at(n+2))
            {
                matrix[2*vgrid.at(n)+2][2*vgrid.at(n+1)+1]=1;
            }
            else
            {
                matrix[2*vgrid.at(n+2)+2][2*vgrid.at(n+1)+1]=1;
            }
        }


    }
    setmazetext(matrix);
    delete []  matrix;
    return 1;
}

string maze::getmazetext()
{
    return mazetext;
}
void maze::setmazetext(int **matrix)
{
    mazetext="";
    for(int i=0;i<2*height+1;i++)
    {
        for(int j=0;j<2*width+1;j++)
        {
            if(matrix[i][j]==0&&j!=2*width) mazetext+="[W] ";
            if(matrix[i][j]==1&&j!=2*width) mazetext+="[R] ";
            else
            {
                if(matrix[i][j]==0&&j==2*width) mazetext+="[W]";
                if(matrix[i][j]==1&&j==2*width) mazetext+="[R]";
            }
        }
        mazetext+="\n";
    }
}

#endif // MAZE_H
