with open("input.txt", "r") as inp:
    lines = inp.readlines()

hex_string = lines[0].strip()


def get_package_value(package):
    package_size = 5
    bit_value = ""
    end_of_package = False
    for i in range(0, len(package), package_size):
        hi = i + package_size
        bit_group = package[i:hi]
        if bit_group[0] == "0":
            end_of_package = True
        bit_value += bit_group[1:]
        if end_of_package:
            break
    return int(bit_value, 2)


def extrack_package(package, length_id):
    package_size = 15 if length_id == "0" else 11
    packages = []
    for i in range(0, len(package), package_size):
        hi = i + package_size
        bit_group = package[i:hi]
        if bit_group[0] == "0":
            end_of_package = True
        packages.append(bit_group)
        if end_of_package:
            break


def first(hex_string):
    bin_string = bin(int(hex_string, 16))[2:].zfill(len(hex_string) * 4)
    strings = [bin_string]
    while True:
        temp_arr = []

        for bin_string in strings:
            if len(bin_string) < 6:
                break
            version = int(bin_string[:3], 2)
            package_id = int(bin_string[3:6], 2)
            if package_id == 4:
                version, value = get_package_value(bin_string[6:])
            else:
                temp = extrack_package(bin_string[7:], bin_string[6])
        strings = temp_arr
    return 0


print(first(hex_string))


"""
001 110 00000000000110111101000101001010010001001000000000
38006F45291200 to 111000000000000110111101000101001010010001001000000000
00111000000000000110111101000101001010010001001000000000

EE00D40C823060 to 11101110000000001101010000001100100000100011000001100000
11101110000000001101010000001100100000100011000001100000

16 = 8A004A801A8002F478 to 100010100000000001001010100000000001101010000000000000101111010001111000
100 010 = 4, 2
1 = 11
00000000001 = 1
001 010 = 1, 2
1 = 11
00000000001 = 1
101 010 = 5, 2
0 = 15
000000000001011 = 11
110 100 = 6, 4
01111

000

12 = 620080001611562C8802118E34 to 01100010000000001000000000000000000101100001000101010110001011001000100000000010000100011000111000110100
011 000 = 3, 2
1 = 11
00000000010 = 2
000 000 = 0, 0
0 = 15
000000000010110 = 22
000 100 = 0, 4
01010 = 10

remain = 10110001011


001 000 = 1, 0
1 = 11
00000000010 = 2
000 100 =0,4
01100 = 12
0111000110100

23 = C0015000016115A2E0802F182340 to 1100000000000001010100000000000000000001011000010001010110100010111000001000000000101111000110000010001101000000

31 = A0016C880162017C3686B18A3D4780 to 101000000000000101101100100010000000000101100010000000010111110000110110100001101011000110001010001111010100011110000000

"""
