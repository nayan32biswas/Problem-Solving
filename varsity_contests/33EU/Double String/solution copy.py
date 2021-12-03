def solve():
    # n = int(input())
    # data = input()
    n, data = [x for x in input().split(" ")]
    n = int(n)
    if data[:n//2] == data[n//2:]:
        return "Yes"
    return "No"

if __name__ == "__main__":
    test = int(input())
    for _ in range(test):
        print(solve())