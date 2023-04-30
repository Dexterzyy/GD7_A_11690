#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

typedef char string[50];

void tampilMenu();
void inputData(int *dataAsli, int dataTampug);
void tampilData(int panjang, int lebar);
void hitungLuas(int panjang, int lebar);
void hitungKeliling(int *keliling, int panjang, int lebar);
void gatchaAngka(int *angka, int min, int max);

int main(int argc, char *argv[])
{
	srand(time(NULL)); // deklarasi untuk mendapatkan angka atau karakter random
	int menu, temp;
	int panjang, lebar;
	int keliling;
	int angkaRandom;
	bool cekInput = false;

	do
	{
		tampilMenu();
		printf("\n>>> ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
		{
			if (!cekInput) // if(!cekInput) merupakan bentuk lain dari "if(cekInput == false)"
			{
				do
				{
					printf("\nMasukan Panjang : ");
					scanf("%d", &temp);
					if (temp <= 0)
					{
						printf("\nPanjang tidak boleh kurang dari sama dengan 0!\n");
					}
					else
					{
						inputData(&panjang, temp);
						break;
					}
				} while (true); // while(true) merupakan bentuk lain dari "while(temp <=0)"
								// dengan syarat wajib meletakan "break;" pada kondis else

				do
				{
					printf("\nMasukan Lebar	: ");
					scanf("%d", &temp);
					if (temp <= 0)
					{
						printf("\nLebar tidak boleh kurang dari sama dengan 0!\n");
					}
					else
					{
						inputData(&lebar, temp);
						break;
					}
				} while (true);

				printf("\nBerhasil input");
				cekInput = true;
			}
			else
			{
				printf("\nAnda sudah input!");
			}
		}
		break;

		case 2:
		{
			if (cekInput) // if(cekInput ) merupakan bentuk lain dari "if(cekInput == true)"
			{
				tampilData(panjang, lebar);
				hitungLuas(panjang, lebar);
			}
			else
			{
				printf("\nAnda belum input!");
			}
		}
		break;

		case 3:
		{
			if (cekInput)
			{
				tampilData(panjang, lebar);
				hitungKeliling(&keliling, panjang, lebar);
				// variabel keliling yg sudah di deklarasi pada main. nilainya berubah
				// sesuai perhitung pada prosedur dan dibawa dalam parameter output

				printf("\n\n\tKeliling Persegi Panjang adalah %d cm", keliling);
			}
			else
			{
				printf("\nAnda belum input!");
			}
		}
		break;

		case 4:
		{
			gatchaAngka(&angkaRandom, 1, 5);
			// dalam pemanggilan parameter bisa diisi langsung dengan value
			// contoh diatas parameter min yang diisi dengan 1 dan max diisi dengan 5
			// mengenerat angka random dari 1 sampai 5

			inputData(&panjang, angkaRandom);
			// mengisi Panjang dng ankga random yg tela di generat

			gatchaAngka(&angkaRandom, 6, 10);

			inputData(&lebar, angkaRandom);
			// mengisi lebar dg angka random yg telah di generate

			tampilData(panjang, lebar);
			// menampilkan kembali informasi panjang dan lebarnya

			cekInput = true;
		}
		break;

		case 0:
		{
			printf("\n\n\t <Antonius Hardiantono Karurukan> - <A> - <220711690>");
		}
		break;

		default:
		{
			printf("\nMenu tidak ada!");
		}
		break;
		}
		getch();
	} while (menu != 0);

	return 0;
}

void tampilMenu()
{
	system("cls");
	puts("[1]. Input Panjang & Lebar");
	puts("[2]. Tampil Luas Persegi Panjang");
	puts("[3]. Tampil Keliling Persegi Panjang");
	puts("[4]. Generate Panjang & Lebar Random");
}

void inputData(int *dataAsli, int dataTampung)
{
	*dataAsli = dataTampung;
	// tanda "*" atau pointer selalu menempel pada variabel
	// yang pada parameternya menggunakan pointer
	// tidak hanya di parameter saja
}

void tampilData(int panajng, int lebar)
{
	printf("\n\t-----Data Panjang & Lebar Persegi Panjang-----");
	printf("\n\tPanjang Persegi Panjang (Saat ini) = %d", panajng);
	printf("\n\tLebar Persegi Panjang (Saat ini) = %d", lebar);
}

void hitungLuas(int panjang, int lebar)
{
	int luas;
	luas = panjang * lebar;
	printf("\n\n\tLuas Persegi Panjang adalah %d cm", luas);
	// karena variabel luas tidak di bawa atau di passing ke dalam main
	// maka dicetak luasnya didalam prosedur
}

void hitungKeliling(int *keliling, int panjang, int lebar)
{
	*keliling = 2 * (panjang + lebar);
}

void gatchaAngka(int *angka, int min, int max)
{
	*angka = (rand() % (max - min + 1) + min);
	// artinya didaptkan angka random dari rentang min sampai dengan max
	// misal min = 3 & max = 5, maka didaptkan rentang angka 3 sampai dengan 5
}
