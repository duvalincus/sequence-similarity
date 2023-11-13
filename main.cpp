#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

typedef enum {up, left, diagonal} direction;

struct letter {
  double val;
  direction d;
};

int main() {
  /*A   C   G   T
  A 1 -.1 -.1 -.15
  C     1 -.15 -.1
  G         1  -.1
  T              1
  */
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
        dp[i][j].d = direction::diagonal;
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
          dp[i][j].d = direction::up;
        }
        else if (max == ins) {
          dp[i][j].d = direction::left;
        }
        else dp[i][j].d = direction::diagonal;
      }
    }
  }
  score = dp[y-1][x-1].val;

  //print alignment
  x--;
  y--;
  while (x > 0 && y > 0) {
    if (dp[y][x].d == direction::up) {
      newA.insert(x, "-");
      y--;
    }
    else if (dp[y][x].d == direction::left) {
      newB.insert(y, "-");
      x--;
    }
    else if (dp[y][x].d == direction::diagonal) {
      x--;
      y--;
    }
  }
  std::cout << score << std::endl << newA << std::endl << newB << std::endl;
  return 0;
}
