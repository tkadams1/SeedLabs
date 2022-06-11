#!/usr/bin/python3

# XOR two bytearrays
def xor(first, second):
   return bytearray(x^y for x,y in zip(first, second))

MSG   = "This is a known message!"
HEX_1 = "a469b1c502c1cab966965e50425438e1bb1b5f9037a4c159"
HEX_2 = "bf73bcd3509299d566c35b5d450337e1bb175f903fafc159"

HEX_3 = "EE10A1FA65430C9C902CD8CB1A3E6C8B43787529A22850CCDDAC"
HEX_4 = "F50AACEC37105FF09079DDC61D69638BC2D9E189D31B439C03"
# Convert ascii string to bytearray
D1 = bytes(MSG, 'utf-8')

# Convert hex string to bytearray
D2 = bytearray.fromhex(HEX_3)
D3 = bytearray.fromhex(HEX_4)

r1 = xor(D1, D2)
r2 = xor(D2, D3)
r3 = xor(D2, D2)
r4 = xor(r1, D3)
print(r1.hex())
print(r2.hex())
print(r3.hex())
print(r4)