#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 typedef struct Patient {
     int age;
     char name[30];
     int id;
     struct Patient* next;
 } Patient;
 
 Patient *front = NULL, *rear = NULL;
 int counter = 0;
 
 void enqueue(char name[], int age) {
     Patient* new = (Patient*)malloc(sizeof(Patient));
     new->age = age;
     strcpy(new->name, name);
     new->id = ++counter;
     new->next = NULL;
 
     if (rear == NULL) {
         front = rear = new;
     } else {
         rear->next = new;
         rear = new;
     }
 
     printf("Added: %s (Age: %d, ID: %d)\n", name, age, new->id);
 }
 
 void dequeue() {
     if (front == NULL) {
         printf("Queue is empty!\n");
         return;
     }
 
     Patient* temp = front;
     printf("Removed: %s (ID: %d)\n", temp->name, temp->id);
     front = front->next;
     if (front == NULL) rear = NULL;
     free(temp);
 }
 
 void disp() {
     if (front == NULL) {
         printf("Queue is empty!\n");
         return;
     }
 
     Patient* temp = front;
     printf("\nPatient Queue:\n");
     while (temp != NULL) {
         printf("%s, Age: %d, ID: %d\n", temp->name, temp->age, temp->id);
         temp = temp->next;
     }
     printf("\n");
 }
 
 int main() {
     enqueue("Guna", 17);
     enqueue("Sai Charan Yadav", 18);
     enqueue("Revanth Nayak", 17);
 
     disp();
 
     dequeue();
     enqueue("Abdul Faheem", 18);
 
     disp();
 
     return 0;
 }
 
 /*
 
 Added: Guna (Age: 17, ID: 1)
 Added: Sai Charan Yadav (Age: 18, ID: 2)
 Added: Revanth Nayak (Age: 17, ID: 3)
 
 Patient Queue:
 Guna, Age: 17, ID: 1
 Sai Charan Yadav, Age: 18, ID: 2
 Revanth Nayak, Age: 17, ID: 3
 
 Removed: Guna (ID: 1)
 Added: Abdul Faheem (Age: 18, ID: 4)
 
 Patient Queue:
 Sai Charan Yadav, Age: 18, ID: 2
 Revanth Nayak, Age: 17, ID: 3
 Abdul Faheem, Age: 18, ID: 4
 
 */