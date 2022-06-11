#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Feb 10 12:58:41 2022

@author: tayloradams
"""

from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

IV_hex = '010203040506070809000a0b0c0d0e0f'
plaintext = 'This is CS542 class Lab 1 task 7.'
ciphertext_hex_to_find = '8befe2fe4733ce57e2884cef864f66ed1e7c8659e9b031e3b87e951427b10213675873dff380fe0862e9068bdf43eb7e'

with open('words.txt') as words_list_file:
    
    test_key = ""
    #while loop that ends when word list file ends
    while(test_key != '################'):

        #read the next line in the word list
        word = words_list_file.readline()
        #Remove new line character
        word = word[:-1]
        
        #if length of the word is less than 16 chars add padding
        if(len(word) <= 16):
            padding_int = 16 - (len(word))
            test_key = word + ('#' * padding_int)
        #if length of word is greater than 16 chars skip to next word
        elif(len(word) > 16):
            pass
        #if length is 16 make key to test = word
       # elif(len(shave_length = 16)):
       #     test_key = word

        #put key as test_key in bytes for AES
        key = str.encode(test_key)
        #print(key)
        print(test_key)
        
        #convert the IV to bytes (Needed for insertion into AES.new method)
        IV_bytes = bytes.fromhex(IV_hex)
        text = str.encode(plaintext)

        #set encryption algorithm
        AES_enc = AES.new(key, AES.MODE_CBC, IV_bytes)
        #encrypt the plaintext
        #print(AES.block_size) = 16 
        ciphertext = AES_enc.encrypt(pad(text, AES.block_size))
        #print(ciphertext)
        
        #convert ciphertext to hex format
        ciphertext_hex_to_test = ciphertext.hex()
        
        print(ciphertext_hex_to_test)
        
        if (ciphertext_hex_to_test == ciphertext_hex_to_find):
            print("\n#############################################################")
            print(f"\nKey: {word}")
            print(f"Ciphertext to find\t: {ciphertext_hex_to_find}")
            print(f"Ciphertext Found\t: {ciphertext_hex_to_find}")
            print("\n#############################################################")
            break

words_list_file.close()