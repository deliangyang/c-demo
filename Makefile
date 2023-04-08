
curl_demo:
	gcc -o bin/curl curlx/test.c -lcurl
	chmod +x bin/curl
	./bin/curl

cb:
	gcc -o bin/cb callback/main.c
	chmod +x ./bin/cb
	./bin/cb