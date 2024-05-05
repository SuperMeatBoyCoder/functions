import math


def extended_gcd(x, y, more=False) -> tuple[int, int, int, int, int]:
    """
    :param int x: integer greater than 0 (x > y)
    :param int y: integer greater than 0
    :param bool more: if set, prints the process

    return gcd(x, y), p, q, step_p and step_q such that (p + step_p * t) * x + (q + step_q * t) * y = gcd(x, y)
    for each t ∈ Z
    """
    if more:
        save_x, save_y = x, y
    xy_gcd = math.gcd(x, y)
    step_p = y // xy_gcd
    step_q = -x // xy_gcd
    x //= xy_gcd
    y //= xy_gcd

    if x == y:
        return xy_gcd, 1, 0, step_p, step_q

    elif y == 1:
        return xy_gcd, 1, -x + 1, step_p, step_q

    quotients = []
    quotient = 0
    while y > 0:
        if more:
            print(f'({x}, {y})', quotient)
        # this is the Euclidean algorithm, but we also save all the quotients
        temp = y
        quotient, y = divmod(x, y)
        x = temp
        quotients.append(quotient)

    quotients.pop()
    p = 1
    q = -quotients[-1]
    for j in range(2, len(quotients) + 1):
        # in this for loop we go through quotients list backwards, on every iteration we have ap + bq = 1,
        # where a and b are quotients from Euclidean algorithm such that a > b
        if more:
            print(f'{p}, {q} =', f'{p}, {q} * (1 - {quotients[-j]}) =', f'{q}, {p - q * quotients[-j]}')
        p -= q * quotients[-j]
        p, q = q, p
    if more:
        print(xy_gcd, '=', f'{p} * {save_x} + {q} * {save_y}\n')
    return xy_gcd, p, q, step_p, step_q


def more_extended_gcd(x, y, more=False) -> tuple[int, int, int, int, int]:
    """
    :param int x: integer greater than 0 (x > y)
    :param int y: integer greater than 0
    :param bool more: if set, prints the process

    return gcd(x, y), p, q, step_p and step_q such that (p + step_p * t) * x + (q + step_q * t) * y = gcd(x, y)
    for each t ∈ Z
    """

    x_mul = 1
    if x < 0:
        x_mul = -1
        x *= -1

    y_mul = 1
    if y < 0:
        y *= -1
        y_mul = -1

    is_flip = False
    if y > x:
        x, y = y, x
        x_mul, y_mul = y_mul, x_mul
        is_flip = True

    xy_gcd, p, q, step_p, step_q = extended_gcd(x, y, more)

    if is_flip:
        return xy_gcd, q * y_mul, p * x_mul, step_q * y_mul, step_p * x_mul
    return xy_gcd, p * x_mul, q * y_mul, step_p * x_mul, step_q * y_mul




def find_gate(p: int, q: int, step_p: int, step_q: int) -> tuple[int, int]:
    """
    return left and right limit of the following system: { \n
    p + step_p * t >= 0 \n
    q + step_q * t >= 0 \n
    t ∈ Z \n
    step_p != 0 \n
    step_q != 0 \n
    }

    if step_p * step_q < 0, aka one of the step_p and step_q are positive, and other is negative.
    """

    if step_p > 0:
        return math.ceil(-p / step_p), math.floor(-q / step_q)
    return math.ceil(-q / step_q), math.floor(-p / step_p)


def homework(questions):
    """Only algebra rn"""
    for question in questions:
        x, y, s = question
        xy_gcd, p, q, step_p, step_q = more_extended_gcd(x, y, True)
        if s % xy_gcd != 0:
            print('No answer\n\n')
            continue
        mul = s // xy_gcd
        p *= mul
        q *= mul

        print(f'a = {p} {"+-"[int(step_p < 0)]} {abs(step_p)}t')
        print(f'b = {q} {"+-"[int(step_q < 0)]} {abs(step_q)}t')
        print("t ∈ Z")
        print('\n')


if __name__ == "__main__":
    homework([[1003, 173, 2]])
