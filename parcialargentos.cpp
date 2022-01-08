#include <iostream>


using namespace std;

int main(){

  int a = 1;
  int b = 2;
  int c = 0;

  while(a < 10 && b < 8){
      c+=a+b;

      a++;
      b++;
  }


  cout << c << endl;

    return 0;
} 