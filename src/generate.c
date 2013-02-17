#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	perror("Number of arguments not Correct");
	else
	{
		int times=atoi(argv[1]);
		FILE *fp=fopen("tempfile.txt","w");
		if(fp==NULL)
		{
			perror("File IOError");
			return 0;
		}
		srand(time(NULL));
		int i;
		for(i=0;i<times;i++)
		{
			int rd=rand()%times;
			fprintf(fp,"%d\n",rd);
		}
		fclose(fp);
	}
	return 0;
}
