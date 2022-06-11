
from Crypto.Util.Padding import pad

def add_padding(string):
    return pad(bytes(string, 'utf-8'), 16)

def xor(first, second):
   return bytearray(x^y for x,y in zip(first, second))

def hex_to_bytes(string):
    return bytearray.fromhex(string)

def main():

    #bob_CT = '3b1580ae7f7cc2fced76ac8406311d29'
    bob_Y = 'Yes'
    bob_N = 'No'
    next_IV = '538c4c7a1fae807d3c9eaa029d8b358b'
    prev_IV = '83213d591fae807d3c9eaa029d8b358b'

    bob_Y = add_padding(bob_Y)
    bob_N = add_padding(bob_N)

    prev_IV = hex_to_bytes(prev_IV)
    next_IV = hex_to_bytes(next_IV)

    my_P_yes = xor(xor(bob_Y, prev_IV), next_IV)
    print("Yes\t:", my_P_yes.hex())
   

    my_P_no = xor(xor(bob_N, prev_IV), next_IV)
    print("No\t:", my_P_no.hex())

main()