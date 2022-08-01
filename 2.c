#include <Windows.h>
#include<stdio.h>

int main()
{
 HANDLE hMutex = CreateMutex(NULL, TRUE, "MutexExample");

 if (hMutex == NULL) {
 printf("Error creating mutex.\n");
 exit(EXIT_FAILURE);
 }

 if (GetLastError() == ERROR_ALREADY_EXISTS) {
 //the mutex already is in existence
 printf("The mutex alread exists.\n");
 exit(EXIT_FAILURE);
 }
 else {
 printf("Mutex created.\n");
 printf("...releasing mutex.\n");
 //release ownership of the mutex
 ReleaseMutex(hMutex);
 }

 //close mutex handle
 CloseHandle(hMutex);

 return 0;
}
