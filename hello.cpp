/* ==========================================================
   TOC PRACTICAL PROGRAMS (Turbo C++)
   ========================================================== */


/* ==========================================================
   PRACTICAL 1: DFA - strings containing 111
   ========================================================== */
#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void main()
{
    char Input[100];
    clrscr();

    cout<<"Enter a string to validate (input string should be of 0 and 1)\n";
    gets(Input);

    int i=-1;

A:
    i++;
    if(Input[i]=='0')
        goto A;
    else if(Input[i]=='1')
        goto B;
    else if(Input[i]=='\0')
        goto Invalid;
    else
        goto Wrong;

B:
    i++;
    if(Input[i]=='0')
        goto A;
    else if(Input[i]=='1')
        goto C;
    else if(Input[i]=='\0')
        goto Invalid;
    else
        goto Wrong;

C:
    i++;
    if(Input[i]=='0')
        goto A;
    else if(Input[i]=='1')
        goto D;
    else if(Input[i]=='\0')
        goto Invalid;
    else
        goto Wrong;

D:
    i++;
    if(Input[i]=='0')
        goto D;
    else if(Input[i]=='1')
        goto D;
    else if(Input[i]=='\0')
        goto Valid;
    else
        goto Wrong;

Valid:
    cout<<"\n Output: Valid String";
    goto exit;

Invalid:
    cout<<"\n Output: Invalid String";
    goto exit;

Wrong:
    cout<<"\n Please enter binary string {format of 0, 1}";

exit:
    getch();
}


/* ==========================================================
   PRACTICAL 2: DFA - binary numbers divisible by 3
   ========================================================== */
#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void main()
{
    char Input[100];
    clrscr();

    cout<<"Enter a string to validate (input string should be of 0 and 1)\n";
    gets(Input);

    int i=-1;

q:
    i++;
    if(Input[i]=='0')
        goto q0;
    else if(Input[i]=='1')
        goto q1;
    else if(Input[i]=='\0')
        goto Invalid;
    else
        goto Wrong;

q0:
    i++;
    if(Input[i]=='0')
        goto q0;
    else if(Input[i]=='1')
        goto q1;
    else if(Input[i]=='\0')
        goto Valid;
    else
        goto Wrong;

q1:
    i++;
    if(Input[i]=='0')
        goto q2;
    else if(Input[i]=='1')
        goto q0;
    else if(Input[i]=='\0')
        goto Invalid;
    else
        goto Wrong;

q2:
    i++;
    if(Input[i]=='0')
        goto q1;
    else if(Input[i]=='1')
        goto q2;
    else if(Input[i]=='\0')
        goto Invalid;
    else
        goto Wrong;

Valid:
    cout<<"\n Output: Valid String";
    goto exit;

Invalid:
    cout<<"\n Output: Invalid String";
    goto exit;

Wrong:
    cout<<"\n Please enter binary string {format of 0, 1}";

exit:
    getch();
}


/* ==========================================================
   PRACTICAL 3: DFA - strings of form C followed only by A and B
   ========================================================== */
#include<iostream.h>
#include<string.h>
#include<conio.h>

void DFA(char *str, int N)
{
    if(N <= 1)
    {
        cout<<"No";
        return;
    }

    int count = 0;

    if(str[0] == 'C')
    {
        count++;

        for(int i = 1; i < N; i++)
        {
            if(str[i] == 'A' || str[i] == 'B')
                count++;
            else
                break;
        }
    }
    else
    {
        cout<<"No";
        return;
    }

    if(count == N)
        cout<<"Yes";
    else
        cout<<"No";
}

void main()
{
    char *str = "CBA";
    int N = strlen(str);

    clrscr();
    DFA(str, N);
    getch();
}


/* ==========================================================
   PRACTICAL 4: DFA - binary string with states q0, q2, q1q3, q4, qt
   ========================================================== */
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main()
{
    char Input[100];
    clrscr();

    cout << "Enter a regular expression\n";
    gets(Input);

    int i = -1;

q0:
    i++;

    if (Input[i] == '0')
    {
        goto q2;
    }
    else if (Input[i] == '1')
    {
        goto q1q3;
    }
    else if (Input[i] == '\0')
    {
        goto Invalid;
    }
    else
    {
        goto Wrong;
    }

q2:
    i++;

    if (Input[i] == '0')
    {
        goto q2;
    }
    else if (Input[i] == '1')
    {
        goto q4;
    }
    else if (Input[i] == '\0')
    {
        goto Invalid;
    }
    else
    {
        goto Wrong;
    }

q1q3:
    i++;

    if (Input[i] == '0')
    {
        goto q4;
    }
    else if (Input[i] == '1')
    {
        goto q2;
    }
    else if (Input[i] == '\0')
    {
        goto Invalid;
    }
    else
    {
        goto Wrong;
    }

q4:
    i++;

    if (Input[i] == '0')
    {
        goto qt;
    }
    else if (Input[i] == '1')
    {
        goto qt;
    }
    else if (Input[i] == '\0')
    {
        goto Valid;
    }
    else
    {
        goto Wrong;
    }

qt:
    i++;

    if (Input[i] == '0')
    {
        goto qt;
    }
    else if (Input[i] == '1')
    {
        goto qt;
    }
    else if (Input[i] == '\0')
    {
        goto Valid;
    }
    else
    {
        goto Wrong;
    }

Valid:
    cout << "\nOutput: Valid String";
    goto exit;

Invalid:
    cout << "\nOutput: Invalid String";
    goto exit;

Wrong:
    cout << "\nPlease enter a binary string";

exit:
    getch();
}


/* ==========================================================
   PRACTICAL 5: PDA - strings of form 0^n 1^n (n >= 1)
   ========================================================== */
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main()
{
    char Input[100];
    char stack[100]; // Implementing stack through array.

    int Top = -1;

    clrscr();

    cout << "Enter binary string to validate (input string should be of 0 and 1)\n";
    gets(Input);

    stack[++Top] = 'Z'; // Taking 'Z' as an initial stack symbol.

    int i = -1;

q0:
    i++;

    if (Input[i] == '0' && stack[Top] == 'Z')
    {
        stack[++Top] = 'A';
        goto q0;
    }
    else if (Input[i] == '0' && stack[Top] == 'A')
    {
        stack[++Top] = 'A';
        goto q0;
    }
    else if (Input[i] == '1' && stack[Top] == 'A')
    {
        Top--;
        goto q1;
    }
    else
    {
        goto Invalid;
    }

q1:
    i++;

    if (Input[i] == '1' && stack[Top] == 'A')
    {
        Top--;
        goto q1;
    }
    else if (Input[i] == '\0' && stack[Top] == 'Z')
    {
        Top--;
        goto q2;
    }
    else
    {
        goto Invalid;
    }

q2:
    cout << "\nOutput: Valid String";
    goto exit;

Invalid:
    cout << "\nOutput: Invalid String";
    goto exit;

exit:
    getch();
}


/* ==========================================================
   PRACTICAL 6: PDA - strings of form wCw^R
   ========================================================== */
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main()
{
    char Input[100];
    char stack[100];
    int Top = -1;

    clrscr();

    cout << "Enter string to be validate\n";
    gets(Input);

    stack[++Top] = 'Z';

    int i = -1;

q0:
    i++;

    if (Input[i] == '0' && stack[Top] == 'Z')
    {
        stack[++Top] = 'A';
        goto q0;
    }
    else if (Input[i] == '1' && stack[Top] == 'Z')
    {
        stack[++Top] = 'B';
        goto q0;
    }
    else if (Input[i] == '0' &&
            (stack[Top] == 'A' || stack[Top] == 'B'))
    {
        stack[++Top] = 'A';
        goto q0;
    }
    else if (Input[i] == '1' &&
            (stack[Top] == 'A' || stack[Top] == 'B'))
    {
        stack[++Top] = 'B';
        goto q0;
    }
    else if (Input[i] == 'C' &&
            (stack[Top] == 'A' || stack[Top] == 'B'))
    {
        goto q1;
    }
    else
    {
        goto Invalid;
    }

q1:
    i++;

    if (Input[i] == '0' && stack[Top] == 'A')
    {
        Top--;
        goto q1;
    }
    else if (Input[i] == '1' && stack[Top] == 'B')
    {
        Top--;
        goto q1;
    }
    else if (Input[i] == '\0' && stack[Top] == 'Z')
    {
        goto Valid;
    }
    else
    {
        goto Invalid;
    }

Valid:
    cout << "\nOutput: Valid String";
    goto exit;

Invalid:
    cout << "\nOutput: Invalid String";
    goto exit;

exit:
    getch();
}


/* ==========================================================
   PRACTICAL 7: PDA - strings of form 0^(m+k) 1^m 2^k
   ========================================================== */
#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void main()
{
    char stack[100];
    char input[100];
    int top=-1;

    clrscr();

    cout<<"Enter a string to validate\n";
    gets(input);

    stack[++top]='z';

    int i=-1;
    int flag=0;

q0:
    i++;

    if(input[i]=='0' && stack[top]=='z')
    {
        stack[++top]='a';
        goto q0;
    }
    else if(input[i]=='0' && stack[top]=='a')
    {
        stack[++top]='a';
        goto q0;
    }
    else if(input[i]=='1' && stack[top]=='a')
    {
        top--;
        flag=1;
        goto q1;
    }
    else
    {
        goto invalid;
    }

q1:
    i++;

    if(input[i]=='1' && stack[top]=='a')
    {
        top--;
        goto q1;
    }
    else if(input[i]=='2' && stack[top]=='a' && flag==1)
    {
        top--;
        flag=2;
        goto q2;
    }
    else
    {
        goto invalid;
    }

q2:
    i++;

    if(input[i]=='2' && stack[top]=='a' && flag==2)
    {
        top--;
        goto q2;
    }
    else if(input[i]=='\0' && stack[top]=='z' && flag==2)
    {
        cout<<"\nOutput: Valid string";
        goto exit;
    }
    else
    {
        goto invalid;
    }

invalid:
    cout<<"\nOutput: Invalid string";
    goto exit;

exit:
    getch();
}


/* ==========================================================
   PRACTICAL 8: Turing-style machine - two's complement (original)
   ========================================================== */
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main()
{
    char Input[100];
    clrscr();

    cout << "Enter input binary string\n";
    gets(Input);

    int i = 0;

Q0:
    if (Input[i] == '0' || Input[i] == '1')
    {
        i++;
        goto Q0;
    }
    else if (Input[i] == '\0')
    {
        i--;
        goto Q1;
    }
    else
    {
        goto Invalid;
    }

Q1:
    if (Input[i] == '0')
    {
        i--;
        goto Q1;
    }
    else if (Input[i] == '1')
    {
        i--;
        goto Q2;
    }
    else
    {
        goto Invalid;
    }

Q2:
    if (Input[i] == '0')
    {
        Input[i] = '1';
        i--;
        goto Q2;
    }
    else if (Input[i] == '1')
    {
        Input[i] = '0';
        i--;
        goto Q2;
    }
    else if (i == -1)
    {
        goto Q3;
    }
    else
    {
        goto Invalid;
    }

Q3:
    cout << "\nOutput: Two's complement is ";
    puts(Input);
    goto Exit;

Invalid:
    cout << "\nYou have entered some invalid string.";
    goto Exit;

Exit:
    getch();
}


/* ==========================================================
   PRACTICAL 8 (CORRECTED): bounds bug fixed
   Fixes: empty input guard, and i < 0 checked before Input[i]
   ========================================================== */
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main()
{
    char Input[100];
    clrscr();

    cout << "Enter input binary string\n";
    gets(Input);

    int i = 0;

Q0:
    if (Input[i] == '0' || Input[i] == '1')
    {
        i++;
        goto Q0;
    }
    else if (Input[i] == '\0')
    {
        if (i == 0)              // FIX 1: empty string is invalid
        {
            goto Invalid;
        }
        i--;
        goto Q1;
    }
    else
    {
        goto Invalid;
    }

Q1:
    if (i < 0)                   // FIX 2: check bounds BEFORE reading Input[i]
    {
        goto Q3;                 // no 1 found (e.g. "0"): result is the input itself
    }
    else if (Input[i] == '0')
    {
        i--;
        goto Q1;
    }
    else if (Input[i] == '1')
    {
        i--;
        goto Q2;
    }
    else
    {
        goto Invalid;
    }

Q2:
    if (i < 0)                   // FIX 3: stop before reading Input[-1]
    {
        goto Q3;
    }
    else if (Input[i] == '0')
    {
        Input[i] = '1';
        i--;
        goto Q2;
    }
    else if (Input[i] == '1')
    {
        Input[i] = '0';
        i--;
        goto Q2;
    }
    else
    {
        goto Invalid;
    }

Q3:
    cout << "\nOutput: Two's complement is ";
    puts(Input);
    goto Exit;

Invalid:
    cout << "\nYou have entered some invalid string.";
    goto Exit;

Exit:
    getch();
}
