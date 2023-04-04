#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    FILE *f;
    f = fopen("main.c", "r");
    char buffer[20];
    fread(buffer, 10, 1, f);
    printf("%s\n", buffer);
    fclose(f);

    FILE *fp;
    fp = fopen("log.txt", "w");
    fwrite(buffer, strlen(buffer), 1, fp);
    fclose(fp);

    unlink("log.txt");

    return 0;
}
