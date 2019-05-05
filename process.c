#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int j=0;

int minimum(int arr[],int n){
	int min=arr[0];
	for(int i=1;i<n;i++)
		if(arr[i]<min)
			min=arr[i];
	return min;
}

int main(int argc,char *argv[]){
	int i,save[4],n;
	pid_t pid[4];
	printf("Enter the number of elements(multiples of 4):\n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	for(i=0;i<4;i++){
		int fd[2];
		int val=0;
		int array[n/4];
		for(int k=0;k<(n/4);k++)
			array[k]=arr[j++];
		pipe(fd);
		if((pid[i]=fork())==0){
			sleep(1);
			close(fd[0]);
			val=minimum(array,n/4);
			write(fd[1],&val,sizeof(val));
			sleep(1);
			exit(0);
		}
		else if(pid[i]!=0){
			wait(NULL);
			close(fd[1]);
			read(fd[0],&val,sizeof(val));
			save[i]=val;
		}
	}
	printf("\n%d", minimum(save,4));
	
	if(n%4!=0)
		printf("\nThe output may be incorrect");
	return 0;
}
