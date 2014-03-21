#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int main(){
  int A = 0;
  int B = 0;
  int tmp[6] = {1, 5, 10, -1, -5, -10};
  queue<p> q;

  cin >> A >> B;
  q.push(p(A, 0));
  while(!q.empty()){
    p n = q.front();q.pop();
    if(B == n.first){
      cout << (n.second) << endl;
      return 0;
    }
    for(int i = 0; i < 6; i++){
      q.push(p(n.first + tmp[i], n.second + 1));
    }
  }
}
