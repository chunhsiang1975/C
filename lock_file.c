#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define WRITE_FLAGS (O_WRONLY  | O_CREAT | O_APPEND)

int main(int argc, char *argv[]){
	struct flock lock;
	int fs=open("testfile",WRITE_FLAGS);
	int result_of_fcntl=0;
	if(fs==-1){
		perror("The file cannot opened.\n");
		return -1;	
	}
	memset(&lock,0,sizeof(lock));
  lock.l_type=F_WRLCK;  
  result_of_fcntl=fcntl(fs,F_SETLKW,&lock);
  char buffer2[]={"deneme\n"};

  int byteswritten = write(fs,buffer2,7);
	printf("%d\n",byteswritten);
  if(byteswritten==-1){
     perror("Error while writing to file:");
     //printf("Error while writing to file:");
     return -1;
  }

#if 0
	char buffer[512];
	int n;
	while((n = read(0, buffer, sizeof buffer)) > 0){
		write(1, buffer, n);
	}

	if(n<0){
		perror("read");
		return -1;
  }
#endif

#if 1
	printf("Enter u to unlock file\n");
	printf("Enter l to lock file\n");
	printf("Enter q to exit\n");
	char c;
	while(1){
		c=getchar();
		if(c=='u'){
  		lock.l_type=F_UNLCK;
  		result_of_fcntl=fcntl(fs,F_SETLKW,&lock);
  		if(result_of_fcntl==-1){
  			perror("Error:");
				return -1;
			}
		}
		if(c=='l'){
  		lock.l_type=F_WRLCK;
  		result_of_fcntl=fcntl(fs,F_SETLKW,&lock);
  		if(result_of_fcntl==-1){
  			perror("Error:");
				return -1;
			}
		}
		if(c=='q'){
				return 0;
		}
	}
	int closeFlag= close(fs);
	if(closeFlag==-1){
			perror("The file cannot closed.\n");
			return-1;
	}
#endif
   return 0;
}

