#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	void generate(vector<string> &answer, vector<vector<int>>& tables, int cur, string str, string& s) {
		if (cur == 0) {
			answer.push_back(str.substr(1, str.size() - 1));
		} else {
			for (int i = 0; i < tables[cur].size(); i++) {
				string ano = " " + s.substr(tables[cur][i], cur - tables[cur][i]) + str;
				generate(answer, tables, tables[cur][i], ano, s);
			}
		}
	}
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> tables(s.size() + 1, vector<int>());
        tables[0].push_back(0);
        for (int i = 1; i <= s.size(); i++) {
        	for (int j = i - 1; j >= 0; j--) {
        		if (tables[j].size() != 0) {
        			string word = s.substr(j, i - j);
        			if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
        				tables[i].push_back(j);
        			}
        		}
        	}
        }
        vector<string> answer;
        string str = "";
        generate(answer, tables, s.size(), str, s);
        return answer;
    }
};

int main() {
	string s = "catsanddog";
	vector<string> wordDict{"cat","cats","and","sand","dog"};
	Solution so;
	so.wordBreak(s, wordDict);
}