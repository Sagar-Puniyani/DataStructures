#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
template <typename T>

class graph
{
public:
    unordered_map<T, list<T>> adj;
    void AddEdge(T u, T v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdj()
    {
        for (auto [key, value] : adj)
        {
            cout << key << "-> ";
            for (auto item : value)
            {
                cout << item<< ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph<int> g;

    int m;
    cout << "Enter the No. of Edges : " << endl;
    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.AddEdge(u, v, 0);
    }

    g.printAdj();

    return 0;
}