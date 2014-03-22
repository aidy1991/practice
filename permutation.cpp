#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
  int N = 4;
  int list[N];
  for(int i = 0; i < N; i++){
    list[i] = i + 1;
  }

  do{
    for(int i = 0; i < N; i++){
      cout << list[i] << " ";
    }
    cout << endl;
  }while(next_permutation(list, list + N));

}
