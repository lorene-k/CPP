#include "minishell.h"


// Ce fichier CONTIENT LES NOUVELLES FONCTIONS A UTILISER POUR EXPANSION




// Obtient le nom de la variable d'environnement (premiere occurence) a partir du curseur cursor
char *get_first_var_key(t_infos *infos, char *str, int cursor) // i designe le curseur dans la str
{
    int z;
    int len_var_key;
    char *var_key;
    char *new_str;

    len_var_key = 0;
            z = cursor;
            while(ft_isalnum(str[z]) && z++ < ft_strlen(str))
                len_var_key++;
            var_key = malloc(sizeof(char) * (len_var_key + 1));
            if (!var_key)
                return (NULL);
            z = 0;
            while (z < len_var_key)
            {
                var_key[z] = str[cursor + z];
                z++;
            }
            var_key[z] = '\0';
    return (var_key);
}


// Crée la premiere partie de la string lorsque l'on fait l'expansion (pour le $VAR UNIQUEMENT)
static char *first_part_replace_one_var(t_infos *infos, char *str, char *key, int i)
{
    char *first;
    char *second;
    char *var_content;
    int ret;

            if (i == 0)
                first = strdup("");
            else
                first = ft_substr(str, 0, i);
            if(!first)
                return (NULL);
            ret = env_var_exists(infos, key);
            if (ret == 1)
            {
                var_content = get_env_var(infos, key);
                if (!var_content)
                    return (free(first), NULL);
                second = ft_strjoin(first, var_content);
                free(var_content);
                if(!second)
                    return(free(first), NULL);
            }
            else if (ret == 0)
            {
                second = ft_strjoin(first, ""); 
                if(!second)
                    return (free(first), NULL);
            }
            else if (ret == -1)
                return (free(first), NULL);
            return (free(first), second);
}


// Crée la premiere partie de la string lorsque l'on fait l'expansion (pour le $? UNIQUEMENT)
static char *first_part_replace_one_var_sig(t_infos *infos, char *str, int heredoc, int i)
{
    char *first;
    char *second;
    char *var_content;
    int ret;

            if (i == 0)
                first = strdup("");
            else
                first = ft_substr(str, 0, i);
            if(!first)
                return (NULL);
            if (heredoc == 1)
                var_content = ft_itoa(infos->sig_id_heredoc);
            else
                var_content = ft_itoa(sig_id);
            if (var_content != NULL)
            {
                second = ft_strjoin(first, var_content);
                free(var_content);
            }
            return (free(first), second);
}


// Remplace une variable d'environnement $VAR par son contenu (une seule occurence avec la key donnee) en partant de i (curseur)
char *replace_one_var_on_str_from_new(t_infos *infos, char *str, char *key, int i)
{
    char *second;
    char *third;
    char *final;
    char    *var_content;

            second = first_part_replace_one_var(infos, str, key, i);
            if (!second)
                return (NULL);
            i++;
            while(ft_isalnum(str[i]) && i < ft_strlen(str))
                i++;
            third = ft_substr(str, i, ft_strlen(str));
            if(!third)
                return (free(second), NULL);
            final = ft_strjoin(second, third);
            if (!final)
                return (free(second), free(third), NULL);
            return (free(second), free(third), final);
}

// Remplace la premiere occurence de $? par 127 par ex en partant de i (curseur)
char *replace_one_return_code_on_str_from_new(t_infos *infos, char *str, int i, int heredoc)
{
    char *second;
    char *third;
    char *final;

            second = first_part_replace_one_var_sig(infos, str, heredoc, i);
            if (!second)
                return (NULL);

            i += 2;
            while(ft_isalnum(str[i]) && i < ft_strlen(str))
                i++;
            third = ft_substr(str, i, ft_strlen(str));
            if(!third)
                return (free(second), NULL);
            final = ft_strjoin(second, third);
            if (!final)
                return (free(second), free(third), NULL);
            return (free(second), free(third), final);

}

// A FAIRE : creer une fonction qui prend en parametre : le cursuer et la str, renvoi 1 OU 0 si on doit faire expansion lorsque le $ a pour index (cuseur).
// ex : "$PWD"'$TOTO' (str, 1 : le curseur) renvoi 1 mais (str, 7) renvoie 0


// Retourne une nouvelle chaine avec une seule occurence de remplacée (ex : "Hello $PATH $PWD" devient "Hello ... $PWD")
char *replace_str_var_one_new(t_infos *infos, char *str, int heredoc, int *cursor)
{
    int i;
    char *new_str;
    char *var_key;
    i = 0;

    i = *cursor;
    while (i < ft_strlen(str))
    {
        if (str[i] == '$' && i + 1 < ft_strlen(str) && (ft_isalpha(str[i + 1]))) // Si on tombe sur un $QQCHOSE
        {
            i++;
            var_key = get_first_var_key(infos, str, i);
            if (!var_key)
                return (NULL);
            new_str = replace_one_var_on_str_from_new(infos, str, var_key, i - 1);
            if (!new_str)
                return (free(var_key), NULL); 
            free(var_key);
            *cursor = i;
            return (new_str);
            break;
        }
        else if (str[i] == '$' && i + 1 < ft_strlen(str) && str[i + 1] == '?') // Si on tombe sur $?
        {
            i++;
            new_str = replace_one_return_code_on_str_from_new(infos, str, i - 1, heredoc);
            *cursor = i;
            return (new_str);
            break;
        }
        i++;
    }
        return (str);
}

// Appelé pour remplace toutes les occurences $? et $VAR dans une chaine de caractère
char *replace_str_var_new(t_infos *infos, char *str)
{

    int cursor;
    char *new_str;

    cursor = 0;
    if(!str)
        return (NULL);

    if (!contains_env_var(str) && !contains_return_code_var(str))
        return (ft_strdup(str));

    while (str != NULL && (contains_env_var(str) || contains_return_code_var(str)))
    {
        str = replace_str_var_one_new(infos, str, 0, &cursor);
    }
    return (str);
}


// Appelé pour remplace toutes les occurences $? et $VAR dans une chaine de caractère (pour le heredoc)
char *replace_str_var_heredoc_new(t_infos *infos, char *str)
{
    int cursor;
    char *new_str;

    cursor = 0;
    if(!str)
        return (NULL);

    if (!contains_env_var(str) && !contains_return_code_var(str))
        return (ft_strdup(str));

    while (str != NULL && (contains_env_var(str) || contains_return_code_var(str)))
    {
        str = replace_str_var_one_new(infos, str, 1, &cursor);
    }
    return (str);
}