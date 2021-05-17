//OPIS: while statement
//RETURN: 21

unsigned j;

int main(){
    int i = 0;
    j = 0u;
    while (i < 10){
        i = i + 1;
        while (j < 10u){
            i = i + 1;
            j++;
        }
        j = 0u;
        while (j < 10u){
            i = i + 1;
            j++;
        }
    }
    return i;
}