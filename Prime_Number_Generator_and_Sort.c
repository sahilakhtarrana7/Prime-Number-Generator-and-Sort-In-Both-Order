#include <stdio.h>
#include <stdbool.h>

#define MAX 100000  // Maximum possible range for prime generation

// Function to generate prime numbers using the Sieve of Eratosthenes
int generatePrimes(int limit, int primes[]) {
    bool isPrime[MAX];
    int i, j, count = 0;

    for (i = 0; i <= limit; i++)
        isPrime[i] = true;

    isPrime[0] = false;
    isPrime[1] = false;

    for (i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    for (i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes[count++] = i;
        }
    }

    return count; // Return total number of primes found
}

// Function to sort array in ascending order
void sortAscending(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to sort array in descending order
void sortDescending(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int limit, count, i;
    int primes[MAX];

    printf("=== PRIME NUMBER GENERATOR AND SORT IN BOTH ORDER ===\\n");
    printf("Enter the upper limit: ");
    scanf("%d", &limit);

    if (limit < 2) {
        printf("No prime numbers below 2.\\n");
        return 0;
    }

    count = generatePrimes(limit, primes);

    printf("\\nPrime numbers up to %d:\\n", limit);
    for (i = 0; i < count; i++)
        printf("%d ", primes[i]);

    sortAscending(primes, count);
    printf("\\n\\nPrimes in Ascending Order:\\n");
    for (i = 0; i < count; i++)
        printf("%d ", primes[i]);

    sortDescending(primes, count);
    printf("\\n\\nPrimes in Descending Order:\\n");
    for (i = 0; i < count; i++)
        printf("%d ", primes[i]);

    printf("\\n\\nTotal Prime Numbers Found: %d\\n", count);

    return 0;
}
