int foo(int a) {
    a = a + 20;
    return a;
}

int main() {
    int i;
    i = 0;
    {
        int j;
        j = 10;
        i = i + foo(i);
        i = j;
    }

    return i;
}
