// OPIS: break u otherwise
int main(){
    int a = 6;
    unsigned b = 6u;


    switch(a){
        case 1:
            a = 5;
            break;
        case 5:
            a = 1;
        otherwise:
            a = 17;
            break;
    }

}
