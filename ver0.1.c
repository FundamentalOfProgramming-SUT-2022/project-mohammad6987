#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <unistd.h> 
#include <sys/stat.h>   
#include <stdbool.h>    
char function_name[]={0};
char details[]={0};
char treename[]="tree";
char catname[]="cat";
char removename[]="remove";
char copyname[]="copy";
char insertname[]="insertstr";
char createfil[]="createfile";
char exi[]="exit";


int fexist(char *addresss)
{
    FILE *f;
    if (f = fopen(addresss, "r")){
        fclose(f);
        return 1;
    }
    return 0;
}

int pexist(char *pth)
{
    struct stat st;
    int len = strlen(pth);
    char cur[1000];
    for (int i = 0; i < len; i ++){
        cur[i] = pth[i];
        cur[i + 1] = '\0';
        if (cur[i] == '/'){
            cur[i] = '\0';
            if (stat(cur, &st) == -1)
                return 0;
            cur[i] = '/';
        }
    }
    return 1; //path exists
}

int createFile(char *pth){
    if (fexist(pth))
        return -1;
    int len = strlen(pth);
    char cur[1000];
    for (int i = 0; i < len; i ++){
        cur[i] = pth[i];
        cur[i + 1] = '\0';
        if (cur[i] == '/')
            mkdir(cur);
    }
    FILE *f = fopen(pth, "w");
    fclose(f);
    return 1; //file created
}


/*void insert(char str[1000])//2
{
     char filename[]={0};
     char strtoinsert[]={0};
     int x,y;
    sscanf(str,"insertstr -- file %s --str %s --pos%i:%i",filename,strtoinsert,&y,&x);
  
  
      printf("invalid command");
    gotoxy(x,y);
    fprintf(*n,);
    }

void cat(char str[1000])//3
{

}
void remove(char str[1000])//4
{

}
void copy(char str[1000])//5
{

}
void cut(char str[1000])//6
{

}
void paste(char str[1000])//7
{

}
int find(char str[1000])//8
{

}
void replace(char str[1000])//9
{

}
void grep(char str[1000])//10
{

}
int grep_c(char str[1000])//11
{

}
int grep_l(char str[1000])//12
{

}
void undo()//13
{

}
void backup()//14
{

}
void auto-indent()//15
{

}*/
void tree(char str[1000])//16
{
   int depth;
   sscanf(str,"tree -- %d",&depth);
   if(&depth==NULL)
      printf("INVALID input\n");
    else
      printf("%d\n",depth);
        
}

int main()
{
    while(1) 
    {
   char str[1000];
   fgets(str,1000,stdin);
   sscanf(str,"%['_'A-Za-z]'\0'--'\0'%[]",function_name,details);
  // printf("%s\n",function_name);

    if( strcmp(function_name,treename)==0 )  
     tree(str);

    else if(strcmp(function_name,createfil)==0) 
     createfile(str);

 /* else if(strcmp(function_name,insertname)==0) 
     insert(str);
   
   else if(function_name=="cat") 
     cat(str);
   else if(function_name=="remove") 
     remove(str);
   else if(function_name=="copy") 
     copy(str);
   else if(function_name=="cut") 
     cut(str);
   else if(function_name=="paste") 
     paste(str);
   else if(function_name=="find") 
     find(str);
   else if(function_name=="replace") 
     replace(str);
   else if(function_name=="grep") 
     grep(str);
   else if(function_name=="grep_c") 
     grep_c(str);
   else if(function_name=="grep_l") 
     grep_l(str); 
   else if(function_name=="undo") 
     nudo();
   else if(function_name=="auto_indent")
     auto_indent(str);*/
    else if(strcmp(function_name,exi)==0)
    break;
     else
       printf("Invalid Command\n");

    }
    printf("thank's for using this editor");
    

}