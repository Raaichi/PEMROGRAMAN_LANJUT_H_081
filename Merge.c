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

// Fungsi untuk menggabungkan sub-array
void merge(struct Mahasiswa mhs[5], int left, int mid, int right, int (*cmp)(struct Mahasiswa, struct Mahasiswa)) {
    int n1 = mid - left + 1, n2 = right - mid;
    struct Mahasiswa L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = mhs[left + i];
    for (int j = 0; j < n2; j++) R[j] = mhs[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) mhs[k++] = (cmp(L[i], R[j]) <= 0) ? L[i++] : R[j++];
    while (i < n1) mhs[k++] = L[i++];
    while (j < n2) mhs[k++] = R[j++];
}

// Fungsi rekursif merge sort
void mergeSort(struct Mahasiswa mhs[5], int left, int right, int (*cmp)(struct Mahasiswa, struct Mahasiswa)) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(mhs, left, mid, cmp);
        mergeSort(mhs, mid + 1, right, cmp);
        merge(mhs, left, mid, right, cmp);
    }
}

// Fungsi pembanding
int compareNPM(struct Mahasiswa a, struct Mahasiswa b) { return strcmp(a.npm, b.npm); } 	// a, b ascending; b, a descending
int compareNama(struct Mahasiswa a, struct Mahasiswa b) { return strcmp(a.nama, b.nama); } 	// a, b ascending; b, a descending
int compareIPK(struct Mahasiswa a, struct Mahasiswa b) { return (a.ipk < b.ipk) ? -1 : (a.ipk > b.ipk); } // <> ascending, >< desncending

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
                mergeSort(mhs, 0, n - 1, compareNPM);
                printf("\nData Mahasiswa diurutkan berdasarkan NPM:\n");
                tampilkanData(mhs, n);
                break;
            case 2:
                mergeSort(mhs, 0, n - 1, compareNama);
                printf("\nData Mahasiswa diurutkan berdasarkan Nama:\n");
                tampilkanData(mhs, n);
                break;
            case 3:
                mergeSort(mhs, 0, n - 1, compareIPK);
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
