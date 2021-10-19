#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

struct page {
    int id;
    int counter;
};

struct page create_page() {
    struct page page;
    page.id = -1;
    page.counter = 0;
    return page;
}

struct page* create_page_list(int size) {
    struct page* pages = malloc(sizeof(struct page) * size);

    for (int i = 0;i < size; i++) {
        pages[i] = create_page();
    }

    return pages;
}

int main() {
    int n;

    printf("Please input number of page frames\n");

    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of page frames must be >= 0, but got %d\n", n);
        return 0;
    }

    struct page* pages = create_page_list(n);

    FILE *file = fopen("ex1.in", "r");

    int hit_counter = 0;
    int miss_counter = 0;

    int requested_page_id;
    while (fscanf(file, "%d ", &requested_page_id) == 1) {
        bool page_found = false; 

        for (int i = 0; i < n; i++) {
            if (pages[i].id == requested_page_id) {
                hit_counter++;
                page_found = true;
                break;
            }
        }
        

        if (page_found == false) {
            miss_counter++;

            for (int i = 0;i < n; i++) {
                if (pages[i].id == -1) {
                    pages[i].id = requested_page_id;
                    pages[i].counter = 0;
                    page_found = true;
                }
            }
        }

        if (page_found == false) {

            int most_aged_index = 0;
            for (int i = 1;i < n; i++) {
                if (pages[i].counter > pages[most_aged_index].counter) {
                    most_aged_index = i;
                }
            }
            pages[most_aged_index].id = requested_page_id;
            pages[most_aged_index].counter = 0;
        }
        

        // update counters (update age)
        for (int i = 0; i < n; i++) {
            pages[i].counter >>= 1;
            if (pages[i].id == requested_page_id) {
                pages[i].counter += (1 << (31)); // we can add as the most signifacnt bit of counter will be 2^(30) after prev shift
            }
        }
    }

    printf("Number of hits = %d\n", hit_counter);
   	printf("Number of misses = %d\n", miss_counter);
   	printf("hit/miss ratio = %f\n", ((float)hit_counter / (float) miss_counter));
   	
   	
   	fclose(file);
   	free(pages);
	
	return 0;

    
    
}