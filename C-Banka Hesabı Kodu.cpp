#include <stdio.h>

int sifre;	          	  //sifre --> sizin belirleyeceðiiz banka þifresidir
int sifre_control;		  //sifre_control --> belirledðiðiniz þifrenin tekrar girip doðruluðunun kontrol edileceði deðiþkendir.
int islem_no;		      //islem_no --> seçeceðiniz iþlem numarasýdýr
int bakiye;		          //bakiye --> banka hesabinizda bulunan sizin belirleyeceðiniz bakiye miktaridir
int tutar;         		  //tutar --> banka iþlemlerinde kullanacaðýnýz para miktarýdýr
int devam;		 	      //devam --> hesaptan çýkýþ yapýp yapýlmayacaðýný soran deðiþkendir

void Islemler()		 // Banka iþlemlerini ekrana yazdýran fonksiyondur
{
	printf("\n-------------\nIslemler\n-------------\n1-Bakiye Sorgulama\n2-Para Cekme\n3-Para Yatirma\n4-Cikis Yap\n-------------\n");
	printf("Yapmak Istediginiz Islemi Tuslayiniz: ");
	scanf("%d",&islem_no);
}

void AltIslemler()	  //Bir iþlem seçildikten sonra bu fonksiyon devreye girer ve hangi iþlemde ne yapýlacaðý gösterilir
{		
	Islemler();
		
		switch(islem_no)
		{
			case 1:
				printf("Bakiyeniz= %d",bakiye);									
				printf("\n-----------------------");
				printf("\nIslemlere Devam Etmek Istiyorsaniz 1'e, Cikis Yapmak istiyorsaniz Herhangi Bir Tusa Basin: ");
				scanf("%d",&devam);
					if(devam==1)
					{
						AltIslemler();
					}	
					else
					{
						printf("---------------------------");
						printf("\n---------------------------\n");
						printf("Hesabinizdan Cikis Yapilmistir\nEmirBank Iyi Gunler Diler");
					}	
			break;				    
			
			case 2:
				printf("Bakiyeniz= %d\n",bakiye);
				printf("Para Cekilecek Tutari Giriniz: ");
				scanf("%d",&tutar);
					if(tutar>bakiye)
					{
						printf("Yetersiz Bakiye Oldugundan Isleminiz Gerceklesemedi\n");
						printf("Bakiyeniz= %d\n",bakiye);								
					}
					else
					{
						bakiye-=tutar;
						printf("Hesabinizdan %d Tutarinda Para Cekilmistir\n",tutar);
						printf("Hesabinizda Kalan Bakiye %d",bakiye);
					}
				printf("\n-----------------------");
				printf("\nIslemlere Devam Etmek Istiyorsaniz 1'e, Cikis Yapmak istiyorsaniz Herhangi Bir Tusa Basin: ");
				scanf("%d",&devam);
		
					if(devam==1)
					{
						AltIslemler();
					}	
					else
					{
						printf("---------------------------");
						printf("\n---------------------------\n");
						printf("Hesabinizdan Cikis Yapilmistir\nEmirBank Iyi Gunler Diler");
					}
			break;
			
			case 3:
		   	    printf("Bakiyeniz= %d",bakiye);
				printf("\nHesabiniza Yatirilacak Olan Tutari Giriniz: ");
				scanf("%d",&tutar);
				bakiye+=tutar;
				printf("Hesabiniza Yatirilan Para %d",tutar);
				printf("Yeni Bakiyeniz %d",bakiye);
				printf("\n-----------------------");
				printf("\nIslemlere Devam Etmek Istiyorsaniz 1'e, Cikis Yapmak istiyorsaniz Herhangi Bir Tusa Basin: ");
				scanf("%d",&devam);
		
					if(devam==1)
					{
						AltIslemler();
					}	
					else
					{
						printf("---------------------------");
						printf("\n---------------------------\n");
						printf("Hesabinizdan Cikis Yapilmistir\nEmirBank Iyi Gunler Diler");
					}
			break;
			
			case 4:
				printf("---------------------------");
				printf("\n---------------------------\n");
				printf("Hesabinizdan Cikis Yapilmistir\nEmirBank Iyi Gunler Diler");
			break;
			
			default:
				printf("Bilinmeyen Islem\n");
				printf("Lutfen 1 Ile 4 Arasinda Sayi Tuslayin\n");
				AltIslemler();
			}
}

	void SifreKontrol()		// Þifrenizin doðruluðunu kontrol eder, eðer yanlýþsa hesaba girilemez, 3 kere yanlýþ þifre girildiðinde kart bloklanýr
	{		
		printf("Sifreniz Yanlis Lutfen Tekrar Deneyiniz\n");
		printf("Lutfen Sifrenizi Giriniz: ");
		scanf("%d",&sifre_control);
		
			if(sifre==sifre_control)
			{
				printf("---------------------------\n");
				printf("\n---------------------------\n");	
				printf("<*Hesabiniza Giris Yapildi*>\n");
				printf("---------------------------\n");	
				AltIslemler();
			}
			else
			{
				if(sifre==sifre_control)
				{
					printf("---------------------------\n");
					printf("\n---------------------------\n");	
					printf("<*Hesabiniza Giris Yapildi*>\n");
					printf("---------------------------\n");	
					AltIslemler();
				}	
				else
				{
					printf("Sifreniz Yanlis Lutfen Tekrar Deneyiniz\n");
					printf("Lutfen Sifrenizi Giriniz: ");
					scanf("%d",&sifre_control);
					
					if(sifre==sifre_control)
					{
						printf("---------------------------\n");
						printf("\n---------------------------\n");	
						printf("<*Hesabiniza Giris Yapildi*>\n");
				    	printf("---------------------------\n");	
						AltIslemler();
					}
					else
					{									
						printf("3. Kez Sifrenizi Yanlis Girdiginiz Icin Kartiniz Bloke Olmustur");
						printf("\nLutfen En Yakin EmirBank Subesine Gidiniz");				
					}			
				}					
		}
	}
	
int main()
{
	printf("4 Haneli Sifrenizi Belirleyiniz: ");
	scanf("%d",&sifre);
	if(999<sifre && sifre<10000)
	{	
		printf("Bakiyenizi Belirleyiniz: ");
		scanf("%d",&bakiye); 
		printf("---------------------------\n\n");
		printf("---------------------------\n");
		printf("EmirBank'a Hosgeldiniz\n");
		printf("Lutfen Sifrenizi Giriniz: ");
		scanf("%d",&sifre_control);
		
			if(sifre==sifre_control)
			{
				printf("---------------------------\n");
				printf("\n---------------------------\n");		
				printf("<*Hesabiniza Giris Yapildi*>\n");
				printf("---------------------------\n");	
				AltIslemler();
			}
			else
			{
				SifreKontrol();				
			}
	}
	else
	{
		printf("--------------------------------\n4 Haneli Bir Sifre Girmediginiz Icin Program Sonlandi\nLutfen Programi Tekrar Baslatin ve 4 Haneli Bir Sifre Belirleyin"); 
	}
}
