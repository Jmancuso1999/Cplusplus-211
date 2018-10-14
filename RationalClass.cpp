// Rat class i.e. a class for rational numbers

#include <iostream>

using namespace std;

class Rat{

 private:
    int n; 
    int d;
 public:
     // constructors

 // default constructor 
 Rat(){
	n=0; 
	d=1; 
	}

 // 2 parameter constructor
 Rat(int i, int j){ 
	n=i; 
    d=j; 
  } 

 // conversion constructor 

 Rat(int i){
    n=i;
    d=1; 
 }
 //accessor functions (usually called get() and set(...) ) 
 int getN(){ return n;} 
 int getD(){ return d;} 
 
 void setN(int i){ n=i;} 
 void setD(int i){ d=i;}
 

//arithmetic operators 
 //adding operator

 Rat operator+(Rat r){	
   Rat t;	
   t.n=n*r.d+d*r.n; //CROSS-MULTIPLYING 	
   t.d=d*r.d;	
   simplify(t);	
   improperFraction(t);	

   return t; 
 }  

 //subtracting operator 

 Rat operator-(Rat r){	
    Rat t;	
    t.n=(n*r.d)-(r.n*d); //Multiply by the opposite denominators	
    t.d=d*r.d;	//multiply denominators to get a like term

    simplify(t);	
    improperFraction(t);	

    return t; 
 } 

//MULTIPLYING OPERATOR 	
 Rat operator*(Rat r){	
    Rat t;
    t.n=n*r.n;	
    t.d=d*r.d;	 
    simplify(t);	
    improperFraction(t);	
    return t;	
 } 

 //Division OPERATOR - Works

 Rat operator/(Rat r){	
    Rat t;	
    t.n= n*r.d; //Flip's the fractions to multiply	
    t.d= d*r.n;	
    simplify(t);	
    improperFraction(t);	

    return t;	
 }

 // 2 overloaded i/o operators 
   friend ostream& operator<<(ostream& os, Rat r); 
   friend istream& operator>>(istream& is, Rat& r); 
   int gcd(int a, int b) { 
      if(b == 0) {	 
        return a; 
      } 
      else { 
        return gcd(b, a % b); //a % b checks if it is  
       } 
 } 

 void simplify(Rat &r) {
  //pass by reference because we want r to be changed.   
   int x = r.gcd(r.getN(), r.getD()); //gets the greatest common factor
   r.n = r.n / x; //once gcd is solved for, we can simplify both the numeirator and denominators   
   r.d = r.d / x;   
 } 

 void improperFraction(Rat &r) {   
   if (r.n > r.d) {       
      cout << r.n / r.d << " ";     
       r.n = r.n % r.d;   
   } 
 }
}; //end OF RAT CLASS****

// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.

ostream& operator<<(ostream& os, Rat r){	
    os<<r.n<<" / "<<r.d<<endl;
	return os;
} 

// operator>>() is NOT a member function but since it was declared a friend of Rat

// it has access to its provate parts.

istream& operator>>(istream& is, Rat& r){
    is>>r.n>>r.d; 
    return is;
}



int main(){ 
	Rat x(9,4), y(2,5), z;
	
	z=x+y;	
	cout<<z; 
	
	x.setN(3); 	
	y.setD(2);
	
	z=x*y; 
	
	cout<<z;
	
	cout << "Enter 2 values for Rat X: ";	
	cin>>; 
	cout<<x; 

	z= x+5; 
	cout<<z; 
	system("pause"); 

return 0;

}
