#include <iostream>
#include <algorithm>

using namespace std;

bool check(int l[], char *f[], int *ald[]);
void clearField(char *f[], int *ald[]);
bool canPut(char *f[], int x, int y);
bool on(int x, int y);
void printF(char *f[]);

int ALD = 3;
int N = 8;

int main(){
  int l[N];
  char *input[N];
  int *ald[ALD];
  for(int i = 0; i < ALD; i++){
    ald[i] = new int[2];
  }

  for(int i = 0; i < N; i++){
    input[i] = new char[N];
    cin >> input[i];
    l[i] = i;
  }

  //既に置かれている場所をマーク
  int aldtmp = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N;j++){
      if(input[i][j] == 'Q'){
        ald[aldtmp][0] = i;
        ald[aldtmp][1] = j;
        aldtmp++;
      }
    }
  }


  bool succ = false;
  do{
    if(check(l, input, ald)){
      printF(input);
      succ = true;
      break;
    }
    clearField(input, ald);
  }while(next_permutation(l, l + N));

  if(!succ) cout << "No Answer" << endl;
}

bool check(int l[], char *f[], int *ald[]){
  int aldn = 0;
  //既に置かれているコマをカバーしているか
  for(int i = 0; i < N; i++){
    int x = l[i];
    int y = i;
    if(f[y][x] == 'Q') aldn++;
    f[y][x] = 'Q';
  }

  //三つともカバーしていなければ失敗
  if(aldn == ALD){
    for(int y = 0; y < N; y++){
      int x = l[y];
      if(!canPut(f, x, y)){
        return false;
      }
    }
    return true;
  }
  return false;
}

void clearField(char *f[], int *ald[]){
  for(int y = 0; y < N; y++){
    for(int x = 0; x < N; x++){
      f[y][x] = '.';
    }
  }
  for(int i = 0; i < ALD; i++){
    int y = ald[i][0];
    int x = ald[i][1];
    f[y][x] = 'Q';
  }
}

bool canPut(char *f[], int x, int y){
  for(int dx = -1; dx <= 1; dx++){
    for(int dy = -1; dy <= 1; dy++){
      if(dx == 0 || dy == 0) continue;
      int nx = x + dx;
      int ny = y + dy;
      while(on(nx, ny)){
        if(f[ny][nx] == 'Q') return false;
        nx += dx;
        ny += dy;
      }
    }
  }
  return true;
}

bool on(int x, int y){
  return 0 <= x && x < N && 0 <= y && y < N;
}

void printF(char *f[]){
  for(int y = 0; y < N; y++){
    for(int x = 0; x < N; x++){
      cout << f[y][x];
    }
    cout << endl;
  }
}
