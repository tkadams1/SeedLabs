#Encrypts data using AES-128-CBC
openssl enc -aes-128-cbc -d -in aes-128-cbcEData.bin -out aes-128-cbc-d.txt -K 0F529044ECA70F0867A73A6DC38530ED -iv 080F128D233A0EFB87165F8763355A70

#Encrypts data using AES-128-ECB
openssl enc -aes-128-ecb -d -in aes-128-ecbEData.bin -out aes-128-ecb-d.txt -K 9A1F479D32448B969838A9A361E0C7AE

#Encrypts data using Camilla-128-CBC
openssl enc -camellia-128-cbc -d -in camilla-128-cbcEData.bin -out camilla-128-cbc-d.txt -K 40FD2B875B4D132F8F47CEC000C8E1B1 -iv BDE188A7C8B53F3B08856D8386D6A683

#Encrypts data using DES-ECB
openssl enc -des-ecb -d -in DesECBEData.bin -out Des-ecb-d.txt -K 21B3B91748FE01A5

#Intentionally wrong key DES-ECB
openssl enc -des-ecb -d -in DesECBEData.bin -out WRONGDes-ecb-d.txt -K 21B3B91748FE01A6
