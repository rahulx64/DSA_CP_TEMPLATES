#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int> adj[maxn];
vector<int> intime(maxn);
vector<int> outtime(maxn);
vector<int> euler_tour;
int timer=0;
void dfs(int node,int par)
{
     intime[node]=timer++;
     euler_tour.push_back(node);
     for(auto it:adj[node])
     {
          if(it != par)
          {
               dfs(it,node);
          }
     }
     outtime[node]=timer++;
     euler_tour.push_back(node);
}

int main()
{
     int n; // Number of nodes
     cin >> n;

     // Input tree edges
     for (int i = 0; i < n - 1; i++)
     {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     // Perform Euler Tour starting from root (node 1)
     dfs(1, -1);

     // Print Euler Tour
     cout << "Euler Tour: ";
     for (int node : euler_tour)
     {
          cout << node << " ";
     }
     cout << endl;

     // Print in-time and out-time
     cout << "In-Time and Out-Time:\n";
     for (int i = 1; i <= n; i++)
     {
          cout << "Node " << i << ": " << intime[i] << " " << outtime[i] << endl;
     }

     return 0;
}
