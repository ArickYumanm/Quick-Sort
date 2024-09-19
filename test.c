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

  for (int p = 0; p < 2; p++)
  {
    head = A[x];
    printf("checking ****************************************************************************************\n");
    for (int o = 0; o < as; o++)
    {
      printf("Looping ====================== \n");
      printf("Value of Head = %d\n", head);
      printf("Index of head = %d\n", x);
      printf("----------------------------HEAD + 1  = %d\n", x);

      for (int i = x + 1; i < as; i++) // checking for A
      {
        printf("Finding A \n");
        printf("value of A = %d\n", A[i]);
        printf("Index of A = %d\n", i);
        printf("flagA of A = %d\n", flagA);

        if (A[i] > head) // if a > x
        {
          indexA = i; // index of "a"
          flagA = 1;
          valA = A[i];
          printf("A = %d\n", A[i]);
          printf("Index of A = %d\n", i);
          printf("flagA = True\n");
          break;
        }
      }

      if (flagA == 0) // if a < x (if X is the biggest no. in the array) X meaning the head
      {
        printf("Running FlagA swapping the head and the last value\n");
        swap = A[b];
        printf("b value = %d\n", b);
        printf("The last value = %d\n", A[b]);
        A[b] = A[x];
        A[x] = swap;
        printf("The First value = %d\n", A[x]);
        newIndex = x;
        newHead = A[x];
        printf("The  = %d\n", x);
        printf("Swapped 000000000000000000000000000000000000000000000000000000000000000\n");
        break;
      }
      for (int i = b; i > x; i--) // checking for B
      {
        printf("value of Head = %d\n", head);
        printf("Finding B \n");
        printf("value of B = %d\n", A[i]);
        printf("Index of B = %d\n", i);
        printf("Value of a === %d\n", a);
        if (A[i] < head) // if b < x
        {
          indexB = i; // index of "b"
          flagB = 1;
          valB = A[i];
          printf("B = %d\n", A[i]);
          printf("Index of B = %d\n", i);
          printf("flagB = True\n");
          break;
        }
      }

      if (flagB == 0) // if b > x (if x is the smallest value in the array)
      {
        printf("Running FlagB \n");
        printf("Value of X = %d\n", x);
        newIndex = x + 1;
        newHead = A[newIndex];
        printf("New Head = %d\n", newHead);
        printf("This is the NewIndex = %d\n", newIndex);
      }

      if (flagA == 1 && flagB == 1 && indexB < indexA) // swapping the value of x and b after they Cross a and b
      {
        printf("Swapping X and B \n");
        swap = A[x];
        printf("Head before switch = %d\n", A[x]);
        A[x] = A[indexB];
        printf("Head after switch = %d\n", A[x]);
        printf("A[b] before = %d\n", A[b]);
        A[indexB] = swap;
        printf("A[b] after = %d\n", A[b]);
        newIndex = x;
        newHead = A[x];
        printf("New index of X = %d\n", newIndex);
        printf("New Head = %d\n", newHead);
        // break;
      }
      else if (flagA == 1 && flagB == 1 && indexB > indexA) // the normal A and B swap
      {
        printf("Swapping A and B \n");
        // if a and b reqd value is found swap the value of a and b
        swap = A[indexB];
        A[indexB] = A[indexA];
        A[indexA] = swap;
        printf("New value A = %d\n", A[indexA]);
        printf("New value B = %d\n", A[indexB]);
        printf("New Index value A = %d\n", indexA);
        printf("New Index value B = %d\n", indexB);
        newHead = A[x];
        newIndex = x;
      }
      flagA = 0;
      flagB = 0;

      printf("This is after break ++++++++++ \n");
      printf("The array after : \n");
      for (int y = 0; y < as; y++)
      {
        printf(" %d ", A[y]);
      }
      printf("\n");
      head = newHead;
      x = newIndex;
    }

    printf("The array after : \n");
    for (int y = 0; y < as; y++)
    {
      printf(" %d ", A[y]);
    }
    printf("\n");
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
      printf("Sorted successfully \n");
      break;
    }
    else if (Qs == 0)
    {
      printf("Not Sorted yet \n");
      x = 0;
      head = A[x];
    }
    head = newHead;
    x = newIndex;
    printf("Value of final X = %d\n", x);
    printf("Value of final head = %d\n", head);
  }

  printf("The array after : \n");
  for (int y = 0; y < as; y++)
  {
    printf(" %d ", A[y]);
  }
  printf("\n");

  return 0;
}
