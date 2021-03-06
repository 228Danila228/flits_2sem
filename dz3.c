#include <stdio.h>
#include <stdlib.h>
int main()
{
  FILE *f1, *f2; 
  char arr[1001][1001], s;
  int i = 0, j = 0, flag = 0,reb =0 ; 
  f1 = fopen("matrix_of_incendence13.txt", "r");
  while (!feof(f1))
  {
    fscanf(f1, "%c", &s); 
    if (s != ' ')
    {
      arr[i][j] = s;
      j++;
      if (s == '\n')
      {
        if(flag == 0){
          reb = j;
          flag = 1;
        }
        i++;
        j = 0;
      }
    }
  }
  i++;reb--;
  char u;
  f2 = fopen("res.gv", "w");
  fprintf(f2, "graph Grath {\n");
  for(int d = 0;d<i;d++){
    fprintf(f2, "%d\n", d+1); 
  }
  for (int a = 0; a < reb; a++)
  {
    u = -1;
    for (int y = 0; y < i; y++)
    {
      if (arr[y][a] != '0')
      {
        if (u == -1)
        {
          fprintf(f2, "%d", y + 1);
          printf("%d", y + 1);
          u = 0;
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
  for (int i = 0; i <= 4; i++)
  {
    for (int j = 0; j <= 4; j++)
    {
      if (arr[i][j] > 1)
        arr[i][j] = 1;
      if (i == j)
        arr[i][j] = 0;
    }
  }
  if (reb >= ((i - 1) * (i - 2) / 2)) // graph connectivity theorem
    {
        printf("graph - connected\n");
        fprintf(f2, "0 [label = connected]\n");
    }
    else
    {
        printf("graph -  not connected\n");
        fprintf(f2, "0 [label = \"not connected\"]\n");
    }
    printf("------------------\n");
  fprintf(f2, "}");
  fclose(f2);
  return 0;
}
