#create files for encryption

echo -n "12345" > f1.txt
echo -n "12345678910" > f2.txt
echo -n "12345678910111213141516" > f3.txt

###########################################################################################
#ENCRYPTION
###########################################################################################
#Encrypts data using AES-128-CBC
openssl enc -aes-128-cbc -e -in f1.txt -out f1-cbc.bin -K FF2352FF6A9A2E66741AF7281EC6714D -iv 00114187D0FE385B4B2F41F6A57BE18F

openssl enc -aes-128-cbc -e -in f2.txt -out f2-cbc.bin -K FF2352FF6A9A2E66741AF7281EC6714D -iv 00114187D0FE385B4B2F41F6A57BE18F

openssl enc -aes-128-cbc -e -in f3.txt -out f3-cbc.bin -K FF2352FF6A9A2E66741AF7281EC6714D -iv 00114187D0FE385B4B2F41F6A57BE18F
###########################################################################################
#Encrypts data using AES-128-ECB
openssl enc -aes-128-ecb -e -in f1.txt -out f1-ecb.bin -K 32E6490D99FA30A8432D49C520C537F1

openssl enc -aes-128-ecb -e -in f2.txt -out f2-ecb.bin -K 32E6490D99FA30A8432D49C520C537F1

openssl enc -aes-128-ecb -e -in f3.txt -out f3-ecb.bin -K 32E6490D99FA30A8432D49C520C537F1
###########################################################################################
#Encrypts data using AES-128-CFB
openssl enc -aes-128-cfb -e -in f1.txt -out f1-cfb.bin -K 687DA64933D509216EA070012C5AB53B -iv 4456A52DE3F0341BA437927C0C4EFEC9

openssl enc -aes-128-cfb -e -in f2.txt -out f2-cfb.bin -K 687DA64933D509216EA070012C5AB53B -iv 4456A52DE3F0341BA437927C0C4EFEC9

openssl enc -aes-128-cfb -e -in f3.txt -out f3-cfb.bin -K 687DA64933D509216EA070012C5AB53B -iv 4456A52DE3F0341BA437927C0C4EFEC9
###########################################################################################
#Encrypts data using AES-128-OFB
openssl enc -aes-128-ofb -e -in f1.txt -out f1-ofb.bin -K 78E847DE43497F272D75894A11F8CEC0 -iv F305CFC8EE930EC8906D6AB0F8D8FE08

openssl enc -aes-128-ofb -e -in f2.txt -out f2-ofb.bin -K 78E847DE43497F272D75894A11F8CEC0 -iv F305CFC8EE930EC8906D6AB0F8D8FE08

openssl enc -aes-128-ofb -e -in f3.txt -out f3-ofb.bin -K 78E847DE43497F272D75894A11F8CEC0 -iv F305CFC8EE930EC8906D6AB0F8D8FE08
###########################################################################################
#DECRYPTION
###########################################################################################
#Encrypts data using AES-128-CBC
openssl enc -aes-128-cbc -d -out f1-cbc-D.txt -in f1-cbc.bin -K FF2352FF6A9A2E66741AF7281EC6714D -iv 00114187D0FE385B4B2F41F6A57BE18F -nopad

openssl enc -aes-128-cbc -d -out f2-cbc-D.txt -in f2-cbc.bin -K FF2352FF6A9A2E66741AF7281EC6714D -iv 00114187D0FE385B4B2F41F6A57BE18F -nopad

openssl enc -aes-128-cbc -d -out f3-cbc-D.txt -in f3-cbc.bin -K FF2352FF6A9A2E66741AF7281EC6714D -iv 00114187D0FE385B4B2F41F6A57BE18F -nopad
###########################################################################################
#Encrypts data using AES-128-ECB
openssl enc -aes-128-ecb -d -out f1-ecb-D.txt -in f1-ecb.bin -K 32E6490D99FA30A8432D49C520C537F1 -nopad

openssl enc -aes-128-ecb -d -out f2-ecb-D.txt -in f2-ecb.bin -K 32E6490D99FA30A8432D49C520C537F1 -nopad

openssl enc -aes-128-ecb -d -out f3-ecb-D.txt -in f3-ecb.bin -K 32E6490D99FA30A8432D49C520C537F1 -nopad
###########################################################################################
#Encrypts data using AES-128-CFB
openssl enc -aes-128-cfb -d -out f1-cfb-D.txt -in f1-cfb.bin -K 687DA64933D509216EA070012C5AB53B -iv 4456A52DE3F0341BA437927C0C4EFEC9 -nopad

openssl enc -aes-128-cfb -d -out f2-cfb-D.txt -in f2-cfb.bin -K 687DA64933D509216EA070012C5AB53B -iv 4456A52DE3F0341BA437927C0C4EFEC9 -nopad

openssl enc -aes-128-cfb -d -out f3-cfb-D.txt -in f3-cfb.bin -K 687DA64933D509216EA070012C5AB53B -iv 4456A52DE3F0341BA437927C0C4EFEC9 -nopad
###########################################################################################
#Encrypts data using AES-128-OFB
openssl enc -aes-128-ofb -d -out f1-ofb-D.txt -in f1-ofb.bin -K 78E847DE43497F272D75894A11F8CEC0 -iv F305CFC8EE930EC8906D6AB0F8D8FE08 -nopad

openssl enc -aes-128-ofb -d -out f2-ofb-D.txt -in f2-ofb.bin -K 78E847DE43497F272D75894A11F8CEC0 -iv F305CFC8EE930EC8906D6AB0F8D8FE08 -nopad

openssl enc -aes-128-ofb -d -out f3-ofb-D.txt -in f3-ofb.bin -K 78E847DE43497F272D75894A11F8CEC0 -iv F305CFC8EE930EC8906D6AB0F8D8FE08 -nopad
