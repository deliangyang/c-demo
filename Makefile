
curl_demo:
	gcc -o bin/curl curlx/test.c -lcurl
	chmod +x bin/curl
	./bin/curl

cb:
	gcc -o bin/cb callback/main.c
	chmod +x ./bin/cb
	./bin/cb

statictest:
	gcc -o bin/statictest static/test.c
	chmod +x ./bin/statictest
	./bin/statictest

changemainentry:
	# gcc -o bin/changemainentry change_main_entry/test.c -nostartfiles -etest
	gcc -o bin/changemainentry change_main_entry/test.c # -nostartfiles -etest
	chmod +x ./bin/changemainentry
	./bin/changemainentry