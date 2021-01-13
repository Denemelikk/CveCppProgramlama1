#include<iostream>
using namespace std;

int sifre;						//sifre --> sizin belirleyeceðiiz banka þifresidir
int sifre_control;		        //sifre_control --> belirledðiðiniz þifrenin tekrar girip doðruluðunun kontrol edileceði deðiþkendir.
int islem_no;				    //islem_no --> seçeceðiniz iþlem numarasýdýr
int bakiye;		                //bakiye --> banka hesabinizda bulunan sizin belirleyeceðiniz bakiye miktaridir
int tutar;		    		    //tutar --> banka iþlemlerinde kullanacaðýnýz para miktarýdýr
int devam;	             		//devam --> hesaptan çýkýþ yapýp yapýlmayacaðýný soran deðiþkendir

void Islemler()		   // Banka iþlemlerini ekrana yazdýran fonksiyondur
{
	cout<<"\n-------------\nIslemler\n-------------\n1-Bakiye Sorgulama\n2-Para Cekme\n3-Para Yatirma\n4-Cikis Yap\n-------------\n";
	cout<<"Yapmak Istediginiz Islemi Tuslayiniz: ";
	cin>>islem_no;
}

void AltIslemler() 	  //Bir iþlem seçildikten sonra bu fonksiyon devreye girer ve hangi iþlemde ne yapýlacaðý gösterilir
{		
	Islemler();
		
		switch(islem_no)
		{
			case 1:
				cout<<"Bakiyeniz= "<<bakiye;									
				cout<<"\n-----------------------";
				cout<<"\nIslemlere Devam Etmek Istiyorsaniz 1'e, Cikis Yapmak istiyorsaniz Herhangi Bir Tusa Basin: ";
				cin>>devam;
					if(devam==1)
					{
						AltIslemler();
					}	
					else
					{
						cout<<"---------------------------";
						cout<<"\n---------------------------\n";
						cout<<"Hesabinizdan Cikis Yapilmistir\nEmirBank Iyi Gunler Diler";
					}	
			break;				    
			
			case 2:
				cout<<"Bakiyeniz= "<<bakiye<<"\n";
				cout<<"Para Cekilecek Tutari Giriniz: ";
				cin>>tutar;
					if(tutar>bakiye)
					{
						cout<<"Yetersiz Bakiye Oldugundan Isleminiz Gerceklesemedi\n";
						cout<<"Bakiyeniz= "<<bakiye<<"",bakiye;								
					}
					else
					{
						bakiye-=tutar;
						cout<<"Hesabinizdan "<<tutar<<" Tutarinda Para Cekilmistir\n";
						cout<<"Hesabinizda Kalan Bakiye "<<bakiye;
					}
				cout<<"\n-----------------------";
				cout<<"\nIslemlere Devam Etmek Istiyorsaniz 1'e, Cikis Yapmak istiyorsaniz Herhangi Bir Tusa Basin: ";
				cin>>devam;
		
					if(devam==1)
					{
						AltIslemler();
					}	
					else
					{
						cout<<"---------------------------";
						cout<<"\n---------------------------\n";
						cout<<"Hesabinizdan Cikis Yapilmistir\nEmirBank Iyi Gunler Diler";
					}
			break;
			
			case 3:
		   	    cout<<"Bakiyeniz="<<bakiye;
				cout<<"\nHesabiniza Yatirilacak Olan Tutari Giriniz: ";
				cin>>tutar;
				cout<<"Hesabiniza "<<tutar<<" Tutarinda Para Yatirilmistir\n";
				bakiye+=tutar;
				cout<<"Yeni Bakiyeniz "<<bakiye;
				cout<<"\n-----------------------";
				cout<<"\nIslemlere Devam Etmek Istiyorsaniz 1'e, Cikis Yapmak istiyorsaniz Herhangi Bir Tusa Basin: ";
				cin>>devam;
		
					if(devam==1)
					{
						AltIslemler();
					}	
					else
					{	
						cout<<"---------------------------";
						cout<<"\n---------------------------\n";
						cout<<"Hesabinizdan Cikis Yapilmistir\nEmirBank Iyi Gunler Diler";
					}
			break;
			
			case 4:
				cout<<"---------------------------";
				cout<<"\n---------------------------\n";
				cout<<"Hesabinizdan Cikis Yapilmistir\nEmirBank Iyi Gunler Diler";
			break;
			
			default:
				cout<<"Bilinmeyen Islem\n";
				cout<<"Lutfen 1 Ile 4 Arasinda Sayi Tuslayin\n";
				AltIslemler();
			}
}

	void SifreKontrol()		// Þifrenizin doðruluðunu kontrol eder, eðer yanlýþsa hesaba girilemez, 3 kere yanlýþ þifre girildiðinde kart bloklanýr
	{		
		cout<<"Sifreniz Yanlis Lutfen Tekrar Deneyiniz\n";
		cout<<"Lutfen Sifrenizi Giriniz: ";
		cin>>sifre_control;
		
			if(sifre==sifre_control)
			{
				cout<<"---------------------------\n";
				cout<<"\n---------------------------\n";	
				cout<<"<*Hesabiniza Giris Yapildi*>\n";
				cout<<"---------------------------\n";	
				AltIslemler();
			}
			else
			{
				if(sifre==sifre_control)
				{
					cout<<"---------------------------\n";
					cout<<"\n---------------------------\n";	
					cout<<"<*Hesabiniza Giris Yapildi*>\n";
				    cout<<"---------------------------\n";	
					AltIslemler();
				}	
				else
				{
					cout<<"Sifreniz Yanlis Lutfen Tekrar Deneyiniz\n";
					cout<<"Lutfen Sifrenizi Giriniz: ";
					cin>>sifre_control;
					
					if(sifre==sifre_control)
					{
						cout<<"---------------------------\n";
						cout<<"\n---------------------------\n";	
						cout<<"<*Hesabiniza Giris Yapildi*>\n";
				    	cout<<"---------------------------\n";	
						AltIslemler();
					}
					else
					{									
						cout<<"3. Kez Sifrenizi Yanlis Girdiginiz Icin Kartiniz Bloke Olmustur";
						cout<<"\nLutfen En Yakin EmirBank Subesine Gidiniz";				
					}
				}					
		}
	}
	
int main()
{
	cout<<"4 Haneli Sifrenizi Belirleyiniz: ";
	cin>>sifre;
	if(999<sifre && sifre<10000)
	{	
		cout<<"Bakiyenizi Belirleyiniz: ";
		cin>>bakiye; 
		cout<<"---------------------------\n\n";
		cout<<"---------------------------\n";
		cout<<"EmirBank'a Hosgeldiniz\n";
		cout<<"Lutfen Sifrenizi Giriniz: ";
		cin>>sifre_control;
		
			if(sifre==sifre_control)
			{
				cout<<"---------------------------\n";
				cout<<"\n---------------------------\n";		
				cout<<"<*Hesabiniza Giris Yapildi*>\n";
				cout<<"---------------------------\n";	
				AltIslemler();
			}
			else
			{
				SifreKontrol();				
			}
	}
	else
	{
		cout<<"--------------------------------\n4 Haneli Bir Sifre Girmediginiz Icin Program Sonlandi\nLutfen Programi Tekrar Baslatin ve 4 Haneli Bir Sifre Belirleyin"; 
	}
}
