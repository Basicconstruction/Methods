def LinRange(startNum, endNum, length, float_control = 2, format_control = True):
    arr_get = []
    ladder = (endNum - startNum) / (length - 1)
    while startNum <= endNum:
        if format_control:
            startNum = float(format(startNum, ".{}f".format(float_control)))
        arr_get.append(startNum)
        startNum += ladder
    return arr_get


def collect(startNum, endNum, ladder, float_control = 2, format_control = True):
    arr_get = []
    while startNum <= endNum:
        if format_control:
            startNum = float(format(startNum, ".{}f".format(float_control)))
        arr_get.append(startNum)
        startNum += ladder
    return arr_get


def printter(*args):
    try:
        if args[-1][0:4] == "pre_":
            r = args[-1][4:]
            for ele in args[:-1]:
                print(ele, end=r)
    except:
        print("",end="")
    finally:
        for ele in args:
            print(ele, end=" ")


def round(float_num=0.0, keeped_decimal=0):
    processed_float = float_num * (10 ** keeped_decimal)
    Integer_part = int(processed_float)
    if abstract(processed_float - Integer_part) >= 0.5:
        if float_num >= 0:
            Integer_part += 1
        else:
            Integer_part -= 1
    else:
        Integer_part += 0
    if keeped_decimal == 0:
        return int(Integer_part / int(10 ** keeped_decimal))
    else:
        return Integer_part / int(10 ** keeped_decimal)


def abstract(processed_number):
    if processed_number >= 0:
        return processed_number
    else:
        return -processed_number


def sqrt_r(a):
    if a == 0 or a == False:
        return 0
    x = a + 0.1
    y = (x + a / x) / 2
    for i in range(100):
        #基本上，大多数的开方将会在这里结束
        if x == y:
            return y
        else:
            x = y
            y = (x + a / x) / 2
    while abs(y - x) > 0.00000001:
        x = y
        y = (x + a / x) / 2
    return y

LinRange_DEBUG = False
if LinRange_DEBUG:
    a = LinRange(1,10,22)
    print(a, end = "\n")
collect_DEBUG = False
if collect_DEBUG:
    b = collect(1, 10, 0.45)
    print(b, end="\n")
printter_DEBUG = False
if printter_DEBUG:
    printter(2, 3, 4, "pre_ * ")
round_DEBUG = False
if round_DEBUG:
    print(round(10.929,2))
sqrt_r_DEBUG = True
if sqrt_r_DEBUG:
    print(sqrt_r(100))
    print(sqrt_r(3))