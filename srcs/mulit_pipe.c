#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	int fd_stdout = dup(1);
	int fd_stdin = dup(0);

	int status;
	int fd[2];
	//close(fd)를 확실하게 해줘야한다.

	//자식 프로세스에다가 파이프를 설정하면 실행이 안된다.
	if (pipe(fd) < 0)
		return (0);
	
	int len = 0;	
	pid = fork();
	if (pid < 0)
		return (1);
	else if (pid == 0)
	{	
		//fork() 안, 임시적으로 dup2(fd[1],1)로 바꾸기 위한 용도
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);

		char *argv[3] = {"ls", NULL};
		execve("/bin/ls", argv, NULL);
	}
	waitpid(pid,&status ,0);
	
	//부모프로세스 fd[1], fd[0] open 되어 있음

	pid = fork();

	if (pid < 0)
		return (1);
	else if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		
		char *argv[3] = {"cat",NULL};
		
        if (execve("/bin/cat", argv, NULL)< 0)
			fputs("fail", stdout);

	}
	else 
	{
		close(fd[1]);
		close(fd[0]);	
		waitpid(pid,&status ,0);	
	}
}




// int main(void)
// {
// 	pid_t pid;
// 	int fd_stdout = dup(1);
// 	int fd_stdin = dup(0);

// 	int status;
// 	int fd[2];
// 	//close(fd)를 확실하게 해줘야한다.

// 	//자식 프로세스에다가 파이프를 설정하면 실행이 안된다.
// 	if (pipe(fd) < 0)
// 		return (0);
	
// 	int len = 0;

	
// 	pid = fork();
// 	if (pid < 0)
// 		return (1);
// 	else if (pid == 0)
// 	{	
// 		//fork() 안에서만 임시적으로 dup2(fd[1],1)로 바꾸기 위한 용도
// 		//이 결과 execve의 값이 파이프로 들어간다.
// 		close(fd[0]);
// 		dup2(fd[1], 1);
// 		close(fd[1]);

// 		char *argv[3] = {"ls", NULL};
// 		execve("/bin/ls", argv, NULL);
// 	}
// 	waitpid(pid,&status ,0);
	
// 	//부모프로세스 fd[1], fd[0] open 되어 있음
// 	//파이프에 담긴 값을 사용할 수 있음

// 	pid = fork();

// 	//close(fd[1]);
// 	if (pid < 0)
// 		return (1);
// 	else if (pid == 0)
// 	{
// 		dup2(fd[1], 1);
// 		close(fd[1]);
// 		dup2(fd[0], 0);
// 		close(fd[0]);
		
// 		char *argv[3] = {"cat",NULL};
		
//         if (execve("/bin/cat", argv, NULL)< 0)
// 			fputs("fail", stdout);

// 	}
// 	waitpid(pid,&status ,0);
// 	//close(fd[0]);


// 	// dup2(fd[1], 1);
// 	// close(fd[1]);
// 	// dup2(fd[0], 0);
// 	// close(fd[0]);

// 	// //마지막 프로세스만
// 	// dup2(fd_stdout, 1);
	
// 	pid = fork();
// 	close(fd[1]);
	
// 	if (pid < 0)
// 		return (1);
// 	else if (pid == 0)
// 	{	
// 		close(fd[1]);
// 		dup2(fd[0], 0);
// 		close(fd[0]);
// 		char *argv[3] = {"cat",NULL};
//         if (execve("/bin/cat", argv, NULL)< 0)
// 			fputs("fail", stdout);

// 	}
// 	waitpid(pid,&status ,0);
// 	close(fd[0]);

// }