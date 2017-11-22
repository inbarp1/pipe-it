#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
  //setting stuff up
  int pen = 1;
  int book = 0;
  int padre[2];
  int nino[2];
  pipe(nino);
  pipe(padre);
  //if it is the child
  if(fork()==0){
    int mathme;
    close(padre[pen]);
    close(nino[book]);
    read(padre[book], &mathme, sizeof(mathme));
    printf("Child doing maths on: %d\n", mathme);
    mathme = mathme * 3 + 5;
    // doin math! 
    write(nino[pen], &mathme, sizeof(mathme));
  }
  //if it is a parent
  else{
    close(nino[pen]);
    close(padre[book]);
    int tomath;
    tomath= 10;
    write(padre[pen], &tomath, sizeof(tomath));
    printf("Parent sent: %d \n", tomath);
    read(nino[book], &tomath, sizeof(tomath));
    printf("Parent recieved: %d\n", tomath);
  }
  //program done 
  return 0;
}
    
