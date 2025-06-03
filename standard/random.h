#ifndef __RANDOM__
#define __RANDOM__

#define WORD_LENGTH 8 // Define the length of the generated word
#define CHARSET                                                                \
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" // Characters
                                                                   // to pick
                                                                   // from


char *generate_random_string(char *word, int length) {

  int charset_length = strlen(CHARSET);
  for (int x = 0; x < length; x++) {
    word[x] = CHARSET[rand() % charset_length];
  }
  word[length] = '\0';
}

char **generate_random_word_array(int length_array, int length_word) {

  char **str = (char **)malloc(length_array * (length_word * sizeof(char *)));

  for (int x = 0; x < length_array; x++) {
    str[x] = (char *)malloc(length_word * sizeof(char *));
    generate_random_string(str[x], length_word);
    printf("%s \n", str[x]);
  }

  return str;
}


#endif