#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *array;
void bubblesort(int length);

int main(nt argc,char* argv[])
{
  if(argc!=2)
  {
  	perror("Number of arguments not correct");
  	return;
  }
  int arrl=atoi(argv[1]);
  array=malloc(sizeof(int)*arrl);
  FILE *fp=fopen("tempfile.txt","r");
  if(fp==NULL)
    {
      perror("Error Opening File");
    }
  else
    {
      int fr,i=0;
      while(fscanf(fp,"%d\n",&fr)!=EOF)
	{
	  array[i]=fr;
	  i++;
	}
      //printf("\n\n%d\n",i);
      struct timeval t0,t1;
      gettimeofday(&t0,0);
      bubblesort(i); 
      gettimeofday(&t1,0);
      long long elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
      printf("%lld",elapsed);
    }
  return 0;
}

void bubblesort(int length)
{
  int i,j,temp;
  for(i=0;i<length;i++)
    for(j=0;j<length-1;j++)
      if(array[j]>array[j+1])
	{
	  temp=array[j];
	  array[j]=array[j+1];
	  array[j+1]=temp;
	}
}
