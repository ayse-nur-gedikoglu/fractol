# fractol
# Fractal Nedir?

Fraktal, hiç bitmeyen bir desendir. Fraktallar, farklı ölçeklerde kendi kendine benzer olan sonsuz derecede karmaşık desenlerdir. Basit bir işlemin sürekli bir geri bildirim döngüsünde tekrar tekrar yapılmasıyla oluşturulurlar. Özyinelemeyle yönlendirilen fraktallar, dinamik sistemlerin görüntüleridir - Kaosun resimleridir. Geometrik olarak, aşina olduğumuz boyutlar arasında var olurlar. Fraktal desenler son derece aşinadır, çünkü doğa fraktallarla doludur. Örneğin: ağaçlar, nehirler, kıyı şeritleri, dağlar, bulutlar, deniz kabukları, kasırgalar, vb. Soyut fraktallar - Mandelbrot Kümesi gibi - bir bilgisayarın basit bir denklemi tekrar tekrar hesaplamasıyla üretilebilir.

![](http://fractalfoundation.wolfesongs.com/wp-content/uploads/2009/01/sierpinski-zoom41.gif)

## Kaos Teorisi Nedir?

Kaos, sürprizlerin, doğrusal olmayan ve öngörülemez olanın bilimidir. Bize beklenmeyeni beklemeyi öğretir. Geleneksel bilimin çoğu, yer çekimi, elektrik veya kimyasal reaksiyonlar gibi sözde öngörülebilir olgularla ilgilenirken, Kaos Teorisi, türbülans, hava durumu, borsa, beyin durumlarımız vb. gibi etkili bir şekilde öngörülmesi veya kontrol edilmesi imkansız olan doğrusal olmayan şeylerle ilgilenir. Bu olgular genellikle doğanın sonsuz karmaşıklığını yakalayan fraktal matematikle tanımlanır. Manzaralar, bulutlar, ağaçlar, organlar, nehirler vb. dahil olmak üzere birçok doğal nesne fraktal özellikler gösterir ve içinde yaşadığımız sistemlerin çoğu karmaşık, kaotik davranışlar sergiler. Dünyamızın kaotik, fraktal doğasını tanımak bize yeni içgörüler, güç ve bilgelik verebilir. Örneğin, atmosferin karmaşık, kaotik dinamiklerini anlayarak, bir balon pilotu bir balonu istenen yere "yönlendirebilir". Ekosistemlerimizin, sosyal sistemlerimizin ve ekonomik sistemlerimizin birbirine bağlı olduğunu anladığımızda, uzun vadeli refahımıza zarar verebilecek eylemlerden kaçınmayı umabiliriz.

![](http://fractalfoundation.wolfesongs.com/wp-content/uploads/2009/01/butterflaps1.gif)

**Kaosun Prensipleri**

- Kelebek Etkisi: Bu etki, New Mexico'da kanatlarını çırpan bir kelebeğe Çin'de bir kasırgaya neden olma gücü verir. Çok uzun zaman alabilir, ancak bağlantı gerçektir. Kelebek, uzay/zamanda tam doğru noktada kanatlarını çırpmasaydı, kasırga olmazdı. Bunu ifade etmenin daha kesin bir yolu, başlangıç koşullarındaki küçük değişikliklerin sonuçlarda köklü değişikliklere yol açmasıdır. Hayatlarımız bu ilkenin devam eden bir gösterisidir. Milyonlarca çocuğa kaos ve fraktallar hakkında eğitim vermenin uzun vadeli etkilerinin ne olacağını kim bilebilir?
- Öngörülemezlik: Karmaşık bir sistemin tüm başlangıç koşullarını yeterli (yani mükemmel) ayrıntıda asla bilemeyeceğimiz için, karmaşık bir sistemin nihai kaderini tahmin etmeyi umamayız. Bir sistemin durumunu ölçmedeki küçük hatalar bile önemli ölçüde artacak ve herhangi bir tahmini işe yaramaz hale getirecektir. Dünyadaki tüm kelebeklerin (vb.) etkilerini ölçmek imkansız olduğundan, doğru uzun vadeli hava tahmini her zaman imkansız kalacaktır.
- Düzen/Düzensizlik Kaos sadece düzensizlik değildir. Kaos, düzen ve düzensizlik arasındaki geçişleri araştırır ve bu geçişler genellikle şaşırtıcı şekillerde gerçekleşir.
- Karıştırma: Türbülans, karmaşık bir sistemdeki iki bitişik noktanın bir süre geçtikten sonra sonunda çok farklı konumlarda son bulmasını sağlar. Örnekler: İki komşu su molekülü okyanusun farklı yerlerinde veya hatta farklı okyanuslarda son bulabilir. Birlikte fırlatılan bir grup helyum balonu sonunda çok farklı yerlere inecektir. Karıştırma kapsamlıdır çünkü türbülans her ölçekte meydana gelir. Ayrıca doğrusal değildir: sıvılar karışmadan bırakılamaz.
- Geri bildirim: Sistemler genellikle geri bildirim mevcut olduğunda kaotik hale gelir. Bunun iyi bir örneği borsanın davranışıdır. Bir hisse senedinin değeri yükseldikçe veya düştükçe, insanlar o hisse senedini almaya veya satmaya eğilimlidir. Bu da hisse senedinin fiyatını daha da etkileyerek kaotik bir şekilde yükselmesine veya düşmesine neden olur.

*“Matematik yasaları gerçeğe atıfta bulunduğu ölçüde kesin değildir, kesin olduğu ölçüde de gerçeğe atıfta bulunmaz.”*

> *Albert Einstein*
> 

---

Bu projede grafiksel arayüz oluşturmak adına miniLibX kütüphanesini kullanacağız. Bu kütüphane hakkında detaylı bilgi için aşağıda bulunan bağlantıya gidiniz.

https://harm-smits.github.io/42docs/libs/minilibx

Bağlantı içerisinde aldığım textler ile bazı kısımları anlaşılması daha kolay hale getireceğim.

Başlayalım…

## MiniLibX

MiniLibX, X-Window ve Cocoa hakkında hiçbir bilginiz olmadan ekranlarda bir şeyler oluşturmak için en temel şeyleri yapmanıza olanak tanıyan küçük bir grafik kütüphanesidir. Basit pencere oluşturma, şüpheli bir çizim aracı, yarım yamalak görüntü işlevleri ve garip bir olay yönetim sistemi sağlar. 

MiniLibX'in "yarım yamalak görüntü işlevleri" denmesinin sebebi aslında kütüphanenin oldukça **basit ve sınırlı** olmasından kaynaklanıyor. MiniLibX, temel grafik işlemlerini yapmak için tasarlanmış minimalist bir kütüphane ve genellikle daha büyük grafik kütüphaneleriyle (OpenGL, SDL gibi) kıyaslandığında çok daha az işlev sunuyor.

- Görüntü dosyalarını sadece **XPM (X PixMap)** formatında açabiliyor. PNG, JPEG veya diğer popüler formatları desteklemiyor.
- Alfa (şeffaflık) kanalı desteği **yok**.
- Sadece birkaç temel fonksiyon sağlıyor:
    - Pixel koyma (**mlx_pixel_put()**)
    - Görüntü oluşturma (**mlx_new_image()**)
    - Görüntüye pixel yazma (**mlx_put_image_to_window()**)
- Görüntüleri döndürme, ölçekleme gibi ileri seviye işlemler **desteklenmiyor**.
- Görüntülerin renk derinlikleri veya filtreler gibi gelişmiş özellikler **yok**.
- Optimize edilmemiş, yani performans konusunda oldukça zayıf.

Kısacası bu kütüphanenin amacı size bilgisayar grafiklerinin nasıl çalıştığını düşük seviyede öğretmek.

### Temel Fonksiyonlar

| Fonksiyon | Açıklama |
| --- | --- |
| `mlx_init()` | Kütüphane başlangıcı |
| `mlx_new_window()` | Pencere açar |
| `mlx_pixel_put()` | Piksel çizer |
| `mlx_loop()` | Event loop'u başlatır |
| `mlx_key_hook()` | Tuş basıldığında çalışan fonksiyon |
| `mlx_destroy_window()` | Pencereyi kapatır |
| `mlx_xpm_file_to_image()` | XPM dosyasını image objesine çevirir |

### Kurulumda Linux'ta Sık Karşılaşılan Sorunlar:

- `mlx_init()` null dönerse genellikle **X11** veya gerekli kütüphaneler eksik demektir.
- **Mouse click eventleri** Linux'ta bazen çalışmıyor.
- PNG dosyalarını kullanmak için ekstra bir bağımlılık eklemek gerekiyor.

# ADIM ADIM MİNİLİBX NASIL ÇALIŞIR?

## **X Pencere Sistemine kısa bir giriş**

Şeylerin gerçekte nasıl çalıştığını anlamak için, GNU/Linux dünyasında grafiklerin genellikle nasıl çalıştığını anlamak gerekir.

1980'lerden beri grafikleri görüntülemenin en popüler yolu X11 protokolünü kullanmaktır (X protokolü, 11. spesifikasyon). İşleri basit tutmak için, X11, ekrandaki metin satırları dışındaki grafik öğelerini işlemek için tasarlanmış ağ odaklı bir protokoldür. Bu protokolün birkaç uygulaması mevcuttur, ancak en popüler/kullanılanı **Xorg'dur** .

Tüm bunların çalışması için iki öğeye ihtiyaç vardır: 

**bir X sunucusu** (bizim durumumuzda **Xorg** sunucusu) ve **X sunucusuna bir şeyler talep edebilen istemciler** (bunlar temelde her gün kullandığınız tüm GUI uygulamalarıdır). Bu uygulamalar **bir programlama arayüzü kullanarak sunucuyla iletişim** kurabilir : en popüler olanı (minilibx'in temel olarak güvendiği) [Xlib'dir](https://www.x.org/releases/current/doc/libX11/libX11/libX11.html) .

Xlib düşük seviyeli şeyleri halleder ve grafikleri gerçekten oluşturmaya başlamadan önce anlamamız gereken çok şey vardır. **Neyse ki** , Xlib'in üzerine inşa edilmiş daha gelişmiş kütüphaneler oluşturuldu ve bu da en önemli şeye, yani **inşa etmek istediğimiz uygulamaya odaklanmamızı** sağladı .

Minilibx bunlardan biri: [SDL2](https://www.libsdl.org/download-2.0.php) veya [GTK](https://www.gtk.org/) gibi kütüphaneler kadar özellikli değil , ama karmaşık **,** düşük seviyeli şeyleri soyutlamada iyi bir iş çıkar

## MiniLibX -> Xlib -> Xorg

MiniLibX'in en dipte yaptığı şey şu:
**Bir işletim sistemi ile donanım arasında iletişim kurmak.**

İşletim sistemi bu işlemleri yapmak için bir **Display Server (Görüntü Sunucusu)** kullanır.

**Linux'ta bunun adı: Xorg**

Windows'ta: **GDI**

MacOS'ta: **Quartz**

## Xorg Nedir?

**Xorg** veya **X11 (X Window System)**, 1980'lerden beri Unix sistemlerinde kullanılan grafik sunucu protokolüdür.

Modern Linux dağıtımlarında hala kullanılan **en alttaki grafik katmanı** budur.

### Xorg'un Görevi:

- Grafik kartından görüntüleri alır
- Bunları ekran tamponlarına (framebuffer) yollar
- Klavye ve mouse olaylarını işler
- Pencereleri yönetir

## Nasıl Çalışır?

Sistem açıldığında:

1. Xorg başlar.
2. Donanım sürücülerini yükler.
3. Ekran çözünürlüğünü ayarlar.
4. Bir **Display Server** açar.
5. Programlardan gelen istekleri dinler.

### Şu Önemli:

Xorg hiçbir programla doğrudan konuşmaz.

Onunla konuşan ara katmanlar var:

| Katman | Görevi | Kütüphaneler |
| --- | --- | --- |
| Uygulama | Grafik Programı | MiniLibX |
| Xlib | Xorg API'si | libX11 |
| Xorg | Grafik sunucusu | xserver |
| Kernel | Donanım sürücüsü | Nouveau, AMDGPU, i915 |

## XLİB NEDİR?

Xlib, Xorg'un **C dili ile kullanılan API'sidir**.

**Xlib, Xorg ile iletişim kuran en düşük seviye C API'sidir.**

Aslında Xlib = **X11 protokolünü yöneten bir istemci (client-side)** kütüphane.

Bu yüzden senin programın **server-client** mimarisiyle çalışır.

Temelde 3 şey yapar:

1. Pencere oluşturur
2. Eventleri dinler (klavye, mouse vs.)
3. Piksel çizdirir

**Xlib**, Xorg ile konuşmak için kullanılan **düşük seviyeli bir C kütüphanesidir**.

Bunu şöyle düşünebiliriz:
Xorg = Fabrika
Xlib = Fabrikaya sipariş gönderen mektuplar 📄
MiniLibX = O mektupları yazan postacı ✍️

[Kod]
↓
[MiniLibX]
↓
[Xlib]
↓
[Xorg]
↓
[Donanım]
↓
[Ekran]

---

💡 MiniLibX kendi başına bir grafik motoru değil. Xorg ve Xlib'in sağladığı işlevleri kullanarak sana daha basit bir arayüz sağlıyor.

---

Mesela şu satır:

```c

mlx_new_window(mlx, 800, 600, "Hello");

```

Aslında Xlib'de böyle bir şeye dönüşüyor:

```c

Display *d = XOpenDisplay(NULL);
Window w = XCreateSimpleWindow(d, RootWindow(d, 0), 0, 0, 800, 600, 1, 0, 0);
XMapWindow(d, w);
XFlush(d);
```

---

### 🔑 Bağlantı Şeması

```
+--------------+
|   MiniLibX   |  → Basit Fonksiyonlar (mlx_pixel_put, mlx_new_window)
+--------------+
        ↓
+--------------+
|    Xlib      |  → XDrawPoint, XCreateWindow, XMapWindow
+--------------+
        ↓
+--------------+
|    Xorg      |  → Grafik Donanımı, Ekran İşleyici
+--------------+
```

### Şimdi kodlarımız üzerinde minik bir inceleme yapalım

Minilibx'i kullanırken, gerçekten bir şeyler oluşturmaya başlamadan önce bir sürü şeyi başlatmanız gerekir. Kütüphane, tam olarak bu işi yapan tek bir işlevle birlikte gelir: 

Bu işlev, minilibx'in işlerini yapmak için ihtiyaç duyacağı tüm şeyleri içeren bir yapı oluşturur.`mlx_init`

void *mlx = mlx_init(  );

Bu gerçekten basit bir fonksiyon, ancak burada ilginç bir şey var. Fonksiyonun aslında döndürdüğü şey bir **void pointer** . Eğer aşina değilseniz, bir void pointer temelde bir adrestir, ancak derleyici bu adresin hangi türü işaret ettiğini bilmez. Bu, C'de bir tür "genel" oluşturmanın en kolay yoludur

Her şeye ilk adımı attığımız satır bu.

Aslında şunu yapıyor:

1. **XOpenDisplay()** çağrısını yapıyor.
2. X11 sunucusuyla bağlantı kuruyor.
3. **Display** yapısını bellekte saklıyor.
4. Bu yapı, senin bilgisayarın ekranıyla iletişim kuran en temel yapı oluyor.
5. `void *` ile saklamasının sebebi ise **sana detayları göstermemek** 😏.

MiniLibX'in içinde bu yapı aslında böyle saklanıyor:

```c
typedef struct s_mlx
{
    Display *display;   // Xlib bağlantısı
    int screen;         // X ekran numarası
    Window root;        // Root Pencere
} t_mlx;
```

MiniLibX, Xlib'in iç yapısını saklamak için `void *` kullanıyor. Çünkü:

| Neden | Açıklama |
| --- | --- |
| Soyutlama | Kullanıcının Xlib detaylarını bilmesine gerek yok. |
| Taşınabilirlik | Apple, Linux veya farklı sistemlerde aynı API çalışsın. |
| Kapsülleme | Direkt Display pointer'ına erişmeni istemiyor. |
| Kütüphane Esnekliği | Eğer yarın başka bir grafik sistemi kullanılırsa, bu yapı değiştirilebilir. |

**DÖNÜŞ DEĞERLERİ**

`mlx_init()`Grafiksel sisteme bağlantı kurulamadığı takdirde NULL döndürülür, aksi takdirde bağlantı tanımlayıcısı olarak null olmayan bir işaretçi döndürülür.

## **Kaynakları yok etmek ve serbest bırakmak**

Programımızı bitirdiğimizde, ona tahsis edilen tüm kaynakları serbest bırakmak isteyeceğiz. Bu noktada, fonksiyonu çağırıp ona 'nizi geçirebilirsiniz . Ancak, gibi bir bellek hatası algılama programı çalıştırırsak , bazı sızıntılar olduğunu göreceğiz. Bunun nedeni, ekranın kapatılmamış olmasıdır. Peki, ekran nedir?`freemlx_ptrvalgrind`

Başlatılan en önemli şeylerden biri **display'dir** . X Programlamada, display temel olarak X Sunucusuyla iletişim kurmak için kullanılan bağlantı tanımlayıcısına atıfta bulunur. Burada ayrıntılara çok fazla girmeyeceğiz, ancak bunun sizin için perde arkasında yönetilen başka bir büyük yapı olduğunu unutmayın. Ancak bilinmesi gereken önemli bir şey, bu display'in bir noktada kapatılması gerektiğidir. Minilibx artık Xlib API'sini kullanmadan bunu yapmanıza olanak tanıyan gerçekten temel bir işleve sahiptir.`mlx_init`

Fonksiyon bu . Fonksiyondan önce çağırmamız gerekiyor çünkü display değişkenini almak için erişime ihtiyacımız var . Artık herhangi bir sızıntımız olmamalı.`mlx_destroy_displayfreemlx_ptr`

## Ekranda Çizim Yapmak İçin Minilibx Resimleri Kullanma

Ancak, minilibx'in Xshm eklentisini kullanması ilginçtir; bu eklenti, programımızın görüntüleri X Server ile paylaşımlı bellek ( ) üzerinden paylaşmasını sağlar ve herhangi bir rutin kullanırken olduğu gibi soket üzerinden paylaşmaz .`/dev/shmXlib`

Piksellerimizi pencereye yerleştirmek için sürekli olarak nasıl çağrı yaptığımızı hatırlayın . Bellekte paylaşılan görüntülerle, bir işaretçi kullanarak pikselleri doğrudan değiştirebileceğiz. Açık olmak gerekirse, bu çok daha hızlıdır ve bu yüzden onu kullanmak istiyoruz!`mlx_pixel_put`

## JULİA VE MANDELBROT FRACTALLARI

### Mandelbrot Fraktalı

---

**Bir nokta, sonsuz kere kendisini işlettiğimizde patlayacak mı yoksa hapsolacak mı?**

## Matematik Formülü:

![image (1)](https://github.com/user-attachments/assets/ea20c033-a8d8-4445-8bfc-cf870be4a5cb)

---

Burada:

- **C** → Başlangıç noktası
- **Z₀** → 0
- Eğer Z sonsuzda patlarsa → Nokta dışarıda
- Eğer Z hep bir aralıkta sıkışıp kalırsa → Nokta içeride (Siyah)

### Julia Fraktalı

---

**Julia Fraktalı**, aslında Mandelbrot'un kardeşi gibi.

Ama burada fark şu:

👉 **Başlangıç Noktası Sabit**

👉 Z'nin kendisi geziyor.

## Matematik Formülü:

![image (2)](https://github.com/user-attachments/assets/cb6aa64e-5fc8-47f6-8c3e-44a45330930d)

---

İkisi arasındaki ilişki şu:

**Mandelbrot → Hangi C değerleri hapsoluyor?**

**Julia → Sabit bir C ile Z'nin nasıl davrandığını gösteriyor.**
