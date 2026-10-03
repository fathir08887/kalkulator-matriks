#include <iostream>
using namespace std;

const int MAX = 10;

// Fungsi input matriks
void inputMatriks(int matriks[MAX][MAX], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "Masukkan elemen [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriks[i][j];
        }
    }
}

// Fungsi menampilkan matriks
void tampilMatriks(int matriks[MAX][MAX], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }
}

// Penjumlahan matriks
void tambahMatriks(
    int A[MAX][MAX],
    int B[MAX][MAX],
    int hasil[MAX][MAX],
    int baris,
    int kolom
) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Pengurangan matriks
void kurangMatriks(
    int A[MAX][MAX],
    int B[MAX][MAX],
    int hasil[MAX][MAX],
    int baris,
    int kolom
) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Perkalian matriks
void kaliMatriks(
    int A[MAX][MAX],
    int B[MAX][MAX],
    int hasil[MAX][MAX],
    int barisA,
    int kolomA,
    int kolomB
) {
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomB; j++) {
            hasil[i][j] = 0;

            for (int k = 0; k < kolomA; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Transpose matriks
void transposeMatriks(
    int A[MAX][MAX],
    int hasil[MAX][MAX],
    int baris,
    int kolom
) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[j][i] = A[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], hasil[MAX][MAX];
    int barisA, kolomA, barisB, kolomB;
    int pilihan;

    do {
        cout << "\n=================================\n";
        cout << "       KALKULATOR MATRIKS\n";
        cout << "=================================\n";
        cout << "1. Penjumlahan Matriks\n";
        cout << "2. Pengurangan Matriks\n";
        cout << "3. Perkalian Matriks\n";
        cout << "4. Transpose Matriks\n";
        cout << "5. Keluar\n";
        cout << "=================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            cout << "\n--- PENJUMLAHAN MATRIKS ---\n";

            cout << "Jumlah baris: ";
            cin >> barisA;
            cout << "Jumlah kolom: ";
            cin >> kolomA;

            cout << "\nMatriks A\n";
            inputMatriks(A, barisA, kolomA);

            cout << "\nMatriks B\n";
            inputMatriks(B, barisA, kolomA);

            tambahMatriks(A, B, hasil, barisA, kolomA);

            cout << "\nHasil A + B:\n";
            tampilMatriks(hasil, barisA, kolomA);
            break;

        case 2:
            cout << "\n--- PENGURANGAN MATRIKS ---\n";

            cout << "Jumlah baris: ";
            cin >> barisA;
            cout << "Jumlah kolom: ";
            cin >> kolomA;

            cout << "\nMatriks A\n";
            inputMatriks(A, barisA, kolomA);

            cout << "\nMatriks B\n";
            inputMatriks(B, barisA, kolomA);

            kurangMatriks(A, B, hasil, barisA, kolomA);

            cout << "\nHasil A - B:\n";
            tampilMatriks(hasil, barisA, kolomA);
            break;

        case 3:
            cout << "\n--- PERKALIAN MATRIKS ---\n";

            cout << "Jumlah baris Matriks A: ";
            cin >> barisA;
            cout << "Jumlah kolom Matriks A: ";
            cin >> kolomA;

            cout << "Jumlah baris Matriks B: ";
            cin >> barisB;
            cout << "Jumlah kolom Matriks B: ";
            cin >> kolomB;

            // Syarat perkalian matriks
            if (kolomA != barisB) {
                cout << "\nMatriks tidak dapat dikalikan!\n";
                cout << "Kolom A harus sama dengan baris B.\n";
                break;
            }

            cout << "\nMatriks A\n";
            inputMatriks(A, barisA, kolomA);

            cout << "\nMatriks B\n";
            inputMatriks(B, barisB, kolomB);

            kaliMatriks(
                A, B, hasil,
                barisA, kolomA, kolomB
            );

            cout << "\nHasil A x B:\n";
            tampilMatriks(hasil, barisA, kolomB);
            break;

        case 4:
            cout << "\n--- TRANSPOSE MATRIKS ---\n";

            cout << "Jumlah baris: ";
            cin >> barisA;
            cout << "Jumlah kolom: ";
            cin >> kolomA;

            cout << "\nMatriks A\n";
            inputMatriks(A, barisA, kolomA);

            transposeMatriks(
                A, hasil,
                barisA, kolomA
            );

            cout << "\nHasil transpose:\n";
            tampilMatriks(hasil, kolomA, barisA);
            break;

        case 5:
            cout << "\nProgram selesai.\n";
            break;

        default:
            cout << "\nPilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}