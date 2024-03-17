#include "Headers.h"
#include <string.h>
#include <stdio.h>

/* strlen:  return length of string s */
int strlen0(char *s)
{
    int n;
    for (n = 0; *s != '\0';s++) n++;
    return n;
}

unsigned long strlen1(char *s)
{
    char *p = s;
    while (*p != '\0') p++;
    return p - s;
}

void strCpyStd (char *s, char *t)
{
    int i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

//Lo mismo pero con Punteros
void strCpyPointers (char *s, char *t)
{
    while ((*s = *t) != '\0'){
        s++;
        t++;
    }
}

// Tambien se pude poner mas bonito
void strCpyPointersPretty (char *s, char *t)
{
    while ((*s++ = *t++) != '\0');
}

// La comparacion con '\0' es redundante ya que si tenemos un 0 tendriamos un false que detendria el while
void strCpyPointersPrettyer (char *s, char *t)
{
    while ((*s++ = *t++));
}

// strcmp:  return <0 if s<t, 0 if s==t, >0 if s>t
int strcmpStd(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
    return 0;
    return s[i] - t[i];
}

int strCmpPointer(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0') return 0;

    return *s - *t;
}

void strcatPointer(char *s, char *t)
{
    while (*s) s++;
    while ((*s++ = *t++));
}

int strend(char *s, char*t)
{
    // Get the lenght of t and s
    unsigned long lenT = strlen(t) + 1;
    unsigned long lenS = strlen(s) + 1;

    if(lenS < lenT) return 0;
    s += lenS - lenT;

    for ( ; *s == *t; s++, t++)
        if (*s == '\0') return 1;

    return 0;
}

/* writelines:  write output lines */
void writelines(char *lineptr[],  int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* swap:  interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* qsort:  sort v[left]...v[right] into increasing order */
void qsort(char *v[],  int left, int right)
{
    int i, last;
    if (left >= right)   /* do nothing if array contains */
        return;           /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v,  ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
