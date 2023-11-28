#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /* this data is shared by the thread */
void *runner(void *param);

int main(int argc, char *argv[])
{
	pthread_t tid;		 // 쓰레드의 식별자를 선언
	pthread_attr_t attr; // 새로 생성되는 쓰레드의 속성을 설정한다.

	/* set the default attributes of the thread */
	pthread_attr_init(&attr); // 쓰레드의 속성을 기본값으로 바꿔주는 함수를 사용하여 기본값으로 변경해준다.
	/* create the thread */
	pthread_create(&tid, &attr, runner, argv[1]); // 쓰레드를 설정한다. 쓰레드의 식별자 주소, 러너 함수를 실행, 1부터 덧셈을 진행할 값을 char형 배열에 숫자를 받아준다.
	/* wait for the thread to exit */
	pthread_join(tid, NULL);
	// 쓰레드가 정상종료할때 까지 기다리는 pthread_join을 사용한다. runner함수에서 pthread_exit에 0이 있어 종료처리가 되기 때문에 기다린다.
	printf("sum = %d\n", sum);
	// 러너함수에서 나온 값을 출력해준다.

	return 0;
}

/* The thread will execute in this function */
void *runner(void *param)
{
	// char형으로 받았기 때문에 아스키코드값을 정수형으로 변경시켜주는 함수인 atoi함수를 사용하여 sum에 값을 더해준다.
	int i, upper = atoi(param);
	sum = 0;
	for (i = 1; i <= upper; i++)
		sum += i;

	pthread_exit(0); // 쓰레드를 사용한 이유 사용한 쓰레드를 놓아준다.
}
