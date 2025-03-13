# AcilServisYonetimSistemi
## Programın Amacı
Bu proje hastaların kayıtlarını tutmak, reçetelerini oluşturmak ve acil durum önceliğine göre sıralamak için bir Hasta Yönetim Sistemi uygular. Proje, C dilinde yazılmıştır ve hasta bilgileri ile reçeteler için stack ve kuyruk veri yapılarını kullanır.


## Programın Özelikleri
- Hasta ekleme ve çıkarma.
- Hasta bilgilerini görüntüleme.
- Hastaları acil durum önceliğine göre sıralama.
- Reçete oluşturma ve kaydetme.
- Hasta bilgilerini arama (Hasta Numarası veya Ad/Soyad ile).
- Acil durum sırasına göre hastaların öncelik sıralaması.

## Kullanılan Veri Yapıları
- Stack: Hastalar stack veri yapısı ile eklenip çıkarılabilir. Stack, hastaların son giren ilk çıkar (LIFO) prensibine göre düzenlenmesini sağlar.
- Queue: Hastalar acil durumlarına göre sıralanır. Queue, hastaların sıralanmasını FIFO (First In, First Out) prensibine göre gerçekleştirir.

## Kurulum
1. Bu projeyi bilgisayarınıza kopyalayın.
2. Projeyi derlemek için bir C derleyicisi (örneğin DEV C++)
3. Programı çalıştırın.

## Kullanım
Program çalıştırıldığında ana menüde aşağıdaki seçenekler sunulmaktadır:

- Hasta Ekle: Yeni bir hasta kaydeder.
- Hasta Çıkar: Sistemdeki bir hastayı çıkarır.
- Hasta Kayıtları: Hastaları aramak, sıralamak ve reçetelerini görüntülemek için seçenekler sunar.
- Çıkış: Programdan çıkmanıza olanak tanır.


## Hasta Bilgileri

- Hasta Numarası
- Ad
- Soyad
- Acil Durum (1-5 arası)
- Rahatsızlık
- Ateş (°C)
- Tansiyon (mmHg)
- Hastanın Aciliyetine Bağlı Renk Kodu (1: Kırmızı, 2: Sarı, 3: Yeşil)


## Reçeteler
Her hasta için bir veya birden fazla reçete oluşturulabilir. Reçetelerde ilaç adı bulunur.

## Katkı
Bu proje açık kaynaklıdır ve katkılara açıktır. Katkı sağlamak için aşağıdaki adımları izleyebilirsiniz:
1. Bu depoyu forkladıktan sonra, kendi dalınızı oluşturun (git checkout -b feature-xyz).
2. Değişikliklerinizi yapın ve commit edin (git commit -am 'Add new feature').
3. Dalınızı GitHub'a gönderin (git push origin feature-xyz).
4. Bir pull request oluşturun.


## TAVSİYE EDİLEN DERLEYİCİLER

Bu programı sisteminizde kullanabilmek için bir C programlama dili derleyicisine ihtiyacınız olacaktır. İşte sizin için iki öneri:

• Windows yüklü sistemlerde kullanmak için : [Devc++ (indirme aracı)](https://sourceforge.net/projects/dev-cpp/files/Binaries/Dev-C%2B%2B%204.9.9.2/devcpp-4.9.9.2_setup.exe/download)


• Tarayıcı üzerinden herhangi bir uygulamaya gerek olmadan kullanmak için: [Online C Derleyici](https://www.onlinegdb.com/online_c_compiler)
