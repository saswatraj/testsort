#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXVARS 100000
int array[MAXVARS];
void heapsort(int length);

int  main()
{
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
      heapsort(i) ;
      gettimeofday(&t1,0);
      long long elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
      printf("%lld",elapsed);
      /*int j;
      for(j=0;j<i;j++)
        printf("%d ",array[j]);*/
    }
  return 0;
}

int left(int index)
{
  index+=1;
  return 2*index-1;
}

int right(int index)
{
  index+=1;
  return 2*index;
}

void minHeapify(int i,int length)
{
  int lc=left(i);
  int rc=right(i);
  int sl;
  if((lc<length)&&(array[lc]<array[i]))
	sl=lc;
  else
	sl=i;
  if((rc<length)&&(array[rc]<array[sl]))
	sl=rc;
  if(sl!=i)
  {
    int temp=array[sl];
	array[sl]=array[i];
	array[i]=temp;
	minHeapify(sl,length);
  }
}

void buildMinHeap(int length)
{
	int i=(length)/2;
	for(;i>=0;i--)
	minHeapify(i,length);
}

void heapsort(int length)
{
	int temp,i;
	buildMinHeap(length);
	int size=length;
	for(i=length-1;i>=1;i--)
	{
		temp=array[0];
		array[0]=array[i];
		array[i]=temp;
		size=size-1;
		minHeapify(0,size);
	}
}
