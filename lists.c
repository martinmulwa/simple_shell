#include "main.h"

/**
 * add_node_end - adds a new node at the end of a list_s list
 * @head: pointer to the address of the first node
 * @name: the value of the name field of the new node
 * @value: the value of the value field of the new node
 *
 * Return: head of the new list. Otherwise NULL
 */
list_t *add_node_end(list_t **head, const char *name, const char *value)
{
	list_t *trav, *new;
	int index = 0;

	if (head == NULL || name == NULL || value == NULL)
		return (NULL);

	trav = *head;

	/* create the new node */
	new = create_node(name, value, index);
	if (new == NULL)
		return (NULL);

	/* if the list has no elements */
	if (trav == NULL)
	{
		*head = new;
		return (*head);
	}

	/* traverse to the end of the list */
	while (trav->next != NULL)
	{
		index++;
		trav = trav->next;
	}

	new->index = index;
	trav->next = new;

	return (*head);
}

/**
 * list_len - finds the number of elements in a linked list_t list
 * @h: pointer to a list_t
 *
 * Return: number of elements in the list_t
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}

/**
 * create_node - creates a new list_t node
 * @name: value of the name field
 * @value: value of the value field
 * @index: index of the new node
 *
 * Return: address of new node. Otherwise NULL
 */
list_t *create_node(const char *name, const char *value, int index)
{
	list_t *new;

	if (name == NULL || value == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->name = _strdup(name);
	new->value = _strdup(value);
	new->index = index;
	new->next = NULL;

	return (new);
}

/**
 * split_string - splits a given string using a given delimiter
 * @s: string to split
 * @delim: delimiter
 *
 * Return: list of strings
 */
list_t *split_string(char *s, char *delim)
{
	char *str, *next_str;
	list_t *strings = NULL;

	if (s == NULL || delim == NULL)
	{
		return (NULL);
	}

	str = _strdup(s);

	/* get first string */
	add_node_end(&strings, _strtok(str, delim), "");

	/* get all other strings */
	while ((next_str = _strtok(NULL, delim)))
		add_node_end(&strings, next_str, "");

	free(str);

	return (strings);
}

/**
 * free_node - frees a list_t node
 * @h: pointer to list_t node
 */
void free_node(list_t *h)
{
	if (h == NULL)
		return;

	if (h->name)
		free(h->name);

	if (h->value)
		free(h->value);

	free(h);
	h = NULL;
}

/**
 * free_list - frees a list_t list
 * @h: list_t head
 */
void free_list(list_t *h)
{
	list_t *current;

	if (h == NULL)
		return;

	while (h != NULL)
	{
		current = h;
		h = h->next;
		free_node(current);
	}

}

/**
 * list_to_array - converts a given list of strings into an array of strings
 * @h: head of given list
 *
 * Return: an array of strings. Otherwise NULL
 */
char **list_to_array(const list_t *h)
{
	char **array;
	unsigned int i, length;

	if (h == NULL)
		return (NULL);

	/* allocate space for array */
	length = list_len(h);
	array = malloc(sizeof(char *) * (length + 1));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < length && h; i++, h = h->next)
		array[i] = _strdup(h->name);

	array[length] = NULL;

	return (array);
}

/**
  * free_array - frees an array of strings
  * arr: array
  */
void free_array(char **arr)
{
	unsigned int i;

	for (i = 0; arr && arr[i]; i++)
		free(arr[i]);

	if (arr)
	{
		free(arr);
	}

	arr = NULL;
 }

 /**
  * print_list - prints all the elements of a list_t list in a given format
  * @h: pointer to a list_t
  *
  * Return: number of nodes in given list_t
  */
 size_t print_list(const list_t *h)
 {
 	size_t count = 0;

 	while (h != NULL)
 	{
 		printf("%s\n", h->name);

 		count++;
 		h = h->next;
 	}

 	return (count);
 }
