
#include<stdio.h>
#include<string.h>
#include<ctype.h>


#define S2 1
#define S3 2
#define S4 3
#define S5 4
#define S6 5
#define S9 6
#define S11 7
#define S12 8
#define S14 46

#define S15 9
#define S16 10
#define S18 11
#define S19 12
#define S20 13
#define S21 14
#define S22 15
#define S23 16
#define S25 17
#define S26 18
#define S28 19
#define S29 20
#define S30 21
#define S31 22
#define S32 23
#define S33 24
#define S35 25
#define S36 26
#define S37 27
#define S38 28
#define S39 29
#define S40 30
#define S43 31

#define R1 32
#define R2 33
#define R3 34
#define R4 35
#define R5 36
#define R6 37
#define R7 38
#define R8 39
#define R9 40
#define R10 41
#define R11 42
#define R12 43
#define R13 44
#define R14 45
#define AC 47           /* ACCEPT */
#define ER -1            /* ERROR */

/* the parsing table  */
int table[44][27]= {
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S2,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,1,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,AC,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S3,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {S4,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,S5,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S6,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S9,ER,ER,ER,ER,ER,ER,7,ER,ER,ER,ER,8,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,R6,S11,ER,ER,R6,ER,ER,R6,ER,10,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S12,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,R14,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S14,ER,ER,ER,R8,ER,ER,ER,ER,ER,ER,ER,13,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,S15,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,S16,ER,R4,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,17,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S18,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {S19,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S20,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S21,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,S22,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,S23,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S25,ER,ER,ER,ER,ER,ER,ER,ER,ER,24,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,S26,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,S16,ER,R4,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,27,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,R2,R2,ER,ER,R2,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,S28,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,S29,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,S30,ER,S31,S32,S33,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,R6,S11,ER,ER,R6,ER,ER,R6,ER,34,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,R3,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S35,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S36,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S37,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S38,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S39,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S40,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,R5,ER,ER,ER,R5,ER,ER,R5,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,R1,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,R6,S11,ER,ER,R6,ER,ER,R6,ER,41,ER,ER,ER,ER,ER,ER,42},
  {ER,R10,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,R9,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,R12,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,R11,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,R13,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,S43,ER,ER,ER,ER,ER,ER,ER,ER,ER},
  {ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,R7,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER,ER}
};
#define STRING_SIZE 500

char string[STRING_SIZE];
int p=0;
int save;
int hash=0;
int y;
#define STACK_SIZE 100

typedef struct {
  int list[STACK_SIZE];
  int top;
}Stack;

error()
{
    if(hash==0){

               for(y=0;y<p-1;y++)
               {
                   printf("%c ",string[y]);
               }
  printf("Syntax error between %c and  %c\n",string[p-2],string[p-1]);}
getch();
  exit(0);
}


void initialize(Stack *s)
 {
  s->top=-1;
}
void push(int value,Stack *s)
 {
  s->list[++(s->top)]=value;
}
int pop(Stack *s)
 {
  return(s->list[(s->top)--]);
}
int isempty(Stack *s)
{
  return(s->top==-1);
}
int peek(Stack *s)
{
  return(s->list[s->top]);
}
int stacksize(Stack *s)
{
  return((s->top)+1);
}


#define ZERO 3
#define COMMA 2
#define SEMI 4
#define OPBR 0
#define CLBR 1
#define LT 5
#define EQ 6
#define GT 7
#define d 8
#define e 9
#define f 10
#define i 11
#define m 12
#define n 13
#define r 14
#define v 15
#define OPCB 16
#define CLCB 17
#define DOLLAR 18
#define A 19
#define D 20
#define E 21
#define I 22
#define R 23
#define S 24
#define T 25
#define Z 26


short int gettoken()
{
  /* ignore blanks */
  while(string[p]==' '&&string[p+1]!=' '&& string[p-1]!=' ')
    p++;

   if(string[p]=='0')
   {
    save=p;
    p++;
    return ZERO;

  }
  else if(string[p]==',')
   {
    save=p;
    p++;
    return COMMA;
  }

  else if(string[p]=='(')
   {
    save=p;
    p++;
    return OPBR;
  }
  else if(string[p]==')')
  {
    save=p;
    p++;
    return CLBR;
  }
    else if(string[p]==';')
    {
    save=p;
    p++;
    return SEMI;
  }

    else if(string[p]=='<')
     {
    save=p;
    p++;
    return LT;
  }


    else if(string[p]=='>')
    {
    save=p;
    p++;
    return GT;
  }

    else if(string[p]=='{')
    {
    save=p;
    p++;
    return OPCB;
  }

    else if(string[p]=='}')
     {
    save=p;
    p++;
    return CLCB;
  }

  else if(string[p]=='!')
  {
      if(string[p+1]=='=')
   {

   save=p+1;
    p=p+2;
    return d;}
    else
    {
        error();

    }
  }

    else if(string[p]=='=')
    {
        if(string[p+1]=='=')
   {

    save=p+1;
    p=p+2;
    return e;}
    else
    {
        save=p;
        p++;
        return EQ;
    }
  }

    else if(string[p]=='f')
    {
    save=p;
    p++;
    return f;
  }
else if(string[p]=='e')
{
    save=p;
    p++;
    return r;
  }
  else if(string[p]=='t')
   {
    save=p;
    p++;
    return r;
  }
  else if(string[p]=='u')
  {
    save=p;
    p++;
    return r;
  }

   else if(string[p]=='n')
   {
    save=p;
    p++;
    return r;
  }

     else if(string[p]=='i')
    {
        if((string[p+1]=='n')&&(string[p+2]=='t'))
    {
    save=p+2;
    p=p+3;
    return n;
    }
    else if(string[p+1]=='f')
    {

    save=p+1;
    p=p+2;
    return f;
  }

    else
    {
     save=p;
    p++;
    return i;
    }
  }

    else if((string[p]=='m')&&(string[p+1]=='a')&&(string[p+2]=='i')&&(string[p+3]=='n'))
     {
     save=p+3;
     p=p+4;
    return m;
  }





    else if(string[p]=='r')
    {


    if((string[p+1]=='e'))
    {
        if(string[p+2]=='t')
        {
        if(string[p+3]=='u')
        {


          if(string[p+5]=='n')
          {


         save=p+5;
        p+=6;
        return r;
          }
       }
       }
   }
  }


    else if(string[p]=='v')
  {

    save=p;
    p++;
    return v;
  }


  else if(string[p]==0)
  {
    return DOLLAR;
  }
  else
  {
      return -1;
  }
}
int parse() {
  int token;
  Stack stack;
  int state;
  int j;
  int action;
  int previous;
  initialize(&stack);
  push(0,&stack);
  token=0;
  int x;
  while(1) {
    token=gettoken();
    if(token==-1)
    {
               for(x=0;x<p;x++)
               {
                   printf("successfully compiling %c",string[x]);
               }
                 printf("Syntax error at %c",string[p]);
                 getch();
                 hash=1;
                 break;

    }
    action=table[peek(&stack)][token];


    switch(action)
     {

     case S2:
      push(token,&stack);
      push(2,&stack);
      break;
    case S3:
      push(token,&stack);
      push(3,&stack);
      break;
    case S4:
      push(token,&stack);
      push(4,&stack);
      break;
      case S5:
      push(token,&stack);
      push(5,&stack);
      break;
    case S6:
      push(token,&stack);
      push(6,&stack);
      break;

      case S9:
      push(token,&stack);
      push(9,&stack);
      break;

      case S11:
      push(token,&stack);
      push(11,&stack);
      break;
      case S12:
      push(token,&stack);
      push(12,&stack);
      break;
      case S14:
      push(token,&stack);
      push(14,&stack);
      break;
      case S15:
      push(token,&stack);
      push(15,&stack);
      break;

      case S16:
      push(token,&stack);
      push(16,&stack);
      break;

      case S18:
      push(token,&stack);
      push(18,&stack);
      break;
      case S19:
      push(token,&stack);
      push(19,&stack);
      break;
      case S20:
      push(token,&stack);
      push(20,&stack);
      break;
      case S22:
      push(token,&stack);
      push(22,&stack);
      break;
      case S21:
      push(token,&stack);
      push(21,&stack);
      break;
      case S23:
      push(token,&stack);
      push(23,&stack);
      break;

      case S25:
      push(token,&stack);
      push(25,&stack);
      break;
      case S26:
      push(token,&stack);
      push(26,&stack);
      break;

      case S28:
      push(token,&stack);
      push(28,&stack);
      break;
      case S29:
      push(token,&stack);
      push(29,&stack);
      break;
      case S30:
      push(token,&stack);
      push(30,&stack);
      break;
      case S31:
      push(token,&stack);
      push(31,&stack);
      break;
      case S32:
      push(token,&stack);
      push(32,&stack);
      break;
      case S33:
      push(token,&stack);
      push(33,&stack);
      break;


      case S35:
      push(token,&stack);
      push(35,&stack);
      break;
      case S36:
      push(token,&stack);
      push(36,&stack);
      break;
      case S37:
      push(token,&stack);
      push(37,&stack);
      break;
      case S38:
      push(token,&stack);
      push(38,&stack);
      break;
      case S39:
      push(token,&stack);
      push(39,&stack);
      break;
      case S40:
      push(token,&stack);
      push(40,&stack);
      break;

      case S43:
      push(token,&stack);
      push(43,&stack);
      break;

    case AC:
      return 1;
    case ER:
    error();

    }
    if(action>=32 && action <=45)
    {
      while(action>=32 && action <=45)
       {
    action=table[peek(&stack)][token];

    switch(action)
     {
    case R1:
      for(j=0;j<24;j++)
        pop(&stack);
      state=table[peek(&stack)][S];
      if(state!=ER)
      {

        push(S,&stack);
        push(state,&stack);
      }
      else
        error();
      break;
    case R2:
      for(j=0;j<8;j++)
        pop(&stack);
      state=table[peek(&stack)][D];
      if(state!=ER)
       {
        push(D,&stack);

        push(state,&stack);
      }
      else
        error();

      break;

    case R3:
      for(j=0;j<6;j++)
        pop(&stack);
      state=table[peek(&stack)][R];
      if(state!=ER)
       {
        push(R,&stack);
        push(state,&stack);
      }
      else
        error();
      break;
    case R4:

      state=table[peek(&stack)][R];
      if(state!=ER)
       {
        push(R,&stack);
        push(state,&stack);
      }
      else
        error();
      break;
    case R5:
      for(j=0;j<10;j++)
        pop(&stack);
      state=table[peek(&stack)][A];
      if(state!=ER)
       {
        push(A,&stack);
        push(state,&stack);
      }
      else
        error();
      break;
    case R6:

      state=table[peek(&stack)][A];
      if(state!=ER)
       {
        push(A,&stack);
        push(state,&stack);
      }
      else
        error();
      break;
      case R7:

    for(j=0;j<14;j++)
        pop(&stack);
       state=table[peek(&stack)][I];
      if(state!=ER)
       {
        push(I,&stack);
        push(state,&stack);
      }
      else
        error();
      break;
      case R8:

      state=table[peek(&stack)][I];
      if(state!=ER) {
        push(I,&stack);
        push(state,&stack);
      }
      else
        error();
      break;
      case R9:
      for(j=0;j<6;j++)
        pop(&stack);
      state=table[peek(&stack)][E];
      if(state!=ER)
       {
        push(E,&stack);
        push(state,&stack);
      }
      else
       error();
      break;

      case R10:
      for(j=0;j<6;j++)
        pop(&stack);
      state=table[peek(&stack)][E];
      if(state!=ER)
      {
        push(E,&stack);
        push(state,&stack);
      }
      else
       error();
      break;


      case R11:
      for(j=0;j<6;j++)
        pop(&stack);
      state=table[peek(&stack)][E];
      if(state!=ER)
       {
        push(E,&stack);
        push(state,&stack);
      }
      else
       error();
      break;

      case R12:
      for(j=0;j<6;j++)
        pop(&stack);
      state=table[peek(&stack)][E];
      if(state!=ER)
      {
        push(E,&stack);
        push(state,&stack);
      }
      else
       error();
      break;


      case R13:
      for(j=0;j<2;j++)
        pop(&stack);
      state=table[peek(&stack)][Z];
      if(state!=ER)
       {
        push(Z,&stack);
        push(state,&stack);
      }
      else
       error();
      break;

      case R14:
      for(j=0;j<2;j++)
        pop(&stack);
      state=table[peek(&stack)][T];
      if(state!=ER)
       {
        push(T,&stack);
        push(state,&stack);
      }
      else
       error();
      break;
    case AC:
      return 1;
    case ER:
   error();
    }
      }
      p=save;
    }
  }
  return 0;
}
int main() {
  printf("Enter the string: ");
  scanf("%s",string);
  int k;
  if(parse())
   {
    printf("the above code is in decaf , therefore executing the code....\n ....\n");
    FILE *fopen(),*fp;
    fp=fopen("myfile.c","w");
    fprintf(fp,"%s",string);
    fclose(fp);
  //  system("gcc myfile.c");
   // system("./a.out");

  }
  else
   error();
getch();

}
