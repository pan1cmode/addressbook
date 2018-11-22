#include "data_structures/s_linked_list.h"
#include "common.h"
#include "s_contact.h"

s_linked_list *create_linked_list() {
	s_linked_list *list = malloc(sizeof(s_linked_list));
	list->head = NULL;
	list->tail = NULL;

	list->length = 0;

	return list;
}

bool push_to_list(s_linked_list *list, void *data) {
	struct s_node* new_item = malloc(sizeof(struct s_node));

	new_item->data = data;
	new_item->next = NULL;

	if (list->head == NULL)
	{
		list->head = new_item;
	}

	else if(list->tail == NULL)
	{
		list->tail = new_item;
		list->head->next = list->tail;
	}

	else
	{
		list->tail->next = new_item;
		list->tail = list->tail->next;
	}

	list->length += 1;

    return true;
}

void remove_from_list(s_linked_list *list, void *data) {

	struct s_node* temp = list->head;
	struct s_node* prev = NULL;

	while(temp != NULL)
	{
		if (temp->data == data)
		{
			if(list->head == temp)
			{
				list->head = list->head->next;
			}

			if(prev != NULL) prev->next = temp->next;

			free(temp->data);
			free(temp);
			list->length -= 1;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
}

void remove_last(s_linked_list* list) {

	if (list->head->next == NULL)
	{
		printf("\n There is only head left, removing it");
		free(list->head->data);
		list->head = NULL;
		return;
	}

	struct s_node* prevTail = list->head;

	while (prevTail->next != list->tail)
	{
		prevTail = prevTail->next;
	}

	struct s_node* tempNext = prevTail->next;
	free(tempNext->data);
	free(tempNext);

	prevTail->next = NULL;
	list->tail = prevTail;
}

void print_list(s_linked_list *list)
{
	struct s_node* temp = list->head;
	if (temp == NULL)
	{
		printf("\n List is empty");
		return;
	}

	while(temp != NULL)
	{
		s_contact* tempContact = temp->data;
		temp = temp->next;
	}
}

int get_list_length(s_linked_list *list) {
	return list->length;
}

bool is_list_empty(s_linked_list *list)
{
    return list->length == 0;
}

void* list_last_element(s_linked_list* list)
{
    if (is_list_empty(list))
    {
        printf("List is empty \n");
        return NULL;
    }
    if (list->tail == NULL)
    {
        return list->head->data;
    }

    return list->tail->data;
}