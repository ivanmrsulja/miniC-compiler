int main(){
    int x;
    int y;

    x = 2;
    y = 3;

    {
        int x;
        x = 5;
        y = x + y;
        {
            int x;
            x = 1;
            {
                unsigned z;
                z = 5u;
            }
        }
    }
    return x + y;
}