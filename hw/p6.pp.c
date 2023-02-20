/*@ requires size >= 0;
  @ requires \valid(a + (0..size-1));
  @ ensures \result == 0;
  @ ensures \forall integer i; 0 <= i < size && \old(a[i]) == x ==> a[i] == y;
  @ ensures \forall integer i; 0 <= i < size && \old(a[i]) != x ==> a[i] == \old(a[i]);
  @ assigns a[0..size-1];
  @ frees a;*/
// */

int replace (int *a, int size, int x, int y) {
    /*@ loop invariant 0 <= i <= size;
      @ loop invariant a == \at(a, Pre) + i;
      @ loop invariant \forall integer j; 0 <= j < i && \at(a[j], Pre) == x ==> \at(a, Pre)[j] == y;
      @ loop invariant \forall integer j; 0 <= j < i && \at(a[j], Pre) != x ==> \at(a, Pre)[j] == \at(a[j], Pre);
      @ loop invariant \forall integer j; i <= j < size ==> \at(a[j], Pre) == \at(a, Pre)[j];
      @ loop assigns \at(a, Pre)[0..i-1];
      @ loop variant size - i;
    */
    for (int i = 0; i < size; i++) {
        if (*a == x) *a = y;
        a++;
    }
    return 0;
}
