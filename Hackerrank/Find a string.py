def count_substring(text, pattern):
    ans = 0
    # print(len(text), len(pattern))
    for i, t in enumerate(text):
        if t == pattern[0] and i+len(pattern)<=len(text):
            coun = 0
            for p in pattern:
                # print(i+coun)
                if text[i+coun] != p:
                    break
                coun += 1
            if coun == len(pattern):
                ans += 1
    return ans

text = input()
pattern = input()
print(count_substring(text, pattern))