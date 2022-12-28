#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Page
{
    int frame_index;
    bool valid;
} PT[50];

bool isPagePresent(int page)
{
    if (PT[page].valid == true)
        return true;
    return false;
}

void updatePageTable(int page, int frame, int status)
{
    PT[page].frame_index = frame;
    PT[page].valid = status;
}

void printFrame(int frames[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", frames[i]);
    printf("\n");
}

int main()
{

    int n, page_fault = 0, current = 0, size;
    bool flag = true;
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
            if (flag && current < size)
            {
                frames[current] = req_queue[i];
                updatePageTable(req_queue[i], current, true);
                current++;
                if (current == size)
                {
                    current = 0;
                    flag = false;
                }
            }
            else
            {
                updatePageTable(frames[current], -1, false);
                frames[current] = req_queue[i];
                updatePageTable(req_queue[i], current, true);
                current = (current + 1) % size;
            }
        }
    }

    printf("Page Fault : %d\n", page_fault);
    printf("Page Fault ratio  : %f\n", (float)page_fault/n);
    printf("Page Fault : %f\n", (float)(n-page_fault)/n);

    return 0;
}