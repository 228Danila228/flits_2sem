#include <stdio.h>
#include <stdbool.h>

int main()
{
  FILE *f1, *f2;
  char arr[101][101], s; 
  int i = 0, j = 0;
  f1 = fopen("ИМЯ ФАЙЛА С МАТРИЦЕЙ", "r");
  while (!feof(f1))
  {
    fscanf(f1, "%c", &s);
    if (s != ' ' && s != '\n') 
    {
      arr[i][j] = s; 
      j++; 
      if (j == 20)
      {
        i++; 
        j = 0;
      }
    }
  }
  bool flag;
  f2 = fopen("graf.gv", "w");
  fprintf(f2, "graph dzgraf {\n");  
  for(int d = 0;d<5;d++){
    fprintf(f2, "%d\n", d+1);
  }
  for (int a = 0; a < 20; a++) 
  {
    flag = true;
    for (int y = 0; y < 5; y++)
    {
      if (arr[y][a] != '0')
      {
        if (flag) 
        {
          fprintf(f2, "%d", y + 1);
          printf("%d", y + 1);
          flag = false;
        }
        else
        {
          printf(" -- %d", y + 1);
          fprintf(f2, " -- %d [label = ""%d""]", y + 1, a+1);
        }
      }
    }
    fprintf(f2, "\n");
    printf("\n");
  }
  fprintf(f2, "}");
  fclose(f2);
}
