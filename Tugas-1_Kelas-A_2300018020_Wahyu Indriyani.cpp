#include<iostream>
using namespace std;

int main()
{
  for ( int w=0; w<=9; w++){
    for (int x=0; x<=9; x++){
      if ( w==0 || w==3 || w==6 || w==9|| x==0 || x==3 || x==6 || x==9){
        cout << " * ";
      } else {
        cout << "   ";
      }
    }
    cout << endl;
  }
  return 0;
}
