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
void selectNPM(struct Mahasiswa mhs[5], int n) {
    for (int i = 0; i < n - 1; i++) {
        int a = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(mhs[j].npm, mhs[a].npm) < 0) { // < ascending, > descending
                a = j;
            }
        }
        struct Mahasiswa temp = mhs[i];
        mhs[i] = mhs[a];
        mhs[a] = temp;
    }
}

// Fungsi sorting data (Nama)
void selectNama(struct Mahasiswa mhs[5], int n) {
    for (int i = 0; i < n - 1; i++) {
        int b = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(mhs[j].nama, mhs[b].nama) < 0) { // < ascending, > descending
                b = j;
            }
        }
        struct Mahasiswa temp = mhs[i];
        mhs[i] = mhs[b];
        mhs[b] = temp;
    }
}

// Fungsi sorting data (IPK)
void selectIPK(struct Mahasiswa mhs[5], int n) {
    for (int i = 0; i < n - 1; i++) {
        int c = i;
        for (int j = i + 1; j < n; j++) {
            if (mhs[j].ipk < mhs[c].ipk) { // < ascending, > descending
                c = j;
            }
        }
        struct Mahasiswa temp = mhs[i];
        mhs[i] = mhs[c];
        mhs[c] = temp;
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
	tampilkanData(mhs, n);

	int pilihan;
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
                selectNPM(mhs, n);
                printf("\nData Mahasiswa diurutkan berdasarkan NPM:\n");
				tampilkanData(mhs, n);
                break;
            case 2:
                selectNama(mhs, n);
                 printf("\nData Mahasiswa diurutkan berdasarkan Nama:\n");
				tampilkanData(mhs, n);
                break;
            case 3:
                selectIPK(mhs, n);
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
