#include "minishell.h"


// static size_t	ft_count_words(char const *s, char c)
// {
// 	size_t	words;
// 	size_t	i;

// 	words = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
// 			words++;
// 		i++;
// 	}
// 	return (words);
// }



// A PARTIR D'UN INPUT DANS LE TERMINAL : CREE LES TOKENS, separe : "echo toto $ABC" en : "echo" "toto" "$ABC"
char **generate_tokens_array_new(char *str)
{

  char  **splitted;
  int  i;

  splitted = ft_split(str, ' ');
  if (!splitted)
  {
    return (NULL);
  }
  return (splitted);
}