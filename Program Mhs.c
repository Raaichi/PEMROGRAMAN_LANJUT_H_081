#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char npm[15];
    char nama[50];
    char prodi[50];
    double ipk;
};

void tampilkanData(struct Mahasiswa mhs[5], int n) {
    printf("\n%1s %16s %36s %13s\n", "NPM", "Nama", "Prodi", "IPK");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s %-35s %-15s %-10.2f\n", mhs[i].npm, mhs[i].nama, mhs[i].prodi, mhs[i].ipk);
    }
    printf("\n");
}

void sortNama(struct Mahasiswa mhs[5], int n) {
    struct Mahasiswa temp;
    // Loop setiap elemen array
    for (int i = 0; i < n - 1; i++) {
    	// Loop membandingkan elemen bersebelahan
        for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(mhs[j].nama, mhs[j + 1].nama) > 0) { // > ascending, < descending
                temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
    printf("Data telah diurutkan berdasarkan Nama (ascending).\n");
}

int main() {
    struct Mahasiswa mhs[5] = {
        {"23081010035", "Muthmainnah Az Zahra", "Informatika", 3.84},
        {"23081010209", "Shahzada Sabih Anandian Hartanto", "Informatika", 3.85},
        {"23081010203", "Christian Bimo Aryoputro", "Informatika", 3.82},
        {"23081010215", "Febbyna Aulia Putri", "Informatika", 3.83},
        {"23081010260", "Nugraini Dewi Puspitasari", "Informatika", 3.81}
    };

    int pilihan;
    do {
        printf("------ Menu Mahasiswa ------\n");
        printf("1. Tampilkan Data Mahasiswa\n");
        printf("2. Sorting Data (Nama)\n");
        printf("3. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanData(mhs, 5);
                break;
            case 2:
                sortNama(mhs, 5);
                tampilkanData(mhs, 5);
                break;
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 3);

    return 0;
}
