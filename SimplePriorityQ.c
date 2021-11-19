//@Author: Dr.Mydhili K Nair, Professor, ISE Dept, RIT.
/* Inserting and Deleting elements into Linear Priority Queue of 5 indexes using Arrays.
NOTE: In this program highest priority implies smallest value in the Linear Queue
NOTE: This program is NOT Menu Driven. The program logic is very simple
 Step 1: Declare a Linear Queue of 5 elements
 Step 2: In Main call the "enQueue" function iteratively to keep Enqueing all 5 indexes until Queue is full
 Step 3: In the "enQueue" function check if the element entered newly is larger than previous element
 Step 4: If so, sort the Linear Queue in DESCENDING order, so that the smallest value is at the last index, here index 5
        if not, just insert the new element at the current index, which is the last index. This essentially means that
        the current value entered is the smallest element in the Queue so far.
 NOTE: "rear" always points to the last index. Meaning "rear" always has the element with the highest priority, that is
 smallest value.
 Step 5: After enQueuing call the "diaplay" function, to print the Q elements until "rear" position
 Step 6: After this call "peek" function to display the element with the highest priority, essentially where "rear"
 points to.
 Step 7: After this call the "qSize" function to display the number of elements of the Q. It will be 5.
 Step 8: Now call "deQueue". This is a very simple function that always return the "rear" value. After this it
 decrements the "rear" to point to the next smallest element of the Queue.
 Step 9: Call the "qSize" function to display the number of elements of the Q.
 It will be 4, as top priority element is deQueued.
 
 
Possible VIVA Questions are displayed in comments with their answers.
*/
#include <stdio.h>
#include <string.h>

#define SIZE 5

int priQ[SIZE];
int rear = -1;

void display()
{
    /* Viva Q: How is the condition "i<=rear;" in for loop below valid,when rear is initialized to -1?
     Answer: The order of execution is call the "isEmpty" function to check if there are elements in the Q
     if not, it will display Q is empty
     Only if there are elements, which means "enQueue" function was called SIZE times and Q is full to be displayed.
    */
    if(!isEmpty())
    {
    printf(" \nElements of the Priority Queue are :");
      for(int i =0; i<=rear; i++)
      printf(" %d ", priQ[i]);
    }//end if
    else
    printf("\n Priority Values in Q is empty!");
}
/* Viva Q: How is "rear" the index for peek function?
 Answer: In this program the logic is highest priority implies smallest element in the Q. This is the value of index
 pointed by "rear". The pre-requisite logic is that the "enQueue" function always sorts the array in descending order.
 */
int peek(){
    return priQ[rear];
}

/*Viva Q: Explain the "return" statement below
 Answer: This reads as "if 'rear' equals '-1' return true, that is 1. If not return false, that is 0.
 It uses the 'ternary operator' '?' for the same.
 */
int isEmpty(){
    return (rear == -1)?1:0;
}

/* Viva Q: Why should "rear" be SIZE-1. It should be SIZE, here SIZE = 5. Q has 5 elements, not 4.
 Answer: "rear" is intialized to "-1". Enqueuing starts at index 0 and continues to index 4, which is 5 elements.
 When Q is full "rear" value is 4, not 5.
 */
int isFull(){
    return (rear == SIZE-1)?1:0;
}

/*Viva Q: Why rear+1 for Q-Size?
 Answer: See above explanation for "isFull" function
 */
int qSize(){
    return rear+1;
}

/* Viva Q: enQueue function looks so complicated? Why?
 See explanation in Step 3 & 4 above.
 */
void enQueue(int element){
    int i = 0;
    
    if(!isFull())
    {
        // if queue is empty, insert the data
        if(rear == -1){
            priQ[++rear] = element;
        }//end inner if
        else
        {
            // start from the right end of the queue
            // sort in descending order
            for(i = rear; i >= 0; i-- ){
                // if data is larger, shift existing item to right end
                if(element > priQ[i]){
                    priQ[i+1] = priQ[i];
                }
                else
                {
                    break; //Dont do anything. Just quit the loop
                    /* Meaning the current value is the smallest element in the Queue so far.*/
                }
            }//end for
            
            /* insert the new element at the current index, which is the last index. This essentially means that
            the current value entered is the smallest element in the Queue so far. */
            
            priQ[i+1] = element;
            rear++;
        }//end inner else
        
    }//end outer if
    else
    printf("\nQueue is full...cannot insert \n");
}

/* Viva Q: Dequeue function is just one line? How is this possible? In all other Q programs dequeue is involves
 lot of processing the array indices.
 Answer: The logic of this program always sorts the array in descending order, with the smallest element (highest
 priority) at the "rear", last index of the Queue. Therefore "deQueue" is a simple return of that rear value and
 decrementing rear, to point to the next smallest element.
 */
int deQueue(){
    return priQ[rear--];
}


int main()
{
    int priority;
    for(int i = 0; i<SIZE; i++)
    {
        printf("\nEnter the priority value to be put in the Q in any random order");
        scanf("%d", &priority);
        enQueue(priority);
    }
    printf("\nSorted priority values in the queue are:");
    
    display();
    
    printf("\nElement at front: %d\n",peek());
    
    if(isFull()){
        printf("\nPriority Values in Queue is full!");
    }
    printf("\nNumber of Q elements is %d", qSize());
    // remove one item
    int num = deQueue();
    printf("\nElement with highest priority is removed, which is %d in front of the Queue ",num);
    
    display();
    printf("\nNumber of Q elements is %d", qSize());
    printf("\nElement at front: %d\n",peek());
    
    printf("\nEnter the priority value to be put in the freed position in the Queue ");
    scanf("%d", &priority);
    enQueue(priority);
    
    printf("\nSorted priority values in the queue are:");
    display();
    
    printf("\nElement at front: %d\n",peek());
    
    printf("\nEnter the priority value to be put in the FULL Queue...try...");
    scanf("%d", &priority);
    enQueue(priority);
    
    display();
    printf("\n");
}



