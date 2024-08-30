#include "minishell.h"


//// ATTENTION AUX LEAKS D EMEMOIRE , TOUT REVOIR


// Cree les paths pour les commandes a partir du tableau de variables denvironnement 
void init_env_var(t_infos *infos, char **envp)
{
    //if (infos->paths)

    //infos->paths = ft_split(get_env_var(infos, "PATH"), ':');
}

// Renvoi 1 si la variable d'environnement existe dans la table sinon renvoi 0
int env_var_exists(t_infos *infos, char *key)
{
    char    *temp_key;
    int len;
    int i;

    temp_key = ft_strjoin(key, "=");
    if (!temp_key)
        protect_memory(infos, 0, 0);
    len = ft_strlen(temp_key);
    i = 0;
    while (infos->new_envp[i]!=NULL)
    {
        if (ft_strncmp(infos->new_envp[i], temp_key, len) == 0)
        {
            free(temp_key);
            return (1);
        }
        i++;
    }
    free(temp_key);
    return (0);
}

void add_env_var(t_infos *infos, char *key, char *value)
{
    int i;
    char *temp_key;
    int len;
    char    *temp_str;

    i = 0;
    char    *new_str;


    temp_str = ft_strjoin(key, "=");
    if (!temp_str)
        protect_memory(infos, 0, 0);
    new_str = ft_strjoin(temp_str, value); // Leak a revoir !!!!!!!!!!!!!!
    if (!new_str)
        protect_memory(infos, temp_str, 0);
    free(temp_str);
    temp_key = ft_strjoin(key, "=");
    if (!temp_key)
        protect_memory(infos, new_str, 0);
    len = ft_strlen(temp_key);
    while (infos->new_envp[i]!=NULL)
    {
        if (ft_strncmp(infos->new_envp[i], temp_key, len) == 0)
        {
            free(infos->new_envp[i]);
            free(temp_key);
            infos->new_envp[i] = ft_strdup(new_str); // A VOIR
            if (!infos->new_envp[i])
                protect_memory(infos, new_str, 0);
            free(new_str);
            return ;
        }
        i++;
    }
    // Si la valeur n'existe pas :/ A FINIR !!!!!
    int z = 0;
    char **new_envp = malloc(sizeof(char *) * (i + 2));
    if (!new_envp)
    {    
        free(new_str);
        protect_memory(infos, temp_key, 0);
    }
    while (z < i)
    {
        new_envp[z] = infos->new_envp[z];
        z++;
    }
    new_envp[z] = ft_strdup(new_str);
    free(temp_key);
    free(new_str);
    if (!new_envp[z])
        protect_memory(infos, 0, 0);
    z++;
    new_envp[z] = NULL;    
    free(infos->new_envp); // test
    infos->new_envp = new_envp;     
}



// Supprime une variable d'environnement
void remove_env_var(t_infos *infos, char *key)
{
    int i;
    char *temp_key;
    int len;
    char    **new_envp;
    int z;

    len = 0;
    if (!env_var_exists(infos, key))
        return ;
    while (infos->new_envp[len]!=NULL)
        len++;
    new_envp = malloc(sizeof(char *) * (len));
    if (!new_envp)
        protect_memory(infos, 0, 0);
    temp_key = ft_strjoin(key, "=");
    if (!temp_key)
        protect_memory(infos, 0, new_envp);
    i = 0;
    z = 0;
    while (infos->new_envp[i]!=NULL)
    {
        if (ft_strncmp(infos->new_envp[i], temp_key, ft_strlen(temp_key)) == 0)
            free(infos->new_envp[i]);
        else
            new_envp[z++] = infos->new_envp[i];
        i++;
    }
    new_envp[z] = NULL;
    free(infos->new_envp);   // A FAIRE : free tout le contenu de chaque strng
    free(temp_key);
    infos->new_envp = new_envp;
    free(new_envp);
}



char	*find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
	{
		envp++;
	}
	return (*envp + 5);
}





void set_infos_path(t_infos *infos)
{
	infos->paths = ft_split(get_env_var(infos, "PATH"), ':');
    if (!infos->paths)
        protect_memory(infos, 0, 0);
}

// Retourne la valeur d'une variable d'environnement
char *get_env_var(t_infos *infos, char *key)
{
    int i;
    char *temp_key;
    int len;
    char *env_var;

    i = 0;
    env_var = NULL;
    if(!env_var_exists(infos, key))
        return (NULL);

    temp_key = ft_strjoin(key, "=");
    if (!temp_key)
        protect_memory(infos, 0, 0);
    len = ft_strlen(temp_key);
    while (infos->new_envp[i]!=NULL)
    {
        // printf("%s \n", infos->new_envp[i]);
        if (ft_strncmp(infos->new_envp[i], temp_key, len) == 0)
        {
            // write(1, "M", 1);
            // ft_substr(infos->new_envp[i], len, ft_strlen(infos->new_envp[i]));
            free(temp_key);
            env_var = ft_substr(infos->new_envp[i], len, ft_strlen(infos->new_envp[i]));
            if (!env_var)
                protect_memory(infos, 0, 0);
            return (env_var);
        }
        i++;
    }
    free(temp_key);
    return (NULL);
}

// Retourne 1 si la chaine de caractère contient au moins une variable d'environnement non traitée ($var)
int contains_env_var(char  *str)
{
    int i;
    int len;
    char *var_key;
    int z;
    int len_var_key;

    z = 0;
    i = 0;
    len = ft_strlen(str);
    len_var_key = 0;
    while (i < len)
    {
        if (str[i] == '$' && i + 1 < len && (ft_isalpha(str[i + 1])))
            return (1);
        i++;
    }  
    return (0);
}

// Retourne 1 si la chaine de caractère contient au moins un $? non traitée ($var)
int contains_return_code_var(char  *str)
{
    int i;
    int len;
    char *var_key;
    int z;
    int len_var_key;

    z = 0;
    i = 0;
    len = ft_strlen(str);
    len_var_key = 0;
    while (i < len)
    {
        if (str[i] == '$' && i + 1 < len && (str[i + 1] == '?'))
            return (1);
        i++;
    }  
    return (0);
}

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
    if (!first)
        protect_memory(infos, 0, 0);
    var_content = get_env_var(infos, key);
    if (var_content != NULL)
    {
        second = ft_strjoin(first, var_content);
        free(var_content);
    }
    else
        second = ft_strjoin(first, "");
    free(first);
    if (!second)
        protect_memory(infos, 0, 0);
    i++;
    while(ft_isalnum(str[i]) && i < ft_strlen(str))
        i++;
    third = ft_substr(str, i, ft_strlen(str));
    if (!third)
        protect_memory(infos, second, 0);
    final = ft_strjoin(second, third);
    if (!final)
    {   
        free(second); 
        protect_memory(infos, third, 0);
    }
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
            if (!first)
                protect_memory(infos, 0, 0);
            if (heredoc == 1)
                var_content = ft_itoa(infos->sig_id_heredoc);
            else
                var_content = ft_itoa(sig_id);
            if (var_content != NULL) //CAN'T PROTECT MALLOC HERE - check behavior
            {
                second = ft_strjoin(first, var_content);
                free(var_content);
            }
            else
                second = ft_strjoin(first, "");
            free(first);
            if (!second)
                protect_memory(infos, 0, 0); //check leaks
            i++;
            i++;
            while(ft_isalnum(str[i]) && i < ft_strlen(str))
                i++;
            third = ft_substr(str, i, ft_strlen(str));
            if (!third)
                protect_memory(infos, 0, 0);
            final = ft_strjoin(second, third);
            if (!final)
            {   
                free(second); 
                protect_memory(infos, third, 0);
            }
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
    if (!var_key)
        protect_memory(infos, 0, 0);
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
    if (!var_key)
        protect_memory(infos, 0, 0);
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
    if (!contains_env_var(str) && !contains_return_code_var(str))
        return (ft_strdup(str));
    while (contains_env_var(str) || contains_return_code_var(str))
        str = replace_str_var_one(infos, str);
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