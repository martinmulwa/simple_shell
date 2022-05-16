#include "main.h"

/**
 * create_env - creates a list of environment variables
 * @env: array of environment variables
 *
 * Return: new head of list. Otherwise NULL
 */
list_t *create_env(char **env, list_t *env_list)
{
	unsigned int i;
	char *name, *value;

	if (env == NULL)
	{
		return (NULL);
	}

	for (i = 0; env[i]; i++)
	{
		name = _strtok(env[i], "=");
		value = _strtok(NULL, "\n");

		if (add_node_end(&env_list, name, value) == NULL)
		{
			return (NULL);
		}
	}

	return (env_list);
}

/**
 * _getenv - gets the value of an environment variable
 * @env_list: list of environment variables
 * @name: environment variable
 *
 * Return: value of name. Otherwise NULL
 */
char *_getenv(list_t *env_list, char *name)
{
	list_t *trav = env_list;

	if (name == NULL)
	{
		return (NULL);
	}


	while (trav && _strcmp(trav->name, name))  /* check each node for a match */
	{
		trav = trav->next;
	}


	if (trav)
		return (trav->value);

	return (NULL);
}

/**
 * print_env - prints all the environment variables
 * @env_list: list of environment variables
 */
void print_env(list_t *env_list)
{
	list_t *trav = env_list;
	/*unsigned int index = 0;*/

	while (trav != NULL)
	{
		printf("%s=", trav->name);
		printf("%s\n", trav->value);

		trav = trav->next;
	}
}
