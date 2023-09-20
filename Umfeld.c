#include "shell.h"

/**
 * mon_new_var - Initialize a new environment variable or modify an old one
 * @info: a structure to maintain constant function prototype.
 *  Return: Always 0
 */
int mon_new_var(info_t *info)
{
	if (info->argc != 3)
	{
		eput_str("Incorrect number of arguements\n");
		return (1);
	}
	if (novel_env(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * get_var_env - gets the value of an environ variable
 * @info: Structure that maintain constant function prototype
 * @Nom: environment variable's name
 *
 * Return: the value
 */
char *get_var_env(info_t *info, const char *Nom)
{
	list_t *node = info->env;
	char *ptr;

	while (node)
	{
		ptr = start_with(node->str, Nom);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * Mon_envir - prints the current environment
 * @info: A structure tthat maintain constant function prototype.
 * Return: Always 0
 */
int Mon_envir(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * envir_list - a function populates envir linked list
 * @info: A structure that maintain constant function prototype.
 * Return: Always 0
 */
int envir_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * unset_env_var - Remove an environment variable
 * @info: A structure to maintain constant function prototype.
 *  Return: Always 0
 */
int unset_env_var(info_t *info)
{
	if (info->argc != 3)
	{
		eput_str("Incorrect number of arguements\n");
		return (1);
	}
	if (novel_env(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
