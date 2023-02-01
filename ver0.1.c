#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <unistd.h> 
#include <sys/stat.h> 

char function_name[]={0};
char details[]={0};
char treename[]="tree";
char catname[]="cat";
char removename[]="removestr";
char copyname[]="copy";
char insertname[]="insertstr";
char cutname[]="cut";
char pastename[]="paste";
char findname[]="find";
char grepname[]="grep";
char grep_cname[]="grep_c";
char createfil[]="createfile";
char replacename[]="replace";
char exi[]="exit";
char grep_lname[]="grep_l";
char undoname[]="undo";
char auto_indentname[]="auto_indent";
char clipboard[]={0};


int countchar(char *str, char x)
{
    int count = 0;
    for (int i = 0; i <strlen(str); i++)
        if (str[i] == x)
            count++;
    return count;
}

void slashchange(char str[200])
{
	int w=strlen(str);
	for(int j=0;j<w;j++)
	{
		if(str[j]=='/')
		  str[j]='\\' ;
	}
}




 void createfile(char str[1000])
 {
   FILE *q;
   char dir1[50]={0};
	char dir2[50]={0};
  char dir3[50]={0};
  char dir4[50]={0};
  char filename[]={0};
  char address[200]={0};
  char address2[200]={0};
  sscanf(str,"createfile -- file %s",address);
  int x=countchar(address,'/');
  strcpy(address2,address);
  slashchange(address2);
  printf("your file address is : %s\n",address2);
  int g =checkaddress(address2);
  if(g==1)
    {
      printf("your file already exists\n");
      return ;
    }
  else
  {
       switch(x)
  {
     case 0:
     {
      sscanf(address2,"%[a-zA-Z0-9'.''/''\']",filename);
           q=fopen(filename,"w");
           printf("%s\n",filename);
           printf("your file has been created succesfully\n");
           fclose(q);
           chdir("..") ; 
        
     }break;
     case 1:
     {
      sscanf(address2,"%[a-zA-Z0-9'.''/''\']\\%[a-zA-Z0-9'.''/''\']",dir1,filename);
      mkdir(dir1);
      chdir(dir1);
       q=fopen(filename,"w");
           printf("your file created succesfully\n");
           fclose(q);
           chdir("..") ; 
          
     }break;
     case 2:
     {
    sscanf(address2," %[a-zA-Z0-9'.''/''\']\\%[a-zA-Z0-9'.''/'\']\\%[a-zA-Z0-9'.''/'\']",dir1,dir2,filename);
   printf("%s\n%s\n%s\n",dir1,dir2,filename);
       mkdir(dir1);
       chdir(dir1);
        mkdir(dir2);
       chdir(dir2);
       q=fopen(filename,"w");
           printf("your file created succesfully\n");
           fclose(q);
           chdir("..") ;
          
     }break;
     case 3:
     {
      sscanf(address2,"%[a-zA-Z0-9'.''/''\']\\%[a-zA-Z0-9'.''/''\']\\%[a-zA-Z0-9'.''/''\']\\%[a-zA-Z0-9'.''/''\']",dir1,dir2,dir3,filename);
      mkdir(dir1);
       chdir(dir1);
        mkdir(dir2);
       chdir(dir2);
       mkdir(dir3);
       chdir(dir3);
       q=fopen(filename,"w");
           printf("your file created succesfully\n");
           fclose(q);
        chdir("..") ;  
     }break;
      case 4:
     {
      sscanf(address2,"%[a-zA-Z0-9'.''/''\''\0']\\%[a-zA-Z0-9'.''/''\''\0']\\%[a-zA-Z0-9'.''/''\''\0']\\%[a-zA-Z0-9'.''/''\''\0']\\%[a-zA-Z0-9'.''/''\''\0']",dir1,dir2,dir3,dir4,filename);
      mkdir(dir1);
       chdir(dir1);
        mkdir(dir2);
       chdir(dir2);
       mkdir(dir3);
       chdir(dir3);
       mkdir(dir4);
       chdir(dir4);
       q=fopen(filename,"w");
           printf("your file created succesfully\n");
           fclose(q);
        chdir("..") ;  
     }break;
     default : printf("your address is beyond this programm capablity\n");
  }
  }
    
 }  
  
int checkaddress(char address[160])
{
  FILE *f;
  f=fopen(address,"r");
  if(f==NULL)
    return 0;
  else 
    return 1; 
}
 
void insert(char str[1000])//2
{                               
     char filename[]={0};
     char strtoinsert[]={0};
     int x,y;
    sscanf(str,"insertstr -- file %[a-zA-Z0-9'.''/'] --str %[a-zA-Z0-9'.''/'\"] --pos%i:%i",filename,strtoinsert,&y,&x);
    printf("%s\n%s\n%d %d\n",filename,strtoinsert,y,x);
  
    }

void cat(char str[1000])//3  complete
{
    char address[]={0};
    sscanf(str,"cat--file-%[a-zA-Z0-9'.''/']",address);
     FILE *fp;
   int c;
  // printf("%s\n",address);
   fp = fopen(address,"r");
   if(fp==NULL)
   {
    printf("your file doesn't exist\n");
    return;
   }
   c = getc(fp) ;
   while (c!= EOF){
        putchar(c);
	c = getc(fp);
   }
   printf("\n");
   fclose(fp);
}

void remov(char str[1000])//4
{
    char filename[]={0};
     int y,x,s;
     char method;
sscanf(str,"removestr -- file %[] --pos %d:%d -size %d %c",filename,&y,&x,&s,&method);

}
void copy(char str[1000])//5
{
 char filename[]={0};
     int y,x,s;
     char method;
sscanf(str,"copy -- file %['/'A-Za-z0-9] --pos %d:%d -size %d %c",filename,&y,&x,&s,&method);
}
void cut(char str[1000])//6
{
 char filename[]={0};
     int y,x,s;
     char method;
sscanf(str,"copy -- file %['/'A-Za-z0-9] --pos %d:%d -size %d %c",filename,&y,&x,&s,&method);
}
/*void paste(char str[1000])//7
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
      {
        char command[]={0};
        strcpy( command, "tree /F" );
   system(command);
      }
        
}

int main()
{
    printf("******************************text editor******************************\n");
    while(1) 
    {
   char str[1000];
   fgets(str,1000,stdin);
   sscanf(str,"%['_'A-Za-z]'\0'--'\0'%[]",function_name,details);
  // printf("%s\n",function_name);

    if( strcmp(function_name,treename)==0 )  //+
     tree(str);
    else if(strcmp(function_name,createfil)==0)// +
     createfile(str);
  else if(strcmp(function_name,insertname)==0) //+
     insert(str);
   else if(strcmp(function_name,catname)==0) //+++
     cat(str);
   else if(strcmp(function_name,removename)==0) //+
     remov(str);
 /*  else if(strcmp(function_name,copyname)==0) //+
     copy(str);
   else if(strcmp(function_name,cutname)==0) //+
     cut(str);
   else if(strcmp(function_name,pastename)==0) //+
     paste(str);
   else if(strcmp(function_name,findname)==0) //+
     find(str);
   else if(strcmp(function_name,replacename)==0) //+
     replace(str);
   else if(strcmp(function_name,grepname)==0) //+
     grep(str);
   else if(strcmp(function_name,grep_cname)==0) //+
     grep_c(str);
   else if(strcmp(function_name,grep_lname)==0) //+
     grep_l(str); 
   else if(strcmp(function_name,undoname)==0) //
     nudo();
   else if(strcmp(function_name,auto_indenttname)==0)//
     auto_indent(str);*/
    else if(strcmp(function_name,exi)==0)//++
    {
      break;
    }
     else
       printf("Invalid Command\n");
    }
printf("thank's for using this editor\n");
printf("**************************************************\n");
    
    

}