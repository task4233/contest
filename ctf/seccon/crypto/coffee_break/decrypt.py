import base64
from Crypto.Cipher import AES
import string
import os

key = os.urandom(16)
chars = string.ascii_uppercase + string.ascii_lowercase + string.digits
secrets       = b'HogeFugaPiyoSpamHogeFugaPiyoSpamHogeFugaPiyoSpamHogeFugaPiyoSpam'
cipher_base64 = "FyRyZNBO2MG6ncd3hEkC/yeYKUseI/CxYoZiIeV2fe/Jmtwx+WbWmU1gtMX9m905"

## -----------------------------------------
## original decrypt
## -----------------------------------------
def encrypt(key, text):
    s = ''
    #文字列の最初の文字から最後の文字までループ
    for i in range(len(text)):
        #ord ... 文字のascii番地
        #後ろからi番目から0x20を引いたascii番地の0x5fの余剰をとって
        #前からi番目の0x20を引いたascii番地を足して
        #0x20を足したところをsとする
        fst = (ord(text[i]) - 0x20)
        scd = (ord(key[i % len(key)]) - 0x20)
        # thd = (0x7e - 0x20 + 1
        s += chr(((fst + scd) % 0x5f) + 0x20)
    return s

def decrypt(enc):
    text = ""
    key = "SECCON"

    for i in reversed(range(len(enc1))):
        tmp = ord(enc[i]) - 0x20
        # mod 0x5f
        scd  = ord(key[i % len(key)]) - 0x20
        # fst + scd
        fst  = tmp - scd

        while not str(chr(fst + 0x20)).isalnum:
            fst += 0x5f
        text += chr(fst + 0x20)
    
    return text




if __name__ == "__main__":
    # cipher_base64 -> cipher_bin
    cipher_bin = base64_to_bin(cipher_base64)
    print(cipher_bin)

    secret = decrypt_AES()
