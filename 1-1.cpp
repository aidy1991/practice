#include <iostream>

using namespace std;

int main(){
  int N = 0;
  int MAXANS = 4;
  int *check = new int[MAXANS];
  fill(check, check + MAXANS, 0);
  char *ans;
  cin >> N;
  ans = new char[N];
  cin >> ans;
  for(int i = 0; i < N; i++){
    check[ans[i] - '0']++;
  }

  int mx = 0;
  int mn = 100000;
  for(int i = 1; i < MAXANS; i++){
    mx = max(mx, check[i]);
    mn = min(mn, check[i]);
  }
  cout << mx << " " << mn << endl;
}
