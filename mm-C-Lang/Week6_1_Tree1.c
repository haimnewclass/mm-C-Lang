
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

typedef struct
{
	int age;
	char name[100];
	char address[100];

} DetailsT;

struct Leaf
{
	// Management or MetaData
	int level;
	struct Leaf* Left;
	struct Leaf* Right;
	struct Leaf* Parent;

	// Data (Real Data)
	DetailsT Details;
};
struct Leaf* Root;
struct Leaf* Head;

main()
{
	struct Leaf leaf;
	struct Leaf *leafPtr = (struct Leaf* ) malloc(sizeof(struct Leaf));

	leaf.Details.age = 23;
	leafPtr->Details.age = 23;

	strcpy(leaf.Details.address, "dafsdfsdf");
}