
#include <stdio.h>
#include <stdbool.h>

void simulate_lru(int page_requests[], int num_requests, int num_frames) {
    int frames[num_frames];
    int last_used[num_frames]; // Timestamp array
    int page_faults = 0;

    // Initialize empty slots
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    for (int time = 0; time < num_requests; time++) {
        int page = page_requests[time];
        bool hit = false;

        // TODO 1: Check if 'page' is already in 'frames' (HIT)

        for(int i=0; i < num_frames; i++) {
            if(frames[i] == page){
                hit = true;
                last_used[i] = time;
                break;
            }
        }

        if(hit){
            printf("%d -> HIT [", page);
            for(int i=0; i < num_frames; i++){
                if(frames[i] == -1){
                    printf("- ");
                }		
                else{
                    printf("%d ", frames[i]);
                }
            }
            printf("]\n");
            continue;
        }

        // TODO 2: Handle PAGE FAULT if not found

        page_faults++;

        int replace_index = -1;

        // empty index
        for(int i=0; i<num_frames; i++) {
            if(frames[i] == -1){
                replace_index = i;
                break;
            }
        }

        // no empty index found
        if(replace_index == -1){
            int minimum = last_used[0];
            replace_index = 0;

            for(int i=1; i<num_frames; i++){
                if(last_used[i] < minimum) {
                    minimum = last_used[i];
                    replace_index = i;
                }
            }
        }

        // Replace page
        frames[replace_index] = page;
        last_used[replace_index] = time;

        printf("%d -> FAULT [", page);
        for (int i = 0; i < num_frames; i++) {
            if (frames[i] == -1)
                printf("- ");
            else
                printf("%d ", frames[i]);
        }
        printf("]\n");
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    int requests[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int num_requests = sizeof(requests) / sizeof(requests[0]);
    
    simulate_lru(requests, num_requests, 3);
    return 0;
}