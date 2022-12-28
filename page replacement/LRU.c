#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Page
{
    int frame_index;
    int last_time_access;
    bool valid;
} PT[50];

bool isPagePresent(int page)
{
    if (PT[page].valid == true)
        return true;
    return false;
}

void updatePageTable(int page, int frame, int status, int last_access)
{
    PT[page].frame_index = frame;
    PT[page].valid = status;
    PT[page].last_time_access = last_access;
}

void printFrame(int frames[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", frames[i]);
    printf("\n");
}

int LRUPage(int frames[], int n)
{
    int min = 32000, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (PT[frames[i]].last_time_access < min)
        {
            min = PT[frames[i]].last_time_access;
            index = i;
        }
    }
    return index;
}

int main()
{

    int n, page_fault = 0, current = 0, size;

    printf("Enter the number of the page in queue : ");
    scanf("%d", &n);
    int req_queue[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &req_queue[i]);
    for (int i = 0; i < 50; i++)
        PT[i].valid = false;
    printf("Enter the size of the frame : ");
    scanf("%d", &size);
    int frames[size];
    for (int i = 0; i < n; i++)
    {
        if (!isPagePresent(req_queue[i]))
        {
            page_fault++;
            if (current < size)
            {
                frames[current] = req_queue[i];
                updatePageTable(req_queue[i], current, true, i);
                current++;
            }
            else
            {
                int index = LRUPage(frames, size);
                updatePageTable(frames[index], -1, false, i);
                frames[index] = req_queue[i];
                updatePageTable(req_queue[i], index, true, i);
            }
        }
        PT[req_queue[i]].last_time_access = i;
    }

    printf("Page Fault : %d\n", page_fault);
    printf("Page Fault ratio  : %f\n", (float)page_fault / n);
    printf("Page Fault : %f\n", (float)(n - page_fault) / n);

    return 0;
}