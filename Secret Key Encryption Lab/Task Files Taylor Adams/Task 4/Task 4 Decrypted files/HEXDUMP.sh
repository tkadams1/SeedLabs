
printf "\nAES-128-CBC\n" > Task4DUMP.txt
hexdump -C f1-cbc-D.txt >>Task4DUMP.txt
hexdump -C f2-cbc-D.txt >>Task4DUMP.txt
hexdump -C f3-cbc-D.txt >>Task4DUMP.txt

printf "\nAES-128-ECB\n" >> Task4DUMP.txt
hexdump -C f1-ecb-D.txt >>Task4DUMP.txt
hexdump -C f2-ecb-D.txt >>Task4DUMP.txt
hexdump -C f3-ecb-D.txt >>Task4DUMP.txt

printf "\nAES-128-CFB\n" >> Task4DUMP.txt
hexdump -C f1-cfb-D.txt >>Task4DUMP.txt
hexdump -C f2-cfb-D.txt >>Task4DUMP.txt
hexdump -C f3-cfb-D.txt >>Task4DUMP.txt

printf "\nAES-128-OFB\n" >> Task4DUMP.txt
hexdump -C f1-ofb-D.txt >>Task4DUMP.txt
hexdump -C f2-ofb-D.txt >>Task4DUMP.txt
hexdump -C f3-ofb-D.txt >>Task4DUMP.txt
