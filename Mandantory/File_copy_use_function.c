#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fin, *fout;						   // 입력 및 출력파일의 주소를 받아주는 인스턴스
	char file_to_c, infile[128], outfile[128]; // 파일에 글자를 받아 오는 변수 c, 입력 및 출력파일 이름을 받기 위한 배열
	printf("입력 파일 이름: ");
	gets(infile); // infile 배열에 입력파일 이름 저장.
	printf("출력 파일 이름.  ");
	gets(outfile); // outfile 배열에 출력파일 이름 저장.

	fin = fopen(infile, "r"); // fin변수에 fopen함수를 사용하여, infile배열에 있는 파일 읽기모드로 열기
	if (fin == NULL)		  // 만약 파일이 존재하지 않고, 값을 입력하지 않았다면
	{
		printf("Error : 파일 %s을 열수 없습니다.\n", infile); // 입력파일 이름과 함께 오류 메세지 출력
		exit(1);											  // 강제종료
	}

	fout = fopen(outfile, "w"); // 위 제어문을 통과했다면 출력할 파일을 쓰기모드로 열기
	if (fout == NULL)			// 만약 출력파일을 입력하지 않았다면
	{
		printf("Error : 파일 %s을 열 수 없습니다.\n", outfile); // 출력파일이름과 오류 메세지 출력
		exit(1);												// 강제종료
	}
	while ((file_to_c = fgetc(fin)) != EOF) // 반복문을 사용하여 c라는 인스턴스에 입력파일의 끝까지 글자를 받아온다.
		fputc(file_to_c, fout);				// 출력파일에 입력파일 내용을 하나씩 넣어준다.
	fclose(fin);							// 반복문이 종료후, 입력파일을 닫아준다.
	fclose(fout);							// 모든과정이 끝난 후 출력파일을 닫아준다.

	return 0;
}
