// FCI - programming 1 - 2018 - assignment 2.
// program name : Xor Chiper.cpp.
// last modification 1/2/2018.
// Author 1 and ID and group: Nehal Akram Ahmed 20170318 12.
// Teaching assistant : khadeaga khaled and dina mahmoud.
// purpose : to cipher and decipher a message.

#include <iostream>
#include<algorithm>
#include <cmath>

using namespace std;


int String_TO_Integer( string x ){
    int num = 0 ;
    string z = "0123456789";
    int len = x.length();
    int pw = len-1;
    for ( int i = 0; i < len; i++ ){
        for ( int j = 0; j < 10; j++ ){
            if ( x[i] == z[j] ){
                num += j * pow(10,pw);
                pw--;
                break;
            }
        }
    }
    return num;
}


int Hex_to_Decimal( string x ){
    string two_char = "";
    int num = 0, sum = 0;
    int counter = 0;
    for ( int i = x.length()-1; i > -1; i-- ){
        if ( (int)x[i] >= 48 && (int)x[i] <= 57 ){ // from 0 to 9
            two_char = "";
            two_char += x[i];
            num = String_TO_Integer( two_char );
        }
        else{
            if ( x[i] == 'a' ){ num = 10; }
            else if ( x[i] == 'b' ){ num = 11; }
            else if ( x[i] == 'c' ){ num = 12; }
            else if ( x[i] == 'd' ){ num = 13; }
            else if ( x[i] == 'e' ){ num = 14; }
            else if ( x[i] == 'f' ){ num = 15; }
        }

        sum += num * pow( 16 , counter );
        counter++;
    }
    return sum;
}

int main()
{
    string sent="" , txt="" , msg="" ;
    int i ,z , decimal;
    char sec_key ;
    int y = 0;

    cout<<"Ahlan ya user ya 7abibi" << endl ;
    cout<<"What do you like to do today" << endl;
    cout<<" 1-cipher a message" <<endl <<" 2-decipher a message"<<endl<<" 3-end: ";
    cin >> z ;
    while(z>3 || z<1)
    {
        cout << "Please choose number 1 , 2 or 3: " ;
        cin >> z;
    }

      if (z==3)
    {
        return 0 ;
    }

    cout << "Enter a secret letter: ";
    cin>> sec_key ;

    cin.ignore();

    if(z==1){
        cout <<"Enter Sentence: " ;

        getline(cin,sent);

        cout << " Message is: " ;

        for (i=0 ; i < sent.length() ; i++)
        {
            y = (int)sent[i] ^ (int)sec_key ;
            sent[i] = (char)y ;

            if ( y <= 15 ) { cout << "0"; }
            cout << hex << y ;
        }
        cout << endl;

        cout << " Message is : " << sent;
    }

    if (z==2)
    {
        cout <<"Enter Ciphered Sentence: " ;

        getline(cin,sent);

        for (i=0 ; i < sent.length() ; i+=2)
        {
            txt="" ;
            txt+=sent[i];
            txt+=sent[i+1];

            decimal= Hex_to_Decimal(txt);
            y = decimal ^ (int)sec_key ;

            msg+= (char)y ;

        }
        cout << msg ;
    }
}
