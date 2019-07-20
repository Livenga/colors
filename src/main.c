#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>


#define BOLD      (1)
#define OPACITY   (2)
#define ITALIC    (3)
#define UNDERLINE (4)
#define BLINK     (5)


int
main(int argc, char *argv[]) {
  const struct option longopts[] = {
    //{"normal",    no_argument, NULL, 'n'}, // 0
    {"bold",      no_argument, NULL, 'B'}, // 1
    {"italic",    no_argument, NULL, 'i'}, // 3
    {"underline", no_argument, NULL, 'u'}, // 4
    {"blink",     no_argument, NULL, 'b'}, // 5
    //{"fast-blink", no_argument, NULL, 'f'}, // 6
    {0, 0, 0, 0},
  };

  int i, j;
  int opt, longindex;
  char effect[32];

  memset((void *)effect, '\0', sizeof(effect));

  while((opt = getopt_long(argc, argv, "Biub",
          longopts, &longindex)) > 0) {
    switch(opt) {
      case 'B':
        if(strchr(effect, '1') == NULL)
          strncat(effect, "1;", 31);
        break;
      case 'i':
        if(strchr(effect, '3') == NULL)
        strncat(effect, "3;", 31);
        break;
      case 'u':
        if(strchr(effect, '4') == NULL)
          strncat(effect, "4;", 31);
        break;
      case 'b':
        if(strchr(effect, '5') == NULL)
          strncat(effect, "5;", 31);
        break;
    }
  }
  if(strlen(effect) != 0)
    printf("* Enabled effects: %s\n\n", effect);


  printf("    |");
  for(j = 0; j < 8; ++j) {
    printf("   %2d  |", j + 40);
  }
  putchar('\n');

  for(i = 0; i < 8; ++i) {
    printf(" %2d |", 30 + i);
    for(j = 0; j < 8; ++j) {
      if(strchr(effect, '5') != NULL && j == 0) {
        printf("\033[%s%dm Hello \033[0m|", effect, 30 + i);
      } else {
        printf("\033[%s%d;%dm Hello \033[0m|", effect, 30 + i, 40 + j);
      }
    }
    putchar('\n');
  }

	return 0;
}
