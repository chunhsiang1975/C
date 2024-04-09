#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	struct flock lock;
	char *buffer;
  char *buffer_temp;
  char *free_buffer;
  char c;
  int i=0,j;
  int buffer_size=25536;
  buffer=(char *)malloc(sizeof(char)*buffer_size);

	//int fs=open("testfile",O_RDONLY);
	int fs=open("testfile",O_RDWR);
	int result_of_fcntl=0;
	if(fs==-1){
		perror("The file cannot opened.\n");
		return -1;	
	}
	memset(&lock,0,sizeof(lock));
  //ps: lock.l_type=F_RDLCK is false for another thread to write this file and it will let another thread can't write testfile after unlocking.  
  lock.l_type=F_WRLCK;  
  result_of_fcntl=fcntl(fs,F_SETLKW,&lock);
#if 1
	int n;
	while((n = read(fs, buffer, sizeof(buffer))) > 0){
		//printf("%d\n",n);
		write(1, buffer, n);
	}
	if(n<0){
		perror("read");
		return -1;
  }
#endif

#if 1
	printf("Enter u to unlock file\n");
	printf("Enter q to exit\n");
	while(1){
		c=getchar();
		if(c=='u'){
  		lock.l_type=F_UNLCK;
  		result_of_fcntl=fcntl(fs,F_SETLKW,&lock);
			close(fs);
  		if(result_of_fcntl==-1){
  			perror("Error:");
				return -1;
			}
			return 0;
		}
		if(c=='q'){
				close(fs);
				return 0;
		}
	}
#endif
   return 0;
}

