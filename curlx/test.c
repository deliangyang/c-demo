#include <curl/curl.h>
#include <stdio.h>

size_t write_callback(char *buf, size_t size, size_t nmemb, void *user_data) {
  printf("-----%s\n", buf);
  return size * nmemb;
}

int main(int argc, char const *argv[]) {
  /* code */
  CURL *curl;
  CURLcode code;
  curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_HEADER, 1);
  curl_easy_setopt(curl, CURLOPT_URL, "https://www.baidu.com");
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_NOBODY, 0);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  // curl_easy_setopt(curl, CURLOPT_WRITEDATA, write_callback);
  code = curl_easy_perform(curl);
  if (code != CURLE_OK) {
    printf("get error: %s\n", curl_easy_strerror(code));
  }
  curl_easy_cleanup(curl);
  return 0;
}
