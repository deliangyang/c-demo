

code = '48bbff2f62696e2f736848c1eb08534889e74831d24831c04831f6b03b0f05'
result = ""
for i in range(0, len(code), 2):
    if i < len(code) - 1:
        result += '\\x' + code[i:i+2]
    else:
        result += '\\x' + code[i]
# with open('a.txt', 'wb') as fw:
#     fw.write(bytes.fromhex(code))
print(result)