#include <stdio.h>

void showPermissions(int mode) {
    int owner = (mode / 100) % 10;
    int group = (mode / 10) % 10;
    int others = mode % 10;
    int perms[3] = {owner, group, others};
    char *labels[3] = {"Owner", "Group", "Others"};

    printf("\nPermission String: -");
    for (int i = 0; i < 3; i++) {
        printf("%c", (perms[i] & 4) ? 'r' : '-');
        printf("%c", (perms[i] & 2) ? 'w' : '-');
        printf("%c", (perms[i] & 1) ? 'x' : '-');
    }
    printf("\n\n");

    for (int i = 0; i < 3; i++) {
        printf("%-7s -> Read:%s  Write:%s  Execute:%s\n",
               labels[i],
               (perms[i] & 4) ? "Yes" : "No",
               (perms[i] & 2) ? "Yes" : "No",
               (perms[i] & 1) ? "Yes" : "No");
    }
}

int main() {
    char filename[50];
    int mode;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter permission code (e.g. 754): ");
    scanf("%d", &mode);

    printf("\nFile: %s\n", filename);
    showPermissions(mode);

    return 0;
}
