#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  int a, b;
  cin >> a >> b;
  int n = a - b + 1;
  vector<int> fizz, buzz, nums;
  for (int i = a; i <= b; i++) {
    string t;
    cin >> t;
    if (t == "FizzBuzz") {
      fizz.push_back(i);
      buzz.push_back(i);
    } else if (t == "Fizz")
      fizz.push_back(i);
    else if (t == "Buzz")
      buzz.push_back(i);
    else
      nums.push_back(i);
  }
  int gcdfizz = b + 1;
  if (!fizz.empty())
    gcdfizz = fizz[0];
  int gcdbuzz = b + 2;
  if (!buzz.empty())
    gcdbuzz = buzz[0];

  for (auto x : fizz)
    gcdfizz = gcd(gcdfizz, x);

  for (auto x : buzz)
    gcdbuzz = gcd(gcdbuzz, x);

  cout<<gcdfizz<<" "<<gcdbuzz<<"\n";
  
}