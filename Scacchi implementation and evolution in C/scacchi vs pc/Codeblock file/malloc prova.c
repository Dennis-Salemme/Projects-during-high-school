#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Inserisci il numero di stringhe: ");
    scanf("%d", &n);
    char **strings = (char**)malloc(n * sizeof(char*));
    if (strings == NULL) {
        printf("Memoria insufficiente");
        return 1;
    }
    int i;
    for (i = 0; i < n; i++) {
        strings[i] = (char*)malloc(20 * sizeof(char));
        sprintf(strings[i], "Stringa numero %d", i);
    }
    for (i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }
    for (i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);
    return 0;
}
