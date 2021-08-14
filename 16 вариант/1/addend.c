#include "head.h"

void AddEnd(char * FileName, int *Count)
{
	int result, P = (*Count);
	FILE *out;
	struct myStruct TR;
	if((out = fopen(FileName, "r+")) == NULL)
	{ 
    printf("Невозможно открыть файл для записи\n"); 
    return ; 
  }
	if(*Count == MAX_TR)
	{
		printf("Внимание Список полностью заполнен! Последний элемент будет заменен!\nПродолжить ? (1 - Да, 2 - Нет): ");
		scanf("%d", &result);
		ClearBuffer();
		if(result == 1){ }
		else
		{
			return ;
		}
	}
	printf("Введите название трансформатора номер %d: ", (*Count) + 1);
	scanf("%s", TR.Name);
	ClearBuffer();
	printf("Введите страну произволителя: ");
	scanf("%s", TR.Country);
	ClearBuffer();
	while(1)
	{
		printf("Введите значение мощности P: ");
		while(scanf("%d", &TR.P) != 1)
		{
			printf("Некорректное значение!\n");
			ClearBuffer();
			continue;
		}
		ClearBuffer();
		if(TR.P > 0) break;
		else printf("Вводимое значение должно быть больше 0!\n\n");
	}
	while(1)
	{
		printf("Введите значение тока I: ");
		while(scanf("%d", &TR.I) != 1)
		{
			printf("Некорректное значение!\n");
			ClearBuffer();
			continue;
		}
		ClearBuffer();
		if(TR.I > 0) break;
		else printf("Вводимое значение должно быть больше 0!\n\n");
	}
	printf("Введите выходное напряжение: ");
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
