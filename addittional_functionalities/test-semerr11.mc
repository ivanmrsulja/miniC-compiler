// OPIS: pristupanje van bloka i promenljiva kojoj nije dodeljivana vrednost
int main(){
    int x;
    x = 2;
    {
        int z;
        x = 5;
    }
    return x + z;
}
