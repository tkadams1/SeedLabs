touch Task3Keys.txt

#Generate secret key and initial vectors for each cipher
printf "\nAES-128-CBC\n" > Task3Keys.txt
openssl enc -aes-128-cbc -iter 123 -k secret -P -md sha1 >> Task3Keys.txt

printf "\nAES-128-ECB\n" >> Task3Keys.txt
openssl enc -aes-128-ecb -iter 456 -k secret -P -md sha1 >> Task3Keys.txt
