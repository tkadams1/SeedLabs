#AES-128-CBC
openssl enc -aes-128-cbc -d -in task5-cbc-C.bin -out task5cbc-DEC.txt -K FF2352FF6A9A2E66741AF7281EC6714D -iv 00114187D0FE385B4B2F41F6A57BE18F

#AES-128-ECB
openssl enc -aes-128-ecb -d -in task5-ecb-C.bin -out task5-ecb-DEC.txt -K 32E6490D99FA30A8432D49C520C537F1

#AES-128-CFB
openssl enc -aes-128-cfb -d -in task5-cfb-C.bin -out task5-cfb-DEC.txt -K 687DA64933D509216EA070012C5AB53B -iv 4456A52DE3F0341BA437927C0C4EFEC9

#AES-128-OFB
openssl enc -aes-128-ofb -d -in task5-ofb-C.bin -out task5-ofb-DEC.txt -K 78E847DE43497F272D75894A11F8CEC0 -iv F305CFC8EE930EC8906D6AB0F8D8FE08