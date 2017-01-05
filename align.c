#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main()
{
	char buf[4096];
	printf("buf[0]'s addr [%x][%d]\n", (int)(char*)&buf[0],(int)(char*)&buf[0]);
	printf("buf[1]'s addr [%x][%d]\n", (int)(char*)&buf[1],(int)(char*)&buf[1]);
	printf("buf[2]'s addr [%x][%d]\n", (int)(char*)&buf[2],(int)(char*)&buf[2]);
	printf("buf[3]'s addr [%x][%d]\n", (int)(char*)&buf[3],(int)(char*)&buf[3]);
	struct timeval starttime,endtime;
	double timeuse;


	int tmp = 0;
	int count = 2000000;
	int i,j;

	memset(buf, sizeof(buf), 0);
//1.
 	gettimeofday(&starttime,0);
	for (i=0; i<count; ++i)
	{
		for (j=1;j<(sizeof(buf)-4);j+=4)
		{
			tmp = *(int*)&buf[j];
			tmp++;
			*(int*)&buf[j] = tmp;
		}
	}
 	gettimeofday(&endtime,0);
	timeuse  = 1000000*(endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;
	timeuse = timeuse/1000;
	printf("shift 1 byte --> timeuse: %f ms \n",timeuse);

	memset(buf, sizeof(buf), 0);
//1.
 	gettimeofday(&starttime,0);
	for (i=0; i<count; ++i)
	{
		for (j=2;j<(sizeof(buf)-4);j+=4)
		{
			tmp = *(int*)&buf[j];
			tmp++;
			*(int*)&buf[j] = tmp;
		}
	}
 	gettimeofday(&endtime,0);
	timeuse  = 1000000*(endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;
	timeuse = timeuse/1000;
	printf("shift 2 byte --> timeuse: %f ms\n",timeuse);

	memset(buf, sizeof(buf), 0);
//1.
 	gettimeofday(&starttime,0);
	for (i=0; i<count; ++i)
	{
		for (j=3;j<(sizeof(buf)-4);j+=4)
		{
			tmp = *(int*)&buf[j];
			tmp++;
			*(int*)&buf[j] = tmp;
		}
	}
 	gettimeofday(&endtime,0);
	timeuse  = 1000000*(endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;
	timeuse = timeuse/1000;
	printf("shift 3 byte --> timeuse: %f ms\n",timeuse);

	memset(buf, sizeof(buf), 0);
//1.
 	gettimeofday(&starttime,0);
	for (i=0; i<count; ++i)
	{
		for (j=0;j<(sizeof(buf)-4);j+=4)
		{
			tmp = *(int*)&buf[j];
			tmp++;
			*(int*)&buf[j] = tmp;
		}
	}
 	gettimeofday(&endtime,0);
	timeuse  = 1000000*(endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;
	timeuse = timeuse/1000;
	printf("shift 4(0) byte --> timeuse: %f ms\n",timeuse);

	return 0;
}
