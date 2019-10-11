/*
	Programming Assignment No. 1
	author: Sujeet Hiremath
	Polynomials
*/

#include <iostream>
#include <sstream>  // for istringstream
#include <vector>
#include <string>
#include "ArrayPolynomial.h"

 
using namespace std;


vector<string> split( const string& s , char delimiter )
    {
        vector<string> tokens;          // vector of tokens
        string token;                   // a single token
        istringstream tokenStream(s);   // an input string stream

        // Tokenize s by grabbing individual tokens
        while( getline( tokenStream , token , delimiter ) )
            tokens.push_back(token);    // add found token

        return tokens;
    }
 
int main()
{
    string input;
    unsigned flag=1; //flags for keeping track of getline inputs
    //unsigned count=0;                 // input string to hold 1 line from cin
    char   delimiter = ' ';       // what separates tokens in the input string
    vector<string> listOfTokens;
      // store tokens of input here
 
   // Read in a string as a line of text from standard input.
 
    ArrayPolynomial AP;
    while( getline( cin , input ) ) {
 
        // Use the split() function above to extract tokens
        listOfTokens = split( input , delimiter );        
        
        if(flag==1)
        {                       
           vector<double> inputData;   //holds input of coefficient      
           for(auto tokens:listOfTokens)
           inputData.push_back(stod(tokens));
           unsigned k=0;  
           for(int i=inputData.size()-1; i!=-1; i-- )
        	{
				AP.addTerm(inputData[i],k);     //inserting into the array coeff[] from arrayPolnomial class
            	k++;
          }
          flag=2;       
        }
        else
        {
          for(unsigned j=0;j<=(listOfTokens.size()-1);j++)
          {
              double values = stod(listOfTokens[j]); //converting values of f(x) from string to double
              if(j<listOfTokens.size()-1)   //to format output spacing
              cout<<AP.evaluate(values)<<" ";  //Evaluating the polynomial and displaying output
              else
              cout<<AP.evaluate(values);
          }
          flag=1;
          AP.clear();
          cout<<endl;     
        }
 
    }
    
    return 0;
 
}