#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Linked list structure
struct list{
    char val; // char value
    struct list *next; // next pointer
};

struct list *head = NULL;
typedef struct list Node;

void InsertList(char *c){
    struct list *newNode=(struct list*)malloc(sizeof(struct list)); //Dynamically create new node 
    struct list *curr = head;	// curr Pointer to traverse through list
	struct list *trail = NULL;  // trail points to curr's previous node
    newNode->val = *c; 			//Assign value to node 
    
    if (head == NULL) { 		//Insert at head if this is 1st insertion
    	newNode->next = NULL;
    	head = newNode;
    }
    else if (newNode->val <= head->val) {	//Insert at head after 1st insertion
    	newNode->next = head;
    	head = newNode;
    }
    else {    								//Insert at the middle of the list
	while (curr->next != NULL) {			
		if(*c <= curr->val) {				//If letter c is less than curr's node value then new node will be inserted
			newNode->next = curr;	
			trail->next = newNode;           
			break;     
		}            
		else {							//If letter c is bigger than curr's node value then keep moving along the list until c is smaller 
			trail = curr;				//Updating trail
			curr = curr->next;			//Moving curr                 
		}            
        }
		if (curr->next == NULL) {			//If letter c is the biggest letter then it's added to the last of the list
			newNode->next = NULL;
			curr->next=newNode;
		}
    	}	
}

void PrintList()
{
    struct list *curr=head;
    if(head==NULL){		//Nothing in the list
        printf("The list is empty \n");
    }
    while (curr != NULL){
        printf("%c ",curr->val);
        curr = curr->next;	//Traverse curr and print
    }
    printf("\n");
}
void RemoveList(){
    // make head as null so other function cant operate
    printf("Linked list is now empty\n");
    head=NULL;
    free(head); // free the head
}

int main(){    
    while(1)	//Nonstop loop until user calls exit
    {
        char str[100]; 
        printf("> ");
        scanf("%s",str);
        
        if(strcmp(str,"insert") == 0)	//compare user's input with function's name
        {
            char c;
            printf("enter a char: ");
            getchar();
            scanf("%c",&c); 
            InsertList(&c);
        }       
        
        else if(strcmp(str,"print") == 0)
        {
            PrintList();
        }
        
        else if(strcmp(str,"remove") == 0)
        {
            RemoveList();
        }
        else if(strcmp(str,"exit") == 0)
        {
            if(head!=NULL){
                printf("Can't exit while there is a none null linked list. Call remove first. \n");
            }
            else{
                break;
            }
        }
        else{
            printf("Error: unknown request'%s'\n",str);
        }
    }
    return 0;
}
			
    			
    

	
			
