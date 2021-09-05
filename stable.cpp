/*
Notes before starting:
  0 is the most preferable, 2 is the least (for a 3 men and woman)
*/
#include <iostream>
using namespace std;

struct Solution{

  int n = 3;
  int m[3] = {}; 
  int mp[3][3] = {{0,2,1},  
                  {0,2,1},
                  {1,2,0}};   
  
  int wp[3][3] = {{2,1,0},
                  {0,1,2},
                  {2,0,1}};
                  
  void printMatching(){
    for ( int i = 0; i < n; i++ ){
      cout << "male: " << i << " and female: " << m[i] << endl;
    }
    cout << endl;
  }

  bool isAlreadyTaken(int c){
    for (int i = 0; i < c; i++){
        if (m[c]==m[i]){
            return true;
        }
    }
    return false;
  }
// 1=c 0=i
  bool isStable(int c){
      for (int i = 0; i < c; i++){
          if (mp[c][m[i]] < mp[c][m[c]] && wp[m[i]][c] < wp[m[i]][i] || mp[i][m[c]] < mp[i][m[i]] && wp[m[c]][i] < wp[m[c]][c] ){
              return false;
          }
      }
      return true;
    
  }


  bool ok(int currMale){
    if (!isAlreadyTaken(currMale) and isStable(currMale)){
      return true;
    }
    else{
      return false;
    }
  }


  void solve(){

    //Start with the first male
    int c = 0;
    // While we have not backtracked beyond the first male:
    while (c>-1){
      
      // If all the people have been matched, 
      if(c>2){
        // print 
        printMatching();
        // backtrack
        c--;
        if (c==-1){
            return;
        }
        m[c]++;
        continue;
      }

      // If the current male has been matched with all the avalible women
      if (m[c]>2){
        //reset current male
        m[c]=0;
        //backtrack
        c--;
        if (c==-1){
            return;
        }
        m[c]++;
        continue;
      }

      //check if the matching is stable
      if( ok(c) ){
          // move to the next man
          c++;

      }
      else{
        // pair the man with the next avalible woman
        m[c]++;

      }
    }
  }



};



int main() {
  Solution s;
  s.solve();
  cout << "finished" <<endl;
}