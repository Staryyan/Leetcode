#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 100000000));
        dp[M][N - 1] = 1;
        dp[M - 1][N] = 1;
        for (int i = M - 1; i >= 0; i--) {
        	for (int j = N - 1; j >= 0; j--) {
        		int need = min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
        		dp[i][j] = need <= 0 ? 1 : need;
        	}
        }
        return dp[0][0];
    }
};


struct Node {
	int M;
	int N;
	int MinHP;
	int CurMP;
	Node() {
		M = 0;
		N = 0;
		MinHP = 1;
		CurMP = 1;
	}
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        int minHP = 1000000000;
        vector<vector<int>> MinHP_records = vector<vector<int>>(M, vector<int>(N, 100000000));
        vector<vector<int>> CurHP_records = vector<vector<int>>(M, vector<int>(N, 100000000));
        Node knight;
        queue<Node> states;
        states.push(knight);
        while (!states.empty()) {
        	knight = states.front();
        	states.pop();
        	if (dungeon[knight.M][knight.N] < 0) {
        		if (knight.CurMP <= -dungeon[knight.M][knight.N]) {
        			knight.MinHP += -dungeon[knight.M][knight.N] - knight.CurMP + 1;
        			knight.CurMP = 1;
        		} else {
        			knight.CurMP += dungeon[knight.M][knight.N];
        		}
        	} else {
        		knight.CurMP += dungeon[knight.M][knight.N];
        	}
        	if (MinHP_records[knight.M][knight.N] > knight.MinHP || CurHP_records[knight.M][knight.N] < knight.CurMP) {
        		MinHP_records[knight.M][knight.N] = min(MinHP_records[knight.M][knight.N], knight.MinHP);
        		CurHP_records[knight.M][knight.N] = max(CurHP_records[knight.M][knight.N], knight.CurMP);
	        	if (knight.M == M - 1 && knight.N == N - 1) {
	        		if (minHP > knight.MinHP) {
	        			minHP = knight.MinHP;
	        		}
	        	} else {
	        		if (knight.M != M - 1) {
	        			Node downNode;
	        			downNode.M = knight.M + 1;
	        			downNode.N = knight.N;
	        			downNode.MinHP = knight.MinHP;
	        			downNode.CurMP = knight.CurMP;
	        			states.push(downNode);
	        		}
	        		if (knight.N != N - 1) {
	        			Node rightNode;
	        			rightNode.M = knight.M;
	        			rightNode.N = knight.N + 1;
	        			rightNode.MinHP = knight.MinHP;
	        			rightNode.CurMP = knight.CurMP;
	        			states.push(rightNode);
	        		}
	        	}
	        }
        }
        return minHP;
    }
};