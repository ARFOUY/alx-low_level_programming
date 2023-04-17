#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A dog's basic info
 * @name: First member
 * @age: Second member
 * @owner: Third member
 *
 * Description: Defines a dog's name, age, and owner as a struct.
 */
struct dog
{
	char *name; /* Name of the dog */
	float age; /* Age of the dog */
	char *owner; /* Owner of the dog */
};

/**
 * dog_t - Typedef for struct dog
 */
typedef struct dog dog_t;

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

/* Utility function prototypes */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif /* DOG_H */
