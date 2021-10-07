#include <stdio.h>
#define TF 9 // (Matriz Quadrada) de 1 a 9, para não estourar o desenho
// by: Victor R.

const int show1(int mat[][TF], int l, int c)
{
  printf("[0%d]", mat[l][c]);
}

const int show2(int mat[][TF], int l, int c)
{
  printf("[%d]", mat[l][c]);
}

int main()
{
  int mat[TF][TF], l, c, cont;

  for (cont = 1, l = 0; l < TF; l++)
    for (c = 0; c < TF; c++)
    {
      mat[l][c] = cont;
      cont++;
    }

  putchar('\n');
  for (l = 0; l < TF; l++)
  {
    for (c = 0; c < TF; c++)
      mat[l][c] < 10 ? show1(mat, l, c) : show2(mat, l, c);
    putchar('\n');
  }

  printf("--------------------------------------");
  printf("\nElementos Acima da Diagonal Principal\n\n");
  for (l = 0; l < TF - 1; l++)
  {
    for (c = 0; c < TF; c++)
      l + 1 <= c ? mat[l][c] < 10 ? show1(mat, l, c) : show2(mat, l, c) : printf("    ");
    putchar('\n');
  }

  printf("\n--------------------------------------");
  printf("\nElementos da Diagonal Principal\n\n");
  for (l = 0; l < TF; l++)
  {
    for (c = 0; c < l + 1; c++)
      l == c ? mat[l][c] < 10 ? show1(mat, l, c) : show2(mat, l, c) : printf("    ");
    putchar('\n');
  }

  printf("\n--------------------------------------");
  printf("\nElementos Abaixo da Diagonal Principal\n\n");
  for (l = 1; l < TF; l++)
  {
    for (c = 0; c < l; c++)
      mat[l][c] < 10 ? show1(mat, l, c) : show2(mat, l, c);
    putchar('\n');
  }

  printf("\n--------------------------------------");
  printf("\nElementos Acima da Diagonal Secundaria\n\n");
  for (l = 0; l < TF; l++)
  {
    for (c = 0; c < TF - 1 - l; c++)
      mat[l][c] < 10 ? show1(mat, l, c) : show2(mat, l, c);
    putchar('\n');
  }

  printf("--------------------------------------");
  printf("\nElementos da Diagonal Secundaria\n\n");
  for (l = 0; l < TF; l++)
  {
    for (c = 0; c < TF - l; c++)
      c == TF - 1 - l ? mat[l][c] < 10 ? show1(mat, l, c) : show2(mat, l, c) : printf("    ");
    putchar('\n');
  }

  printf("\n--------------------------------------");
  printf("\nElementos Abaixo da Diagonal Secundaria\n\n");
  for (l = 1; l < TF; l++)
  {
    for (c = 0; c < TF; c++)
      c > TF - 1 - l ? mat[l][c] < 10 ? show1(mat, l, c) : show2(mat, l, c) : printf("    ");
    putchar('\n');
  }
  printf("\nBy: Victor R.\nhttps://github.com/taveirasrc/\nhttps://github.com/taveirasrc/c-files/blob/master/DPDS.c\n");
  getc(stdin);
}