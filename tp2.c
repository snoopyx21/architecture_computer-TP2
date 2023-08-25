#include <stdio.h>
#include <stdlib.h>

#define BIT(A,B) ((A>>B)&0x1)
#define OR(A,B) (A||B)
#define AND(A,B) (A&&B)
#define NOT(A) (!A)
#define XOR(A,B) (((!A) && B) || (A &&(!B)))

long long int P2(int n) {
  return (n<0?0:(n==0?1 : 2*P2(n-1)));
}

///exo2
int F2(int args){
  return XOR(BIT(args,0),BIT(args,1));
}

int F3(int args){
  return OR( AND(BIT(args,0),NOT(BIT(args,1))), (OR(AND(BIT(args,1),NOT(BIT(args,2))), AND(NOT(BIT(args,1)),BIT(args,2)))));
}

int F4(int args){
  return OR(XOR(AND(AND(BIT(args,0),BIT(args,1)),NOT(BIT(args,2))),AND(AND(BIT(args,0),NOT(BIT(args,1))),BIT(args,2))),AND(BIT(args,2),NOT(BIT(args,3))));
}

///exo3

void verite2var( int (*func) (int) ){
  int nbvar=2;
  int max=P2(nbvar);
  int i,j;
  printf("A|B|F(A,B) \n");
  printf("---|---|------ \n");
  for(i=0;i<max;i++){
    for(j=0;j<nbvar;j++)
      printf("%d|",BIT(i,j));
  printf("%d \n",func(i));
  }
}

///exo4

void veriteNvar(int N, int (*func) (int) ){
  int nbvar=N;
  int max=P2(N);
  int i,j;
  for(j=0;j<nbvar;j++){ printf("X%d|",j);
  printf("X0,....,X%d",j-1);}
  for(j=0;j<nbvar;j++) printf("----");
  printf("-----------");
  for(i=0;i<max;i++){
    for(j=0;j<nbvar;j++) printf("%d |",BIT(i,j));
  }
  printf("%d \n",func(i));
}

///exo5

void disjonctive( int N, int (*func) (int)) {
int nbvar = N;
int max = P2(nbvar);
int i,j;
int nbplus=0;
for (i=0; i<max; i++)
    if (func(i)==1)
        nbplus++;
for (i=0; i<max; i++){
    if(func(i)==1){
    for(j=0; j<nbvar; j++){
        if (BIT(i,j)==1)
            printf("X%d",j);
        else
            printf("!X%d",j);}
    if (nbplus>1)
        printf("+");
    nbplus--;
    }   
    }
    printf("\n");
}



void conjonctive( int N, int (*func) (int)) {
int nbvar = N;
int max = P2(nbvar);
int i,j;
int nbpoint=0;
for (i=0; i<max; i++)
    if (func(i)==1)
        nbpoint++;
for (i=0; i<max; i++){
    if(func(i)==1){
    for(j=0; j<nbvar; j++){
        if (BIT(i,j)==1)
            printf("X%d+",j);
        else
            printf("!X%d+",j);}
    if (nbpoint>1)
        printf(".");
    nbpoint--;
    }   
    }
    printf("\n");
}

//c'est mon main
int main(){
  int nbvar=4;
  int max=P2(nbvar);
  int i,j;
  for(i=0;i<max;i++){
    for(j=0;j<nbvar;j++)
      printf("%d",BIT(i,j));
  printf("\n");
  }
  int arg=1;
  printf("F2 ( %d ,%d ) = %d \n",BIT(arg,0),BIT(arg,1),F2(arg));
  arg=7;
  printf("F3 ( %d , %d , %d ) = %d \n",BIT(arg,0),BIT(arg,1),BIT(arg,2),F3(arg));
  arg=8;
  printf("F4 ( %d, %d, %d , %d ) = %d \n",BIT(arg,0),BIT(arg,1),BIT(arg,2),BIT(arg,3),F4(arg));
  //verite2var(F2);
  //veriteNvar(7,F3);
  //veriteNvar(8,F4);
  conjonctive(2,F2);
  conjonctive(3,F3);
  disjonctive(2,F2);
  disjonctive(3,F3);
  return 0;
}
