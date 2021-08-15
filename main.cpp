//
// Created by Kylian Lee on 2021/08/15.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <deque>

using namespace std;

int main(){
  int case_num;
  scanf("%d", &case_num);
  for (int i = 0; i < case_num; ++i) {
    deque<int> dq;
    char cmd[100001];
    int temp, tmp = 0;
    scanf("%s", cmd);
    scanf("%d", &temp);
    getchar();
    while(true){
      char ch = getchar();
      if(ch == '\n')
        break;
      else if(ch >= '0' && ch <= '9'){
        tmp *= 10;
        tmp += ch - '0';
      }
      else if(ch == ',' || ch == ']'){
        dq.push_back(tmp);
        tmp = 0;
      }
    }   //  덱에 숫자 enqueue
    if(temp == 0)
      dq.pop_back();
    bool reversed = false, flag = false;
    for (int j = 0; j < strlen(cmd); ++j) {
      if(cmd[j] == 'R')
        reversed = !reversed;
      else{
        if(dq.empty()){
          flag = true;
          break;
        }
        if(reversed)
          dq.pop_back();
        else
          dq.pop_front();
      }
    }
    if(flag){
      printf("error\n");
      continue;
    }
    if(dq.empty()){
      printf("[]\n");
      continue;
    }
    if(reversed){
      printf("[");
      for (int j = dq.size() - 1; j > 0; --j)
        printf("%d,", dq[j]);
      printf("%d]\n", dq[0]);
    }
    else{
      printf("[");
      for (int j = 0; j < dq.size() - 1; ++j)
        printf("%d,", dq[j]);
      printf("%d]\n", dq[dq.size() - 1]);
    }
  }
  return 0;
}