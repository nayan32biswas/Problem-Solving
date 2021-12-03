def minion_game(string):
    Kevin = 0
    Stuart = 0
    vowels = {'A': 1, 'E': 1, 'I': 1, 'O': 1, 'U': 1}
    n = len(string)
    for x in string:
        if x in vowels:
            Kevin += n
        else:
            Stuart += n
        n -= 1

    if Stuart>Kevin:
        print("Stuart", Stuart)
    elif Kevin>Stuart:
        print("Kevin", Kevin)
    else:
        print("Draw")

minion_game(input())