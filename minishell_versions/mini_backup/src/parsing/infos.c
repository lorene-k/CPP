#include "minishell.h"

int count_pipes(char *s)
{
    int i;
    int words;

    words = 0;
	i = 0;
	while (s[i])
	{
        if(s[i] == '|')
            words++;
		i++;
	}
	return (words);
}

