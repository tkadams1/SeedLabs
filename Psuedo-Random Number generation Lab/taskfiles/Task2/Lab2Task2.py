from Crypto.Cipher import AES
from Crypto import Random

def main():

    plaintext = bytearray.fromhex("255044462d312e350a25d0d4c5d80a34")
    known_Ciphertext = bytearray.fromhex("d06bf9d0dab8e8ef880660d2af65aa82")
    iv = bytearray.fromhex("09080706050403020100A2B2C2D2E2F2")
    start_time = 1524013729
    end_time = 1524020929
    #i = start_time
    keyfound = False

    key_list = open("possible_keys.txt", "r")
    for key in key_list:
        key = key.strip('\n')
        #print(key)
        key = bytearray.fromhex(key)
        cipher = AES.new(key, AES.MODE_CBC, iv)
        testciphertext = cipher.encrypt(plaintext)
        if testciphertext.hex() == known_Ciphertext.hex():
            keyfound = True
            print("Key found: " + key.hex())
            break
        #i += 1
        #print("Ciphertext: " + testciphertext.hex())
        #print("Known Ciphertext: " + known_Ciphertext.hex())
    
    if keyfound == False:
        print("Key not found")

main()
