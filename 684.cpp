#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int unionFind(int index, vector<int>& sets) {
      if (sets[index] == index) {
        return index;
      } else {
        sets[index] = unionFind(sets[index], sets);
        return sets[index];
      }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      vector<vector<int>> records = edges;
      sort(records.begin(), records.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
      });

      int size = edges.size();
      vector<int> sets(size + 1, 0);
      for (int i = 0; i <= size; i++) {
        sets[i] = i;
      }
      vector<int> result;
      for (auto each : records) {
        if (unionFind(each[0], sets) != unionFind(each[1], sets)) {
          sets[each[1]] = unionFind(each[0], sets);
        }
      }
      for (auto each : edges) {
        if (unionFind(each[0], sets) == unionFind(each[1], sets)) {
          result = each;
          break;
        }
      }

      return result;
    }
};

int main() {
  std::vector<std::vector<int>> v{{1,4},{3,4},{1,3},{1,2},{4,5}};
  Solution so;
  std::vector<int> result = so.findRedundantConnection(v);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}
