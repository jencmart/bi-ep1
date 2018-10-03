#include <iostream>
#include <vector>
#include <set>

using namespace std;


void dfs(int i, int j, vector<vector<char>> &graph, set<int> &visited, char current);


int colG;
int rowG;


int wolfCount, sheepCount, side;
int main()
{

    for(; ; )
    {
        ///SCAN GRAPH INFO
        unsigned row, col, numOfCervotocs;
        char dummy;
        scanf("%d%d%d\n", &row, &col, &numOfCervotocs);
        string dummy2;
        colG = col;
        rowG = row;

        /// SCAN CERV NAMES
        vector<pair<char, int>> cervove;
        for (int i = 0; i < numOfCervotocs; ++i)
        {
            char cervName;
            scanf("%c", &cervName);
            cervove.push_back(make_pair(cervName, 0));
            getline(cin, dummy2);
        }

        /// SCAN GRAPH
        vector<vector<char>> graph(row, vector<char>(col));
        set<int> visited;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                char c;
                scanf("%c", &c);
                if (c == '*')
                    visited.insert(i * col + j + 1);
                for( auto &cerv : cervove)
                {
                    if (cerv.first == c) {
                        cerv.second += 1;
                        break;
                    }

                }
                graph[i][j] = c;
            }
            getline(cin, dummy2);
        }

     /**
      *    ///SEARCH GRPH FOR CERVS
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                /// pokud jeste nebyl prohledany tento bod a ani to neni zed...
                if (visited.count(i * col + j + 1) != 1) {
                    for (auto &x : cervove) {
                        if (x.first == graph[i][j]) {
                            x.second += 1;
                            break;
                        }
                    }
                    dfs(i, j, graph, visited, graph[i][j]);
                }
            }
        }

      */
        for( auto cerv : cervove)
        {
            cout << cerv.first << ": " <<cerv.second <<endl;
        }

        int a, b, c;
        if( scanf("%d%d%d", &a, &b, &c) != 3)
            break;
    }
}

void dfs(int i, int j, vector<vector<char>> &graph, set<int> &visited, char current)
{
    if(visited.count(i*colG+j+1) || graph[i][j] != current)
        return;

    visited.insert(i*colG+j+1);

    if(j-1 >= 0)
        dfs(i, j-1, graph, visited, current);

    if(i-1 >= 0)
        dfs(i-1, j, graph, visited, current);

    if(j+1 < colG)
        dfs(i,j+1, graph, visited, current);

    if(i+1 < rowG)
        dfs(i+1, j, graph, visited, current);

    if( i-1 >= 0 && j-1 >= 0)
        dfs(i-1, j-1, graph, visited, current);

    if(i-1 >= 0 && j+1 < colG)
        dfs(i-1, j+1, graph, visited, current);

    if(i+1 < rowG && j-1 >=0)
        dfs(i+1, j-1, graph, visited, current);

    if(i+1 < rowG && j+1 < colG)
        dfs(i+1, j+1, graph, visited, current);
}