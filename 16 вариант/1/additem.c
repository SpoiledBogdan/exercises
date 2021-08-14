#include "head.h"

void AddItem(char * FileName, int *Count)
{
	int result, i = (*Count);
	struct myStruct TR, Temp;
	FILE *in, *out;
	char ch;
 	if(( in = fopen(FileName, "r")) == NULL)
  {
		printf("Файл для чтения не найден");
  	return ;
  }  
  if(( out = fopen("test1", "w+")) == NULL)
  {
    printf("Невозможно создать файл для записи");
    return ;
  }
	fscanf(in, "%d", Count);
	fprintf(out, "%d\n", (*Count)+1);
	if(*Count == MAX_TR)
	{
		while(1)
		{
			printf("Внимание Список полностью заполнен! Последний элемент будет заменен!\nПродолжить ? (1 - Да, 2 - Нет): ");
			while(scanf("%d", &result) != 1)
			{
				printf("Некорректный ввод!\n");
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
		printf("Введите номер элемента после которого хотите вставить запись: ");
		while(scanf("%d", &result) != 1)
		{
			printf("Некорректный ввод!\n");
			ClearBuffer();
			continue;
		}
		ClearBuffer();
		if(result > 0 && result < MAX_TR) break;
	}
	printf("Введите название трансформатора %d: ", result + 1);
	scanf("%s", TR.Name);
	ClearBuffer();
	printf("Введите страну производитель: ");
	scanf("%s", TR.Country);
	ClearBuffer();
	while (1)
	{
		printf("Введите значение мощности P: ");
		while (scanf("%d", &TR.P) != 1)
		{
			printf("Некорректное значение!\n");
			ClearBuffer();
			continue;
		}
		ClearBuffer();
		if (TR.P > 0) break;
		else printf("Вводимое значение должно быть больше 0!\n\n");
	}
	while (1)
	{
		printf("Введите значение тока I: ");
		while (scanf("%d", &TR.I) != 1)
		{
			printf("Некорректное значение!\n");
			ClearBuffer();
			continue;
		}
		ClearBuffer();
		if (TR.I > 0) break;
		else printf("Вводимое значение должно быть больше 0!\n\n");
	}
	printf("Введите выходное напряжение: ");
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
		printf("Файл для чтения не найден");
  	return ;
  }  
  if(( out = fopen("test1", "r")) == NULL)
  {
    printf("Невозможно создать файл для записи");
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
