touch Task4Keys.txt

#Generate secret key and initial vectors for each cipher
printf "\nAES-128-CBC\n" > Task4Keys.txt
openssl enc -aes-128-cbc -iter 100 -k secret -P -md sha1 >> Task4Keys.txt

printf "\nAES-128-ECB\n" >> Task4Keys.txt
openssl enc -aes-128-ecb -iter 100 -k secret -P -md sha1 >> Task4Keys.txt

printf "\nAES-128-CFB\n" >> Task4Keys.txt
openssl enc -aes-128-cfb -iter 100 -k secret -P -md sha1 >> Task4Keys.txt

printf "\nAES-128-OFB\n" >> Task4Keys.txt
openssl enc -aes-128-ofb -iter 100 -k secret -P -md sha1 >> Task4Keys.txt
