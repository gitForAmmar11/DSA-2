#include<iostream>
#include<queue>
using namespace std;

struct nDistance
{
    int node;
    int distance;
};

int INF = 0x7F7F7F7F;

void printPath(int node, int parent[])
{
    if(parent[node] == node)
    {
        cout << node << " ";
    }
    else
    {
        printPath(parent[node], parent);
        cout << node << " ";
    }
}
void dijkstra(vector< pair< int , int > > Graph[], int v, int src)
{
    int distance[v];
    for(int i=0; i<v; i++) distance[i] = INF;

    int parent[v];
    for(int i=0; i<v; i++) parent[i] = i;

    auto cmp = [&](nDistance a, nDistance b)
    {
        if(a.distance<=b.distance) return false;
        else return true;
    };

    priority_queue< nDistance, vector< nDistance >, decltype(cmp) > PQ(cmp);

    distance[src] = 0;
    PQ.push({src, distance[src]});

    while(PQ.empty() == false)
    {
        nDistance temp = PQ.top();
        PQ.pop();

        int currentNode = temp.node;

        for(pair< int , int > neighbor : Graph[currentNode])
        {
            if(distance[neighbor.first]>distance[currentNode] + neighbor.second)
            {
                distance[neighbor.first] = distance[currentNode] + neighbor.second;
                PQ.push({neighbor.first, distance[neighbor.first]});
                parent[neighbor.first] = currentNode;
            }
        }
    }
    for(int i=0; i<v; i++)
    {
        cout << src << "->" << i << ": " << distance[i] << " Path: ";
        printPath(i, parent);
        cout << endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector< pair< int , int > > Graph[v];
    for(int i=0; i<e; i++)
    {
        int from, to, cost; cin >> from >> to >> cost;
        Graph[from].push_back({to, cost});
    }
    int src;
    cin >> src;
    dijkstra(Graph, v, src);

    return 0;
}

