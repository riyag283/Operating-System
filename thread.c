//program to linear search a given key from an array
//by improving the execution through parallelism, i.e.,
//multi-threading 
//The following program makes 4 threads.
#include<pthread.h>
#include<stdio.h>

//the following are gloabal variables from all the threads
int key, pos, flag=0;
int n;//number of elements in the array
int a[100];//the array can have at most 100 elements

//function that marks the execution of each thread
void *search(void *arg){
	int id=(int)arg;
	int start=id*(n/4);//starting index of search
	for(int i=start;i<start+n/4;i++){
		if(a[i]==key){
			flag=1;//set when the key is found
			pos=i;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&key);
	pthread_t thread[4];
	for(int i=0;i<4;i++)
		pthread_create(&thread[i],NULL,search,(void *)i);
	for(int i=0;i<4;i++)
		pthread_join(thread[i],NULL);
	if(flag==1)
		printf("Position: %d\n", pos);
	else
		printf("Not found :-(\n");
	
}