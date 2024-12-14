#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO her can azalmasinda uyari mesaji
//TODO can <= 20 iken uyari versin

int main()
{
    // Gerekli tanimlamalar yapilir
    int islem = 0, altislem = 0;

    // Karakterin ozellikleri tanimlanir
    char ad[30], calgi[30];

    // Karakterin temel nitelikleri tanimlanir
    int can = 100, tokluk = 100, uyku = 100, hijyen = 100, suDoygunlugu = 100, mentalSaglik = 100, mutluluk = 100; // [0,100] araliginda degisir

    // Temel nitelikler sifirlandiginda her tur kaybedilecek can miktarlari tanimlanir
    int turSonuKayip_tokluk = 20, turSonuKayip_uyku = 15, turSonuKayip_hijyen = 10, turSonuKayip_suDoygunlugu = 15, turSonuKayip_mentalSaglik = 10, turSonuKayip_mutluluk = 10;

    // Karakterin becerlieri tanimlanir
    int guc = 3, ceviklik = 3, dayaniklilik = 3, karizma = 3, toplayicilik = 3; // [0,25] araliginda degisir

    // Macera degiskenleri tanimlanir
    int altin = 10, tecrubePuani = 0;

    srand(time(NULL)); // rastgele degerler olusturmak icin kullanilir

    printf("********** OZANIN MACERALARI **********\n\n");

    printf("Ozanin adini giriniz: ");
    gets(ad); // Ozanin adi alinir
    ad[0] = toupper(ad[0]); // Ozanin bas harfi buyuk yazilir

    printf("%s ozaninin kullandigi calgiyi giriniz: ", ad);
    gets(calgi); // Ozanin calgisi alinir
    calgi[0] = tolower(calgi[0]); // Ozanin calgisinin bas harfi kucuk yazilir

    printf("\n1. Kamp alanina git.\n2. Sifahaneye git.\n3. Hana git.\n4. Maceraya atil.\n5. Seviye atla.\n6. Durumu goster.\n\n7. Oyundan cik.\n\n");

    while (can > 0) {
        printf("Yapilacak islemi giriniz: ");

        if (scanf("%d",&islem) == 1) {
            if (islem == 1) {
                // Kamp alanina git.
            } else if (islem == 2) {
                // Sifahaneye git.
            } else if (islem == 3) {
                // Hana git.

                printf("1. Yiyecek satin al ve ye.\n2. Icecek satin al, ic, eglen.\n3. Enstruman cal ve sarki soyle.\n\n4. Koy meydanina don.\n\n");

                printf("Handa yapilacak islemi giriniz: ");
                scanf("%d",&altislem);

                if (altislem == 3) {
                    if (hijyen <= 20)
                        printf("Hijyen seviyen 20 ve alti oldugu icin handa sarki soyleyemezsin. (Hijyen seviyen: \"%d\")\n\nKoy meydanina geri donuldu.\n\n", hijyen);
                    else {
                        // Handa sarki soylendi
                        int kazanilan = 10 + (int)(karizma*hijyen/100.0);
                        printf("Tebrikler!!! Handa sarki soyleyerek insanlari etkilemeyi basardin! Handaki insanlar sana %d altin bahsis verdi.\nToplam kazandigin altin: %d\n\n",(int)(karizma*hijyen/100.0),kazanilan);

                        altin += kazanilan;
                    }
                }

            } else if (islem == 4) {
                // Maceraya atil.
            } else if (islem == 5) {
                // Seviye atla.
            } else if (islem == 6) {
                // Durumu goster.
            } else if (islem == 7) {
                char eminmi;

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

    }

    printf("Program sonlandirildi.");

    if (can <= 0) {
        printf("%s ozani hayatini kaybetti...",ad);
    }

    return 0;
}
