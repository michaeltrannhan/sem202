
#include "mem.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void *mem_pool = NULL;

pthread_mutex_t lock;

struct mem_region
{
	size_t size;			 // Size of memory region
	char *pointer;			 // Pointer to the first byte
	struct mem_region *next; // Pointer to the next region in the list
	struct mem_region *prev; // Pointer to the previous region in the list
};

struct mem_region *free_regions = NULL;
struct mem_region *used_regions = NULL;

static void *best_fit_allocator(unsigned int size);
static void *first_fit_allocator(unsigned int size);
static void *worst_fit_allocator(unsigned int size);
int mem_init(unsigned int size)
{
	/* Initial lock for multi-thread allocators */
	pthread_mutex_init(&lock, NULL);

	/* Prealocate the mem pool based on used request */
	mem_pool = malloc(size);

	/* Initial free list with only 1 region */
	free_regions = (struct mem_region *)malloc(sizeof(struct mem_region));
	free_regions->size = size;
	free_regions->pointer = (char *)mem_pool;
	free_regions->next = NULL;
	free_regions->prev = NULL;

	return (mem_pool != 0);
}

void mem_finish()
{
	/* Delete lock */
	pthread_mutex_destroy(&lock);

	/* Clean lists */
	struct mem_region *tmp;
	if (free_regions != NULL)
	{
		tmp = free_regions->next;
		while (tmp != NULL)
		{
			free(free_regions);
			free_regions = tmp;
			tmp = tmp->next;
		}
		free(free_regions);
	}
	if (used_regions != NULL)
	{
		tmp = used_regions->next;
		while (tmp != NULL)
		{
			free(used_regions);
			used_regions = tmp;
			tmp = tmp->next;
		}
		free(used_regions);
	}

	/* Clean preallocated region */
	free(mem_pool);
}

void *mem_alloc(unsigned int size)
{
	pthread_mutex_lock(&lock);
	// Follow is FIST FIT allocator used for demonstration only.
	// You need to implment your own BEST FIT allocator.
	// TODO: Comment the next line
	//void *pointer = first_fit_allocator(size);
	// Commnent out the previous line and uncomment to next line
	// to invoke best fit allocator
	// TODO: uncomment the next line
	void * pointer = best_fit_allocator(size);
	// TODO: uncomment if use other algorithm
	//void * pointer = worst_fit_allocator(size);

	// FOR VERIFICATION ONLY. DO NOT REMOVE THESE LINES
	if (pointer != NULL)
	{
		printf("Alloc [%4hu bytes] %p-%p\n", size, pointer, (char *)pointer + size - 1);
		//printf("--- Used %d bytes ---\n", size);
	}
	else
	{
		printf("Alloc [%4hu bytes] NULL", size);
	}

	pthread_mutex_unlock(&lock);
	return pointer;
}
void free_stat(){
	printf("Free : %ld \n", free_regions->size);
}
void used_stat(){
	printf("Used : %ld \n", used_regions->size);
}
void print_all(){
	free_stat();
	used_stat();
}
void mem_free(void *pointer)
{
	pthread_mutex_lock(&lock);
	struct mem_region *current_region = used_regions;
	// Get allocated region from the list of used_regions
	while (current_region != NULL && current_region->pointer != pointer)
	{
		current_region = current_region->next;
	}
	if (current_region != NULL)
	{
		// Remove current region from the list of used regions
		if (current_region == used_regions)
		{
			used_regions = used_regions->next;
			if (used_regions != NULL)
			{
				used_regions->prev = NULL;
			}
		}
		else
		{
			if (current_region->prev != NULL)
			{
				current_region->prev->next = current_region->next;
			}
			if (current_region->next != NULL)
			{
				current_region->next->prev = current_region->prev;
			}
		}

		// FOR VERIFICATION ONLY. DO NOT REMOVE THESE LINES
		printf("Free  [%4lu bytes] %p-%p\n", current_region->size, current_region->pointer,
			   current_region->pointer + current_region->size - 1);

		// Free this region by putting it into free list
		if (free_regions == NULL)
		{
			// No free region
			free_regions = current_region;
		}
		else
		{
			// Find a location of the list for it
			if (current_region->pointer < free_regions->pointer)
			{
				// new region will be put on the first location
				if (current_region->pointer + current_region->size == free_regions->pointer)
				{
					// The new regions and the first region in the list are contiguous
					free_regions->pointer = current_region->pointer;
					free_regions->size += current_region->size;
					free(current_region);
				}
				else
				{
					// These regions are not contiguous
					free_regions->prev = current_region;
					current_region->prev = NULL;
					current_region->next = free_regions;
					free_regions = current_region;
				}
			}
			else
			{
				// new region will be put on somewhere in the middle or at the end of the list
				struct mem_region *tmp = free_regions;
				while (tmp->pointer < current_region->pointer && tmp->next != NULL)
				{
					tmp = tmp->next;
				}
				if (tmp->next == NULL)
				{
					// new region will be put at the end of the list
					if (tmp->pointer + tmp->size == current_region->pointer)
					{
						// Merge two contiguous regions
						tmp->size += current_region->size;
						free(current_region);
					}
					else
					{
						tmp->next = current_region;
						current_region->prev = tmp;
						current_region->next = NULL;
					}
				}
				else
				{
					// new region is in the middle of the list
					if (tmp->prev->pointer + tmp->prev->size == current_region->pointer)
					{
						// current_region and its previous one are contiguous
						tmp->prev->size += current_region->size;
						free(current_region);
						current_region = tmp->prev;
					}
					else
					{
						current_region->prev = tmp->prev;
						current_region->next = tmp;
						tmp->prev->next = current_region;
						tmp->prev = current_region;
					}
					if (current_region->pointer + current_region->size == tmp->pointer)
					{
						// current region and its next one are contiguous
						tmp->pointer = current_region->pointer;
						tmp->size += current_region->size;
						tmp->prev = current_region->prev;
						if (current_region->prev != NULL)
						{
							current_region->prev->next = tmp;
						}
						free(current_region);
					}
				}
			}
		}
	}
	pthread_mutex_unlock(&lock);
}

void *best_fit_allocator(unsigned int size)
{
	// TODO: Implement your best fit allocator here

	int found = 0;
	struct mem_region *current_region = free_regions;
	unsigned int min = __INT16_MAX__;
	struct mem_region *temp_ite = free_regions;
	while (temp_ite != NULL && temp_ite->size - size > 0)
	{
		if(min > temp_ite->size - size){
			min = temp_ite->size - size;
			break;
		}
		else
			temp_ite = temp_ite->next;
	}
	do 
	{
		if(min == current_region->size - size)
			found = 1;
		else 
			current_region = current_region->next;
	}while(!found && current_region != NULL && current_region->size > size);

	if (found)
	{
		struct mem_region *tmp =
			(struct mem_region *)malloc(sizeof(struct mem_region));
		tmp->pointer = current_region->pointer;
		tmp->size = size;
		tmp->next = used_regions;
		tmp->prev = NULL;
		if (used_regions == NULL)
		{
			used_regions = tmp;
		}
		else
		{
			used_regions->prev = tmp;
			used_regions = tmp;
		}
		if (current_region->size == size)
		{
			if (current_region == free_regions)
			{
				free_regions = free_regions->next;
				if (free_regions != NULL)
				{
					free_regions->prev = NULL;
				}
			}
			else
			{
				if (current_region->prev != NULL)
				{
					current_region->prev->next = current_region->next;
				}
				if (current_region->next != NULL)
				{
					current_region->next->prev = current_region->prev;
				}
			}
			free(current_region);
		}
		else
		{
			current_region->pointer += size;
			current_region->size -= size;
		}
		print_all();
		return tmp->pointer;
	}
	else
	{
		return NULL;
	}
	//return NULL; // remember to remove this line
}

void *worst_fit_allocator(unsigned int size)
{
	// TODO: Implement your worst fit allocator here
	int found = 0;
	struct mem_region *current_region = free_regions;
	unsigned int max = 0;
	struct mem_region *temp_ite = free_regions;
	while (temp_ite != NULL && temp_ite->size - size > 0)
	{
		if(max < temp_ite->size - size){
			max = temp_ite->size - size;
			break;
		}
		else
			temp_ite = temp_ite->next;
	}
	do 
	{
		if(max == current_region->size - size)
			found = 1;
		else 
			current_region = current_region->next;
	}while(!found && current_region != NULL && current_region->size > size);

	if (found)
	{
		struct mem_region *tmp =
			(struct mem_region *)malloc(sizeof(struct mem_region));
		tmp->pointer = current_region->pointer;
		tmp->size = size;
		tmp->next = used_regions;
		tmp->prev = NULL;
		if (used_regions == NULL)
		{
			used_regions = tmp;
		}
		else
		{
			used_regions->prev = tmp;
			used_regions = tmp;
		}
		if (current_region->size == size)
		{
			if (current_region == free_regions)
			{
				free_regions = free_regions->next;
				if (free_regions != NULL)
				{
					free_regions->prev = NULL;
				}
			}
			else
			{
				if (current_region->prev != NULL)
				{
					current_region->prev->next = current_region->next;
				}
				if (current_region->next != NULL)
				{
					current_region->next->prev = current_region->prev;
				}
			}
			free(current_region);
		}
		else
		{
			current_region->pointer += size;
			current_region->size -= size;
		}
		print_all();
		return tmp->pointer;
	}
	else
	{
		return NULL;
	}
	//return NULL; // remember to remove this line
}

void *first_fit_allocator(unsigned int size)
{
	/* First fit example */
	int found = 0;
	struct mem_region *current_region = free_regions;
	do
	{
		if (size <= current_region->size)
		{
			found = 1;
		}
		else
		{
			current_region = current_region->next;
		}
	} while (!found && current_region != NULL);

	if (found)
	{
		struct mem_region *tmp =
			(struct mem_region *)malloc(sizeof(struct mem_region));
		tmp->pointer = current_region->pointer;
		tmp->size = size;
		tmp->next = used_regions;
		tmp->prev = NULL;
		if (used_regions == NULL)
		{
			used_regions = tmp;
		}
		else
		{
			used_regions->prev = tmp;
			used_regions = tmp;
		}
		if (current_region->size == size)
		{
			if (current_region == free_regions)
			{
				free_regions = free_regions->next;
				if (free_regions != NULL)
				{
					free_regions->prev = NULL;
				}
			}
			else
			{
				if (current_region->prev != NULL)
				{
					current_region->prev->next = current_region->next;
				}
				if (current_region->next != NULL)
				{
					current_region->next->prev = current_region->prev;
				}
			}
			free(current_region);
		}
		else
		{
			current_region->pointer += size;
			current_region->size -= size;
		}
		print_all();
		return tmp->pointer;
	}
	else
	{
		return NULL;
	}
}
