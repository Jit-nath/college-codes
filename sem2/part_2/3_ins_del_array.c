#include <stdio.h>
void array_insert_element(int *array , int length){
    int element , position ;

    printf("\nInserting element-> ");
    scanf("%d",&element);
    printf("\nPosition -> ");
    scanf("%d",&position);

    if (position < 0 || position > length) {
        printf("Invalid position\n");
    } else {
        for (int i = length - 1; i >= position; i--) {
            array[i + 1] = array[i];
        }
        array[position] = element;
        length++;

        for (int i = 0; i < length; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}
void array_delete_element(int *array , int length){
    
    int delete_position;
    printf("\nDelete Position -> ");
    scanf("%d",&delete_position);

    printf("\nDeleting element at position %d:\n", delete_position);
    if (delete_position < 0 || delete_position >= length) {
        printf("Invalid position\n");
    } else {
        for (int i = delete_position; i < length - 1; i++) {
            array[i] = array[i + 1];
        }
        length--;

        for (int i = 0; i <= length; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}
int main() {
    int arr[100];
    int length;
    int *p = arr;
    // Inserting elements into the array
    printf("Enter the number of elements-> ");
    scanf("%d",&length);
    printf("\nEnter the elements \n");
    for(int i =0 ; i<length; i++)
    {
        printf("%d-> ",i);
        scanf("%d",&arr[i]);
    }
    printf("\n");
    array_insert_element(p,length);
    array_delete_element(p,length);
    return 0;
}
