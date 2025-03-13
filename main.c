#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASTA 100
#define MAX_RECETE 50

// Hasta yapısı
typedef struct {
    int hastaNo;
    char ad[50];
    char soyad[50];
    int acilDurum; // 1-5 arası acil durum derecesi
    char rahatsizlik[100]; // Hasta rahatsızlığı
    int renkKodu; // 1: Kırmızı, 2: Sarı, 3: Yeşil
    float ates;
    int tansiyon;
} Hasta;

// Reçete yapısı
typedef struct {
    int receteNo;
    int hastaNo;
    char ilacAdi[50];
} Recete;

// Stack için yapı
typedef struct {
    Hasta hastalar[MAX_HASTA];
    int top;
} HastaStack;

// Kuyruk için yapı
typedef struct {
    Hasta hastalar[MAX_HASTA];
    int front, rear;
} HastaQueue;

// Fonksiyon prototipleri
void hastaEkle(HastaStack *stack, Hasta hasta);
void hastaCikar(HastaStack *stack, Hasta *hastalar, int *hastaSayisi);
void hastaSirala(HastaQueue *queue, Hasta hasta);
void receteOlustur(Recete *receteler, int *receteSayisi, int hastaNo, char *ilacAdi);
void hastaKaydet(Hasta hasta);
void receteKaydet(Recete recete);
void hastaKayitlariGoster(Hasta *hastalar, int *hastaSayisi, Recete *receteler, int receteSayisi, HastaQueue *queue);

void inputBufferTemizle() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void hastaEkle(HastaStack *stack, Hasta hasta) {
    if (stack->top < MAX_HASTA - 1) {
        stack->hastalar[++stack->top] = hasta;
        printf("Hasta eklendi.\n");
    } else {
        printf("Stack dolu.\n");
    }
}

void hastaCikar(HastaStack *stack, Hasta *hastalar, int *hastaSayisi) {
    int hastaNo;
    printf("Silinecek Hasta Numarasi: ");
    if (scanf("%d", &hastaNo) != 1) {
        printf("Hasta numarasi sadece sayilar olarak girebilirsiniz.\n");
        inputBufferTemizle(); // Input bufferını temizlemek için
        return;
    }
    inputBufferTemizle(); // Input bufferını temizlemek için

    for (int i = 0; i < *hastaSayisi; i++) {
        if (hastalar[i].hastaNo == hastaNo) {
            printf("Cikarilan hasta: %d %s %s\n", hastalar[i].hastaNo, hastalar[i].ad, hastalar[i].soyad);
            for (int j = i; j < *hastaSayisi - 1; j++) {
                hastalar[j] = hastalar[j + 1];
            }
            (*hastaSayisi)--;
            printf("Hasta kaydi silindi.\n");
            return;
        }
    }
    printf("Hasta bulunamadi.\n");
}

void hastaSirala(HastaQueue *queue, Hasta hasta) {
    if (queue->rear < MAX_HASTA - 1) {
        if (queue->front == -1) {
            queue->front = queue->rear = 0;
            queue->hastalar[queue->rear] = hasta;
        } else {
            int i;
            for (i = queue->rear; i >= queue->front && queue->hastalar[i].renkKodu > hasta.renkKodu; i--) {
                queue->hastalar[i + 1] = queue->hastalar[i];
            }
            queue->hastalar[i + 1] = hasta;
            queue->rear++;
        }
        printf("Hasta siralandi.\n");
    } else {
        printf("Kuyruk dolu.\n");
    }
}

void receteOlustur(Recete *receteler, int *receteSayisi, int hastaNo, char *ilacAdi) {
    if (*receteSayisi < MAX_RECETE) {
        receteler[*receteSayisi].receteNo = *receteSayisi + 1;
        receteler[*receteSayisi].hastaNo = hastaNo;
        strcpy(receteler[*receteSayisi].ilacAdi, ilacAdi);
        (*receteSayisi)++;
        printf("Recete olusturuldu.\n");
    } else {
        printf("Recete limiti doldu.\n");
    }
}

void hastaKaydet(Hasta hasta) {
    // Dosyaya kaydetme islemleri burada yapilabilir.
    printf("Hasta kaydedildi.\n");
}

void receteKaydet(Recete recete) {
    // Dosyaya kaydetme islemleri burada yapilabilir.
    printf("Recete kaydedildi.\n");
}

void hastaKayitlariGoster(Hasta *hastalar, int *hastaSayisi, Recete *receteler, int receteSayisi, HastaQueue *queue) {
    int secim;
    printf("Hasta arama secenekleri:\n");
    printf("1. Hasta Numarasi ile arama\n");
    printf("2. Ad ve Soyad ile arama\n");
    printf("3. Oncelik Sirala\n");
    printf("Seciminiz: ");
    scanf("%d", &secim);
    inputBufferTemizle(); // Input bufferını temizlemek için

    switch (secim) {
        case 1: {
            int hastaNo;
            printf("Hasta Numarasi: ");
            if (scanf("%d", &hastaNo) != 1) {
                printf("Hasta numarasi sadece sayilar olarak girebilirsiniz.\n");
                inputBufferTemizle(); // Input bufferını temizlemek için
                return;
            }
            inputBufferTemizle(); // Input bufferını temizlemek için
            for (int i = 0; i < *hastaSayisi; i++) {
                if (hastalar[i].hastaNo == hastaNo) {
                    printf("Hasta Numarasi: %d\n", hastalar[i].hastaNo);
                    printf("Ad: %s\n", hastalar[i].ad);
                    printf("Soyad: %s\n", hastalar[i].soyad);
                    printf("Acil Durum: %d\n", hastalar[i].acilDurum);
                    printf("Rahatsizlik: %s\n", hastalar[i].rahatsizlik);
                    printf("Ates: %.2f C\n", hastalar[i].ates);
                    printf("Tansiyon: %d mmHg\n", hastalar[i].tansiyon);
                    printf("Renk Kodu: %d\n", hastalar[i].renkKodu);

                    printf("Receteler:\n");
                    int sayac = 0;
                    for (int j = 0; j < receteSayisi; j++) {
                        if (receteler[j].hastaNo == hastaNo) {
                            printf("Recete No: %d, Ilac Adi: %s\n", receteler[j].receteNo, receteler[j].ilacAdi);
                            sayac++;
                        }
                    }
                    if (sayac == 0) {
                        printf("Hasta icin recete bulunamadi.\n");
                    }

                    printf("Ilac Recete Olusturmak ister misiniz? (1: Evet, 2: Hayir)\n");
                    scanf("%d", &secim);
                    inputBufferTemizle(); // Input bufferını temizlemek için
                    if (secim == 1) {
                        char ilacAdi[50];
                        printf("Ilac Adi: ");
                        scanf("%49s", ilacAdi); // scanf için buffer overflow önlemek için 49 karakter sınırı konuldu
                        inputBufferTemizle(); // Input bufferını temizlemek için
                        receteOlustur(receteler, &receteSayisi, hastaNo, ilacAdi);
                        receteKaydet(receteler[receteSayisi - 1]);
                    }
                    printf("Ana menuye donmek icin Enter tusuna basin...\n");
                    getchar(); // Enter tuşuna basılmasını beklemek için
                    return;
                }
            }
            printf("Hasta bulunamadi.\n");
            printf("Ana menuye donmek icin Enter tusuna basin...\n");
            getchar(); // Enter tuşuna basılmasını beklemek için
            break;
        }
        case 2: {
            char ad[50], soyad[50];
            printf("Ad: ");
            scanf("%49s", ad); // scanf için buffer overflow önlemek için 49 karakter sınırı konuldu
            inputBufferTemizle(); // Input bufferını temizlemek için
            printf("Soyad: ");
            scanf("%49s", soyad); // scanf için buffer overflow önlemek için 49 karakter sınırı konuldu
            inputBufferTemizle(); // Input bufferını temizlemek için
            for (int i = 0; i < *hastaSayisi; i++) {
                if (strcmp(hastalar[i].ad, ad) == 0 && strcmp(hastalar[i].soyad, soyad) == 0) {
                    printf("Hasta Numarasi: %d\n", hastalar[i].hastaNo);
                    printf("Ad: %s\n", hastalar[i].ad);
                    printf("Soyad: %s\n", hastalar[i].soyad);
                    printf("Acil Durum: %d\n", hastalar[i].acilDurum);
                    printf("Rahatsizlik: %s\n", hastalar[i].rahatsizlik);
                    printf("Ates: %.2f C\n", hastalar[i].ates);
                    printf("Tansiyon: %d mmHg\n", hastalar[i].tansiyon);
                    printf("Renk Kodu: %d\n", hastalar[i].renkKodu);

                    printf("Receteler:\n");
                    int sayac = 0;
                    for (int j = 0; j < receteSayisi; j++) {
                        if (receteler[j].hastaNo == hastalar[i].hastaNo) {
                            printf("Recete No: %d, Ilac Adi: %s\n", receteler[j].receteNo, receteler[j].ilacAdi);
                            sayac++;
                        }
                    }
                    if (sayac == 0) {
                        printf("Hasta icin recete bulunamadi.\n");
                    }

                    printf("Ilac Recete Olusturmak ister misiniz? (1: Evet, 2: Hayir)\n");
                    scanf("%d", &secim);
                    inputBufferTemizle(); // Input bufferını temizlemek için
                    if (secim == 1) {
                        char ilacAdi[50];
                        printf("Ilac Adi: ");
                        scanf("%49s", ilacAdi); // scanf için buffer overflow önlemek için 49 karakter sınırı konuldu
                        inputBufferTemizle(); // Input bufferını temizlemek için
                        receteOlustur(receteler, &receteSayisi, hastalar[i].hastaNo, ilacAdi);
                        receteKaydet(receteler[receteSayisi - 1]);
                    }
                    printf("Ana menuye donmek icin Enter tusuna basin...\n");
                    getchar(); // Enter tuşuna basılmasını beklemek için
                    return;
                }
            }
            printf("Hasta bulunamadi.\n");
            printf("Ana menuye donmek icin Enter tusuna basin...\n");
            getchar(); // Enter tuşuna basılmasını beklemek için
            break;
        }
        case 3: {
            Hasta hasta;
            printf("Hasta Numarasi: ");
            if (scanf("%d", &hasta.hastaNo) != 1) {
                printf("Hasta numarasi sadece sayilar olarak girebilirsiniz.\n");
                inputBufferTemizle(); // Input bufferını temizlemek için
                return;
            }
            inputBufferTemizle(); // Input bufferını temizlemek için
            printf("Ad: ");
            scanf("%49s", hasta.ad); // scanf için buffer overflow önlemek için 49 karakter sınırı konuldu
            printf("Soyad: ");
            scanf("%49s", hasta.soyad); // scanf için buffer overflow önlemek için 49 karakter sınırı konuldu
            inputBufferTemizle(); // Input bufferını temizlemek için
            printf("Acil Durum (1-5): ");
            scanf("%d", &hasta.acilDurum);
            inputBufferTemizle(); // Input bufferını temizlemek için
            printf("Rahatsizlik: ");
            scanf("%99s", hasta.rahatsizlik);
            printf("Ates (Celsius): ");
            scanf("%f", &hasta.ates);
            inputBufferTemizle(); // Input bufferını temizlemek için
            printf("Tansiyon (mmHg): ");
            scanf("%d", &hasta.tansiyon);
            inputBufferTemizle(); // Input bufferını temizlemek için
            printf("Renk Kodu (1: Kirmizi, 2: Sari, 3: Yesil): ");
            scanf("%d", &hasta.renkKodu);
            inputBufferTemizle(); // Input bufferını temizlemek için

            hastaSirala(queue, hasta);
            printf("Hasta siralandi.\n");
            printf("Ana menuye donmek icin Enter tusuna basin...\n");
            getchar(); // Enter tuşuna basılmasını beklemek için
            return;
        }
        default:
            printf("Gecersiz secim. Lutfen gecerli bir secenek seciniz.\n");
            printf("Ana menuye donmek icin Enter tusuna basin...\n");
            getchar(); // Enter tuşuna basılmasını beklemek için
    }
}

int main() {
    HastaStack stack;
    stack.top = -1;

    HastaQueue queue;
    queue.front = queue.rear = -1;

    Recete receteler[MAX_RECETE];
    int receteSayisi = 0;

    Hasta hastalar[MAX_HASTA];
    int hastaSayisi = 0;

    int secim;
    while (1) {
        printf("1. Hasta Ekle\n");
        printf("2. Hasta Cikar\n");
        printf("3. Hasta Kayitlari\n");
        printf("4. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        inputBufferTemizle(); // Input bufferını temizlemek için

        switch (secim) {
            case 1: {
                Hasta hasta;
                printf("Hasta Numarasi: ");
                if (scanf("%d", &hasta.hastaNo) != 1) {
                    printf("Hasta numarasi sadece sayilar olarak girebilirsiniz.\n");
                    inputBufferTemizle(); // Input bufferını temizlemek için
                    continue;
                }
                inputBufferTemizle(); // Input bufferını temizlemek için
                printf("Ad: ");
                scanf("%49s", hasta.ad); // scanf için buffer overflow önlemek için 49 karakter sınırı konuldu
                printf("Soyad: ");
                scanf("%49s", hasta.soyad); // scanf için buffer overflow önlemek için 49 karakter sınırı konuldu
                inputBufferTemizle(); // Input bufferını temizlemek için
                printf("Acil Durum (1-5): ");
                scanf("%d", &hasta.acilDurum);
                inputBufferTemizle(); // Input bufferını temizlemek için
                printf("Rahatsizlik: ");
                scanf("%99s", hasta.rahatsizlik);

                printf("Ates (Celsius): ");
                scanf("%f", &hasta.ates);
                inputBufferTemizle(); // Input bufferını temizlemek için
                printf("Tansiyon (mmHg): ");
                scanf("%d", &hasta.tansiyon);
                inputBufferTemizle(); // Input bufferını temizlemek için

                printf("Renk Kodu (1: Kirmizi, 2: Sari, 3: Yesil): ");
                scanf("%d", &hasta.renkKodu);
                inputBufferTemizle(); // Input bufferını temizlemek için

                hastaEkle(&stack, hasta);
                hastalar[hastaSayisi++] = hasta;
                hastaKaydet(hasta);
                break;
            }
            case 2: {
                printf("Hasta Numarasi: ");
                int hastaNo;
                if (scanf("%d", &hastaNo) != 1) {
                    printf("Hasta numarasi sadece sayilar olarak girebilirsiniz.\n");
                    inputBufferTemizle(); // Input bufferını temizlemek için
                    continue;
                }
                inputBufferTemizle(); // Input bufferını temizlemek için
                hastaCikar(&stack, hastalar, &hastaSayisi);
                break;
            }
            case 3: {
                hastaKayitlariGoster(hastalar, &hastaSayisi, receteler, receteSayisi, &queue);
                break;
            }
            case 4:
                return 0;
            default:
                printf("Gecersiz secim. Lutfen gecerli bir secenek seciniz.\n");
        }
    }

    return 0;
}
