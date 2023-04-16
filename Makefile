
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

calctest:
	gcc -o bin/calctest calc/main.c
	chmod +x ./bin/calctest
	./bin/calctest

pointtest:
	gcc -o bin/pointtest point/test.c
	chmod +x ./bin/pointtest
	./bin/pointtest

pointfunc:
	gcc -o bin/pointfunc point/func.c
	chmod +x ./bin/pointfunc
	objdump -d ./bin/pointfunc |grep --color '<test>'
	objdump -d ./bin/pointfunc |grep --color '<main>'
	gcc -S point/func.c  -o point/func.s
	./bin/pointfunc

shellx:
	gcc -o bin/shell shellcode/shell.c
	gcc -o bin/shellcode shellcode/test.c
	chmod +x ./bin/shellcode
	./bin/shellcode