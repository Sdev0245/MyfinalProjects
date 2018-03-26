//own block chain
//codeBy Deven Sharma
//NIT HAMIRPUR
//My own BlockChain
# include <bits/stdc++.h>
# include <openssl/sha.h>
# include <openssl/crypto.h>
# include <unistd.h>
# define SHA256_DIGEST_LENGTH 32
# include <ctime>
# define ll long long 
using namespace std;
struct block
{
	int amount;
	int data;
	unsigned char prevHash[SHA256_DIGEST_LENGTH];
	struct block *link;
} *head;
void TransferMoney(int n ,int amount);
void addBlock(ll data);
void printBlocks();
void check();
void addNewData(int n, int newData);
void changeHash();
 unsigned char* toString( struct block);
void hashPrinter(unsigned char hash[SHA256_DIGEST_LENGTH] ,int len);
int hashCompare(char *a ,char *b);

void addBlock(ll data)
{
	if(head==NULL)
	{
		

		head =new block();
		SHA256((unsigned char *)" ",sizeof(" "),(unsigned char*)(head->prevHash));
		head->data=data;
		cout<<"Adding BLock ............................."<<endl;
		usleep(100000);
		cout<<"Block added"<<endl;

		return;

	}
	struct block *myblock=head;

	while(myblock->link)
	{
		myblock =myblock->link;
		cout<<myblock->data<<" "<<endl;
		
	}

	struct block *current = new block();
	myblock->link = current;
	current->data=data;
	cout<<"Adding BLock ............................."<<endl;
		usleep(100000);
		cout<<"Block added"<<endl;

	SHA256(toString(*myblock),sizeof(*myblock),current->prevHash);
}
void check()
{
	if(head == NULL)
	{
		cout<<"currently our blockChain is empty"<<endl;
		return;
	}
	struct block *temp ;
	temp =head->link;
		struct block *prev= head;


	int count=1;
	while(temp)
	{
		cout<<count<<" "<<temp->data<<endl;
		hashPrinter(SHA256(toString(*prev),sizeof(*prev),NULL),SHA256_DIGEST_LENGTH);
cout<<endl;
		hashPrinter(temp->prevHash,SHA256_DIGEST_LENGTH);
		cout<<endl;
		
		if(hashCompare(
				(char* )SHA256(toString(*prev),sizeof(*prev),NULL),
				(char* ) (temp->prevHash)
			)
		 )
		{	cout<<"Your current Block is Varified";
	cout<<endl;

prev=temp;
			temp=temp->link;

}

		else
		{
			cout<<"! Current Block is not varified"<<" "<<endl; 
			
prev=temp;
			temp=temp->link;

		}
	}

}
void addNewData(int n, int newData)
{
	int count=0;
	struct  block *temp =head;
	if(head == NULL)
	{
		cout<<"No such block number exists in block chain"<<endl;
		return ;

	}
	while(count!=n)

	{
		if(count!=n && temp->link==NULL)
		{

			cout<<"NO such Block Exists"<<endl;

		}
		else if(count==n)
		{

			break;
		}
		temp = temp->link;
		count++;

	}
	temp->data =newData;

}
void changeHash()
{
	struct block *temp =head->link, *prev =head;
	if(temp==NULL)
		{cout<<"Your blockChain is empty"<<endl;
return;}
	while(temp)
	{
		prev=temp;
		temp=temp->link;
		if(!(SHA256(toString(*prev),sizeof(*prev),NULL),temp->prevHash))
		{
			hashPrinter((SHA256(toString(*prev),sizeof(*prev),NULL),temp->prevHash),SHA256_DIGEST_LENGTH);
			cout<<"Hash changed"<<" ";


		}
		cout<<endl;


	}


}
 unsigned char *toString(struct block bc)
{
	unsigned char *str = (unsigned char *)malloc( sizeof(unsigned char)*sizeof(bc));
	memcpy(str,&bc,sizeof(bc));
	return str;

}
void hashPrinter(unsigned char hash[10000] ,int len)
{
	for(int  i= 0 ;i< len ;i++)
		printf("%02x",hash[i]);
}
// int  hashCompare(unsigned char *a ,unsigned char *b)
int  hashCompare(char *a ,char *b)
{
	for(ll i =0 ;i< SHA256_DIGEST_LENGTH ;i++)
	{
		if(a[i]!=b[i])
			return  0 ;
	}
	return 1;

}
void TransferMoney(int n ,int amount)
{
	struct block *temp =head;
	if(head == NULL)
	{
		cout<<"There is no one active"<<endl;
	}
	int count=1;
	int flag=0;
	while(temp->link)
	{
		
		 if(count == n)
		{
			temp->amount =amount;
			cout<<"..................Transfeering money.................."<<" "<<endl;
			usleep(2000000);
			cout<<"Money Transferred to"<<"" <<endl;
			hashPrinter(temp->prevHash,SHA256_DIGEST_LENGTH);
			cout<<endl; 	
			usleep(2000000);
			return;	 


		}
		else
		{
			//cout<<count<<" ";
		  temp = temp->link;
			count++;
		}

	}
	cout<<"NO such block exists"<<endl;
}
void printBlocks(struct block *head)
{
	struct block *temp = head;
	while(temp->link)
	{
		temp=temp->link;
		hashPrinter(temp->prevHash,sizeof(temp->prevHash));
		printf("%p\n",temp );
		printf("[%d]\n",temp->data );
	}

	
}
int main()
{
	ll a,b,c,d;
		int amount1, block1;
	
	do
	{
		cout<<endl;
		cout<<"(1).addBlock \n (2).check  \n (3).addNewData  \n (4).changeHash \n (5).printBlocks \n(6).TransferMoney"<<endl;
		cin>>a;

		switch(a)
		{
			case 1:
				cout<<"enter the data :";
				cin>>c;
				addBlock(c);
				break;
			case 2:
				check();
				break;
			case 3:
				cout<<"enter the pos and newValue where you want to enter";
				cin>>c>>d;
				addNewData(c,d);
				break;
			case 4:
				cout<<"It will change the hashes that are not varified"<<endl;
				changeHash();
				break;
			case 5:
				cout<<"It will printBlocks"<<endl;
				printBlocks(head);
				break;
			case 6:
				cout<<"This will help you to TransferMoney enter block no and amount"<<" ";
				cin>>block1>>amount1;
				TransferMoney(block1,amount1);
				break;

			default:
				break;


		}

	}while(1);


	return 0;


}
