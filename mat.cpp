//
//  mat.cpp
//  
//
//  Created by Subramanian Venkatesan on 22/02/13.
//  Copyright (c) 2013 SRv. All rights reserved.
//

#include <iostream>
#include "matrix.h"
#include <cfloat>
#include <math.h>
#define STEP_SIZE 0.0001
#define EPS 1.0e-20
Matrix gradient(Matrix A,Matrix x,Matrix b)
{
    Matrix t = A * x - b;
//    cout<<t;
    return t;
}
double function_val(Matrix A,Matrix x , Matrix b)
{
     Matrix c = 0.5 * x.transpose() * A * x - b * x;
    cout << c[0][0] ;
    return c[0][0];
}
/*bool is_same(Matrix x , Matrix  y)
{
   for(int i=0;i<x.getDimensions().first;i++)
   {
      for(int j=0;j<x.getDimesions().second; j++)
     {
       	
                   if(abs(x[i][j] - y[i][j]) > EPS) return false;
	}      
     return true;
   }
}*/
int main()
{
    int n;
    cout<<"Enter number of unknowns:";
    cin>>n;
    cout<<n; 
    Matrix A(n,n),b(n,1);
    Matrix x(n,1);
    cout<<"EQUATION : AX = B "<<endl<<"Enter Matrix A:"<<endl;
    cout<<"Enter the Matrix (a11,a12,...)"<<endl;
    for(int i=0;i<n;i++)
    {
         for(int j=0;j<n;j++)
         {
            double p;
            cout<<"Enter A["<<i+1<<","<<j+1<<"]:";
            cin>>p;
            A[i][j]=p;
         }
    }
    cout<<"Enter B Matrix"<<endl;
    for(int i=0;i<n;i++)
    {
       double v;
       
      cout<<"Enter B["<<i<<","<<"0]:";
      cin>>v;
      b[i][0] = v;
      x[i][0] = 0;
        
    }
    double old_norm = DBL_MAX;
    Matrix s=gradient(A,x,b);
    double new_norm =s.norm();  
   cout<<"Calculating";
  while( (old_norm - new_norm)  > EPS)
  {
       
     old_norm = new_norm; 
     x = x - STEP_SIZE*s;
     s = gradient(A,x,b);
     new_norm = s.norm(); 
  }
  cout<<endl<<"Solution";
  cout << x ; 
   
}