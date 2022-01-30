#include <iostream>
#include <cctype>

using namespace std;
const int MAX = 21;

/* Restituisce il numero di caratteri contenuti nella stringa “s”,
terminatore escluso. Ad esempio la stringa “ciao” è lunga 4 caratteri. */
int lunghezzaStringa(char s[]) {
    int i = 0;
    do {
        i++;
    } while (s[i]);
    return i;
}

/* Converte la stringa “s” in minuscolo (cioè in lower case). Ad esempio, la
stringa “LocaNdiera” viene convertita in “locandiera” */
void convertiStringa(char s[]) {
    int lun = lunghezzaStringa(s);
    for (int i = 0; i < lun; i++) s[i] = tolower(s[i]);
}

/* Ordina i caratteri contenuti nella stringa “daOrd” per codice ASCII
decrescente. Può essere applicato un qualsiasi algoritmo di ordinamento di
un vettore. */
void ordinaStringa(char daOrd[], int n) {
    char mem;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (daOrd[i] < daOrd[j]) {
                mem = daOrd[j];
                daOrd[j] = daOrd[i];
                daOrd[i] = mem;
            }
        }
    }
}

/* Restituisce true se le stringhe s1 e s2 sono due anagrammi, false
altrimenti. In altre parole, implementa l'algoritmo descritto nelle
specifiche, utilizzando le funzioni definite in precedenza. */
bool anagrammi(char s1[], char s2[]) {
    int l1 = lunghezzaStringa(s1);
    int l2 = lunghezzaStringa(s2);
    /*cout<<"s1="<<s1<<"\t l1="<<l1<<endl;
    cout<<"s2="<<s2<<"\t l2="<<l2<<endl;*/
    if (l1 == l2) {
        convertiStringa(s1);
        convertiStringa(s2);
        /*cout<<"s1="<<s1<<"\t l1="<<l1<<endl;
    cout<<"s2="<<s2<<"\t l2="<<l2<<endl;*/
        ordinaStringa(s1, l1);
        ordinaStringa(s2, l2);
        /*cout<<"s1="<<s1<<"\t l1="<<l1<<endl;
    cout<<"s2="<<s2<<"\t l2="<<l2<<endl;*/
        for (int i = 0; i < l1; i++) if (s1[i] != s2[i]) return false;
        return true;
    } else return false;
}

// Programma principale
int main() {
    char s1[MAX];
    char s2[MAX];
    cin >> s1 >> s2;
    if (anagrammi(s1, s2)) cout << "s1 e s2 sono anagrammi.";
    else cout << "s1 e s2 non sono anagrammi.";
}