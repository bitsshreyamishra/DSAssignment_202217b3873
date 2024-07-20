#include <stdio.h>
#define MAX 20

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n = 0, i;

int main() { // Use 'int main()' instead of 'void main()'
    int ch;
    char g = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display \n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0; // Return 0 to indicate successful completion
            default:
                printf("\nEnter the correct choice.");
        }

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g); // Add a space before %c to consume the newline character left by previous input
    } while(g == 'y' || g == 'Y');

    return 0; // Return 0 to indicate successful completion
}

void create() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Number of nodes exceeds the maximum limit of %d\n", MAX);
        n = 0;
        return;
    }
    for(i = 0; i < n; i++) {
        printf("\nEnter the Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    int pos;
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);
    if(pos >= n || pos < 0) {
        printf("\nInvalid Location\n");
    } else {
        for(i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
        printf("\nThe elements after deletion: ");
        display();
    }
}

void search() {
    int e, found = 0;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);
    for(i = 0; i < n; i++) {
        if(b[i] == e) {
            printf("\nValue is at position %d", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nValue %d is not in the list", e);
    }
}

void insert() {
    int pos, p;
    printf("\nEnter the position where you need to insert: ");
    scanf("%d", &pos);
    if(pos > n || pos < 0 || n == MAX) {
        printf("\nInvalid Location\n");
    } else {
        for(i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
        printf("\nThe list after insertion: ");
        display();
    }
}

void display() {
    printf("\nThe elements of the list ADT are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
