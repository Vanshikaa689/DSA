#include<iostream>
using namespace std;
#include<vector>
#include<queue>
int rottenoranges(vector<vector<int>>grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int> ,int>> q;
    int vis[n][m];
    int i, j;
    int count;
    int cntfresh= 0;
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<m; j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i, j}, 0});
                vis[i][j]=2;
            }
            else
            {
                vis[i][j] = 0;
            }
            if(grid[i][j]==1)
            {
                cntfresh++;
            }
        }
    }
    int tm = 0;
    int drow[]= {-1, 0, +1, 0};
    int dcol[]= {0, +1, 0, -1};
    int cnt = 0;
    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        for(i = 0; i<4; i++)
        {
            int nr = r+drow[i];
            int nc = c+dcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1)
            {
                vis[nr][nc] = 2;
                q.push({{nr, nc}, t+1});
                cnt++;
            }
        }
    }
        if(cnt!=cntfresh)
        {
            return -1;
        }
        else
        {
            return tm;
        }
    
}
int main()
{
    vector<vector<int>>grid{{0, 1, 2},{0, 1, 2}, {2, 1, 1}};
    cout<<rottenoranges(grid);
}
