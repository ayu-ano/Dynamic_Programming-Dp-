
// oTHER way of memoization but gfg gives tle but coding ninjas accepted this solution 
#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int>mp;
#define mod 1000000007
int Evaluate_Expression_To_True(string &exp, int i, int j , bool istrue){

   if(i > j){
       return 0;
   }

   if(i == j){
      if (istrue) {
            return exp[i] == 'T' ? 1 : 0;
        } else {
            return exp[i] == 'F' ? 1 : 0;
        }
    }
      string temp = to_string(i);
      temp.push_back(' ');
      temp.append(to_string(j));
      temp.push_back(' ');
       temp.append(to_string(istrue));


       if(mp.find(temp)!= mp.end()){
           return mp[temp];
       }

    long long ans = 0;

    for(int k = i + 1; k <= j - 1; k += 2){  // k is the operator position
      long long leftT = Evaluate_Expression_To_True(exp, i, k - 1, true);
      long long leftF = Evaluate_Expression_To_True(exp, i, k - 1, false);
      long long rightT = Evaluate_Expression_To_True(exp, k + 1, j, true);
      long long rightF = Evaluate_Expression_To_True(exp, k + 1, j, false);
      
      if (exp[k] == '|') {
          // T | T = T, T | F = T, F | T = T, F | F = F.
          if (istrue) {
              ans += (leftT * rightT + leftT * rightF + leftF * rightT) % mod;
          } else {
              ans += (leftF * rightF) % mod;
          }
      } 
      else if (exp[k] == '&') {
          // T & T = T, T & F = F, F & T = F, F & F = F.
          if (istrue) {
              ans += (leftT * rightT) % mod;
          } else {
              ans += (leftT * rightF + leftF * rightT + leftF * rightF) % mod;
          }
      } 
      else if (exp[k] == '^') {
          // T ^ T = F, T ^ F = T, F ^ T = T, F ^ F = F.
          if (istrue) {
              ans += (leftT * rightF + leftF * rightT) % mod;
          } else {
              ans += (leftT * rightT + leftF * rightF) % mod;
          }
      }
      ans %= mod;
    }
    
    return mp[temp]= ans;
}


     

int evaluateExp(string & exp) {
    // Write your code here.
    mp.clear();
    int n = exp.size();
    return Evaluate_Expression_To_True(exp,0,n-1,true);
}

int main() {
    // Hardcoded expression
    string expression = "T|F&T^F";  // You can modify this expression to test other cases.
    
    // Output the number of ways to evaluate the expression to true
    cout << "Number of ways to evaluate expression to True: " << evaluateExp(expression) << endl;

    return 0;
}