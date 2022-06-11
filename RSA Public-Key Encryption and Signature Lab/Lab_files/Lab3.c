#include <stdio.h>
#include <openssl/bn.h>
#include <string.h>

#define NBITS 256

void bnSample();
void printBN(char *msg, BIGNUM * a);
void task1();
BIGNUM* get_private_key(BIGNUM* p, BIGNUM* q, BIGNUM* e);
void task2();
void string2hexString(char* input, char* output);
void task3();
void hex_to_string(uint8_t* msg, size_t msg_sz, uint8_t* hex, size_t hex_sz);
void task4();
void task5();
void task6();


/*
M = plaintext
d = private key
e = public key
n = modulus
(e, n) = public key pair

d = e^(-1) mod tt(n)

*/

//##############################################################
//Main
//##############################################################

int main(){
   // bnSample();
    task1();
	task2();
	task4();
	task5();
	task6();
    return 0;
}
//##############################################################
//Task 1
//##############################################################

void task1(){

	printf("\nTask 1: \n");

    BIGNUM *p = BN_new();
	BIGNUM *q = BN_new();
	BIGNUM *e = BN_new();
	
	// Assign the first large prime
	BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
	
	// Assign the second large prime
	BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
	
	// Assign the Modulus
	BN_hex2bn(&e, "0D88C3");

	BIGNUM* priv_key1 = get_private_key(p, q, e);
	printBN("the private key for task1 is:", priv_key1);

return;
}

BIGNUM* get_private_key(BIGNUM* p, BIGNUM* q, BIGNUM* e)
{
	//Initialize big number variables
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM* p_minus_one = BN_new();
	BIGNUM* q_minus_one = BN_new();
	BIGNUM* one = BN_new();
	BIGNUM* tt = BN_new();

	BN_dec2bn(&one, "1");
	///BN_sub() subtracts b from a and places the result in r ("r=a-b")
	BN_sub(p_minus_one, p, one);
	BN_sub(q_minus_one, q, one);
	//BN_mul() multiplies a and b and places the result in r ("r=a*b"). r may be the same BIGNUM as a or b. For multiplication by powers of 2, use bn_lshift(3).
	BN_mul(tt, p_minus_one, q_minus_one, ctx);

	BIGNUM* res = BN_new();
	//BN_mod_inverse() computes the inverse of a modulo n places the result in r ("(a*r)%n==1"). If r is NULL, a new BIGNUM is created.
	BN_mod_inverse(res, e, tt, ctx);

	// ctx is a previously allocated BN_CTX used for temporary variables. r may be the same BIGNUM as a or n.
	BN_CTX_free(ctx);


	return res;
}

//##############################################################
//Task 2 and 3
//##############################################################
void task2(){

	printf("\nTask 2:\n");

	//initialize strings
	char ascii_str[] = "TaylorAdams+11702550";
	int len = strlen(ascii_str);
	char hex_str[(len*2)+1];

	//convert string to hex
	string2hexString(ascii_str, hex_str);

	//Print the hex string generated
	printf("Hex string:\t %s", hex_str);

	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *private_key_d = BN_new();
	BIGNUM *modulus_n = BN_new();
	BIGNUM *public_key_e = BN_new();
	BIGNUM *plaintext_M = BN_new();
	// converts the plaintext to be encrypted from hex to binary and stores in a big number
	BN_hex2bn(&plaintext_M, hex_str);
	printBN("\nBIGNUM plaintext before encryption:\t\t", plaintext_M);

	BN_hex2bn(&modulus_n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_dec2bn(&public_key_e, "65537");
	BN_hex2bn(&private_key_d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

	BIGNUM *ciphertext = BN_new();
	BN_mod_exp(ciphertext, plaintext_M, public_key_e, modulus_n, ctx);
	BN_CTX_free(ctx);
	printBN("ciphertext:\t", ciphertext);
	
	task3(ciphertext, private_key_d, public_key_e, modulus_n);
	

}

void task3(BIGNUM* ciphertext, BIGNUM* private_key_d, BIGNUM* public_key_e, BIGNUM* modulus_n){
	
	printf("\nTask 3:\n");

	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *decrypted_ciphertext = BN_new();
	BN_hex2bn(&ciphertext, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
	//decrypt the ciphertext
	BN_mod_exp(decrypted_ciphertext, ciphertext, private_key_d, modulus_n, ctx);
	//print decrypted ciphertext in hex format
	printBN("Decrypted Ciphertext: ", decrypted_ciphertext);
	BN_CTX_free(ctx);
	//generate vars for hex conversion
	uint8_t *hex = BN_bn2hex(decrypted_ciphertext);
	int len = strlen(hex);
	uint8_t *ascii[100];
	int ascii_len = 100;
	hex_to_string(ascii, ascii_len, hex, len);

	return;
}

//converts a string to hex using c instead of python
void string2hexString(char* input, char* output)
{
    int loop;
    int i; 
    
    i=0;
    loop=0;
    
    while(input[loop] != '\0')
    {
        sprintf((char*)(output+i),"%02X", input[loop]);
        loop+=1;
        i+=2;
    }
    //insert NULL at the end of the output string
    output[i++] = '\0';
}

void hex_to_string(uint8_t* msg, size_t msg_sz, uint8_t* hex, size_t hex_sz)
{
   memset(msg, '\0', msg_sz);
   if (hex_sz % 2 != 0 || hex_sz/2 >= msg_sz)
      return;

   for (int i = 0; i < hex_sz; i+=2)
   {
      uint8_t msb = (hex[i+0] <= '9' ? hex[i+0] - '0' : (hex[i+0] & 0x5F) - 'A' + 10);
      uint8_t lsb = (hex[i+1] <= '9' ? hex[i+1] - '0' : (hex[i+1] & 0x5F) - 'A' + 10);
      msg[i / 2] = (msb << 4) | lsb;
   }

   printf("The decrypted hex is: %s", msg);
}


//##############################################################
//Task 4
//##############################################################
void task4(){

printf("\n\nTask 4:\n");

//initialize strings and convert to hex
char string[] = "Taylor Adams owes you $2000";
char string1[] = "Taylor Adams owes you $3000";
int len = strlen(string);
char string_hex[(len*2)+1];
char string1_hex[(len*2)+1];
string2hexString(string, string_hex);
string2hexString(string1, string1_hex);

//Initialize bignum variables
BIGNUM* string_M = BN_new();
BIGNUM* string1_M = BN_new();
BN_CTX *ctx = BN_CTX_new();
BIGNUM *private_key_d = BN_new();
BIGNUM *modulus_n = BN_new();
BIGNUM *public_key_e = BN_new();

//convert hex to BIGNUM data type
BN_hex2bn(&string_M, string_hex);
BN_hex2bn(&string1_M, string1_hex);

//declare the BIGNUM variables
BN_hex2bn(&modulus_n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
BN_dec2bn(&public_key_e, "65537");
BN_hex2bn(&private_key_d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

//create output BIGNUMs to pass to BN_mod_exp
BIGNUM *signed_Message = BN_new();
BIGNUM *signed_Message1 = BN_new();
/*m^d mod n
In order to sign a message you need to to perform the operation m^d mod n where m = the message; d = private key; and n =
*/
BN_mod_exp(signed_Message, string_M, private_key_d, modulus_n, ctx);

BN_mod_exp(signed_Message1, string1_M, private_key_d, modulus_n, ctx);


printBN("\nSigned Message:\t\t", signed_Message);

printBN("\nSigned Message Modified:", signed_Message1);

// BN_mod_exp(signed_Message, signed_Message, public_key_e, modulus_n, ctx);

// printBN("\nUnsigned Message:", signed_Message);

BN_CTX_free(ctx);
}


//##############################################################
//Task 5
//##############################################################

void task5(){

	printf("\nTask 5: \n");

	//initialize the BN values
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *modulus_n = BN_new();
	BIGNUM *public_key_e = BN_new();
	BIGNUM *digital_signature_S = BN_new();

	//corrupt the 2F at the end of the signature to 3F and rerun
	BN_hex2bn(&digital_signature_S, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");
	BN_dec2bn(&public_key_e, "65537");
	BN_hex2bn(&modulus_n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");

	BIGNUM *unsigned_Message = BN_new();
	//check S
	BN_mod_exp(unsigned_Message, digital_signature_S, public_key_e, modulus_n, ctx);
	
	//convert BIGNUM to hex and hex to ascii
	uint8_t *hex = BN_bn2hex(unsigned_Message);
	int len = strlen(hex);
	uint8_t *ascii[100];
	int ascii_len = 100;
	hex_to_string(ascii, ascii_len, hex, len);


}

//##############################################################
//Task 6
//##############################################################

void task6(){

	printf("\n\nTask 6: \n");

	//for modulus run: openssl x509 -in c1.pem -noout -modulus
	BIGNUM *modulus_n = BN_new();
	BN_hex2bn(&modulus_n, "BF8AD1634DE118EA875DE8163C8F7FB6BE871737A40CF8313F9F45544021D79D079BCA03234ABD9BED8502633F9F85B9EC28EFF28622DBF84D5441C5B4427FCF3317010E829052D3C734A4C1A101DA32A040AD1F59E433FCA0C396AC686CD3E899738C261077CBB73F3932E8D25928EE0786E2093B85F8AA69F6A96B9F58AD72C85B8766AE08E074FB2D534362833D8F854C1197DC1EFC5030B88308325E5C5CC4E175204AEBA5D6752DDC2D7D7CE0D0FE7C75A14E4002849AD90D5A2EA0ACF3358A2AEAD65A5A6C8E2CABF6DEFD784726797AAA22EAA9E6711203D3F8BA53D2799CBD64ACF61B63BB4D8F3802F8F0575DC5AA255A0C5DC530FE2053196CE9C3");

	//openssl x509 -in c1.pem -text -noout : run command and extract the exponent to get 'e'
	BIGNUM *public_key_e = BN_new();
	BN_dec2bn(&public_key_e, "65537");

	//openssl x509 -in c0.pem -text -noout : then save the S in a file and run the tr command against it to remove all extra spaces and colons : cat signature | tr -d ’[:space:]:’
	BIGNUM *digital_signature_S = BN_new();
	BN_hex2bn(&digital_signature_S, "8f531fedec00fc8a613e59cb74799133b8231f4b9af99be320ce91c6a8350b7437a5d8cba1792150503f38031aa7395c9a2a44ef84b50e6c4820a309090f55b631df831185158fffa83e99afe66790b9757b3be15810e255b301fbf6a47faa8f7bbd78ef74550d499eae2cd44b038909dd86b6e62f64d2fb83beb8cdfe096d68d4e9089bfe3e15db67b150b4b22e61a62f590c84e6c3aad7bad58304ea66681ad0214ba5ae549746468a15de9acf135a844a99c9dabe83bc80a5af762990d36733b57a1305cdc6b2a08d605cce37f0cecfff50477f99aa31b0190f79149e40aa2b395185e1fc68ef9dff23b0d598a6345af8ec2d416d5b62ed0bb3b656c12586");

	//sha256sum c)_body.bin
	//f91d2f5ceae88acf1c9ed475a23ed117e55b5248b34c6052a9d104462bba4684
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *unsigned_Message = BN_new();

	BN_mod_exp(unsigned_Message, digital_signature_S, public_key_e, modulus_n, ctx);

	printBN("\nTask 6 hash:", unsigned_Message);

}

//##############################################################
//Sample code provided by lab
//##############################################################


void printBN(char *msg, BIGNUM * a)
{
   /* Use BN_bn2hex(a) for hex string
    * Use BN_bn2dec(a) for decimal string */
   char * number_str = BN_bn2hex(a);
   printf("%s %s\n", msg, number_str);
   OPENSSL_free(number_str);
}

void bnSample(){
  BN_CTX *ctx = BN_CTX_new();
  BIGNUM *a = BN_new();
  BIGNUM *b = BN_new();
  BIGNUM *n = BN_new();
//PU: a, b, n are pointers to Big numbers
BIGNUM *res = BN_new();
// Initialize a, b, n
BN_generate_prime_ex(a, NBITS, 1, NULL, NULL, NULL);
BN_dec2bn(&b, "273489463796838501848592769467194369268");

//generates a cryptographically strong psuedo-random number of bits
BN_rand(n, NBITS, 0, 0);
// res = a*b
BN_mul(res, a, b, ctx);
printBN("a * b = ", res);
// res = aˆb mod n
BN_mod_exp(res, a, b, n, ctx);
printBN("aˆc mod n = ", res);
}