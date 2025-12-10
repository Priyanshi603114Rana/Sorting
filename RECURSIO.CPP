//RECURSSION :- A function can call itself again and again for a condition

#include <stdio.h>
#include <conio.h>

int fact(int);

int main(){
  int n,ft;
  clrscr();
  printf("Enter number : ");
  scanf("%d",&n);
  ft = fact(n);
  printf("Factorial of %d = %d\n",n,ft);
  getch();
  return 0;
}

int fact(int t){
  if(t==0){
    return 1;
  }
  else{
    return(t*fact(t-1));
  }
}