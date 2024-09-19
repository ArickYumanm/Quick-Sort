#include <stdio.h>

int main()
{
  int x, a, b, A[] = {5, 4, 3, 2, 1};
  int as = sizeof(A) / sizeof(A[0]);
  x = 0;
  b = as - 1;
  a = x + 1;
  int indexA = a, indexB = b, valA, valB, swap, head, newHead, newIndex, Qs;
  int flagA = 0, flagB = 0;
  printf("The given array  : \n");
  for (int y = 0; y < as; y++)
  {
    printf(" %d ", A[y]);
  }
  printf("\n");

  for (int p = 0; p < 2; p++)
  {
    head = A[x];
    for (int o = 0; o < as; o++)
    {
      for (int i = x + 1; i < as; i++) // checking for A
      {
        if (A[i] > head) // if a > x
        {
          indexA = i; // index of "a"
          flagA = 1;
          valA = A[i];
          break;
        }
      }

      if (flagA == 0) // if a < x (if X is the biggest no. in the array) X meaning the head
      {
        swap = A[b];
        A[b] = A[x];
        A[x] = swap;
        newIndex = x;
        newHead = A[x];
        break;
      }
      for (int i = b; i > x; i--) // checking for B
      {
        if (A[i] < head) // if b < x
        {
          indexB = i; // index of "b"
          flagB = 1;
          valB = A[i];
          break;
        }
      }

      if (flagB == 0) // if b > x (if x is the smallest value in the array)
      {
        newIndex = x + 1;
        newHead = A[newIndex];
      }

      if (flagA == 1 && flagB == 1 && indexB < indexA) // swapping the value of x and b after they Cross a and b
      {
        swap = A[x];
        A[x] = A[indexB];
        A[indexB] = swap;
        newIndex = x;
        newHead = A[x];
        // break;
      }
      else if (flagA == 1 && flagB == 1 && indexB > indexA) // the normal A and B swap
      {
        // if a and b reqd value is found swap the value of a and b
        swap = A[indexB];
        A[indexB] = A[indexA];
        A[indexA] = swap;
        newHead = A[x];
        newIndex = x;
      }
      flagA = 0;
      flagB = 0;
      head = newHead;
      x = newIndex;
    }
    // checking if the array is shorted
    for (int j = 0; j < as; j++)
    {
      for (int k = 0; k < as; k++)
      {
        if (A[j] < A[k])
        {
          Qs = 1;
        }
        else
        {
          Qs = 0;
        }
      }
    }
    if (Qs == 1)
    {
      break;
    }
    else if (Qs == 0)
    {
      x = 0;
      head = A[x];
    }
    head = newHead;
    x = newIndex;
  }

  printf("The final array  : \n");
  for (int y = 0; y < as; y++)
  {
    printf(" %d ", A[y]);
  }
  printf("\n");

  return 0;
}
