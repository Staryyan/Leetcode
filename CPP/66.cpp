#include <iostream>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
    digits[digits.size() - 1]++;
    for (int i = digits.size() - 1; i >= 1; i--) {
      if (digits[i] >= 10) {
        digits[i] -= 10;
        digits[i-1]++;
      }
    }
    if (digits[0] >= 10) {
      digits[0] = 0;
      digits.insert(digits.begin(), 1);
    }
    return digits;
}
int main(int argc, char const *argv[]) {
  std::vector<int> digits{9,9,9};
  plusOne(digits);
  for (auto each : digits) {
    cout << each << endl;
  }
  return 0;
}
