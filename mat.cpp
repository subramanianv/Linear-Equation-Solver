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
#define STEP 0.001
#define EPS 1.0e-20
Matrix gradient(Matrix A,Matrix x,Matrix b)
{
    Matrix t = A * x - b;
//    cout<<t;
    return t;
}
double function_val(Matrix A,Matrix x , Matrix b)
{
     Matrix c = 0.5 * x.transpose() * A * x - b.transpose() * x;
//    cout << c[0][0] ;
    return c[0][0];
}
double step(Matrix A,Matrix x,Matrix b,Matrix g)
{
   
     double alpha=1.0;
     double beta = 0.5;
     double c1 = 1e-4;
     double func_val = function_val(A,x,b);
     double func_l = function_val(A,x-alpha*g,b);
     Matrix gt =(g.transpose()*g); 
     double dx = gt[0][0];
//     abort();
    while(func_l > func_val - c1 * alpha * dx)
    {
       alpha = alpha * beta;
       func_l = function_val(A,x-alpha*g,b);
       cout<<"Loopingd";
    }       
   return alpha;
}

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
   if(A.determinant()==0)
   {
     cout<<"No Solution"<<endl;
     return 1;
  }
    Matrix s=gradient(A,x,b);
    double norm =s.norm();  
    cout<<"Calculating";
  //  double step_size = step (A,x,b,s);    
    while( norm  > EPS)
   {
        
     x = x - STEP * s;
     s = gradient(A,x,b);
  //   step_size = step(A,x,b,s);
     norm = s.norm();
     
  }
  cout<<endl<<"Solution";
  cout << x ; 
  return 0; 
}
