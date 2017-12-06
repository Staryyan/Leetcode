// A C++ program to find strongly connected components in a given
// directed graph using Tarjan's algorithm (single DFS)
#include <iostream>
#include <list>
#include <stack>
#include <vector>
#define NIL -1
using namespace std;
 
// // A class that represents an directed graph
// class Graph
// {
//     int V;    // No. of vertices
//     list<int> *adj;    // A dynamic array of adjacency lists
 
//     // A Recursive DFS based function used by SCC()
//     vector<int> SCCUtil(int u, int disc[], int low[],
//                  stack<int> *st, bool stackMember[]);
// public:
//     Graph(int V);   // Constructor
//     void addEdge(int v, int w);   // function to add an edge to graph
//     int SCC();    // prints strongly connected components
// };
 
// Graph::Graph(int V)
// {
//     this->V = V;
//     adj = new list<int>[V];
// }
 
// void Graph::addEdge(int v, int w)
// {
//     adj[v].push_back(w);
// }
 
// // A recursive function that finds and prints strongly connected
// // components using DFS traversal
// // u --> The vertex to be visited next
// // disc[] --> Stores discovery times of visited vertices
// // low[] -- >> earliest visited vertex (the vertex with minimum
// //             discovery time) that can be reached from subtree
// //             rooted with current vertex
// // *st -- >> To store all the connected ancestors (could be part
// //           of SCC)
// // stackMember[] --> bit/index array for faster check whether
// //                  a node is in stack
// vector<int> Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st,
//                     bool stackMember[])
// {
//     // A static variable is used for simplicity, we can avoid use
//     // of static variable by passing a pointer.
//     static int time = 0;
 
//     // Initialize discovery time and low value
//     disc[u] = low[u] = ++time;
//     st->push(u);
//     stackMember[u] = true;
 
//     // Go through all vertices adjacent to this
//     list<int>::iterator i;
//     for (i = adj[u].begin(); i != adj[u].end(); ++i)
//     {
//         int v = *i;  // v is current adjacent of 'u'
 
//         // If v is not visited yet, then recur for it
//         if (disc[v] == -1)
//         {
//             SCCUtil(v, disc, low, st, stackMember);
 
//             // Check if the subtree rooted with 'v' has a
//             // connection to one of the ancestors of 'u'
//             // Case 1 (per above discussion on Disc and Low value)
//             low[u]  = min(low[u], low[v]);
//         }
 
//         // Update low value of 'u' only of 'v' is still in stack
//         // (i.e. it's a back edge, not cross edge).
//         // Case 2 (per above discussion on Disc and Low value)
//         else if (stackMember[v] == true)
//             low[u]  = min(low[u], disc[v]);
//     }
 
//     // head node found, pop the stack and print an SCC
//     vector<int> circle;
//     int w = 0;  // To store stack extracted vertices
//     if (low[u] == disc[u])
//     {
//         while (st->top() != u)
//         {
//             w = (int) st->top();
//             circle.push_back(w);
//             stackMember[w] = false;
//             st->pop();
//         }
//         w = (int) st->top();
//         circle.push_back(w);
//         stackMember[w] = false;
//         st->pop();
//     }
//     return circle;
// }
 
// // The function to do DFS traversal. It uses SCCUtil()
// int Graph::SCC()
// {
//     int *disc = new int[V];
//     int *low = new int[V];
//     bool *stackMember = new bool[V];
//     stack<int> *st = new stack<int>();
 
//     // Initialize disc and low, and stackMember arrays
//     for (int i = 0; i < V; i++)
//     {
//         disc[i] = NIL;
//         low[i] = NIL;
//         stackMember[i] = false;
//     }
 
//     // Call the recursive helper function to find strongly
//     // connected components in DFS tree with vertex 'i'
//     bool flag = false;
//     int total = 0;
//     for (int k = 0; k < V; k++) {
//         if (disc[k] == NIL) {
//             vector<int> circle = SCCUtil(k, disc, low, st, stackMember);
//             flag = false;
//             for (int j = 0; j < circle.size(); j++) {
//     			for (list<int>::iterator i = adj[circle[j]].begin(); i != adj[circle[j]].end(); ++i) {
// 			        int v = *i;
// 			        if (find(circle.begin(), circle.end(), v) == circle.end()) {
// 			        	flag = true;
// 			        	break;
// 			        }
//                 }
// 			    if (flag) {
// 			    	break;
// 			    }
//             }
//             if (!flag) {
//             	total++;
//             }
//         } else {
//         	if (adj[k].size() == 0) {
//         		total++;
//         	}
//         }
//     }
//     return total;
// }

// class Solution {
// public:
//     int minLeftMonsters(vector<vector<char>> G) {
//     	int m = G.size();
// 	    Graph g5(m);
//     	for (int i = 0; i < m; i++) {
//     		for (int j = 0; j < m; j++) {
//     			if (G[i][j] == '+') {
//     				g5.addEdge(i, j);
//     			}
//     		}
//     	}
//     	return g5.SCC();
// 	}
// };

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Vertex {
    Vertex() : lowlink(-1), index(-1), sc(-1), onStack(false) {}
    int lowlink;
    int index;
    int sc;
    bool onStack;
    vector<int> succ;
};

typedef vector<Vertex> Graph;

class Solution {
  public:
    int minLeftMonsters(vector<vector<char>> m) {
        int n = m.size();
        Graph graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (m[i][j] == '-') {
                    graph[i].succ.push_back(j);
                }
            }
        }
        stack<int> stk;
        index = 0;
        scn = 0;
        for (int i = 0; i < n; ++i) {
            if (graph[i].index < 0) {
                strongConnect(graph, i, stk);
            }
        }
        vector<bool> result(scn, true);
        for (int i = 0; i < n; ++i) {
            for (int v : graph[i].succ) {
                if (graph[v].sc != graph[i].sc) {
                    result[graph[v].sc] = false;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < result.size(); ++i) {
            if (result[i]) {
                ++ret;
            }
        }
        return ret;
    }

    void strongConnect(Graph &g, int v, stack<int> &stk) {
        g[v].index = index;
        g[v].lowlink = index;
        ++index;
        g[v].onStack = true;
        stk.push(v);

        for (int w : g[v].succ) {
            if (g[w].index < 0) {
                strongConnect(g, w, stk);
                g[v].lowlink = min(g[v].lowlink, g[w].lowlink);
            } else if (g[w].onStack) {
                g[v].lowlink = min(g[v].lowlink, g[w].index);
            }
        }

        if (g[v].lowlink == g[v].index) {
            int w;
            g[v].sc = scn;
            do {
                w = stk.top();
                stk.pop();
                g[w].onStack = false;
                g[w].sc = scn;
            } while (w != v);
            ++scn;
        }
    }

    int count;
    int index;
    int scn;
};
int main() {
	vector<vector<char>> G{ {'0'} };
	Solution so;
    cout << so.minLeftMonsters(G) << endl;
	return 0;
}
