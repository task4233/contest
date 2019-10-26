import requests
import string

URL = 'htttp://web-search.chal.seccon.jp/'
chars = string.ascii_uppercase + string.ascii_lowercase + string.digits


def get_length():
    ng = -1
    ok = 1024

    while ok - ng > 1:
        mid = (ok + ng) // 2
        
