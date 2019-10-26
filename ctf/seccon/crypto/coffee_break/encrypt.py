import sys
import base64
from Crypto.Cipher import AES
import string

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

def decrypt(key, enc):
    text = ''

    for i in range(len(enc)):
        tmp = ord(enc[i]) - 0x20
        # mod 0x5f
        scd  = ord(key[i % len(key)]) - 0x20
        # fst + scd
        fst  = tmp - scd

        sm = fst + 0x20
        while (sm < 0):
            sm += 0x5f
        while not str(chr(sm)).isalnum():
            sm += 0x5f
        text += chr(sm)
    
    return text


## -----------------------------------------
## AES decrypt
## -----------------------------------------
# cipher = cipher.new(key, MODE_ECB)
# enc_bytes = cipher.encrypt(plain + chr(p) * p)
def decrypt_AES(enc_bytes, key, cipher, p):
    chars = string.ascii_uppercase + string.ascii_lowercase + string.digits
    plain = cipher.decrypt(enc_bytes).decode('ascii')
    return plain
    
## -----------------------------------------
## base64 -> bytes
## -----------------------------------------
def bytes_to_base64(cipher_bytes):
    return base64.b64encode(cipher_bytes).decode('ascii')

def base64_to_bytes(cipher_base64):
    return base64.b64decode(cipher_base64.encode('ascii'))

## -----------------------------------------
## main
## -----------------------------------------
if __name__ == "__main__":
    cipher_base64 = "FyRyZNBO2MG6ncd3hEkC/yeYKUseI/CxYoZiIeV2fe/Jmtwx+WbWmU1gtMX9m905"
    
    # base64 -> bytes
    print("cipher_base64 : " + cipher_base64)
    cipher_bytes = base64_to_bytes(cipher_base64)
    print("cipher_bytes  : ", end="")
    print(cipher_bytes)

    ## AES part

    # static
    # key2を16の倍数まで0x00で埋めてECBモードでAESしたものをcipherに渡す
    key2 = "seccon2019"
    key = key2 + chr(0x00) * (16 - (len(key2) % 16))
    cipher = AES.new(key, AES.MODE_ECB)
    p = 16 - (len(cipher_base64) % 16)

    dec2_str = decrypt_AES(cipher_bytes, key, cipher, p)
    
    print("dec2_str      : " + dec2_str)

    ## --------------------------------------------------------------------
    ## key1でtextを暗号化
    ## --------------------------------------------------------------------
    key1 = "SECCON"
    dec1 = decrypt(key1, dec2_str)
    print("dec1          : " + dec1)
        
