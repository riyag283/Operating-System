#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	int fd; 
	char * myfifo = "/tmp/myfifo"; 

	mkfifo(myfifo, 0666); 

	char arr1[80], arr2[80]; 
	while (1) 
	{ 
		fd = open(myfifo, O_WRONLY);
		fgets(arr2, 80, stdin); 
		int n;
		n=strlen(arr2);
		for(int i=0;i<n;i++)
			arr2[i]++;

		write(fd, arr2, strlen(arr2)+1); 
		close(fd); 
		fd = open(myfifo, O_RDONLY); 
		read(fd, arr1, sizeof(arr1)); 
		char c1=*arr1;
		char c2=*(arr1+1);
		char c3=*(arr1+2);
		char c4=*(arr1+3);
		if(c1=='e'&&c2=='x'&&c3=='i'&&c4=='t')
			break;
		printf("Person 2: %s\n", arr1); 
		close(fd); 
	} 
	return 0; 
} 
