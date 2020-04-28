#include<iostream>
#include<stdlib.h>
#include<map>
#include<list>
#include<algorithm>

using namespace std;
template <typename T>
class Graph
{

map<T,list<pair<T,int> > > adjList;

public:
Graph(){}

void addEdge(T u,T v,int weight,bool bidir = true){
adjList[u].push_back(make_pair(v,weight));

if(bidir){
adjList[v].push_back(make_pair(u,weight));
}
}

void display(){
for(auto node:adjList){
cout<<node.first<<" -> ";

for(auto vertex:node.second){
cout<<"( "<<vertex.first<<", "<<vertex.second<<" )";
}
cout<<endl;
}
}
};
//Manhattan function
int ManhattanProblem(int  **RightMatrix, int **DownMatrix,int right_row,int down_column)
{
 int n = right_row;
 int m = down_column;
 int ManhattanMatrix[n][m];

 ManhattanMatrix[0][0] = 0;

 for (int i=1;i<n;i++)
 {

  ManhattanMatrix[i][0] = ManhattanMatrix[i - 1] [0] + DownMatrix[i - 1] [0];
 }

 for (int j=1;j<m;j++)
 {

  ManhattanMatrix[0][j] = ManhattanMatrix[0][j - 1] + RightMatrix[0][j - 1];
 }

 for (int i = 1; i <n; i++)
 {
  for (int j = 1; j <m; j++)
  {

   ManhattanMatrix[i][j] =max(ManhattanMatrix[i - 1][j] + DownMatrix[i - 1][j],ManhattanMatrix[i][j - 1] + RightMatrix[i][j - 1]);
  }
 }

 return ManhattanMatrix[n-1][m-1];
}
void display1()

{
  cout<<"\n\n\n\n\n\n\n ";
  system("color A");
  cout<<"\t\t\t\t\t\t                              ______                  ______     ______                  _______    "<<endl;
  cout<<"\t\t\t\t\t\t   \\                      /  |          |            |          |      |   |\\      /|   |          "<<endl;
  cout<<"\t\t\t\t\t\t    \\                    /   |          |            |          |      |   | \\    / |   |          "<<endl;
  cout<<"\t\t\t\t\t\t     \\        /\\        /    |          |            |          |      |   |  \\  /  |   |          "<<endl;
  cout<<"\t\t\t\t\t\t      \\      /  \\      /     |______    |            |          |      |   |   \\/   |   |______    "<<endl;
  cout<<"\t\t\t\t\t\t       \\    /    \\    /      |          |            |          |      |   |        |   |          "<<endl;
  cout<<"\t\t\t\t\t\t        \\  /      \\  /       |          |            |          |      |   |        |   |          "<<endl;
  cout<<"\t\t\t\t\t\t         \\/        \\/        |_______   |________    |______    |______|   |        |   |_______   "<<endl;
  cout<<endl;
  //sleep(3);
  system("color E");
  system("color B");
  cout<<endl<<endl<<endl<<endl<<endl;

  system("color BC");
  //sleep(1);
  system("color 7");
}
int main()
{
    Graph<int> g;

    int first,second,weight,horizontal_count,vertical_count;

    int  ch;

    display1();


            cout<<"Enter the no of nodes in first line:"<<endl<<endl;

                cin>>horizontal_count;

            cout<<"Enter the node of nodes in vertical line:"<<endl<<endl;

                 cin>>vertical_count;

            cout<<"Enter horizontal edges"<<endl<<endl;

            cout<<"Press -1 to stop"<<endl<<endl;
    int **horizontal=new int*[horizontal_count];

      for(int i=0;i<horizontal_count;i++)
      {
        horizontal[i]=new int[vertical_count];
      }

     int i=0,j=0;

 do
    {
        if(i==vertical_count-1)
        {
          i=0;
          j++;
        }
            cout<<" Enter first vertex"<<endl<<endl;

                cin>>first;

            cout<<" Enter second vertex"<<endl<<endl;

                cin>>second;

           cout<<"Enter weight"<<endl<<endl;

                cin>>weight;

  horizontal[j][i]=weight;

  g.addEdge(first,second,weight,false);

     cout<<"Do u want to enter more edges"<<endl<<endl;

     cin>>ch;

     i++;

}while(ch!=-1);
    i=0;
    j=0;
   cout<<"Enter vertical edges"<<endl<<endl;

   cout<<"Press -1 to stop"<<endl<<endl;

   int **vertical=new int*[vertical_count];

    for(int i=0;i<vertical_count;i++)
    {
        vertical[i]=new int[horizontal_count];
    }

do
{
     if(j==horizontal_count)
       {
         j=0;
         i++;
       }
          cout<<"Enter first vertex"<<endl<<endl;

              cin>>first;

          cout<<"Enter second vertex"<<endl<<endl;

              cin>>second;

          cout<<"Enter weight"<<endl<<endl;

           cin>>weight;
   g.addEdge(first,second,weight,false);

   vertical[i][j]=weight;

   j++;
      cout<<"Do u want to enter more edges"<<endl<<endl;
      cin>>ch;

}while(ch!=-1);
system("CLS");
//printing graph
    cout<<endl;
    cout<<"GRAPH"<<endl<<endl;
    g.display();
    cout<<endl;
//printing horizontal matrix
    cout<<endl;
    cout<<"HORIZONTAL MATRIX"<<endl<<endl;
    for(int i=0;i<horizontal_count;i++)
    {
        for(int j=0;j<vertical_count-1;j++)
        {
            cout<<horizontal[i][j]<<" ";
        }
        cout<<endl;
    }
// printing vertical matrix
    cout<<endl;
    cout<<"VERTICAL MATRIX"<<endl<<endl;
    for(int i=0;i<vertical_count-1;i++)
    {
        for(int j=0;j<horizontal_count;j++)
        {
            cout<<vertical[i][j]<<" ";
        }
        cout<<endl;
    }
//function call manhattan
    cout<<"Maximum number of nodes visited from source to destination:"<<endl<<endl;

    cout<<ManhattanProblem(horizontal,vertical,horizontal_count,horizontal_count);
}
