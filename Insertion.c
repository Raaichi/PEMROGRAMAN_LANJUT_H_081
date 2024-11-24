#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char npm[15];
    char nama[50];
    char prodi[50];
    double ipk;
};

void tampilkanData(struct Mahasiswa mhs[5], int n) {
    printf("%-15s %-35s %-20s %-5s\n", "NPM", "Nama", "Prodi", "IPK");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s %-35s %-20s %.2f\n", mhs[i].npm, mhs[i].nama, mhs[i].prodi, mhs[i].ipk);
    }
    printf("\n");
}

// Fungsi sorting data (NPM)
void insertNPM(struct Mahasiswa mhs[5], int n) {
    for (int i = 1; i < n; i++) {
        struct Mahasiswa a = mhs[i];
        int j = i - 1;
        while (j >= 0 && strcmp(mhs[j].npm, a.npm) > 0) { // > ascending, < descending
            mhs[j + 1] = mhs[j];
            j--;
        }
        mhs[j + 1] = a;
    }
}

// Fungsi sorting data (Nama)
void insertNama(struct Mahasiswa mhs[5], int n) {
    for (int i = 1; i < n; i++) {
        struct Mahasiswa b = mhs[i];
        int j = i - 1;
        while (j >= 0 && strcmp(mhs[j].nama, b.nama) > 0) { // > ascending, < descending
            mhs[j + 1] = mhs[j];
            j--;
        }
        mhs[j + 1] = b;
    }
}

// Fungsi sorting data (IPK)
void insertIPK(struct Mahasiswa mhs[5], int n) {
    for (int i = 1; i < n; i++) {
        struct Mahasiswa c = mhs[i];
        int j = i - 1;
        while (j >= 0 && mhs[j].ipk > c.ipk) { // > ascending, < descending
            mhs[j + 1] = mhs[j];
            j--;
        }
        mhs[j + 1] = c;
    }
}

int main() {
    struct Mahasiswa mhs[5] = {
        {"23081010035", "Muthmainnah Az Zahra", "Informatika", 3.84},
        {"23081010209", "Shahzada Sabih Anandian Hartanto", "Informatika", 3.85},
        {"23081010203", "Christian Bimo Aryoputro", "Informatika", 3.82},
        {"23081010215", "Febbyna Aulia Putri", "Informatika", 3.83},
        {"23081010260", "Nugraini Dewi Puspitasari", "Informatika", 3.81}
    };
    int n = sizeof(mhs) / sizeof(mhs[5]);

    int pilihan;
	tampilkanData(mhs, n);
   do {
        printf("------ Menu Mahasiswa ------\n");
        printf("Urutkan data berdasarkan:\n");
		printf("1. NPM\n");
        printf("2. Nama\n");
        printf("3. IPK\n");
        printf("4. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                insertNPM(mhs, n);
                printf("\nData Mahasiswa diurutkan berdasarkan NPM:\n");
                tampilkanData(mhs, n);
                break;
            case 2:
                insertNama(mhs, n);
                printf("\nData Mahasiswa diurutkan berdasarkan Nama:\n");
                tampilkanData(mhs, n);
                break;
            case 3:
                insertIPK(mhs, n);
                printf("\nData Mahasiswa diurutkan berdasarkan IPK:\n");
                tampilkanData(mhs, n);
                break;
            case 4:
                printf("Keluar...\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 4);

    return 0;
}
