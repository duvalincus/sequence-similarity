#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


struct letter {
  double val;
  char d = 'o';
};

int main() {
  /*A   C   G   T
  A 1 -.1 -.1 -.15
  C     1 -.15 -.1
  G         1  -.1
  T              1
  */
 //AGTACCGTAACTGTCAGT
 //AGCACGTTAGCAGTTGAT
  int x,y;
  double score = 0;
  double penalty = -.1;
  std::string a, b;
  std::cin >> a >> b;
  std::string newA = a;
  std::string newB = b;
  x = a.size() + 1;
  y = b.size() + 1;
  letter dp[y][x];
  for (int i = 0; i < x; i++) {
    dp[0][i].val = (-.2 *i);
  }
  for (int i = 0; i < y; i++) {
    dp[i][0].val = (-.2 * i);
  }
  for (int i = 1; i < y; i++) {
    for (int j = 1; j < x; j++) {
      char aChar = a[j-1];
      char bChar = b[i-1];
      //matching
      if (aChar == bChar) {
        dp[i][j].val = (dp[i-1][j-1].val + 1);
        dp[i][j].d = 'd';
      }
      else {
        //replace
        if (aChar == 'A' && bChar == 'C' || 
            bChar == 'A' && aChar == 'C' || 
            aChar == 'A' && bChar == 'G' || 
            bChar == 'A' && aChar == 'G' || 
            aChar == 'C' && bChar == 'T' || 
            bChar == 'C' && aChar == 'T' ||
            aChar == 'T' && bChar == 'G' || 
            bChar == 'T' && aChar == 'G') {
          penalty = -.1;
        }
        else if (aChar == 'A' && bChar == 'T' || 
                 bChar == 'A' && aChar == 'T' || 
                 aChar == 'C' && bChar == 'G' || 
                 bChar == 'C' && aChar == 'G') {
          penalty = -.15;
        }
        else {
          penalty = -.15;
        }
        double rep = dp[i-1][j-1].val + penalty;
        double ins = dp[i][j-1].val - 0.2; //insertion
        double del = dp[i-1][j].val - 0.2; //deletion
        double max = std::max({rep, ins, del});
        dp[i][j].val = max;
        if(max == del) {
          dp[i][j].d = 'u';
        }
        else if (max == ins) {
          dp[i][j].d = 'l';
        }
        else dp[i][j].d = 'd';
      }
    }
  }
  x--;
  y--;
  score = dp[y][x].val;

  //print alignment
  while (x > 0 && y > 0) {
    if (dp[y][x].d == 'u') {
      newA.insert(x, "-");
      y--;
    }
    else if (dp[y][x].d == 'l') {
      newB.insert(y, "-");
      x--;
    }
    else if (dp[y][x].d == 'd') {
      x--;
      y--;
    }
  }
  while (x > 0) {
    newA.insert(x-1, "-");
    x--;
  }
  while (y > 0) {
    newA.insert(y-1, "-");
    y--;
  }
  std::cout << score << std::endl << newA << std::endl << newB << std::endl;
  return 0;
}
