### BLOCKCHAIN USING C++
Hi friends here i have created a local block chain using C++.I have basically used the Openssl library for the cryptography.I 
was mesmrized by this technology in 2nd year.So few days back i started understanding the block chain.I have basically made the 
structure (a dummy block) in the block you can add the data ,hashes the hash is the 32 bit and is generated by SHA256() 
provided by Openssl.

```
struct block
{
	int amount; //for the transaction
	int data;
	unsigned char prevHash[SHA256_DIGEST_LENGTH];//stores the hashed 
	struct block *link;  ///link to previous block 
  
}

```
__SHA256(toString(*prev),sizeof(*prev),NULL),SHA256_DIGEST_LENGTH) //SHA256 that takes source ,size and destination block.__
In the block chain ,that i have created you can add a new block,check the validity of block(By comparing the hash of current and previous block) 
and also a dummy tracnsaction can be done