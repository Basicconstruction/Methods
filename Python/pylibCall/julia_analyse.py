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


print(round(1.738324232, 5))