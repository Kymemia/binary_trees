#include "binary_trees.h"

/**
 *
 */

Queue *createQueue() {
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	if (queue == NULL)
		exit(EXIT_FAILURE);
	queue->front = queue->rear = NULL;
	return (queue);
}

int isEmpty(Queue *queue)
{
	return (queue->front == NULL);
}

void enqueue(Queue *queue, binary_tree_t *node)
{
	QueueNode *newNode = createQueueNode(node);
	if (isEmpty(queue))
	{
		queue->front = queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

binary_tree_t *dequeue(Queue *queue)
{
	if (isEmpty(queue))
		exit(EXIT_FAILURE);
	QueueNode *temp = queue->front;
	binary_tree_t *node = temp->node;
	queue->front = queue->front->next;
	free(temp);
	return (node);
}

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (func == NULL)
		return;

	Queue *queue = CreateQueue();

	enqeue(queue, (binary_tree_t *)tree);

	while (!isEmpty(queue))
	{
		binary_tree_t current = dequeue(queue);
		func(current->n);

		if (current->left != NULL)
			enqueue(queue, current->left);

		if (current->right != NULL)
			enqueue(queue, current->right);
	}
	free(queue);
}
