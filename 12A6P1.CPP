#include"jihadijohn.h"
class outfit
{
  private:
  char ocode[25];
  char otype[25];
  char ofabric[25];
  int osize;
  float oprice;
  void initprice()
  {
    if(strcmp(strupr(ofabric),"DENIM")==0)
    {
       if(strcmp(strupr(otype),"TROUSER")==0)
       {
	 oprice=1500;
       }
       if(strcmp(strupr(otype),"JACKET")==0)
       {
	 oprice=2500;
       }
    }
    else
    {
       if(strcmp(strupr(otype),"TROUSER")==0)
       {
	 oprice=1500*0.75;
       }
       if(strcmp(strupr(otype),"JACKET")==0)
       {
	 oprice=2500*0.75;
       }
    }
  }
  public:
  outfit()
  {
    cout<<"\nDEFAULT CONSTUCTOR RUNNING";
    strcpy(ocode,"NOT INITIALIZED");
    strcpy(otype,"NOT INITIALIZED");
    osize=0;
    strcpy(ofabric,"NOT INITIALIZED");
    oprice=0;
  }
  void getdata()
  {
    cout<<"\n\aENTER THE CLOTH CODE=";
    gets(ocode);
    cout<<"\n\aENTER THE CLOTH TYPE=";
    gets(otype);
    cout<<"\n\aENTER THE CLOTH SIZE=";
    cin>>osize;
    cout<<"\n\aENTER THE CLOTH FABRIC=";
    gets(ofabric);
  }
  void putdata()
  {
    cout<<"\n\aTHE CLOTH CODE="<<ocode;
    cout<<"\n\aTHE CLOTH TYPE="<<otype;
    cout<<"\n\aTHE CLOTH SIZE="<<osize;
    cout<<"\n\aTHE CLOTH FABRIC="<<ofabric;
    initprice();
    cout<<"\n\aTHE CLOTH PRICE="<<oprice;
  }
  ~outfit()
  {
    cout<<"\nOBJECT DESTROYED";
  }
};
void main()
{
   clrscr();
   outfit c;
   c.getdata();
   c.putdata();
   getch();
}