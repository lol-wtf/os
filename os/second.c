#include<stdio.h>
#define MAX 20

int frames[MAX],ref[MAX],mem[MAX][MAX],faults,
	sp,m,n,u[MAX];

void accept()
{
	int i;

	printf("Enter no.of frames:");
	scanf("%d", &n);

	printf("Enter no.of references:");
	scanf("%d", &m);

	printf("Enter reference string:\n");
	for(i=0;i<m;i++)
	{
		printf("[%d]=",i);
		scanf("%d",&ref[i]);
	}
}

void disp()
{
	int i,j;

	for(i=0;i<m;i++)
		printf("%3d",ref[i]);

	printf("\n\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mem[i][j])
				printf("%3d",mem[i][j]);
			else
				printf("   ");
		}
		printf("\n");
	}

	printf("Total Page Faults: %d\n",faults);
}

int search(int pno)
{
	int i;

	for(i=0;i<n;i++)
	{
		if(frames[i]==pno)
			return i;
	}

	return -1;
}

void second()
{
	int i,j,k;

	for(i=0;i<m;i++)
	{
		k=search(ref[i]);

		if(k==-1)
		{
			while(1)
			{
				if(u[sp]==0) break;
				u[sp]=0;
				sp=(sp+1)%n;
			}

			frames[sp]=ref[i];
			u[sp]=1;
			faults++;
			sp=(sp+1)%n;

			for(j=0;j<n;j++)
				mem[j][i] = ref[j];
		}
		else
			u[k] = 1;
	}
}
						

int main()
{
	accept();
	second();
	disp();

	return 0;
}





	






