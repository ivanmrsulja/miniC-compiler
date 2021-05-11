//OPIS: para statement
//RETURN: 57

int main(){
	int a, i, j;
	int b = 0;
	para (a = 0 en 2){
		para(i = 0 en 2){
			para(j = 0 en 2){
				b++;
			}
			para(j = 0 en 2){
				b++;
			}
		}
	}
	
	para(j = 0 en 2){
		b = b + j;
	}
	return b;
}
