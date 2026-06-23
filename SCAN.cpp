#include <stdio.h>
#include <stdlib.h>

void scan(int requests[], int n, int head, int disk_size, int direction) {
    int seek_count = 0;
    int distance, cur_track;
    int left[100], right[100];
    int l = 0, r = 0;

    // direction: 1 = towards higher tracks, 0 = towards lower tracks
    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[l++] = requests[i];
        else
            right[r++] = requests[i];
    }

    // Sort both sub-arrays
    for (int i = 0; i < l - 1; i++)
        for (int j = i + 1; j < l; j++)
            if (left[i] > left[j]) { int t = left[i]; left[i] = left[j]; left[j] = t; }

    for (int i = 0; i < r - 1; i++)
        for (int j = i + 1; j < r; j++)
            if (right[i] > right[j]) { int t = right[i]; right[i] = right[j]; right[j] = t; }

    cur_track = head;

    if (direction == 1) {
        // Move right first, then go to disk end, reverse, then left
        printf("Seek Sequence: %d", cur_track);
        for (int i = 0; i < r; i++) {
            seek_count += abs(right[i] - cur_track);
            cur_track = right[i];
            printf(" -> %d", cur_track);
        }
        seek_count += abs((disk_size - 1) - cur_track);
        cur_track = disk_size - 1;
        printf(" -> %d", cur_track);

        for (int i = l - 1; i >= 0; i--) {
            seek_count += abs(cur_track - left[i]);
            cur_track = left[i];
            printf(" -> %d", cur_track);
        }
    } else {
        // Move left first, then go to disk start, reverse, then right
        printf("Seek Sequence: %d", cur_track);
        for (int i = l - 1; i >= 0; i--) {
            seek_count += abs(cur_track - left[i]);
            cur_track = left[i];
            printf(" -> %d", cur_track);
        }
        seek_count += cur_track;
        cur_track = 0;
        printf(" -> %d", cur_track);

        for (int i = 0; i < r; i++) {
            seek_count += abs(right[i] - cur_track);
            cur_track = right[i];
            printf(" -> %d", cur_track);
        }
    }

    printf("\nTotal Seek Count (SCAN) = %d\n", seek_count);
}

int main() {
    int n, head, disk_size, direction;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size (max track number + 1): ");
    scanf("%d", &disk_size);

    printf("Enter direction (1 for towards higher tracks, 0 for towards lower tracks): ");
    scanf("%d", &direction);

    scan(requests, n, head, disk_size, direction);

    return 0;
}
