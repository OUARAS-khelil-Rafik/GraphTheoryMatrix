#include <iostream>
#include <climits> // Pour utiliser INT_MAX
using namespace std;

// Fonction pour vérifier si la valeur entrée est 0 ou 1
void verifier(int &M, int i, int j) {
    do {
        cout << "M[" << i << "][" << j << "]= ";
        cin >> M;
    } while ((M != 0) && (M != 1));
}

// Fonction pour saisir les valeurs de la matrice
void intMat(int M[][100], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int z = M[i][j];
            verifier(z, i, j);
            M[i][j] = z;
        }
    }
}

// Fonction pour afficher la matrice
void affichMat(int M[][100], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fonction pour vérifier la connexité du graphe
void VerfConnexe(int M[][100], int n) {
    int s = 0;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s = s + M[i][j];
        }
        if (s == 0) {
            k = 1;
            i = n + 1;
        }
        s = 0;
    }
    if (k == 1) {
        cout << "Le graphe matricielle M n'est pas connexe";
    } else {
        cout << "Le graphe matricielle M est connexe";
    }
}

// Fonction pour calculer le degré d'un sommet
int CalDegree(int M[][100], int n, int x) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s = s + M[x][i] + M[i][x];
    }
    return s;
}

// Fonction pour chercher les composantes fortement connexes
void CFC(int M[][100], int n) {
    int W[n + 1];
    int s = 0;
    int k = 0;

    for (int i = 1; i <= n; i++) {
        W[i] = i; // L'ensemble de tous les sommets//
        s = s + W[i];
    }
    cout << "\nInitialisation : ";
    cout << "k = " << k << "\nW ={";
    for (int i = 1; i <= n; i++) {
        cout << W[i] << ",";
    }
    cout << "}";
    int R[2 * n];
    int p = 1;

    for (int i = 1; i <= n; i++) {
        int d = 0;
        cout << "\nOn marque tous les successeurs de sommet : " << i;
        for (int j = 1; j <= n; j++) {
            if (M[i][j] == 1) {
                R[p + d] = j;
                cout << "\n" << R[p + d] << "\t";
                d++;
            }
        }
        if (d == 0) {
            cout << "\nAucun successeurs";
        }
        p = p + d;
    }

    int P[2 * n];
    int q = 1;
    for (int j = 1; j <= n; j++) {
        int d = 0;
        cout << "\nOn marque tous les predeccesseurs de sommet : " << j;
        for (int i = 1; i <= n; i++) {
            if (M[i][j] == 1) {
                P[q + d] = i;
                cout << "\n" << P[q + d] << "\t";
                d++;
            }
        }
        if (d == 0) {
            cout << "\nAucun predecesseurs";
        }
        q = q + d;
    }
}

// Fonction pour trier les sommets en fonction de leurs degrés
void Tri(int R[], int n) {
    int T[n];
    for (int i = 1; i <= n; i++) {
        T[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int k = 0, r = 0;
            if (R[i] > R[j]) {
                k = R[i];
                r = T[i];
                R[i] = R[j];
                T[i] = T[j];
                R[j] = k;
                T[j] = r;
            }
        }
    }
    cout << "\nOrdonnencment des sommets: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << T[i] << "\t";
    }
}

// Fonction pour ordonner le graphe
void Ordre(int M[][100], int n) {
    int T[n];
    for (int i = 1; i <= n; i++) {
        int d = 0;
        for (int j = 1; j <= n; j++) {
            if (M[i][j] == 1) {
                d++;
            }
        }
        T[i] = d; // le nombre de successeur de chaque sommet //
    }
    Tri(T, n);
}

int main() {
    int k;
    cout << "Donnez moi le nombre des sommets : ";
    cin >> k;
    int M[100][100];
    cout << "Pour Creer une graphe matricielle, svp donnez moi les coordonnes de la matrice M (entre 0 et 1) : \n";
    intMat(M, k);
    cout << "---------------------------------------------------------\n";
    cout << "Le graphe matricielle M :\n";
    affichMat(M, k);
    cout << "---------------------------------------------------------\n";
    VerfConnexe(M, k);
    cout << "\n---------------------------------------------------------\n";
    cout << "Pour calculer les degres de tous les sommets : \n";
    for (int i = 1; i <= k; i++) {
        cout << "\nLe degre du sommet N = " << i << " est : " << CalDegree(M, k, i);
    }
    cout << "\n---------------------------------------------------------\n";
    cout << "Pour Chercher les composantes fortement connexes :\n";
    CFC(M, k);
    cout << "\n---------------------------------------------------------";
    cout << "\nOrdonner le graphe matricielle : " << endl;
    Ordre(M, k);
    return 0;
}