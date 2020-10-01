#include <stdio.h>//for standard input output
#include <conio.h>
//For structure 
struct
{
	int bt;
	int a;
	int st;
	int et;
	
	int wt;
} typedef rr;
//Here main function use
int main()
{
	int n, qt, i, j;
	printf("enter number of process:");
	scanf("%d", &n);
	rr r[n], t;
	printf("enter time quantum:");
	scanf("%d",&qt);
//For loop start with 0
	for (i = 0; i < n; i++)
	{
		printf("enter duration of process:");
		scanf("%d",&r[i].bt);
        
	}
	
	int x, sum = 0;
	float awt = 0;
	r[0].st = 0;
	r[0].wt = 0;
	for (i = 0; i < n; i++)
	{
		if (i>0)
		{
			r[i].st = r[i - 1].et;
			r[i].wt = r[i].st;
		}
		if (r[i].bt > qt)
		{
			r[i].a = r[i].bt - qt;
			r[i].et = r[i].st + qt;
			
		}
		else
		{
			r[i].et = r[i].st + r[i].bt;
			r[i].a = 0;
		}
		
		
	}
	do
	{
		for (i = 0; i < n; i++)
		{
			if (r[i].a > 0)
			{
				if (i == 0)
				{
					r[i].st = r[n - 1].et;
				}
				else
				{
					r[i].st = r[i - 1].et;
				}
				r[i].wt += r[i].st - r[i].et;
				
			
				if (r[i].a > qt)
				{
					r[i].a -= qt;
					
					if (i == 0)
					{
						
						r[i].et = r[n - 1].et + qt;
					}
					else
					{
						r[i].et = r[i - 1].et + qt;
					}
				}
				else
				{
					
					if (i == 0)
					{
						r[i].et = r[n - 1].et + r[i].a;
					}
					else
					{
						r[i].et = r[i - 1].et + r[i].a;
					}

					r[i].a = 0;
				}
				
			}
			
			}
			
		

		x = 0;
		for (i = 0; i < n; i++)
		{
			x += r[i].a;
		}
	}while(x > 0);
	for (i = 0; i < n; i++)
	{
		sum += r[i].wt;
	}
	awt = (float)sum / n;
	printf("avrage wating time:%0.3f\n", awt);
	return 0;
}
