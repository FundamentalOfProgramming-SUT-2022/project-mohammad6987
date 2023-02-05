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
char text_compare[]="text_compare";
char clipboard[1000]={0};
int len=strlen(clipboard);
char lastpop[150];

void restorepop(const char address2[150])
{
    strcpy(lastpop,address2);
    return;
}

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
      sscanf(address2,"%[^'-']",filename);
           q=fopen(filename,"w");
           printf("%s\n",filename);
           printf("your file has been created succesfully\n");
           fclose(q);
           chdir("..") ; 
        
     }break;
     case 1:
     {
      sscanf(address2,"%[^'/']\\%[^'/']",dir1,filename);
      mkdir(dir1);
      chdir(dir1);
       q=fopen(filename,"w");
           printf("your file created succesfully\n");
           fclose(q);
           chdir("..") ; 
          
     }break;
     case 2:
     {
    sscanf(address2," %[^'--']\\%[^'--']\\%[^'--']",dir1,dir2,filename);
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
      sscanf(address2,"%[^'--']\\%[^'--']\\%[^'--']\\%[^'--']",dir1,dir2,dir3,filename);
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
      sscanf(address2,"%[^'--']\\%[^'--']\\%[^'--']\\%[^'--']\\%[^'--']",dir1,dir2,dir3,dir4,filename);
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
     char filename[160]={0};
     char address2[160]={0};
     char strtoinsert[700]={0};
     int x,y;//100*10
     int z=100*(y-1)+x;
     char cpy[2000];
     char c;
     int count=0;
    sscanf(str,"insertstr -- file %[a-zA-Z0-9'.''/'] --str %[^'--'] --pos%i:%i",filename,strtoinsert,&y,&x);
    printf("%s\n%s\n%d %d\n",filename,strtoinsert,y,x);
    strcpy(address2,filename);
  slashchange(address2);
    int g =checkaddress(address2);
  if(g==0)
    {
      printf("your file doesn't exists\n");
      return ;
    }
    
  char * buffer = 0;
long length;
FILE * f = fopen (address2, "rb");

if (f)
{
  fseek (f, 0, SEEK_END);
  length = ftell (f);
  fseek (f, 0, SEEK_SET);
  buffer = malloc (length);
  if (buffer)
  {
    fread (buffer, 1, length, f);
  }
  fclose (f);
  remove(address2);
}


FILE *q=fopen(address2);
if (buffer)
{
  // start to process your data / extract strings here...
   strncpy(copy,buffer,z-1);
   for(int i=0;i<strlen(strtoinsert),i++)
      copy[i+z]=strtoinsert[i];
   if(strlen(buffer)>z)   
   {
    for(int j=0;j<strlen(buffer)-z;j++)
        copy[z+strlen(strtoinsert)+j]=buffer[z+j];
      for(int k=0;k<strlen(copy);k++)
      {
        if(copy[k]=='\n')
          {
            fputc('\n',q);
            continue;
          }
        if(copy[k]=='\\')  
            copy[k]="\\";

         fputc(copy[k],q) ;
         count++;
         if(count==100)
         {
          fputc('\n',q);
          count=0;
         }
           
      }
   }  
   else
   {
         for(int k=0;k<strlen(copy);k++)
      {
        if(copy[k]=='\n')
          {
            fputc('\n',q);
            continue;
          }
        if(copy[k]=='\\')  
            copy[k]="\\";
            
         fputc(copy[k],q);
         count++;
         if(count==100)
         {
          fputc('\n',q);
          count=0;
         }
           
      }
   }   
} 
    }

void cat(char str[1000])//3  complete
{
    char address[160]={0};
    sscanf(str,"cat--file-%[^'-']",address);
     FILE *fp;
   int c;
  // printf("%s\n",address);
  slashchange(address);
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
    char filename[150]={0};
    char address2[150]={0};
     int y,x,s;
     int z=100(y-1)+x;
     char method;
    char aux[900]={0};
sscanf(str,"removestr -- file %[^'--'] --pos %d:%d -size %d %c",filename,&y,&x,&s,&method);
    strcpy(address2,filename);
  slashchange(address2);
    int g =checkaddress(address2);
  if(g==0)
    {
      printf("your file doesn't exists\n");
      return ;
    }
    FILE *f=fopen(address2,"w+");
     fgets(aux,900,f);
     fclose(f);
     remove(address2);
    for(int i=z;i<z+s;i++)
    {
       aux[i]=aux[i+z];
       aux[i+z]=" ";
    }
    f=fopen(address2,"w+");
     fputs(aux,f);
     fclose(f);
}
void copy(char str[1000])//5
{
 char filename[150]={0};
 char address2[150]={0};
 char aux[900]={0};
     int y,x,s;
     char method;
     long int s=100(y-1)+x;
sscanf(str,"copy -- file %[^'--'] --pos %d:%d -size %d %c",filename,&y,&x,&s,&method);
    
   strcpy(address2,filename);
  slashchange(address2);
    int g =checkaddress(address2);
  if(g==0)
    {
      printf("your file doesn't exists\n");
      return ;
    }
    FILE *f=fopen(address2,"w+");
     fgets(aux,900,f);
     fclose(f);
    for(int i=z;i<z+s;i++)
    {
       aux[i]=clipboard[i-z];
    }
    if(s=='b')
      methodchange(clipboard);
}
void methodchange(char str[800])
{
  int w=strlen(str);
  char temp;
  for(int e=0;e<w/2+1;e++)
    {
      temp=str[e];
      str[e]=str[w-1-e];
      str[w-1-e]=temp;
    }   
}
void cut(char str[1000])//6
{
 char filename[150]={0};
 char address2[150]={0};
     int y,x,s;
     char method;
     char aux[900]={0};
sscanf(str,"cutstr -- file %[^'--'] --pos %d:%d -size %d %c",filename,&y,&x,&s,&method);
long int z=100(y-1)+x;
  strcpy(address2,filename);
  slashchange(address2);
    int g =checkaddress(address2);
  if(g==0)
    {
      printf("your file doesn't exists\n");
      return ;
    }
    FILE *f=fopen(address2,"w+");//copy
     fgets(aux,900,f);
     fclose(f);
    for(int i=z;i<z+s;i++)
    {
       aux[i]=clipboard[i-z];
    }
    if(s=='b')
      methodchange(clipboard);
      
      
       f=fopen(address2,"w+");//paste
     fgets(aux,900,f);
     fclose(f);
     remove(address2);
    for(int i=z;i<z+s;i++)
    {
       aux[i]=aux[i+z];
       aux[i+z]=" ";
    }
    f=fopen(address2,"w+");
     fputs(aux,f);
     fclose(f);


}
void paste(char str[1000])//7
{
int x,y;
char filename[150]={0};
char address2[150]={0};
char aux[900]={0};
char final[1800]={0};
sscanf(str,"pastestr -- file %[^'--'] --pos %d:%d",filename,&y,&x);
int z=100(y-1)+x;
 strcpy(address2,filename);
  slashchange(address2);
    int g =checkaddress(address2);
  if(g==0)
    {
      printf("your file doesn't exists\n");
      return ;
    }
     FILE *f=fopen(address2,"w+");//copy
     fgets(aux,900,f);
     fclose(f);
     int y=strlen(aux);
    remove(address2);
    strncpy(final,aux,z-1);
    strcat(final,clipboard);
    if(z != y)
    {
      for(int r=y-z;r<y;r++)
    {
        final[z-1+len+r]=aux[r];
    }
      
       f=fopen(address2,"w+");
     fputs(final,f);
     fclose(f);
    }
     else
    {
       f=fopen(address2,"w+");
     fputs(final,f);
     fclose(f);
    }

}
int find(char str[1000])//8
{
  char filename[150]={0};
  char address2[150]={0};
  char needle[100]={0};
  char aux[900]={0};
  FILE *f;
  int line_number=1;
sscanf(str,"find --str %[^'--'] --file %[^'--']--%[^'--']--%[^'--']--%[^'--']",needle,filename)
    strcpy(address2,filename);
  slashchange(address2);
    int g =checkaddress(address2);
  if(g==0)
    {
      printf("your file doesn't exists\n");
      return ;
    }
    
     f=fopen(address2,"w+");
     fputs(aux,f);
     
     char *found_string = strstr(aux,needle);
    if (found_string == NULL)
    {
        printf ("Substring not found in the string");
        return -1;
    } 
    while (fgets(string, sizeof string, in_file)) {
        if (strstr(string, student)) {
            return line_number;
        }
        if (strchr(string, '\n')) {
            line_number += 1;
        }
    fclose(f);
}

/*int strpos(char *hay, char *needle, int offset)
{
   char haystack[strlen(hay)];
   strncpy(haystack, hay+offset, strlen(hay)-offset);
   char *p = strstr(haystack, needle);
   if (p)
      return p - haystack+offset;
   return -1;
}*/

void replace(char str[1000])//9
{

}
void grep(char str[1000])//10
{
  char pattern[60]={0};
  char code[5]="grep ";
  FILE *l;
   sscanf(str,"grep--str %[^'--']--files %[^'\n']",pattern,files);
     strcat(code,pattern);
     strcat(code," ");
     strcat(code,files);
     l=popen(code,"r");

}
int grep_c(char str[1000])//11
{
   char pattern[60]={0};
  char code[5]="grep_c ";
  FILE *l;
   sscanf(str,"grep_c--str %[^'--']--files %[^'\n']",pattern,files);
     strcat(code,pattern);
     strcat(code," ");
     strcat(code,files);
     l=popen(code,"r");
}
int grep_l(char str[1000])//12
{
   char pattern[60]={0};
  char code[5]="grep_l ";
  FILE *l;
   sscanf(str,"grep_l--str %[^'--']--files %[^'\n']",pattern,files);
     strcat(code,pattern);
     strcat(code," ");
     strcat(code,files);
     l=popen(code,"r");

}
void undo()//13
{
//backup(address2)

}
void backup(char address2[150])//14
{
     char ch;// source_file[20], target_file[20];
   FILE *source, *target;
   char target_file[]="C:/Users/zare8/Desktop/temp.txt";
   slashchange(target_file);
   slashchange(address2);
   source = fopen(address2, "r");
   target = fopen(target_file, "w"); 
   while ((ch = fgetc(source)) != EOF)
      fputc(ch, target);
   fclose(source);
   fclose(target);

}

void text_compare(char str[1000])
{
  char file1[60];
  char file2[60];
  sscanf(str,"compare--%[^'\0'] %[^'\0']");
  
}

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