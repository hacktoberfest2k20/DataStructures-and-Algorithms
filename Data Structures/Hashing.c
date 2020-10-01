#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

//Define data item
struct DataItem
{
   int data;
   int key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

//Define a hashing method to compute the hash code of the key of the data item.
int hashCode(int key)
{
   return key % SIZE;
}

//Search Operation Function
struct DataItem *search(int key) 
{
   //get the hash
   int hashIndex = hashCode(key);
	
   //move in array until an empty
   while(hashArray[hashIndex] != NULL) 
   {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex];
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }

   return NULL;        
}

//Insert Operation Function
void insert(int key,int data) 
{
   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;     

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
   {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;        
}

//Delete Operation Function
struct DataItem* delete(struct DataItem* item) 
{
   int key = item->key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty 
   while(hashArray[hashIndex] !=NULL) 
   {
      if(hashArray[hashIndex]->key == key) 
      {
         struct DataItem* temp = hashArray[hashIndex]; 
			
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      } 
		
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }  
	
   return NULL;        
}

//Display Operation Function
void display()
{
   int i = 0;
	
   for(i = 0; i<SIZE; i++) 
   {
      if(hashArray[i] != NULL)
         printf(" (%d,%d)\n",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}


int main()
{
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;  
   dummyItem->key = -1; 
   int response, key, data;
   do
   {
        printf("\n****Menu**** \n 1.Search Operation\n 2.Insert Operation \n 3.Delete Operation \n 4.Display Operation \n 5.Quit \n Enter Response: ");
        scanf("%d", &response);
        switch (response)
        {
            case 1: printf("Enter key for which data to be Search: ");
                    scanf("%d", &key);
                    item = search(key);
                    if(item != NULL) 
                    {
                        printf("Data found: %d\n", item->data);
                    } 
                    else 
                    {
                        printf("Data not found\n");
                    }
                    break;

            case 2:	printf("Enter key to be insert: \n");
                    scanf("%d", &key);
                    printf("Enter data to be insert: \n");
                    scanf("%d", &data);
                    insert(key,data);
                    break;
            case 3:	printf("Enter key for which data to be Delete: \n");
                    scanf("%d", &key);
                    item=search(key);
                    if(item != NULL) 
                    {
                        printf("Data deleted: %d\n", item->data);
                        delete(item);
                    } 
                    else 
                    {
                        printf("Data not found\n");
                    }
                    break;
            case 4:	display();
                    break;
            //for error handling
            default: break;
        }
    }
    while(response!=5);
    return 0;
}
