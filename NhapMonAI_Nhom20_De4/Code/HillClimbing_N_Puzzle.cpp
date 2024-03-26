#include<iostream>
#include<vector>
#include<map>
#include<Windows.h>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<queue>

#define N 4
#define pb push_back
#define Puzzle vector<vector<int>>
#define pii pair<int,int>
#define x first
#define y second
#define pip pair<int,Puzzle>

using namespace std;

ifstream in("C:/Users/Admin/Desktop/NhapMonAI_Nhom20_De4/Test/input/test10.txt");
ofstream out("C:/Users/Admin/Desktop/NhapMonAI_Nhom20_De4/Test/output/test10.txt");

void Print(Puzzle X)
{
    int i,j;

    for(i=0;i<N;out <<'\n'&&i++)
        for(j=0;j<N;j++)out << setw(2) << right << X[i][j] <<" ";
    out <<'\n';
}

void Read(Puzzle &X)
{
    int i;
    X.resize(N);

    for(i=0;i<N;i++)
    {
        X[i].resize(N);
        for(int &j:X[i])in >> j;
    }
}

pii Find(Puzzle X, int u)
{
    int i,j;

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(X[i][j]==u)return {i,j};
}
vector<pii>Move={{0,1},{1,0},{0,-1},{-1,0}};

bool isSafe(pii bl, pii m)
{
    return 0<=bl.x+m.x&&bl.x+m.x<N&&0<=bl.y+m.y&&bl.y+m.y<N;
}

Puzzle X,Y,initial,final;

int h(Puzzle u)
{
    int i,j,Ans=0;

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            pii tmp=Find(final,u[i][j]);
            Ans+=abs(i-tmp.x)+abs(j-tmp.y);
        }
    return Ans;
}

int main()
{
    Read(initial);
    Read(final);

    priority_queue<pip,vector<pip>>temp;
	vector<Puzzle>open,Path;
	map<Puzzle,bool>visited;
	map<Puzzle,Puzzle>father;
    pii blank;
    int cnt=0;
    clock_t start,end;
    double time_use;

    start=clock();

	open.pb(initial);
    while(!open.empty())
    {
        X=open.back();open.pop_back();
        if(X==final){cout <<"Tim kiem thanh cong";break;}
        blank=Find(X,0);
        for(pii m:Move)
            if(isSafe(blank,m))
            {
                Y=X;swap(Y[blank.x][blank.y],Y[blank.x+m.x][blank.y+m.y]);
                if(!visited[Y]){visited[Y]=1;temp.push({h(Y),Y});father[Y]=X;}
            }
        while(!temp.empty()){open.pb(temp.top().y);temp.pop();}
    }
    end=clock();
    while(X!=initial)
    {
        Path.pb(X);
        X=father[X];
    }
    Print(X);
    while(!Path.empty()){Print(Path.back());Path.pop_back();cnt++;}
    time_use=(double)(end-start)/CLOCKS_PER_SEC;
    out << cnt+1 <<'\n'<< time_use;
}

