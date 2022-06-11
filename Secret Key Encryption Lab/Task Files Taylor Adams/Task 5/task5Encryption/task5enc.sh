#AES-128-CBC
openssl enc -aes-128-cbc -e -in task5file.txt -out task5-cbc.bin -K FF2352FF6A9A2E66741AF7281EC6714D -iv 00114187D0FE385B4B2F41F6A57BE18F

#AES-128-ECB
openssl enc -aes-128-ecb -e -in task5file.txt -out task5-ecb.bin -K 32E6490D99FA30A8432D49C520C537F1

#AES-128-CFB
openssl enc -aes-128-cfb -e -in task5file.txt -out task5-cfb.bin -K 687DA64933D509216EA070012C5AB53B -iv 4456A52DE3F0341BA437927C0C4EFEC9

#AES-128-OFB
openssl enc -aes-128-ofb -e -in task5file.txt -out task5-ofb.bin -K 78E847DE43497F272D75894A11F8CEC0 -iv F305CFC8EE930EC8906D6AB0F8D8FE08
