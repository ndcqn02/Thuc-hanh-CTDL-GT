#include <stdio.h>
struct NL{
	int dl;
	NL *tiep;
};

NL *BoSung(NL *D, NL *ptu)
{
	NL *tg;
	if (D==NULL)
		D=ptu;
	else
	{
		tg=D;
		while(tg->tiep!= NULL){
			tg=tg->tiep;
		}
		tg->tiep= ptu;
	}
	return D;	
}
void Tao(NL *&D){
	NL *p;
	int n;
	printf("Nhap so ptu: ");
	scanf("%d", &n);
	for (int i= 1; i<=n; i++ ){
		p = new NL;
		printf("Nhap ptu thu %d: ",i);
		scanf("%d",&p->dl);
		p->tiep = NULL;
		D= BoSung(D, p);
	}
}

void Duyet(NL *D){
	while(D!=NULL){
		printf("%d ",D->dl);	
		D= D->tiep;	
	}	
}

int kTra(NL *D, int so){
	NL *tg;
	i=0;
	tg=D;
	while(tg!=NULL){
		if(tg->dl == so)
			i++;
		tg= tg->tiep;	
	}
	return i;
}

int chen(NL *D, int chen){
	while(tg!=NULL){
		if(tg->dl > so)
			i++;	
		tg= tg->tiep;	
	}
}

main()
{
	NL *H,*p,*H2,*p2,*chen;
	int n,i,so;
	H=NULL;	
	H2=NULL;	
	Tao(H);
	Duyet(H);
	printf("Nhap so ban muon kiem tra: ");
	scanf("%d",&so);
	if(kTra(H, so)!=0)
		printf("Co trong danh sach");
	else
		printf("Khong trong danh sach ");
	
	printf("\n\n(bai 2) ");
	Tao(H2);
	Duyet(H2);
	printf("Nhap so muon chen ");
	scanf("%d",&chen);
	
	
}












