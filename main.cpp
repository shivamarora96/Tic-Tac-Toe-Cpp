#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<cstring>

using namespace std;


class ij{
public:
int i ;
int j;
ij(int ii = 0 , int jj = 0):i{ii} , j{jj}{}
ij(const ij &obj){
this->i = obj.i;
this->j = obj.j;
}

~ij()
{}

};


//------------------------------------------------------------------

//Show Screen ................
void ShowArray(char a[3][3] ){


for(int i = 0 ;  i< 3 ; i++){
    cout<<"                                           ";
    for(int j = 0 ;j < 3 ;j++){
        cout<<"|____"<<a[i][j]<<"____|";

    }
    cout<<endl<<endl<<endl;
}
return ;
}
//-------------------------------------------------------------------------
//array[map
//array screen

ij Position(int pos ){
ij b[10] ;

b[   1   ].i =      0    ;
b[   1   ].j =     0     ;


b[   2   ].i =      0    ;
b[   2   ].j =      1    ;

b[   3   ].i =        0  ;
b[   3   ].j =       2   ;

b[   4   ].i =        1  ;
b[   4   ].j =      0    ;

b[   5   ].i =     1     ;
b[   5   ].j =     1    ;

b[   6  ].i =         1 ;
b[   6   ].j =      2    ;

b[   7   ].i =       2   ;
b[   7   ].j =         0 ;

b[   8   ].i =    2      ;
b[   8   ].j =         1 ;

b[9].i = 2;
b[9].j = 2;






ij obj2 = b[pos ];
return obj2;
}
//---------------------------------------------------------------------------

int updatescreen(ij obj , int turn , char  a[3][3]  ){


int i = obj.i;
int j = obj.j;
int altturn= 0;

if(turn == 1 ){

    if(a[i][j]!='O' && a[i][j]!='X'){
        a[i][j] = 'O';
        altturn = 2;
        }
    else{
        cout<<endl<<"Invalid Move !! "<<endl;
        altturn = 1;
        getch();

        }
}


else if(turn == 2){

        if(a[i][j]!='O' && a[i][j]!='X'){
        a[i][j] = 'X';
        altturn = 1;
        }

        else{
        cout<<endl<<"Invalid Move !! "<<endl;
        getch();
        altturn=2;
        }

    }

    turn = altturn;
return turn;


}


//-------------------------------------------------------------------------------
int  check(char a[3][3] )
{
    /*
    0 =  draw
    1= palyer1 wins
    2=player2 wins
    */
    for(int  k = 0 ; k<3 ; k++ ){
        if(a[k][0] == a[k][1]  && a[k][1] == a[k][2])
            {

                if(a[k][0] == 'X')
                    return 2;
                else if(a[k][0] == 'O')
                    return 1;
            }

        else if(a[0][k] == a[1][k]  && a[1][k] == a[2][k])
            {

                if(a[0][k] == 'X')
                    return 2;
                else if(a[0][k] == 'O')
                    return 1;
            }

        else if( a[0][0] == a[1][1]  && a[1][1] == a[2][2])
            {

                if(a[0][0] == 'X')
                    return 2;
                else if(a[0][0] == 'O')
                    return 1;
        }

        else if(a[1][1] == a[0][2]  && a[1][1] == a[2][0])
            {

                if(a[2][0] == 'X')
                    return 2;
                else if(a[2][0] == 'O')
                    return 1;

            }

    }

    for(int i = 0 ; i< 3  ; i++){
        for(int j = 0 ;j <3 ;j++){
            if(a[i][j]!='X' && a[i][j]!='O')
                return 10;
        }
    }

 return 0 ;


}

//------------------------------------------------------------------------------


int main()

{

    bool p = 1;
while(p){



    char a[3][3] ;
    a[0][0] = '1'  ;
    a[0][1] =  '2' ;
    a[0][2] = '3'  ;
    a[1][0] =  '4' ;
    a[1][1] =  '5' ;
    a[1][2] =  '6' ;
    a[2][0] =  '7' ;
    a[2][1] = '8'  ;
    a[2][2] =  '9' ;




cout<<"     ________ _________ ________ ____________ ______TIC  TAC  TOE ______ _________ _______ ______ ________ ______   "<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"Enter Names --:: ";
string x , y ;
cout<<endl<<endl<<"First Player == ";
cin>>x;
cout<<endl<<endl<<"Second Player == ";
cin>>y;
system("cls");
cout<<"     ________ _________ ________ ____________ ______TIC  TAC  TOE ______ _________ _______ ______ ________ ______   "<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

cout<<endl<<endl<<"Welcome To Tic Tac TOe  ======>>>>> Enjoy :) :)          "<<x <<"    VS     "<<y<<endl<<endl;
//delay(5000);
system("cls");

cout<<"       _________ ________ ____________ ______TIC  TAC  TOE(  "<<x<<"  vs  "<<y <<"  )   __ _______ ______ ________ ______   "<<endl<<endl<<endl<<endl<<endl<<endl<<endl;


ShowArray( a );
cout<<endl<<endl;

int checker = 3;
int player = 1;
int pos=0;
//int alternateplayer=0;

while( checker<0 || checker>2 ){

if(player == 1)

   {
    cout<<x<<" 's Turn  !! "<<endl;
    cout<<"Enter value == ";
    cin>>pos;
    //alternateplayer = 2;
   }

else if (player == 2)

   {
    cout<<y<<" 's Turn  !! "<<endl;
    cout<<"Enter value == ";
    cin>>pos;
    //alternateplayer=1;
   }

ij obj(0,0) ;
obj =  Position(pos);

int alternateplayer = updatescreen(obj , player ,  a);
system("cls");
cout<<"       _________ ________ ____________ ______TIC  TAC  TOE(  "<<x<<"  vs  "<<y <<"  )   __ _______ ______ ________ ______   "<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

cout<<endl<<endl<<endl<<endl<<endl<<endl;
ShowArray(a);
player=alternateplayer;
checker = check(a);

}

getch();
system("cls");

if(checker == 1)
{
    cout<<"       _________ ________ ____________ ______TIC  TAC  TOE(  "<<x<<"  vs  "<<y <<"  )   __ _______ ______ ________ ______   "<<endl<<endl<<endl<<endl<<endl<<endl<<endl;


    cout<<x<< "  Wins The Game"<<endl<<endl;
    cout<<"Better Luck Next Time "<< y <<endl;
}

else if(checker == 2)
{
    cout<<"       _________ ________ ____________ ______TIC  TAC  TOE(  "<<x<<"  vs  "<<y <<"  )   __ _______ ______ ________ ______   "<<endl<<endl<<endl<<endl<<endl<<endl<<endl;


    cout<<y<< "  Wins The Game"<<endl<<endl;
    cout<<"Better Luck Next Time "<< x <<endl;
}
else if(checker == 0)
{
    cout<<"       _________ ________ ____________ ______TIC  TAC  TOE(  "<<x<<"  vs  "<<y <<"  )   __ _______ ______ ________ ______   "<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<  " Match Tied !! "<<endl<<endl;

}

getch();

system("cls");
cout<<"Do you Wish To Countinue????????Have You Enjoyedit !! :) :) "<<endl;
cout<<endl<<endl<<endl<<" < Y  /  N > "<<endl;
char con;
cin>>con ;

if(con=='y'||con=='Y')
    continue;

else break;


}

return 0;
  }
