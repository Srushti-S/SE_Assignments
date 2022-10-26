#include<iostream>
using namespace std;

class graph{
    int **adjMatrix;
    int vertices, edges;

    public:
    graph(int, int);
    void creatGraph();
    void addEdge(int, int, int);
    void prims();
    void displayMatrix();
};

graph :: graph(int v, int e){
    vertices = v;
    edges = e;
    adjMatrix = new int*[v];
    for(int row = 0; row < v; row++){
        adjMatrix[row] = new int[v];
        for(int column = 0; column < v; column++){
            adjMatrix[row][column] = 0;
        }
    }
}

void graph :: creatGraph(){
    int source, destination, weight;
    for(int i = 0; i < edges; i++){
        cout << "\nEnter source : ";
        cin >> source;
        cout<<"\nEnter destination : ";
        cin >> destination;
        cout << "\nEnter weight : ";
        cin >> weight;
        addEdge(source,destination,weight);
    }
    cout <<endl;
}

void graph :: addEdge(int s, int d, int w){
    adjMatrix[s][d] = w;
    adjMatrix[d][s] = w;
}

void graph :: prims(){
    int edge_no = 0;
    int x,y;
    int min;
    int minimumWeight = 0;
    bool visited[vertices];
    for(int i = 0; i < vertices; i++){
        visited[i] = false;
    }
    visited[0] = true;
    while(edge_no < vertices - 1){
        x = 0;
        y = 0; 
        min = 21363;
        
        for(int i = 0; i < vertices; i++){
            if(visited[i]){
                for(int j = 0; j < vertices; j++){
                    if(!visited[j] && adjMatrix[i][j]){
                        if(min > adjMatrix[i][j]){
                            min = adjMatrix[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " ----> " << y << " : " << adjMatrix[x][y] << endl;
        minimumWeight += min;
        visited[y] = true;
        edge_no++;
    }
    cout << "\n\nMinimum weight : "<<minimumWeight;
}

void graph :: displayMatrix(){
    cout << "\n\n<------------- Adjacency Matrix ------------->\n\n";
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            cout << adjMatrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(){
    int v,e;
    cout << "\nEnter number of vertices : ";
    cin >> v;
    cout << "\nEnter number of edges : ";
    cin >> e;
    graph g(v,e);
    g.creatGraph();
    cout << "\n\nMinimum spanning tree is :" << endl;
    g.prims();
    g.displayMatrix();
}