/*
using stack to balance the parentheses
bool notpair(char c) --> compare c with s.top(), return true if not pair.
*/

#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

stack<char> s;

//check if the paratheses are pair or not
bool notpair(char c){
	if(s.top()== '(' && c == ')'){
		return false;
	}
		
	if(s.top()== '[' && c == ']'){
		return false;
	}
		
	if(s.top()== '{' && c == '}'){
		return false;
	}
		
	else 
		return true;
}

int main(){
	char c[50];
	printf("Enter a string: \n");
	gets(c);

	for(int i = 0; i<strlen(c); i++){
		//pushing into the stack
		if(c[i] == '('|| c[i] == '[' || c[i] == '{'){
			s.push(c[i]);	
		}

		if(c[i] == ')'|| c[i] == ']' || c[i]== '}'){
			printf("%c\n", c[i]);
			//if is empty or not pair
			if(s.empty() || notpair(c[i])){
				printf("Unbalanced!!! %c\n", c[i]);
				return false;
			}else{
				s.pop();
			}
		}
	}
	//if you pop out all the parathesis, then you did it
	if(s.empty())
		printf("You did it, it is balanced!\n");
}