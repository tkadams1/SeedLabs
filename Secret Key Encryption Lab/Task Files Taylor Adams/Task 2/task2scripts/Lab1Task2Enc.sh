#Encrypts data using AES-128-CBC
openssl enc -aes-128-cbc -e -in testText.txt -out aes-128-cbcEData.bin -K 0F529044ECA70F0867A73A6DC38530ED -iv 080F128D233A0EFB87165F8763355A70

#Encrypts data using AES-128-ECB
openssl enc -aes-128-ecb -e -in testText.txt -out aes-128-ecbEData.bin -K 9A1F479D32448B969838A9A361E0C7AE

#Encrypts data using Camilla-128-CBC
openssl enc -camellia-128-cbc -e -in testText.txt -out camilla-128-cbcEData.bin -K 40FD2B875B4D132F8F47CEC000C8E1B1 -iv BDE188A7C8B53F3B08856D8386D6A683

#Encrypts data using DES-ECB
openssl enc -des-ecb -e -in testText.txt -out DesECBEData.bin -K 21B3B91748FE01A5
