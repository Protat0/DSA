// This code identifies the difference between pass by copy and pass by address


// an example of pass by copy function
void exchangeCPY(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

// an example of pass by address function
void exchangeADD(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int A = 5;
    int B = 10;

    printf("The value of A: %d", A);
    printf("\nThe value of B: %d", B);

    exchangeCPY(A, B);
    // exchangeADD(&A, &B);

    printf("\n\nThe new value of A: %d", A);
    printf("\nThe new value of B: %d", B);
}