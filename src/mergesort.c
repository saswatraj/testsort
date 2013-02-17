#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *array;
int mergesort(int arr[],int l,int h);

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
      mergesort(array,0,i-1); 
      gettimeofday(&t1,0);
      long long elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
      printf("%lld",elapsed);
      /*int j;
      for(j=0;j<i;j++)
	printf("%d ",array[j]);*/
    }
  return 0;
}


//for the merge sort
int mergesort(int arr[],int l,int h)
{
  int mid;
  if(l<h) {
    mid=(l+h)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,h);
    merge(arr,l,mid,h);
}
return 0;
}

int merge(int arr[],int l,int m,int h)
{
	//returns the merged arrays
  int ar1[10000],ar2[10000];
  int n1,n2,i,j,k;
  n1=m-l+1;
  n2=h-m;
  for(i=0; i<n1; i++)
    ar1[i]=arr[l+i];
  for(j=0; j<n2; j++)
    ar2[j]=arr[m+j+1];
  ar1[i]=9999;
  ar2[j]=9999;
i=0;
j=0;
for(k=l; k<=h; k++) {
if(ar1[i]<=ar2[j])
  arr[k]=ar1[i++];
else
  arr[k]=ar2[j++];
 }
return 0;
}
