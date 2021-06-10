//         simplex method for two variables///////********
// this program is for solving maximization of the function for the inequaliteies
//of the function having only two variables such as;
//              p=2x+3y,
//              2x-5y>=45
//              3x+4y>=32

//ps; the process after not finding the negative element is r3 is not included in this due to insuffient time for coding//
//@copyright kailash pantha
#include<iostream>

using namespace std;

class simplex{


    float x[6]= {};

 public:
    void getdata_ineq()
    {
                for (int j=0;j<6; j++)
            {
                cout<<"enter in x1+x2+s1+s2+p=v"<<endl;
                cin>>x[j];
            }
    }

    void show_ineq(){

         for (int j=0;j<6; j++)
            {
                cout<<x[j]<<"          ";
            }
}


// function for identifying smallest negative element in r3
int smallest()
{
    int small , colum;
    if(x[0]>x[1])
    {small= x[1];
    colum=1;}
    else{
    small = x[0];
    colum=0;}

return colum;
}

int smallest_than_zero()
{
    int small , colum;
    if(x[0]< 0)
    {
    //small= x[1];
    colum=1;}
    else{
    //small = x[0];
    colum=0;}
}

float val(int colum)
{

    float val1 ;
    val1 = x[5]/x[colum];
    return val1;
}

int pivot(float r0 , float r1 )
{ int row;
    if (r0<r1)
    row=0;
    else
    row=1;

    //cout<<"pivoted colum is"<<
return row;
}



int unity (int piv_element)
{   float z=x[piv_element];
    for (int i=0 ; i<6;i++)
    {
    x[i]=x[i]/z ;

    }

   return x[piv_element];
}

float rowoperator(int ro)
{   float rop;
    rop=x[ro];
    return rop;
}
void rowoperation(simplex r1,float rop)

{
    cout<<rop<<"this is operator@@@@@"<<endl;
   for (int i=0; i<6;i++)
        {

        x[i]=x[i]-rop*r1.x[i];
        cout<<x[i]<<"  ";
        }
        cout<< " row opearation success full";

}


int data(int i)
{
    int k;
    k=x[i];
    return k;
}
};





int main()
{

    float pivcol,row1,row2,row,rop,rop2,column;
    class simplex r1,r2,r3,check,calc;
    r1.getdata_ineq();
    cout<<"enter data for second inequility"<<endl;
    r2.getdata_ineq();
    cout<<"enter the value for function for f=x1+x2"<<endl;
    cout<<"in the pattern as -x1-x2+f=0"<<endl;
    r3.getdata_ineq();
    cout<<"the arrays are"<<endl;
    cout<<" x1      x2          s1        s2           p           v"<<endl;
    cout<<"******************************************************************"<<endl;
    r1.show_ineq();
    cout<<" "<<endl;
    cout<<"******************************************************************"<<endl;
    r2.show_ineq();
    cout<<" "<<endl;
    cout<<"******************************************************************"<<endl;
    r3.show_ineq();
    pivcol=r3.smallest();
    cout<<endl<<"small column is"<<pivcol<<endl;
    row1=r1.val(pivcol);
    row2=r2.val(pivcol);
   // cout<<"divided value for row 1 "<<row1<<endl;
   // cout<<"divided value for row 2 "<<row2 <<endl;

    row =check.pivot(row1,row2);
   // cout<<"the pivot row is"<<row<<"the pivoted column is"<<pivcol;
    // making pivoted element 1


    if (row==0 && pivcol==0)
    {
    r1.unity(0);
    // for performing row operaton
    rop=r2.rowoperator(0);//gets rop i.e. row operator
    //cout<<rop;
   r2.rowoperation( r1, rop);
   rop2=r3.rowoperator(0);
   r3.rowoperation(r1,rop2);
    }
    if (row==0 && pivcol==1)
    {
    r1.unity(1);
    rop=r2.rowoperator(1);
    r2.rowoperation(r1,rop);
    rop2=r3.rowoperator(1);
    r3.rowoperation(r1,rop2);

    }
    if (row==1 && pivcol==0)
    {
    r2.unity(0);
    rop=r1.rowoperator(0);
    r1.rowoperation(r2,rop);
    rop2=r3.rowoperator(0);
    r3.rowoperation(r2,rop2);
    }
    if (row==1 && pivcol==1)
    {r2.unity(1);
    rop=r1.rowoperator(1);
    r1.rowoperation(r2,rop);
    rop2=r3.rowoperator(1);
    r3.rowoperation(r2,rop2);
    }


    cout<<"the arrays are"<<endl;
    cout<<" x1      x2          s1        s2           p           v"<<endl;
    cout<<"******************************************************************"<<endl;
    r1.show_ineq();
    cout<<" "<<endl;
    cout<<"******************************************************************"<<endl;
    r2.show_ineq();
    cout<<" "<<endl;
    cout<<"******************************************************************"<<endl;
    r3.show_ineq();


    //######################################################################################################################
cout<<"##########################################################################################################################"<<endl;
 column=r3.data(0);
 if (column == 0)
 {cout<<"we are ready for next operation";
    row1=r1.val(1);
    row2=r2.val(1);
   // cout<<"divided value for row 1 "<<row1<<endl;
   // cout<<"divided value for row 2 "<<row2 <<endl;
    pivcol=1;
    row =check.pivot(row1,row2);
   // cout<<"the pivot row is"<<row<<"the pivoted column is"<<pivcol;
    //row =0 and col =1

    if (row==0 && pivcol==1)
    {
    r1.unity(1);
    rop=r2.rowoperator(1);
    r2.rowoperation(r1,rop);
    rop2=r3.rowoperator(1);
    r3.rowoperation(r1,rop2);
    }

//row =1 column = 1
    if (row==1 && pivcol==1)
    {r2.unity(1);
    rop=r1.rowoperator(1);
    r1.rowoperation(r2,rop);
    rop2=r3.rowoperator(1);
    r3.rowoperation(r2,rop2);
    }



    cout<<"the arrays are"<<endl;
    cout<<" x1      x2          s1        s2           p           v"<<endl;
    cout<<"******************************************************************"<<endl;
    r1.show_ineq();
    cout<<" "<<endl;
    cout<<"******************************************************************"<<endl;
    r2.show_ineq();
    cout<<" "<<endl;
    cout<<"******************************************************************"<<endl;
    r3.show_ineq();

 }else
 {cout<<"we are not ready";
    row1=r1.val(0);
    row2=r2.val(0);
   // cout<<"divided value for row 1 "<<row1<<endl;
    //cout<<"divided value for row 2 "<<row2 <<endl;
    pivcol=0;
    row =check.pivot(row1,row2);
   // cout<<"the pivot row is"<<row<<"the pivoted column is"<<pivcol;

if (row==0 && pivcol==0)
    {
    r1.unity(0);
    // for performing row operaton
    rop=r2.rowoperator(0);//gets rop i.e. row operator
    //cout<<rop;
   r2.rowoperation( r1, rop);
   rop2=r3.rowoperator(0);
   r3.rowoperation(r1,rop2);
    }
    if (row==1 && pivcol==0)
    {
    r2.unity(0);
    rop=r1.rowoperator(0);
    r1.rowoperation(r2,rop);
    rop2=r3.rowoperator(0);
    r3.rowoperation(r2,rop2);
    }
    cout<<"the arrays are"<<endl;
    cout<<" x1      x2          s1        s2           p           v"<<endl;
    cout<<"******************************************************************"<<endl;
    r1.show_ineq();
    cout<<" "<<endl;
    cout<<"******************************************************************"<<endl;
    r2.show_ineq();
    cout<<" "<<endl;
    cout<<"******************************************************************"<<endl;
    r3.show_ineq();

    cout<<endl<<"#################"<<endl;
 column=r3.data(5);
 cout<<"Maximum value is "<<column;
     cout<<"#################"<<endl;

 }
}
