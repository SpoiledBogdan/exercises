#include "head.h"

void AddEnd(char * FileName, int *Count)
{
	int result, P = (*Count);
	FILE *out;
	struct myStruct TR;
	if((out = fopen(FileName, "r+")) == NULL)
	{ 
    printf("���������� ������� ���� ��� ������\n"); 
    return ; 
  }
	if(*Count == MAX_TR)
	{
		printf("�������� ������ ��������� ��������! ��������� ������� ����� �������!\n���������� ? (1 - ��, 2 - ���): ");
		scanf("%d", &result);
		ClearBuffer();
		if(result == 1){ }
		else
		{
			return ;
		}
	}
	printf("������� �������� �������������� ����� %d: ", (*Count) + 1);
	scanf("%s", TR.Name);
	ClearBuffer();
	printf("������� ������ �������������: ");
	scanf("%s", TR.Country);
	ClearBuffer();
	while(1)
	{
		printf("������� �������� �������� P: ");
		while(scanf("%d", &TR.P) != 1)
		{
			printf("������������ ��������!\n");
			ClearBuffer();
			continue;
		}
		ClearBuffer();
		if(TR.P > 0) break;
		else printf("�������� �������� ������ ���� ������ 0!\n\n");
	}
	while(1)
	{
		printf("������� �������� ���� I: ");
		while(scanf("%d", &TR.I) != 1)
		{
			printf("������������ ��������!\n");
			ClearBuffer();
			continue;
		}
		ClearBuffer();
		if(TR.I > 0) break;
		else printf("�������� �������� ������ ���� ������ 0!\n\n");
	}
	printf("������� �������� ����������: ");
	scanf("%d", &TR.Uvt);
	ClearBuffer();
	if(P != MAX_TR) (*Count)++;
	rewind(out);
	fprintf(out, "%d\n", *Count);
	fseek(out, 0, SEEK_END);
	fprintf(out, "%s %s %d %d %d\n", TR.Name, TR.Country, TR.P, TR.I, TR.Uvt);
	fclose(out);
	return ;
}
