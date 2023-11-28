#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
	/* the size (in bytes) of shared memory object */
	const int SIZE = 4096; // 공유 메모리의 크기 4096bytes로 설정해준다.
	/* name of the shared memory object */
	const char *name = "OS"; // 공유 메모리의 이름을 OS로 설정해준다.
	/* shared memory file descriptor */
	int fd; // 공유메모리의 파일 디스크립터를 정수형 변수로 선언해준다 0은 표준입력 1은 표준 출력, 2는 표준에러이다
	// 파일 디스크립터는 리눅스 혹은 유닉스 계열의 시스템에서 프로세스가 파일을 다룰 때 사용하는 개념으로 프로세스에서 특정 파일에 접근할 때 사용하는 추상적인 값이다.
	/* pointer to shared memory obect */
	char *ptr; // 공유메모리의 주소값을 저장해주는 변수

	/* open the shared memory object */
	fd = shm_open(name, O_RDONLY, 0666); // 파일 디스크립터를 이용하여 읽기모드로 공유메모리를 열어준다.

	/* memory map the shared memory object */
	ptr = (char *)
		mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0); // READ ONLY로 열 땐, PROT_READ인자만을 사용해야한다. Produce와 같은 방식으로 사용하지만 읽기모드만 넣어준다.

	/* read from the shared memory object */
	printf("%s", (char *)ptr); // 공유 메모리에 있는 값을 읽어온다.

	/* remove the shared memory object */
	shm_unlink(name); // 공유메모리의 객체를 지워준다.

	return 0;
}
