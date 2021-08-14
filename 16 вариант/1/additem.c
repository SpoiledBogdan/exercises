#include "head.h"

void AddItem(char * FileName, int *Count)
{
	int result, i = (*Count);
	struct myStruct TR, Temp;
	FILE *in, *out;
	char ch;
 	if(( in = fopen(FileName, "r")) == NULL)
  {
		printf("���� ��� ������ �� ������");
  	return ;
  }  
  if(( out = fopen("test1", "w+")) == NULL)
  {
    printf("���������� ������� ���� ��� ������");
    return ;
  }
	fscanf(in, "%d", Count);
	fprintf(out, "%d\n", (*Count)+1);
	if(*Count == MAX_TR)
	{
		while(1)
		{
			printf("�������� ������ ��������� ��������! ��������� ������� ����� �������!\n���������� ? (1 - ��, 2 - ���): ");
			while(scanf("%d", &result) != 1)
			{
				printf("������������ ����!\n");
				ClearBuffer();
				continue;
			}
			ClearBuffer();
			if(result == 1)break;
			else
			{
				return ;
			}
		}
	}
	while(1)
	{
		printf("������� ����� �������� ����� �������� ������ �������� ������: ");
		while(scanf("%d", &result) != 1)
		{
			printf("������������ ����!\n");
			ClearBuffer();
			continue;
		}
		ClearBuffer();
		if(result > 0 && result < MAX_TR) break;
	}
	printf("������� �������� �������������� %d: ", result + 1);
	scanf("%s", TR.Name);
	ClearBuffer();
	printf("������� ������ �������������: ");
	scanf("%s", TR.Country);
	ClearBuffer();
	while (1)
	{
		printf("������� �������� �������� P: ");
		while (scanf("%d", &TR.P) != 1)
		{
			printf("������������ ��������!\n");
			ClearBuffer();
			continue;
		}
		ClearBuffer();
		if (TR.P > 0) break;
		else printf("�������� �������� ������ ���� ������ 0!\n\n");
	}
	while (1)
	{
		printf("������� �������� ���� I: ");
		while (scanf("%d", &TR.I) != 1)
		{
			printf("������������ ��������!\n");
			ClearBuffer();
			continue;
		}
		ClearBuffer();
		if (TR.I > 0) break;
		else printf("�������� �������� ������ ���� ������ 0!\n\n");
	}
	printf("������� �������� ����������: ");
	scanf("%d", &TR.Uvt);
	ClearBuffer();
	for(i = 0; i != (*Count); i++)
	{
		fscanf(in, "%s%s%d%d%d", Temp.Name, Temp.Country, &Temp.P, &Temp.I, &Temp.Uvt);
		fprintf(out, "%s %s %d %d %d\n", Temp.Name, Temp.Country, Temp.P, Temp.I, Temp.Uvt);
		if(i == result-1)
		{ 
			fseek(out, 0, SEEK_END);
			fprintf(out, "%s %s %d %d %d\n", TR.Name, TR.Country, TR.P, TR.I, TR.Uvt);
		}
  }
  fclose(in);
  fclose(out);
	
	if(( in = fopen(FileName, "w+")) == NULL)
  {
		printf("���� ��� ������ �� ������");
  	return ;
  }  
  if(( out = fopen("test1", "r")) == NULL)
  {
    printf("���������� ������� ���� ��� ������");
    return ;
  }
  while(!feof(out))
  {
    ch=getc(out);
  	if(!feof(out)) putc(ch, in);   
  }
  fclose(in);
  fclose(out);
	remove("test1");
	(*Count)++;
	return ;
}
