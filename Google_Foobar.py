#region 1. I Love Lance & Janice

def get_decrypted_char(char):
    if char.isalpha() and char.islower():
        return chr(122 - (ord(char) - 97))
    else:
        return char
def solution(s):
    return ''.join([get_decrypted_char(char) for char in s])

#endregion

#region 2. Lovely Lucky LAMBs

# adaw

#endregion

# 1. I Love Lance & Janice
# print(solution('Yvzs! I xzm\'g yvorvev Lzmxv olhg srh qly zg gsv xlolmb!!'))

# 2. Lovely Lucky LAMBs
print(solution([4, 17, 50]))