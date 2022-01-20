from random import randint

nums = ''.join(list(map(lambda n: str(n), [randint(1,10) for x in range(9)])))
comp1 = [x for x in range(10,1,-1)]
comp2 = [x for x in range(11,1,-1)]

def calc(cpf):
    sum = 0

    try:
        for n in range(len(cpf)):
            if len(cpf) < 10:
                sum += int(cpf[n]) * comp1[n]
            else:
                sum += int(cpf[n]) * comp2[n]
    except:
        global nums
        nums = ''.join(list(map(lambda n: str(n), [randint(1,10) for x in range(9)])))
        calc(nums)

    sum = sum * 10 % 11

    return str(sum) if sum < 10 else '0'

final_digits = calc(nums)
final_digits += calc(nums+final_digits)
print(nums + final_digits)
