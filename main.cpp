#include <QCoreApplication>
#include<bits/stdc++.h>
#include"maze.h"
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    string command="";//getline twice to get
    string tmpsize,tmplink;

    getline(cin,tmpsize);
    getline(cin,tmplink);
    command=tmpsize+"\n"+tmplink;

    maze m_maze;
    if(m_maze.create(command))
    {
        string result;
        result=m_maze.getmazetext();
        cout<<result;
    }
    system("pause");
    return app.exec();
}
