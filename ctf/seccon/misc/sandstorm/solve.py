import zlib

dc = ''
src_path = input()
dst_path = input()

with open(src_path, 'rb') as f:
    data = f.read()
    dc = zlib.decompress(data)

with open(dst_path, 'wb') as f:
    f.write(dc)
