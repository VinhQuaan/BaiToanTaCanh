#include<iostream>
#include<vector>
#include<map>
#include<Windows.h>
#include<fstream>
#include<iomanip>
#include<time.h>

#define MAX 50
#define N 4
#define pb push_back
#define Puzzle vector<vector<int>>
#define pii pair<int,int>
#define x first
#define y second

using namespace std;

ifstream in("C:/Users/Admin/Desktop/NhapMonAI_Nhom20_De4/Test/input/test4.txt");
ofstream out("C:/Users/Admin/Desktop/NhapMonAI_Nhom20_De4/Test/output/test4.txt");

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

pii Find(Puzzle X)
{
    int i,j;

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(X[i][j]==0)return {i,j};
}
vector<pii>Move={{0,1},{1,0},{0,-1},{-1,0}};

bool isSafe(pii bl, pii m)
{
    return 0<=bl.x+m.x&&bl.x+m.x<N&&0<=bl.y+m.y&&bl.y+m.y<N;
}

clock_t start,End;
double time_use;

void DLS(Puzzle initial, Puzzle final, int k)
{
	vector<Puzzle>open,Path;
	map<Puzzle,bool>visited;
	map<Puzzle,Puzzle>father;
	map<Puzzle,int>depth;
    pii blank;
    bool Check=0;
    Puzzle X,Y;
    int cnt=0;

	open.pb(initial);depth[initial]=0;
    while(!open.empty())
    {
        X=open.back();open.pop_back();
        if(depth[X]>k)continue;
        if(X==final){cout <<"Tim kiem thanh cong";Check=1;break;}
        blank=Find(X);
        for(pii m:Move)
            if(isSafe(blank,m))
            {
                Y=X;swap(Y[blank.x][blank.y],Y[blank.x+m.x][blank.y+m.y]);
                if(!visited[Y]){visited[Y]=1;open.pb(Y);father[Y]=X;depth[Y]=depth[X]+1;}
            }
    }
    if(Check)
    {
        End=clock();
        while(X!=initial)
        {
            Path.pb(X);
            X=father[X];
        }
        Print(X);
        while(!Path.empty()){Print(Path.back());Path.pop_back();cnt++;}
        time_use=(double)(End-start)*1000/CLOCKS_PER_SEC;
        out << cnt+1 <<'\n'<< time_use;
        exit(0);
    }
}

int main()
{
	Puzzle initial,final;

	Read(initial);
	Read(final);

    start=clock();
    for(int d=0;d<=MAX;d++)DLS(initial,final,d);
    cout <<"Tim kiem khong thanh cong";
}
