#�al��t�rmadan �nce glut kurulumu yap�lmal�d�r
#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>
#include<math.h>


	float x,y;
	float a1;
    float b1;
    float c1;
    float vektor[3][3]; //��genin x ve y koordinatlar�
    
    

//Do�runun denklemi 
void result(float a, float b, float c) {
	x = 0;
	float temp;
	temp =b*x + c;
	y = temp / a;
	
	
	 float temp2 = y;
	 temp2 = 0;
	 x = -c / b;
	 
	 
}



void initGL() {
   
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
}

//kullan�c�dan de�er alma fonsiyonu
int enter() {
	
	int i,j;
	
	//pozisyon vekt�rleri kullan�c�dan al�n�r
	printf("Lutfen Ax,Ay, Bx,By, Cx,Cy pozisyon vektorlerini girin:\n\n");
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			printf("%d. pozisyon vektorunu girin:",i+1);
			scanf("%f",&vektor[i][j]);
			
		}
	}
	vektor[0][2] = 1; //vekt�rlere 1 atamas� yap�l�r
	vektor[1][2] = 1;
	vektor[2][2] = 1;
	
	
	//Do�ru i�in katsay�lar kullan�c�dan al�n�r
	printf("\nLuften denklemin katsayilarini giriniz\n");
	printf("ay = bx + c\n\n");
	printf("a: ");
	scanf("%f",&a1);
	
	printf("b: ");
	scanf("%f",&b1);
	
	printf("c: ");
	scanf("%f",&c1);
	
	//a ve/veya b s�f�r olamaz
	if(a1 == 0 || b1 == 0 ) {
		printf("a ve/veya b katsayisi 0 olamaz\n\n");
		enter();
		
	}

	
}
 
void display(void){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	//koordinat sistemi �izilir
	glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    int k=0;
    for(k=-10;k<=50;k++){
        glVertex3f(k,-20,0);
        glVertex3f(k,20,0);
    }
    for(k=-10;k<=50;k++){
        glVertex3f(-20,k,0);
        glVertex3f(20,k,0);
    }
 	glEnd();
 
    //koordinat de�erleri ekrana yazd�r�l�r
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
    glVertex3f(0,90,0);
    glVertex3f(0,-90,0);
    glEnd();
    
    glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
    glVertex3f(90,0,0);
    glVertex3f(-90,0,0);
	glEnd();
	
	
	//belirli x ve y noktas� i�in yer belirlenir		
   float pozitifx = 13;
   float negatifx = -9;
 
    
    //x eksen�ne 13 verince y ekseni bulur ve yazd�r�r. Do�ruyu hesaplamak i�in
   float temp = b1 * pozitifx + c1;
   float dogruY = temp / a1;  // (13,dogruY)
   
   //x eksenine -9 verince y eksenini bularak yazd�r�r
   temp = b1 * negatifx + c1;
   float dogru_Y = temp / a1; //(-9,dogru_Y)
   
   	
   	//Do�ru �izimi ger�ekle�tirilir
	glBegin(GL_LINES); 
	glColor3f(0.0,1.0,1.0);
    glVertex3f(pozitifx,dogruY,0);
    glVertex3f(negatifx,dogru_Y,0);
	glEnd();
	
	
	//Do�ruyu �teleme
	// x = 0 ve y = 0
	result(a1,b1,c1); //(x,y) sonucu al�n�r
    
    float otele = x;
    otele = otele*-1;
    
     //�rn: x = -4 olmas� �teleme i�leminde kullna�lacakt�r
    //printf("x: %f\n",dogruY);
    //printf("y: %f\n",dogru_Y);
    
    
    double matris_dogru[3][3] = {{pozitifx,dogruY,1},{x,0,1},{negatifx,dogru_Y,1}}; //do�ru matrisi
    double matris_otele[3][3] = {{1,0,0},{0,1,0},{otele,0,1}}; //�teleme fonksiyonu matrisi
    double matris_carpim[3][3]; //�telenmi� do�ru matrisi olu�turulur
    
    
    //do�ruyu �telemk i�in matris �arp�m� ger�ekle�tirilir
    int sayac, satirSayac, sutunSayac;
    float deger;
    for(satirSayac = 0; satirSayac<3; satirSayac++){
        for(sutunSayac = 0; sutunSayac<3; sutunSayac++){
            deger = 0;
            for(sayac = 0; sayac<3; sayac++){
                deger += matris_dogru[satirSayac][sayac]*matris_otele[sayac][sutunSayac];
                }       
            matris_carpim[satirSayac][sutunSayac] = deger;
            }

    }
    
    //�telenmis do�ru matrisi yazd�r�l�r
    /*
    int satirSay,sutunSay;
    for(satirSay = 0; satirSay < 3; satirSay++){
        for(sutunSay = 0; sutunSay < 3; sutunSay++){
            printf(" %f ", matris_carpim[satirSay][sutunSay]);
            }
        printf("\n");
        }
        
      */  
    
    
    //�telenmi� do�ru matrisi ekrana yazd�r�l�r
	/*
	glBegin(GL_LINES);  //do�ru'yu �teleme       
    glColor3f(1.0f, 1.0f, 1.0f); 
    glVertex2f( matris_carpim[0][0], matris_carpim[0][1]);
    glVertex2f( matris_carpim[2][0], matris_carpim[2][1]);	
    glEnd();
    */
    
    //��gen �izimi yap�l�r
    glBegin(GL_LINE_LOOP);        
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex2f( vektor[0][0], vektor[0][1]);
    glVertex2f( vektor[1][0], vektor[1][1]);	
    glVertex2f( vektor[2][0], vektor[2][1]);
    glEnd();
    
    //��genin bir k��esine ye�il nokta koyar
  	glPointSize(7.0f);
	glBegin(GL_POINTS);
	glColor3f(0.0,1.0,0.0); //ye�il
	glVertex2f( vektor[0][0], vektor[0][1]);
	glEnd();
	
	 //��genin bir k��esine nokta koyar
	glBegin(GL_POINTS);
	glColor3f(1.0,0.0,1.0);
 	glVertex2f( vektor[1][0], vektor[1][1]);
	glEnd();
	
	 //��genin bir k��esine mavi nokta koyar
	glBegin(GL_POINTS);
	glColor3f(0.0,0.0,1.0);
	glVertex2f( vektor[2][0], vektor[2][1]);
	glEnd();
	
	
	
	//Not: do�ruya yap�lan �telemeyi cisme de yap�lacakt�r
	//�cgene �teleme yap�l�r
	float ucgen_oteleme[3][3];
	for(satirSayac = 0; satirSayac<3; satirSayac++){
        for(sutunSayac = 0; sutunSayac<3; sutunSayac++){
            deger = 0;
            for(sayac = 0; sayac<3; sayac++){
                deger += vektor[satirSayac][sayac]*matris_otele[sayac][sutunSayac];
                }       
            ucgen_oteleme[satirSayac][sutunSayac] = deger;
            }

    }
	
	//�telenen �cgen ekrana �izilir. yorum sat�r�ndad�r.
	/*
	glBegin(GL_LINE_LOOP);        
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex2f( ucgen_oteleme[0][0], ucgen_oteleme[0][1]);
    glVertex2f( ucgen_oteleme[1][0], ucgen_oteleme[1][1]);	
    glVertex2f( ucgen_oteleme[2][0], ucgen_oteleme[2][1]);
    glEnd();
	*/
	
	//do�rudan al�nan a��ya g�re ��gen_�teleme d�nd�r�lecek 
	
    float egim = b1 / a1; //do�runun e�imi
	    
  	float val = 180.0 / 3.14159265;
    float ret = atan(egim) * val; //a��y� radyan cinsinden kullanmak i�in
   
    //a�� matrisi
	float t_dondur[3][3] = {{cos(egim),-sin(egim),0},{sin(egim),cos(egim),0},{0,0,1}};
	
	
	//�telenen ��geni d�nd�rmek i�in matris �arp�m�
	float ucgen_dondur[3][3];
	for(satirSayac = 0; satirSayac<3; satirSayac++){
        for(sutunSayac = 0; sutunSayac<3; sutunSayac++){
            deger = 0;
            for(sayac = 0; sayac<3; sayac++){
                deger += ucgen_oteleme[satirSayac][sayac]*t_dondur[sayac][sutunSayac];
                }       
            ucgen_dondur[satirSayac][sutunSayac] = deger;
            }

    }	
    
    
	//d�nd�r�lm�� ��gen
	/*
	glBegin(GL_LINE_LOOP);        
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex2f( ucgen_dondur[0][0], ucgen_dondur[0][1]);
    glVertex2f( ucgen_dondur[1][0], ucgen_dondur[  1][1]);	
    glVertex2f( ucgen_dondur[2][0], ucgen_dondur[2][1]);
    glEnd();
	*/
	
	//Yans�tma i�lemi
	//yans�t�lan de�er matrisi
	float yansit[3][3] = {{1,0,0},{0,-1,0},{0,0,1}}; 
	
    //d�nen ��geni yans�tmak i�in matris �arp�m� yap�ld�
    float ucgen_yansit[3][3];
    for(satirSayac = 0; satirSayac<3; satirSayac++){
        for(sutunSayac = 0; sutunSayac<3; sutunSayac++){
            deger = 0;
            for(sayac = 0; sayac<3; sayac++){
                deger += ucgen_dondur[satirSayac][sayac]*yansit[sayac][sutunSayac];
                }       
            ucgen_yansit[satirSayac][sutunSayac] = deger;
            }

    }
    
    //yans�lt�lan ��gen g�sterilmemesi i�in yorum sat�r�na al�nd�
    /*
    glBegin(GL_LINE_LOOP);        
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex2f( ucgen_yansit[0][0], ucgen_yansit[0][1]);
    glVertex2f( ucgen_yansit[1][0], ucgen_yansit[1][1]);	
    glVertex2f( ucgen_yansit[2][0], ucgen_yansit[2][1]);
    glEnd();
    */
    
   
   //t-1 dond�r
   //yap�lan i�lemleri geri almak i�in
   float geri_dondur[3][3] = {{cos(egim),sin(egim),0},{-sin(egim),cos(egim),0},{0,0,1}};
   
   float ucgen_geri_dondur[3][3];
   for(satirSayac = 0; satirSayac<3; satirSayac++){
        for(sutunSayac = 0; sutunSayac<3; sutunSayac++){
            deger = 0;
            for(sayac = 0; sayac<3; sayac++){
                deger += ucgen_yansit[satirSayac][sayac]*geri_dondur[sayac][sutunSayac];
                }       
            ucgen_geri_dondur[satirSayac][sutunSayac] = deger;
            }

    }
    //D�nd�r�len ��gen
    /*
    glBegin(GL_LINE_LOOP);        
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex2f( ucgen_geri_dondur[0][0], ucgen_geri_dondur[0][1]);
    glVertex2f( ucgen_geri_dondur[1][0], ucgen_geri_dondur[1][1]);	
    glVertex2f( ucgen_geri_dondur[2][0], ucgen_geri_dondur[2][1]);
    glEnd();
   */
   
   
   //t-1 �tele
   //Yans�t�lan ��geni �teler
   float geri_otele[3][3] = {{1,0,0},{0,1,0},{-otele,0,1}};
   
   float ucgen_geri_otele[3][3];

   for(satirSayac = 0; satirSayac<3; satirSayac++){
        for(sutunSayac = 0; sutunSayac<3; sutunSayac++){
            deger = 0;
            for(sayac = 0; sayac<3; sayac++){
                deger += ucgen_geri_dondur[satirSayac][sayac]*geri_otele[sayac][sutunSayac];
                }       
            ucgen_geri_otele[satirSayac][sutunSayac] = deger;
            }

    }
    
    //��genin tam olarak do�ruya yans�m�� hali
    glBegin(GL_LINE_LOOP);        
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex2f( ucgen_geri_otele[0][0], ucgen_geri_otele[0][1]);
    glVertex2f( ucgen_geri_otele[1][0], ucgen_geri_otele[1][1]);	
    glVertex2f( ucgen_geri_otele[2][0], ucgen_geri_otele[2][1]);
    glEnd();
   
   //��genin kenar noktalar� �izilir
   glBegin(GL_POINTS);
	glColor3f(0.0,1.0,0.0); 
	glVertex2f( ucgen_geri_otele[0][0], ucgen_geri_otele[0][1]);
	glEnd();
	
	
	glBegin(GL_POINTS);
	glColor3f(1.0,0.0,1.0);
 	glVertex2f( ucgen_geri_otele[1][0], ucgen_geri_otele[1][1]);
	glEnd();
	
	glBegin(GL_POINTS);
	glColor3f(0.0,0.0,1.0);
	glVertex2f( ucgen_geri_otele[2][0], ucgen_geri_otele[2][1]);
	glEnd();
	
   
	
	glFlush();
	
}

int main(int argc, char *argv[]) {
	
	enter();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,500);
	glutCreateWindow("Vize �devi");
	
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-5,15.0,-5,10.0,-1.0,1.0);
	glutDisplayFunc(display);
	initGL();
	glutMainLoop();
	return 0;
}



