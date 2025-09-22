#include <stdio.h>
#include <stdlib.h>

// Define a real-world structure for a book
struct book {
    char bookTitle[50];   // Book title (up to 49 chars + null terminator)
    int bookNumber;       // Inventory number or ID
    int bookPages;        // Number of pages in the book
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number_of_books>\n", argv[0]);
        return 1;
    }

    int num_books = atoi(argv[1]);
    struct book* library = (struct book*)malloc(num_books * sizeof(struct book));

    if (library == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nPlease enter information for %d books.\n", num_books);
    printf("Format: <title> <bookNumber> <bookPages>\n");
    printf("(Example: \"JoesLife 1234 23\")\n\n");

    for (int i = 0; i < num_books; i++) {
        printf("Enter details for book %d: ", i + 1);
        scanf("%49s %d %d", library[i].bookTitle, &library[i].bookNumber, &library[i].bookPages);

        printf("You entered: Title=\"%s\", Number=%d, Pages=%d (stored at index %d)\n\n",
               library[i].bookTitle, library[i].bookNumber, library[i].bookPages, i);
    }

    // Print all books
    printf("\nHere is the data for all books in the library:\n");
    for (int i = 0; i < num_books; i++) {
        printf("Book %d -> Title: %s | Number: %d | Pages: %d\n",
               i, library[i].bookTitle, library[i].bookNumber, library[i].bookPages);
    }

    free(library);
    return 0;
}


/*

WHAT TO DO

MODIFY THIS CODE

Instead of a stupid example structure (really this is the best you could think of Joe - "myStruct", "myInt", come on man)

Update this code to do something more...real world.

For examle:

Maybe create a structure like this:

struct book {

    char bookTitle[10];
    int bookNumber;
    int bookPages;

};

Example data might be (remember we're just making stuff up here)  Here title is some made-up title.  A made up inventory number.  A made up number of pages (not a very big book...).

bookTitle - Joe's Life
bookNumber - 1234
bookPages - 23


*/