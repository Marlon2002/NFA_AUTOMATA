



#include <iostream>
#include <string.h>


using namespace std;


char curstate[100], nextstate[100];
int state,accept;

// el nfa contiene 3 estados
char q0 = '1', q1 = '2', q2 = '3';

// inserta el estado inicial en el array del estado actual


void state0(char), state1(char), state2(char);
void copyToCurrent(), popCurrent();
	
// define los siguientes estados desde el actual
// el valor de state0 siempre se encuentra en el índice 0,1
void state0(char a){
	if(a == '0'){
		
		nextstate[0] = q0;
		nextstate[1] = q1;
	}
	else{
		
		nextstate[0] = q0;
	}
}

// determina el siguiente estado a partir de la entrada actual
void state1(char a){
	if(a == '1'){
		//hace un push al siguiente estado
		nextstate[2] = q2;
	}
	else{
			
	}
}

// determina el siguiente estado a partir de la entrada actual
void state2(char a){
	if(a == '0'){
		//hace un push al siguiente estado
		nextstate[2] = '0';
	}
	else{
		
		nextstate[2] = '0';
	}
}


void copyToCurrent(){
	for(int i = 0; i< 100; i++){
		curstate[i] = nextstate[i];
	}
}

void popCurrent(){
	for(int i = 0; i< 100; i++){
		curstate[i] = '0';
	}
}


int acceptInput(char inputString[]){
	
 
	int len = strlen(inputString);

	for (int i = 0; i < len; i++) {
		// recorre el estado actual y determinar el siguiente estado
		for (int j =0; j<100; j++){
			
			//si curstate contiene estado empuja su nextstae a la lista nextstate
			if(curstate[j] == q0){
				state0(inputString[i]);
			}
			
			if(curstate[j] == q1){
				state1(inputString[i]);
			}
			
			if(curstate[j] == q2){
				state2(inputString[i]);
			}
		}
		
		// limpia el array actual
		popCurrent();
		
		// copia los siguientes estados al array del estado actual
		copyToCurrent();
	}
	
	//salida de los posibles estados finales del array
	cout<<endl<<"Posible estado final: [";
	for (int i = 0; i <3; i++) {
		cout<<curstate[i];
		if(i != 2){
			cout<<",";
		}
	}
	cout<<"]"<<endl<<endl;;
	
	//verifica si el estado final está en el array de estados finales posibles
	for (int n = 0; n < 100; n++) {
			if(curstate[n] == q2){
				accept = 1;
			}
	}
}



int main(){
	char fn;
	char input[fn];
	cout<<"Ingresa cadena a analizar ";
	cin >> input;
	curstate[0] = q0;
	
	cout<<"Este NFA Acepta una cadena que termine en '01'"<<endl;
	cout<<endl<<"Lista de estados"<<endl;
	cout<<"q0 == 1"<<endl<<"q1 == 2"<<endl<<"q2 == 3"<<endl<<"estado muerto == 0"<<endl;
	
	cout<<endl<<"Cadena Ingresada  "<<input<<endl;
	acceptInput(input);
	
	if(accept == 1){
		cout<<"Cadena aceptada";
	}
	else{
		cout<<"Cadena rechazada";
	}
	return 0;
}

