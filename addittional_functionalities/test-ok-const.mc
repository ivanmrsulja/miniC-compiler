//OPIS: Konstante
//RETURN: 110

int f(int x, int broj) {
  int z = 0;
  return x + z;
} 

int y() {
  return 2147483647; //max int
}

int main() {
  int a;
  unsigned b = 1u;
  a = 0;

  if (a < -10)
    a = f(a + 3, 1);
  else
    a = y();
  a = -556;

  return a + 666;   //110
}

unsigned z() {
  unsigned b;
  b = 16u;
  if (b < 10u)
    b = 3u;
  return b + 4u;
}

