#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fin, *fout;
	char infile[128], outfile[128];
	char buffer[5] = {
		0,
	};
	printf("입력 파일 이름 : ");
	scanf("%s", infile);
	printf("출력 파일 이름 : ");
	scanf("%s", outfile);

	fin = fopen(infile, "r");
	if (fin == NULL)
	{
		printf("Error : 파일 %s을 열 수 없습니다.\n", infile);
		exit(1);
	}

	fout = fopen(outfile, "w");
	if (fout == NULL)
	{
		printf("Error : 파일 %s을 열 수 없습니다.\n", outfile);
		exit(1);
	}

	while ((fread(buffer, sizeof(char), 1, fin)) != 0)
		fwrite(buffer, sizeof(char), 1, fout);

	fclose(fin);
	fclose(fout);

	return 0;
}
