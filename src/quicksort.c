#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *array;
void quicksort(int start,int end);
int partition(int start,int end);

int main(int argc,char* argv[])
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
      quicksort(0,i-1); 
      gettimeofday(&t1,0);
      long long elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + (t1.tv_usec-t0.tv_usec);
      printf("%lld",elapsed);
      /*int j;
      for(j=0;j<i;j++)
	printf("%d ",array[j]);*/
    }
  return 0;
}

void quicksort(int start,int end)
{
  if(start<end)
    {
      int r=partition(start,end);
      quicksort(start,r-1);
      quicksort(r+1,end);
    }
}

int partition(int start,int end)
{
	int pivot,i,j,temp;
	pivot=array[start];
	i=start+1;j=end;
	while(1)
	{
		while((array[i]<=pivot)&&(i<end))i++;
		while(array[j]>pivot)j--;
		if(i>=j)break;
		temp=array[i];
		array[i]=array[j];
		array[j]=temp;
	}
	temp=array[j];
	array[j]=array[start];
	array[start]=temp;
	return j;
}
