for _ in[0]*int(input()):
    d = int(input())
    D = d*d/4-d
    if D < 0:
        print("N")
    else:
        D **= .5
        print("Y", d/2+D, d/2-D)
# wrong but very close
# def binary_search(n):
#     if n == 0:
#         print(f"Y {0:.6f} {0:.6f}")
#         return False
#     incre = 0.0000000000000000001
#     start = 0.999999999
#     End = 2.000000001
#     mid = (start+End)/2.0
#     n = float(format(n, '.18g'))
#     # print(incre, start, End, mid, n)
#     it = 0
#     while start < End and it < 1000:
#         mid = (start+End)/2.0

#         a = float(format(n-mid, '.18g'))
#         temp_n = float(format(a*mid, '.18g'))

#         if n == temp_n:
#             print(f"Y {a:.17f} {mid:.17f}")
#             return False
#         elif (n < temp_n):
#             End = mid-incre
#         else:
#             start = mid+incre
#         it += 1
#     return True


# for _ in[0]*int(input()):
#     n = int(input())
#     if binary_search(n):
#         print("N")
