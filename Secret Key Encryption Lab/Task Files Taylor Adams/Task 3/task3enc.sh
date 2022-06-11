#Encrypts data using AES-128-CBC
openssl enc -aes-128-cbc -e -in UA.bmp -out pic_cbc.bmp -K 368F70E8784B5363A0871B31B217678E -iv B7C04A8744BAECF2397281F5204B3EB6

#Encrypts data using AES-128-ECB
openssl enc -aes-128-ecb -e -in UA.bmp -out pic_ecb.bmp -K 9472115647B9075E7F5FFAAE99C2BEAB

#Repair the encrypted bmp images
head -c 54 UA.bmp  > header
tail -c +55 pic_ecb.bmp > body
cat header body > ecb_repaired.bmp

tail -c +55 pic_cbc.bmp > body
cat header body > cbc_repaired.bmp
