#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ormanKesfiSavas(int haydutCan, int haydutGuc, int haydutCeviklik, int haydutDayaniklilik, int *can, int guc, int ceviklik, int dayaniklilik, int *altin, int *tecrubePuani) {
    srand(time(NULL));

    int karakterVerilenHasar, haydutAlinanHasar, haydutVerilenHasar, karakterAlinanHasar, kazanilanGanimet, baslayacak;
    char savassecim;

    if (haydutCeviklik < ceviklik) {
        // Karakter baslar

        printf("\nBir haydutla karsilastin!!!\n\nHaydutun Ozellikleri:\n\n- Haydutun gucu: %d/25\n- Haydutun cevikligi: %d/25\n- Haydutun dayaniklilik: %d/25\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

        while (*can > 0 && haydutCan > 0) {
            int kacabilmeIhtimali = 4*ceviklik;
            printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
            scanf(" %c", &savassecim);

            if (savassecim == 'k') {
                if ((rand() % 100) +1 < kacabilmeIhtimali) {
                    printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                    break;
                } else {
                    printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                    printf("Ceviklik seviyen daha yuksek oldugu icin savasa ilk sen basladin!\n");

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
                }
            } else {
                printf("Savasmaya devam ettin!\n");

                karakterVerilenHasar = 4*guc;
                haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                haydutCan -= haydutAlinanHasar;
                printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                haydutVerilenHasar = 4*haydutGuc;
                karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                *can -= karakterAlinanHasar;

                printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
            }
        }

        if (haydutCan <= 0) {
            printf("\nSavastan galip geldin!\n");
            kazanilanGanimet = rand()%10+15; // [15,25]
            *altin += kazanilanGanimet;
            *tecrubePuani += 30;
            printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 30 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
        }
    } else if (haydutCeviklik > ceviklik) {
        // Haydut baslar

        printf("\nBir haydutla karsilastin!!!\n\nHaydutun Ozellikleri:\n\n- Haydutun gucu: %d/25\n- Haydutun cevikligi: %d/25\n- Haydutun dayaniklilik: %d/25\n\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

        while (*can > 0 && haydutCan > 0) {
            int kacabilmeIhtimali = 4*ceviklik;
            printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
            scanf(" %c", &savassecim);

            if (savassecim == 'k') {
                if ((rand() % 100) +1 < kacabilmeIhtimali) {
                    printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                    break;
                } else {
                    printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                    printf("Haydutun ceviklik seviyesi daha yuksek oldugu icin savasa ilk haydut basladi!\n");

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
                }
            } else {
                printf("Savasmaya devam ettin!\n");

                haydutVerilenHasar = 4*haydutGuc;
                karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                *can -= karakterAlinanHasar;

                printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                karakterVerilenHasar = 4*guc;
                haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                haydutCan -= haydutAlinanHasar;
                printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
            }
        }

        if (haydutCan <= 0) {
            printf("\nSavastan galip geldin!\n");
            kazanilanGanimet = rand()%10+15; // [15,25]
            *altin += kazanilanGanimet;
            *tecrubePuani += 30;
            printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 30 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
        }
    } else {
        // Rastgele kisi baslar

        baslayacak = rand()%2; // [0,2]

        printf("\nBir haydutla karsilastin!!!\n\nHaydutun Ozellikleri:\n\n- Haydutun gucu: %d/25\n- Haydutun cevikligi: %d/25\n- Haydutun dayaniklilik: %d/25\n\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

        if (baslayacak == 0) { // Karakter baslar
            while (*can > 0 && haydutCan > 0) {
                int kacabilmeIhtimali = 4*ceviklik;
                printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
                scanf(" %c", &savassecim);

                if (savassecim == 'k') {
                    if ((rand() % 100) +1 < kacabilmeIhtimali) {
                        printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                        break;
                    } else {
                        printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                        printf("Ceviklik seviyen daha yuksek oldugu icin savasa ilk sen basladin!\n");

                        karakterVerilenHasar = 4*guc;
                        haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                        haydutCan -= haydutAlinanHasar;
                        printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                        haydutVerilenHasar = 4*haydutGuc;
                        karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                        *can -= karakterAlinanHasar;

                        printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
                    }
                } else {
                    printf("Savasmaya devam ettin!\n");

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
                }
            }

            if (haydutCan <= 0) {
                printf("\nSavastan galip geldin!\n");
                kazanilanGanimet = rand()%10+15; // [15,25]
                *altin += kazanilanGanimet;
                *tecrubePuani += 30;
                printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 30 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
            }
        } else { // Haydut baslar
            while (*can > 0 && haydutCan > 0) {
                int kacabilmeIhtimali = 4*ceviklik;
                printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
                scanf(" %c", &savassecim);

                if (savassecim == 'k') {
                    if ((rand() % 100) +1 < kacabilmeIhtimali) {
                        printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                        break;
                    } else {
                    printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                    printf("Haydutun ceviklik seviyesi daha yuksek oldugu icin savasa ilk haydut basladi!\n");

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                        *can -= karakterAlinanHasar;

                        printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                        karakterVerilenHasar = 4*guc;
                        haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                        haydutCan -= haydutAlinanHasar;
                        printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
                    }
                } else {
                    printf("Savasmaya devam ettin!\n");

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
                }
            }

            if (haydutCan <= 0) {
                printf("\nSavastan galip geldin!\n");
                kazanilanGanimet = rand()%10+15; // [15,25]
                *altin += kazanilanGanimet;
                *tecrubePuani += 30;
                printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 30 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
            }
        }
    }
}

void kayalikKesfiSavas(int haydutCan, int haydutGuc, int haydutCeviklik, int haydutDayaniklilik, int *can, int guc, int ceviklik, int dayaniklilik, int *altin, int *tecrubePuani) {
    srand(time(NULL));

    int karakterVerilenHasar, haydutAlinanHasar, haydutVerilenHasar, karakterAlinanHasar, kazanilanGanimet, baslayacak;
    char savassecim;

    if (haydutCeviklik < ceviklik) {
        // Karakter baslar

        printf("\nBir haydutla karsilastin!!!\n\nHaydutun Ozellikleri:\n\n- Haydutun gucu: %d/25\n- Haydutun cevikligi: %d/25\n- Haydutun dayaniklilik: %d/25\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

        while (*can > 0 && haydutCan > 0) {
            int kacabilmeIhtimali = 4*ceviklik;
            printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
            scanf(" %c", &savassecim);

            if (savassecim == 'k') {
                if ((rand() % 100) +1 < kacabilmeIhtimali) {
                    printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                    break;
                } else {
                    printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                    printf("Ceviklik seviyen daha yuksek oldugu icin savasa ilk sen basladin!\n");

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
                }
            } else {
                printf("Savasmaya devam ettin!\n");

                karakterVerilenHasar = 4*guc;
                haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                haydutCan -= haydutAlinanHasar;
                printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                haydutVerilenHasar = 4*haydutGuc;
                karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                *can -= karakterAlinanHasar;

                printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
            }
        }

        if (haydutCan <= 0) {
            printf("\nSavastan galip geldin!\n");
            kazanilanGanimet = rand()%20+55; // [55,75]
            *altin += kazanilanGanimet;
            *tecrubePuani += 60;
            printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 60 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
        }
    } else if (haydutCeviklik > ceviklik) {
        // Haydut baslar

        printf("\nBir haydutla karsilastin!!!\n\nHaydutun Ozellikleri:\n\n- Haydutun gucu: %d/25\n- Haydutun cevikligi: %d/25\n- Haydutun dayaniklilik: %d/25\n\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

        while (*can > 0 && haydutCan > 0) {
            int kacabilmeIhtimali = 4*ceviklik;
            printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
            scanf(" %c", &savassecim);

            if (savassecim == 'k') {
                if ((rand() % 100) +1 < kacabilmeIhtimali) {
                    printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                    break;
                } else {
                    printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                    printf("Haydutun ceviklik seviyesi daha yuksek oldugu icin savasa ilk haydut basladi!\n");

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
                }
            } else {
                printf("Savasmaya devam ettin!\n");

                haydutVerilenHasar = 4*haydutGuc;
                karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                *can -= karakterAlinanHasar;

                printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                karakterVerilenHasar = 4*guc;
                haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                haydutCan -= haydutAlinanHasar;
                printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
            }
        }

        if (haydutCan <= 0) {
            printf("\nSavastan galip geldin!\n");
            kazanilanGanimet = rand()%20+55; // [55,75]
            *altin += kazanilanGanimet;
            *tecrubePuani += 60;
            printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 60 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
        }
    } else {
        // Rastgele kisi baslar

        baslayacak = rand()%2; // [0,2]

        printf("\nBir haydutla karsilastin!!!\n\nHaydutun Ozellikleri:\n\n- Haydutun gucu: %d/25\n- Haydutun cevikligi: %d/25\n- Haydutun dayaniklilik: %d/25\n\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

        if (baslayacak == 0) { // Karakter baslar
            while (*can > 0 && haydutCan > 0) {
                int kacabilmeIhtimali = 4*ceviklik;
                printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
                scanf(" %c", &savassecim);

                if (savassecim == 'k') {
                    if ((rand() % 100) +1 < kacabilmeIhtimali) {
                        printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                        break;
                    } else {
                        printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                        printf("Ceviklik seviyen daha yuksek oldugu icin savasa ilk sen basladin!\n");

                        karakterVerilenHasar = 4*guc;
                        haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                        haydutCan -= haydutAlinanHasar;
                        printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                        haydutVerilenHasar = 4*haydutGuc;
                        karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                        *can -= karakterAlinanHasar;

                        printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
                    }
                } else {
                    printf("Savasmaya devam ettin!\n");

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
                }
            }

            if (haydutCan <= 0) {
                printf("\nSavastan galip geldin!\n");
                kazanilanGanimet = rand()%20+55; // [55,75]
                *altin += kazanilanGanimet;
                *tecrubePuani += 60;
                printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 60 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
            }
        } else { // Haydut baslar
            while (*can > 0 && haydutCan > 0) {
                int kacabilmeIhtimali = 4*ceviklik;
                printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
                scanf(" %c", &savassecim);

                if (savassecim == 'k') {
                    if ((rand() % 100) +1 < kacabilmeIhtimali) {
                        printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                        break;
                    } else {
                    printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                    printf("Haydutun ceviklik seviyesi daha yuksek oldugu icin savasa ilk haydut basladi!\n");

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                        *can -= karakterAlinanHasar;

                        printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                        karakterVerilenHasar = 4*guc;
                        haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                        haydutCan -= haydutAlinanHasar;
                        printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
                    }
                } else {
                    printf("Savasmaya devam ettin!\n");

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
                }
            }

            if (haydutCan <= 0) {
                printf("\nSavastan galip geldin!\n");
                kazanilanGanimet = rand()%20+55; // [55,75]
                *altin += kazanilanGanimet;
                *tecrubePuani += 60;
                printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 60 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
            }
        }
    }
}

void vadiKesfiSavas(int haydutCan, int haydutGuc, int haydutCeviklik, int haydutDayaniklilik, int *can, int guc, int ceviklik, int dayaniklilik, int *altin, int *tecrubePuani) {
    srand(time(NULL));

    int karakterVerilenHasar, haydutAlinanHasar, haydutVerilenHasar, karakterAlinanHasar, kazanilanGanimet, baslayacak;
    char savassecim;

    if (haydutCeviklik < ceviklik) {
        // Karakter baslar

        printf("\nBir haydutla karsilastin!!!\n\nHaydutun Ozellikleri:\n\n- Haydutun gucu: %d/25\n- Haydutun cevikligi: %d/25\n- Haydutun dayaniklilik: %d/25\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

        while (*can > 0 && haydutCan > 0) {
            int kacabilmeIhtimali = 4*ceviklik;
            printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
            scanf(" %c", &savassecim);

            if (savassecim == 'k') {
                if ((rand() % 100) +1 < kacabilmeIhtimali) {
                    printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                    break;
                } else {
                    printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                    printf("Ceviklik seviyen daha yuksek oldugu icin savasa ilk sen basladin!\n");

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
                }
            } else {
                printf("Savasmaya devam ettin!\n");

                karakterVerilenHasar = 4*guc;
                haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                haydutCan -= haydutAlinanHasar;
                printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                haydutVerilenHasar = 4*haydutGuc;
                karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                *can -= karakterAlinanHasar;

                printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
            }
        }

        if (haydutCan <= 0) {
            printf("\nSavastan galip geldin!\n");
            kazanilanGanimet = rand()%20+55; // [55,75]
            *altin += kazanilanGanimet;
            *tecrubePuani += 90;
            printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 90 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
        }
    } else if (haydutCeviklik > ceviklik) {
        // Haydut baslar

        printf("\nBir haydutla karsilastin!!!\n\nHaydutun Ozellikleri:\n\n- Haydutun gucu: %d/25\n- Haydutun cevikligi: %d/25\n- Haydutun dayaniklilik: %d/25\n\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

        while (*can > 0 && haydutCan > 0) {
            int kacabilmeIhtimali = 4*ceviklik;
            printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
            scanf(" %c", &savassecim);

            if (savassecim == 'k') {
                if ((rand() % 100) +1 < kacabilmeIhtimali) {
                    printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                    break;
                } else {
                    printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                    printf("Haydutun ceviklik seviyesi daha yuksek oldugu icin savasa ilk haydut basladi!\n");

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
                }
            } else {
                printf("Savasmaya devam ettin!\n");

                haydutVerilenHasar = 4*haydutGuc;
                karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                *can -= karakterAlinanHasar;

                printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                karakterVerilenHasar = 4*guc;
                haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                haydutCan -= haydutAlinanHasar;
                printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
            }
        }

        if (haydutCan <= 0) {
            printf("\nSavastan galip geldin!\n");
            kazanilanGanimet = rand()%20+55; // [55,75]
            *altin += kazanilanGanimet;
            *tecrubePuani += 90;
            printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 90 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
        }
    } else {
        // Rastgele kisi baslar

        baslayacak = rand()%2; // [0,2]

        printf("\nBir haydutla karsilastin!!!\n\nHaydutun Ozellikleri:\n\n- Haydutun gucu: %d/25\n- Haydutun cevikligi: %d/25\n- Haydutun dayaniklilik: %d/25\n\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

        if (baslayacak == 0) { // Karakter baslar
            while (*can > 0 && haydutCan > 0) {
                int kacabilmeIhtimali = 4*ceviklik;
                printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
                scanf(" %c", &savassecim);

                if (savassecim == 'k') {
                    if ((rand() % 100) +1 < kacabilmeIhtimali) {
                        printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                        break;
                    } else {
                        printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                        printf("Ceviklik seviyen daha yuksek oldugu icin savasa ilk sen basladin!\n");

                        karakterVerilenHasar = 4*guc;
                        haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                        haydutCan -= haydutAlinanHasar;
                        printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                        haydutVerilenHasar = 4*haydutGuc;
                        karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                        *can -= karakterAlinanHasar;

                        printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
                    }
                } else {
                    printf("Savasmaya devam ettin!\n");

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);
                }
            }

            if (haydutCan <= 0) {
                printf("\nSavastan galip geldin!\n");
                kazanilanGanimet = rand()%20+55; // [55,75]
                *altin += kazanilanGanimet;
                *tecrubePuani += 90;
                printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 90 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
            }
        } else { // Haydut baslar
            while (*can > 0 && haydutCan > 0) {
                int kacabilmeIhtimali = 4*ceviklik;
                printf("\nCanin: %d | Haydutun cani: %d\n\nk -> kac (kacabilme ihtimalin: %%%d)\ns -> savasa devam et\nSavasta yapilacak islemi girin: ", *can, haydutCan, kacabilmeIhtimali);
                scanf(" %c", &savassecim);

                if (savassecim == 'k') {
                    if ((rand() % 100) +1 < kacabilmeIhtimali) {
                        printf("\nSavastan kacmayi basardin!\n\nKoye geri dondun.\n\n");
                        break;
                    } else {
                    printf("\nSavastan kacamadin! Mecbur olarak savasa katildin.\n\n");

                    printf("Haydutun ceviklik seviyesi daha yuksek oldugu icin savasa ilk haydut basladi!\n");

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                        *can -= karakterAlinanHasar;

                        printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                        karakterVerilenHasar = 4*guc;
                        haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                        haydutCan -= haydutAlinanHasar;
                        printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
                    }
                } else {
                    printf("Savasmaya devam ettin!\n");

                    haydutVerilenHasar = 4*haydutGuc;
                    karakterAlinanHasar = haydutVerilenHasar - ((int)haydutVerilenHasar*dayaniklilik*0.04 - 1);
                    *can -= karakterAlinanHasar;

                    printf("\nHaydut sana %d hasar verdi!\n",karakterAlinanHasar);

                    karakterVerilenHasar = 4*guc;
                    haydutAlinanHasar = karakterVerilenHasar - ((int)karakterVerilenHasar*haydutDayaniklilik*0.04 - 1);
                    haydutCan -= haydutAlinanHasar;
                    printf("\nHayduta %d hasar verdin!\n",haydutAlinanHasar);
                }
            }

            if (haydutCan <= 0) {
                printf("\nSavastan galip geldin!\n");
                kazanilanGanimet = rand()%20+55; // [55,75]
                *altin += kazanilanGanimet;
                *tecrubePuani += 90;
                printf("\nHaydutun uzerinden %d altin ganimet topladin! Koye geri dondun.\nSavas sonucunda 90 tecrube puani kazandin.\n\nToplam altin miktarin: %d\nToplam tecrube puanin: %d\n\n",kazanilanGanimet,*altin,*tecrubePuani);
            }
        }
    }
}

int main()
{
    // Gerekli tanimlamalar yapilir
    int islem = 0, altislem = 0, satinalinacakislem = 0;

    // Karakterin ozellikleri tanimlanir
    char ad[30], calgi[30], intihar, eminmi, savassecim;

    // Karakterin temel nitelikleri tanimlanir
    int can = 100, tokluk = 100, uyku = 100, hijyen = 100, suDoygunlugu = 100, mentalSaglik = 100, mutluluk = 100; // [0,100] araliginda degisir

    // Temel nitelikler sifirlandiginda her tur kaybedilecek can miktarlari tanimlanir
    int gunSonuKayip_tokluk = 20, gunSonuKayip_uyku = 15, gunSonuKayip_hijyen = 8, gunSonuKayip_suDoygunlugu = 25, gunSonuKayip_mentalSaglik = 10, gunSonuKayip_mutluluk = 10;

    // Karakterin becerlieri tanimlanir
    int guc = 3, ceviklik = 3, dayaniklilik = 3, karizma = 3, toplayicilik = 3; // [0,25] araliginda degisir

    // Macera degiskenleri tanimlanir
    int altin = 10, tecrubePuani = 0, tur = 1, gun = 1;

    // Sans faktorleri tanimlanir
    int sifaliBitkiBulmaSansi = 0;
    srand(time(NULL)); // rastgele degerler olusturmak icin kullanilir

    printf("********** OZANIN MACERALARI **********\n\n");

    printf("Ozanin adini giriniz: ");
    gets(ad); // Ozanin adi alinir
    ad[0] = toupper(ad[0]); // Ozanin bas harfi buyuk yazilir

    printf("%s ozaninin kullandigi calgiyi giriniz: ", ad);
    gets(calgi); // Ozanin calgisi alinir
    calgi[0] = tolower(calgi[0]); // Ozanin calgisinin bas harfi kucuk yazilir

    printf("\n%s ozani cocuklugundan beri %s calgisina derin bir baglilik hissetmistir. Babasinin ona hediye ettigi bu %s, adeta hayatinin ve ruhunun bir parcasi haline gelmis, ne zaman zorlansa ona guc vermistir. %s kucuk yaslardan itibaren muzigin sadece bir eglence degil, ayni zamanda bir kurtulus yolu olduguna inanmisti.\n",ad,calgi,calgi,ad);
    printf("\nHer sabah gunesin ilk isiklariyla uyanir, kasabanin etrafindaki ormanlarda %s calgisiyla melodiler calardi. %s ozaninin melodileri o kadar etkileyiciydi ki, sadece insanlari degil, kuslari ve diger hayvanlari bile derinden etkiliyordu.\n",calgi,ad);
    printf("\nHer gun yeni bir maceraya atilan %s, haydutlarla karsilasip onlarla savasirdi. Kimi zaman yaralanirdi ve koy halki onu sifahaneye gotururdu. Sifaci, ozel sifali karisimlarla onun yaralarini iyilestirirken, %s, %s calgisiyla sarkilar calar ve soyler, etrafa moral kaynagi olurdu.\n",ad,ad,calgi);
    printf("\nBazi gunler %s, hana giderdi. Bu han, yorgun gezginlerin bir araya gelip hem dinlendikleri hem de eglendikleri bir yerdi. Insanlar burada yer, icer, sarki soyler ve eglenirdi.\n",ad);
    printf("\nHan geceleri muzikle yankilanir, kahkahalarla dolu olurdu. Zamanla %s, sadece bir muzisyen degil ayni zamanda bir kahraman olarak gorulmeye basladi. Onun sarkilari, yureklere cesaret veriyor, umutsuz insanlara umut asiliyordu. Gittigi her yerde muzigiyle zorluklari yenerek, insanlarin kalplerini fethediyordu. %s calgisi ise onun en derinden bagli oldugu dostuydu. %s maceralarina devam ederken, nereye giderse gitsin, %s calgisi hep yaninda olacak ve muzigiyle dunyayi daha iyi bir yer haline getirecekti.\n",ad,calgi,calgi);
    printf("\nBu maceralara tanik olmak icin:");

    printf("\n1. Kamp alanina git.\n2. Sifahaneye git.\n3. Hana git.\n4. Maceraya atil.\n5. Seviye atla.\n6. Durumu goster.\n\n7. Oyundan cik.\n\n");

    while (can > 0) {

        if (tur == 4) {
            gun++;

            if (tokluk == 0) {
                can -= gunSonuKayip_tokluk;
                printf("\nCok ac oldugun icin canin %d azalarak %d oldu!!!\n",gunSonuKayip_tokluk,can);
            }

            if (uyku == 0) {
                can -= gunSonuKayip_uyku;
                printf("\nCok uykusuz oldugun icin canin %d azalarak %d oldu!!!\n",gunSonuKayip_uyku,can);
            }

            if (hijyen == 0) {
                can -= gunSonuKayip_hijyen;
                karizma -= 1;
                printf("\nCok pis oldugun icin canin %d azalarak %d oldu!!!\n",gunSonuKayip_hijyen,can);
            }

            if (suDoygunlugu == 0) {
                can -= gunSonuKayip_suDoygunlugu;
                printf("\nCok susuz oldugun icin canin %d azalarak %d oldu!!!\n",gunSonuKayip_suDoygunlugu,can);
            }

            if (mentalSaglik == 0) {
                can -= gunSonuKayip_mentalSaglik;
                printf("\nMental sagligin cok kotu oldugun icin canin %d azalarak %d oldu!!!\n",gunSonuKayip_mentalSaglik,can);
            }

            if (mutluluk == 0) {
                can -= gunSonuKayip_mutluluk;
                printf("\nCok mutsuz kotu oldugun icin canin %d azalarak %d oldu!!!\n",gunSonuKayip_mutluluk,can);
            }

            if (can <= 20) {
                printf("Canin 20'nin altina dustu!!! Canin: %d/100",can);
            }
        }

        if (tur == 8) { // tur degiskeni uyudugu zaman 0lanir yani tur degeri karakterin uyumadigi gun sayisidir.
            mentalSaglik -= 20;
            mutluluk -= 10;

            printf("\n2 gun boyunca uyumadigin icin mental sagligin %d/100 oldu.\n",mentalSaglik);
        }

        if (tur == 12) {
            mentalSaglik -= 30;
            mutluluk -= 20;

            printf("\n3 gun boyunca uyumadigin icin mental sagligin %d/100 oldu.\n",mentalSaglik);
        }

        if (tur == 16) {
            mentalSaglik = 10;
            mutluluk -= 30;

            printf("\n4 gun boyunca uyumadigin icin mental sagligin 10/100 oldu.\n");
        }

        if (mentalSaglik == 0) {
            printf("Mental sagligin 0'a dustu. Intihar etmek ister misin? (e/h)");

            scanf(" %c",&intihar);
            if (intihar == 'e') {
                printf("\nIntihar edildi.\n\n");
                can = 0;
                break;
            } else {
                if (mentalSaglik == 0)
                    mentalSaglik += 10;
                else
                    mutluluk += 10;
                continue;
            }
        }

        if (tecrubePuani >= 100)
            printf("\nTecrube puanin 100'e ulasti! Seviye atlamak icin seviye atla menusune gecmelisin!\n\n");

        printf("Yapilacak islemi giriniz (Gun: %d Saat: %d:00): ",gun,(tur%4)*6);

        if (scanf("%d",&islem) == 1) {
            if (islem == 1) {
                // Kamp alanina git.

                printf("1. Kamp atesinin basinda calgi cal/sarki soyle.\n2. Nehirde yikan.\n3. Cadirina girip uyu.\n\n4. Koy meydanina don.\n\n");
                printf("Kamp alaninda yapilacak islemi giriniz: ");

                if (scanf("%d",&altislem) == 1) {
                    if (altislem == 1) {
                        if (hijyen <= 20)
                            printf("Hijyen seviyen 20 ve alti oldugu icin kamp atesinin basinda sarki soyleyemezsin. (Hijyen seviyen: \"%d\")\n\nKoy meydanina geri donuldu.\n\n", hijyen);
                        else if (uyku <= 20) {
                            printf("Uyku seviyen cok dusuk oldugu icin sarki soylemeye halin yok.\nUyku seviyen: %d/100\n\nKoy meydanina geri donuldu.\n\n",uyku);
                        } else {
                            // Kamp atesinde sarki soylendi
                            int kazanilan = 8 + (int)(karizma*hijyen/100.0);
                            tecrubePuani += 15;
                            altin += kazanilan;
                            mentalSaglik += 9;
                            mutluluk += 7;
                            uyku -= 10;
                            karizma += 1;
                            printf("Tebrikler!!! Kamp atesinde %s ile calgi calip sarki soyleyerek insanlari etkilemeyi basardin! Kamp atesindeki insanlar sana %d altin bahsis verdi.\nToplam kazandigin altin: %d\nKazandigin tecrube puani: 15\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",calgi,(int)(karizma*hijyen/100.0),kazanilan,altin);
                        }
                    } else if (altislem == 2) {
                        int olasilik = rand()%20+1; // [1,20] arasinda

                        if (olasilik == 1) {
                            printf("\n\nNehirde yikanmaya calisirken boguldun ve kimse seni kurtaramadi!!!\n\n");
                            can = 0;
                        } else {
                            if (hijyen == 100) {
                                printf("\n\nHijyen seviyen zaten full tekrar yikanamazsin.\n\nKoy meydanina geri donuldu.\n\n");
                            } else {
                                hijyen = 100;
                                printf("\nNehirde yikanarak hijyen seviyeni fulledin.\n\nKoy meydanina geri donuldu.\n\n");
                            }
                        }
                    } else if (altislem == 3) {
                        if (uyku == 100) {
                            printf("\n\nUykun olmadigi icin uyuyamadin.\n\nKoy meydanina geri donuldu.\n\n");
                        } else {
                            uyku = 100;
                            printf("\n\nCadirinda misil misil uyuyarak uykunu fulledin.\n\nKoy meydanina geri donuldu.\n\n");
                        }
                    } else {
                        printf("Koy meydanina geri donuldu.\n\n");
                    }
                } else {
                    printf("Hatali islem secildi.\n");
                    while (getchar() != '\n'); // Karakter girildiginde girilen yanlis ifadeler bellekten temizlenir
                }
                } else if (islem == 2) {
                // Sifahaneye git.

                if (can == 100)
                    printf("Can degeri %d/100 oldugu icin sifahaneye gidemezsin.\n",can);
                else {
                    printf("\nToplam altin miktari: %d\nToplam can miktari: %d\n\n",altin,can);
                    printf("1. Sifacidan yaralarini sarmasini iste. (+30 can, 60 altin)\n2. Sifacidan merhem yapip surmesini iste. (+20 can, 40 altin)\n\n3. Koy meydanina don.\n\n");

                    printf("Sifahanede yapilacak islemi giriniz: ");

                    if (scanf("%d",&altislem) == 1) {
                        if (altislem == 1 && altin >= 60) {
                            // Yaralarini sardirdi
                            if (can>=70) {
                                can=100;
                                altin-=60;
                                hijyen-=5;
                                printf("Yaralarin sariliyor...\n");
                                printf("Yaralarin sarildi. Can degeri tekrardan 100 oldu.\n");
                                printf("Toplam altin miktari: %d\n\n",altin);
                                printf("Koy meydanina donuluyor...\n\n");
                            } else {
                                can+=30;
                                altin-=60;
                                hijyen-=5;
                                printf("Yaralarin sariliyor...\n");
                                printf("Yaralarin sarildi. Can degeri %d oldu.\n",can);
                                printf("Toplam altin miktari: %d\n",altin);
                                printf("Koy meydanina donuluyor...\n\n");
                            }
                        } else if((altislem == 2) && altin>=40) {
                            // Merhem suruluyor
                            if (can>=80) {
                                can=100;
                                altin-=40;
                                hijyen-=3;
                                printf("Merhem suruluyor...\n");
                                printf("Merhem suruldu. Can degeri tekrardan 100 oldu.\n");
                                printf("Toplam altin miktari: %d\n\n",altin);
                                printf("Koy meydanina donuluyor...\n\n");
                            } else {
                                can+=20;
                                altin-=40;
                                hijyen-=3;
                                printf("Merhem suruluyor...\n");
                                printf("Merhem suruldu. Can degeri %d oldu.\n",can);
                                printf("Toplam altin miktari: %d\n",altin);
                                printf("Koy meydanina donuluyor...\n\n");
                            }
                        } else if (altin < 40)
                            printf("Yetersiz altin!!\n");
                        else
                            printf("Koy meydanina geri donuldu.\n\n");
                    } else
                        printf("Hatali giris!!!\n");
                }
            } else if (islem == 3) {
                // Hana git.

                printf("1. Yiyecek satin al, ye ve eglen.\n2. Icecek satin al, ic ve eglen.\n3. Enstruman cal ve sarki soyle.\n\n4. Koy meydanina don.\n\n");

                printf("Handa yapilacak islemi giriniz: ");

                if (scanf("%d",&altislem) == 1) {
                    if (altislem == 1) {
                        // Yiyecek satin al, ye ve eglen.

                        printf("\nYiyecek Listesi: \n1. Ekmek (10 tokluk) -> 10 altin\n2. Bir porsiyon yahni (50 tokluk) -> 40 altin\n3. Elma (5 tokluk) -> 5 altin\n4. Bir porsiyon tavuk (35 tokluk) -> 35 altin\n5. Atistirmaliklar (15 tokluk) -> 15 altin\n");

                        printf("Satin alinacak yiyecegi giriniz (%d altinin var): ", altin);

                        if (scanf("%d",&satinalinacakislem) == 1) {
                            if (satinalinacakislem == 1) {
                                if (tokluk == 100) {
                                    printf("Cok tok oldugunuz icin secilen yiyecek satin alinmadi.\n\nKoy meydanina geri donuldu.\n\n");
                                } else if ((tokluk+10 >= 100) && (altin >= 10)) {
                                    tokluk = 100;
                                    altin -= 10;
                                    uyku -= 5;
                                    printf("Bir ekmek satin alip yediniz! Tokluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",tokluk,altin);
                                } else if (altin >= 10){
                                    tokluk += 10;
                                    altin -= 10;
                                    uyku -= 5;
                                    printf("Bir ekmek satin alip yediniz! Tokluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",tokluk,altin);
                                } else {
                                    printf("Bu yiyecegi satin alabilmek icin yeterli altinin yok. Altin miktarin: %d\n\n",altin);
                                }
                            } else if (satinalinacakislem == 2) {
                                if (tokluk == 100) {
                                    printf("Cok tok oldugunuz icin secilen yiyecek satin alinmadi.\n\nKoy meydanina geri donuldu.\n\n");
                                } else if ((tokluk+50 >= 100) && (altin >= 50)) {
                                    tokluk = 100;
                                    altin -= 50;
                                    uyku -= 20;
                                    printf("Bir porsiyon yahni satin alip yediniz! Tokluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",tokluk,altin);
                                } else if (altin >= 50) {
                                    tokluk += 50;
                                    altin -= 50;
                                    uyku -= 20;
                                    printf("Bir porsiyon yahni satin alip yediniz! Tokluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",tokluk,altin);
                                } else {
                                    printf("Bu yiyecegi satin alabilmek icin yeterli altinin yok. Altin miktarin: %d\n\n",altin);
                                }
                            } else if (satinalinacakislem == 3) {
                                if (tokluk == 100) {
                                    printf("Cok tok oldugunuz icin secilen yiyecek satin alinmadi.\n\nKoy meydanina geri donuldu.\n\n");
                                } else if ((tokluk+5 >= 100) && (altin >= 5)) {
                                    tokluk = 100;
                                    altin -= 5;
                                    uyku -= 2;
                                    printf("Bir elma satin alip yediniz! Tokluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",tokluk,altin);
                                } else if (altin >= 5) {
                                    tokluk += 5;
                                    altin -= 5;
                                    uyku -= 2;
                                    printf("Bir elma satin alip yediniz! Tokluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",tokluk,altin);
                                } else {
                                    printf("Bu yiyecegi satin alabilmek icin yeterli altinin yok. Altin miktarin: %d\n\n",altin);
                                }
                            } else if (satinalinacakislem == 4) {
                                if (tokluk == 100) {
                                    printf("Cok tok oldugunuz icin secilen yiyecek satin alinmadi.\n\nKoy meydanina geri donuldu.\n\n");
                                } else if ((tokluk+35 >= 100) && (altin >= 35)) {
                                    tokluk = 100;
                                    altin -= 35;
                                    uyku -= 15;
                                    printf("Bir porsiyon tavuk satin alip yediniz! Tokluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",tokluk,altin);
                                } else if (altin >= 35){
                                    tokluk += 35;
                                    altin -= 35;
                                    uyku -= 15;
                                    printf("Bir porsiyon tavuk satin alip yediniz! Tokluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",tokluk,altin);
                                } else {
                                    printf("Bu yiyecegi satin alabilmek icin yeterli altinin yok. Altin miktarin: %d\n\n",altin);
                                }
                            } else if (satinalinacakislem == 5) {
                                if (tokluk == 100) {
                                    printf("Cok tok oldugunuz icin secilen yiyecek satin alinmadi.\n\nKoy meydanina geri donuldu.\n\n");
                                } else if ((tokluk+15 >= 100) && (altin >= 15)) {
                                    tokluk = 100;
                                    altin -= 15;
                                    uyku -= 10;
                                    printf("Atistirmaliklar satin alip yediniz! Tokluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",tokluk,altin);
                                } else if (altin >= 15) {
                                    tokluk += 15;
                                    altin -= 15;
                                    uyku -= 10;
                                    printf("Atistirmaliklar satin alip yediniz! Tokluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",tokluk,altin);
                                } else {
                                    printf("Bu yiyecegi satin alabilmek icin yeterli altinin yok. Altin miktarin: %d\n\n",altin);
                                }
                            } else {
                                printf("Hatali islem secildi.\n");
                            }
                        } else {
                            printf("Hatali islem secildi.\n");
                            while (getchar() != '\n'); // Karakter girildiginde girilen yanlis ifadeler bellekten temizlenir
                        }
                    } else if (altislem == 2) {
                        // Icecek satin al, ic ve eglen.

                        printf("\nIcecek Listesi: \n1. Su (40 sudoygunlugu) -> 40 altin\n2. Meyve suyu (15 sudoygunlugu) -> 15 altin\n3. Sut (20 sudoygunlugu) -> 20 altin\n");

                        printf("Satin alinacak icecegi giriniz (%d altinin var): ", altin);

                        if (scanf("%d",&satinalinacakislem) == 1) {
                            if (satinalinacakislem == 1) {
                                if (suDoygunlugu == 100) {
                                    printf("Vucudundaki su miktari cok yuksek oldugu icin secilen icecek satin alinmadi.\n\nKoy meydanina geri donuldu.\n\n");
                                } else if ((suDoygunlugu+40 >= 100) && (altin >=40)) {
                                    suDoygunlugu = 100;
                                    altin -= 40;
                                    printf("Bir su satin alip ictiniz! Su doygunluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",suDoygunlugu,altin);
                                } else if (altin >=40) {
                                    suDoygunlugu += 40;
                                    altin -= 40;
                                    printf("Bir su satin alip ictiniz! Su doygunluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",suDoygunlugu,altin);
                                } else {
                                    printf("Bu icecegi satin alabilmek icin yeterli altinin yok. Altin miktarin: %d\n\n",altin);
                                }
                            } else if (satinalinacakislem == 2) {
                                if (suDoygunlugu == 100) {
                                    printf("Vucudundaki su miktari cok yuksek oldugu icin secilen icecek satin alinmadi.\n\nKoy meydanina geri donuldu.\n\n");
                                } else if ((suDoygunlugu+15 >= 100) && (altin >=15)) {
                                    suDoygunlugu = 100;
                                    altin -= 15;
                                    printf("Bir meyve suyu satin alip ictiniz! Su doygunluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",suDoygunlugu,altin);
                                } else if (altin >= 15) {
                                    suDoygunlugu += 15;
                                    altin -= 15;
                                    printf("Bir meyve suyu satin alip ictiniz! Su doygunluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",suDoygunlugu,altin);
                                } else {
                                    printf("Bu icecegi satin alabilmek icin yeterli altinin yok. Altin miktarin: %d\n\n",altin);
                                }
                            } else if (satinalinacakislem == 3) {
                                if (suDoygunlugu == 100) {
                                    printf("Vucudundaki su miktari cok yuksek oldugu icin secilen icecek satin alinmadi.\n\nKoy meydanina geri donuldu.\n\n");
                                } else if ((suDoygunlugu+20 >= 100) && altin >= 20) {
                                    suDoygunlugu = 100;
                                    altin -= 20;
                                    uyku -= 40;
                                    printf("Bir sut satin alip ictiniz! Su doygunluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",suDoygunlugu,altin);
                                } else if (altin >= 20) {
                                    suDoygunlugu += 20;
                                    altin -= 20;
                                    uyku -= 40;
                                    printf("Bir sut satin alip ictiniz! Su doygunluk seviyeniz: %d/100\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",suDoygunlugu,altin);
                                } else {
                                    printf("Bu icecegi satin alabilmek icin yeterli altinin yok. Altin miktarin: %d\n\n",altin);
                                }
                            } else {
                                printf("Hatali islem secildi.\n");
                            }
                        } else {
                            printf("Hatali islem secildi.\n");
                            while (getchar() != '\n'); // Karakter girildiginde girilen yanlis ifadeler bellekten temizlenir
                        }
                    } else if (altislem == 3) {
                        // Enstruman cal ve sarki soyle.

                        if (hijyen <= 20)
                            printf("Hijyen seviyen 20 ve alti oldugu icin handa sarki soyleyemezsin. (Hijyen seviyen: \"%d\")\n\nKoy meydanina geri donuldu.\n\n", hijyen);
                        else if (uyku <= 20) {
                            printf("Uyku seviyen cok dusuk oldugu icin sarki soylemeye halin yok.\nUyku seviyen: %d/100\n\nKoy meydanina geri donuldu.\n\n",uyku);
                        } else {
                            // Handa sarki soylendi

                            int kazanilan = 10 + (int)(karizma*hijyen/100.0);
                            tecrubePuani += 20;
                            altin += kazanilan;
                            mentalSaglik += 10;
                            mutluluk += 8;
                            uyku -= 15;
                            karizma += 1;
                            printf("Tebrikler!!! Handa %s ile sarki soyleyerek insanlari etkilemeyi basardin! Handaki insanlar sana %d altin bahsis verdi.\nToplam kazandigin altin: %d\nKazandigin tecrube puani: 20\nToplam altin miktari: %d\n\nKoy meydanina geri donuldu.\n\n",calgi,(int)(karizma*hijyen/100.0),kazanilan,altin);
                        }
                    } else if (altislem == 4)
                        printf("Koy meydanina geri donuldu.\n\n");

                } else {
                    printf("Hatali islem secildi.\n");
                    while (getchar() != '\n');
                }

            } else if (islem == 4) {
                // Maceraya atil.

                printf("1. Yakin cevreden sifali bitki topla ve avlan.\n2. Ormani kesfe cik (kolay)\n3. Kayaliklari kesfe cik (orta)\n4. Vadiyi kesfe cik (zor)\n5. Koy meydanina don\n\n");

                printf("Yapilacak macerayi giriniz: ");

                if (scanf("%d",&altislem) == 1) {
                    if (altislem == 1) {
                        sifaliBitkiBulmaSansi = toplayicilik*4;
                        int sayac = 0;
                        if ((rand() % 100) +1 < sifaliBitkiBulmaSansi) {
                            can += 10;
                            if (can > 100)
                                can = 100;
                            sayac ++;
                            printf("\nBir sifali bitki buldun! Canin 10 artarak %d oldu.\n", can);
                        }

                        if ((rand() % 100) +1 < sifaliBitkiBulmaSansi) {
                            tokluk += 10;
                            if (tokluk > 100)
                                tokluk = 100;

                            sayac ++;
                            printf("\nBir meyve buldun! Toklugun 10 artarak %d oldu.\n", tokluk);
                        }

                        if ((rand() % 100) +1 < sifaliBitkiBulmaSansi/2) {
                            tokluk += 50;
                            if (tokluk > 100)
                                tokluk = 100;

                            sayac ++;
                            printf("\nBir av hayvan buldun ve onu avladin! Toklugun 50 artarak %d oldu.\n", tokluk);
                        }

                        if (sayac == 0) {
                            printf("\nCok sanssizsin herhangi bir bitki veya av bulamadin.\n");
                        }
                    } else if (altislem == 2) { // Kolay
                        int haydutGuc = rand()%3+1;
                        int haydutCeviklik = rand()%3+1;
                        int haydutDayaniklilik = rand()%3+1;

                        ormanKesfiSavas(100,haydutGuc,haydutCeviklik,haydutDayaniklilik,&can,guc,ceviklik,dayaniklilik,&altin,&tecrubePuani);

                        if (mutluluk + 10 >= 100) mutluluk = 100; else mutluluk += 10;
                        if (uyku - 20 <= 0) uyku = 0; else uyku -= 20;
                        if (tokluk - 10 <= 0) tokluk = 0; else tokluk -= 10;
                        if (suDoygunlugu - 15 <= 0) suDoygunlugu = 0; else suDoygunlugu -= 15;
                        if (hijyen - 10 <= 0) hijyen = 0; else hijyen -= 10;

                    } else if (altislem == 3) { // Orta
                        int haydutGuc = rand()%3+4;
                        int haydutCeviklik = rand()%3+4;
                        int haydutDayaniklilik = rand()%3+4;

                        kayalikKesfiSavas(100,haydutGuc,haydutCeviklik,haydutDayaniklilik,&can,guc,ceviklik,dayaniklilik,&altin,&tecrubePuani);

                        if (mutluluk + 20 >= 100) mutluluk = 100; else mutluluk += 20;
                        if (uyku - 30 <= 0) uyku = 0; else uyku -= 30;
                        if (tokluk - 20 <= 0) tokluk = 0; else tokluk -= 20;
                        if (suDoygunlugu - 25 <= 0) suDoygunlugu = 0; else suDoygunlugu -= 25;
                        if (hijyen - 20 <= 0) hijyen = 0; else hijyen -= 20;

                    } else if (altislem == 4) { // Zor
                        int haydutGuc = rand()%4+7;
                        int haydutCeviklik = rand()%4+7;
                        int haydutDayaniklilik = rand()%4+7;

                        vadiKesfiSavas(100,haydutGuc,haydutCeviklik,haydutDayaniklilik,&can,guc,ceviklik,dayaniklilik,&altin,&tecrubePuani);

                        if (mutluluk + 30 >= 100) mutluluk = 100; else mutluluk += 30;
                        if (uyku - 40 <= 0) uyku = 0; else uyku -= 40;
                        if (tokluk - 30 <= 0) tokluk = 0; else tokluk -= 30;
                        if (suDoygunlugu - 35 <= 0) suDoygunlugu = 0; else suDoygunlugu -= 35;
                        if (hijyen - 30 <= 0) hijyen = 0; else hijyen -= 30;

                    } else {
                        printf("Hatali islem secildi.\n");
                    }
                } else {
                    printf("Hatali islem secildi.\n");
                    while (getchar() != '\n');
                }
            } else if (islem == 5) {
                // Seviye atla.

                if (tecrubePuani == 100) {
                    int beceriyukseltme;
                    printf("\nTebrikler!! Seviye atladiniz.\n");
                    printf("\n--- Beceriler ---\n1. Guc = %d\n2. Ceviklik = %d\n3. Dayaniklilik = %d\n4. Karizma = %d\n5. Toplayicilik = %d\n\n",guc,ceviklik,dayaniklilik,karizma,toplayicilik);
                    tecrubePuani=0;
                    for(int i=0;i<5;i++) {
                        printf("%d. olarak yukseltilecek beceriyi giriniz: ",i+1);
                        if(scanf("%d",&beceriyukseltme) == 1){
                            if (beceriyukseltme == 1) {
                                guc++;
                            } else if (beceriyukseltme == 2) {
                                ceviklik++;
                            } else if (beceriyukseltme == 3) {
                                dayaniklilik++;
                            } else if (beceriyukseltme == 4) {
                                karizma++;
                            } else if (beceriyukseltme == 5) {
                                toplayicilik++;
                            } else {
                                printf("Gecersiz beceri secimi, lutfen 1 ile 5 arasinda bir deger giriniz.\n");
                                i--;
                            }
                        } else {
                            printf("Hatali islem secildi.\n");
                            while (getchar() != '\n'); // Karakter girildiginde girilen yanlis ifadeler bellekten temizlenir
                            i--;
                        }
                    }
                    printf("\nYukseltme gerceklestirildi. Becerilerin yeni degerleri: \n1. Guc = %d\n2. Ceviklik = %d\n3. Dayaniklilik = %d\n4. Karizma = %d\n5. Toplayicilik = %d\n\n",guc,ceviklik,dayaniklilik,karizma,toplayicilik);
                } else {
                    printf("Tecrube puani yeterli degil!!!\n");
                }
            } else if (islem == 6) {
                // Durumu goster.

                printf("\nDurum gosteriliyor...\n");
                printf("\nOzanin adi: %s\nKullanilan calgi: %s\n",ad,calgi);
                printf("\n--- Temel Nitelikler ---\n\n- Can = %d/100\n- Tokluk = %d/100\n- Uyku = %d/100\n- Hijyen = %d/100\n- Su Doygunlugu = %d/100\n- Mental Saglik = %d/100\n- Mutluluk = %d/100\n\n- Altin = %d\n- Tecrube Puani: %d/100\n\n",can,tokluk,uyku,hijyen,suDoygunlugu,mentalSaglik,mutluluk,altin,tecrubePuani);
                printf("--- Beceriler ---\n\n- Guc = %d/25\n- Ceviklik = %d/25\n- Dayaniklilik = %d/25\n- Karizma = %d/25\n- Toplayicilik = %d/25\n\n",guc,ceviklik,dayaniklilik,karizma,toplayicilik);
            } else if (islem == 7) {
                printf("Program sonlanacak. Emin misiniz?\n\ne -> evet\nh -> hayir\n");
                scanf(" %c",&eminmi);

                if (eminmi == 'e') {
                    printf("\nProgramdan sonlandiriliyor...\n\n");
                    break;
                } else
                    continue;
            } else
                printf("Hatali islem secildi.\n");
        } else {
            printf("Hatali islem secildi.\n");
            while (getchar() != '\n'); // Karakter girildiginde girilen yanlis ifadeler bellekten temizlenir
        }

        tur++;
    }

    printf("\nProgram sonlandirildi. ");

    if (can <= 0)
        printf("%s ozani hayatini kaybetti...",ad);

    return 0;
}
