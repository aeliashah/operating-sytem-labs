#include <stdio.h>
#include <stdlib.h> // for exit()

int main() {
    int b[20], l[20], n, i, pa, s, a, d;

    printf("Program for Segmentation\n");

    printf("Enter the number of segments: ");
    scanf("%d", &n);

    printf("Enter the base address and limit register for each segment:\n");
    for (i = 0; i < n; i++) {
        printf("Segment %d - Base: ", i);
        scanf("%d", &b[i]);
        printf("Segment %d - Limit: ", i);
        scanf("%d", &l[i]);
    }

    printf("\nEnter the segment number: ");
    scanf("%d", &s);

    if (s >= n) {
        printf("Invalid segment number\n");
        exit(0);
    }

    printf("Enter the logical address (offset): ");
    scanf("%d", &d);

    if (d < l[s]) {
        pa = b[s] + d;
        a = b[s];
        printf("\n\tSegNo.\tBaseAddr\tPhysicalAddr\n");
        printf("\t%d\t%d\t\t%d\n", s, a, pa);
    } else {
        printf("\nOffset exceeds the limit of the segment\n");
    }

    return 0;
}

