#include "minishell.h"


// Remplace une variable d'environnement par son contenu (une seule occurence avec la key donnee) en partant de i (curseur)
char *replace_one_var_on_str_from(t_infos *infos, char *str, char *key, int i)
{
    char *first;
    char *second;
    char *third;
    char *final;
    char *var_content;

            if (i == 0)
                first = strdup("");
            else
                first = ft_substr(str, 0, i);


            if (env_var_exists(infos, "PATH") == 1)
            {
                var_content = get_env_var(infos, key);
                second = ft_strjoin(first, var_content);
                free(var_content);
            }
            else
            {
                second = ft_strjoin(first, ""); 
            }
            free(first);
            i++;
            while(ft_isalnum(str[i]) && i < ft_strlen(str))
                i++;
            third = ft_substr(str, i, ft_strlen(str));
            final = ft_strjoin(second, third);
            return (free(second), free(third), final);
}

// Remplace la premiere occurence de $? par 127 par ex en partant de i (curseur)
char *replace_one_return_code_on_str_from(t_infos *infos, char *str, int i, int heredoc)
{
    char *first;
    char *second;
    char *third;
    char *final;
    char *var_content;

            if (i == 0)
                first = strdup("");
            else
                first = ft_substr(str, 0, i);

            if (heredoc == 1)
                var_content = ft_itoa(infos->g_sig_id_heredoc);
            else
                var_content = ft_itoa(g_sig_id);
            if (var_content != NULL)
            {
                second = ft_strjoin(first, var_content);

                free(var_content);
            }
            else
                second = ft_strjoin(first, "");
            free(first);
            i++;
            i++;
            while(ft_isalnum(str[i]) && i < ft_strlen(str))
                i++;
            third = ft_substr(str, i, ft_strlen(str));
            final = ft_strjoin(second, third);
            return (free(second), free(third), final);
}

// Remplace la première occurence $var par le contenu de la variable d'environnement var
char *replace_str_var_with_content(t_infos *infos, char *str, char *key)
{
    int i;

    i = 0;

    while (i < ft_strlen(str))
    {
        if (str[i] == '$' && i + 1 < ft_strlen(str) && (ft_isalpha(str[i + 1])))
        {
            return (replace_one_var_on_str_from(infos, str, key, i));
        }
        else if (str[i] == '$' && i + 1 < ft_strlen(str) && str[i + 1] == '?')
        {
            return (replace_one_return_code_on_str_from(infos, str, i, 0));
        }
        i++;
    }
    return (NULL);
}


// Remplace la première occurence $var par le contenu de la variable d'environnement var
char *replace_str_var_with_content_heredoc(t_infos *infos, char *str, char *key)
{
    int i;

    i = 0;

    while (i < ft_strlen(str))
    {
        if (str[i] == '$' && i + 1 < ft_strlen(str) && (ft_isalpha(str[i + 1])))
        {
            return (replace_one_var_on_str_from(infos, str, key, i));
        }
        else if (str[i] == '$' && i + 1 < ft_strlen(str) && str[i + 1] == '?')
        {
            return (replace_one_return_code_on_str_from(infos, str, i, 1));
        }
        i++;
    }
    return (NULL);
}


// Prepare puis modifie la chaine de caractere qui contient une $VARIABLE_GLOBALE, APPELLE DEPUIS replace_str_var
// Retourne la nouvelle chaine de caractere modifiee  (ex : "$PATH ABC $PATH" devient "Contenu_de_path ABC $PATH") 
char *prepare_and_replace_one_env_var(t_infos *infos, char *str, int cursor) // i designe le curseur dans la str
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
            z = 0;
            while (z < len_var_key)
            {
                var_key[z] = str[cursor + z];
                z++;
            }
            var_key[z] = '\0';
            new_str = replace_str_var_with_content(infos, str, var_key);
            free(var_key);
    return (new_str);
}

// A FAIRE
// Retourne la nouvelle chaine de caractere modifiee  (ex : "$? ABC $PATH" devient "127 ABC $PATH") 
char *prepare_and_replace_return_code(t_infos *infos, char *str, int cursor) // i designe le curseur dans la str
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
            z = 0;
            while (z < len_var_key)
            {
                var_key[z] = str[cursor + z];
                z++;
            }
            var_key[z] = '\0';
            new_str = replace_str_var_with_content(infos, str, var_key);
            free(var_key);
    return (new_str);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////

// A AMELIORER zz
// Retourne une nouvelle chaine avec les $VAR contenus dans une chaine de caractere par leur valeur (ex : "$PATH ABC $PWD" devient "Contenu_de_path ABC Contenu_pwd") 
char *replace_str_var_one(t_infos *infos, char *str)
{
    int i;
    char *new_str;

    i = 0;

    while (i < ft_strlen(str))
    {
        if (str[i] == '$' && i + 1 < ft_strlen(str) && (ft_isalpha(str[i + 1]))) // Si on tombe sur un $QQCHOSE
        {
            i++;
            new_str = prepare_and_replace_one_env_var(infos, str, i);
            break;
        }
        else if (str[i] == '$' && i + 1 < ft_strlen(str) && str[i + 1] == '?') // Si on tombe sur $?
        {
            i++;
            new_str = prepare_and_replace_return_code(infos, str, i);
            
            break;
            //new_str = replace_str_var_with_content(infos, str, NULL);

        }
        i++;
    }
        return (new_str);
}


char *replace_str_var(t_infos *infos, char *str)
{
    char *new_str;
    if (!contains_env_var(str) && !contains_return_code_var(str))
        return (ft_strdup(str));


    while (contains_env_var(str) || contains_return_code_var(str))
    {
        str = replace_str_var_one(infos, str);
    }
    return (str);

}


// SEGFAULT A CORRIGER
// (ex : "$PATH ABC $PWD" devient "Contenu_de_path ABC Contenu_pwd")  POUR LE HEREDOC UNIQUEMENT
char *replace_str_var_heredoc_one(t_infos *infos, char *str)
{
    int i;
    char *new_str;

    i = 0;

    while (i < ft_strlen(str))
    {
        if (str[i] == '$' && i + 1 < ft_strlen(str) && (ft_isalpha(str[i + 1]))) // Si on tombe sur un $QQCHOSE
        {
            i++;
            new_str = prepare_and_replace_one_env_var(infos, str, i);
            break;
        }
        else if (str[i] == '$' && i + 1 < ft_strlen(str) && str[i + 1] == '?') // Si on tombe sur $?
        {
            i++;
            new_str = replace_str_var_with_content_heredoc(infos, str, NULL);
            break;
        }
        i++;
    }

    // if(contains_env_var(new_str) || contains_return_code_var(new_str)) //// ATTENTION SEGFAULT si : $? et $PWD dans la premiere ligne FONCTIONNE MAIS SI $PWD et $? NON
    //     return (replace_str_var_heredoc(infos, new_str));
    // else
        return (new_str);
}



char *replace_str_var_heredoc(t_infos *infos, char *str)
{
    char *new_str;
    if (!contains_env_var(str) && !contains_return_code_var(str))
        return (strdup(str));


    while (contains_env_var(str) || contains_return_code_var(str))
    {
        str = replace_str_var_heredoc_one(infos, str);
    }
    return (str);

}