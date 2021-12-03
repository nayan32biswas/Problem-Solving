def solve(s):
    s = [x.capitalize() for x in s.split(" ")]
    return " ".join(s)

print(solve("hello asdlfk"))