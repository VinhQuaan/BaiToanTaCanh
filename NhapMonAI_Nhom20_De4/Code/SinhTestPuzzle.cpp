#include<iostream>
#include<vector>
#include<map>
#include<Windows.h>
#include<fstream>
#include<iomanip>
#include<time.h>

#define N 4
#define pb push_back
#define Puzzle vector<vector<int>>
#define pii pair<int,int>
#define x first
#define y second
#define r open.size()-1
#define T 5000000

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

int main()
{
    srand(time(0));

    Puzzle X,Y,initial,final;

	Read(initial);
	Read(final);

    vector<Puzzle>open,Path;
	map<Puzzle,bool>visited;
	map<Puzzle,Puzzle>father;
    int l=0;
    pii blank,m;
    clock_t start,end;
    double time_use;


    Y=final;
    for(int i=0;i<T;i++)
    {
        blank=Find(Y);
        m=Move[(int)rand()%4];
        while(!isSafe(blank,m))m=Move[(int)rand()%4];
        swap(Y[blank.x][blank.y],Y[blank.x+m.x][blank.y+m.y]);
    }
    Print(Y);
}
