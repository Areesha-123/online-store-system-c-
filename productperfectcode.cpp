#include<iostream>
#include<fstream>
using namespace std;
struct shopping
{
		int pcode;
		float price;
		float dis;
		string pname;
		void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
			
};

void shopping :: menu()
{
     system("cls");   //  for clear Screen :)  ..     
	int choice;
	string email;
	string password;
	
	while(true){
	cout<<"\t\t\t\t|-------------------------------------|\n";
	cout<<"\t\t\t\t|          UMER Store Main Menu       |\n";
	cout<<"\t\t\t\t|-------------------------------------|\n";
	cout<<"\t\t\t\t|                                     |\n";
	cout<<"\t\t\t\t|  1) Administrator   |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  2) Buyer           |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  3) Exit            |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\n\t\t\t Please select!";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t Please Login \n";
			cout<<"\t\t\t Enter Email   \n";
			cin>>email;
			cout<<"\t\t\t Password       \n";
			cin>>password;
			
			if(email=="riphah@email.com" && password=="riphah@123")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid email/password";
			}
			break;
	case 2:
		{
			buyer();
		}
	case 3:
		{
			exit(0);
		}
    default :
			{
				cout<< "Please select from the given options";
              system("cls");
			}
			if(choice==3){
				break;
			}
}
	}
}

void shopping:: administrator()
{
	 system("cls");
	system("COLOR 80");
	
	int choice;
	while(true){
	cout<<"\n\n\n\t\t\t Administrator menu";
	cout<<"\n\t\t\t|1) Add the product|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_2) Modify the product|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_3) Delete the product|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|4) Back to main menu|";
    
    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;
    
       switch(choice)
    {
    	case 1:
    		add();
    		break;
    	case 2:
    		edit();
    		break;
    	case 3:
    		rem();
    		break;
    	case 4:
    		menu();
    		break;
    	default :
    		cout<<"Invalid choice!";
	}
	if(choice==4){
		break;
	}
	}
}

void shopping:: buyer()
{

int choice;
while(true){
	cout<<"\t\t\t  Buyer \n";
	cout<<"\t\t\t|              | \n";
	cout<<"|                     |\n";
	cout<<"\t\t\t1) Buy product \n";
	cout<<"|                     |\n";
	cout<<"\t\t\t2) Go back     \n";
	cout<<"\t\t\t Enter your choice : ";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
		default :
			cout<<"invalid choice";
	}
}
}

void shopping::add() {         // corrected this method
    fstream data;
    int c;
    bool productExists = false;
    float p, d;
    string n;

    cout << "\n\n\t\t\tAdd new product";
    cout << "\n\n\tProduct code of the product: ";
    cin >> pcode;
    cout << "\n\n\tName of the product: ";
    cin >> pname;
    cout << "\n\n\tPrice of the product: ";
    cin >> price;
    cout << "\n\n\tDiscount on product: ";
    cin >> dis;

    data.open("database.txt");
    if (data.is_open()) {
        while (data >> c >> n >> p >> d) {
            if (c == pcode) {
                productExists = true;
                break;
            }
        }
        data.close();
    }

    if (!productExists) {
       
        data.open("database.txt");
        if (data.is_open()) {
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            cout << "\n\n\t\tRecord inserted!";
        } else {
            cout << "\n\n\t\tError opening file!";
        }
        data.close();
    } else {
        cout << "\n\n\t\tProduct already exists!";
    }
}
void shopping ::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;
	
	data.open("database.txt");
	if(!data)
	{
		cout<<"\n\nFile doesn't exist! ";
	}
	else{
		
		data1.open("database1.txt");
		
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited ";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found sorry!";
		}
	}
}
void shopping::rem()
{
	
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Product code :";
	cin>>pkey;
	data.open("database.txt");
	if(!data)
	{
		cout<<"File doesnt exist";
	}
	else{
		data1.open("database1.txt");
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted succesfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found";
		}
	}
}
void shopping:: list()
{
	fstream data;
	data.open("database.txt");
	cout<<"\n\n|_\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|_\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}
void shopping::receipt() 
	{
		system("cls");
		fstream data;
		
		int arrc[100],arrq[100];
		char choice;
		int c=0;
		float amount=0;
		float dis=0;
		float total=0;
		cout<<"\n\n\t\t\t Receipt ";
		data.open("database.txt");
		if(!data)
		{
			cout<<"\n\n Empty database";
		}
		else
		{
			data.close();                                   
			list();
			cout<<"\n|============================|\n";
			cout<<"\n|                            |";
			cout<<"\n|    Please place the order  |";
			cout<<"\n|============================|\n";
			do
			{
				cout<<"\n\n Product Code : ";
				cin>>arrc[c];
				cout<<"\n Product Quantity : ";
				cin>>arrq[c];
				for(int i=0;i<c;i++)
				{
					if(arrc[c] == arrc[i])
					{
						cout<<"\n\n Duplicate Product Code. Please try again!";
					}
				}
				c++;             
				cout<<"\n\n Want to buy another product? Press y for yes and n for no : ";
				cin>>choice;	
			}
			while(choice == 'y');
			system("cls");
			
			cout<<"\n\n\t\t\t__RECEIPT\n";
			cout<<"\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";
			
			for(int i=0;i<c;i++) 
			{
				data.open("database.txt");
				data>>pcode>>pname>>price>>dis;
				while(!data.eof())
				{
					if(pcode == arrc[i])   
					{
						amount = price*arrq[i];
						dis = amount - (amount*dis/100);
						total =total+ dis;
						cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;	
					}
					   data>>pcode>>pname>>price>>dis;  
				}
				data.close();
			}
			cout<<"\n\n----------------------------------------";
			cout<<"\n Total Amount : "<<total;
		}
	}
int main()
{
system("COLOR 60"); // For adding Color to Screen
	shopping s;
	s.menu();
	return 0;
}
