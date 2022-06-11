
touch Task2Keys.txt

#Generate secret key and initial vectors for each cipher
printf "\nAES-128-CBC\n" > Task2Keys.txt
openssl enc -aes-128-cbc -iter 123 -k secret -P -md sha1 >> Task2Keys.txt

printf "\nAES-128-ECB\n" >> Task2Keys.txt
openssl enc -aes-128-ecb -iter 456 -k secret -P -md sha1 >> Task2Keys.txt

printf "\nCamellia-128-CBC\n" >> Task2Keys.txt
openssl enc -camellia-128-cbc -iter 789 -k secret -P -md sha1 >> Task2Keys.txt

printf "\nDES-ECB\n" >> Task2Keys.txt
openssl enc -des-ecb -iter 1112 -k secret -P -md sha1 >> Task2Keys.txt
