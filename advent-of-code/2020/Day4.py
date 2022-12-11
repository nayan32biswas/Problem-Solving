file = open("input.txt", "r")

lines = file.readlines()


def extract_persion():
    parsons = []
    parson = ""
    for line in lines:
        if line == "\n":
            if len(lines) > 0:
                parsons.append(parson[1:])
            parson = ""
            continue
        else:
            parson += " " + line[:-1]
    if len(lines) > 0:
        parsons.append(parson[1:])
    return parsons


def valid_byr(data):
    return len(data) == 4 and 1920 <= int(data) <= 2002


def valid_iyr(data):
    return len(data) == 4 and 2010 <= int(data) <= 2020


def valid_eyr(data):
    return len(data) == 4 and 2020 <= int(data) <= 2030


def valid_hgt(data):
    height, tag = data[:-2], data[-2:]
    if "cm" == tag:
        return len(height) == 3 and 150 <= int(height) <= 193
    if "in" == tag:
        return len(height) == 2 and 59 <= int(height) <= 76
    return False


def valid_hcl(data):
    if data[0] != "#":
        return False
    try:
        int(data[1:], 16)
        return True
    except Exception:
        pass
    return False


def valid_ecl(data):
    return data in ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"]


def valid_pid(data):
    return len(data) == 9 and data.isdigit()


def valid_cid(data):
    return True


func_def = {
    "byr": valid_byr,
    "iyr": valid_iyr,
    "eyr": valid_eyr,
    "hgt": valid_hgt,
    "hcl": valid_hcl,
    "ecl": valid_ecl,
    "pid": valid_pid,
    "cid": valid_cid,
}
valid = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"]


def is_curroct(passport):

    for each in valid:
        if each not in passport:
            return 0
    for each in passport.split(" "):
        code, data = each.split(":")
        if not func_def[code](data):
            return 0
    return 1


parsons = extract_persion()
print(sum([is_curroct(parson) for parson in parsons]))
