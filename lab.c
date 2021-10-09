# include <stdio.h>
# include <string.h>


void propriedades(char *buff) {	
  *buff = '\0';
  for(int i = 0; i < 8; i++)
  {
    strcat(buff, "[#]");
  }
}

void propriedades2(char *buff) {	
  *buff = '\0';

  for(int i = 0; i < 8; i++)
  {
    strcat(buff, "[-]");
  }
}

int main()
{
  char buff[25] = "";
  
  propriedades(buff);
  printf("1-%s\n", buff);

  propriedades2(buff);
  printf("2-%s\n", buff);
  printf("Len: %d\n", strlen("[C][C][C][C][C][C][C][C]"));
  return 0;
}