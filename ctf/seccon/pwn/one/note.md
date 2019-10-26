# one
> Host : one.chal.seccon.jp
Port : 18357

 - `$ checksec -f ./one`
   - `checksec` can install `$ apt install checksec`
   - checksec - check executables and kernel properties
   - `-f`: Checks individual files for security features compiled into the executable

```
 # checksec.sh --file=one
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH	Symbols		FORTIFY	Fortified	Fortifiable  FILE
Full RELRO      Canary found      NX enabled    PIE enabled     No RPATH   No RUNPATH   82 Symbols     Yes	0		2	one
 ```
 - ptrlib
   - $ apt install python3-gmpy2
   - $ python3 -m pip install ptrlib
